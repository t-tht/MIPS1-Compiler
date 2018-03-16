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
		~BinExpr(){
			delete op;
		};

		void translate(std::ostream &dst)const override{
			left->translate(dst);
			dst << *op;
			right->translate(dst);
		};

		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
			std::vector<unsigned int> tmp = cntx.freetempregs();
			cntx.regsetused(tmp[0]);
			if(*op == "+"){

				left->compile(dst, cntx, destloc);
				right->compile(dst, cntx, tmp[0]);
				dst << "\taddu\t$" << destloc << ", $" << destloc << ", $" << tmp[0] << std::endl;

			}else if(*op == "-"){

				left->compile(dst, cntx, destloc);
				right->compile(dst, cntx, tmp[0]);
				dst << "\tsub\t$" << destloc << ", $" << destloc << ", $" << tmp[0] << std::endl;

			}else if(*op == "*"){

				left->compile(dst, cntx, destloc);
				right->compile(dst, cntx, tmp[0]);
				dst << "\tmult\t$" << destloc << ", $" << tmp[0] << std::endl;
				dst << "\tmflo\t$" << destloc << std::endl;

			}else if(*op == "/"){

				left->compile(dst, cntx, destloc);
				right->compile(dst, cntx, tmp[0]);
				dst << "\tdiv\t$" << destloc << ", $" << tmp[0] << std::endl;
				dst << "\tmflo\t$" << destloc << std::endl;
			}
		};

};

#endif
