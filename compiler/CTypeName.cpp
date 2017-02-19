//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

CTypeNameList::CTypeNameList(CTypeCategory category, const string& name) {
    push_back(make_shared<CTypeName>(category, name));
}

string CTypeName::getName() {
    if (category == CTC_Function) {
        string str = "(";
        for (auto it : *argTypeNames) {
            if (it != argTypeNames->front()) {
                str += ", ";
            }
            if (it->mutability == CTM_Mutable) {
                str += "=";
            } else {
                str += ":";
            }
            str += it->getName();
        }
        str += ")" + returnTypeName->getName();
        return str;
    } else {
        string str = "";
        if (category == CTC_Interface) {
            str += "#";
        }
        str += name;
        if (templateTypeNames) {
            if (templateTypeNames->size() == 1) {
                str += "!" + (*templateTypeNames)[0]->getName();
            } else {
                str += "![";
                for (auto it : *templateTypeNames) {
                    if (it != templateTypeNames->front()) {
                        str += ", ";
                    }
                    str += it->getName();
                }
                str += "]";
            }
        }
        return str;
    }
}
