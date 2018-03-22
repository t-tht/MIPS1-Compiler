#ifndef ast_funccallexpr_hpp
#define ast_funccallexpr_hpp

#include "ast.hpp"

class FuncCallExpr;

class FuncCallExpr: public Node{
protected:
	std::string* id;
	NodePtr param;		//needs fixing later, but atm assume no
public:
	FuncCallExpr(std::string* _id, NodePtr _param): id(_id), param(_param){};
	~FuncCallExpr(){
		delete id;
		delete param;
	};
	void translate(std::ostream &dst) const override{
		dst << *id << "(";
		if(param != NULL){
			param->translate(dst);
		}
		dst << ")";

	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
		InterpretContext temp;
		if(param != NULL){
			param->GetSize(temp);
		}
		for(unsigned int i = 0; i < temp.param_no; i++){
			dst << "\tlw\t\t$" << 4+i << ", " << cntx.sp << "($fp)" << std::endl;
			cntx.spIncrement();
		}
		//cntx.functionLevelIncrement();
		dst << "\tjal\t" << *id << std::endl;
		//cntx.functionLevelDecrement();
		dst << "\tnop" << std::endl;
	};
	void GetSize(InterpretContext &cntx) const override{};
};

#endif
