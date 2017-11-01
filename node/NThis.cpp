#include "Node.h"

NThis::NThis(CLoc loc) : NVariableBase(NodeType_This, loc) { }

shared_ptr<CType> NThis::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	trLine << "_this";
	return thisVar->getType(compiler, result);
}

shared_ptr<CVar> NThis::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    
    thisVar->parent.lock()->setHasRefCount();    
    return thisVar;
}
