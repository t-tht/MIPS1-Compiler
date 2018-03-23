#ifndef ast_assignment_hpp
#define ast_assignment_hpp

#include "ast.hpp"

class AssignmentStatement;

class AssignmentStatement: public Node{
protected:
    std::string* type;
    std::string* id;
    NodePtr Expr;
public:
    AssignmentStatement(std::string* _type, std::string* _id, NodePtr _Expr): type(_type), id(_id), Expr(_Expr){}
    ~AssignmentStatement(){
    }
    void translate(std::ostream &dst) const override{
        if(type != NULL){
            dst << *type;
        }
        dst<< " "<< *id;
        if(Expr != NULL){
            dst << " = ";
            Expr ->translate(dst);
        }

    }
    void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc) const override{};
    unsigned int GetContext(InterpretContext &cntx) const override{
        unsigned int exprv = Expr->GetContext(cntx);
        cntx.UpdateVariable(*id,exprv);
        return 0;
    };
};

#endif
