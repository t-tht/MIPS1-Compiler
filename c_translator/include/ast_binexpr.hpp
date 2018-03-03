#ifndef ast_binexpr_hpp
#define ast_binexpr_hpp

class BinExpr;

class BinExpr : public Node{
	protected:
		NodePtr left;
		NodePtr right;
		std::string* op;
	public:
		BinExpr(NodePtr _left, NodePtr _right, std::string* _op) : left(_left), right(_right), op(_op){};
		~BinExpr(){};
		virtual void translate(std::ostream &dst)const override{
			left->translate(dst);
			dst << *op;
			right->translate(dst);
		};
		virtual void print(std::ostream &dst)const override{};
};

#endif
