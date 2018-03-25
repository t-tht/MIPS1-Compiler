#ifndef ast_block_hpp
#define ast_block_hpp

#include "ast.hpp"

class Block;

class Block : public Node{
	protected:
		const NodePtr left;
		const NodePtr right;
	public:
		Block(const NodePtr _left, const NodePtr _right) : left(_left), right(_right){};
		~Block(){
			delete left;
			delete right;
		};
		void translate(std::ostream &dst)const override{
            int x=0;
            if(left != NULL){
				left->translate(dst);
                x=tab;
			}
			if(right != NULL){
                tab=x;
				right->translate(dst);
			}
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
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
