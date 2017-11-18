#include "Node.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

void NInclude::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    if (thisFunction->name != "global") {
        result.addError(loc, CErrorCode::IncludeOnlyInGlobal, "can only use include in the global scope");
    }
    
    auto path = (fs::path(*loc.fileName).remove_filename() / fs::path(fileName)).lexically_normal();
    compiler->includeFile(result, path.string());
}

shared_ptr<CVar> NInclude::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    return nullptr;
}
