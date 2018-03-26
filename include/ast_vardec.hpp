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
		if(Expr != NULL){
			Expr->compile(dst, cntx, destloc);
		}
		dst << "\tsw\t\t$" << destloc << ", " << cntx.FindOnStack(*id)/*+cntx.frame_size*/ << "($fp)" << std::endl;

	};
	unsigned int GetContext(InterpretContext &cntx) const override{
		unsigned int exprv = Expr->GetContext(cntx);
		cntx.AddVariable(*id,exprv);
		cntx.AddToStack(*id);
		return 0;
	};
};

#endif
