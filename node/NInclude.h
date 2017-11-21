//
//  NInclude.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NInclude_h
#define NInclude_h

class NInclude : public NBase {
public:
    string fileName;
    
    NInclude(CLoc loc, const char* fileName) : NBase(NodeType_Include, loc), fileName(fileName) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode);
};

#endif /* NInclude_h */
