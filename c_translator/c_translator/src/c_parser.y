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
  double number;
  std::string *string;
}

%token T_LBRACKET T_RBRACKET T_CLBRACKET T_CRBRACKET T_SEMICOLON
%token T_NUMBER T_IDENTIFIER T_RETURN T_TYPE

%type <node> PROGRAM FUNCTION STATEMENT EXPRESSION
%type <number> T_NUMBER
%type <string> T_IDENTIFIER T_RETURN T_TYPE

%start ROOT

%%

ROOT : PROGRAM 												{ g_root = $1; }
PROGRAM: FUNCTION                     { $$ = $1; }
FUNCTION :	T_TYPE T_IDENTIFIER T_LBRACKET STATEMENT T_RBRACKET T_CLBRACKET STATEMENT T_CRBRACKET	{$$ = new Function($1,*$2,$4,$7);}
STATEMENT :	T_RETURN EXPRESSION T_SEMICOLON	{$$ = new Statement($2);}
EXPRESSION :	T_NUMBER	{$$ = new Number($1);}

%%
const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
