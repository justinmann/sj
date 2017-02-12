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
    int64_t refCount;
    int64_t size;
    int64_t count;
    char* str;
};

#endif /* library_hpp */
