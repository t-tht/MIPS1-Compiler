#include "../include/ast.hpp"
#include "../include/ast_interpretcontext.hpp"
#include <iostream>
int tab=0;
std::vector<std::string> globalvars;

int main(int argc, char* argv[]){

freopen(argv[2], "r", stdin);
freopen(argv[4], "w", stdout);

    const Node *ast=parseAST();
   InterpretContext cntx;
 unsigned int destloc = 0;


   if(std::string(argv[1])== "--compile"){
      ast->compile(std::cout, cntx, destloc);
   }

if(std::string(argv[1])== "--translate"){
        ast->translate(std::cout);
  std::cout<<"\n# Boilerplat" << std::endl;
  std::cout<<"if __name__ == \"__main__\":" << std::endl;
  std::cout<<"\timport sys\n\tret=main()\n\tsys.exit(ret)"<<std::endl;
    std::cout<< "\n";
       }

   fclose(stdin);
   fclose(stdout);


    return 0;
}
