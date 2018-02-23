#ifndef ast_astnode_hpp
#define ast_astnode_hpp

#include "ast_astnode.hpp"

class Function
    : public Program
{
protected:
    ASTNodePtr arg;
    Function(ASTNodePtr _arg)
        : arg(_arg)
    {}
public:
    virtual const char * getFunction() const =0;

    ProgramPtr getArg() const
    { return arg; }

    virtual void print(std::ostream &dst) const override
    {
        dst<<getFunction()<<"( ";
        arg->print(dst);
        dst<<" )";
    }

    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const override
    {
        // NOTE : This should be implemented by the inheriting function nodes, e.g. LogFunction
        throw std::runtime_error("FunctionOperator::evaluate is not implemented.");
    }
};



#endif
