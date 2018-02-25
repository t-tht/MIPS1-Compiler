%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Node *node;
  Statement* statement;
  double number;
  std::string *string;
}

%token T_LBRACKET T_RBRACKET T_CLBRACKET T_CRBRACKET T_SEMICOLON
%token T_NUMBER T_IDENTIFIER T_RETURN T_TYPE

%type <node> PROGRAM FUNCTION EXPRESSION 
%type <statement> STATEMENT
%type <number> T_NUMBER
%type <string> T_IDENTIFIER T_RETURN T_TYPE

%start ROOT

%%
ROOT: Program                                           { g_root = $1; }

Program: FunctionDeclaration                            { $$= new Program($1); }

FunctionDeclaration: TYPE T_IDENTIFIER T_LBRACKET T_RBRACKET Block { $$= new FuncDeclaration($1, $2, NULL, $5); }

Statement: CompoundStatement                        { $$= $1; }
            |SimpleStatement                                {$$ = $1;}


CompoundStatement: Block                            { $$= $1;}

SimpleStatement: ReturnStatement                    {$$ = new ReturnStatement($1);}


Block: T_CLBRACKET T_CRBRACKET                      { $$= new Block(NULL);}
| T_CLBRACKET Statement T_CRBRACKET                    { $$= new Block($2);}


ReturnStatement: T_RETURN Expr T_SEMICOLON                  { $$= new Expr($1);}

Expr: T_NUMBER                      { $$= new Number($1);}

TYPE: T_INT                         { $$ = new std::string("int"); }
    |T_VOID                               {  $$= new std::string("void");}


Type
//
//ROOT : FUNCTION 												{ g_root = $1; }
//
//FUNCTION :	T_TYPE T_IDENTIFIER T_LBRACKET T_RBRACKET T_CLBRACKET STATEMENT T_CRBRACKET	{$$ = new Function($1,$2,NULL,$6);}
//STATEMENT :	T_RETURN T_NUMBER T_SEMICOLON	{$$ = new Statement($2);}
//
//DECLARATION:  VARDEC 
//			| FUNCDEC
//


%%
const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
