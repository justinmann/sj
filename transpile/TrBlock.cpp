#include "../node/Node.h"

// #define SKIP_FREE

void TrBlock::writeToStream(ostream& stream, int level, bool outputLines) {
    writeVariablesToStream(stream,level, outputLines);
    writeBodyToStream(stream, level, outputLines);
    writeVariablesReleaseToStream(stream, level, outputLines);
    writeReturnToStream(stream, level, outputLines);
}

void TrBlock::writeVariablesToStream(ostream& stream, int level, bool outputLines) {
    if (initBlock) {
        initBlock->writeVariablesToStream(stream, level, outputLines);
    }

    for (auto variable : variables)
    {
        addSpacing(stream, level);
        stream << variable.second->type->cname;
        stream << " " << variable.first;
        if (!variable.second->type->parent.expired()) {
            if (variable.second->type->category == CTC_Value) {
                switch (variable.second->type->typeMode) {
                case CTM_Stack:
                    stream << " = { -1 }";
                    break;
                case CTM_Local:
                case CTM_Heap:
                case CTM_Weak:
                    stream << " = 0";
                    break;
                default:
                    assert(false);
                    break;
                }
            }
            else {
                switch (variable.second->type->typeMode) {
                case CTM_Local:
                case CTM_Heap:
                case CTM_Stack:
                case CTM_Weak:
                    stream << " = { 0 }";
                    break;
                default:
                    assert(false);
                    break;
                }
            }
        }
        stream << ";\n";
    }

    if (variables.size() > 0) {
        stream << "\n";
    }
}

void getLineDirective(ostream& stream, CLoc& prevLoc, CLoc& loc) {
    if (loc.shortFileName.size() == 0) {
        if (prevLoc.line != 0) {
            stream << "#line " << prevLoc.line << "\n";
        }
    }
    else if (prevLoc.shortFileName == loc.shortFileName) {
        prevLoc = loc;
        if (loc.line != 0) {
            stream << "#line " << loc.line << "\n";
        }
    }
    else {
        prevLoc = loc;
        stream << "#line " << loc.line << " \"" << loc.shortFileName << "\"\n";
    }
}

void TrBlock::writeBodyToStream(ostream& stream, int level, bool outputLines) {
    if (initBlock) {
        initBlock->writeBodyToStream(stream, level, outputLines);
    }

    CLoc previousLoc = CLoc::undefined;
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

            statement.block->writeToStream(stream, level + 1, outputLines);

            if (statement.elseBlock != nullptr) {
                addSpacing(stream, level);
                stream << "} else {\n";
                statement.elseBlock->writeToStream(stream, level + 1, outputLines);
            }

            addSpacing(stream, level);
            stream << "}\n";
            previousLineBlock = true;
        }
        else if (statement.line.size() > 0) {
            auto firstChar = statement.line.front();
            auto lastChar = statement.line.back();
            if (firstChar == '}') {
                level--;
            }

            if (outputLines) {
                getLineDirective(stream, previousLoc, statement.loc);
            }
            addSpacing(stream, level);
            stream << statement.line;
            if (lastChar != ':' && lastChar != ';' && lastChar != '{' && lastChar != '}' && !statement.fromCCode) {
                stream << ";";
            }
            if (lastChar == '{') {
                level++;
            }
            stream << "\n";
        }
    }
}

void TrBlock::writeVariablesReleaseToStream(ostream& stream, int level, bool outputLines) {
    if (initBlock) {
        initBlock->writeVariablesReleaseToStream(stream, level, outputLines);
    }

    stringstream varStream;
    for (auto variable : variables) {
        variable.second->writeReleaseToStream(varStream, level, outputLines);
    }

    for (auto variable : variables) {
        if (variable.second->type->typeMode == CTM_Stack) {
            addSpacing(varStream, level);
            varStream << "if (" << variable.first << "._refCount == 1) { " << variable.second->type->parent.lock()->getCDestroyFunctionName() << "(&" << variable.first << "); }\n";
        }
    }

    auto varString = varStream.str();
    if (varString.size() > 0) {
        stream << "\n" << varString;
    }
}

