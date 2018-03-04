#ifndef ast_param_hpp
#define	ast_param_hpp

class Param;

class Param : public Node{
	protected:
		NodePtr left;
		NodePtr right;
	public:
		Param(const NodePtr _left, NodePtr _right) : left(_left), right(_right){};
		~Param(){};
		void translate(std::ostream &dst)const override{
			if(left != NULL && right != NULL){
				left->translate(dst);
				dst << ",";
				right->translate(dst);
			}else if(left != NULL && right == NULL){
				left->translate(dst);
			}
			
		};
		void print(std::ostream &dst)const override{};
};

#endif