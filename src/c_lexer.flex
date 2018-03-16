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
[,]										{return T_COMMA;}

[*]                                     { return T_TIMES; }
[+]                                     { return T_PLUS; }
[-]                                     { return T_MINUS; }
[/]                                     { return T_DIVIDE; }
[=]                                     { return T_EQUALS; }

\<\=                                     { return T_LESSTHANEQ;}
\=\>                                     { return T_MORETHANEQ;}
\=\=                                     { return T_CONDEQ;}
\!\=                                     { return T_NOTEQ;}

\&\&                                    {return T_LOGAND;}
\|\|                                    {return T_LOGOR;}



return									{return T_RETURN;}
int										{return T_INT;}
void									{return T_VOID;}
if                                      {return T_IF;}

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
