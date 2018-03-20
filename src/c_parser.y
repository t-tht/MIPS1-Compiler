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
%token T_TIMES T_DIVIDE T_PLUS T_MINUS
%token T_LBRACKET T_RBRACKET T_CLBRACKET T_CRBRACKET T_SEMICOLON T_COMMA T_EQUALS T_LESSTHANEQ T_MORETHANEQ T_CONDEQ T_NOTEQ T_LOGAND T_LOGOR T_IF
%token T_NUMBER T_IDENTIFIER T_RETURN T_INT
%token T_ADD T_VOID

%type <node> Program Block BlockList Term Factor
%type <node> FunctionDeclaration VariableDeclaration Arg
%type <node> FunctionCall Param
%type <node> Statements IfStatement AssignStatement ReturnStatement
%type <node> Expression BinaryExpression CompareExpression
%type <number> T_NUMBER
%type <string> T_IDENTIFIER T_RETURN T_INT T_ADD Type T_VOID
%type <string> BinaryOp CompareOp

%start ROOT

%%

ROOT:
 Program                                                                        { g_root = $1; }


Program:
 FunctionDeclaration                                                            { $$ = new Program($1, NULL); }
|Program FunctionDeclaration							                        { $$ = new Program($1, $2); }
|VariableDeclaration                                                            { $$ = new Program($1, NULL); }


FunctionDeclaration:
 Type T_IDENTIFIER T_LBRACKET T_RBRACKET Block                                  { $$ = new FuncDec($1, $2, NULL, $5); }
|Type T_IDENTIFIER T_LBRACKET Param T_RBRACKET Block                            { $$ = new FuncDec($1, $2, $4, $6); }


VariableDeclaration:
 Type T_IDENTIFIER T_SEMICOLON                                                  { $$ = new VarDec($1, $2, NULL); }
|Type T_IDENTIFIER T_EQUALS Expression T_SEMICOLON                              { $$ = new VarDec($1, $2, $4); }


Block:
 T_CLBRACKET BlockList T_CRBRACKET                                              { $$ = $2; }


BlockList:
 Statements                                                                     { $$ =  new Block($1, NULL); }
|BlockList Statements                                                           { $$ = new Block($1, $2); }


Statements:
 ReturnStatement                                                                { $$ = $1; }
|AssignStatement                                                                { $$ = $1; }
|IfStatement                                                                    { $$ = $1; }


ReturnStatement:
 T_RETURN Expression T_SEMICOLON                                                { $$ = new ReturnStat($2); }


AssignStatement:
 Type T_IDENTIFIER T_SEMICOLON                                                  { $$ = new AssignmentStatement( $1,$2, NULL); }
|Type T_IDENTIFIER T_EQUALS Expression T_SEMICOLON                              { $$ = new AssignmentStatement($1, $2, $4); }
|T_IDENTIFIER T_EQUALS Expression T_SEMICOLON                                   { $$ = new AssignmentStatement(NULL, $1, $3); }

IfStatement:
 T_IF T_LBRACKET CompareExpression T_RBRACKET Block                             { $$ = new IfStatement($3, $5); }


CompareExpression:
 Expression CompareOp Expression                                                { $$ = new CompExpr($1, $2, $3); }


CompareOp:
 T_LESSTHANEQ                                                                   { $$ = new std::string("<="); }
|T_MORETHANEQ                                                                   { $$ = new std::string("=>"); }
|T_CONDEQ                                                                       { $$ = new std::string("=="); }
|T_NOTEQ                                                                        { $$ = new std::string("!="); }
|T_LOGAND                                                                       { $$ = new std::string("&&"); }
|T_LOGOR                                                                        { $$ = new std::string("||"); }


Expression :
 BinaryExpression                                                               { $$ = $1; }
|Term                                                                           { $$ = $1; }
|FunctionCall                                                                   { $$ = $1; }

FunctionCall:
T_IDENTIFIER T_LBRACKET T_RBRACKET                                              { $$ = new FuncCallExpr($1, NULL); }
|T_IDENTIFIER T_LBRACKET Arg T_RBRACKET                                       { $$ = new FuncCallExpr($1, $3); }
//need to change param to arg for ambiguity

BinaryExpression :
 Expression BinaryOp Expression                                                 { $$ = new BinExpr($1, $2, $3); }

BinaryOp:
 T_PLUS                                                                         { $$ = new std::string("+"); }
|T_MINUS                                                                        { $$ = new std::string("-"); }
|T_TIMES                                                                        { $$ = new std::string("*"); }
|T_DIVIDE                                                                       { $$ = new std::string("/"); }

Term:
 Factor                                                                         { $$ = $1; }
|Term T_TIMES Factor                                                            { $$ = new BinExpr($1,new std::string("*"), $3); }
|Term T_DIVIDE Factor                                                           { $$ = new BinExpr($1,new std::string("/"),$3); }


Factor:
 T_NUMBER                                                                       { $$ = new Number($1); }
|T_IDENTIFIER                                                                   { $$ = new Variable($1); }


Param:  //for function declaration
 Type T_IDENTIFIER                                                              { $$ = new Param($1, $2, NULL); }
|Param T_COMMA Type T_IDENTIFIER                                                { $$ = new Param($3, $4, $1); }


Arg:    //for function calls
 T_IDENTIFIER                                                                   { $$ = new Param(NULL, $1, NULL); }
|Type T_IDENTIFIER                                                              { $$ = new Param($1, $2, NULL); }
|Arg T_COMMA T_IDENTIFIER                                                       { $$ = new Param(NULL, $3, $1); }
|Arg T_COMMA Type T_IDENTIFIER                                                  { $$ = new Param($3, $4, $1); }


Type:
 T_INT                                                                          { $$ = new std::string("int"); }
|T_VOID                                                                         { $$ = new std::string("void"); }


%%
const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
