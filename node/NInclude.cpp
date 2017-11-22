#include "Node.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

void NInclude::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    if (thisFunction->name != "global") {
        compiler->addError(loc, CErrorCode::IncludeOnlyInGlobal, "can only use include in the global scope");
    }
    
    auto path = (fs::path(*loc.fileName).remove_filename() / fs::path(fileName)).lexically_normal();
    compiler->includeFile(path.string());
}

shared_ptr<CVar> NInclude::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    return nullptr;
}
