//
//  NGetOrElse.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NGetOrElse_h
#define NGetOrElse_h

class NGetOrElse : public NVariableBase {
public:
    NGetOrElse(CLoc& loc, shared_ptr<NVariableBase> left, shared_ptr<NVariableBase> right) : NVariableBase(NodeType_GetOrElse, loc), left(left), right(right) {}

    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NVariableBase> left;
    shared_ptr<NVariableBase> right;
};

#endif /* NGetOrElse_h */
