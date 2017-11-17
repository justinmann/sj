//
//  NString.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NString_h
#define NString_h

class NString : public NVariableBase {
public:
    NString(CLoc loc, const string& str);

    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode);

private:
    string str;
    string varName;
};

#endif /* NString_h */
