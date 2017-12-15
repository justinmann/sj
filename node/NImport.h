//
//  NImport.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NImport_h
#define NImport_h

class CImportVar : public CVar {
public:
    CImportVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> var, shared_ptr<ImportScope> functionBlock) : CVar(loc, scope), var(var), importScope(importScope) { assert(var); }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CVar> var;
    shared_ptr<ImportScope> importScope;
};

class NImport : public NBase {
public:
    NImport(CLoc loc, vector<pair<string, vector<string>>> importNamespaces, shared_ptr<NBase> node) : NBase(NodeType_Import, loc), importNamespaces(importNamespaces), node(node) { }
    void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    
private:
    vector<pair<string, vector<string>>> importNamespaces;
    shared_ptr<NBase> node;
};

#endif /* NImport_h */
