//
//  NFunctionDeclaration.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NFunctionDeclaration_h
#define NFunctionDeclaration_h

#include "NBlock.h"

class NFunctionDeclaration : public NBase {
public:
    const string type;
    const string name;
    const shared_ptr<NodeList> arguments;
    const shared_ptr<NBlock> block;
    
    NFunctionDeclaration(CLoc loc, const char* type, const char* name, shared_ptr<NodeList> arguments, shared_ptr<NBlock> block) : type(type), name(name), arguments(arguments), block(block), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
    Function* functionGen(Compiler* compiler) const;
};

#endif /* NFunctionDeclaration_h */
