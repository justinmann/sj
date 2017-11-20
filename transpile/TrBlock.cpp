#include "../node/Node.h"

TrValue::TrValue(shared_ptr<CType> type_, string name_) : type(type_), typeName(type_->nameRef), name(name_) {}

void TrBlock::writeToStream(ostream& stream, int level) {
    writeStackValuesToStream(stream, level);
    writeVariablesToStream(stream,level);
    writeBodyToStream(stream, level);
    writeVariablesReleaseToStream(stream, level);
    writeStackValuesReleaseToStream(stream, level);
    writeReturnToStream(stream, level);
}

void TrBlock::writeStackValuesToStream(ostream& stream, int level) {
    for (auto stackValue : stackValues)
    {
        addSpacing(stream, level);
        stream << stackValue.second->nameValue << " " << stackValue.first << ";\n";
    }
}

void TrBlock::writeVariablesToStream(ostream& stream, int level) {
    for (auto variable : variables)
    {
        addSpacing(stream, level);
        if (variable.second->type) {
            switch (variable.second->type->typeMode) {
            case CTM_Local:
                stream << variable.second->type->nameRef;
                break;
            case CTM_Stack:
                stream << variable.second->type->nameValue;
                break;
            case CTM_Heap:
                stream << variable.second->type->nameRef;
                break;
            case CTM_Value:
                stream << variable.second->type->nameValue;
                break;
            default:
                assert(false);
                break;
            }
        }
        else {
            stream << variable.second->typeName;
        }
        stream << " " << variable.first << ";\n";
    }

    if (variables.size() > 0) {
        stream << "\n";
    }
}

void TrBlock::writeBodyToStream(ostream& stream, int level) {
    bool previousLineBlock = false;
    for (auto statement : statements)
    {
        if (previousLineBlock) {
            previousLineBlock = false;
            stream << "\n";
        }

        if (statement.block != nullptr) {
            addSpacing(stream, level);
            stream << statement.line << " {\n";

            statement.block->writeToStream(stream, level + 1);

            if (statement.elseBlock != nullptr) {
                addSpacing(stream, level);
                stream << "} else {\n";
                statement.elseBlock->writeToStream(stream, level + 1);
            }

            addSpacing(stream, level);
            stream << "}\n";
            previousLineBlock = true;
        }
        else if (statement.line.size() > 0) {
            addSpacing(stream, level);
            stream << statement.line << ";\n";
        }
    }
}

void TrBlock::writeVariablesReleaseToStream(ostream& stream, int level) {
    stringstream varStream;
    for (auto variable : variables)
    {
        variable.second->writeReleaseToStream(this, varStream, level);
    }
    auto varString = varStream.str();
    if (varString.size() > 0) {
        stream << "\n" << varString;
    }
}

void TrBlock::writeStackValuesReleaseToStream(ostream& stream, int level) {
    for (auto stackValue : stackValues)
    {
        if (!stackValue.second->parent.expired()) {
            addSpacing(stream, level);
            stream << stackValue.second->parent.lock()->getCDestroyFunctionName() << "(&" << stackValue.first << ");\n";
        }
    }
}

void TrBlock::writeReturnToStream(ostream& stream, int level) {
    if (returnLine.size() > 0) {
        stream << "\n";
        addSpacing(stream, level);
        stream << "*_return = " << returnLine << ";\n";
    }
}

shared_ptr<TrValue> TrBlock::getVariable(string name) {
    auto var = variables.find(name);
    if (var == variables.end()) {
        if (parent != nullptr) {
            return parent->getVariable(name);
        }
        return nullptr;
    }
    return var->second;
}

shared_ptr<TrValue> TrBlock::createVariable(shared_ptr<CType> type, string name) {
    assert(getVariable(name) == nullptr);
    auto var = make_shared<TrValue>(type, name);
    variables[name] = var;
    return var;
}

shared_ptr<TrValue> TrBlock::createTempVariable(shared_ptr<CType> type, string prefix) {
    auto varStr = nextVarName(prefix);
    auto var = make_shared<TrValue>(type, varStr);
    variables[varStr] = var;
    return var;
}

string TrBlock::createStackValue(string prefix, shared_ptr<CType> type) {
    auto varStr = nextVarName(prefix);
    stackValues[varStr] = type;
    return varStr;
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

bool TrValue::writeReleaseToStream(TrBlock* block, ostream& stream, int level) {
    if (!type || type->parent.expired())
        return false;

    if (type->typeMode == CTM_Heap) {
        if (type->isOption) {
            TrBlock::addSpacing(stream, level);
            stream << "if (" << name << " != 0) {\n";
            level++;
        }

        TrBlock::addSpacing(stream, level);
        stream << name << "->_refCount--;\n";

#ifdef DEBUG_ALLOC
        TrBlock::addSpacing(stream, level);
        stream << "printf(\"RELEASE\\t" << type->nameRef << "\\t%0x\\t" << (block ? block->getFunctionName() : "") << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);\n";
#endif

        TrBlock::addSpacing(stream, level);
        stream << "if (" << name << "->_refCount <= 0) {\n";
        TrBlock::addSpacing(stream, level + 1);
        stream << type->parent.lock()->getCDestroyFunctionName() << "(" << convertToLocalName(type, name) << ");\n";

        TrBlock::addSpacing(stream, level + 1);
        stream << "free(" << name << ");\n";

        TrBlock::addSpacing(stream, level);
        stream << "}\n";

        if (type->isOption) {
            level--;
            TrBlock::addSpacing(stream, level);
            stream << "}\n";
        }
    }

    return true;
}

