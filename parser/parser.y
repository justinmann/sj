%define parse.error verbose
%define api.pure true
%locations
%token-table
%lex-param {void *scanner}
%parse-param {void *scanner} {CResult* result}

%{

#include <stdio.h>
#include "../node/Node.h"
#include "parser.hpp"

#pragma clang diagnostic ignored "-Wunreachable-code"
#pragma clang diagnostic ignored "-Wunused-variable"

#define LOC CLoc(yyloc.first_line, yyloc.first_column)

int yyerror(YYLTYPE *locp, void *scanner, CResult* result, const char *msg) {
  if (locp) {
  	result->addWarning(CLoc(locp->first_line, locp->first_column), CErrorCode::Parser, msg);
  } else {
  	result->addWarning(CLoc::undefined, CErrorCode::Parser, msg);
  }
  return (0);
}

extern int yylex(YYSTYPE * yylval_param,YYLTYPE * yylloc_param , void *scanner);

#define YYPRINT yyprint

void yyprint(FILE* file, unsigned short int v1, const YYSTYPE type) {
	switch (v1) {
		case TIDENTIFIER:
        case TINTEGER:
        case TDOUBLE:
			fprintf(file, "%s", type.string->c_str());
	}				
}

%}

/* Represents the different ways to access our code being compiled*/

%union {
	NBase* node;
	NBlock* block;
	NIf* nif;
	NAssignment* var_decl;
	std::vector<shared_ptr<NBase>>* exprvec;
	std::string* string;
	TemplateTypeNames* templateTypeNames;
	int token;
	bool isMutable;
}

/* Terminal symbols. They need to match tokens in tokens.l file */
%token <string> TIDENTIFIER TINTEGER TDOUBLE TINVALID
%token <token> error TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TEND TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TCOLON TQUOTE TPLUS TMINUS TMUL TDIV TTRUE TFALSE TCAST TVOID TIF TELSE TTHROW TCATCH TEXTERN TFOR TTO TWHILE TPLUSPLUS TMINUSMINUS TPLUSEQUAL TMINUSEQUAL TLBRACKET TRBRACKET TEXCLAIM

/* Non Terminal symbols. Types refer to union decl above */
%type <node> program expr var stmt var_decl func_decl func_call func_arg for_expr while_expr
%type <block> stmts block catch
%type <nif> if_expr
%type <exprvec> func_args func_block
%type <isMutable> assign
%type <string> type
%type <templateTypeNames> temp_args temp_block

/* Operator precedence */
%left TPLUS TMINUS
%left TMUL TDIV

/* Starting rule in the grammar*/

%start program

/* Grammar rules */

%%

program 			: stmts 										{ result->block = std::shared_ptr<NBlock>($1); }
					;

stmts 				: stmt											{ $$ = new NBlock(LOC); if ($1) $$->statements.push_back(shared_ptr<NBase>($1)); }
					| stmts TEND stmt								{ if ($3) $1->statements.push_back(shared_ptr<NBase>($3)); }
					;
					
stmt 				: /* Blank! */									{ $$ = nullptr; }
					| var_decl
					| func_decl 
					| expr
					| error	 										{ $$ = nullptr; /* yyclearin; */ result->errors.push_back(CError(LOC, CErrorCode::InvalidCharacter)); }
					;

block 				: TLBRACE stmts TRBRACE 						{ $$ = $2; }
					;

var_decl 			: TIDENTIFIER assign stmt						{ /* x = 1 */ 		$$ = new NAssignment(LOC, "", $1->c_str(), shared_ptr<NBase>($3), $2); }
					| TIDENTIFIER type assign stmt					{ /* x'int = 2 */ 	$$ = new NAssignment(LOC, $2->c_str(), $1->c_str(), shared_ptr<NBase>($4), $3); }
					| TIDENTIFIER TPLUSPLUS                         { $$ = new NMathAssignment(LOC, $1->c_str(), NMAO_Inc, nullptr); delete $1; }
					| TIDENTIFIER TMINUSMINUS                       { $$ = new NMathAssignment(LOC, $1->c_str(), NMAO_Dec, nullptr); delete $1; }
					| TIDENTIFIER TPLUSEQUAL stmt                   { $$ = new NMathAssignment(LOC, $1->c_str(), NMAO_Add, shared_ptr<NBase>($3)); delete $1; }
					| TIDENTIFIER TMINUSEQUAL stmt                  { $$ = new NMathAssignment(LOC, $1->c_str(), NMAO_Sub, shared_ptr<NBase>($3)); delete $1; }
					| TEXCLAIM stmt                                 { $$ = new NNot(LOC, shared_ptr<NBase>($2)); }
					;

func_decl 			: TIDENTIFIER func_block block catch			{ /* f()'int */		$$ = new NFunction(LOC, FT_Private, "", $1->c_str(), nullptr, *($2), shared_ptr<NBlock>($3), shared_ptr<NBlock>($4)); }
					| TIDENTIFIER func_block type block catch		{ /* f() */			$$ = new NFunction(LOC, FT_Private, $3->c_str(), $1->c_str(), nullptr, *($2), shared_ptr<NBlock>($4), shared_ptr<NBlock>($5)); }
					| TIDENTIFIER temp_block func_block block catch		{ /* f() */			$$ = new NFunction(LOC, FT_Private, "", $1->c_str(), shared_ptr<TemplateTypeNames>($2), *($3), shared_ptr<NBlock>($4), shared_ptr<NBlock>($5)); }
					| TIDENTIFIER temp_block func_block type block catch		{ /* f() */			$$ = new NFunction(LOC, FT_Private, $4->c_str(), $1->c_str(), shared_ptr<TemplateTypeNames>($2), *($3), shared_ptr<NBlock>($5), shared_ptr<NBlock>($6)); }
					| TEXTERN TIDENTIFIER func_block type 			{ /* #f()'int */	$$ = new NFunction(LOC, FT_Extern, $4->c_str(), $2->c_str(), nullptr, *($3), nullptr, nullptr); }
					;

