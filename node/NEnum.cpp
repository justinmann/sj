#include <sjc.h>
#include "Node.h"

EnumArg::EnumArg(string name) : name(name), hasValue(false) {
    boost::algorithm::to_lower(this->name);
}

EnumArg::EnumArg(string name, string value) : name(name), hasValue(true), value(value) {
    boost::algorithm::to_lower(this->name);
}

CInitBlockVar::CInitBlockVar(CLoc loc, shared_ptr<CScope> scope, vector<shared_ptr<CVar>> statements) : CVar(loc, scope), statements(statements) {
    for (auto it : statements) {
        assert(it != nullptr);
    }
}

bool CInitBlockVar::getReturnThis() {
    return statements.back()->getReturnThis();
}

shared_ptr<CType> CInitBlockVar::getType(Compiler* compiler) {
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getType(compiler);
}

void CInitBlockVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    if (!trBlock->initBlock) {
        trBlock->initBlock = make_shared<TrBlock>(trBlock);
    }

    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        auto type = it->getType(compiler);
        if (!type) {
            compiler->addError(it->loc, CErrorCode::InvalidType, "line has no type");
            continue;
        }
        it->transpile(compiler, trOutput, trBlock->initBlock.get(), thisValue, isLastStatement ? storeValue : trBlock->initBlock->createVoidStoreVariable(loc, type));
    }
}

void CInitBlockVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "{\n";
    for (auto it : statements) {
        stringstream line;
        it->dump(compiler, functions, line, level + 1);
        auto t = line.str();
        if (t.size() > 0) {
            dumpf(ss, level + 1);
            ss << t << "\n";
        }
    }
    dumpf(ss, level);
    ss << "}";
}

NEnum::NEnum(CLoc loc, string name, shared_ptr<EnumArgs> enumArgs) : NVariableBase(NodeType_Enum, loc), name(name), enumArgs(enumArgs) {
    boost::algorithm::to_lower(this->name);
}

void NEnum::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    this->packageNamespace = packageNamespace;
    this->packageNamespace.push_back(name);
    
    // create a new type
    auto ctypes = CType::create(packageNamespace, name, "int32_t", "(int32_t)0", "int32_option", "int32_empty");
    compiler->types[name] = ctypes;

    vector<shared_ptr<NSwitchClause>> clauses;
    auto index = 0;
    for (auto enumArg : *enumArgs) {
        auto clause = make_shared<NSwitchClause>(loc, make_shared<NInteger>(loc, (enumArg->hasValue ? enumArg->value : to_string(index)).c_str()), make_shared<NString>(loc, enumArg->name));
        clauses.push_back(clause);
        index++;
    }

    auto defaultClause = make_shared<NSwitchClause>(loc, nullptr, make_shared<NString>(loc, ""));
    clauses.push_back(defaultClause);

    auto switchBlock = make_shared<NSwitch>(loc, make_shared<NVariable>(loc, "e", nullptr), clauses);

    asStringFunction = make_shared<NFunction>(loc, nullptr, (name + "_asstring").c_str(), nullptr, nullptr, nullptr,
        make_shared<NodeList>(make_shared<NAssignment>(loc, nullptr, make_shared<CTypeName>(CTC_Value, CTM_Value, packageNamespace, name, false), "e", nullptr, AssignOp::immutableCreate)),
        switchBlock, nullptr, nullptr, nullptr);

    asStringFunction->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NEnum::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto ctypes = compiler->types[name];

    // create constants in a package namespace
    vector<string> enumNamespace;
    vector<shared_ptr<CVar>> statementVars;
    enumNamespace.push_back(name);
    scope->pushNamespace(compiler, enumNamespace);
    for (auto enumArg : *enumArgs) {
        auto leftVar = scope->getCVar(compiler, scope, nullptr, enumArg->name, VSM_LocalThisParent);
        if (leftVar) {
            compiler->addError(loc, CErrorCode::ImmutableAssignment, "var '%s' already exists", enumArg->name.c_str());
            return;
        }

        string nameNS;
        bool isFirst = true;
        for (auto ns : packageNamespace) {
            if (isFirst) {
                isFirst = false;
            }
            else {
                nameNS += "_";
            }
            nameNS += ns;
        }
        if (!isFirst) {
            nameNS += "_";
        }
        nameNS += enumArg->name;

        auto leftStoreVar = make_shared<CNormalVar>(loc, scope, ctypes->stackValueType, enumArg->name, "sjv_" + nameNS, false, CVarType::Var_Local, nullptr);
        scope->addOrUpdateLocalVar(compiler, packageNamespace, leftStoreVar);
        enumVars.push_back(leftStoreVar);
    }
    scope->popNamespace(compiler, enumNamespace);

    asStringFunction->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NEnum::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto ctypes = compiler->types[name];

    // create constants in a package namespace
    vector<string> enumNamespace;
    vector<shared_ptr<CVar>> statementVars;
    enumNamespace.push_back(name);
    scope->pushNamespace(compiler, enumNamespace);
    auto index = 0;
    for (auto enumArg : *enumArgs) {
        auto leftStoreVar = enumVars[index];
        auto rightVar = make_shared<CConstantVar>(loc, scope, ctypes->stackValueType, enumArg->hasValue ? enumArg->value : to_string(index));
        auto assignVar = make_shared<CAssignVar>(loc, scope, AssignOp::immutableCreate, leftStoreVar, rightVar);
        statementVars.push_back(assignVar);
        index++;
    }
    scope->popNamespace(compiler, enumNamespace);

    return make_shared<CInitBlockVar>(loc, scope, statementVars);
}

