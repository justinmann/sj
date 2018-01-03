%option bison-bridge
%option bison-locations
%option ecs
%option nodefault
%option noyywrap
%option reentrant
%option stack
%option warn
%option never-interactive
%option caseless

%{
#include <sjc.h>
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

void updateLocation(YYLOCATION& loc, const char* s, const size_t len) {
	size_t lastReturn = 0;
	for (size_t i = 0; i < len; i++) {
		if (s[i] == '\n') {
			loc.l++;
			loc.c = 0;
			lastReturn = 0;
		}
	}
	loc.c += (int)(len - lastReturn);
}

#define SAVE_LOC yylloc_param->first_line = yyg->yyextra_r.l; yylloc_param->first_column = yyg->yyextra_r.c; updateLocation(yyg->yyextra_r, yytext, yyleng)
#define TOKEN_STR(t, leftTrim, rightTrim) SAVE_LOC; yylval->string = new std::string(yytext + (size_t)leftTrim, yyleng - (size_t)leftTrim - (size_t)rightTrim); return t
#define TOKEN_VAL(t) SAVE_LOC; yylval->token = t; return t
%}

%x CBLOCK
%x CVAR
%x CSTRUCT
%x CDEFINE
%x CINCLUDE
%x CTYPEDEF
%x CFUNCTION

%%
(?:"--c--")						{ BEGIN(CBLOCK); }
<CBLOCK>. 	 					{ yymore(); }
<CBLOCK>\n 					    { TOKEN_STR(TCBLOCK, 0, 1); }
<CBLOCK>(?:"--c--")				{ BEGIN(INITIAL); TOKEN_STR(TCBLOCK, 0, 5); }

(?:"--cvar--")					{ BEGIN(CVAR); }
<CVAR>. 						{ yymore(); }
<CVAR>\n 						{ TOKEN_STR(TCVAR, 0, 1); }
<CVAR>(?:"--cvar--")			{ BEGIN(INITIAL); TOKEN_STR(TCVAR, 0, 8); }

(?:"--cstruct--")				{ BEGIN(CSTRUCT); }
<CSTRUCT>. 						{ yymore(); }
<CSTRUCT>\n 					{ TOKEN_STR(TCSTRUCT, 0, 1); }
<CSTRUCT>(?:"--cstruct--")		{ BEGIN(INITIAL); TOKEN_STR(TCSTRUCT, 0, 11); }

(?:"--cdefine--")				{ BEGIN(CDEFINE); }
<CDEFINE>. 						{ yymore(); }
<CDEFINE>\n 					{ TOKEN_STR(TCDEFINE, 0, 1); }
<CDEFINE>(?:"--cdefine--")		{ BEGIN(INITIAL); TOKEN_STR(TCDEFINE, 0, 11); }

(?:"--cinclude--")				{ BEGIN(CINCLUDE); }
<CINCLUDE>. 					{ yymore(); }
<CINCLUDE>\n 					{ TOKEN_STR(TCINCLUDE, 0, 1); }
<CINCLUDE>(?:"--cinclude--")	{ BEGIN(INITIAL); TOKEN_STR(TCINCLUDE, 0, 12); }

(?:"--ctypedef--")				{ BEGIN(CTYPEDEF); }
<CTYPEDEF>. 					{ yymore(); }
<CTYPEDEF>\n 					{ TOKEN_STR(TCTYPEDEF, 0, 1); }
<CTYPEDEF>(?:"--ctypedef--")	{ BEGIN(INITIAL); TOKEN_STR(TCTYPEDEF, 0, 12); }

(?:"--cfunction--")				{ BEGIN(CFUNCTION); }
<CFUNCTION>. 					{ yymore(); }
<CFUNCTION>\n 					{ TOKEN_STR(TCFUNCTION, 0, 1); }
<CFUNCTION>(?:"--cfunction--")	{ BEGIN(INITIAL); TOKEN_STR(TCFUNCTION, 0, 13); }

