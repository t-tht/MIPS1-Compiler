#ifndef ast_funcdecl_hpp
#define ast_funcdecl_hpp

#include<string>
#include<iostream>
#include<ast.hpp>

class FuncDecl;

class FuncDecl: public Node{
	protected:
		std::string* type;
		std::string* id;
		NodePtr arg;		//needs fixing later, but atm assume no arg
        NodePtr block;
	public:
		FuncDecl(std::string* _type, std::string* _id, NodePtr _arg, NodePtr _block): type(_type), id(_id), arg(_arg), block(_block){}
		~FuncDecl(){
			delete arg;
			delete block;
		}
		void translate(std::ostream &dst) const{
			dst << "def " << id << "():" << std::endl;
			arg->translate(dst);
			block->translate(dst);
		}
		void print(std::ostream &dst) const {
			dst << "print not implemented yet" <<std::endl;
			arg->print(dst);
			block->print(dst);
		}
};

#endif