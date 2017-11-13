%define parse.error verbose
%define api.pure true
%locations
%token-table
%lex-param {void *scanner}
%parse-param {void *scanner} {CResult* result}

%code requires {
struct OPTIONANDTYPELIST {
	bool isOption;
	CTypeNameList* templateTypeNames;	
};
}

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
	OPTIONANDTYPELIST optionAndTypeList;
	NTupleAssignmentArgList* tupleAssignmentArgList;
	NTupleAssignmentArg* tupleAssignmentArg;
}

/* Terminal symbols. They need to match tokens in tokens.l file */
%token <string> TIDENTIFIER TINTEGER TDOUBLE TINVALID TSTRING TCHAR TCCODE
%token <token> error TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TEND TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TCOLON TQUOTE TPLUS TMINUS TMUL TDIV TTRUE TFALSE TAS TVOID TIF TELSE TTHROW TCATCH TFOR TTO TWHILE TPLUSPLUS TMINUSMINUS TPLUSEQUAL TMINUSEQUAL TLBRACKET TRBRACKET TEXCLAIM TDOT TTHIS TINCLUDE TAND TOR TDESTROY TMOD THASH TAT TCPEQ TCPNE TMULEQUAL TDIVEQUAL TISEMPTY TGETVALUE TASOPTION TQUESTION TEMPTY TVALUE TQUESTIONCOLON TQUESTIONDOT TPARENT

/* Non Terminal symbols. Types refer to union decl above */
%type <node> program stmt var_decl func_decl func_arg for_expr while_expr assign array interface_decl interface_arg block catch destroy expr
%type <var> var var_right expr_math expr_var const expr_and expr_comp tuple expr_and_inner
%type <block> stmts
%type <nif> if_expr
%type <exprvec> func_args func_block array_args tuple_args interface_args interface_block
%type <isMutable> assign_type
%type <typeName> arg_type_quote arg_type return_type_quote return_type func_type func_arg_type func_type_name implement_arg
%type <templateTypeNames> temp_args temp_block temp_block_optional func_arg_type_list implement implement_args
%type <string> arg_type_interface
%type <tupleAssignmentArg> assign_tuple_arg
%type <tupleAssignmentArgList> assign_tuple
%type <optionAndTypeList> temp_option_optional

/* Operator precedence */
%left TAND TOR
%left TPLUS TMINUS
%left TMUL TDIV
%left TMOD
%left TQUESTIONCOLON

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
					| expr 											{ $$ = $1; }
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
					| var TPLUSEQUAL expr_and                  		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Add, shared_ptr<NVariableBase>($3)); }
					| var TMINUSEQUAL expr_and                		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Sub, shared_ptr<NVariableBase>($3)); }
					| var TMULEQUAL expr_and                		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Mul, shared_ptr<NVariableBase>($3)); }
					| var TDIVEQUAL expr_and                		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Div, shared_ptr<NVariableBase>($3)); }
					| var TLBRACKET expr TRBRACKET					{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3)))); }
					| var TLBRACKET expr TRBRACKET TEQUAL stmt		{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "setAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3), shared_ptr<NBase>($6)))); }
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
					;

func_type_name		: TIDENTIFIER									{ $$ = new CTypeName(CTC_Value, $1->c_str(), false); delete $1; }
					| TIDENTIFIER temp_block 						{ $$ = new CTypeName(CTC_Value, $1->c_str(), shared_ptr<CTypeNameList>($2), false); delete $1; }
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
					| interface_decl
					| assign 										
					| func_decl 										
					| expr 											{ $$ = $1; }
					; 

implement 			: implement_args								{ $$ = $1; }
					;

implement_args 		: implement_arg									{ $$ = new CTypeNameList(); $$->push_back(shared_ptr<CTypeName>($1)); }							
					| implement_args implement_arg 					{ $$ = $1; $$->push_back(shared_ptr<CTypeName>($2)); }
					;

implement_arg 		: THASH arg_type_interface temp_block_optional	{ $$ = new CTypeName(CTC_Interface, (string("#") + *$2).c_str(), shared_ptr<CTypeNameList>($3), false); delete $2; }							
					;

interface_decl		: THASH TIDENTIFIER temp_block_optional interface_block { $$ = new NInterface(LOC, (string("#") + *$2).c_str(), shared_ptr<CTypeNameList>($3), shared_ptr<NodeList>($4)); delete $2; }
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

expr 				: if_expr										{ $$ = $1; }
					| for_expr										
					| while_expr								
					| expr_and										{ $$ = $1; }
					| array
					| TTHROW TLPAREN expr TRPAREN					{ $$ = new NThrow(LOC, shared_ptr<NBase>($3)); }
					| TVOID											{ $$ = new NVoid(LOC); }
					;

expr_and			: expr_comp TAND expr_and 						{ $$ = new NAnd(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| expr_comp TOR expr_and 						{ $$ = new NOr(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| expr_comp
					;					

expr_and_inner		: expr_comp TAND expr_and 						{ $$ = new NAnd(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| expr_comp TOR expr_and 						{ $$ = new NOr(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| tuple 										{ $$ = $1; }
					| expr_comp
					;					

expr_comp 			: expr_math TCEQ expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::EQ, shared_ptr<NVariableBase>($3)); }
					| expr_math TCNE expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::NE, shared_ptr<NVariableBase>($3)); }
					| expr_math TCPEQ expr_math 					{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::PEQ, shared_ptr<NVariableBase>($3)); }
					| expr_math TCPNE expr_math 					{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::PNE, shared_ptr<NVariableBase>($3)); }
					| expr_math TCLT expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::LT, shared_ptr<NVariableBase>($3)); }
					| expr_math TCLE expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::LE, shared_ptr<NVariableBase>($3)); }
					| expr_math TCGT expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::GT, shared_ptr<NVariableBase>($3)); }
					| expr_math TCGE expr_math 						{ $$ = new NCompare(LOC, shared_ptr<NVariableBase>($1), NCompareOp::GE, shared_ptr<NVariableBase>($3)); }
					| expr_math										{ $$ = $1; }
					;

