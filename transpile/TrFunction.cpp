#include "../compiler/Compiler.h"

void TrFunction::writeBodyToStream(ostream& stream) {
	for (auto variable : variables)
	{
		stream << "    " << variable.second << " " << variable.first << ";\n";
	}

	auto level = 1;
	for (auto statement : statements)
	{	
		if (statement.size() == 0)
			continue;

		if (statement.front() == '}') {
			level--;
		}

		for (auto i = 0; i < level; i++) {
			stream << "    ";
		}

		stream << statement;

		if (statement.back() == '{') {
			level++;
		} else if (statement.front() != '}') {
			stream << ";";
		}

		stream << "\n";
	}
}
