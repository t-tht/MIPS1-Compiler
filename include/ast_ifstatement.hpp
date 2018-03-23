#ifndef ast_ifstatement_hpp
#define ast_ifstatement_hpp

#include "ast.hpp"

class IfStatement;

class IfStatement : public Node{
	protected:
		const NodePtr cond;
		const NodePtr body;
	public:
		IfStatement(const NodePtr _cond, const NodePtr _body) : cond(_cond), body(_body){};
		~IfStatement(){
			delete cond;
			delete body;
		};
		void translate(std::ostream &dst)const override{
			dst << "if(";
			if(cond != NULL){
				cond->translate(dst);
			}
			dst << "):" << std::endl;
			if(body != NULL){
				body->translate(dst);
			}
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
			dst << "if statement compile function not yet implemented" << std::endl;
		};
		unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
