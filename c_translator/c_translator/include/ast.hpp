#ifndef ast_hpp
#define ast_hpp
#include <string>
#include <iostream>
#include <map>

#include <memory>
//----------------------------------Declaration-------------------------------------
class Node;

//----------------------------------Node----------------------------------------

typedef const Node* NodePtr;
//https://stackoverflow.com/questions/750178/is-it-a-good-idea-to-typedef-pointers
class Node
{
public:
    virtual ~Node()
    {}

    //! Tell and expression to print itself to the given stream
    virtual void print(std::ostream &dst) const =0;

    //! Evaluate the tree using the given mapping of variables to numbers
};
// ---------------------------------PROGRAM---------------------------------



// #include "ast/ast_expression.hpp"
// #include "ast/ast_primitives.hpp"
// #include "ast/ast_operators.hpp"
// #include "ast/ast_functions.hpp"


extern const Node *parseAST();




#endif