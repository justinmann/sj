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
    NCC_STRUCT,
    NCC_INCLUDE,
    NCC_FUNCTION
};

class CCCodeVar : public CVar {
public:
    CCCodeVar(CLoc loc, shared_ptr<CScope> scope, NCCodeType codeType, string code, shared_ptr<CType> returnType) : CVar(loc, scope), codeType(codeType), code(code), returnType(returnType) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

private:
    NCCodeType codeType;
    string code;
    shared_ptr<CType> returnType;
}; 

class NCCode : public NBase {
public:
    NCCode(CLoc loc, NCCodeType codeType, const char* code_) : NBase(NodeType_Integer, loc), codeType(codeType), code(code_) { }
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);

private:
    NCCodeType codeType;
    string code;
};

#endif /* NCCode_h */
