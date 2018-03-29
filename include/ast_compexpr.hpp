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
		// dst << "#comp expr--start" << std::endl;
		/*
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
	*/
	if(left != NULL && right != NULL && *op != "||"){
		cntx.RegSetUsed(destloc);
		left->compile(dst, cntx, destloc);
		std::vector<unsigned int> temp = cntx.AvailableReg();
		cntx.RegSetUsed(temp[0]);
		right->compile(dst,cntx, temp[0]);

		//destloc = left			//temp[0] = right

		if(*op == "=="){

			dst << "\tbne\t\t$" << destloc << ", $" << temp[0] << ", exit" << jump << std::endl << std::endl;

		}else if(*op == "!="){

			dst << "\tbeq\t\t$" << destloc << ", $" << temp[0] << ", exit" << jump << std::endl << std::endl;

		}else if(*op == "<"){

			dst << "\tbge\t$" << destloc << ", $" << temp[0] << ", exit"<< jump<< std::endl;

		}else if(*op == "<="){

  			dst << "\tslt\t\t$" << temp[0] << ", $" << temp[0] << ", $" << destloc << std::endl;
			dst << "\tbne\t\t$" << temp[0] << ", $0, exit" << jump << std::endl << std::endl;

		}else if(*op == ">"){

			dst << "\tslt\t\t$" << temp[0] << ", $" << temp[0] << ", $" << destloc << std::endl;
			dst << "\tbeq\t\t$" << temp[0] << ", $0, exit" << jump << std::endl << std::endl;

		}else if(*op == ">="){

			dst << "\tslt\t\t$" << temp[0] << ", $" << destloc << ", $" << temp[0] << std::endl;
			dst << "\tbne\t\t$" << temp[0] << ", $0, exit" << jump << std::endl << std::endl;

		}else if(*op == "&&"){

		}else{
			dst << "not implemented" << std::endl;
		}
		cntx.RegSetAvailable(temp[0]);
		cntx.RegSetAvailable(destloc);
	}else if(left != NULL && right != NULL && *op == "||"){
		cntx.RegSetUsed(destloc);
		left->compile(dst, cntx, destloc);
		std::vector<unsigned int> temp = cntx.AvailableReg();
		cntx.RegSetUsed(temp[0]);
		right->compile(dst,cntx, temp[0]);
		//
		cntx.RegSetAvailable(temp[0]);
		cntx.RegSetAvailable(destloc);
	}
	// dst << "#comp expr--end" << std::endl;
};
unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
