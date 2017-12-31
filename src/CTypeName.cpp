//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include <sjc.h>


vector<string> emptyNamespace; 

CTypeName::CTypeName(shared_ptr<CType> ctype_) : ctype(ctype_), isOption(ctype_->isOption) {
}

CTypeNameList::CTypeNameList(CTypeCategory category, CTypeMode typeMode, vector<string> packageNamespace, const string& valueName, bool isOption) {
    push_back(make_shared<CTypeName>(category, typeMode, packageNamespace, valueName, isOption));
}

shared_ptr<CTypeName> CTypeName::parse(string name) {
    CTypeMode typeMode;
    vector<string> packageNamespace;

    if (name.find("stack ") == 0) {
        typeMode = CTM_Stack;
        name = name.substr(6, name.size() - 6);
    }
    else if (name.find("heap ") == 0) {
        typeMode = CTM_Heap;
        name = name.substr(5, name.size() - 5);
    }
    else {
        typeMode = CTM_Undefined;
    }

    if (name.front() == '(') {
        assert(false);
        return make_shared<CTypeName>(CTC_Function, typeMode, packageNamespace, name, name.back() == '?');
    } else if (name.front() == '#') {
        assert(false);
        return make_shared<CTypeName>(CTC_Interface, typeMode, packageNamespace, name, name.back() == '?');
    } else {
        auto bang = name.find('!');
        if (bang != string::npos) {
            auto typeName = name.substr(0, bang);
            auto templateNames = name.substr(bang + 1, name.size() - bang - 1);
            auto typeNameList = make_shared<CTypeNameList>();
            if (templateNames.front() == '[' && templateNames.back() == ']') {
                templateNames = templateNames.substr(1, templateNames.size() - 2);
                string::size_type prev_pos = 0;
                string::size_type pos = 0;
                while((pos = templateNames.find(',', pos)) != std::string::npos)
                {
                    std::string substring(templateNames.substr(prev_pos, pos - prev_pos) );
                    
                    auto templateType = parse(substring);
                    if (!templateType) {
                        return nullptr;
                    }
                    typeNameList->push_back(templateType);
                    
                    prev_pos = ++pos;
                }
            } else {
                auto templateType = parse(templateNames);
                if (!templateType) {
                    return nullptr;
                }
                typeNameList->push_back(templateType);
            }
            
            return make_shared<CTypeName>(CTC_Value, typeMode, packageNamespace, typeName, typeNameList, typeName.back() == '?');
        } else {
            return make_shared<CTypeName>(CTC_Value, typeMode, packageNamespace, name, name.back() == '?');
        }
    }
    return nullptr;
}

string CTypeName::getFullName() {
    string str = "";
    
    switch (typeMode) {
        case CTM_Local:
            str = "local ";
            break;
        case CTM_Stack:
            // str = "stack ";
            break;
        case CTM_Heap:
            str = "heap ";
            break;
        default:
            break;
    }
    
    if (category == CTC_Function) {
        str += "(";
        for (auto it : *argTypeNames) {
            if (it != argTypeNames->front()) {
                str += ", ";
            }
            if (it->mutability == CTI_Mutable) {
                str += "=";
            } else {
                str += ":";
            }
            str += it->getFullName();
        }
        str += ")" + returnTypeName->getFullName();
        if (isOption) {
            str += '?';
        }
        return str;
    } else {
        if (category == CTC_Interface) {
            str += '#';
        }
        str += valueName;
        if (isOption) {
            str += '?';
        }
        if (templateTypeNames) {
            if (templateTypeNames->size() == 1) {
                str += "!" + (*templateTypeNames)[0]->getFullName();
            } else {
                str += "![";
                for (auto it : *templateTypeNames) {
                    if (it != templateTypeNames->front()) {
                        str += ", ";
                    }
                    str += it->getFullName();
                }
                str += "]";
            }
        }
        return str;
    }
}
