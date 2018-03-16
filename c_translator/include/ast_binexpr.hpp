#ifndef ast_binexpr_hpp
#define ast_binexpr_hpp

#include "ast.hpp"

class BinExpr;
class BinExpr : public Node{
	protected:
		NodePtr left;
		NodePtr right;
		std::string* op;
	public:
		BinExpr(NodePtr _left, std::string* _op, NodePtr _right) : left(_left), right(_right), op(_op){};
		~BinExpr(){};
		void translate(std::ostream &dst)const override{
			left->translate(dst);
			dst << *op;
			right->translate(dst);
		};

		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
			std::vector<unsigned int> free = cntx.freetempreg();
			if(*op == "+"){
				left->compile(dst, cntx, destloc);
				right->compile(dst, cntx, free[0]);
				dst << "\t" << "" << "\t" << "$" << destloc << ", $" << destloc << ", $" << free[0] << std::endl;
			}else if(*op == "-"){

			}else if(*op == "*"){

			}else if(*op == "/"){

			}
		};

};

#endif
