//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

//string CVar::fullName() {
//    return strprintf("%s.%s", (parent.expired() ? "" : parent.lock()->fullName(false).c_str()), name.c_str());
//}
//
//shared_ptr<CBaseFunction> CVar::getCFunctionForValue(Compiler* compiler, CResult& result) {
//    auto ctype = getType(compiler, result);
//    if (ctype && !ctype->parent.expired()) {
//        return ctype->parent.lock();
//    }
//    return nullptr;
//}

//shared_ptr<CNormalVar> CNormalVar::createThisVar(const CLoc& loc, shared_ptr<CBaseFunction> parent, shared_ptr<CType> type) {
//    auto c = make_shared<CNormalVar>();
//    c->loc = loc;
//    c->mode = CVarType::Var_This;
//    c->name = "this";
//    c->isMutable = false;
//    c->type = type;
//    c->parent = parent;
//    return c;
//}

shared_ptr<CNormalVar> CNormalVar::createLocalVar(const CLoc& loc, const string& name, shared_ptr<CBaseFunction> parent, shared_ptr<NAssignment> nassignment) {
    auto c = make_shared<CNormalVar>();
    c->loc = loc;
    c->mode = CVarType::Var_Local;
    c->name = name;
    c->isMutable = nassignment != nullptr ? nassignment->isMutable : false;
    c->nassignment = nassignment;
    c->parent = parent;
    return c;
}

shared_ptr<CNormalVar> CNormalVar::createFunctionVar(const CLoc& loc, const string& name, shared_ptr<CBaseFunction> parent, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type, shared_ptr<CVar> interfaceMethodArgVar_) {
    auto c = make_shared<CNormalVar>();
    c->loc = loc;
    c->mode = CVarType::Var_Public;
    c->name = name;
    c->isMutable = nassignment != nullptr ? nassignment->isMutable : false;
    c->index = index;
    c->nassignment = nassignment;
    c->parent = parent;
    c->type = type;
    c->interfaceMethodArgVar = interfaceMethodArgVar_;
    
    if (interfaceMethodArgVar_) {
        auto t = static_pointer_cast<CInterfaceMethodArgVar>(interfaceMethodArgVar_);
        t->functionVars.push_back(c);
    }
    
    assert(type != nullptr || nassignment != nullptr);
    
    return c;
}

void CNormalVar::makeFunctionVar(int index) {
    assert(mode == CVarType::Var_Local);
    mode = CVarType::Var_Public;
    this->index = index;
}

shared_ptr<CType> CNormalVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        assert(false);
        // type = nassignment->getType(compiler, result, parent.lock(), nullptr); // TODO:
    }
    isInGetType = false;
    return type;
}

shared_ptr<ReturnValue> CNormalVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto returnType = getType(compiler, result);
    if (!returnType)
        return nullptr;

    if (dotValue) {
        auto returnValue = trBlock->createTempVariable(returnType, "dotTemp");
        stringstream lineStream;
        lineStream << returnValue->name << " = " << dotValue->name << "->" << name;
        trBlock->statements.push_back(lineStream.str());
        return returnValue;
    } else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        auto returnValue = trBlock->createTempVariable(returnType, "dotTemp");
        stringstream lineStream;
        lineStream << returnValue->name << " = " << "_this->" << name;
        trBlock->statements.push_back(lineStream.str());
        return returnValue;
    } else {
        return make_shared<ReturnValue>(returnType, name);
    }    
}

void CNormalVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    stringstream lineStream;

    if (!returnValue)
        return;

    auto returnType = getType(compiler, result);
    if (returnType != returnValue->type) {
        result.addError(loc, CErrorCode::TypeMismatch, "returned type '%s' does not match explicit type '%s'", returnType->name.c_str(), returnValue->type->name.c_str());
        return;
    }

    string varName;
    bool isFirstAssignment = false;

    if (dotValue) {
        varName = dotValue->name + "->" + name;
    }
    else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        if (!isMutable) {
            // TODO: this may not be the first assignment
            isFirstAssignment = true;
        }
        varName = "_this->" + name;
    }
    else {
        if (!trBlock->getVariable(name)) {
            isFirstAssignment = true;
            trBlock->createVariable(returnType, name);
        }
        else if (!isMutable) {
            // Check is mutable or first assignment
            result.addError(loc, CErrorCode::TypeMismatch, "cannot assign to immutable variable", returnType->name.c_str(), returnValue->type->name.c_str());
            return;
        }
        varName = name;
    }
    
    auto varValue = make_shared<ReturnValue>(returnType, varName);
    varValue->addAssignToStatements(trBlock, returnValue->name, isFirstAssignment);
}

void CNormalVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    if (dotSS.gcount()) {
        ss << dotSS.str() << ".";
    }
    
    if (mode == Var_Public || mode == Var_Private) {
        ss << "this.";
    }
    
    ss << name;
}


