#ifndef ast_param_hpp
#define	ast_param_hpp

class Param;

class Param : public Node{
	protected:
		NodePtr left;
		NodePtr right;
		const NodePtr left;
		const NodePtr right;
	public:
		Param(const NodePtr _left, NodePtr _right) : left(_left), right(_right){};
		~Param(){
			delete left;
			delete right;
		};
		void translate(std::ostream &dst)const override{
			if(left != NULL){
				left->translate(dst);
			}
			if(right != NULL){
				dst << ",";
				right->translate(dst);
			}
			
		};
		void print(std::ostream &dst)const override{};
};

#endif