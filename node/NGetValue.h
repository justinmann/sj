//
//  NGetValue.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NGetValue_h
#define NGetValue_h

class NGetValue : public NVariableBase {
public:
    NGetValue(CLoc& loc, shared_ptr<NBase> node, bool isProtectedWithEmptyCheck) : NVariableBase(NodeType_GetValue, loc), node(node), isProtectedWithEmptyCheck(isProtectedWithEmptyCheck) {}

    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NBase> node;
    bool isProtectedWithEmptyCheck;
};

#endif /* NGetValue_h */
