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

    bool previousLineBlock = false;
	for (auto statement : statements)
	{
        if (previousLineBlock) {
            stream << "\n";
        }

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
            previousLineBlock = true;
        } else if (statement.line.size() > 0) {
            addSpacing(stream, level);
            stream << statement.line << ";\n";
        }
	}

    stringstream varStream;
    for (auto variable : variables)
    {
        variable.second->writeReleaseToStream(this, varStream, level);
    }
    auto varString = varStream.str();
    if (varString.size() > 0) {
        stream << "\n" << varString;
    }

    if (returnLine.size() > 0) {
        stream << "\n";
        addSpacing(stream, level);
        stream << "*_return = " << returnLine << ";\n";
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
    auto varStr = nextVarName(prefix);
    auto var = make_shared<ReturnValue>(type, isHeap, release, varStr);
    variables[varStr] = var;
    return var;
}

shared_ptr<ReturnValue> TrBlock::createTempVariable(string prefix, string typeName) {
    auto varStr = nextVarName(prefix);
    auto var = make_shared<ReturnValue>(typeName, varStr);
    variables[varStr] = var;
    return var;
}

string TrBlock::nextVarName(string prefix) {
    auto nextIndex = ++varNames[prefix];
    stringstream varStream;
    varStream << prefix << nextIndex;
    return varStream.str();
}

void TrBlock::resetVarNames() {
    varNames.clear();
}

void TrBlock::addSpacing(ostream& stream, int level) {
    for (auto i = 0; i < level; i++) {
        stream << "    ";
    }
}

string TrBlock::getFunctionName() {
    if (definition.size() > 0)
        return definition;
    if (parent) {
        return parent->getFunctionName();
    }
    return "";
}

map<string, int> TrBlock::varNames;

bool ReturnValue::writeReleaseToStream(TrBlock* block, ostream& stream, int level) {
    if (release == RVR_Ignore || release == RVR_MustRelease)
        return false;

    if (!type || type->parent.expired())
        return false;

    if (!isHeap) {
        TrBlock::addSpacing(stream, level);
        stream << type->parent.lock()->getCDestroyFunctionName() << "(" << name << ");\n";
    }
    else if (release == RVR_MustRetain) {
        TrBlock::addSpacing(stream, level);
        stream << name << "->_refCount--;\n";

#ifdef DEBUG_ALLOC
        TrBlock::addSpacing(stream, level);
        stream << "printf(\"RELEASE\\t" << type->nameRef << "\\t%0x\\t" << (block ? block->getFunctionName() : "") << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);\n";
#endif

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

    return true;
}

void ReturnValue::addReleaseToStatements(TrBlock* block, string name, shared_ptr<CType> type) {
    assert(!type->parent.expired());

    stringstream lineStream;
    lineStream << name << "->_refCount--";
    block->statements.push_back(lineStream.str());

#ifdef DEBUG_ALLOC
    stringstream logStream;
    logStream << "printf(\"RELEASE\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
    block->statements.push_back(logStream.str());
#endif

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

void ReturnValue::addRetainToStatements(TrBlock* block, string name, shared_ptr<CType> type) {
    assert(!type->parent.expired());

    stringstream lineStream;
    lineStream << name << "->_refCount++";
    block->statements.push_back(lineStream.str());

#ifdef DEBUG_ALLOC
    stringstream logStream;
    logStream << "printf(\"RETAIN\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
    block->statements.push_back(logStream.str());
#endif
}

void ReturnValue::addInitToStatements(TrBlock* block, string name, shared_ptr<CType> type) {
    assert(!type->parent.expired());

    stringstream lineStream;
    lineStream << name << "->_refCount = 1";
    block->statements.push_back(lineStream.str());

#ifdef DEBUG_ALLOC
    stringstream logStream;
    logStream << "printf(\"RETAIN\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
    block->statements.push_back(logStream.str());
#endif
}
