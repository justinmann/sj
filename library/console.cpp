//
//  console.cpp
//  sj
//
//  Created by Mann, Justin on 2/4/17.
//  Copyright © 2017 Mann, Justin. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include "library.h"

extern "C" list_char* console_readLine() {
    auto size = 1024;
    auto str = (char*)malloc(size);
    auto index = 0;
    auto ch = ' ';
    do {
        ch = getchar();
        if (ch != '\n') {
            str[index] = ch;
            index++;
            if (index > size) {
                size *= 2;
                str = (char*)realloc(str, size);
            }
        }
    } while (ch != '\n');


    list_char* result = new list_char();
    result->refCount = 1;
    result->count = index;
    result->size = size;
    result->str = str;
    return result;
}

extern "C" void console_write(list_char* str) {
    for (int i = 0; i < str->count; i++) {
        putchar(str->str[i]);
    }
    fflush(stdout);
}
