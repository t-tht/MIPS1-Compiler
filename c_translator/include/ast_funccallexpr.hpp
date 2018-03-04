#ifndef ast_funccallexpr_hpp
#define ast_funccallexpr_hpp

#include<string>
#include<iostream>
#include<ast.hpp>

class FuncCallExpr;

class FuncCallExpr: public Node{
	protected:
		std::string* id;
		NodePtr param;		//needs fixing later, but atm assume no
	public:
		FuncCallExpr(std::string* _id, NodePtr _param): id(_id), param(_param){}
		~FuncCallExpr(){
			delete param;
		}
		void translate(std::ostream &dst) const{
			dst << *id << "(";
			if(param != NULL){
				param->translate(dst);
			}		
			dst << ")";

		}
		void print(std::ostream &dst) const {
			dst << "print not implemented yet" <<std::endl;
			if(param != NULL){
				param ->print(dst);
			}
		}
};

#endif