//
//  library.hpp
//  sj
//
//  Created by Mann, Justin on 2/4/17.
//  Copyright © 2017 Mann, Justin. All rights reserved.
//

#ifndef library_hpp
#define library_hpp

#include <stdio.h>

class list_char {
public:
    __int64_t refCount;
    __int64_t size;
    __int64_t count;
    char* str;
};

#endif /* library_hpp */
