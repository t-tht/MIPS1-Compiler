#ifndef ast_param_hpp
#define	ast_param_hpp

#include "ast.hpp"

class Param;

class Param : public Node{
protected:
	std::string* type;
	std::string* id;
	NodePtr right;
public:
	Param(std::string* _type, std::string* _id, NodePtr _right ) : type(_type), id(_id), right(_right){};
	~Param(){
		delete right;
	};
	void translate(std::ostream &dst)const override{
		dst<< *type << " " << *id;
		if(right != NULL){
			dst << ",";
			right->translate(dst);
		}

	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
		if(right != NULL){
			right->compile(dst,cntx,destloc);
		}
	};
	void GetSize(InterpretContext &cntx) const override{
		cntx.param_no++;
		if(right != NULL){
			right->GetSize(cntx);
		}
	};
};

#endif
