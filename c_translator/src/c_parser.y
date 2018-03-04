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
%token T_NUMBER T_IDENTIFIER T_RETURN T_TYPE
%token T_INT T_VOID T_ADD

%type <node> Program ReturnStatement FunctionDeclaration Block Expression Term Factor Param ParamRecur ParamVar VariableDeclaration
%type <number> T_NUMBER
%type <string> T_IDENTIFIER T_RETURN T_TYPE T_ADD

%start ROOT

%%

ROOT: VariableDeclaration                                          { g_root = $1; }

Program: FunctionDeclaration                                     { $$= new Program($1, NULL); }
        | Program FunctionDeclaration							{ $$= new Program($1, $2);}
        |VariableDeclaration                                    { $$ = new Program($1, NULL);}

FunctionDeclaration: T_TYPE T_IDENTIFIER T_LBRACKET T_RBRACKET Block { $$= new FuncDecl($1, $2, NULL, $5); }
					| T_TYPE T_IDENTIFIER T_LBRACKET ParamRecur T_RBRACKET Block { $$= new FuncDecl($1, $2, $4, $6); }


VariableDeclaration: T_TYPE T_IDENTIFIER T_SEMICOLON            {$$= new VarDec($1, $2, NULL);}
             | T_TYPE T_IDENTIFIER T_EQUALS Expression T_SEMICOLON   {$$ = new VarDec($1, $2, $4);}

//Statement: CompoundStatement                        { $$= $1; }
//            |SimpleStatement                                {$$ = $1;}


//CompoundStatement: Block                            { $$= $1;}

//SimpleStatement: ReturnStatement                    {$$ = $1;}


Block: T_CLBRACKET ReturnStatement T_CRBRACKET                    { $$= $2;}
//T_CLBRACKET T_CRBRACKET                      { $$= new Block(NULL);}



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
		| T_IDENTIFIER T_LBRACKET ParamRecur T_RBRACKET {  $$ = new FuncCallExpr($1, $3);}
		
ParamRecur : Param					{ $$ = new Param($1, NULL); }
		| ParamRecur T_COMMA Param			{ $$ = new Param($1, $3); }
		
Param :     T_NUMBER				{ $$ = new Number($1); }
			| T_IDENTIFIER				{ $$ = new Variable($1);}
		|T_TYPE T_IDENTIFIER { $$ = new ParamVar($1, $2);}
			
			



%%
const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
