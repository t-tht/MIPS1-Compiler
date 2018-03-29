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
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
			// dst << "#while statement --start" << std::endl;
			jump++;
			dst << "loop" << jump << ":" << std::endl;
			cond->compile(dst, cntx, destloc);
			body->compile(dst, cntx, destloc);
			dst << "\tb\t\t" << "loop" << jump << std::endl;
			dst << "exit" << jump << ":" << std::endl;
			// dst << "#while statement --end" << std::endl;
		};
		unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
