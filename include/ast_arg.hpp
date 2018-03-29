#ifndef ast_arg_hpp
#define ast_arg_hpp

#include "ast.hpp"

class Arg;

class Arg : public Node{
protected:
    NodePtr expr;
    NodePtr right;
public:
    Arg(NodePtr _expr, NodePtr _right) : expr(_expr), right(_right){};
    ~Arg(){
        delete expr;
        delete right;
    };
    void translate(std::ostream &dst) const override{
        if(expr != NULL){
            expr->translate(dst);
        }
        if(right != NULL){
            dst << ", ";
            right->translate(dst);
        }
    };
    void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
        if(destloc < 8){
            if(expr != NULL){
                expr->compile(dst, cntx, destloc);
            }
        }else if(destloc > 7){
            if(expr != NULL){
                expr->compile(dst, cntx, 2);
            }
            dst << "\tsw\t\t$" << 2 << ", " << (destloc-8)*4 + 16 << "($sp)" << std::endl;
        }
        destloc++;
        if(right != NULL){
            right->compile(dst, cntx, destloc);
        }
    }
    unsigned int GetContext(InterpretContext &cntx)const override{};
};

#endif
