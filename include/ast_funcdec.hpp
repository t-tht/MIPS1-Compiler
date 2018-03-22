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

		//initialising variables
		if(param!= NULL){
			param->GetSize(cntx);
		}
		cntx.fpSizeCalc();

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


		dst << "\t" << "addiu\t$sp, $sp, -" << cntx.fpSizeGet() << std::endl; //allocate space on stack
		cntx.spSet(0);

		cntx.spIncrement();
		dst << "\t" << "sw\t\t$ra, " << cntx.fpSizeGet()-cntx.spGet() << "($sp)" << std::endl; //save $ra
		cntx.spIncrement();
		dst << "\t" << "sw\t\t$fp, "<< cntx.fpSizeGet()-cntx.spGet() << "($sp)" << std::endl; //save fp
		dst << "\t" << "move\t$fp, $sp" << std::endl << std::endl;

		if(cntx.param_no){
			for(unsigned int i = 0; i < cntx.param_no; i++){
				dst << "\tsw\t\t$" << 4+i << ", " << cntx.sp << "($fp)" << std::endl;
				std::string s = std::to_string(4+i);
				cntx.AddToStack(s);
			}
<<<<<<< HEAD
			dst << "):" << std::endl;
			block->translate(dst);
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{

			dst << "\t" << ".text" << std::endl;
			dst << "\t" << ".align\t2" << std::endl;
			dst << "\t" << ".globl\t" << *id << std::endl;
			dst << "\t" << ".set\tnomips16" << std::endl;
			dst << "\t" << ".set\tnomicromips" << std::endl;
			dst << "\t" << ".ent\t" << *id << std::endl;
			dst << "\t" << ".type\t" << *id << ", @function" << std::endl;
			dst << *id << ":" << std::endl;

			cntx.frame_size = 8;

			dst << "\t" << ".frame\t" << "$fp, " << cntx.frame_size <<", $31" << std::endl;
			dst << "\t" << ".mask\t0x40000000, -4" << std::endl;
			dst << "\t" << ".fmask\t0x00000000, 0" << std::endl;
			dst << "\t" << ".set\tnoreorder" << std::endl;
			dst << "\t" << ".set\tnomacro" << std::endl;
			dst << std::endl;

//<<<<<<< HEAD
//            
//            
//            //allocate space on stack
//            dst << "\t" << "addiu\t$sp, $sp, -8" << std::endl;
//
//            //it needs to store return address here if we plan to jal
//            
//            //store previous frame pointer
//            dst << "\t" << "sw\t$fp, 4($sp)" << std::endl;
//=======
//
//            dst << "\t" << "addiu\t$sp, $sp, -" << cntx.frame_size << std::endl; //save space
//            cntx.spSet(0);
//>>>>>>> master

			if(/*!leaf*/1){
				cntx.spIncrement();
				dst << "\t" << "sw\t\t$31, " << cntx.frame_size - cntx.spGet() << "($sp)" << std::endl;
			}
			cntx.spIncrement();
			dst << "\t" << "sw\t\t$fp, "<< cntx.frame_size- cntx.spGet() << "($sp)" << std::endl;
			dst << "\t" << "move\t$fp, $sp" << std::endl;

			int arg_no = 4;
=======
		}
		// for(int i = 0; i < 4; i++){
		// 	std::string s = std::to_string(4+i);
		// 	dst << "#" <<cntx.FindOnStack(s) << std::endl;
		// }
>>>>>>> master


		if(block != NULL){
			block->compile(dst, cntx, destloc);
		}


		dst << std::endl;
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
	void GetSize(InterpretContext &cntx) const override{};
};

#endif
