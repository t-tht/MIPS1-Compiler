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
		void translate(std::ostream &dst)const{
            dst << "return ";
            Expr->translate(dst);
			dst << std::endl;
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const{
            dst << "return ";
            Expr->compile(dst);
		};
};

#endif
