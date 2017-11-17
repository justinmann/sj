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

class NCCode : public NBase {
public:
    NCCodeType codeType;
    string code;
    
    NCCode(CLoc loc, NCCodeType codeType, const char* code_) : NBase(NodeType_Integer, loc), codeType(codeType), code(code_) { }
    virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode);

private:
    string expandMacro(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, string macro);
    map<CBaseFunction*, string> _final;
    map<CBaseFunction*, vector<shared_ptr<CBaseFunction>>> _functions;
    vector<string> _includes;
};

#endif /* NCCode_h */
