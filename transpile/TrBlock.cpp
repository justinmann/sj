#include <sjc.h>


void TrBlock::writeToStream(Compiler* compiler, ostream& stream, int level) {
    writeVariablesToStream(compiler, stream,level);
    writeBodyToStream(compiler, stream, level);
    writeVariablesReleaseToStream(compiler, stream, level);
    writeReturnToStream(compiler, stream, level);
}

void TrBlock::writeVariablesToStream(Compiler* compiler, ostream& stream, int level) {
    if (initBlock) {
        initBlock->writeVariablesToStream(compiler, stream, level);
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

void TrBlock::writeBodyToStream(Compiler* compiler, ostream& stream, int level) {
    if (initBlock) {
        initBlock->writeBodyToStream(compiler, stream, level);
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

            statement.block->writeToStream(compiler, stream, level + 1);

            if (statement.elseBlock != nullptr) {
                addSpacing(stream, level);
                stream << "} else {\n";
                statement.elseBlock->writeToStream(compiler, stream, level + 1);
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

            if (compiler->outputLines) {
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

void TrBlock::writeVariablesReleaseToStream(Compiler* compiler, ostream& stream, int level) {
    if (initBlock) {
        initBlock->writeVariablesReleaseToStream(compiler, stream, level);
    }

    stringstream varStream;
    for (auto variable : variables) {
        variable.second->writeReleaseToStream(compiler, this, varStream, level);
    }

    for (auto variable : variables) {
        variable.second->writeDestroyToStream(compiler, this, varStream, level);
    }

    auto varString = varStream.str();
    if (varString.size() > 0) {
        stream << "\n" << varString;
    }
}

void TrBlock::writeReturnToStream(Compiler* compiler, ostream& stream, int level) {
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

shared_ptr<TrStoreValue> TrBlock::createCaptureStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type) {
    assert(type->typeMode == CTM_Value || type->typeMode == CTM_Local);
    auto var = make_shared<TrStoreValue>(loc, scope, type, "", AssignOp::immutableCreate);
    var->isCaptureValue = true;
    return var;
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
    if (parent && name.size() == 0) {
        return parent->getFunctionName();
    }
    return name;
}

map<string, int> TrBlock::varNames;

void TrValue::writeReleaseToStream(Compiler* compiler, TrBlock* parentBlock, ostream& stream, int level) {
    TrBlock block(parentBlock);
    addReleaseToStatements(compiler, &block);
    block.writeBodyToStream(compiler, stream, level);
}

void TrValue::writeDestroyToStream(Compiler* compiler, TrBlock* parentBlock, ostream& stream, int level) {
    TrBlock block(parentBlock);
    addDestroyToStatements(compiler, &block);
    block.writeBodyToStream(compiler, stream, level);
}

void TrValue::addReleaseToStatements(Compiler* compiler, TrBlock* block) {
    if (type->typeMode == CTM_Heap) {
        if (type->category == CTC_Function) {
            auto ifNullBlock = make_shared<TrBlock>(block);
            stringstream ifStream;
            ifStream << "if ((uintptr_t)" << name << ".inner._parent > 1)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();

            stringstream lineStream;
            lineStream << name << ".inner._parent->_refCount--";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

            if (compiler->outputDebugLeaks) {
                stringstream logStream;
                logStream << "_object_release((sjs_object*)" << name << ".inner._parent" << ", \"" << block->getFunctionName() << "\");";
                innerBlock->statements.push_back(TrStatement(CLoc::undefined, logStream.str()));
            }

            auto ifBlock = make_shared<TrBlock>(block);
            stringstream ifStream2;
            ifStream2 << "if (" << name << ".inner._parent->_refCount <= 0)";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, ifStream2.str(), ifBlock));

            stringstream destroyStream;
            destroyStream << name << "._destroy(" << name + ".inner._parent" << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));

            if (compiler->outputFree) {
                stringstream freeStream;
                freeStream << "free(" << name << ".inner._parent)";
                ifBlock->statements.push_back(TrStatement(CLoc::undefined, freeStream.str()));
            }
        } 
        else if (type->category == CTC_Interface) {
            auto ifNullBlock = make_shared<TrBlock>(block);
            stringstream ifStream;
            ifStream << "if (" << name << "._parent != 0)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();

            stringstream lineStream;
            lineStream << name << "._parent->_refCount--";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

            if (compiler->outputDebugLeaks) {
                stringstream logStream;
                logStream << "_object_release((sjs_object*)" << name << "._parent" << ", \"" << block->getFunctionName() << "\");";
                innerBlock->statements.push_back(TrStatement(CLoc::undefined, logStream.str()));
            }

            auto ifBlock = make_shared<TrBlock>(block);
            stringstream ifStream2;
            ifStream2 << "if (" << name << "._parent->_refCount <= 0)";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, ifStream2.str(), ifBlock));

            stringstream destroyStream;
            destroyStream << name << "._vtbl->destroy(" << name + "._parent" << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));

            if (compiler->outputFree) {
                stringstream freeStream;
                freeStream << "free(" << name << "._parent)";
                ifBlock->statements.push_back(TrStatement(CLoc::undefined, freeStream.str()));
            }
        }
        else {
            assert(!type->parent.expired());
            shared_ptr<TrBlock> ifNullBlock;
            auto innerBlock = block;
            if (type->isOption) {
                ifNullBlock = make_shared<TrBlock>(block);
                stringstream ifStream;
                ifStream << "if (" << name << " != 0)";
                block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

                innerBlock = ifNullBlock.get();
            }

            stringstream lineStream;
            lineStream << name << "->_refCount--";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));

            if (compiler->outputDebugLeaks) {
                stringstream logStream;
                logStream << "_object_release((sjs_object*)" << name << ", \"" << block->getFunctionName() << "\");";
                innerBlock->statements.push_back(TrStatement(CLoc::undefined, logStream.str()));
            }

            auto ifBlock = make_shared<TrBlock>(block);
            stringstream ifStream;
            ifStream << "if (" << name << "->_refCount <= 0)";
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifBlock));

            stringstream killweakptrStream;
            killweakptrStream << "weakptr_release(" << convertToLocalName(type, name, false) << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, killweakptrStream.str()));

            stringstream destroyStream;
            destroyStream << type->parent.lock()->getCDestroyFunctionName() << "(" << convertToLocalName(type, name, false) << ")";
            ifBlock->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));

            if (compiler->outputFree) {
                stringstream freeStream;
                freeStream << "free(" << name << ")";
                ifBlock->statements.push_back(TrStatement(CLoc::undefined, freeStream.str()));
            }
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

