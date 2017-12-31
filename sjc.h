//
//  sj.pch
//  sj
//
//  Created by Mann, Justin on 1/7/17.
//  Copyright © 2017 Mann, Justin. All rights reserved.
//

#ifndef sj_pch
#define sj_pch

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <streambuf>
#include <iomanip>

#include <memory>
#include <map>
#include <string>
#include <functional>
#include <assert.h>
#include <fstream>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp> 

void __fail(const char* s);

#undef assert
#define assert(x) if (!(x)) { __fail(#x); } 

#include "Node/Node.h"

#endif /* sj_pch */
