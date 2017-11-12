//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

CTypeNameList::CTypeNameList(CTypeCategory category, const string& name) {
    push_back(make_shared<CTypeName>(category, name));
}

shared_ptr<CTypeName> CTypeName::parse(string name) {
    if (name.front() == '(') {
        assert(false);
        return make_shared<CTypeName>(CTC_Function, name);
    } else if (name.front() == '#') {
        assert(false);
        return make_shared<CTypeName>(CTC_Interface, name);
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
            
            return make_shared<CTypeName>(CTC_Value, typeName, typeNameList);
        } else {
            return make_shared<CTypeName>(CTC_Value, name);
        }
    }
    return nullptr;
}

CTypeName::CTypeName(shared_ptr<CType> ctype) {
    category = ctype->category;
    name = ctype->name;
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
