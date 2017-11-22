#include "../node/Node.h"

#define SKIP_FREE

void TrBlock::writeToStream(ostream& stream, int level) {
    writeVariablesToStream(stream,level);
    writeBodyToStream(stream, level);
    writeVariablesReleaseToStream(stream, level);
    writeReturnToStream(stream, level);
}

void TrBlock::writeVariablesToStream(ostream& stream, int level) {
    for (auto variable : variables)
    {
        addSpacing(stream, level);
        switch (variable.second->type->typeMode) {
        case CTM_Local:
            stream << variable.second->type->cname;
            break;
        case CTM_Stack:
            stream << variable.second->type->cname;
            break;
        case CTM_Heap:
            stream << variable.second->type->cname;
            break;
        case CTM_Value:
            stream << variable.second->type->cname;
            break;
        default:
            assert(false);
            break;
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
            stream << statement.line;
            if (statement.line.back() != ':') {
                stream << ";";
            }
            stream << "\n";
        }
    }
}

void TrBlock::writeVariablesReleaseToStream(ostream& stream, int level) {
    stringstream varStream;
    for (auto variable : variables)
    {
        variable.second->writeReleaseToStream(this, varStream, level);
    }

    for (auto variable : variables)
    {
        if (variable.second->type->typeMode == CTM_Stack) {
            addSpacing(varStream, level);
            varStream << variable.second->type->parent.lock()->getCDestroyFunctionName() << "(&" << variable.first << ");\n";
        }
    }

    auto varString = varStream.str();
    if (varString.size() > 0) {
        stream << "\n" << varString;
    }
}

void TrBlock::writeReturnToStream(ostream& stream, int level) {
    if (returnLine.size() > 0) {
        stream << "\n";
        addSpacing(stream, level);
        stream << "return " << returnLine << ";\n";
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

shared_ptr<TrValue> TrBlock::createVariable(shared_ptr<CScope> scope, shared_ptr<CType> type, string name) {
    assert(getVariable(name) == nullptr);
    auto var = make_shared<TrValue>(scope, type, name);
    variables[name] = var;
    return var;
}

shared_ptr<TrValue> TrBlock::createTempVariable(shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix) {
    auto varStr = nextVarName(prefix);
    auto var = make_shared<TrValue>(scope, type, varStr);
    variables[varStr] = var;
    return var;
}

shared_ptr<TrStoreValue> TrBlock::createTempStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix) {
    auto varStr = nextVarName("sjt_" + prefix);
    auto var = make_shared<TrStoreValue>(loc, scope, type, varStr, ASSIGN_Immutable, true);
    variables[varStr] = make_shared<TrValue>(scope, type, varStr);
    return var;
}

shared_ptr<TrStoreValue> TrBlock::createVoidStoreVariable(CLoc loc) {
    return make_shared<TrStoreValue>(loc, nullptr, nullptr, "", ASSIGN_Immutable, true);
}

shared_ptr<TrStoreValue> TrBlock::createReturnStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type) {
    auto returnStoreValue = make_shared<TrStoreValue>(loc, scope, type->getLocalType(), type->typeMode == CTM_Stack ? "_return" : "(*_return)", ASSIGN_Immutable, true);
    returnStoreValue->isReturnValue = true;
    return returnStoreValue;
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

#ifndef SKIP_FREE
        TrBlock::addSpacing(stream, level + 1);
        stream << "free(" << name << ");\n";
#endif
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

#ifndef SKIP_FREE
        stringstream freeStream;
        freeStream << "free(" << name << ")";
        ifBlock->statements.push_back(freeStream.str());
#endif // !SKIP_FREE
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
    else if (type->typeMode == CTM_Local) {
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
        if (from->category == CTC_Interface) {
            return name;
        }
        else {
            return "(" + from->parent.lock()->getCStructName(CTM_Stack) + "*)(((char*)" + name + ") + sizeof(int))";
        }
    default:
        assert(false);
        return "";
    }
}

