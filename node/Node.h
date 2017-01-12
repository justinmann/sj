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
    NodeType_For,
    NodeType_Function,
    NodeType_If,
    NodeType_Integer,
    NodeType_Math,
    NodeType_MathAssignment,
    NodeType_Not,
    NodeType_Throw,
    NodeType_Variable,
    NodeType_Void,
    NodeType_While
};

#include "NAssignment.h"
#include "NBase.h"
#include "NBlock.h"
#include "NBool.h"
#include "NCast.h"
#include "NCall.h"
#include "NCompare.h"
#include "NDouble.h"
#include "NFor.h"
#include "NFunction.h"
#include "NIf.h"
#include "NInteger.h"
#include "NMath.h"
#include "NMathAssignment.h"
#include "NNot.h"
#include "NThrow.h"
#include "NVariable.h"
#include "NVoid.h"
#include "NWhile.h"

#endif /* Node_h */