void TrBlock::writeReturnToStream(ostream& stream, int level, bool outputLines) {
    if (returnLine.size() > 0) {
        stream << "\n";
        addSpacing(stream, level);
        stream << "return " << returnLine << ";\n";
    }
}

shared_ptr<TrValue> TrBlock::getVariable(string name) {
    auto var = variables.find(name);
    if (var == variables.end()) {
        if (localVarParent != nullptr) {
            return localVarParent->getVariable(name);
        }
        return nullptr;
    }
    return var->second;
}

shared_ptr<TrValue> TrBlock::createVariable(shared_ptr<CScope> scope, shared_ptr<CType> type, string name) {
    if (localVarParent && type->typeMode == CTM_Stack) {
        return localVarParent->createVariable(scope, type, name);
    }
    else {
        auto var = getVariable(name);
        if (var) {
            assert(var->type == type);
        }
        else {
            var = make_shared<TrValue>(scope, type, name, false);
            variables[name] = var;
        }
        return var;
    }
}

shared_ptr<TrValue> TrBlock::createTempVariable(shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix) {
    if (localVarParent && type->typeMode == CTM_Stack) {
        return localVarParent->createTempVariable(scope, type, prefix);
    }
    else {
        auto varStr = nextVarName(prefix);
        auto var = make_shared<TrValue>(scope, type, varStr, false);
        variables[varStr] = var;
        return var;
    }
}

shared_ptr<TrStoreValue> TrBlock::createTempStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix) {
    if (localVarParent && type->typeMode == CTM_Stack) {
        return localVarParent->createTempStoreVariable(loc, scope, type, prefix);
    }
    else {
        auto varStr = nextVarName("sjt_" + prefix);
        auto var = make_shared<TrStoreValue>(loc, scope, type, varStr, AssignOp::immutableCreate);
        variables[varStr] = make_shared<TrValue>(scope, type, varStr, false);
        return var;
    }
}

shared_ptr<TrStoreValue> TrBlock::createVoidStoreVariable(CLoc loc, shared_ptr<CType> type) {
    return make_shared<TrStoreValue>(loc, type, true);
}

shared_ptr<TrStoreValue> TrBlock::createReturnStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type) {
    auto returnStoreValue = make_shared<TrStoreValue>(loc, scope, type, type->typeMode == CTM_Stack ? "_return" : "(*_return)", AssignOp::immutableCreate);
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
    return "";
}

map<string, int> TrBlock::varNames;

void TrValue::writeReleaseToStream(ostream& stream, int level, bool outputLines) {
    TrBlock block;
    addReleaseToStatements(&block);
    block.writeBodyToStream(stream, level, outputLines);
}

void TrValue::addReleaseToStatements(TrBlock* block) {
    if (type->typeMode == CTM_Heap) {
        if (type->category == CTC_Function) {
            auto ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if ((uintptr_t)" << name << ".inner._parent > 1)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();

            stringstream lineStream;
            lineStream << name << ".inner._parent->_refCount--";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

#ifdef DEBUG_ALLOC
            stringstream logStream;
            logStream << "printf(\"RELEASE\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
            innerBlock->statements.push_back(logStream.str());
#endif

            auto ifBlock = make_shared<TrBlock>();
            stringstream ifStream2;
            ifStream2 << "if (" << name << ".inner._parent->_refCount <= 0)";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, ifStream2.str(), ifBlock));

            stringstream destroyStream;
            destroyStream << name << "._destroy(" << name + ".inner._parent" << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));

#ifndef SKIP_FREE
            stringstream freeStream;
            freeStream << "free(" << name << ".inner._parent)";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, freeStream.str()));
