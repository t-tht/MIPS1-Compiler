#include "../include/ast.hpp"
#include "../include/ast_interpretcontext.hpp"
#include <iostream>

int main(int argc, char* argv[]){

// freopen(argv[2], "r", stdin);
// freopen(argv[4], "w", stdout);

    const Node *ast=parseAST();
   InterpretContext cntx;
 unsigned int destloc = 99;

   // if(std::string(argv[1])== "--compile"){
        ast->compile(std::cout, cntx, destloc);

   // }

// if(std::string(argv[1])== "--translate"){
        // ast->translate(std::cout);
   // }


    // fclose(stdin);
// fclose(stdout);


    return 0;
}
