//
//  NLibrary.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NLibrary_h
#define NLibrary_h

class NLibrary : public NBase {
public:
    string fileName;
    
    NLibrary(CLoc loc, const char* fileName) : NBase(NodeType_Library, loc), fileName(fileName) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode);
};

#endif /* NLibrary_h */