#endif // !SKIP_FREE
        } 
        else if (type->category == CTC_Interface) {
            auto ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << name << "._parent != 0)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();

            stringstream lineStream;
            lineStream << name << "._parent->_refCount--";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

#ifdef DEBUG_ALLOC
            stringstream logStream;
            logStream << "printf(\"RELEASE\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
            innerBlock->statements.push_back(logStream.str());
#endif

            auto ifBlock = make_shared<TrBlock>();
            stringstream ifStream2;
            ifStream2 << "if (" << name << "._parent->_refCount <= 0)";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, ifStream2.str(), ifBlock));

            stringstream destroyStream;
            destroyStream << name << "._vtbl->destroy(" << name + "._parent" << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));

#ifndef SKIP_FREE
            stringstream freeStream;
            freeStream << "free(" << name << "._parent)";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, freeStream.str()));
#endif // !SKIP_FREE
        }
        else {
            assert(!type->parent.expired());
            shared_ptr<TrBlock> ifNullBlock;
            auto innerBlock = block;
            if (type->isOption) {
                ifNullBlock = make_shared<TrBlock>();
                stringstream ifStream;
                ifStream << "if (" << name << " != 0)";
                block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

                innerBlock = ifNullBlock.get();
            }

            stringstream lineStream;
            lineStream << name << "->_refCount--";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

#ifdef DEBUG_ALLOC
            stringstream logStream;
            logStream << "printf(\"RELEASE\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
            innerBlock->statements.push_back(logStream.str());
#endif

            auto ifBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << name << "->_refCount <= 0)";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifBlock));

            stringstream killweakptrStream;
            killweakptrStream << "weakptr_release(" << convertToLocalName(type, name, false) << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, killweakptrStream.str()));

            stringstream destroyStream;
            destroyStream << type->parent.lock()->getCDestroyFunctionName() << "(" << convertToLocalName(type, name, false) << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));

#ifndef SKIP_FREE
            stringstream freeStream;
            freeStream << "free(" << name << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, freeStream.str()));
