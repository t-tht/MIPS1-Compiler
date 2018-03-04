#ifndef ast_param_dec_hpp
#define	ast_param_dec_hpp

class ParamDec;

class ParamDec : public Node{
	protected:
		NodePtr left;
		NodePtr right;
	public:
		ParamDec(const NodePtr _left, NodePtr _right) : left(_left), right(_right){};
		~ParamDec(){};
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