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

#define LOC CLoc(result->fileName, yyloc.first_line, yyloc.first_column)
#define LLOC CLoc(result->fileName, yylloc.first_line, yylloc.first_column)

int yyerror(YYLTYPE *locp, void *scanner, CResult* result, const char *msg) {
  if (locp) {
  	result->addWarning(CLoc(result->fileName, locp->first_line, locp->first_column), CErrorCode::Parser, msg);
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
	CTypeName* typeName;
	CTypeNameList* templateTypeNames;
	int token;
	bool isMutable;
}

/* Terminal symbols. They need to match tokens in tokens.l file */
%token <string> TIDENTIFIER TINTEGER TDOUBLE TINVALID TSTRING TCHAR TCCODE
%token <token> error TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TEND TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TCOLON TQUOTE TPLUS TMINUS TMUL TDIV TTRUE TFALSE TAS TVOID TIF TELSE TTHROW TCATCH TEXTERN TFOR TTO TWHILE TPLUSPLUS TMINUSMINUS TPLUSEQUAL TMINUSEQUAL TLBRACKET TRBRACKET TEXCLAIM TDOT TTHIS TINCLUDE TAND TOR TDESTROY TMOD THASH TAT

/* Non Terminal symbols. Types refer to union decl above */
%type <node> program expr expr_and expr_comp expr_math expr_var const stmt var_decl func_decl func_arg for_expr while_expr assign array interface_decl interface_arg block catch destroy
%type <var> var var_right
%type <block> stmts
%type <nif> if_expr
%type <exprvec> func_args func_block array_args interface_args interface_block
%type <isMutable> assign_type
%type <typeName> arg_type_quote arg_type return_type_quote return_type func_type func_arg_type func_type_name implement_arg
%type <templateTypeNames> temp_args temp_block temp_block_optional func_arg_type_list implement implement_args

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
					| interface_decl
					| expr
					| TCCODE										{ $$ = new NCCode(LOC, $1->c_str()); delete $1; }
					| TINCLUDE TSTRING								{ $$ = new NInclude(LOC, $2->c_str()); delete $2; }
					| error	 										{ $$ = nullptr; /* yyclearin; */ result->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }
					;

block 				: TLBRACE stmts TRBRACE 						{ $$ = $2; }
					| TCCODE										{ $$ = new NCCode(LOC, $1->c_str()); delete $1; }
					;

var_decl 			: assign
					| var TPLUSPLUS                         		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Inc, nullptr); }
					| var TMINUSMINUS                       		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Dec, nullptr); }
					| var TPLUSEQUAL stmt                   		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Add, shared_ptr<NBase>($3)); }
					| var TMINUSEQUAL stmt                  		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Sub, shared_ptr<NBase>($3)); }
					| var TLBRACKET expr TRBRACKET					{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "get", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3)))); }
					| var TLBRACKET expr TRBRACKET TEQUAL stmt		{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "set", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3), shared_ptr<NBase>($6)))); }
					;

func_decl 			: func_type_name func_block block catch destroy			{ 
						$$ = new NFunction(LOC, FT_Private, nullptr, $1->name.c_str(), $1->templateTypeNames, 
							nullptr, shared_ptr<NodeList>($2), 
							shared_ptr<NBase>($3), shared_ptr<NBase>($4), shared_ptr<NBase>($5));
						delete $1; 
					}
					| func_type_name implement func_block block catch destroy			{ 
						$$ = new NFunction(LOC, FT_Private, nullptr, $1->name.c_str(), $1->templateTypeNames, 
							shared_ptr<CTypeNameList>($2), shared_ptr<NodeList>($3), 
							shared_ptr<NBase>($4), shared_ptr<NBase>($5), shared_ptr<NBase>($6)); 
					}
					| func_type_name func_block return_type_quote block catch destroy { 
						$$ = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>($3), $1->name.c_str(), $1->templateTypeNames, 
							nullptr, shared_ptr<NodeList>($2), 
							shared_ptr<NBase>($4), shared_ptr<NBase>($5), shared_ptr<NBase>($6)); 
					}
					| func_type_name implement func_block return_type_quote block catch destroy { 
						$$ = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>($4), $1->name.c_str(), $1->templateTypeNames, 
							shared_ptr<CTypeNameList>($2), shared_ptr<NodeList>($3), 
							shared_ptr<NBase>($5), shared_ptr<NBase>($6), shared_ptr<NBase>($7)); 
					}
					| TEXTERN TLPAREN TSTRING TRPAREN TIDENTIFIER func_block return_type_quote { 
						$$ = new NFunction(LOC, FT_Extern, $3->c_str(), shared_ptr<CTypeName>($7), $5->c_str(), shared_ptr<NodeList>($6)); 
						delete $3; 
					}
					;

func_type_name		: TIDENTIFIER									{ $$ = new CTypeName(CTC_Value, $1->c_str()); delete $1; }
					| TIDENTIFIER temp_block 						{ $$ = new CTypeName(CTC_Value, $1->c_str(), shared_ptr<CTypeNameList>($2)); delete $1; }
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

implement 			: implement_args								{ $$ = $1; }
					;

implement_args 		: implement_arg									{ $$ = new CTypeNameList(); $$->push_back(shared_ptr<CTypeName>($1)); }							
					| implement_args TCOMMA implement_arg 			{ $$ = $1; $$->push_back(shared_ptr<CTypeName>($3)); }
					;

