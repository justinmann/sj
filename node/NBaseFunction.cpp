#include "Node.h"

void CBaseFunction::setHasThis() {
    // TODO: assert(name != "global");
    hasThis = true;
}

bool CBaseFunction::getHasParent(Compiler* compiler) {
    getThisTypes(compiler);
    return hasParent;
}

void CBaseFunction::setHasParent(Compiler* compiler) {
    assert(name != "global");
    if (parent.expired()) {
        return;
    }
    
    if (parent.lock()->getThisTypes(compiler) == nullptr) {
        return;
    }
    
    // Force parent to have a "this" struct
    parent.lock()->setHasThis();
    
    if (!hasParent) {
        getThisTypes(compiler);
        hasParent = true;
        
        for (auto it : delegateHasParent) {
            it(compiler);
        }
    }
}

void CBaseFunction::onHasParent(std::function<void(Compiler*)> notify) {
    delegateHasParent.push_back(notify);
}