#endif // !SKIP_FREE
        }
    }
    else if (type->typeMode == CTM_Weak) {
        auto cbName = TrBlock::nextVarName("weakptrcb");

        if (type->category == CTC_Interface) {
            stringstream cbStream;
            cbStream << "delete_cb " << cbName << " = { &" << name << "._parent, weakptr_clear };";
            block->statements.push_back(TrStatement(CLoc::undefined, cbStream.str()));

            stringstream lineStream;
            lineStream << "if (" << name << "._parent != 0) { weakptr_cb_remove(" << name << "._parent, " << cbName << "); }";
            block->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else if (type->category == CTC_Function) {
            stringstream cbStream;
            cbStream << "delete_cb " << cbName << " = { &" << name << "._parent, weakptr_clear };";
            block->statements.push_back(TrStatement(CLoc::undefined, cbStream.str()));

            stringstream lineStream;
            lineStream << "if (" << name << "._parent != 0) { weakptr_cb_remove(" << name << "._parent, " << cbName << "); }";
            block->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else {
            stringstream cbStream;
            cbStream << "delete_cb " << cbName << " = { &" << name << ", weakptr_clear };";
            block->statements.push_back(TrStatement(CLoc::undefined, cbStream.str()));

            stringstream lineStream;
            lineStream << "if (" << name << " != 0) { weakptr_cb_remove(" << name << ", " << cbName << "); }";
            block->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
    }
}

void TrValue::addRetainToStatements(TrBlock* block) {
    if (type->typeMode == CTM_Heap) {
        if (type->category == CTC_Function) {
            auto ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if ((uintptr_t)" << name << ".inner._parent > 1)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();
            stringstream lineStream;
            lineStream << name << ".inner._parent->_refCount++";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else if (type->category == CTC_Interface) {
            auto ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << name << "._parent != 0)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();
            stringstream lineStream;
            lineStream << name << "._parent->_refCount++";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else {
            assert(!type->parent.expired());
            shared_ptr<TrBlock> ifNullBlock;
            auto innerBlock = block;
            if (type->isOption) {
                ifNullBlock = make_shared<TrBlock>();
                stringstream ifStream;
                ifStream << "if (" << name << " != 0)";
                block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

                innerBlock = ifNullBlock.get();
            }

            stringstream lineStream;
            lineStream << name << "->_refCount++";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

#ifdef DEBUG_ALLOC
            stringstream logStream;
            logStream << "printf(\"RETAIN\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
            innerBlock->statements.push_back(logStream.str());
#endif
        }
    }
    else if (type->typeMode == CTM_Weak) {
        auto cbName = TrBlock::nextVarName("weakptrcb");

        if (type->category == CTC_Interface) {
            stringstream cbStream;
            cbStream << "delete_cb " << cbName << " = { &" << name << "._parent, weakptr_clear };";
            block->statements.push_back(TrStatement(CLoc::undefined, cbStream.str()));

            stringstream lineStream;
            lineStream << "if (" << name << "._parent != 0) { weakptr_cb_add(" << name << "._parent, " << cbName << "); }";
            block->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else if (type->category == CTC_Function) {
            stringstream cbStream;
            cbStream << "delete_cb " << cbName << " = { &" << name << "._parent, weakptr_clear };";
            block->statements.push_back(TrStatement(CLoc::undefined, cbStream.str()));

            stringstream lineStream;
            lineStream << "if (" << name << "._parent != 0) { weakptr_cb_add(" << name << "._parent, " << cbName << "); }";
            block->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else {
            stringstream cbStream;
            cbStream << "delete_cb " << cbName << " = { &" << name << ", weakptr_clear };";
            block->statements.push_back(TrStatement(CLoc::undefined, cbStream.str()));

            stringstream lineStream;
            lineStream << "if (" << name << " != 0) { weakptr_cb_add(" << name << ", " << cbName << "); }";
            block->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
    }
}
    
void TrValue::addInitToStatements(TrBlock* block) {
    if (type->typeMode == CTM_Value) {
        return;
    }
    else if (type->typeMode == CTM_Heap) {
        if (!type->parent.expired()) {
            if (type->isOption) {
                if (type->category == CTC_Interface) {
                    stringstream initLine;
                    initLine << name << "._parent = 0";
                    block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));
                }
                else {
                    stringstream initLine;
                    initLine << name << " = 0";
                    block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));
                }
            }
            else {
                string structName = type->parent.lock()->getCStructName(type->typeMode);
                stringstream initLine;
                initLine << name << " = (" << structName << "*)malloc(sizeof(" << structName << "))";
                block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));

                stringstream lineStream;
                lineStream << name << "->_refCount = 1";
                block->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

#ifdef DEBUG_ALLOC
                stringstream logStream;
                logStream << "printf(\"RETAIN\\t" << type->nameRef << "\\t%0x\\t" << block->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
                block->statements.push_back(logStream.str());
#endif
            }
        }
    }
    else if (type->typeMode == CTM_Stack) {
        assert(!type->parent.expired());

        stringstream initLine;
        if (isReturnValue) {
            initLine << name << "->_refCount = 1";
        }
        else {
            initLine << name << "._refCount = 1";
        }
        block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));
    }
    else if (type->typeMode == CTM_Local) {
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
        return name;
    case CTM_Value:
        return name;
    case CTM_Weak:
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
        return isReturnValue ? name :from->isOption ? ("(" + name + "._refCount != -1 ? &" + name + " : 0)") : ("&" + name);
    case CTM_Heap:
        if (from->category == CTC_Interface) {
            return name;
        }
        else if (from->category == CTC_Function) {
            return name + ".inner";
        }
        else {
            return name;
        }
    case CTM_Value:
        return name;
    case CTM_Weak:
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

    if (!CType::isSameExceptModeAndOption(type, rightValue->type)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' does not match left type '%s'", rightValue->type->fullName.c_str(), type->fullName.c_str());
        return;
    }

    if (rightValue->type->isOption && !type->isOption && type->typeMode != CTM_Local) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot be converted to left type '%s'", rightValue->type->fullName.c_str(), type->fullName.c_str());
        return;
    }

    if (isVoid) {
        return;
    }

    switch (type->typeMode) {
    case CTM_Value:
    case CTM_ValuePtr:
    case CTM_Local:
        break;
    case CTM_Weak:
        if (rightValue->type->typeMode != CTM_Heap && rightValue->type->typeMode != CTM_Weak) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s'", rightValue->type->fullName.c_str(), type->fullName.c_str());
            return;
        }
        break;
    case CTM_Stack:
        if (type->typeMode != rightValue->type->typeMode && !op.isCopy) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s' without using a copy operator like 'a = copy b'", rightValue->type->fullName.c_str(), type->fullName.c_str());
            return;
        }
        if (rightValue->type->typeMode == CTM_Stack && !op.isCopy) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "must use a copy operator like 'a = copy b' when assigning a stack variable to a stack variable");
            return;
        }
        break;
    case CTM_Heap:
        if (rightValue->type->typeMode != CTM_Heap && rightValue->type->typeMode != CTM_Weak && !op.isCopy) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s' without using a copy operator like 'a = copy b'", rightValue->type->fullName.c_str(), type->fullName.c_str());
            return;
        }
        break;
    default:
        assert(false);
    }

    TrValue leftValue(scope, type, name, isReturnValue);
    if (!op.isCopy) {
        if (!op.isFirstAssignment) {
            leftValue.addReleaseToStatements(block);
        }

        if (type->typeMode == CTM_Value && type->isOption && !rightValue->type->isOption) {
            stringstream line1;
            line1 << name << ".isvalid = true";
            block->statements.push_back(TrStatement(loc, line1.str()));

            stringstream line2;
            line2 << name << ".value = " << rightValue->name;
            block->statements.push_back(TrStatement(loc, line2.str()));
        }
        else {
            stringstream lineStream;
            lineStream << name << " = ";
            if (isObjectCast) {
                lineStream << "(sjs_object*)";
            }
            if (type->typeMode == CTM_Stack || type->typeMode == CTM_Local) {
                lineStream << TrValue::convertToLocalName(rightValue->type, rightValue->name, rightValue->isReturnValue);
            }
            else if (type->typeMode == CTM_ValuePtr && rightValue->type->typeMode == CTM_Value) {
                lineStream << "&" << rightValue->name;
            }
            else {
                lineStream << rightValue->name;
            }
            block->statements.push_back(TrStatement(loc, lineStream.str()));
        }

        leftValue.addRetainToStatements(block);
    }
    else {
        if (type->typeMode == CTM_Value) {
            assert(rightValue->type->typeMode == CTM_Value);
            stringstream lineStream;
            lineStream << name << " = " << rightValue->name;
            block->statements.push_back(TrStatement(loc, lineStream.str()));
        }
        else {
            if (op.isFirstAssignment) {
                leftValue.addInitToStatements(block);
            }
            else {
                leftValue.addReleaseToStatements(block);
            }

            if (type->category == CTC_Function) {
                type->callback.lock()->writeCopy(block, rightValue->name, name, type->typeMode == CTM_Heap);
            } 
            else if (type->category == CTC_Interface) {
                compiler->addError(loc, CErrorCode::Internal, "interface cannot be copied");
            } 
            else {
                stringstream lineStream;
                lineStream << type->parent.lock()->getCCopyFunctionName() << "(" << TrValue::convertToLocalName(type, name, isReturnValue) << ", " << TrValue::convertToLocalName(rightValue->type, rightValue->name, rightValue->isReturnValue) << ")";
                block->statements.push_back(TrStatement(loc, lineStream.str()));
            }
        }
    }
}

string TrStoreValue::getName(TrBlock* block) {
    if (name.size() == 0) {
        name = block->createTempVariable(scope, type, "void")->name;
    }
    if (type->typeMode == CTM_ValuePtr) {
        return "*" + name;
    }
    else {
        return name;
    }
}

shared_ptr<TrValue> TrStoreValue::getValue() {
    return make_shared<TrValue>(scope, type, name, isReturnValue);
}
