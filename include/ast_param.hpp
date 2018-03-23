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
		if(cntx.FindOnStack(*id) < 4){
			dst << "\tsw\t\t$" << cntx.FindOnStack(*id)+4 << ", " << cntx.FindOnStack(*id)*4+cntx.frame_size << "($fp)" << std::endl;
		}
		if(right!= NULL){
			right->compile(dst, cntx, destloc);
		}
	};
	unsigned int GetContext(InterpretContext &cntx) const override{
		cntx.ParamNoIncrement();
		cntx.AddToStack(*id);
		if(right!=NULL){
			right->GetContext(cntx);
		}
		return 0;
	};
};

#endif
