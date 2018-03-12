#ifndef ast_returnstat_hpp
#define ast_returnstat_hpp

#include "ast_global.hpp"
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
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
			//NOT YET IMPLEMENTED
		};
};

#endif
