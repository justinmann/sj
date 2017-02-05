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
#define LLOC CLoc(yylloc.first_line, yylloc.first_column)

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
	NVariableBase* var;
	NodeList* exprvec;
	std::string* string;
	TemplateTypeNames* templateTypeNames;
	int token;
	bool isMutable;
}

/* Terminal symbols. They need to match tokens in tokens.l file */
%token <string> TIDENTIFIER TINTEGER TDOUBLE TINVALID TSTRING TCHAR
%token <token> error TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TEND TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TCOLON TQUOTE TPLUS TMINUS TMUL TDIV TTRUE TFALSE TCAST TVOID TIF TELSE TTHROW TCATCH TEXTERN TFOR TTO TWHILE TPLUSPLUS TMINUSMINUS TPLUSEQUAL TMINUSEQUAL TLBRACKET TRBRACKET TEXCLAIM TDOT TTHIS TINCLUDE TAND TOR TDESTROY TMOD

/* Non Terminal symbols. Types refer to union decl above */
%type <node> program expr expr_and expr_comp expr_math expr_var const stmt var_decl func_decl func_arg for_expr while_expr assign array
%type <var> var var_right
%type <block> stmts block catch destroy
%type <nif> if_expr
%type <exprvec> func_args func_block array_args
%type <isMutable> assign_type
%type <string> type return_type
%type <templateTypeNames> temp_args temp_block

/* Operator precedence */
%left TAND TOR
%left TPLUS TMINUS
%left TMUL TDIV
%left TMOD

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
					| TINCLUDE TSTRING								{ $$ = new NInclude(LOC, $2->c_str()); delete $2; }
					| error	 										{ $$ = nullptr; /* yyclearin; */ result->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }
					;

block 				: TLBRACE stmts TRBRACE 						{ $$ = $2; }
					;

var_decl 			: assign
					| var TPLUSPLUS                         		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Inc, nullptr); }
					| var TMINUSMINUS                       		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Dec, nullptr); }
					| var TPLUSEQUAL stmt                   		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Add, shared_ptr<NBase>($3)); }
					| var TMINUSEQUAL stmt                  		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Sub, shared_ptr<NBase>($3)); }
					| var TLBRACKET expr TRBRACKET					{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "get", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3)))); }
					| var TLBRACKET expr TRBRACKET TEQUAL stmt		{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "set", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3), shared_ptr<NBase>($6)))); }
					;

func_decl 			: TIDENTIFIER temp_block func_block block catch destroy			{ $$ = new NFunction(LOC, FT_Private, "", $1->c_str(), shared_ptr<TemplateTypeNames>($2), shared_ptr<NodeList>($3), shared_ptr<NBlock>($4), shared_ptr<NBlock>($5), shared_ptr<NBlock>($6)); }
					| TIDENTIFIER temp_block func_block return_type block catch destroy 	{ $$ = new NFunction(LOC, FT_Private, $4->c_str(), $1->c_str(), shared_ptr<TemplateTypeNames>($2), shared_ptr<NodeList>($3), shared_ptr<NBlock>($5), shared_ptr<NBlock>($6), shared_ptr<NBlock>($7)); }
					| TEXTERN TLPAREN TSTRING TRPAREN TIDENTIFIER func_block return_type 	{ $$ = new NFunction(LOC, FT_Extern, $3->c_str(), $7->c_str(), $5->c_str(), shared_ptr<NodeList>($6)); delete $3; }
					;

catch				: /* Blank! */									{ $$ = nullptr; }
					| TCATCH block									{ $$ = $2; }
					;

destroy				: /* Blank! */									{ $$ = nullptr; }
					| TDESTROY block								{ $$ = $2; }
					;

func_block			: TLPAREN func_args TRPAREN						{ $$ = $2; }
					;

func_args  			: func_arg										{ $$ = new NodeList(); if ($1) { $$->push_back(shared_ptr<NBase>($1)); } }
					| func_args TEND func_arg 						{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					| func_args TCOMMA func_arg 					{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					;

func_arg			: /* Blank! */									{ $$ = nullptr; }
					| assign 										
					| func_decl 										
					| expr 	
					; 

temp_block			: /* Blank! */									{ $$ = nullptr; }
					| TEXCLAIM TIDENTIFIER							{ $$ = new TemplateTypeNames(); $$->push_back(pair<string, shared_ptr<TemplateTypeNames>>(*$2, nullptr)); delete $2; }
					| TEXCLAIM TLBRACKET temp_args TRBRACKET		{ $$ = $3; }					
					;

temp_args			: TIDENTIFIER temp_block						{ $$ = new TemplateTypeNames(); $$->push_back(pair<string, shared_ptr<TemplateTypeNames>>(*$1, shared_ptr<TemplateTypeNames>($2))); delete $1; }
					| temp_args TCOMMA TIDENTIFIER					{ $1->push_back(pair<string, shared_ptr<TemplateTypeNames>>(*$3, nullptr)); delete $3; }
					;

expr 				: if_expr										{ $$ = (NBase*)$1; }
					| for_expr		
					| while_expr								
					| expr_and
					| TTHROW TLPAREN expr TRPAREN					{ $$ = new NThrow(LOC, shared_ptr<NBase>($3)); }
					| expr TCAST TIDENTIFIER   						{ $$ = new NCast(LOC, $3->c_str(), shared_ptr<NBase>($1)); delete $3; }
					;

expr_and			: expr_comp TAND expr_and 						{ $$ = new NAnd(LOC, shared_ptr<NBase>($1), shared_ptr<NBase>($3)); }
					| expr_comp TOR expr_and 						{ $$ = new NOr(LOC, shared_ptr<NBase>($1), shared_ptr<NBase>($3)); }
					| expr_comp
					;					

expr_comp 			: expr_math TCEQ expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::EQ, shared_ptr<NBase>($3)); }
					| expr_math TCNE expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::NE, shared_ptr<NBase>($3)); }
					| expr_math TCLT expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::LT, shared_ptr<NBase>($3)); }
					| expr_math TCLE expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::LE, shared_ptr<NBase>($3)); }
					| expr_math TCGT expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::GT, shared_ptr<NBase>($3)); }
					| expr_math TCGE expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NBase>($1), NCompareOp::GE, shared_ptr<NBase>($3)); }
					| expr_math
					;