expr_math			: expr_math TPLUS expr_math 					{ $$ = new NMath(LOC, shared_ptr<NVariableBase>($1), NMathOp::Add, shared_ptr<NVariableBase>($3)); }
					| expr_math TMINUS expr_math 					{ $$ = new NMath(LOC, shared_ptr<NVariableBase>($1), NMathOp::Sub, shared_ptr<NVariableBase>($3)); }
					| expr_math TMUL expr_math 						{ $$ = new NMath(LOC, shared_ptr<NVariableBase>($1), NMathOp::Mul, shared_ptr<NVariableBase>($3)); }
					| expr_math TDIV expr_math 						{ $$ = new NMath(LOC, shared_ptr<NVariableBase>($1), NMathOp::Div, shared_ptr<NVariableBase>($3)); }
					| expr_math TMOD expr_math 						{ $$ = new NMath(LOC, shared_ptr<NVariableBase>($1), NMathOp::Mod, shared_ptr<NVariableBase>($3)); }
					| expr_math TQUESTIONCOLON expr_math			{ $$ = new NGetOrElse(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| TEXCLAIM expr_var                             { $$ = new NNot(LOC, shared_ptr<NVariableBase>($2)); }
					| expr_var TAS arg_type 						{ $$ = new NCast(LOC, shared_ptr<CTypeName>($3), shared_ptr<NVariableBase>($1)); }
					| expr_var										{ $$ = $1; }
					;

expr_var 			: TLPAREN expr_and_inner TRPAREN				{ $$ = $2; }
					| var 											{ $$ = $1; }
					| const											{ $$ = $1; }
					;

for_expr			: TFOR TIDENTIFIER TLPAREN expr TTO expr TRPAREN block   { $$ = new NFor(LOC, $2->c_str(), shared_ptr<NBase>($4), shared_ptr<NBase>($6), shared_ptr<NBase>($8)); delete $2; }
					;

while_expr			: TWHILE expr block 							{ $$ = new NWhile(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3)); }
					;
					
if_expr		 		: TIF expr block								{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), nullptr); }
					| TIF expr block TELSE block					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					| TIF expr block TELSE if_expr					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					;

var					: var TDOT var_right							{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| var TQUESTIONDOT var_right					{ $$ = new NOptionDot(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| var_right										
					;

var_right			: func_type_name func_block						{ $$ = new NCall(LOC, $1->name.c_str(), $1->templateTypeNames, shared_ptr<NodeList>($2)); delete $1; }
					| TISEMPTY TLPAREN expr TRPAREN					{ $$ = new NIsEmpty(LOC, shared_ptr<NBase>($3)); }
					| TGETVALUE TLPAREN expr TRPAREN				{ $$ = new NGetValue(LOC, shared_ptr<NBase>($3), false); }
					| TVALUE TLPAREN expr TRPAREN					{ $$ = new NValue(LOC, shared_ptr<NBase>($3)); }
	 				| TIDENTIFIER									{ $$ = new NVariable(LOC, $1->c_str()); delete $1; }
	 				| TPARENT										{ $$ = new NParent(LOC); }
	 				| TTHIS											{ $$ = new NThis(LOC); }
	 				;

const 				: TMINUS TINTEGER 								{ $2->insert(0, "-"); $$ = new NInteger(LOC, $2->c_str()); delete $2; }
					| TINTEGER 										{ $$ = new NInteger(LOC, $1->c_str()); delete $1; }
					| TMINUS TDOUBLE 								{ $2->insert(0, "-"); $$ = new NDouble(LOC, $2->c_str()); delete $2; }
					| TDOUBLE 										{ $$ = new NDouble(LOC, $1->c_str()); delete $1; }
					| TTRUE											{ $$ = new NBool(LOC, true); }
					| TFALSE										{ $$ = new NBool(LOC, false); }
					| TSTRING										{ $$ = new NString(LOC, $1->c_str()); delete $1; }
					| TCHAR											{ $$ = new NChar(LOC, $1->c_str()); delete $1; }
					| TEMPTY arg_type_quote							{ $$ = new NEmpty(LOC, shared_ptr<CTypeName>($2)); }
					;
										
assign				: TIDENTIFIER assign_type stmt						{ $$ = new NAssignment(LOC, nullptr, nullptr, $1->c_str(), shared_ptr<NBase>($3), $2); }
					| TIDENTIFIER assign_type arg_type_quote			{ $$ = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>($3), $1->c_str(), nullptr, $2); }								
					| TIDENTIFIER arg_type_quote assign_type stmt		{ $$ = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>($2), $1->c_str(), shared_ptr<NBase>($4), $3); }
					| var TDOT TIDENTIFIER assign_type stmt				{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), nullptr, $3->c_str(), shared_ptr<NBase>($5), $4); }
					| var TDOT TIDENTIFIER assign_type arg_type_quote	{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), shared_ptr<CTypeName>($5), $3->c_str(), nullptr, $4); }								
					| var TDOT TIDENTIFIER arg_type_quote assign_type stmt	{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), shared_ptr<CTypeName>($4), $3->c_str(), shared_ptr<NBase>($6), $5); }
					| TLPAREN assign_tuple TRPAREN expr_and				{ $$ = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>($2), shared_ptr<NVariableBase>($4)); }
					;

