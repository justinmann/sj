//
//  random.cpp
//  sj
//
//  Created by Mann, Justin on 2/4/17.
//  Copyright © 2017 Mann, Justin. All rights reserved.
//

#include <stdio.h>

extern "C" int64_t random_nextInt() {
    return (uint64_t)rand() << 32 | (uint64_t)rand();
}
