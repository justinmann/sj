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
        variable.second->writeReleaseToStream(varStream, level);
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
    auto var = getVariable(name);
    if (var) {
        assert(var->type == type);
    } else {
        var = make_shared<TrValue>(scope, type, name, false);
        variables[name] = var;
    }
    return var;
}

shared_ptr<TrValue> TrBlock::createTempVariable(shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix) {
    auto varStr = nextVarName(prefix);
    auto var = make_shared<TrValue>(scope, type, varStr, false);
    variables[varStr] = var;
    return var;
}

shared_ptr<TrStoreValue> TrBlock::createTempStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix) {
    auto varStr = nextVarName("sjt_" + prefix);
    auto var = make_shared<TrStoreValue>(loc, scope, type, varStr, AssignOp::immutableOp, true);
    variables[varStr] = make_shared<TrValue>(scope, type, varStr, false);
    return var;
}

shared_ptr<TrStoreValue> TrBlock::createVoidStoreVariable(CLoc loc, shared_ptr<CType> type) {
    return make_shared<TrStoreValue>(loc, type, true);
}

shared_ptr<TrStoreValue> TrBlock::createReturnStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type) {
    auto returnStoreValue = make_shared<TrStoreValue>(loc, scope, type, type->typeMode == CTM_Stack ? "_return" : "(*_return)", AssignOp::immutableOp, true);
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

void TrValue::writeReleaseToStream(ostream& stream, int level) {
    TrBlock block;
    addReleaseToStatements(&block);
    block.writeBodyToStream(stream, level);
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
        destroyStream << type->parent.lock()->getCDestroyFunctionName() << "(" << convertToLocalName(type, name, false) << ")";
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
    }
    else {
        assert(false);
    }
}

string TrValue::getDotName(string rightName) {
    if (!isReturnValue && type->typeMode == CTM_Stack) {
        return name + "." + rightName;
    }
    else {
        return name + "->" + rightName;
    }
}

string TrValue::getPointerName() {
    if (!isReturnValue && type->typeMode == CTM_Stack) {
        return "&" + name;
    }
    else {
        return name;
    }
}

string TrValue::convertToLocalName(CTypeMode typeMode, string name, bool isReturnValue) {
    switch (typeMode) {
    case CTM_Local:
        return name;
    case CTM_Stack:
        return isReturnValue ? name : "&" + name;
    case CTM_Heap:
        return "(void*)(((char*)" + name + ") + sizeof(intptr_t))";
    case CTM_Value:
        return name;
    default:
        assert(false);
        return "";
    }
}

string TrValue::convertToLocalName(shared_ptr<CType> from, string name, bool isReturnValue) {
    switch (from->typeMode) {
    case CTM_Local:
        return name;
    case CTM_Stack:
        return isReturnValue ? name : "&" + name;
    case CTM_Heap:
        if (from->category == CTC_Interface) {
            return name;
        }
        else {
            return "(" + from->parent.lock()->getCStructName(CTM_Stack) + "*)(((char*)" + name + ") + sizeof(intptr_t))";
        }
    case CTM_Value:
        return name;
    default:
        assert(false);
        return "";
    }
}

void TrStoreValue::retainValue(Compiler* compiler, CLoc loc, TrBlock* block, shared_ptr<TrValue> rightValue) {
    hasSetValue = true;

    value = rightValue;

    if (!type) {
        // This is a void store value, so ignore all input
        return;
    }

    if (!CType::isSameExceptMode(type, rightValue->type)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' does not match left type '%s'", rightValue->type->fullName.c_str(), type->fullName.c_str());
        return;
    }

    if (type->typeMode != CTM_Local && type->typeMode != rightValue->type->typeMode && !op.isCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s' without using a copy operator like 'a = copy b'", rightValue->type->fullName.c_str(), type->fullName.c_str());
        return;
    }

    if (isVoid) {
        return;
    }

    if (type->typeMode == CTM_Stack && rightValue->type->typeMode == CTM_Stack && !op.isCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "must use a copy operator like 'a = copy b' when assigning a stack variable to a stack variable");
        return;
    }

    TrValue leftValue(scope, type, name, isReturnValue);
    if (!op.isCopy) {
        if (!isFirstAssignment) {
            leftValue.addReleaseToStatements(block);
        }

        stringstream lineStream;
        lineStream << name << " = ";
        if (type->typeMode == CTM_Stack || type->typeMode == CTM_Local) {
            lineStream << TrValue::convertToLocalName(rightValue->type, rightValue->name, rightValue->isReturnValue);
        }
        else {
            lineStream << rightValue->name;
        }

        block->statements.push_back(lineStream.str());
        leftValue.addRetainToStatements(block);
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
            lineStream << type->parent.lock()->getCCopyFunctionName() << "(" << TrValue::convertToLocalName(type, name, isReturnValue) << ", " << TrValue::convertToLocalName(rightValue->type, rightValue->name, rightValue->isReturnValue) << ")";
            block->statements.push_back(lineStream.str());
        }
    }
}

void TrStoreValue::takeOverValue(Compiler* compiler, CLoc loc, TrBlock* block, shared_ptr<TrValue> rightValue) {
    hasSetValue = true;

    value = rightValue;

    if (!type) {
        // If this value is going nowhere, then release it since we are taking ownership
        rightValue->addReleaseToStatements(block);
        return;
    }

    if (!CType::isSameExceptMode(type, rightValue->type)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' does not match left type '%s'", rightValue->type->fullName.c_str(), type->fullName.c_str());
        return;
    }

    if (type->typeMode != CTM_Local && type->typeMode != rightValue->type->typeMode && !op.isCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s' without using copy operator like 'a = copy b'", rightValue->type->fullName.c_str(), type->fullName.c_str());
        return;
    }

    if (isVoid) {
        return;
    }

    if (type->typeMode == CTM_Stack && rightValue->type->typeMode == CTM_Stack && !op.isCopy) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "must use a copy operator like 'a = copy b' when assigning a stack variable to a stack variable");
        return;
    }

    TrValue leftValue(scope, type, name, isReturnValue);
    if (!op.isCopy) {
        if (!isFirstAssignment) {
            leftValue.addReleaseToStatements(block);
        }

        stringstream lineStream;
        lineStream << name << " = ";
        if (type->typeMode == CTM_Stack || type->typeMode == CTM_Local) {
            lineStream << TrValue::convertToLocalName(rightValue->type, rightValue->name, rightValue->isReturnValue);
        }
        else {
            lineStream << rightValue->name;
        }

        block->statements.push_back(lineStream.str());
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
            lineStream << type->parent.lock()->getCCopyFunctionName() << "(" << TrValue::convertToLocalName(type, name, isReturnValue) << ", " << TrValue::convertToLocalName(rightValue->type, rightValue->name, rightValue->isReturnValue) << ")";
            block->statements.push_back(lineStream.str());
        }
    }
}

string TrStoreValue::getName(TrBlock* block) {
    if (name.size() == 0) {
        name = block->createTempVariable(scope, type, "void")->name;
    }
    return name;
}

shared_ptr<TrValue> TrStoreValue::getValue() {
    return make_shared<TrValue>(scope, type, name, isReturnValue);
}