implement_arg 		: THASH TIDENTIFIER temp_block_optional			{ $$ = new CTypeName(CTC_Interface, $2->c_str(), shared_ptr<CTypeNameList>($3)); delete $2; }							
					;

interface_decl		: THASH TIDENTIFIER temp_block_optional interface_block { $$ = new NInterface(LOC, $2->c_str(), shared_ptr<CTypeNameList>($3), shared_ptr<NodeList>($4)); delete $2; }
					;

interface_block		: TLPAREN interface_args TRPAREN 				{ $$ = $2; }
					;

interface_args		: interface_arg									{ $$ = new NodeList(); if ($1) { $$->push_back(shared_ptr<NBase>($1)); } }
					| interface_args TEND interface_arg 			{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					| interface_args TCOMMA interface_arg 			{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					;

interface_arg 		: /* Blank! */									{ $$ = nullptr; }
					| func_type_name func_block return_type_quote 	{ $$ = new NInterfaceMethod(LOC, $1->name.c_str(), $1->templateTypeNames, shared_ptr<NodeList>($2), shared_ptr<CTypeName>($3)); }
					;

expr 				: if_expr										{ $$ = (NBase*)$1; }
					| for_expr		
					| while_expr								
					| expr_and
					| TTHROW TLPAREN expr TRPAREN					{ $$ = new NThrow(LOC, shared_ptr<NBase>($3)); }
					| expr TAS arg_type   							{ $$ = new NCast(LOC, shared_ptr<CTypeName>($3), shared_ptr<NBase>($1)); }
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

var_right			: func_type_name func_block						{ $$ = new NCall(LOC, $1->name.c_str(), $1->templateTypeNames, shared_ptr<NodeList>($2)); delete $1; }
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
										
assign				: TIDENTIFIER assign_type stmt						{ $$ = new NAssignment(LOC, nullptr, nullptr, $1->c_str(), shared_ptr<NBase>($3), $2); }
					| TIDENTIFIER assign_type arg_type_quote			{ $$ = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>($3), $1->c_str(), nullptr, $2); }								
					| TIDENTIFIER arg_type_quote assign_type stmt		{ $$ = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>($2), $1->c_str(), shared_ptr<NBase>($4), $3); }
					| var TDOT TIDENTIFIER assign_type stmt				{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), nullptr, $3->c_str(), shared_ptr<NBase>($5), $4); }
					| var TDOT TIDENTIFIER assign_type arg_type_quote	{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), shared_ptr<CTypeName>($5), $3->c_str(), nullptr, $4); }								
					| var TDOT TIDENTIFIER arg_type_quote assign_type stmt	{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), shared_ptr<CTypeName>($4), $3->c_str(), shared_ptr<NBase>($6), $5); }
					;

assign_type 		: TEQUAL										{ $$ = true; }
					| TCOLON										{ $$ = false; }
					;

array				: TLBRACKET array_args TRBRACKET				{ $$ = new NList(LOC, shared_ptr<NodeList>($2)); }
					;

array_args 			: expr											{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					| array_args TCOMMA expr 						{ $1->push_back(shared_ptr<NBase>($3)); }
					;

return_type_quote	: TQUOTE return_type							{ $$ = $2; }
					;

arg_type_quote		: TQUOTE arg_type								{ $$ = $2; }
					;

arg_type			: TIDENTIFIER temp_block_optional				{ $$ = new CTypeName(CTC_Value, *$1, shared_ptr<CTypeNameList>($2)); delete $1; }
					| THASH TIDENTIFIER temp_block_optional			{ $$ = new CTypeName(CTC_Interface, *$2, shared_ptr<CTypeNameList>($3)); delete $2; }
					| func_type										{ $$ = $1; }
					;

return_type			: arg_type										{ $$ = $1; }
					| TVOID											{ $$ = new CTypeName(CTC_Value, "void"); }
					;

func_type			: TLPAREN func_arg_type_list TRPAREN return_type { $$ = new CTypeName(shared_ptr<CTypeNameList>($2), shared_ptr<CTypeName>($4)); }
					;

func_arg_type 		: TEQUAL arg_type 								{ $$ = $2; $$->mutability = CTM_Mutable; }
					| TCOLON arg_type 								{ $$ = $2; $$->mutability = CTM_Immutable; }
					;

func_arg_type_list	: /* Blank! */									{ $$ = new CTypeNameList(); }
					| func_arg_type 								{ $$ = new CTypeNameList(); $$->push_back(shared_ptr<CTypeName>($1)); }
					| func_arg_type_list TCOMMA func_arg_type 		{ $1->push_back(shared_ptr<CTypeName>($3)); }
					;

temp_block_optional : /* Blank! */									{ $$ = nullptr; }
					| temp_block									{ $$ = $1; }
					;

temp_block			: TEXCLAIM TIDENTIFIER							{ $$ = new CTypeNameList(); $$->push_back(make_shared<CTypeName>(CTC_Value, *$2)); delete $2; }
					| TEXCLAIM TLBRACKET temp_args TRBRACKET		{ $$ = $3; }					
					;

temp_args			: TIDENTIFIER temp_block_optional				{ $$ = new CTypeNameList(); $$->push_back(make_shared<CTypeName>(CTC_Value, *$1, shared_ptr<CTypeNameList>($2))); delete $1; }
					| temp_args TCOMMA TIDENTIFIER					{ $1->push_back(make_shared<CTypeName>(CTC_Value, *$3)); delete $3; }
					;

%%