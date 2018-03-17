#ifndef ast_funcdec_hpp
#define ast_funcdec_hpp

#include "ast.hpp"

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

			dst << "\t" << ".text" << std::endl;
			dst << "\t" << ".align\t2" << std::endl;
			dst << "\t" << ".globl\t" << *id << std::endl;
			dst << "\t" << ".set\tnomips16" << std::endl;
			dst << "\t" << ".set\tnomicromips" << std::endl;
			dst << "\t" << ".ent\t" << *id << std::endl;
			dst << "\t" << ".type\t" << *id << ", @function" << std::endl;
			dst << *id << ":" << std::endl;

			dst << "\t" << ".frame\t" << "$fp, " << "24" <<", $31" << std::endl;
			dst << "\t" << ".mask\t0x40000000, -4" << std::endl;
			dst << "\t" << ".fmask\t0x00000000, 0" << std::endl;
			dst << "\t" << ".set\tnoreorder" << std::endl;
			dst << "\t" << ".set\tnomacro" << std::endl;

			//allocate space on stack
			dst << "\t" << "addiu\t$sp, $sp, -8" << std::endl;

			//store previous frame pointer
			dst << "\t" << "sw\t$fp, 4($sp)" << std::endl;

			//create new frame pointer
			dst << "\t" << "move\t$fp, $sp" << std::endl;

			//dst << "\t" << "li\t" << "$2, " << "10" << std::endl;
			block->compile(dst, cntx, destloc);

			//get back to base stack pointer. start unrolling at this point
			dst << "\t" << "move\t$sp, $fp" << std::endl;
			dst << "\t" << "movz\t" << "$31, $31, $0" << std::endl;
			//load old frame pointer
			dst << "\t" << "lw\t$fp, 4($sp)" << std::endl;
			//release bytes from stack
			dst << "\t" << "addiu\t$sp, $sp, 8" << std::endl;
			//return
			dst << "\t" << "j\t$31" << std::endl;
			dst << "\t" << "nop" << std::endl << std::endl;

			dst << "\t" << ".set\tmacro" << std::endl;
			dst << "\t" << ".set\treorder" << std::endl;
			dst << "\t" << ".end\t" << *id << std::endl;
			dst << "\t" << ".size\t" << *id << ", .-" << *id << std::endl;

		};
};

#endif
