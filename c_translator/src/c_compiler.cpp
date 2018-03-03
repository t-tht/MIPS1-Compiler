#include "../include/ast.hpp"
#include <iostream>

int main()
{
    const Node *ast=parseAST();

    ast->translate(std::cout);
    std::cout<<std::endl;

    return 0;
}
