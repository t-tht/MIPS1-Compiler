#ifndef ast_program_hpp
#define ast_program_hpp

#include "ast.hpp"

class Program;

class Program : public Node{
	protected:
		NodePtr left;
		NodePtr right;
	public:
		Program(const NodePtr _left, const NodePtr _right) : left(_left), right(_right){};
		~Program(){
			delete left;
			delete right;
		};
		void translate(std::ostream &dst) const override{
			if(left != NULL){
				left->translate(dst);
			}
			if(right != NULL){
				right->translate(dst);
			}
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{
			if(left != NULL){
				left->compile(dst, cntx, destloc);
			}
			if(right != NULL){
				right->compile(dst, cntx, destloc);
			}
		};
		unsigned int GetContext(InterpretContext &cntx) const override{
			if(left != NULL){
				left->GetContext(cntx);
			}
			if(right != NULL){
				right->GetContext(cntx);
			}
			return 0;
		};
};

#endif
