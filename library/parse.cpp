//
//  parse.cpp
//  sj
//
//  Created by Mann, Justin on 2/4/17.
//  Copyright © 2017 Mann, Justin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <unwind.h>
#include <vector>
#include "library.h"

extern "C" int64_t parse_toInt(list_char* str) {
    char* e;
    errno = 0;
    std::string s = std::string(str->str, str->count);
    auto v = strtoll(s.c_str(), &e, 10);
    
    if (ERANGE == errno) {
        return 0;
    }
    
    if (*e != '\0') {
        return 0;
    }
    
    return v;
}
