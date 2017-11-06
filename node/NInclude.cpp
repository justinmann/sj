#include "Node.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

void NInclude::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    if (thisFunction->name != "global") {
        result.addError(loc, CErrorCode::IncludeOnlyInGlobal, "can only use include in the global scope");
    }
    
    auto relativePath = fs::path(fileName);

    auto path = fs::path(*loc.fileName);
    path = path.remove_filename();
    path /= relativePath;
    auto t = path.lexically_normal();

    // TODO: allow a relative path combine for filename
    // fileName = path.append(fileName, *loc.fileName);
    compiler->includeFile(result, fileName);
}

shared_ptr<CVar> NInclude::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    return nullptr;
}

shared_ptr<CType> NInclude::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    return compiler->typeVoid;
}

//shared_ptr<ReturnValue> NInclude::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    return nullptr;
//}

void NInclude::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
}

shared_ptr<ReturnValue> NInclude::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
	return nullptr;
}
