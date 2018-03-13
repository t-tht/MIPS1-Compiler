#ifndef ast_constexpr_hpp
#define ast_constexpr_hpp

#include "ast.hpp"

class ConstExpr;

class ConstExpr : public Node{
protected:
    int val;
public:
    ConstExpr(int _val) : val(_val){};
    ~ConstExpr(){};

    void translate(std::ostream &dst)const override{
        dst << val;
    };

    void compile(std::ostream &dst, InterpretContext &cntx, unsigned int destloc)const override{
        dst << "\t" <<"li\t$" << destloc << ", " << val << std::endl;
    };
};

#endif
