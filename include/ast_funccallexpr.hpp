#ifndef ast_funccallexpr_hpp
#define ast_funccallexpr_hpp

#include "ast.hpp"

class FuncCallExpr;

class FuncCallExpr: public Node{
protected:
	std::string* id;
	NodePtr arg;

public:
	FuncCallExpr(std::string* _id, NodePtr _arg): id(_id), arg(_arg){};
	~FuncCallExpr(){
		delete id;
		delete arg;
	};
	void translate(std::ostream &dst) const override{
		dst << *id << "(";
		if(arg != NULL){
			arg->translate(dst);
		}
		dst << ")";

	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
		if(arg){
			arg->GetContext(cntx);
			arg->compile(dst,cntx,4);
		}
		dst << "\tjal\t\t" << *id << std::endl;
		dst << "\tnop" << std::endl;
		if(destloc != 2){
			dst << "\tmove\t$" << destloc << ", $2" << std::endl;
		}

	};
	unsigned int GetContext(InterpretContext &cntx) const override{
		cntx.RegSetUsed(31);		//need return address
		if(arg != NULL){
			arg->GetContext(cntx);
		}
		return 0;
	};
};

#endif
