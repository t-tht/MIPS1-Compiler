#ifndef ast_funccallexpr_hpp
#define ast_funccallexpr_hpp

#include "ast.hpp"

class FuncCallExpr;

class FuncCallExpr: public Node{
protected:
	std::string* id;
	NodePtr arg;		//needs fixing later, but atm assume no
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
		InterpretContext temp;
		if(arg != NULL){
			arg->GetContext(temp);
		}
		for(unsigned int i = 0; i < temp.arg_no; i++){
			dst << "\tlw\t\t$" << 4+i << ", " << cntx.sp << "($fp)" << std::endl;
			cntx.spIncrement();
		}
		//cntx.functionLevelIncrement();
		dst << "\tjal\t" << *id << std::endl;
		//cntx.functionLevelDecrement();
		dst << "\tnop" << std::endl;
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
