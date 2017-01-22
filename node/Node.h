#ifndef Node_h
#define Node_h

#include "../compiler/Compiler.h"

class NBase;

class NodeList : public vector<shared_ptr<NBase>> {
public:
    NodeList() : vector<shared_ptr<NBase>>() { }
    
    NodeList(shared_ptr<NBase> i0) : vector<shared_ptr<NBase>>() {
        push_back(i0);
    }
    
    NodeList(shared_ptr<NBase> i0, shared_ptr<NBase> i1) : vector<shared_ptr<NBase>>() {
        push_back(i0);
        push_back(i1);
    }

    NodeList(shared_ptr<NBase> i0, shared_ptr<NBase> i1, shared_ptr<NBase> i2) : vector<shared_ptr<NBase>>() {
        push_back(i0);
        push_back(i1);
        push_back(i2);
    }
};

typedef vector<string> StringList;

enum NodeType {
    NodeType_And,
    NodeType_Array,
    NodeType_Assignment,
    NodeType_Block,
    NodeType_Bool,
    NodeType_Cast,
    NodeType_Call,
    NodeType_Compare,
    NodeType_Dot,
    NodeType_Double,
    NodeType_For,
    NodeType_Function,
    NodeType_If,
    NodeType_Include,
    NodeType_Integer,
    NodeType_Math,
    NodeType_MathAssignment,
    NodeType_Not,
    NodeType_Or,
    NodeType_This,
    NodeType_Throw,
    NodeType_Variable,
    NodeType_Void,
    NodeType_While
};

#include "NAnd.h"
#include "NArray.h"
#include "NAssignment.h"
#include "NBase.h"
#include "NBlock.h"
#include "NBool.h"
#include "NCast.h"
#include "NCall.h"
#include "NCompare.h"
#include "NDot.h"
#include "NDouble.h"
#include "NFor.h"
#include "NFunction.h"
#include "NIf.h"
#include "NInclude.h"
#include "NInteger.h"
#include "NMath.h"
#include "NMathAssignment.h"
#include "NNot.h"
#include "NOr.h"
#include "NThis.h"
#include "NThrow.h"
#include "NVariable.h"
#include "NVoid.h"
#include "NWhile.h"

#endif /* Node_h */



