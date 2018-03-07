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
		void print(std::ostream &dst)const override{
            dst << "return ";
            Expr->print(dst);
		};
};

#endif
