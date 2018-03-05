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
%token T_LBRACKET T_RBRACKET T_CLBRACKET T_CRBRACKET T_SEMICOLON T_COMMA T_EQUALS
%token T_NUMBER T_IDENTIFIER T_RETURN T_INT
%token T_ADD T_VOID

%type <node> Program ReturnStatement FunctionDeclaration Block Expression Term Factor Param  VariableDeclaration BlockList AssignStatement
%type <number> T_NUMBER
%type <string> T_IDENTIFIER T_RETURN T_INT T_ADD Type T_VOID

%start ROOT

%%

ROOT: Program                                          { g_root = $1; }

Program: FunctionDeclaration                                     { $$= new Program($1, NULL); }
        | Program FunctionDeclaration							{ $$= new Program($1, $2);}
        |VariableDeclaration                                    { $$ = new Program($1, NULL);}

FunctionDeclaration: Type T_IDENTIFIER T_LBRACKET T_RBRACKET Block { $$= new FuncDec($1, $2, NULL, $5); }
					| Type T_IDENTIFIER T_LBRACKET Param T_RBRACKET Block { $$= new FuncDec($1, $2, $4, $6); }


VariableDeclaration: Type T_IDENTIFIER T_SEMICOLON            {$$= new VarDec($1, $2, NULL);}
             | Type T_IDENTIFIER T_EQUALS Expression T_SEMICOLON   {$$ = new VarDec($1, $2, $4);}

//Statement: CompoundStatement                        { $$= $1; }
//            |SimpleStatement                                {$$ = $1;}


//CompoundStatement: Block                            { $$= $1;}

//SimpleStatement: ReturnStatement                    {$$ = $1;}


Block: T_CLBRACKET BlockList T_CRBRACKET                    { $$= $2;}
//T_CLBRACKET T_CRBRACKET                      { $$= new Block(NULL);}

BlockList:  Statements                              {$$=$1;}
            |BlockList Statements                  { $$ = $2;}
Statements: ReturnStatement                     {$$= $1;}
            |AssignStatement                       {$$=$1;}

AssignStatement: Type T_IDENTIFIER T_SEMICOLON            {$$= new AssignmentStatement($1, $2, NULL);}
                    | Type T_IDENTIFIER T_EQUALS Expression T_SEMICOLON   {$$ = new AssignmentStatement($1, $2, $4);}
                    | T_IDENTIFIER T_EQUALS Expression T_SEMICOLON  {$$ = new AssignmentStatement(NULL, $1, $3);}

//TODO: ADD more to blocklist and make it recursive
//TODO: Define a class for variable z=7; possibly using variable declaration
//TODO: Define if statement class- including comparison expression
//TODO: Define a scope class

ReturnStatement: T_RETURN Expression T_SEMICOLON                  { $$= new ReturnStat($2); }

Expression : Term                      { $$ = $1; }
            | Expression T_PLUS Term         { $$ = new BinExpr ($1, new std::string("+"), $3); }
            | Expression T_MINUS Term        {$$ = new BinExpr ($1,new std::string("-"), $3);}

Term : Factor                     { $$ = $1; }
        | Term T_TIMES Factor        { $$ = new BinExpr($1,new std::string("*"), $3); }
        | Term T_DIVIDE Factor       { $$ = new BinExpr($1,new std::string("/"),$3); }


Factor: T_NUMBER           { $$ = new Number( $1 ); }
        |T_IDENTIFIER        { $$ = new Variable($1); }
        | T_IDENTIFIER T_LBRACKET T_RBRACKET {  $$ = new FuncCallExpr($1, NULL);}
		| T_IDENTIFIER T_LBRACKET Param T_RBRACKET {  $$ = new FuncCallExpr($1, $3);}


Param : Type T_IDENTIFIER             { $$ = new Param($1, $2, NULL);}
        |Type T_IDENTIFIER T_COMMA Param { $$ = new Param($1, $2, $4);}
			
Type: T_INT                         { $$ = new std::string("int");}
    | T_VOID                         { $$ = new std::string("void");}


%%
const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
