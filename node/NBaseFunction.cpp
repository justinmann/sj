#include "Node.h"

void CBaseFunction::setHasThis() {
    assert(name != "global");
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
    
    // Force parent to have a "this" struct
    parent.lock()->setHasThis();    
    if (!hasParent) {
        hasParent = true;
    }
}
