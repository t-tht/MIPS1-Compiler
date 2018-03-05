#ifndef ast_block_hpp
#define ast_block_hpp

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
			if(left != NULL){
				left->translate(dst);
			}
			if(right != NULL){
				right->translate(dst);
			}
		};
		void print(std::ostream &dst)const override{
			if(left != NULL){
				left->print(dst);
			}
			if(right != NULL){
				right->print(dst);
			}
		};
};

#endif