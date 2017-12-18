%define parse.error verbose
%define api.pure true
%locations
%token-table
%lex-param {void *scanner}
%parse-param {void *scanner} {Compiler* compiler} {CParseFile* parseFile}

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

#define LOC CLoc(parseFile->fullFileName, parseFile->shortFileName, yyloc.first_line, yyloc.first_column)
#define LLOC CLoc(parseFile->fullFileName, parseFile->shortFileName, yylloc.first_line, yylloc.first_column)

int yyerror(YYLTYPE *locp, void *scanner, Compiler* compiler, CParseFile* parseFile, const char *msg) {
  if (locp) {
  	compiler->addWarning(CLoc(parseFile->fullFileName, parseFile->shortFileName, locp->first_line, locp->first_column), CErrorCode::Parser, msg);
  } else {
  	compiler->addWarning(CLoc::undefined, CErrorCode::Parser, msg);
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
	NVariableBase* var;
	NodeList* exprvec;
	std::string* string;
	CTypeName* typeName;
	CTypeNameList* templateTypeNames;
	int token;
	AssignOp assignOp;
	OPTIONANDTYPELIST optionAndTypeList;
	NTupleAssignmentArgList* tupleAssignmentArgList;
	NTupleAssignmentArg* tupleAssignmentArg;
	CTypeMode typeMode;
	EnumArg* enumArg;
	EnumArgs* enumArgs;
	std::vector<std::string>* strings;
	std::vector<std::pair<std::string, std::vector<std::string>>>* import_namespaces;
	std::pair<std::string, std::vector<std::string>>* import_namespace;
	NCCode* ccode;
	CTypeNameParts* typeNameParts;
	vector<shared_ptr<NSwitchClause>>* switchClauses;
	NSwitchClause* switchClause;
}

/* Terminal symbols. They need to match tokens in tokens.l file */
%token <string> TIDENTIFIER TINTEGER TDOUBLE TSTRING TCHAR TCBLOCK TCFUNCTION TCDEFINE TCSTRUCT TCINCLUDE TCVAR TCTYPEDEF
%token <token> error TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TEND TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TCOLON TQUOTE TPLUS TMINUS TMUL TDIV TTRUE TFALSE TAS TVOID TIF TELSE TTHROW TCATCH TFOR TTO TWHILE TPLUSPLUS TMINUSMINUS TPLUSEQUAL TMINUSEQUAL TLBRACKET TRBRACKET TEXCLAIM TDOT TTHIS TINCLUDE TAND TOR TCOPY TDESTROY TMOD THASH TCPEQ TCPNE TMULEQUAL TDIVEQUAL TISEMPTY TGETVALUE TQUESTION TEMPTY TVALUE TQUESTIONCOLON TQUESTIONDOT TPARENT TSTACK THEAP TWEAK TLOCAL TTYPEI32 TTYPEU32 TTYPEF32 TTYPEI64 TTYPEU64 TTYPEF64 TTYPECHAR TTYPEBOOL TTYPEPTR TINVALID TCOLONEQUAL THEAPPARENT THEAPTHIS TIFVALUE TELSEEMPTY TTOREVERSE TENUM TSWITCH TDEFAULT TPACKAGE TIMPORT TUNDERSCORE TNULLPTR

/* Non Terminal symbols. Types refer to union decl above */
%type <node> program stmt var_decl func_decl func_arg for_expr while_expr assign array interface_decl interface_arg block catch copy destroy expr end_optional end_star if_expr ifValue_var enum_decl switch_expr
%type <var> var_right expr_math expr_var const expr_and expr_comp tuple
%type <block> stmts
%type <exprvec> func_args func_block array_args tuple_args interface_args interface_block ifValue_vars
%type <assignOp> assign_type assign_tuple_type
%type <typeName> arg_type_quote arg_type return_type_quote return_type func_type func_arg_type func_type_name implement_arg value_type  
%type <templateTypeNames> temp_args temp_block temp_block_optional func_arg_type_list implement implement_args
%type <tupleAssignmentArg> assign_tuple_arg
%type <tupleAssignmentArgList> assign_tuple
%type <optionAndTypeList> temp_option_optional
%type <typeMode> arg_mode
%type <enumArgs> enum_args
%type <enumArg> enum_arg
%type <strings> namespace namespace_dot
%type <ccode> cblock cdefine cstruct cfunction cinclude ctypedef cvar
%type <import_namespaces> import_namespaces
%type <import_namespace> import_namespace
%type <typeNameParts> namespace_hash namespace_last
%type <string> namespace_ident
%type <switchClauses> switch_clauses
%type <switchClause> switch_clause

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

program 			: stmts 										{ parseFile->block = std::shared_ptr<NBlock>($1); }
					;

stmts 				: stmt											{ $$ = new NBlock(LOC); if ($1) $$->statements.push_back(shared_ptr<NBase>($1)); }
					| stmts TEND stmt								{ if ($3) $1->statements.push_back(shared_ptr<NBase>($3)); }
					;
					
stmt 				: /* Blank! */									{ $$ = nullptr; }
					| var_decl
					| func_decl 
					| interface_decl
					| enum_decl
					| expr 											{ $$ = $1; }
					| cblock										{ $$ = $1; }
					| cdefine										{ $$ = $1; }
					| cstruct										{ $$ = $1; }
					| cfunction										{ $$ = $1; }
					| cinclude										{ $$ = $1; }
					| ctypedef										{ $$ = $1; }
					| TINCLUDE TSTRING								{ $$ = new NInclude(LOC, $2->c_str()); delete $2; }
					| TPACKAGE namespace block						{ $$ = new NPackage(LOC, *$2, shared_ptr<NBase>($3)); delete $2; }
					| TIMPORT end_optional import_namespaces end_optional block	{ $$ = new NImport(LOC, *$3, shared_ptr<NBase>($5)); delete $3; }
					| error	 										{ $$ = nullptr; /* yyclearin; */ compiler->addError(LLOC, CErrorCode::InvalidCharacter, "Something failed to parse"); }
					;

cblock 				: cblock TCBLOCK 								{ $$->lines.push_back(*$2); delete $2; }
					| TCBLOCK                                       { $$ = new NCCode(LOC, NCC_BLOCK, $1->c_str()); delete $1; }
					;

cdefine 			: cdefine TCDEFINE 								{ $$->lines.push_back(*$2); delete $2; }
					| TCDEFINE                                      { $$ = new NCCode(LOC, NCC_DEFINE, $1->c_str()); delete $1; }
					;

cstruct 			: cstruct TCSTRUCT 								{ $$->lines.push_back(*$2); delete $2; }
					| TCSTRUCT                                      { $$ = new NCCode(LOC, NCC_STRUCT, $1->c_str()); delete $1; }
					;

cfunction 			: cfunction TCFUNCTION 							{ $$->lines.push_back(*$2); delete $2; }
					| TCFUNCTION                                    { $$ = new NCCode(LOC, NCC_FUNCTION, $1->c_str()); delete $1; }
					;

cinclude			: cinclude TCINCLUDE 							{ $$->lines.push_back(*$2); delete $2; }
					| TCINCLUDE                                     { $$ = new NCCode(LOC, NCC_INCLUDE, $1->c_str()); delete $1; }
					;

ctypedef			: ctypedef TCTYPEDEF 							{ $$->lines.push_back(*$2); delete $2; }
					| TCTYPEDEF                                     { $$ = new NCCode(LOC, NCC_TYPEDEF, $1->c_str()); delete $1; }
					;

cvar				: cvar TCVAR 									{ $$->lines.push_back(*$2); delete $2; }
					| TCVAR                                     	{ $$ = new NCCode(LOC, NCC_VAR, $1->c_str()); delete $1; }
					;

import_namespaces 	: import_namespaces end_star import_namespace 	{ $1->push_back(*$3); delete $3; }
					| import_namespaces TCOMMA import_namespace     { $1->push_back(*$3); delete $3; }
					| import_namespace 								{ $$ = new vector<pair<string, vector<string>>>(); $$->push_back(*$1); delete $1; }
					;

import_namespace    : TIDENTIFIER TCOLON namespace 					{ $$ = new pair<string, vector<string>>(*$1, *$3); delete $1; delete $3; }
					| namespace 									{ $$ = new pair<string, vector<string>>("", *$1); delete $1; }
					;

namespace 			: namespace TDOT TIDENTIFIER               		{ $$->push_back(*$3); delete $3; }
					| TIDENTIFIER									{ $$ = new vector<string>(); $$->push_back(*$1); delete $1; }
					;

block 				: TLBRACE stmts TRBRACE 						{ $$ = $2; }
					;

var_decl 			: assign
					| expr_var TPLUSPLUS                         		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Inc, nullptr); }
					| expr_var TMINUSMINUS                       		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Dec, nullptr); }
					| expr_var TPLUSEQUAL expr_and                  	{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Add, shared_ptr<NVariableBase>($3)); }
					| expr_var TMINUSEQUAL expr_and                		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Sub, shared_ptr<NVariableBase>($3)); }
					| expr_var TMULEQUAL expr_and                		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Mul, shared_ptr<NVariableBase>($3)); }
					| expr_var TDIVEQUAL expr_and                		{ $$ = new NMathAssignment(LOC, shared_ptr<NVariableBase>($1), NMAO_Div, shared_ptr<NVariableBase>($3)); }
					| expr_var TLBRACKET expr TRBRACKET TEQUAL stmt		{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "setAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3), shared_ptr<NBase>($6)))); }
					;

enum_decl			: TENUM TIDENTIFIER TLPAREN end_optional enum_args end_optional TRPAREN 		{ $$ = new NEnum(LOC, *$2, shared_ptr<EnumArgs>($5)); delete $2; }
					;

enum_args			: enum_args end_star enum_arg 						{ $1->push_back(shared_ptr<EnumArg>($3)); }
					| enum_args TCOMMA enum_arg                         { $1->push_back(shared_ptr<EnumArg>($3)); }
					| enum_arg 											{ $$ = new EnumArgs(shared_ptr<EnumArg>($1)); }
					;

enum_arg 			: TIDENTIFIER 										{ $$ = new EnumArg(*$1); delete $1; }
					| TIDENTIFIER TCOLON TINTEGER 						{ $$ = new EnumArg(*$1, *$3); delete $1; delete $3; }
					;

func_decl 			: func_type_name func_block block catch copy destroy			{ 
						$$ = new NFunction(LOC, FT_Private, nullptr, $1->valueName.c_str(), $1->templateTypeNames, 
							nullptr, shared_ptr<NodeList>($2), 
							shared_ptr<NBase>($3), shared_ptr<NBase>($4), shared_ptr<NBase>($5), shared_ptr<NBase>($6));
						delete $1; 
					}
					| func_type_name implement func_block block catch copy destroy			{ 
						$$ = new NFunction(LOC, FT_Private, nullptr, $1->valueName.c_str(), $1->templateTypeNames, 
							shared_ptr<CTypeNameList>($2), shared_ptr<NodeList>($3), 
							shared_ptr<NBase>($4), shared_ptr<NBase>($5), shared_ptr<NBase>($6), shared_ptr<NBase>($7)); 
					}
					| func_type_name func_block return_type_quote block catch copy destroy { 
						$$ = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>($3), $1->valueName.c_str(), $1->templateTypeNames, 
							nullptr, shared_ptr<NodeList>($2), 
							shared_ptr<NBase>($4), shared_ptr<NBase>($5), shared_ptr<NBase>($6), shared_ptr<NBase>($7)); 
					}
					| func_type_name implement func_block return_type_quote block catch copy destroy { 
						$$ = new NFunction(LOC, FT_Private, shared_ptr<CTypeName>($4), $1->valueName.c_str(), $1->templateTypeNames, 
							shared_ptr<CTypeNameList>($2), shared_ptr<NodeList>($3), 
							shared_ptr<NBase>($5), shared_ptr<NBase>($6), shared_ptr<NBase>($7), shared_ptr<NBase>($8)); 
					}
					;

