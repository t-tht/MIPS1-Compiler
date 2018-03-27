#ifndef ast_returnstat_hpp
#define ast_returnstat_hpp

#include "ast.hpp"

class ReturnStat;

class ReturnStat : public Node{
protected:
	NodePtr Expr;
public:
	ReturnStat(NodePtr _Expr) : Expr(_Expr){};
	~ReturnStat(){};
	void translate(std::ostream &dst)const override{
		dst<< "\t";
		dst << "return ";
		Expr->translate(dst);
		dst << std::endl;
	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
		// dst << "#return statement" << std::endl;
		if(Expr != NULL){
			cntx.RegSetUsed(2);
			Expr->compile(dst, cntx, 2);
			cntx.RegSetAvailable(2);
		}
	};
	unsigned int GetContext(InterpretContext &cntx) const override{
		int exprv = 0;
		if(Expr != NULL){
			exprv = Expr->GetContext(cntx);
		}
		return exprv;
	};
};

#endif
