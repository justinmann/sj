#pragma once

enum TrReleaseMode {
    TRM_DONOTHING,      // values or temp references that do not retain
    TRM_RELEASE,        // heap or unknown type variable
    TRM_STACKDESTROY,   // stack variable created in block
};

class TrVariable {
public:
    TrVariable(string type_, string name_, TrReleaseMode releaseMode_, string destroyFunctionName_) : type(type_), name(name_), releaseMode(releaseMode_), destroyFunctionName(destroyFunctionName_) { }
    void writeReleaseToStream(ostream& stream, int level);

	string type;
    string name;
    TrReleaseMode releaseMode;
    string destroyFunctionName;
};
