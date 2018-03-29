#ifndef ast_binexpr_hpp
#define ast_binexpr_hpp

#include "ast.hpp"

class BinExpr;
class BinExpr : public Node{
protected:
	const NodePtr left;
	const NodePtr right;
	std::string* op;
public:
	BinExpr(const NodePtr _left, std::string* _op, const NodePtr _right) : left(_left), right(_right), op(_op){};
	~BinExpr(){
		delete left;
		delete right;
		delete op;
	};

	void translate(std::ostream &dst)const override{
		if((left != NULL) && (right != NULL)){
			left->translate(dst);
			dst << *op;
			right->translate(dst);
		}
	};

	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
		// dst << "#binary expression--start" << std::endl;
		if((left != NULL) && (right != NULL)){
			left->compile(dst, cntx, destloc);
			cntx.RegSetUsed(destloc);
			std::vector<unsigned int> temp = cntx.AvailableReg();
			right->compile(dst, cntx, temp[0]);
			cntx.RegSetUsed(temp[0]);

			if(*op == "+"){

				dst << "\taddu\t$" << destloc << ", $" << destloc << ", $" << temp[0] << std::endl;

			}else if(*op == "-"){

				dst << "\tsubu\t$" << destloc << ", $" << destloc << ", $" << temp[0] << std::endl;

			}else if(*op == "*"){

				dst << "\tmult\t$" << destloc << ", $" << temp[0] << std::endl;
				dst << "\tmflo\t$" << destloc << std::endl;

			}else if(*op == "/"){

				dst << "\tdiv\t$" << destloc << ", $" << temp[0] << std::endl;
				dst << "\tmflo\t$" << destloc << std::endl;

			}
			cntx.RegSetAvailable(temp[0]);
			cntx.RegSetAvailable(destloc);
		}
		// dst << "#binary expression--end" << std::endl;
	};


	unsigned int GetContext(InterpretContext &cntx) const override{
		unsigned int leftv, rightv;
		if(left != NULL){
			leftv = left->GetContext(cntx);
		}
		if(right != NULL){
			rightv = right->GetContext(cntx);
		}
		if(*op == "+"){
			return leftv+rightv;
		}else if(*op == "-"){
			return leftv-rightv;
		}else if(*op == "*"){
			return leftv*rightv;
		}else if(*op == "/"){
			return leftv/rightv;
		}else{
			return -1;
		}
	};
};

#endif