catch				: /* Blank! */									{ $$ = nullptr; }
					| TCATCH block									{ $$ = $2; }

func_call			: TIDENTIFIER func_block						{ $$ = new NCall(LOC, $1->c_str(), nullptr, *($2)); delete $1; }
					| TIDENTIFIER temp_block func_block				{ $$ = new NCall(LOC, $1->c_str(), shared_ptr<TemplateTypeNames>($2), *($3)); delete $1; }
					;
					
func_block			: TLPAREN TRPAREN								{ $$ = new NodeList(); }
					| TLPAREN func_args TRPAREN						{ $$ = $2; }
					| TLPAREN TEND func_args TRPAREN				{ $$ = $3; }
					| TLPAREN TEND func_args TEND TRPAREN			{ $$ = $3; }
					;

func_args  			: func_arg										{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					| func_args TEND func_arg 						{ $1->push_back(shared_ptr<NBase>($3)); }
					| func_args TCOMMA func_arg 					{ $1->push_back(shared_ptr<NBase>($3)); }
					;

func_arg			: var_decl 										
					| func_decl 										
					| expr 	
					| TIDENTIFIER assign type		    			{ $$ = new NAssignment(LOC, $3->c_str(), $1->c_str(), nullptr, $2); delete $3; }								
					; 

temp_block			: TEXCLAIM TIDENTIFIER							{ $$ = new TemplateTypeNames(); $$->push_back(pair<string, shared_ptr<TemplateTypeNames>>(*$2, nullptr)); delete $2; }
					| TEXCLAIM TLBRACKET temp_args TRBRACKET		{ $$ = $3; }					
					;

temp_args			: TIDENTIFIER									{ $$ = new TemplateTypeNames(); $$->push_back(pair<string, shared_ptr<TemplateTypeNames>>(*$1, nullptr)); delete $1; }
					| TIDENTIFIER temp_block						{ $$ = new TemplateTypeNames(); $$->push_back(pair<string, shared_ptr<TemplateTypeNames>>(*$1, shared_ptr<TemplateTypeNames>($2))); delete $1; }
					| temp_args TCOMMA TIDENTIFIER					{ $1->push_back(pair<string, shared_ptr<TemplateTypeNames>>(*$3, nullptr)); delete $3; }
					;

expr				: func_call 	
					| expr TPLUS var 								{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Add, shared_ptr<NBase>($3)); }
					| expr TMINUS var 								{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Sub, shared_ptr<NBase>($3)); }
					| expr TMUL var 								{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Mul, shared_ptr<NBase>($3)); }
					| expr TDIV var 								{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Div, shared_ptr<NBase>($3)); }
					| expr TCEQ var 								{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::EQ, shared_ptr<NBase>($3)); }
					| expr TCNE var 								{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::NE, shared_ptr<NBase>($3)); }
					| expr TCLT var 								{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::LT, shared_ptr<NBase>($3)); }
					| expr TCLE var 								{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::LE, shared_ptr<NBase>($3)); }
					| expr TCGT var 								{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::GT, shared_ptr<NBase>($3)); }
					| expr TCGE var 								{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::GE, shared_ptr<NBase>($3)); }
					| TLPAREN expr TRPAREN 							{ $$ = $2; }
					| expr TCAST TIDENTIFIER   						{ $$ = new NCast(LOC, $3->c_str(), shared_ptr<NBase>($1)); delete $3; }
					| if_expr										{ $$ = (NBase*)$1; }
					| for_expr		
					| while_expr								
					| TTHROW TLPAREN expr TRPAREN					{ $$ = new NThrow(LOC, shared_ptr<NBase>($3)); }
					| var
					;

for_expr			: TFOR TIDENTIFIER TCOLON expr TTO expr block   { $$ = new NFor(LOC, $2->c_str(), shared_ptr<NBase>($4), shared_ptr<NBase>($6), shared_ptr<NBase>($7)); delete $2; }
					;

while_expr			: TWHILE expr block 							{ $$ = new NWhile(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3)); }
					;
					
if_expr		 		: TIF expr block								{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), nullptr); }
					| TIF expr block TELSE block					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					| TIF expr block TELSE if_expr					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					;

var 				: TMINUS TINTEGER 								{ $2->insert(0, "-"); $$ = new NInteger(LOC, $2->c_str()); delete $2; }
					| TINTEGER 										{ $$ = new NInteger(LOC, $1->c_str()); delete $1; }
					| TMINUS TDOUBLE 								{ $2->insert(0, "-"); $$ = new NDouble(LOC, $2->c_str()); delete $2; }
					| TDOUBLE 										{ $$ = new NDouble(LOC, $1->c_str()); delete $1; }
					| TTRUE											{ $$ = new NBool(LOC, true); }
					| TFALSE										{ $$ = new NBool(LOC, false); }
					| TVOID											{ $$ = new NVoid(LOC); }
					| TIDENTIFIER									{ $$ = new NVariable(LOC, $1->c_str()); delete $1; }
					;
										
assign				: TEQUAL										{ $$ = true; }
					| TCOLON										{ $$ = false; }
					;

type 				: TQUOTE TIDENTIFIER							{ $$ = $2; }
					;

%%