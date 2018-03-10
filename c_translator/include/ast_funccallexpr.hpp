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
		void translate(std::ostream &dst) const override{
			dst << *id << "(";
			if(param != NULL){
				param->translate(dst);
			}		
			dst << ")";

		}
<<<<<<< HEAD
		void compile(std::ostream &dst) const {
			dst << "compile not implemented yet" <<std::endl;
=======
		void print(std::ostream &dst) const override{
			dst << "print not implemented yet" <<std::endl;
>>>>>>> 379cf3f1576e8485ea768c8799a099d6c4a50a20
			if(param != NULL){
				param ->compile(dst);
			}
		}
};

#endif
