#include "../node/Node.h"

ReturnValue::ReturnValue(shared_ptr<CType> type_, bool isHeap_, ReturnValueRelease release_, string name_) : type(type_), typeName(type_->nameRef), isHeap(isHeap_), release(release_), name(name_) {}
ReturnValue::ReturnValue(string typeName_, string name_) : type(nullptr), typeName(typeName_), isHeap(false), release(RVR_Ignore), name(name_) {}

void TrBlock::writeBodyToStream(ostream& stream, int level) {
	for (auto variable : variables)
	{
        addSpacing(stream, level);
        stream << variable.second->typeName << " " << variable.first << ";\n";
	}

    if (variables.size() > 0) {
        stream << "\n";
    }

	for (auto statement : statements)
	{
        if (statement.block != nullptr) {
            addSpacing(stream, level);
            stream << statement.line << " {\n";
            
            statement.block->writeBodyToStream(stream, level + 1);

            if (statement.elseBlock != nullptr) {
                addSpacing(stream, level);
                stream << "} else {\n";
                statement.elseBlock->writeBodyToStream(stream, level + 1);
            }

            addSpacing(stream, level);
            stream << "}\n";
        } else if (statement.line.size() > 0) {
            addSpacing(stream, level);
            stream << statement.line << ";\n";
        }
	}

    if (variables.size() > 0) {
        stream << "\n";
    }

    for (auto variable : variables)
    {
        variable.second->writeReleaseToStream(stream, level);
    }

    if (variables.size() > 0) {
        stream << "\n";
    }

    if (returnLine.size() > 0) {
        addSpacing(stream, level);
        stream << "return " << returnLine << ";\n";
    }
}

shared_ptr<ReturnValue> TrBlock::getVariable(string name) {
    auto var = variables.find(name);
    if (var == variables.end()) {
        if (parent != nullptr) {
            return parent->getVariable(name);
        }
        return nullptr;
    }
    return var->second;
}

shared_ptr<ReturnValue> TrBlock::createVariable(string name, shared_ptr<CType> type, bool isHeap, ReturnValueRelease release) {
    assert(getVariable(name) == nullptr);
    auto var = make_shared<ReturnValue>(type, isHeap, release, name);
    variables[name] = var;
    return var;
}

shared_ptr<ReturnValue> TrBlock::createTempVariable(string prefix, shared_ptr<CType> type, bool isHeap, ReturnValueRelease release) {
    auto nextIndex = ++varNames[prefix];
    stringstream varStream;
    varStream << prefix << nextIndex;
    auto varStr = varStream.str();
    auto var = make_shared<ReturnValue>(type, isHeap, release, varStr);
    variables[varStr] = var;
    return var;
}

shared_ptr<ReturnValue> TrBlock::createTempVariable(string prefix, string typeName) {
    auto nextIndex = ++varNames[prefix];
    stringstream varStream;
    varStream << prefix << nextIndex;
    auto varStr = varStream.str();
    auto var = make_shared<ReturnValue>(typeName, varStr);
    variables[varStr] = var;
    return var;
}

void TrBlock::resetVarNames() {
    varNames.clear();
}

void TrBlock::addSpacing(ostream& stream, int level) {
    for (auto i = 0; i < level; i++) {
        stream << "    ";
    }
}

map<string, int> TrBlock::varNames;

void ReturnValue::writeReleaseToStream(ostream& stream, int level) {
    if (release == RVR_Ignore)
        return;

    assert(release == RVR_MustRetain);

    if (!type || type->parent.expired())
        return;

    if (!isHeap) {
        TrBlock::addSpacing(stream, level);
        stream << type->parent.lock()->getCDestroyFunctionName() << "(" << name << ");\n";
    }
    else if (release == RVR_MustRetain) {
        TrBlock::addSpacing(stream, level);
        stream << name << "->_refCount--;\n";
        TrBlock::addSpacing(stream, level);
        stream << "if (" << name << "->_refCount == 0) {\n";
        if (!type->parent.expired()) {
            TrBlock::addSpacing(stream, level + 1);
            stream << type->parent.lock()->getCDestroyFunctionName() << "(" << name << ");\n";
        }
        TrBlock::addSpacing(stream, level + 1);
        stream << "free(" << name << ");\n";
        TrBlock::addSpacing(stream, level);
        stream << "}\n";
    }
}

void ReturnValue::addReleaseToStatements(TrBlock* block, string name, shared_ptr<CType> type) {
    assert(!type->parent.expired());

    stringstream lineStream;
    lineStream << name << "->_refCount--";
    block->statements.push_back(lineStream.str());

    auto ifBlock = make_shared<TrBlock>();
    stringstream ifStream;
    ifStream << "if (" << name << "->_refCount == 0)";
    block->statements.push_back(TrStatement(ifStream.str(), ifBlock));

    stringstream destroyStream;
    destroyStream << type->parent.lock()->getCDestroyFunctionName() << "(" << name << ")";
    ifBlock->statements.push_back(destroyStream.str());

    stringstream freeStream;
    freeStream << "free(" << name << ")";
    ifBlock->statements.push_back(freeStream.str());
}

