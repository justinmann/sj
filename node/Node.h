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

    NodeList(shared_ptr<NBase> i0, shared_ptr<NBase> i1, shared_ptr<NBase> i2, shared_ptr<NBase> i3) : vector<shared_ptr<NBase>>() {
        push_back(i0);
        push_back(i1);
        push_back(i2);
        push_back(i3);
    }

    NodeList(shared_ptr<NBase> i0, shared_ptr<NBase> i1, shared_ptr<NBase> i2, shared_ptr<NBase> i3, shared_ptr<NBase> i4) : vector<shared_ptr<NBase>>() {
        push_back(i0);
        push_back(i1);
        push_back(i2);
        push_back(i3);
        push_back(i4);
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
    NodeType_ChangeMode,
    NodeType_Char,
    NodeType_Code,
    NodeType_Compare,
    NodeType_Copy,
    NodeType_Dot,
    NodeType_Double,
    NodeType_Enum,
    NodeType_Empty,
    NodeType_For,
    NodeType_Function,
    NodeType_GetOrElse,
    NodeType_GetValue,
    NodeType_If,
    NodeType_IfValue,
    NodeType_Import,
    NodeType_Include,
    NodeType_Integer,
    NodeType_Interface,
    NodeType_InterfaceMethod,
    NodeType_IsEmpty,
    NodeType_List,
    NodeType_Math,
    NodeType_MathAssignment,
    NodeType_Negate,
    NodeType_Not,
    NodeType_OptionDot,
    NodeType_Or,
    NodeType_Package,
    NodeType_Parent,
    NodeType_String,
    NodeType_StringArray,
    NodeType_This,
    NodeType_Throw,
    NodeType_Tuple,
    NodeType_TupleAssignment,
    NodeType_Value,
    NodeType_Variable,
    NodeType_Void,
    NodeType_While
};

#include "NAnd.h"
#include "NArray.h"
#include "NAssignment.h"
#include "NBase.h"
#include "NBaseFunction.h"
#include "NBlock.h"
#include "NBool.h"
#include "NCast.h"
#include "NCall.h"
#include "NCCode.h"
#include "NChangeMode.h"
#include "NChar.h"
#include "NCompare.h"
#include "NCopy.h"
#include "NDot.h"
#include "NDouble.h"
#include "NEnum.h"
#include "NEmpty.h"
#include "NFor.h"
#include "NFunction.h"
#include "NGetOrElse.h"
#include "NGetValue.h"
#include "NIf.h"
#include "NIfValue.h"
#include "NImport.h"
#include "NInclude.h"
#include "NInteger.h"
#include "NInterface.h"
#include "NInterfaceMethod.h"
#include "NIsEmpty.h"
#include "NPackage.h"
#include "NParent.h"
#include "NMath.h"
#include "NMathAssignment.h"
#include "NNot.h"
#include "NNegate.h"
#include "NOptionDot.h"
#include "NOr.h"
#include "NString.h"
#include "NThis.h"
#include "NThrow.h"
#include "NTuple.h"
#include "NTupleAssignment.h"
#include "NValue.h"
#include "NVariable.h"
#include "NVoid.h"
#include "NWhile.h"
#include "CCallback.h"

#endif /* Node_h */



