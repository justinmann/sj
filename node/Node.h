#ifndef Node_h
#define Node_h

#include "../compiler/Compiler.h"

class NBase;

typedef vector<shared_ptr<NBase>> NodeList;
typedef vector<string> StringList;

enum NodeType {
    NodeType_Assignment,
    NodeType_Block,
    NodeType_Bool,
    NodeType_Cast,
    NodeType_Call,
    NodeType_Compare,
    NodeType_Double,
    NodeType_Function,
    NodeType_If,
    NodeType_Integer,
    NodeType_Math,
    NodeType_Variable,
    NodeType_Void
};

#include "NAssignment.h"
#include "NBase.h"
#include "NBlock.h"
#include "NBool.h"
#include "NCast.h"
#include "NCompare.h"
#include "NDouble.h"
#include "NFunction.h"
#include "NIf.h"
#include "NInteger.h"
#include "NMath.h"
#include "NCall.h"
#include "NVariable.h"
#include "NVoid.h"

#endif /* Node_h */