void TrValue::addReleaseToStatements(TrBlock* block) {
    if (type->typeMode == CTM_Heap) {
        assert(!type->parent.expired());
        shared_ptr<TrBlock> ifNullBlock;
        auto innerBlock = block;
        if (type->isOption) {
            ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << name << " != 0)";
            block->statements.push_back(TrStatement(ifStream.str(), ifNullBlock));

            innerBlock = ifNullBlock.get();
        }

        stringstream lineStream;
        lineStream << name << "->_refCount--";
        innerBlock->statements.push_back(lineStream.str());

#ifdef DEBUG_ALLOC
        stringstream logStream;
        logStream << "printf(\"RELEASE\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
        innerBlock->statements.push_back(logStream.str());
#endif

        auto ifBlock = make_shared<TrBlock>();
        stringstream ifStream;
        ifStream << "if (" << name << "->_refCount <= 0)";
        innerBlock->statements.push_back(TrStatement(ifStream.str(), ifBlock));

        stringstream destroyStream;
        destroyStream << type->parent.lock()->getCDestroyFunctionName() << "(" << convertToLocalName(type, name) << ")";
        ifBlock->statements.push_back(destroyStream.str());

        stringstream freeStream;
        freeStream << "free(" << name << ")";
        ifBlock->statements.push_back(freeStream.str());
    }
}

void TrValue::addRetainToStatements(TrBlock* block) {
    if (type->typeMode == CTM_Heap) {
        assert(!type->parent.expired());

        shared_ptr<TrBlock> ifNullBlock;
        auto innerBlock = block;
        if (type->isOption) {
            ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << name << " != 0)";
            block->statements.push_back(TrStatement(ifStream.str(), ifNullBlock));

            innerBlock = ifNullBlock.get();
        }

        stringstream lineStream;
        lineStream << name << "->_refCount++";
        innerBlock->statements.push_back(lineStream.str());

#ifdef DEBUG_ALLOC
        stringstream logStream;
        logStream << "printf(\"RETAIN\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
        innerBlock->statements.push_back(logStream.str());
#endif
    }
}
    
void TrValue::addInitToStatements(TrBlock* block) {
    if (type->typeMode == CTM_Value) {
        return;
    }
    else if (type->typeMode == CTM_Heap) {
        assert(!type->parent.expired());

        if (type->isOption) {
            stringstream initLine;
            initLine << name << " = 0";
            block->statements.push_back(TrStatement(initLine.str()));
        }
        else {
            string structName = type->parent.lock()->getCStructName(type->typeMode);
            stringstream initLine;
            initLine << name << " = (" << structName << "*)malloc(sizeof(" << structName << "))";
            block->statements.push_back(TrStatement(initLine.str()));

            stringstream lineStream;
            lineStream << name << "->_refCount = 1";
            block->statements.push_back(lineStream.str());

#ifdef DEBUG_ALLOC
            stringstream logStream;
            logStream << "printf(\"RETAIN\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
            block->statements.push_back(logStream.str());
#endif
        }
    }
    else if (type->typeMode == CTM_Stack) {
        assert(!type->parent.expired());
        assert(!type->isOption);
    }
    else {
        assert(false);
    }
}

string TrValue::getDotName(string rightName) {
    if (type->typeMode == CTM_Stack) {
        return name + "." + rightName;
    }
    else {
        return name + "->" + rightName;
    }
}

string TrValue::getPointerName() {
    if (type->typeMode == CTM_Stack) {
        return "&" + name;
    }
    else {
        return name;
    }
}

string TrValue::convertToLocalName(shared_ptr<CType> from, string name) {
    switch (from->typeMode) {
    case CTM_Local:
        return name;
    case CTM_Stack:
        return "&" + name;
    case CTM_Heap:
        return "(" + from->parent.lock()->getCStructName(CTM_Stack) + "*)(((char*)" + name + ") + sizeof(int))";
    default:
        assert(false);
        return "";
    }
}


void TrStoreValue::setValue(Compiler* compiler, CResult& result, CLoc& loc, TrBlock* block, shared_ptr<TrValue> rightValue) {
    assert(!hasSetValue);
    hasSetValue = true;
    TrValue leftValue(type, name);
    if (op == ASSIGN_Immutable || op == ASSIGN_Mutable) {
        if (!isFirstAssignment) {
            leftValue.addReleaseToStatements(block);
        }

        stringstream lineStream;
        lineStream << name << " = ";
        if (type->typeMode == CTM_Stack || type->typeMode == CTM_Local) {
            lineStream << TrValue::convertToLocalName(rightValue->type, rightValue->name);
        }
        else {
            lineStream << rightValue->name;
        }
        block->statements.push_back(lineStream.str());

        leftValue.addRetainToStatements(block);
    }
    else {
        if (isFirstAssignment) {
            leftValue.addInitToStatements(block);
        }
        else {
            leftValue.addReleaseToStatements(block);
        }

        stringstream lineStream;
        lineStream << type->parent.lock()->getCCopyFunctionName() << "(" << TrValue::convertToLocalName(type, name) << ", " << TrValue::convertToLocalName(rightValue->type, rightValue->name) << ")";
        block->statements.push_back(lineStream.str());
    }
}