void TrValue::addDestroyToStatements(Compiler* compiler, TrBlock* block) {
    if (type->typeMode == CTM_Stack) {
        stringstream destroyStream;
        destroyStream << "if (" << name << "._refCount == 1) { " << type->parent.lock()->getCDestroyFunctionName() << "(&" << name << "); }\n";
        block->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));
    }
}

void TrValue::addDestroyLocalToStatements(Compiler* compiler, TrBlock* block) {
    if (type->typeMode == CTM_Local) {
        stringstream destroyStream;
        destroyStream << "if (" << name << "->_refCount == 1) { " << type->parent.lock()->getCDestroyFunctionName() << "(" << name << "); }\n";
        block->statements.push_back(TrStatement(CLoc::undefined, destroyStream.str()));
    }
}

void TrValue::addRetainToStatements(Compiler* compiler, TrBlock* block) {
    if (type->typeMode == CTM_Heap) {
        if (type->category == CTC_Function) {
            auto ifNullBlock = make_shared<TrBlock>(block);
            stringstream ifStream;
            ifStream << "if ((uintptr_t)" << name << ".inner._parent > 1)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();
            stringstream lineStream;
            lineStream << name << ".inner._parent->_refCount++";
            if (compiler->outputDebugLeaks) {
                lineStream << "; _object_retain((sjs_object*)" << name << ".inner._parent" << ", \"" << block->getFunctionName() << "\");";
            }
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else if (type->category == CTC_Interface) {
            auto ifNullBlock = make_shared<TrBlock>(block);
            stringstream ifStream;
            ifStream << "if (" << name << "._parent != 0)";
            block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

            auto innerBlock = ifNullBlock.get();
            stringstream lineStream;
            lineStream << name << "._parent->_refCount++";
            if (compiler->outputDebugLeaks) {
                lineStream << "; _object_retain((sjs_object*)" << name << "._parent" << ", \"" << block->getFunctionName() << "\");";
            }
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }
        else {
            assert(!type->parent.expired());
            shared_ptr<TrBlock> ifNullBlock;
            auto innerBlock = block;
            if (type->isOption) {
                ifNullBlock = make_shared<TrBlock>(block);
                stringstream ifStream;
                ifStream << "if (" << name << " != 0)";
                block->statements.push_back(TrStatement(CLoc::undefined, ifStream.str(), ifNullBlock));

                innerBlock = ifNullBlock.get();
            }

            stringstream lineStream;
            lineStream << name << "->_refCount++";
            if (compiler->outputDebugLeaks) {
                lineStream << "; _object_retain((sjs_object*)" << name << ", \"" << block->getFunctionName() << "\");";
            }
            innerBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
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
    
void TrValue::addInitToStatements(Compiler* compiler, TrBlock* block) {
    if (type->typeMode == CTM_Value) {
        if (type->isOption) {
            stringstream initLine;
            if (isReturnValue) {
                initLine << name << "->isvalid = true";
            }
            else {
                initLine << name << ".isvalid = true";
            }
            block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));
        }
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

                if (compiler->outputDebugLeaks) {
                    stringstream logStream;
                    logStream << "_object_init((sjs_object*)" << name << ", " << structName + "_typeId, \"" << block->getFunctionName() << "\");";
                    block->statements.push_back(TrStatement(CLoc::undefined, logStream.str()));
                }
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

void TrValue::addEmptyToStatements(Compiler* compiler, TrBlock* block) {
    assert(type->isOption);

    if (type->typeMode == CTM_Value) {
        stringstream initLine;
        if (isReturnValue) {
            initLine << name << "->isvalid = false";
        }
        else {
            initLine << name << ".isvalid = false";
        }
        block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));
    }
    else if (type->typeMode == CTM_Heap) {
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
    else if (type->typeMode == CTM_Stack) {
        assert(!type->parent.expired());
        stringstream initLine;
        if (isReturnValue) {
            initLine << name << "->_refCount = -1";
        }
        else {
            initLine << name << "._refCount = -1";
        }
        block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));
    }
    else if (type->typeMode == CTM_Local) {
        stringstream initLine;
        initLine << name << " = 0";
        block->statements.push_back(TrStatement(CLoc::undefined, initLine.str()));
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
    auto isCopy = op.isCopy;

    if (isVoid) {
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
            isCopy = true;
        }
        if (rightValue->type->typeMode == CTM_Stack && !op.isCopy) {
            isCopy = true;
        }
        break;
    case CTM_Heap:
        if (rightValue->type->typeMode != CTM_Heap && rightValue->type->typeMode != CTM_Weak && !op.isCopy) {
            isCopy = true;
        }
        break;
    default:
        assert(false);
    }

    TrValue leftValue(scope, type, name, isReturnValue);
    if (!isCopy) {
        if (!op.isFirstAssignment) {
            leftValue.addReleaseToStatements(compiler, block);
            leftValue.addDestroyToStatements(compiler, block);
        }

        if (type->typeMode == CTM_Value && type->isOption && !rightValue->type->isOption) {
            stringstream line1;
            line1 << getName(block) << ".isvalid = true";
            block->statements.push_back(TrStatement(loc, line1.str()));

            stringstream line2;
            line2 << getName(block) << ".value = " << rightValue->name;
            block->statements.push_back(TrStatement(loc, line2.str()));
        }
        else {
            stringstream lineStream;
            if (name.size() > 0) {
                lineStream << name << " = ";
            } else {
                assert(isCaptureValue);
            }

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

            if (isCaptureValue && name.size() == 0) {
                captureText = lineStream.str();
            }
            else {
                block->statements.push_back(TrStatement(loc, lineStream.str()));
            }
        }

        leftValue.addRetainToStatements(compiler, block);
    }
    else {
        assert(!isCaptureValue);

        if (type->typeMode == CTM_Value) {
            assert(rightValue->type->typeMode == CTM_Value);
            stringstream lineStream;
            lineStream << name << " = " << rightValue->name;
            block->statements.push_back(TrStatement(loc, lineStream.str()));
        }
        else {
            if (type->isOption) {
                if (!op.isFirstAssignment) {
                    leftValue.addReleaseToStatements(compiler, block);
                    leftValue.addDestroyToStatements(compiler, block);
                }

                string rightTempName = TrBlock::nextVarName("copyoption");

                stringstream lineStream;
                lineStream << rightValue->type->getLocalType()->cname << " " << rightTempName << " = " << TrValue::convertToLocalName(rightValue->type, rightValue->name, rightValue->isReturnValue);
                block->statements.push_back(TrStatement(loc, lineStream.str()));

                stringstream lineStream2;
                lineStream2 << "if (" << rightTempName << " != 0)";
                auto statement = TrStatement(loc, lineStream2.str());

                auto trIfBlock = make_shared<TrBlock>(block);
                trIfBlock->hasThis = block->hasThis;
                trIfBlock->localVarParent = block;
                statement.block = trIfBlock;

                auto trElseBlock = make_shared<TrBlock>(block);
                trElseBlock->hasThis = block->hasThis;
                trElseBlock->localVarParent = block;
                statement.elseBlock = trElseBlock;

                leftValue.addInitToStatements(compiler, trIfBlock.get());
                if (type->category == CTC_Function) {
                    type->callback.lock()->writeCopy(compiler, trIfBlock.get(), rightValue->name, name, type->typeMode == CTM_Heap);
                }
                else if (type->category == CTC_Interface) {
                    compiler->addError(loc, CErrorCode::Internal, "interface cannot be copied");
                }
                else {
                    stringstream lineStream2;
                    lineStream2 << type->parent.lock()->getCCopyFunctionName() << "(" << TrValue::convertToLocalName(type->getValueType(), name, isReturnValue) << ", " << rightTempName << ")";
                    trIfBlock->statements.push_back(TrStatement(loc, lineStream2.str()));
                }

                leftValue.addEmptyToStatements(compiler, trElseBlock.get());

                block->statements.push_back(statement);
            }
            else {
                if (op.isFirstAssignment) {
                    leftValue.addInitToStatements(compiler, block);
                }
                else {
                    leftValue.addReleaseToStatements(compiler, block);
                    leftValue.addDestroyToStatements(compiler, block);
                }

                if (type->category == CTC_Function) {
                    type->callback.lock()->writeCopy(compiler, block, rightValue->name, name, type->typeMode == CTM_Heap);
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
}

string TrStoreValue::getName(TrBlock* block) {
    if (name.size() == 0) {
        name = block->createTempVariable(scope, type, isVoid ? "sjt_void" : "sjt_capture")->name;
        if (isCaptureValue) {
            assert(captureText.size() == 0);
            captureText = name;
        }
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

bool TrStoreValue::parensRequired(string s, bool isIf) {
    if (s.find(' ') != string::npos || s.front() == '&') {
        bool areParensValid = true;
        int parens = 0;
        for (size_t i = 1; i < s.size() - 1; i++) {
            if (s[i] == '(') {
                parens++;
            }
            else if (s[i] == ')') {
                parens--;
                if (parens < 0) {
                    areParensValid = false;
                }
            }
        }

        if (s.front() == '(' && s.back() == ')' && areParensValid) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return isIf;
    }
}

string TrStoreValue::getCaptureText() {
    assert(isCaptureValue);
    if (parensRequired(captureText, false)) {
        return "(" + captureText + ")";
    }
    else {
        return captureText;
    }
}
