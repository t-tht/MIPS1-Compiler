#ifndef ast_whilestatement_hpp
#define ast_whilestatement_hpp

#include "ast.hpp"

class WhileStatement;

class WhileStatement : public Node{
	protected:
		const NodePtr cond;
		const NodePtr body;
	public:
		WhileStatement(const NodePtr _cond, const NodePtr _body) : cond(_cond), body(_body){};
		~WhileStatement(){
			delete cond;
			delete body;
		};
		void translate(std::ostream &dst)const override{
            for(int i=0; i<tab; i++){
                dst<< "\t";
            }
            dst << "while(";
			if(cond != NULL){
				cond->translate(dst);
			}
			dst << "):" << std::endl;
			if(body != NULL){
                tab++;
				body->translate(dst);
                tab--;
			}
            
            
		};
		void compile(std::ostream &dst, InterpretContext &_cntx, unsigned int destloc) const override{
			dst << "if statement compile function not yet implemented" << std::endl;
		};
		unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
