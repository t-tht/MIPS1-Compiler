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
			dst << "compile function not yet implemented" << std::endl;
		};
};

#endif
