#include "Node.h"

void CBaseFunction::setHasRefCount() {
    hasRefCount = true;
}

bool CBaseFunction::getHasParent(Compiler* compiler, CResult& result) {
    getThisTypes(compiler, result);
    return hasParent;
}

void CBaseFunction::setHasParent(Compiler* compiler, CResult& result) {
    if (parent.expired()) {
        return;
    }
    
    if (parent.lock()->getThisTypes(compiler, result) == nullptr) {
        return;
    }
    
    // Force parent to have a "this" struct
    parent.lock()->setHasRefCount();
    
    if (!hasParent) {
        getThisTypes(compiler, result);
        hasParent = true;
        
        for (auto it : delegateHasParent) {
            it(compiler, result);
        }
    }
}

void CBaseFunction::onHasParent(std::function<void(Compiler*, CResult&)> notify) {
    delegateHasParent.push_back(notify);
}