func_type_name		: TIDENTIFIER									{ $$ = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, $1->c_str(), false); delete $1; }
					| TIDENTIFIER temp_block 						{ $$ = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, $1->c_str(), shared_ptr<CTypeNameList>($2), false); delete $1; }
					;

copy				: /* Blank! */									{ $$ = nullptr; }
					| TCOPY block									{ $$ = $2; }
					;

catch				: /* Blank! */									{ $$ = nullptr; }
					| TCATCH block									{ $$ = $2; }
					;

destroy				: /* Blank! */									{ $$ = nullptr; }
					| TDESTROY block								{ $$ = $2; }
					;

func_block			: TLPAREN end_optional func_args end_optional TRPAREN	{ $$ = $3; }
   					| TLPAREN TRPAREN										{ $$ = new NodeList(); }
					;

func_args  			: func_arg										{ $$ = new NodeList(); if ($1) { $$->push_back(shared_ptr<NBase>($1)); } }
					| func_args end_star func_arg 					{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					| func_args TCOMMA end_star func_arg 			{ if ($4) { $1->push_back(shared_ptr<NBase>($4)); } }
					| func_args TCOMMA func_arg 					{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					;

func_arg			: interface_decl
					| assign 										
					| func_decl 										
					| cvar											{ $$ = $1; }
					| expr 											{ $$ = $1; }
					; 

implement 			: implement_args								{ $$ = $1; }
					;

implement_args 		: implement_arg									{ $$ = new CTypeNameList(); $$->push_back(shared_ptr<CTypeName>($1)); }							
					| implement_args implement_arg 					{ $$ = $1; $$->push_back(shared_ptr<CTypeName>($2)); }
					;

implement_arg 		: THASH namespace temp_block_optional			{ string t = $2->back(); $2->pop_back(); $$ = new CTypeName(CTC_Interface, CTM_Stack, *$2, t, shared_ptr<CTypeNameList>($3), false); delete $2; }							
					;

interface_decl		: THASH TIDENTIFIER temp_block_optional interface_block { $$ = new NInterface(LOC, *$2, shared_ptr<CTypeNameList>($3), shared_ptr<NodeList>($4)); delete $2; }
					;

interface_block		: TLPAREN interface_args TRPAREN 				{ $$ = $2; }
					;

interface_args		: interface_arg									{ $$ = new NodeList(); if ($1) { $$->push_back(shared_ptr<NBase>($1)); } }
					| interface_args TEND interface_arg 			{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					| interface_args TCOMMA interface_arg 			{ if ($3) { $1->push_back(shared_ptr<NBase>($3)); } }
					;

interface_arg 		: /* Blank! */									{ $$ = nullptr; }
					| func_type_name func_block return_type_quote 	{ $$ = new NInterfaceMethod(LOC, $1->valueName.c_str(), $1->templateTypeNames, shared_ptr<NodeList>($2), shared_ptr<CTypeName>($3)); }
					;

expr 				: if_expr										{ $$ = $1; }
					| for_expr	
					| switch_expr 									{ $$ = $1; }									
					| while_expr								
					| expr_and										{ $$ = $1; }
					| tuple 										{ $$ = $1; }
					| array
					| TTHROW TLPAREN expr TRPAREN					{ $$ = new NThrow(LOC, shared_ptr<NBase>($3)); }
					| TVOID											{ $$ = new NVoid(LOC); }
					;

expr_and			: expr_comp TAND expr_and 						{ $$ = new NAnd(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| expr_comp TOR expr_and 						{ $$ = new NOr(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
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
					| TEXCLAIM expr_var                             { $$ = new NNot(LOC, shared_ptr<NVariableBase>($2)); }
					| TSTACK expr_var                             	{ $$ = new NChangeMode(LOC, CTM_Stack, shared_ptr<NBase>($2)); }
					| TLOCAL expr_var                             	{ $$ = new NChangeMode(LOC, CTM_Local, shared_ptr<NBase>($2)); }
					| THEAP expr_var                             	{ $$ = new NChangeMode(LOC, CTM_Heap, shared_ptr<NBase>($2)); }
					| TWEAK expr_var                             	{ $$ = new NChangeMode(LOC, CTM_Weak, shared_ptr<NBase>($2)); }
					| TCOPY expr_var                             	{ $$ = new NCopy(LOC, shared_ptr<NBase>($2)); }
					| expr_var										{ $$ = $1; }
					;

expr_var 			: expr_var TAS arg_type 						{ $$ = new NCast(LOC, shared_ptr<CTypeName>($3), shared_ptr<NVariableBase>($1)); }
					| expr_var TDOT var_right						{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| expr_var TQUESTIONCOLON var_right				{ $$ = new NGetOrElse(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NBase>($3)); }
					| expr_var TQUESTIONDOT var_right				{ $$ = new NOptionDot(LOC, shared_ptr<NVariableBase>($1), shared_ptr<NVariableBase>($3)); }
					| expr_var TLBRACKET expr TRBRACKET				{ $$ = new NDot(LOC, shared_ptr<NVariableBase>($1), make_shared<NCall>(LOC, "getAt", nullptr, make_shared<NodeList>(shared_ptr<NBase>($3)))); }
					| var_right 									{ $$ = $1; }
					;

for_expr			: TFOR TIDENTIFIER TCOLON expr TTO expr block   { $$ = new NFor(LOC, $2->c_str(), shared_ptr<NBase>($4), shared_ptr<NBase>($6), shared_ptr<NBase>($7), true); delete $2; }
					| TFOR TIDENTIFIER TCOLON expr TTOREVERSE expr block   { $$ = new NFor(LOC, $2->c_str(), shared_ptr<NBase>($4), shared_ptr<NBase>($6), shared_ptr<NBase>($7), false); delete $2; }
					;

while_expr			: TWHILE expr block 							{ $$ = new NWhile(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3)); }
					;

switch_expr 		: TSWITCH expr TLBRACE end_optional switch_clauses end_optional TRBRACE   { $$ = new NSwitch(LOC, shared_ptr<NBase>($2), *$5); delete $5; }
					| TSWITCH TLBRACE end_optional switch_clauses end_optional TRBRACE 		  { $$ = new NSwitch(LOC, nullptr, *$4); delete $4; }
					;

switch_clauses      : switch_clause 								{ $$ = new vector<shared_ptr<NSwitchClause>>(); $$->push_back(shared_ptr<NSwitchClause>($1)); }
					| switch_clauses end_star switch_clause         { $$ = $1; $$->push_back(shared_ptr<NSwitchClause>($3)); }
					;

switch_clause       : expr block 									{ $$ = new NSwitchClause(LOC, shared_ptr<NBase>($1), shared_ptr<NBase>($2)); }
					| TDEFAULT block 								{ $$ = new NSwitchClause(LOC, nullptr, shared_ptr<NBase>($2)); }
					;
					
if_expr		 		: TIF expr block								{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), nullptr); }
					| TIF expr block TELSE block					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					| TIF expr block TELSE if_expr					{ $$ = new NIf(LOC, shared_ptr<NBase>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					| TIFVALUE ifValue_vars block					{ $$ = new NIfValue(LOC, shared_ptr<NodeList>($2), shared_ptr<NBase>($3), nullptr); }
					| TIFVALUE ifValue_vars block TELSEEMPTY block	{ $$ = new NIfValue(LOC, shared_ptr<NodeList>($2), shared_ptr<NBase>($3), shared_ptr<NBase>($5)); }
					;

ifValue_vars 		: ifValue_vars TCOMMA ifValue_var 				{ $1->push_back(shared_ptr<NBase>($3)); $$ = $1; }
					| ifValue_var 									{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					;

ifValue_var			: TIDENTIFIER assign_type expr					{ $$ = new NAssignment(LOC, nullptr, nullptr, $1->c_str(), shared_ptr<NBase>($3), $2); }
					| func_type_name 								{ $$ = new NVariable(LOC, $1->valueName.c_str(), $1->templateTypeNames); delete $1; }
					;

var_right			: TLPAREN expr TRPAREN							{ $$ = new NVariableStub(shared_ptr<NBase>($2)); }
					| func_type_name func_block						{ $$ = new NCall(LOC, $1->valueName.c_str(), $1->templateTypeNames, shared_ptr<NodeList>($2)); delete $1; }
					| TISEMPTY TLPAREN expr TRPAREN					{ $$ = new NIsEmpty(LOC, shared_ptr<NBase>($3)); }
					| TGETVALUE TLPAREN expr TRPAREN				{ $$ = new NGetValue(LOC, shared_ptr<NBase>($3), false); }
					| TVALUE TLPAREN expr TRPAREN					{ $$ = new NValue(LOC, shared_ptr<NBase>($3)); }
	 				| func_type_name								{ $$ = new NVariable(LOC, $1->valueName.c_str(), $1->templateTypeNames); delete $1; }
	 				| TPARENT										{ $$ = new NParent(LOC, false); }
	 				| TTHIS											{ $$ = new NThis(LOC, false); }
	 				| THEAPPARENT									{ $$ = new NParent(LOC, true); }
	 				| THEAPTHIS										{ $$ = new NThis(LOC, true); }
					| TMINUS var_right 								{ $$ = new NNegate(LOC, shared_ptr<NVariableBase>($2)); }
					| const											{ $$ = $1; }
	 				;

const 				: TINTEGER 										{ $$ = new NInteger(LOC, $1->c_str()); delete $1; }
					| TDOUBLE 										{ $$ = new NDouble(LOC, $1->c_str()); delete $1; }
					| TTRUE											{ $$ = new NBool(LOC, true); }
					| TFALSE										{ $$ = new NBool(LOC, false); }
					| TSTRING										{ $$ = new NString(LOC, $1->c_str()); delete $1; }
					| TCHAR											{ $$ = new NChar(LOC, $1->c_str()); delete $1; }
					| TNULLPTR 										{ $$ = new NNullPtr(LOC); }
					| TUNDERSCORE 									{ $$ = new NUnderscore(LOC); }
					| TEMPTY arg_type_quote							{ $$ = new NEmpty(LOC, shared_ptr<CTypeName>($2)); }
					;
										
assign				: TIDENTIFIER assign_type stmt								{ $$ = new NAssignment(LOC, nullptr, nullptr, $1->c_str(), shared_ptr<NBase>($3), $2); }
					| TIDENTIFIER assign_type arg_type_quote					{ $$ = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>($3), $1->c_str(), nullptr, $2); }								
					| TIDENTIFIER arg_type_quote assign_type stmt				{ $$ = new NAssignment(LOC, nullptr, shared_ptr<CTypeName>($2), $1->c_str(), shared_ptr<NBase>($4), $3); }
					| expr_var TDOT TIDENTIFIER assign_type stmt				{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), nullptr, $3->c_str(), shared_ptr<NBase>($5), $4); }
					| expr_var TDOT TIDENTIFIER assign_type arg_type_quote		{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), shared_ptr<CTypeName>($5), $3->c_str(), nullptr, $4); }								
					| expr_var TDOT TIDENTIFIER arg_type_quote assign_type stmt	{ $$ = new NAssignment(LOC, shared_ptr<NVariableBase>($1), shared_ptr<CTypeName>($4), $3->c_str(), shared_ptr<NBase>($6), $5); }
					| TLPAREN assign_tuple TRPAREN expr							{ $$ = new NTupleAssignment(LOC, shared_ptr<NTupleAssignmentArgList>($2), shared_ptr<NBase>($4)); }
					;

assign_tuple 		: assign_tuple_arg								{ $$ = new NTupleAssignmentArgList(); $$->push_back(shared_ptr<NTupleAssignmentArg>($1)); }
					| assign_tuple TCOMMA assign_tuple_arg 			{ $1->push_back(shared_ptr<NTupleAssignmentArg>($3)); }
					;

assign_tuple_arg	: TIDENTIFIER assign_tuple_type					{ $$ = new NTupleAssignmentArg(LOC, nullptr, nullptr, $1->c_str(), $2); }
					| expr_var TDOT TIDENTIFIER assign_tuple_type	{ $$ = new NTupleAssignmentArg(LOC, shared_ptr<NVariableBase>($1), nullptr, $3->c_str(), $4); }
					;

assign_tuple_type	: TEQUAL 										{ $$.isCopy = false; $$.typeMode = CTM_Undefined; $$.isMutable = true;  $$.isFirstAssignment = false; }
					| TCOLONEQUAL 									{ $$.isCopy = false; $$.typeMode = CTM_Undefined; $$.isMutable = true;  $$.isFirstAssignment = true; }
					| TCOLON 										{ $$.isCopy = false; $$.typeMode = CTM_Undefined; $$.isMutable = false; $$.isFirstAssignment = true; }
					| TEQUAL TCOPY 									{ $$.isCopy = true; $$.typeMode = CTM_Undefined; $$.isMutable = true;  $$.isFirstAssignment = false; }
					| TCOLONEQUAL TCOPY 							{ $$.isCopy = true; $$.typeMode = CTM_Undefined; $$.isMutable = true;  $$.isFirstAssignment = true; }
					| TCOLON TCOPY 									{ $$.isCopy = true; $$.typeMode = CTM_Undefined; $$.isMutable = false; $$.isFirstAssignment = true; }
					;

assign_type 		: TEQUAL 										{ $$.isCopy = false; $$.typeMode = CTM_Undefined; $$.isMutable = true;  $$.isFirstAssignment = false; }
					| TCOLONEQUAL 									{ $$.isCopy = false; $$.typeMode = CTM_Undefined; $$.isMutable = true;  $$.isFirstAssignment = true; }
					| TCOLON 										{ $$.isCopy = false; $$.typeMode = CTM_Undefined; $$.isMutable = false; $$.isFirstAssignment = true; }
					;

tuple				: TLPAREN tuple_args TCOMMA expr_comp TRPAREN	{ $2->push_back(shared_ptr<NBase>($4)); $$ = new NTuple(LOC, shared_ptr<NodeList>($2)); }
					;

tuple_args 			: expr_comp										{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					| tuple_args TCOMMA expr_comp 					{ $1->push_back(shared_ptr<NBase>($3)); }
					;

array				: TLBRACKET end_optional array_args end_optional TRBRACKET	{ $$ = new NArray(LOC, shared_ptr<NodeList>($3)); }
					;

end_optional		: /* Blank! */									{ $$ = nullptr; }			
					| end_star									    { $$ = nullptr; }
					;

end_star			: TEND											{ $$ = nullptr; }			
					| TEND end_star									{ $$ = nullptr; }
					;

array_args 			: expr											{ $$ = new NodeList(); $$->push_back(shared_ptr<NBase>($1)); }
					| array_args end_star expr 						{ $1->push_back(shared_ptr<NBase>($3)); }
					| array_args TCOMMA end_star expr 				{ $1->push_back(shared_ptr<NBase>($4)); }
					| array_args TCOMMA expr 						{ $1->push_back(shared_ptr<NBase>($3)); }
					;

return_type_quote	: TQUOTE return_type							{ $$ = $2; }
					;

arg_type_quote		: TQUOTE arg_type								{ $$ = $2; }
					;

arg_type			: value_type										{ $$ = $1; }
					| arg_mode namespace_hash temp_option_optional 		{ $$ = new CTypeName($2->isHash ? CTC_Interface : CTC_Value, $1, $2->packageNamespace, $2->name, shared_ptr<CTypeNameList>($3.templateTypeNames), $3.isOption); delete $2; }
					| func_type											{ $$ = $1; }
					;

arg_mode			: /* Blank! */									{ $$ = CTM_Undefined; }
					| TLOCAL 										{ $$ = CTM_Local; }
					| TSTACK 										{ $$ = CTM_Stack; }
					| THEAP 										{ $$ = CTM_Heap; }
					| TWEAK 										{ $$ = CTM_Weak; }
					;

return_type			: arg_type											{ $$ = $1; }
					| TVOID												{ $$ = new CTypeName(CTC_Value, CTM_Stack, emptyNamespace, "void", false); }
					;

value_type			: TTYPEI32											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i32", false); }
					| TTYPEU32											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u32", false); }
					| TTYPEF32											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f32", false); }
					| TTYPEI64											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "i64", false); }
					| TTYPEU64											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "u64", false); }
					| TTYPEF64											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "f64", false); }
					| TTYPECHAR											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "char", false); }
					| TTYPEBOOL											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "bool", false); }
					| TTYPEPTR											{ $$ = new CTypeName(CTC_Value, CTM_Value, emptyNamespace, "ptr", false); }
					;

