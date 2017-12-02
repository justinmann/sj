%option bison-bridge
%option bison-locations
%option ecs
%option nodefault
%option noyywrap
%option reentrant
%option stack
%option warn
%option never-interactive

%{
#include <string>
#include "../node/Node.h"
#include "parser.hpp"

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct YYLOCATION {
    int l;
    int c;
};
#define YY_EXTRA_TYPE YYLOCATION

void updateLocation(YYLOCATION& loc, const char* s, const int len) {
	int lastReturn = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '\n') {
			loc.l++;
			loc.c = 0;
			lastReturn = 0;
		}
	}
	loc.c += len - lastReturn;
}

#define SAVE_LOC yylloc_param->first_line = yyg->yyextra_r.l; yylloc_param->first_column = yyg->yyextra_r.c; updateLocation(yyg->yyextra_r, yytext, yyleng)
#define TOKEN_STR(t, leftTrim, rightTrim) SAVE_LOC; yylval->string = new std::string(yytext + leftTrim, yyleng - leftTrim - rightTrim); return t
#define TOKEN_VAL(t) SAVE_LOC; yylval->token = t; return t
%}

%%

"c{"([^\}]|\}+[^\}c])*"}c" TOKEN_STR(TCBLOCK, 2, 2);
"cstruct{"([^\}]|\}+[^\}c])*"}cstruct" TOKEN_STR(TCSTRUCT, 8, 8);
"cdefine{"([^\}]|\}+[^\}c])*"}cdefine" TOKEN_STR(TCDEFINE, 8, 8);
"cfunction{"([^\}]|\}+[^\}c])*"}cfunction" TOKEN_STR(TCFUNCTION, 10, 10);
"/*"([^*]|\*+[^*/])*\*+"/"	TOKEN_VAL(TEND);
"//".*					TOKEN_VAL(TEND);
"as"					TOKEN_VAL(TAS);
"throw"					TOKEN_VAL(TTHROW);
"copy"					TOKEN_VAL(TCOPY);
"catch"					TOKEN_VAL(TCATCH);
"destroy"				TOKEN_VAL(TDESTROY);
"true"					TOKEN_VAL(TTRUE);
"false"					TOKEN_VAL(TFALSE);
"void"					TOKEN_VAL(TVOID);
"stack"					TOKEN_VAL(TSTACK);
"heap"					TOKEN_VAL(THEAP);
"local"					TOKEN_VAL(TLOCAL);
"auto"					TOKEN_VAL(TAUTO);
"i32"					TOKEN_VAL(TTYPEI32);
"u32"					TOKEN_VAL(TTYPEU32);
"f32"					TOKEN_VAL(TTYPEF32);
"i64"					TOKEN_VAL(TTYPEI64);
"u64"					TOKEN_VAL(TTYPEU64);
"f64"					TOKEN_VAL(TTYPEF64);
"char"					TOKEN_VAL(TTYPECHAR);
"bool"					TOKEN_VAL(TTYPEBOOL);
"ptr"					TOKEN_VAL(TTYPEPTR);
"if"					TOKEN_VAL(TIF);
"else"					TOKEN_VAL(TELSE);
"for" 					TOKEN_VAL(TFOR);
"to" 					TOKEN_VAL(TTO);
"while"					TOKEN_VAL(TWHILE);
[ \t]+					SAVE_LOC; 
"^"						TOKEN_STR(TIDENTIFIER, 0, 0);
"this"					TOKEN_VAL(TTHIS);
"parent"				TOKEN_VAL(TPARENT);
"include"				TOKEN_VAL(TINCLUDE);
"isEmpty"				TOKEN_VAL(TISEMPTY);
"getValue"				TOKEN_VAL(TGETVALUE);
"value"					TOKEN_VAL(TVALUE);
"empty"					TOKEN_VAL(TEMPTY);
"#"						TOKEN_VAL(THASH);
"?:"					TOKEN_VAL(TQUESTIONCOLON);
"?."					TOKEN_VAL(TQUESTIONDOT);
"?"						TOKEN_VAL(TQUESTION);
"."						TOKEN_VAL(TDOT);
[a-zA-Z_][a-zA-Z0-9_]*	TOKEN_STR(TIDENTIFIER, 0, 0);
[0-9]+\.[0-9]*(f|d)*		TOKEN_STR(TDOUBLE, 0, 0);
[0-9]+(i|u|v|l)*		TOKEN_STR(TINTEGER, 0, 0);
\n						TOKEN_VAL(TEND);
;						TOKEN_VAL(TEND);
"'\\''"					TOKEN_STR(TCHAR, 1, 1);
"'\\"([^'])"'"			TOKEN_STR(TCHAR, 1, 1);
"'"([^'])"'"			TOKEN_STR(TCHAR, 1, 1);
\"(\\.|[^\"])*\"		TOKEN_STR(TSTRING, 1, 1);
"!"						TOKEN_VAL(TEXCLAIM);
"["						TOKEN_VAL(TLBRACKET);
"]"						TOKEN_VAL(TRBRACKET);
"&&"					TOKEN_VAL(TAND);
"||"					TOKEN_VAL(TOR);
"++"					TOKEN_VAL(TPLUSPLUS);
"--"					TOKEN_VAL(TMINUSMINUS);
"+="					TOKEN_VAL(TPLUSEQUAL);
"-="					TOKEN_VAL(TMINUSEQUAL);
"*="					TOKEN_VAL(TMULEQUAL);
"/="					TOKEN_VAL(TDIVEQUAL);
"="						TOKEN_VAL(TEQUAL);
"==="					TOKEN_VAL(TCPEQ);
"!=="					TOKEN_VAL(TCPNE);
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
"%"						TOKEN_VAL(TMOD);
.						TOKEN_STR(TINVALID, 0, 0);

%%