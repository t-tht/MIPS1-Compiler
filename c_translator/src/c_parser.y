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
%token T_INT T_VOID T_ADD

//%type <node> Program Expr FunctionDeclaration Bin_Expr TYPE Statement CompoundStatement SimpleStatement ReturnStatement Block
%type <node> Program ReturnStatement FunctionDeclaration Block
%type <number> T_NUMBER
%type <string> T_IDENTIFIER T_RETURN T_TYPE T_ADD

%start ROOT

%%

ROOT: Program                                           { g_root = $1; }

Program: FunctionDeclaration                                        { $$= $1; }

FunctionDeclaration: T_TYPE T_IDENTIFIER T_LBRACKET T_RBRACKET Block { $$= new FuncDecl($1, $2, NULL, $5); }

//Statement: CompoundStatement                        { $$= $1; }
//            |SimpleStatement                                {$$ = $1;}


//CompoundStatement: Block                            { $$= $1;}

//SimpleStatement: ReturnStatement                    {$$ = $1;}


Block: T_CLBRACKET ReturnStatement T_CRBRACKET                    { $$= $2;}
//T_CLBRACKET T_CRBRACKET                      { $$= new Block(NULL);}



ReturnStatement: T_RETURN T_NUMBER T_SEMICOLON                  { $$= new ReturnStat($1,$2); }

//Expr: Bin_Expr                      {$$= $1;}

//Bin_Expr: T_NUMBER                  {$$ = new NumExpr($1); }
//        |T_NUMBER T_ADD T_NUMBER   {$$ = new ArithExpr($1,$2,$3);}
//
//
//TYPE: T_INT                         { $$ = new std::string("int"); }
//    |T_VOID                               {  $$= new std::string("void");}

/*

ROOT : PROGRAM																			{ g_root = $1; }

PROGRAM : DECL                                                                            { $$ = $1 }

DECL : 	 		      FUNC_DECL															{ $$ = $1; }
					| VAR_DECL															{ $$ = $1; }

VAR_DECL : 			  T_TYPE T_ID T_SEMICOLON											{ $$ = }
					| T_TYPE T_ID T_EQ EXPR T_SEMICOLON									{ $$ = }

FUNC_DECL : 		  T_TYPE T_ID T_LBRACKET PARAM T_RBRACKET T_SEMICOLON				{ $$ = }
					| T_TYPE T_ID T_LBRACKET T_RBRACKET T_SEMICOLON						{ $$ = }
					| T_TYPE T_ID T_LBRACKET PARAM T_RBRACKET BLOCK						{ $$ = }
					| T_TYPE T_ID T_LBRACKET T_RBRACKET BLOCK							{ $$ = }

PARAM :				  T_TYPE T_ID														{ $$ = }
					| PARAM T_COMMA T_TYPE T_ID											{ $$ = }

<<<<<<< HEAD
BLOCK : 			  T_CLBRACKET VAR_DECL T_CRBRACKET									{ $$ = }
					| T_CLBRACKET STAT T_CRBRACKET										{ $$ = }
					| T_CLBRACKET BLOCK T_CRBRACKET										{ $$ = }

=======
BLOCK : 			  T_CLBRACKET MUL_VAR_DECL T_CRBRACKET									{ $$ = }
					| T_CLBRACKET MUL_STAT T_CRBRACKET										{ $$ = }
					| T_CLBRACKET MUL_VAR_DECL MUL_STAT T_CRBRACKET							{ $$ = }
					| T_CLBRACKET MUL_STAT MUL_VAR_DECL T_CRBRACKET
					| T_CLBRACKET T_CLBRACKET

MUL_VAR_DECL :		  VAR_DECL
					| MUL_VAR_DECL VAR_DECL

MUL_STAT :			  MUL_STAT
					| MUL_STAT STAT


>>>>>>> 51ae665b7be456da01bb83e26f96d8df5509a65f
EXPR :		          ARITH_EXPR														{ $$ = $1; }
					| RELA_EXPR															{ $$ = $1; }
					| INCDEC_EXPR 														{ $$ = $1; }

ARITH_EXPR : 		  EXPR ARITH_OP EXPR												{ $$ = }

ARITH_OP :			  T_PLUS															{ $$ = new std::string("+"); }
					| T_MINUS															{ $$ = new std::string("-"); }
					| T_DIVIDE															{ $$ = new std::string("*"); }
					| T_TIMES															{ $$ = new std::string("/"); }

RELA_EXPR :			  EXPR RELA_OP EXPR													{ $$ = }

RELA_OP :			  T_EQUALITY														{ $$ = new std::string("=="); }
					| T_INEQUALITY														{ $$ = new std::string("!="); }
					| T_GT																{ $$ = new std::string(">"); }
					| T_LT																{ $$ = new std::string("<"); }
					| T_GTEQ															{ $$ = new std::string(">="); }
					| T_LTEQ															{ $$ = new std::string("<="); }

INCDEC_EXPR :		  T_ID INCDEC_OP													{ $$ = }
					| INCDEC_OP T_ID													{ $$ = }

INCDEC_OP :			  T_INC																{ $$ = new std::string("++"); }
					| T_DEC																{ $$ = new std::string("--"); }

STAT :    			  SIMP_STAT															{ $$ = $1; }
					| COMP_STAT															{ $$ = $1; }

SIMP_STAT :   		  RETURN_STAT
					| ASSIGN_STAT
					| ASSERT_STAT
/*
COMP_STAT :			  IF_STAT
					| IF_ELSE_STAT
					| FOR_STAT
					| WHILE_STAT

IF_STAT : 			  T_IF T_LBRACKET ASSERT_STAT T_RBRACKET BLOCK

IF_ELSE_STAT :		  T_IF T_LBRACKET ASSERT_STAT T_RBRACKET BLOCK T_ELSE BLOCK

FOR_STAT :			  T_FOR T_LBRACKET EXPR T_SEMICOLON EXPR T_SEMICOLON EXPR T_SEMICOLON T_RBRACKET BLOCK

WHILE_STAT :
*/

//Type
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
