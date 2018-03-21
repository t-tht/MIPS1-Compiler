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
		block->translate(dst);
	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{

		std::ostream temp(NULL);

		dst << "\t" << ".text" << std::endl;
		dst << "\t" << ".align\t2" << std::endl;
		dst << "\t" << ".globl\t" << *id << std::endl;
		dst << "\t" << ".set\tnomips16" << std::endl;
		dst << "\t" << ".set\tnomicromips" << std::endl;
		dst << "\t" << ".ent\t" << *id << std::endl;
		dst << "\t" << ".type\t" << *id << ", @function" << std::endl;
		dst << *id << ":" << std::endl;

		//counting parameters without output
		if(param!= NULL){
			param->compile(temp, cntx, destloc);
		}else{
			cntx.paramClear();
		}
		//setting values TODO Include arg and var no
		cntx.paramCount();
		//determine frame size
		cntx.fpSizeCalc();
		//resetting values TODO Include arg and var no
		cntx.paramClear();

		dst << "\t\t#f size: " << cntx.fpSizeGet() << std::endl;

		dst << "\t" << ".frame\t" << "$fp, " << cntx.fpSizeGet() <<", $ra" << std::endl;
		dst << "\t" << ".mask\t0x40000000, -4" << std::endl;
		dst << "\t" << ".fmask\t0x00000000, 0" << std::endl;
		dst << "\t" << ".set\tnoreorder" << std::endl;
		dst << "\t" << ".set\tnomacro" << std::endl;
		dst << std::endl;


		dst << "\t" << "addiu\t$sp, $sp, -" << cntx.fpSizeGet() << std::endl; //allocate space on stack
		cntx.spSet(0);//reset sp offset

		/*
		TODO : 	implemented leaf detection
		implement find arg_no
		*/

		if(/*!leaf*/0){//if it is NOT a leaf function (calls another function), save $ra
			cntx.spIncrement();
			dst << "\t" << "sw\t\t$ra, " << cntx.fpSizeGet()-cntx.spGet() << "($sp)" << std::endl;
		}

		cntx.spIncrement();
		dst << "\t" << "sw\t\t$fp, "<< cntx.fpSizeGet()-cntx.spGet() << "($sp)" << std::endl;
		dst << "\t" << "move\t$fp, $sp" << std::endl;

		if(param != NULL){
			param->compile(dst, cntx, destloc);
			int param_no = cntx.paramCount();
			cntx.paramClear();

			if(param_no != 0){
				for(int i = 0; i < param_no; i++){
					dst << "\tsw\t\t$" << 4+i << ", " << (cntx.fpSizeGet()+4*(i)) << "($fp)" << std::endl;
				}
				cntx.spSet(param_no*4); //TODO CHECK THIS
			}
		}

		dst << std::endl;
		if(block != NULL){
		block->compile(dst, cntx, destloc);
		}
		dst << std::endl;

		//get back to base stack pointer. start unrolling at this point
		dst << "\t" << "move\t$sp, $fp" << std::endl;
		dst << "\t" << "lw\t\t$fp, " << cntx.fpSizeGet()-4 <<"($sp)" << std::endl;
		dst << "\t" << "addiu\t$sp, $sp, " << cntx.fpSizeGet() << std::endl;
		//return
		dst << "\t" << "j\t\t$ra" << std::endl;
		dst << "\t" << "nop" << std::endl << std::endl;

		dst << "\t" << ".set\tmacro" << std::endl;
		dst << "\t" << ".set\treorder" << std::endl;
		dst << "\t" << ".end\t" << *id << std::endl;
		dst << "\t" << ".size\t" << *id << ", .-" << *id << std::endl;

	};
};

#endif
