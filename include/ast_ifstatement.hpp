#ifndef ast_ifstatement_hpp
#define ast_ifstatement_hpp

#include "ast.hpp"

class IfStatement;

class IfStatement : public Node{
	protected:
		const NodePtr cond;
		const NodePtr body;
        const NodePtr body1=NULL;
	public:
		IfStatement(const NodePtr _cond, const NodePtr _body) : cond(_cond), body(_body){};
        IfStatement(const NodePtr _cond, const NodePtr _body, const NodePtr _body1) : cond(_cond), body(_body), body1(_body1){};
		~IfStatement(){
			delete cond;
			delete body;
		};
		void translate(std::ostream &dst)const override{
            for(int i=0; i<tab; i++){
                dst<< "\t";
            }
            dst << "if(";
			if(cond != NULL){
				cond->translate(dst);
			}
			dst << "):" << std::endl;
			if(body != NULL){
                tab++;
				body->translate(dst);
                tab--;
			}
            if(body1 != NULL){
                dst<< "else:"<<std::endl;
                tab++;
                body1->translate(dst);
                tab--;
            }
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
            dst << "if statement compile function not yet implemented" << std::endl;
		};
		unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
