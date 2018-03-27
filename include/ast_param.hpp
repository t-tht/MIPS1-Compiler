#ifndef ast_param_hpp
#define	ast_param_hpp

#include "ast.hpp"

class Param;

class Param : public Node{
protected:
	std::string* type;
	std::string* id;
    double Number;
	NodePtr right;
public:
	Param(std::string* _type, std::string* _id, NodePtr _right ) : type(_type), id(_id), right(_right){};
    Param(double _Number, NodePtr _right ) : Number(_Number), right(_right){};
	~Param(){
		delete right;
	};
	void translate(std::ostream &dst)const override{
        if(id != NULL){
             dst<< *id;
        }
        else{
            dst<< Number;
        }
        
		if(right != NULL){
			dst << ",";
			right->translate(dst);
		}

	};
	void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
		if(destloc < 8){
			dst << "\tsw\t\t$" << destloc << ", " << cntx.FindOnStack(*id) << "($fp)" << std::endl;
			destloc++;
		}
		if(right != NULL){
			right->compile(dst, cntx, destloc);
		}
	};
	unsigned int GetContext(InterpretContext &cntx) const override{
		cntx.ParamNoIncrement();
		unsigned int offset = 128 + ((cntx.GetParamNo()-1)*4);
		cntx.AddToStack(*id, offset);
		if(right!=NULL){
			right->GetContext(cntx);
		}
		return 0;
	};
};

#endif
