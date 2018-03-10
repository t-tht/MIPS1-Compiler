#ifndef ast_returnstat_hpp
#define ast_returnstat_hpp

#include<string>
#include<iostream>
#include<ast.hpp>

class ReturnStat;

class ReturnStat : public Node{
	protected:
		NodePtr Expr;
	public:
		ReturnStat(NodePtr _Expr) : Expr(_Expr){};
		~ReturnStat(){};
		void translate(std::ostream &dst)const override{
            dst << "return ";
            Expr->translate(dst);
			dst << std::endl;
		};
<<<<<<< HEAD
		void compile(std::ostream &dst)const{
=======
		void print(std::ostream &dst)const override{
>>>>>>> 379cf3f1576e8485ea768c8799a099d6c4a50a20
            dst << "return ";
            Expr->compile(dst);
		};
};

#endif
