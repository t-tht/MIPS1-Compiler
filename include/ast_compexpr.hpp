#ifndef ast_CompExpr_HPP
#define ast_CompExpr_HPP

#include "ast.hpp"

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
				left->translate(dst);
			}
			if(op != NULL){
				dst << *op;
			}
			if(right != NULL){
				right->translate(dst);
			}
		};
		void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
            std::vector<unsigned int> temp = cntx.AvailableReg();
            cntx.RegSetUsed(temp[0]);
            cntx.RegSetUsed(temp[1]);
            if(*op == "<"){
                left->compile(dst, cntx, temp[0]);
                right->compile(dst,cntx, temp[1]);
                dst << "\tbge\t$" << temp[0] << ", $" << temp[1] << ",link"<< ++jump<< std::endl;
                cntx.RegSetAvailable(temp[0]);
                cntx.RegSetAvailable(temp[1]);
            }
		};
		unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
