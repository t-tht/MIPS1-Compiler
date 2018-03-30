#ifndef ast_forstatement_hpp
#define ast_forstatement_hpp

#include "ast.hpp"

class ForStatement;

class ForStatement : public Node{
	protected:
        const NodePtr vardec;
		const NodePtr cond;
		const NodePtr body;
        const NodePtr increment;
	public:
        ForStatement(const NodePtr _vardec, const NodePtr _cond, const NodePtr _body, const NodePtr _increment) : vardec(_vardec), cond(_cond), body(_body), increment(_increment){};
		~ForStatement(){
			delete cond;
			delete body;
		};
		void translate(std::ostream &dst)const override{};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
            dst << "#for statement--start" << std::endl;
            jump++;
                        vardec->GetContext(cntx);
                vardec->compile(dst,cntx,destloc);
            dst<<"\nfor"<< jump << ":\n";

            cond->compile(dst,cntx,destloc);
            body->compile(dst,cntx,destloc);
            increment->compile(dst,cntx,destloc);
            
            dst<<"\nj\tfor"<< jump;
            dst<<"\nexit"<<jump<<":\n";
            jump--;
		};
		unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