assign_tuple 		: assign_tuple_arg								{ $$ = new NTupleAssignmentArgList(); $$->push_back(shared_ptr<NTupleAssignmentArg>($1)); }
					| assign_tuple TCOMMA assign_tuple_arg 			{ $1->push_back(shared_ptr<NTupleAssignmentArg>($3)); }
					;

assign_tuple_arg	: TIDENTIFIER assign_type						{ $$ = new NTupleAssignmentArg(LOC, nullptr, nullptr, $1->c_str(), $2); }
					| TIDENTIFIER assign_type arg_type_quote		{ $$ = new NTupleAssignmentArg(LOC, nullptr, shared_ptr<CTypeName>($3), $1->c_str(), $2); }
					| var TDOT TIDENTIFIER assign_type				{ $$ = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>($1), nullptr, $3->c_str(), $4); }
					;

assign_type 		: TEQUAL										{ $$ = true; }
					| TCOLON										{ $$ = false; }
					;

tuple				: tuple_args TCOMMA expr_comp					{ $1->push_back(shared_ptr<NBase>($3)); $$ = new NTuple(LOC, shared_ptr<NodeList>($1)); }
					;

tuple_args 			: expr_comp										{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					| tuple_args TCOMMA expr_comp 					{ $1->push_back(shared_ptr<NBase>($3)); }
					;

array				: TLBRACKET array_args TRBRACKET				{ $$ = new NArray(LOC, shared_ptr<NodeList>($2)); }
					;

array_args 			: expr											{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					| array_args TCOMMA expr 						{ $1->push_back(shared_ptr<NBase>($3)); }
					;

return_type_quote	: TQUOTE return_type							{ $$ = $2; }
					;

arg_type_quote		: TQUOTE arg_type								{ $$ = $2; }
					;

arg_type			: TIDENTIFIER temp_option_optional 					{ $$ = new CTypeName(CTC_Value, *$1 + ($2.isOption ? "?" : ""), shared_ptr<CTypeNameList>($2.templateTypeNames), $2.isOption); delete $1; }
					| THASH arg_type_interface temp_option_optional 	{ $$ = new CTypeName(CTC_Interface, string("#") + *$2 + ($3.isOption ? "?" : ""), shared_ptr<CTypeNameList>($3.templateTypeNames), $3.isOption); delete $2; }
					| func_type											{ $$ = $1; }
					;

arg_type_interface	: TIDENTIFIER									{ $$ = $1; }
					| TIDENTIFIER TDOT arg_type_interface			{ $$ = new string(*$1 + "." + *$3); }
					;

return_type			: arg_type										{ $$ = $1; }
					| TVOID											{ $$ = new CTypeName(CTC_Value, "void", false); }
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

temp_option_optional: /* Blank! */									{ $$.isOption = false;  $$.templateTypeNames = nullptr; }
					| TQUESTION 									{ $$.isOption = true;   $$.templateTypeNames = nullptr; }
					| temp_block									{ $$.isOption = false;  $$.templateTypeNames = $1; }
					| TQUESTION temp_block 							{ $$.isOption = true;   $$.templateTypeNames = $2; }
					;

temp_block			: TEXCLAIM arg_type								{ $$ = new CTypeNameList(); $$->push_back(shared_ptr<CTypeName>($2)); }
					| TEXCLAIM TLBRACKET temp_args TRBRACKET		{ $$ = $3; }					
					;

temp_args			: arg_type										{ $$ = new CTypeNameList(); $$->push_back(shared_ptr<CTypeName>($1)); }
					| temp_args TCOMMA arg_type						{ $1->push_back(shared_ptr<CTypeName>($3)); }
					;

%%