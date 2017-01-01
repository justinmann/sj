%option bison-bridge
%option bison-locations
%option ecs
%option nodefault
%option noyywrap
%option reentrant
%option stack
%option warn

%{
#include <string>
#include "node.h"
#include "parser.hpp"

#pragma clang diagnostic ignored "-Wdeprecated-register"
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wdocumentation"
#pragma clang diagnostic ignored "-Wunreachable-code"

struct YYLOCATION {
    int l;
    int c;
};
#define YY_EXTRA_TYPE YYLOCATION

#define SAVE_LOC yylloc_param->first_line = yyg->yyextra_r.l; yylloc_param->first_column = yyg->yyextra_r.c; yyg->yyextra_r.c += yyleng
#define TOKEN_STR(t) SAVE_LOC; yylval->string = new std::string(yytext, yyleng); return t
#define TOKEN_VAL(t) SAVE_LOC; yylval->token = t; return t
%}

%%

" as "					TOKEN_VAL(TCAST);
"true"					TOKEN_VAL(TTRUE);
"false"					TOKEN_VAL(TFALSE);
"void"					TOKEN_VAL(TVOID);
"if"					TOKEN_VAL(TIF);
"else"					TOKEN_VAL(TELSE);
[ \t]+					SAVE_LOC; 
[a-zA-Z_][a-zA-Z0-9_\.]*	TOKEN_STR(TIDENTIFIER);
[0-9]+\.[0-9]*			TOKEN_STR(TDOUBLE);
[0-9]+					TOKEN_STR(TINTEGER);
\n						yyg->yyextra_r.l++; yyg->yyextra_r.c = 0; TOKEN_VAL(TEND);
;						TOKEN_VAL(TEND);
"="						TOKEN_VAL(TEQUAL);
"=="					TOKEN_VAL(TCEQ);
"!="					TOKEN_VAL(TCNE);
"<"						TOKEN_VAL(TCLT);
"<="					TOKEN_VAL(TCLE);
">"						TOKEN_VAL(TCGT);
">="					TOKEN_VAL(TCGE);
"("						TOKEN_VAL(TLPAREN);
")"						TOKEN_VAL(TRPAREN);
"{"						TOKEN_VAL(TLBRACE);
"}"						TOKEN_VAL(TRBRACE);
","						TOKEN_VAL(TCOMMA);
":"						TOKEN_VAL(TCOLON);
"\'"					TOKEN_VAL(TQUOTE);
"+"						TOKEN_VAL(TPLUS);
"-"						TOKEN_VAL(TMINUS);
"*"						TOKEN_VAL(TMUL);
"/"						TOKEN_VAL(TDIV);
.						TOKEN_STR(TINVALID);

%%