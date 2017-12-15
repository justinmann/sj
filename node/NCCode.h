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
    NCC_TYPEDEF,
    NCC_FUNCTION,
    NCC_VAR
};

class CCCodeVar : public CVar {
public:
    CCCodeVar(CLoc loc, shared_ptr<CScope> scope, NCCodeType codeType, vector<string>& lines, shared_ptr<CType> returnType) : CVar(loc, scope), codeType(codeType), lines(lines), returnType(returnType) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    NCCodeType codeType;
    vector<string> lines;
    shared_ptr<CType> returnType;
}; 

class NCCode : public NBase {
public:
    NCCode(CLoc loc, NCCodeType codeType, const char* line) : NBase(NodeType_Code, loc), codeType(codeType) { 
        lines.push_back(line);
    }
    void defineImpl(Compiler* compiler, vector<vector<string>>& namespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    void addToStruct(Compiler* compiler, shared_ptr<CScope> scope, vector<string>& lines);

    vector<string> lines;

private:
    NCCodeType codeType;
};

#endif /* NCCode_h */
