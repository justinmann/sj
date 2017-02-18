//
//  NInterface.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NInterface_h
#define NInterface_h

class NInterface : public NBase {
public:
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<CInterfaceMethodList> methodList;

    NInterface(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CInterfaceMethodList> methodList) : NBase(NodeType_Interface, loc), name(name), templateTypeNames(templateTypeNames), methodList(methodList) { }
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level);

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {}
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) { return nullptr; }
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) { return 0; } 
    virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);
};

#endif /* NInterface_h */
