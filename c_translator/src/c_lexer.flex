%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "c_parser.tab.hpp"
%}

%%

[(]										{return T_LBRACKET;}
[)]										{return T_RBRACKET;}
[{]										{return T_CLBRACKET;}
[}]										{return T_CRBRACKET;}
[;]										{return T_SEMICOLON;}

[+]                                     {return T_ADD;}

return									{return T_RETURN;}
int										{return T_TYPE;}

[-]?[0-9]+([.][0-9]*)?					{yylval.number=strtod(yytext, 0); return T_NUMBER;}
[a-z]+									{yylval.string=new std::string(yytext); return T_IDENTIFIER;}

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
