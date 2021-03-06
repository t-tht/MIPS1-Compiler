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
%token T_LBRACKET T_RBRACKET T_CLBRACKET T_CRBRACKET T_SEMICOLON T_COMMA T_EQUALS T_LESSTHANEQ T_MORETHANEQ T_CONDEQ T_NOTEQ T_LOGAND T_LOGOR T_IF T_MORETHAN T_LESSTHAN
%token T_NUMBER T_IDENTIFIER T_RETURN T_INT T_ELSE T_WHILE T_INCREMENT T_DECREMENT
%token T_ADD T_VOID T_FOR

%type <node> Program Block BlockList Term Factor
%type <node> FunctionDeclaration Param VariableDeclaration GlobalVariableDeclaration
%type <node> FunctionCall Arg
%type <node> Statements IfStatement AssignStatement ReturnStatement WhileStatement ForStatement
%type <node> Expression BinaryExpression  CompareExpressionAndOr CompareExpression IncrementDecrement
%type <number> T_NUMBER
%type <string> T_IDENTIFIER T_RETURN T_INT T_ADD Type T_VOID T_FOR
%type <string> CompareOp

%start ROOT

%%

ROOT:
    Program                                                                        { g_root = $1; }


Program:
 FunctionDeclaration                                                            { $$ = new Program($1, NULL); }
|FunctionDeclaration Program 							                        { $$ = new Program($1, $2); }
|GlobalVariableDeclaration                                                      { $$ = new Program($1, NULL); }
|GlobalVariableDeclaration Program                                              { $$ = new Program($1, $2); }


GlobalVariableDeclaration:
 Type T_IDENTIFIER T_SEMICOLON                                                  { $$ = new GlobalVariable($1, $2, NULL); }
|Type T_IDENTIFIER T_EQUALS Expression T_SEMICOLON                              { $$ = new GlobalVariable($1, $2, $4); }



FunctionDeclaration:
 Type T_IDENTIFIER T_LBRACKET T_RBRACKET Block                                  { $$ = new FuncDec($1, $2, NULL, $5); }
|Type T_IDENTIFIER T_LBRACKET Param T_RBRACKET Block                            { $$ = new FuncDec($1, $2, $4, $6); }


VariableDeclaration:
 Type T_IDENTIFIER T_SEMICOLON                                                  { $$ = new VarDec($1, $2, NULL); }
|Type T_IDENTIFIER T_EQUALS Expression T_SEMICOLON                              { $$ = new VarDec($1, $2, $4); }


Block:
 T_CLBRACKET BlockList T_CRBRACKET                                              { $$ = $2; }


BlockList:
 Statements                                                                     { $$ = new Block($1, NULL); }
|BlockList Statements                                                           { $$ = new Block($1, $2); }
|VariableDeclaration                                                            { $$ = new Block($1, NULL); }
|BlockList VariableDeclaration                                                  { $$ = new Block($1, $2); }

Statements:
ReturnStatement                                                                 { $$ = $1; }
|AssignStatement                                                                { $$ = $1; }
|IfStatement                                                                    { $$ = $1; }
|WhileStatement                                                                 { $$ = $1; }
|ForStatement                                                                 { $$ = $1; }

WhileStatement:
T_WHILE T_LBRACKET CompareExpressionAndOr T_RBRACKET Block                           { $$= new WhileStatement($3, $5); }

ForStatement:
T_FOR T_LBRACKET VariableDeclaration CompareExpression T_SEMICOLON IncrementDecrement T_RBRACKET Block                           { $$= new ForStatement($3, $4, $6, $8); }

ReturnStatement:
 T_RETURN Expression T_SEMICOLON                                                { $$ = new ReturnStat($2); }


AssignStatement:
 T_IDENTIFIER T_EQUALS Expression T_SEMICOLON                                   { $$ = new AssignmentStatement(NULL, $1, $3); }


IfStatement:
 T_IF T_LBRACKET CompareExpression T_RBRACKET Block                             { $$ = new IfStatement($3, $5, NULL); }
|T_IF T_LBRACKET CompareExpression T_RBRACKET Block T_ELSE Block                { $$ = new IfStatement($3, $5, $7); }


CompareExpressionAndOr:
 CompareExpression T_LOGAND CompareExpression                                   { $$ = new CompExpr($1, new std::string("&&"), $3); }
|CompareExpression T_LOGOR CompareExpression                                    { $$ = new CompExpr($1, new std::string("||"), $3); }
|CompareExpression                                                              { $$ = $1; }


CompareExpression:
 Expression CompareOp Expression                                                { $$ = new CompExpr($1, $2, $3); }
|CompareExpressionAndOr                                                         { $$ = $1;}


CompareOp:
 T_LESSTHANEQ                                                                   { $$ = new std::string("<="); }
|T_MORETHANEQ                                                                   { $$ = new std::string("=>"); }
|T_CONDEQ                                                                       { $$ = new std::string("=="); }
|T_NOTEQ                                                                        { $$ = new std::string("!="); }
|T_MORETHAN                                                                     { $$ = new std::string(">"); }
|T_LESSTHAN                                                                     { $$ = new std::string("<"); }

Expression :
 BinaryExpression                                                               { $$ = $1; }
|Term                                                                           { $$ = $1; }
|FunctionCall                                                                   { $$ = $1; }
|IncrementDecrement                                                             { $$ = $1; }

IncrementDecrement:
 T_IDENTIFIER T_INCREMENT                                                     { $$ = new IncrementDecrement(new std::string("post"), new std::string("+"), $1); }
|T_IDENTIFIER T_DECREMENT                                                   { $$ = new IncrementDecrement(new std::string("post"), new std::string("-"), $1); }
|T_INCREMENT T_IDENTIFIER                                                     { $$ = new IncrementDecrement(new std::string("pre"), new std::string("+"), $2); }
|T_DECREMENT T_IDENTIFIER                                                   { $$ = new IncrementDecrement(new std::string("pre"), new std::string("-"), $2); }



FunctionCall:
T_IDENTIFIER T_LBRACKET T_RBRACKET                                              { $$ = new FuncCallExpr($1, NULL); }
|T_IDENTIFIER T_LBRACKET Arg T_RBRACKET                                         { $$ = new FuncCallExpr($1, $3); }


BinaryExpression :
 BinaryExpression T_PLUS Term                                                   { $$ = new BinExpr($1, new std::string("+"), $3); }
|BinaryExpression T_MINUS Term                                                  { $$ = new BinExpr($1, new std::string("-"), $3); }
|Term                                                                           { $$ = $1; }


Term:
 Factor                                                                         { $$ = $1; }
|Term T_TIMES Factor                                                            { $$ = new BinExpr($1, new std::string("*"), $3); }
|Term T_DIVIDE Factor                                                           { $$ = new BinExpr($1, new std::string("/"), $3); }


Factor:
 T_NUMBER                                                                       { $$ = new Number($1); }
|T_IDENTIFIER                                                                   { $$ = new Variable($1); }
|T_CLBRACKET BinaryExpression T_CRBRACKET                                       { $$ = $2; }
|FunctionCall                                                                   { $$ = $1; }

Param:
 Type T_IDENTIFIER                                                              { $$ = new Param($1, $2, NULL); }
|Type T_IDENTIFIER T_COMMA Param                                                { $$ = new Param($1, $2, $4); }


Arg:
 Expression                                                                     { $$ = new Arg($1, NULL); }
|Expression T_COMMA Arg                                                         { $$ = new Arg($1, $3); }


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
