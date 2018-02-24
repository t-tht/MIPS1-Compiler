#include "ast.hpp"
#include <iostream>

int main()
{
    const Node *ast=parseAST();

    ast->print();
    std::cout<<std::endl;

    return 0;
}
