//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

Type* CArrayType::llvmAllocType(Compiler* compiler, CResult& result) {
    auto itemType = parent.lock()->templateTypes[0]->llvmRefType(compiler, result);
    return itemType->getPointerTo();
}

Type* CArrayType::llvmRefType(Compiler* compiler, CResult& result) {
    auto itemType = parent.lock()->templateTypes[0]->llvmRefType(compiler, result);
    return itemType->getPointerTo();
}

