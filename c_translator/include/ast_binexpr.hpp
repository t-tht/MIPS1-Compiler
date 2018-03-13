#ifndef ast_binexpr_hpp
#define ast_binexpr_hpp

#include "ast_global.hpp"

class BinExpr;
class BinExpr : public Node{
	protected:
		NodePtr left;
		NodePtr right;
		std::string* op;
	public:
		BinExpr(NodePtr _left, std::string* _op, NodePtr _right) : left(_left), right(_right), op(_op){};
		~BinExpr(){};
		virtual void translate(std::ostream &dst)const override{
			left->translate(dst);
			dst << *op;
			right->translate(dst);
		};
		virtual void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
            if(*op=="+"){
                //left->compile(dst, context, destloc);
                //right->compile(dst, context, destloc);
                cout<< "\taddu\t$" << destloc<< ", $"<< destloc<< ", $" <<
            }
            
            
            
			dst << "compile function not yet implemented" << std::endl;
		};

};

#endif
