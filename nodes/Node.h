#ifndef Node_h
#define Node_h

#include "../compiler/Compiler.h"

class NBase;

typedef vector<shared_ptr<NBase>> NodeList;
typedef vector<string> StringList;

enum NodeType {
    Assignment,
    Block,
    Bool,
    Cast,
    Compare,
    Double,
    FunctionDeclaration,
    If,
    Integer,
    Math,
    MethodCall,
    Variable,
    Void
    
};

#include "NAssignment.h"
#include "NBase.h"
#include "NBlock.h"
#include "NBool.h"
#include "NCast.h"
#include "NCompare.h"
#include "NDouble.h"
#include "NFunctionDeclaration.h"
#include "NIf.h"
#include "NInteger.h"
#include "NMath.h"
#include "NMethodCall.h"
#include "NVariable.h"
#include "NVoid.h"

#endif /* Node_h */



