//
//  NCCode.hpp
//  sj
//
//  Created by Mann, Justin on 11/2/17.
//  Copyright © 2017 Mann, Justin. All rights reserved.
//

#ifndef NCCode_h
#define NCCode_h

enum NCCodeType {
    NCC_BLOCK,
    NCC_DEFINE,
    NCC_FUNCTION
};

class CCCodeVar : public CVar {
public:
    CCCodeVar(CLoc loc, shared_ptr<CBaseFunction> scope, NCCodeType codeType, string code, vector<shared_ptr<CFunction>> functions, vector<string> includes) : CVar(loc, scope, "", false), codeType(codeType), code(code), functions(functions), includes(includes) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> thisValue);
    void transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, shared_ptr<ReturnValue> thisValue, AssignOp op, bool isFirstAssignment);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

private:
    NCCodeType codeType;
    string code;
    vector<shared_ptr<CFunction>> functions;
    vector<string> includes;
}; 

class NCCode : public NBase {
public:
    NCCode(CLoc loc, NCCodeType codeType, const char* code_) : NBase(NodeType_Integer, loc), codeType(codeType), code(code_) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode);

private:
    string expandMacro(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, string macro);

    map<CBaseFunction*, string> _final;
    map<CBaseFunction*, vector<shared_ptr<CFunction>>> _functions;
    vector<string> _includes;
    NCCodeType codeType;
    string code;
};

#endif /* NCCode_h */
