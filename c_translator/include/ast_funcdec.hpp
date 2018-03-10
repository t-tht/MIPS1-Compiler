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
		void compile(std::ostream &dst) const {
			dst << "compile not implemented yet" <<std::endl;
			if(param != NULL){
				param->compile(dst);
			}
			block->compile(dst);
		}
};

#endif
