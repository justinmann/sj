#include "../compiler/Compiler.h"

void TrBlock::writeBodyToStream(ostream& stream, int level) {
	for (auto variable : variables)
	{
        for (auto i = 0; i < level; i++) {
            stream << "    ";
        }
		stream << variable.second->type << " " << variable.first << ";\n";
	}

	for (auto statement : statements)
	{
        if (statement.block != nullptr) {
            for (auto i = 0; i < level; i++) {
                stream << "    ";
            }
            stream << statement.line << " {\n";
            
            statement.block->writeBodyToStream(stream, level + 1);

            if (statement.elseBlock != nullptr) {
                for (auto i = 0; i < level; i++) {
                    stream << "    ";
                }
                stream << "} else {\n";
                statement.elseBlock->writeBodyToStream(stream, level + 1);
            }

            for (auto i = 0; i < level; i++) {
                stream << "    ";
            }
            stream << "}\n";
        } else if (statement.line.size() > 0) {
            for (auto i = 0; i < level; i++) {
                stream << "    ";
            }
            stream << statement.line << ";\n";
        }
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

shared_ptr<TrVariable> TrBlock::createVariable(string name, string type) {
    assert(getVariable(name) == nullptr);
    auto var = make_shared<TrVariable>(type, name);
    variables[name] = var;
    return var;
}

shared_ptr<TrVariable> TrBlock::createTempVariable(string prefix, string type) {
    auto nextIndex = ++varNames[prefix];
    stringstream varStream;
    varStream << prefix << nextIndex;
    auto varStr = varStream.str();
    auto var = make_shared<TrVariable>(type, varStr);
    variables[varStr] = var;
    return var;
}

void TrBlock::resetVarNames() {
    varNames.clear();
}

map<string, int> TrBlock::varNames;

