#ifndef ast_logicalor_hpp
#define ast_logicalor_hpp

#include "ast.hpp"

class LogicalOr;

class LogicalOr : public Node{
protected:
	const NodePtr left;
	const NodePtr right;
public:
	LogicalOr(const NodePtr _left, const NodePtr _right) : left(_left), right(_right){};
	~LogicalOr(){
		delete left;
		delete right;
	};
	void translate(std::ostream &dst)const override{
		if(left != NULL){
			left->translate(dst);
		}
		dst << "||";
		if(right != NULL){
			right->translate(dst);
		}
	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{

		if(left != NULL && right != NULL){
			cntx.RegSetUsed(destloc);
			left->compile(dst, cntx, destloc);
			std::vector<unsigned int> temp = cntx.AvailableReg();
			cntx.RegSetUsed(temp[0]);
			right->compile(dst,cntx, temp[0]);

			//destloc = left			//temp[0] = right
			// all jumps to false label


			cntx.RegSetAvailable(temp[0]);
			cntx.RegSetAvailable(destloc);
		}
	};
	unsigned int GetContext(InterpretContext &cntx) const override{return 0;};
};

#endif
