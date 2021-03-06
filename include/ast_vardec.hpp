#ifndef ast_vardec_hpp
#define ast_vardec_hpp

#include "ast.hpp"

class VarDec;

class VarDec: public Node{
protected:
	std::string* type;
	std::string* id;
	NodePtr Expr;
public:
	VarDec(std::string* _type, std::string* _id, NodePtr _Expr): type(_type), id(_id), Expr(_Expr){}
	~VarDec(){
	}
	void translate(std::ostream &dst) const override{
		globalvars.push_back(*id);
		for(int i=0; i<tab; i++){
			dst<< "\t";
		}
		dst << *id;
		if(Expr != NULL){
			dst << " = ";
			Expr ->translate(dst);
		}
		else{
			dst<< "=0";
		}
		dst<<std::endl;

	}
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
		// dst << "#variable declaration--start" << std::endl;
		if(Expr != NULL){
			Expr->compile(dst, cntx, destloc);
		}else{
			dst << "\tli\t\t$" << destloc << ", 0" << std::endl;
		}
		dst << "\tsw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
		// dst << "#variable declaration--end" << std::endl;
	};
	unsigned int GetContext(InterpretContext &cntx) const override{
		unsigned int exprv;
		if(Expr != NULL){
			exprv = Expr->GetContext(cntx);
		}else{
			exprv = 0;
		}
		cntx.AddVariable(*id,exprv);
		cntx.AddToStack(*id);
		return 0;
	};
};

#endif