void TrStoreValue::retainValue(Compiler* compiler, TrBlock* block, shared_ptr<TrValue> rightValue) {
    assert(!hasSetValue);
    hasSetValue = true;

    value = rightValue;

    if (!type) {
        // This is a void store value, so ignore all input
        return;
    }

    if (!CType::isSameExceptMode(type, rightValue->type)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' does not match left type '%s'", rightValue->type->name.c_str(), type->name.c_str());
        return;
    }

    if (type->typeMode != CTM_Local && type->typeMode != rightValue->type->typeMode && op != ASSIGN_MutableCopy && op != ASSIGN_ImmutableCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s' without using a :copy or =copy assignment", rightValue->type->name.c_str(), type->name.c_str());
        return;
    }


    if (type->typeMode == CTM_Stack && rightValue->type->typeMode == CTM_Stack && op != ASSIGN_MutableCopy && op != ASSIGN_ImmutableCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "must use a :copy or =copy assignment when assigning a stack variable to a stack variable");
        return;
    }

    TrValue leftValue(scope, type, name);
    if (op == ASSIGN_Immutable || op == ASSIGN_Mutable) {
        if (!isFirstAssignment) {
            leftValue.addReleaseToStatements(block);
        }

        if (isReturnValue) {
            // TODO: assert(rightValue->type->typeMode == CTM_Heap || rightValue->type->typeMode == CTM_Value);
            block->returnLine = rightValue->name;
            rightValue->addRetainToStatements(block);
        }
        else {
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
    }
    else {
        if (type->typeMode == CTM_Value) {
            assert(rightValue->type->typeMode == CTM_Value);
            stringstream lineStream;
            lineStream << name << " = " << rightValue->name;
            block->statements.push_back(lineStream.str());
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
}

void TrStoreValue::takeOverValue(Compiler* compiler, TrBlock* block, shared_ptr<TrValue> rightValue) {
    assert(!hasSetValue);
    hasSetValue = true;

    value = rightValue;

    if (!type) {
        // If this value is going nowhere, then release it since we are taking ownership
        rightValue->addReleaseToStatements(block);
        return;
    }

    if (!CType::isSameExceptMode(type, rightValue->type)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' does not match left type '%s'", rightValue->type->name.c_str(), type->name.c_str());
        return;
    }

    if (type->typeMode != CTM_Local && type->typeMode != rightValue->type->typeMode && op != ASSIGN_MutableCopy && op != ASSIGN_ImmutableCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s' without using a :copy or =copy assignment", rightValue->type->name.c_str(), type->name.c_str());
        return;
    }


    if (type->typeMode == CTM_Stack && rightValue->type->typeMode == CTM_Stack && op != ASSIGN_MutableCopy && op != ASSIGN_ImmutableCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "must use a :copy or =copy assignment when assigning a stack variable to a stack variable");
        return;
    }

    TrValue leftValue(scope, type, name);
    if (op == ASSIGN_Immutable || op == ASSIGN_Mutable) {
        if (!isFirstAssignment) {
            leftValue.addReleaseToStatements(block);
        }

        if (isReturnValue) {
            // TODO: assert(rightValue->type->typeMode == CTM_Heap || rightValue->type->typeMode == CTM_Value);
            block->returnLine = rightValue->name;
        }
        else {
            stringstream lineStream;
            lineStream << name << " = ";
            if (type->typeMode == CTM_Stack || type->typeMode == CTM_Local) {
                lineStream << TrValue::convertToLocalName(rightValue->type, rightValue->name);
            }
            else {
                lineStream << rightValue->name;
            }

            block->statements.push_back(lineStream.str());
        }
    }
    else {
        if (type->typeMode == CTM_Value) {
            assert(rightValue->type->typeMode == CTM_Value);
            stringstream lineStream;
            lineStream << name << " = " << rightValue->name;
            block->statements.push_back(lineStream.str());
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
}

shared_ptr<TrValue> TrStoreValue::getValue() {
    assert(hasSetValue);
    return make_shared<TrValue>(scope, type, name);
}