"/*"([^*]|\*+[^*/])*\*+"/"	TOKEN_VAL(TEND);
"//".*						TOKEN_VAL(TEND);
(?:"as")					TOKEN_VAL(TAS);
(?:"throw")					TOKEN_VAL(TTHROW);
(?:"copy")					TOKEN_VAL(TCOPY);
(?:"catch")					TOKEN_VAL(TCATCH);
(?:"destroy")				TOKEN_VAL(TDESTROY);
(?:"true")					TOKEN_VAL(TTRUE);
(?:"false")					TOKEN_VAL(TFALSE);
(?:"void")					TOKEN_VAL(TVOID);
(?:"stack")					TOKEN_VAL(TSTACK);
(?:"heap")					TOKEN_VAL(THEAP);
(?:"weak")					TOKEN_VAL(TWEAK);
(?:"local")					TOKEN_VAL(TLOCAL);
(?:"i32")					TOKEN_VAL(TTYPEI32);
(?:"u32")					TOKEN_VAL(TTYPEU32);
(?:"f32")					TOKEN_VAL(TTYPEF32);
(?:"i64")					TOKEN_VAL(TTYPEI64);
(?:"u64")					TOKEN_VAL(TTYPEU64);
(?:"f64")					TOKEN_VAL(TTYPEF64);
(?:"char")					TOKEN_VAL(TTYPECHAR);
(?:"bool")					TOKEN_VAL(TTYPEBOOL);
(?:"ptr")					TOKEN_VAL(TTYPEPTR);
(?:"if")					TOKEN_VAL(TIF);
(?:"else")					TOKEN_VAL(TELSE);
(?:"ifvalid")				TOKEN_VAL(TIFVALID);
(?:"elseempty")				TOKEN_VAL(TELSEEMPTY);
(?:"for") 					TOKEN_VAL(TFOR);
(?:"to") 					TOKEN_VAL(TTO);
(?:"toreverse")				TOKEN_VAL(TTOREVERSE);
(?:"while")					TOKEN_VAL(TWHILE);
(?:"type")					TOKEN_VAL(TTYPE);
[ \t]+						SAVE_LOC; 
"^"							TOKEN_VAL(TCARET);
(?:"this")					TOKEN_VAL(TTHIS);
(?:"parent")				TOKEN_VAL(TPARENT);
(?:"include")				TOKEN_VAL(TINCLUDE);
(?:"isempty")				TOKEN_VAL(TISEMPTY);
(?:"isvalid")				TOKEN_VAL(TISVALID);
(?:"opt_getvalue")			TOKEN_VAL(TGETVALUE);
(?:"valid")					TOKEN_VAL(TVALID);
(?:"empty")					TOKEN_VAL(TEMPTY);
(?:"enum")					TOKEN_VAL(TENUM);
(?:"switch")				TOKEN_VAL(TSWITCH);
(?:"default")				TOKEN_VAL(TDEFAULT);
(?:"package")				TOKEN_VAL(TPACKAGE);
(?:"import")				TOKEN_VAL(TIMPORT);
(?:"library")				TOKEN_VAL(TLIBRARY);
(?:"nullptr")				TOKEN_VAL(TNULLPTR);	
(?:"xor")					TOKEN_VAL(TBOOLXOR);
(?:"or")					TOKEN_VAL(TBOOLOR);
(?:"and")					TOKEN_VAL(TBOOLAND);
(?:"not")					TOKEN_VAL(TBOOLNOT);
(?:"shr")					TOKEN_VAL(TBOOLSHR);
(?:"shl")					TOKEN_VAL(TBOOLSHL);
"_"							TOKEN_VAL(TUNDERSCORE);
"#"							TOKEN_VAL(THASH);
"@"							TOKEN_VAL(TAT);
"?:"						TOKEN_VAL(TQUESTIONCOLON);
"?."						TOKEN_VAL(TQUESTIONDOT);
"?"							TOKEN_VAL(TQUESTION);
"."							TOKEN_VAL(TDOT);
[a-zA-Z_][a-zA-Z0-9_]*		TOKEN_STR(TIDENTIFIER, 0, 0);
`[a-zA-Z_][a-zA-Z0-9_#!\[\] ,]*`	TOKEN_STR(TQUOTEDIDENTIFIER, 1, 1);
[0-9]+\.[0-9]+(f|d)*		TOKEN_STR(TDOUBLE, 0, 0);
[0-9]+(i|u|v|l)*			TOKEN_STR(TINTEGER, 0, 0);
"0x"[0-9a-fA-F]+(i|u|v|l)*	TOKEN_STR(TINTEGER, 0, 0);
\r\n						TOKEN_VAL(TEND);
\n							TOKEN_VAL(TEND);
;							TOKEN_VAL(TEND);
"'\\''"						TOKEN_STR(TCHAR, 1, 1);
"'\\"([^'])"'"				TOKEN_STR(TCHAR, 1, 1);
"'"([^'])"'"				TOKEN_STR(TCHAR, 1, 1);
\"(\\.|[^\"])*\"			TOKEN_STR(TSTRING, 1, 1);
"!"							TOKEN_VAL(TEXCLAIM);
"["							TOKEN_VAL(TLBRACKET);
"]"							TOKEN_VAL(TRBRACKET);
"&&"						TOKEN_VAL(TAND);
"||"						TOKEN_VAL(TOR);
"++"						TOKEN_VAL(TPLUSPLUS);
"--"						TOKEN_VAL(TMINUSMINUS);
"+="						TOKEN_VAL(TPLUSEQUAL);
"-="						TOKEN_VAL(TMINUSEQUAL);
"*="						TOKEN_VAL(TMULEQUAL);
"/="						TOKEN_VAL(TDIVEQUAL);
"="							TOKEN_VAL(TEQUAL);
"==="						TOKEN_VAL(TCPEQ);
"!=="						TOKEN_VAL(TCPNE);
"=="						TOKEN_VAL(TCEQ);
"!="						TOKEN_VAL(TCNE);
"<"							TOKEN_VAL(TCLT);
"<="						TOKEN_VAL(TCLE);
">"							TOKEN_VAL(TCGT);
">="						TOKEN_VAL(TCGE);
"("							TOKEN_VAL(TLPAREN);
")"							TOKEN_VAL(TRPAREN);
"{"							TOKEN_VAL(TLBRACE);
"}"							TOKEN_VAL(TRBRACE);
","							TOKEN_VAL(TCOMMA);
":"							TOKEN_VAL(TCOLON);
":="						TOKEN_VAL(TCOLONEQUAL);
"\'"						TOKEN_VAL(TQUOTE);
"+"							TOKEN_VAL(TPLUS);
"-"							TOKEN_VAL(TMINUS);
"*"							TOKEN_VAL(TMUL);
"/"							TOKEN_VAL(TDIV);
"%"							TOKEN_VAL(TMOD);
.							TOKEN_STR(TINVALID, 0, 0);

%%