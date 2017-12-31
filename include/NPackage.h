//
//  NPackage.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NPackage_h
#define NPackage_h

class NPackage : public NBase {
public:
    NPackage(CLoc loc, vector<string> packageNamespace, shared_ptr<NBase> node) : NBase(NodeType_Package, loc), packageNamespace(packageNamespace), node(node) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode);
    
private:
    vector<string> packageNamespace;
    shared_ptr<NBase> node;
};

#endif /* NPackage_h */
