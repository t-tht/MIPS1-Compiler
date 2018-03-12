#include "../include/ast.hpp"
#include <iostream>

extern const ASTnode *parseAST();

int main(int argc, char* argv[]){

    InterpretContext cntx = new InterpretContext();              //not used atm
    unsigned int destloc = 0;           //not used atm

    const Node *ast=parseAST();

//compile to mips
    ast->compile(std::cout, cntx, destloc);

// translate to python
   // ast->translate(std::cout);

   std::cout<<std::endl;

    return 0;
}
