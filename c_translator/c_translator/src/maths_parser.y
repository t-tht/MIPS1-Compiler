%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT
%token T_LBRACKET T_RBRACKET
%token T_LOG T_EXP T_SQRT
%token T_NUMBER T_VARIABLE

%type <expr> EXPR TERM FACTOR
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%%

ROOT : PROGRAM 												{ g_root = $1; }

FUNCTION :	T_TYPE T_IDENTIFIER T_LBRACKET STATEMENT T_RBRACKET T_CLBRACKET STATEMENT T_CRBRACKET	{$$ = new FunctionDec($1,$2,$7);}
STATEMENT :	T_RETURN T_NUMBER T_SEMICOLON	{$$ = new Statement($2);}
EXPERSSION :	T_NUMBER	{$$ = new Number($2);}

%%
const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}


