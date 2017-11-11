#include "node/Node.h"
#include <string.h>
#include <fstream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

void runTest(fs::path path, bool updateResult) {    
	if (path.extension().string().compare(".sj") == 0) {
		printf("Running %s\n", path.string().c_str());
        TrBlock::resetVarNames();

        auto codeFileName = fs::change_extension(path, ".c");
        auto debugFileName = fs::change_extension(path, ".debug");
        auto errorFileName = fs::change_extension(path, ".errors");

		if (updateResult) {
			ofstream code;
			code.open(codeFileName.c_str());
			ofstream error;
			error.open(errorFileName.c_str());
            ofstream debug;
            debug.open(debugFileName.c_str());

			Compiler compiler;
			compiler.transpile(path.string(), code, error, &debug);

			code.close();
			error.close();
            debug.close();
		} else {
			stringstream codeA;
			stringstream errorA;

			Compiler compiler;
			compiler.transpile(path.string(), codeA, errorA, nullptr);

			codeA.seekg(0, codeA.beg);
			errorA.seekg(0, errorA.beg);

			// Compare file output
			int line = 0;
			string lineA;
			string lineB;
			ifstream codeB(codeFileName.c_str());
			if (codeB.is_open())
			{
				while (getline(codeB, lineB))
				{
					line++;
					getline(codeA, lineA);

					if (lineA.compare(lineB) != 0) {
						cout << "Line " << line << " does not match:\n" << lineA << "\n" << lineB << "\n";
					}
				}
				codeB.close();
			}

			// Compare error output
			line = 0;
			ifstream errorB(errorFileName.c_str());
			if (errorB.is_open())
			{
				while (getline(errorB, lineB))
				{
					line++;
					getline(errorA, lineA);

					if (lineA.compare(lineB) != 0) {
						cout << "Error " << line << " does not match:\n" << lineA << "\n" << lineB << "\n";
					}
				}
				errorB.close();
			}
		}
	}
}

void runAllTests(fs::path path, bool updateResult, const char* wildcard) {
    for (auto child : fs::directory_iterator(path)) {
        if (fs::is_directory(child.path())) {
            runAllTests(child.path(), updateResult, wildcard);
        }
        else if (fs::is_regular_file(child.path()) && (wildcard == nullptr || child.path().generic_string().find(wildcard) != string::npos)) {
            runTest(child.path(), updateResult);
        }
    }
}
                          
int main(int argc, char **argv) {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    if (argc == 1) {
        printf("-test or [filename]\n");
        return 0;
    }
    
	if (strcmp(argv[1], "-test") == 0) {
		runAllTests(".", false, argv[2]);
	} else if (strcmp(argv[1], "-testUpdate") == 0) {
		runAllTests(".", true, argv[2]);
    } else {
        result = compiler.compile(argv[1]);
        for (auto error : result->errors) {
            printf("ERROR: %s %d:%d %d %s\n", error.fileName->c_str(), error.line, error.col, error.code, error.msg.c_str());
        }

        for (auto warning : result->warnings) {
            printf("WARNING: %s %d:%d %d %s\n", warning.fileName->c_str(), warning.line, warning.col, warning.code, warning.msg.c_str());
        }
        
        if (result->errors.size() == 0) {
            printf("SUCCESS\n");
            return 0;
        } else {
            return -1;
        }
    }

    return 0;
}
