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
    NPackage(CLoc loc, vector<string> ns, shared_ptr<NBase> node) : NBase(NodeType_Package, loc), ns(ns), node(node) { }
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    
private:
    vector<string> ns;
    shared_ptr<NBase> node;
};

#endif /* NPackage_h */
