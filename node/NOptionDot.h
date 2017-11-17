//
//  NOptionDot.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NOptionDot_h
#define NOptionDot_h

class NOptionDot : public NVariableBase {
public:
    NOptionDot(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NVariableBase> right) : NVariableBase(NodeType_OptionDot, loc), left(left), right(right) {}

    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode);

private:
    shared_ptr<NVariableBase> left;
    shared_ptr<NVariableBase> right;
};

#endif /* NOptionDot_h */
