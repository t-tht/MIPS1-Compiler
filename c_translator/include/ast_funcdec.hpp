#ifndef ast_funcdec_hpp
#define ast_funcdec_hpp

#include<string>
#include<iostream>
#include"ast_param_var.hpp"



class FuncDec;

class FuncDec: public Node{
	protected:
		std::string* type;
		std::string* id;
		NodePtr param;
        NodePtr block;
	public:
		FuncDec(std::string* _type, std::string* _id, NodePtr _param, NodePtr _block): type(_type), id(_id), param(_param), block(_block){}
		~FuncDec(){
			delete param;
			delete block;
		}
		void translate(std::ostream &dst) const{
			dst << "def " << *id << "(";
			if(param != NULL){
				param->translate(dst);
			}
			dst << "):" << std::endl;
			block->translate(dst);
		}
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const {
			//allocate bytes on stack, -8 used to reserve extra space (mips spec?)
			std::cout << "addiu		$sp, $sp, -8" << std::endl;
			//store previous frame pointer
			std::cout << "sw		$fp, 4($sp)" << std::endl;
			//create new frame pointer
			std::cout << "move 		$fp, $sp" << std::endl;
			//save param
			std::cout << "" << std::endl;
			//load param
			std::cout << "" << std::endl;
			//do work
			std::cout << "" << std::endl;
			//get back to base stack pointer. start unrolling at this point
			std::cout << "move 		$sp, $fp" << std::endl;
			//load old frame pointer
			std::cout << "lw 		$fp, 4($sp)" << std::endl;
			//release bytes from stack
			std::cout << "addiu		$sp, $sp, 8" << std::endl;
			//return
			std::cout << "j			$31" << std::endl;
		}
};

#endif