func_type			: arg_mode TLPAREN func_arg_type_list TRPAREN return_type { $$ = new CTypeName($1, shared_ptr<CTypeNameList>($3), shared_ptr<CTypeName>($5)); }
					;

func_arg_type 		: TCOLONEQUAL arg_type 							{ $$ = $2; $$->mutability = CTI_Mutable; }
					| TCOLON arg_type 								{ $$ = $2; $$->mutability = CTI_Immutable; }
					;

func_arg_type_list	: /* Blank! */									{ $$ = new CTypeNameList(); }
					| func_arg_type 								{ $$ = new CTypeNameList(); $$->push_back(shared_ptr<CTypeName>($1)); }
					| func_arg_type_list TCOMMA func_arg_type 		{ $1->push_back(shared_ptr<CTypeName>($3)); }
					;

temp_block_optional : /* Blank! */									{ $$ = nullptr; }
					| temp_block									{ $$ = $1; }
					;

namespace_hash		: namespace_dot namespace_last               	{ $$ = $2; $$->packageNamespace = *$1; delete $1; }
					| namespace_last								{ $$ = $1; }
					;

namespace_dot		: namespace_ident               				{ $$ = new vector<string>(); $$->push_back(*$1); delete $1; }
					| namespace_ident namespace_dot					{ $$ = $2; $$->push_back(*$1); delete $1; }
					;

namespace_ident     : TIDENTIFIER TDOT 								{ $$ = $1; }
					;

namespace_last      : THASH TIDENTIFIER								{ $$ = new CTypeNameParts(); $$->isHash = true;  $$->name = *$2; delete $2; }
					| TIDENTIFIER									{ $$ = new CTypeNameParts(); $$->isHash = false; $$->name = *$1; delete $1; }
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