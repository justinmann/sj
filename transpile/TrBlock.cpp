#include "../compiler/Compiler.h"

void TrBlock::writeBodyToStream(ostream& stream, int level) {
	for (auto variable : variables)
	{
        addSpacing(stream, level);
        stream << variable.second->type << " " << variable.first << ";\n";
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

    for (auto variable : variables)
    {
        variable.second->writeReleaseToStream(stream, level);
    }

    if (returnLine.size() > 0) {
        addSpacing(stream, level);
        stream << "return " << returnLine << ";\n";
    }
}

shared_ptr<TrVariable> TrBlock::getVariable(string name) {
    auto var = variables.find(name);
    if (var == variables.end()) {
        if (parent != nullptr) {
            return parent->getVariable(name);
        }
        return nullptr;
    }
    return var->second;
}

shared_ptr<TrVariable> TrBlock::createVariable(string name, string type, TrReleaseMode releaseMode, string destroyFunctionName) {
    assert(getVariable(name) == nullptr);
    auto var = make_shared<TrVariable>(type, name, releaseMode, destroyFunctionName);
    variables[name] = var;
    return var;
}

shared_ptr<TrVariable> TrBlock::createTempVariable(string prefix, string type, TrReleaseMode releaseMode, string destroyFunctionName) {
    auto nextIndex = ++varNames[prefix];
    stringstream varStream;
    varStream << prefix << nextIndex;
    auto varStr = varStream.str();
    auto var = make_shared<TrVariable>(type, varStr, releaseMode, destroyFunctionName);
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

