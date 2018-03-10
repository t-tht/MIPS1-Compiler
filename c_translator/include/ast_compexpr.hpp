#ifndef ast_CompExpr_HPP
#define ast_CompExpr_HPP

class CompExpr;

class CompExpr : public Node{
	protected:
		const NodePtr left;
		std::string* op;
		const NodePtr right;
	public:
		CompExpr(const NodePtr _left, std::string* _op, const NodePtr _right) : left(_left), op(_op), right(_right){};
		~CompExpr(){
			delete left;
			delete right;
		};
		void translate(std::ostream &dst)const override{
			if(left != NULL){
				left->compile(dst);
			}
			if(op != NULL){
				dst << " " << *op << " ";
			}
			if(right != NULL){
				right->compile(dst);
			}
		};
		void compile(std::ostream &dst)const override{};
};

#endif
