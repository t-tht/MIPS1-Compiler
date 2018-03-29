#ifndef ast_funcdec_hpp
#define ast_funcdec_hpp

#include "ast.hpp"
#include "ast_param.hpp"

class FuncDec;

class FuncDec: public Node{
protected:
	std::string* type;
	std::string* id;
	NodePtr param;
	NodePtr block;
public:
	FuncDec(std::string* _type, std::string* _id, NodePtr _param, NodePtr _block): type(_type), id(_id), param(_param), block(_block){};
	~FuncDec(){
		delete type;
		delete id;
		delete param;
		delete block;
	};
	void translate(std::ostream &dst) const override{
		dst << "def " << *id << "(";
		if(param != NULL){
			param->translate(dst);
		}
		dst << "):" << std::endl;
		if(globalvars.size()!=0){
			tab++;
			for(int i=0; i<tab; i++){
				dst<< "\t";

			}
			tab--;
			for(unsigned int i=0; i<globalvars.size(); i++){
				dst<< "global " << globalvars[i];
				dst<< std::endl;
			}
		}
		tab++;
		if(block!=NULL){
			block->translate(dst);
		}
		tab--;
	};
	void compile(std::ostream &dst, InterpretContext &_cntx, unsigned int destloc) const override{
		InterpretContext cntx(_cntx);
		this->GetContext(cntx);

		dst << std::endl << std::endl;

		//default text stuff
		dst << "\t" << ".text" << std::endl;
		dst << "\t" << ".align\t2" << std::endl;
		dst << "\t" << ".globl\t" << *id << std::endl;
		dst << "\t" << ".set\tnomips16" << std::endl;
		dst << "\t" << ".set\tnomicromips" << std::endl;
		dst << "\t" << ".ent\t" << *id << std::endl;
		dst << "\t" << ".type\t" << *id << ", @function" << std::endl;
		dst << *id << ":" << std::endl;
		dst << "\t" << ".frame\t" << "$fp, " << cntx.fpSizeGet() <<", $ra" << std::endl;
		dst << "\t" << ".mask\t0x40000000, -4" << std::endl;
		dst << "\t" << ".fmask\t0x00000000, 0" << std::endl;
		dst << "\t" << ".set\tnoreorder" << std::endl;
		dst << "\t" << ".set\tnomacro" << std::endl;
		dst << std::endl;

		cntx.AllocateStack(dst);

		if(param != NULL){
			param->compile(dst, cntx, 4);
		}

		if(block != NULL){
			// dst << "#compiling function body" << std::endl;
			block->compile(dst, cntx, destloc);
		}


		dst << std::endl;
		cntx.DeallocateStack(dst);
		//return
		dst << "\t" << "j\t\t$ra" << std::endl;
		dst << "\t" << "nop" << std::endl << std::endl;

		dst << "\t" << ".set\tmacro" << std::endl;
		dst << "\t" << ".set\treorder" << std::endl;
		dst << "\t" << ".end\t" << *id << std::endl;
		dst << "\t" << ".size\t" << *id << ", .-" << *id << std::endl;

		// cntx.PrintStack(dst);
		// cntx.PrintVariable(dst);

	};



	unsigned int GetContext(InterpretContext &cntx) const override{
		if(param!=NULL){
			param->GetContext(cntx);
		}
		if(block!=NULL){
			block->GetContext(cntx);
		}
		return 0;
	};

};

#endif