expr_math			: expr_math TPLUS expr_math 					{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Add, shared_ptr<NBase>($3)); }
					| expr_math TMINUS expr_math 					{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Sub, shared_ptr<NBase>($3)); }
					| expr_math TMUL expr_math 						{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Mul, shared_ptr<NBase>($3)); }
					| expr_math TDIV expr_math 						{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Div, shared_ptr<NBase>($3)); }
					| expr_math TMOD expr_math 						{ $$ = new NMath(LOC, shared_ptr<NBase>($1), NMathOp::Mod, shared_ptr<NBase>($3)); }
					| TEXCLAIM expr_var                             { $$ = new NNot(LOC, shared_ptr<NBase>($2)); }
					| expr_var
					;

expr_var 			: TLPAREN expr TRPAREN 							{ $$ = $2; }
					| var 											{ $$ = $1; }
					| array
					| const
					;

for_expr			: TFOR TIDENTIFIER TCOLON expr TTO expr block   { $$ = new NFor(LOC, $2->c_str(), shared_ptr<NBase>($4), shared_ptr<NBase>($6), shared_ptr<NBase>($7)); delete $2; }
					;

while_expr			: TWHILE expr block 							{ $$ = new NWhile(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3)); }
					;
					
if_expr		 		: TIF expr block								{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), nullptr); }
					| TIF expr block TELSE block					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					| TIF expr block TELSE if_expr					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					;

var					: var TDOT var_right							{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| var_right										
					;

var_right			: TIDENTIFIER temp_block func_block				{ $$ = new NCall(LOC, $1->c_str(), shared_ptr<TemplateTypeNames>($2), shared_ptr<NodeList>($3)); delete $1; }
	 				| TIDENTIFIER									{ $$ = new NVariable(LOC, $1->c_str()); delete $1; }
	 				| TTHIS											{ $$ = new NThis(LOC); }
	 				;

const 				: TMINUS TINTEGER 								{ $2->insert(0, "-"); $$ = new NInteger(LOC, $2->c_str()); delete $2; }
					| TINTEGER 										{ $$ = new NInteger(LOC, $1->c_str()); delete $1; }
					| TMINUS TDOUBLE 								{ $2->insert(0, "-"); $$ = new NDouble(LOC, $2->c_str()); delete $2; }
					| TDOUBLE 										{ $$ = new NDouble(LOC, $1->c_str()); delete $1; }
					| TTRUE											{ $$ = new NBool(LOC, true); }
					| TFALSE										{ $$ = new NBool(LOC, false); }
					| TVOID											{ $$ = new NVoid(LOC); }
					| TSTRING										{ $$ = new NString(LOC, $1->c_str()); delete $1; }
					| TCHAR											{ $$ = new NChar(LOC, $1->c_str()[0]); delete $1; }
					;
										
assign				: TIDENTIFIER assign_type stmt					{ $$ = new NAssignment(LOC, nullptr, "", $1->c_str(), shared_ptr<NBase>($3), $2); }
					| TIDENTIFIER assign_type type					{ $$ = new NAssignment(LOC, nullptr, $3->c_str(), $1->c_str(), nullptr, $2); delete $3; }								
					| TIDENTIFIER type assign_type stmt				{ $$ = new NAssignment(LOC, nullptr, $2->c_str(), $1->c_str(), shared_ptr<NBase>($4), $3); }
					| var TDOT TIDENTIFIER assign_type stmt			{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), "", $3->c_str(), shared_ptr<NBase>($5), $4); }
					| var TDOT TIDENTIFIER assign_type type			{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), $5->c_str(), $3->c_str(), nullptr, $4); delete $5; }								
					| var TDOT TIDENTIFIER type assign_type stmt	{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), $4->c_str(), $3->c_str(), shared_ptr<NBase>($6), $5); }
					;

assign_type 		: TEQUAL										{ $$ = true; }
					| TCOLON										{ $$ = false; }
					;

array				: TLBRACKET array_args TRBRACKET				{ $$ = new NList(LOC, shared_ptr<NodeList>($2)); }
					;

array_args 			: expr											{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					| array_args TCOMMA expr 						{ $1->push_back(shared_ptr<NBase>($3)); }
					;

return_type			: TQUOTE TIDENTIFIER temp_block					{ $$ = $2; }
					| TQUOTE TVOID									{ $$ = new string("void"); }
					;

type 				: TQUOTE TIDENTIFIER temp_block					{ $$ = $2; }
					;

%%