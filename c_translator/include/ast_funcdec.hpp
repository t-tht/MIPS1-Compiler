#ifndef ast_funcdec_hpp
#define ast_funcdec_hpp

#include<string>
#include<iostream>
#include"ast_param_var.hpp"
#include "ast_global.hpp"



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
		void translate(std::ostream &dst) const override{
			dst << "def " << *id << "(";
			if(param != NULL){
				param->translate(dst);
			}
			dst << "):" << std::endl;
			block->translate(dst);
		}
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
			//allocate bytes on stack, -8 used to reserve extra space (mips spec?)
			dst << "addiu		$sp, $sp, -8" << std::endl;
			//store previous frame pointer
			dst << "sw		$fp, 4($sp)" << std::endl;
			//create new frame pointer
			dst << "move 		$fp, $sp" << std::endl;
			//save param
			dst << "" << std::endl;
			//load param
			dst << "" << std::endl;
			//do work
			dst << "" << std::endl;
			//get back to base stack pointer. start unrolling at this point
			dst << "move 		$sp, $fp" << std::endl;
			//load old frame pointer
			dst << "lw 		$fp, 4($sp)" << std::endl;
			//release bytes from stack
			dst << "addiu		$sp, $sp, 8" << std::endl;
			//return
			dst << "j			$31" << std::endl;
		}
};

#endif
