#ifndef ast_globalvariable_hpp
#define ast_globalvariable_hpp

#include "ast.hpp"

class GlobalVariable;

class GlobalVariable : public Node{
protected:
    std::string* type;
    std::string* id;
    NodePtr val;
public:
    GlobalVariable(std::string* _type, std::string* _id, NodePtr _val) : type(_type), id(_id), val(_val){};
    ~GlobalVariable(){
        delete val;
    };
    void translate(std::ostream &dst)const override{};
    void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
        this->GetContext(cntx);
        dst << "a:" << std::endl;
        dst << "\t\t.word\t";
        if(val != NULL){
        dst << val->GetContext(cntx);
        }
        dst << std::endl;
    };
    unsigned int GetContext(InterpretContext &cntx)const override{
        unsigned int tempv = val->GetContext(cntx);
        cntx.AddGlobal(*id, tempv);
    };
};

#endif
