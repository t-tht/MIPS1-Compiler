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
//<<<<<<< HEAD
//        virtual void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
//            if(*op=="+"){
//                //left->compile(dst, context, destloc);
//                //right->compile(dst, context, destloc);
//                cout<< "\taddu\t$" << destloc<< ", $"<< destloc<< ", $" <<
//            }
//
//
//
//=======
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{

			dst << "compile function not yet implemented" << std::endl;
		};

};

#endif
