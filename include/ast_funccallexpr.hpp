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
		if(param != NULL){
			std::ostream temp(NULL);
			param->compile(temp, cntx, destloc);
			int param_no = cntx.paramCount();
			for(int i = 0; i < param_no; i++){
				dst << "\tlw\t\t$" << 4+i << ", " << /*fp offset*/ << "($fp)" << std::endl;
			}
		}
		//cntx.functionLevelIncrement();
		dst << "\tjal\t" << *id << std::endl;
		//cntx.functionLevelDecrement();
		dst << "\tnop" << std::endl;
		dst << "\tmove\t$" << destloc << ", $2" << std::endl;
	};
};

#endif
