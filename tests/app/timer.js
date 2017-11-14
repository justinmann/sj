// The Module object: Our interface to the outside world. We import
// and export values on it, and do the work to get that through
// closure compiler if necessary. There are various ways Module can be used:
// 1. Not defined. We create it here
// 2. A function parameter, function(Module) { ..generated code.. }
// 3. pre-run appended it, var Module = {}; ..generated code..
// 4. External script tag defines var Module.
// We need to do an eval in order to handle the closure compiler
// case, where this code here is minified but Module was defined
// elsewhere (e.g. case 4 above). We also need to check if Module
// already exists (e.g. case 3 above).
// Note that if you want to run closure, and also to use Module
// after the generated code, you will need to define   var Module = {};
// before the code. Then that object will be used in the code, and you
// can continue to use Module afterwards as well.
var Module;
if (!Module) Module = (typeof Module !== 'undefined' ? Module : null) || {};

// Sometimes an existing Module object exists with properties
// meant to overwrite the default module functionality. Here
// we collect those properties and reapply _after_ we configure
// the current environment's defaults to avoid having to be so
// defensive during initialization.
var moduleOverrides = {};
for (var key in Module) {
  if (Module.hasOwnProperty(key)) {
    moduleOverrides[key] = Module[key];
  }
}

// The environment setup code below is customized to use Module.
// *** Environment setup code ***
var ENVIRONMENT_IS_WEB = false;
var ENVIRONMENT_IS_WORKER = false;
var ENVIRONMENT_IS_NODE = false;
var ENVIRONMENT_IS_SHELL = false;

// Three configurations we can be running in:
// 1) We could be the application main() thread running in the main JS UI thread. (ENVIRONMENT_IS_WORKER == false and ENVIRONMENT_IS_PTHREAD == false)
// 2) We could be the application main() thread proxied to worker. (with Emscripten -s PROXY_TO_WORKER=1) (ENVIRONMENT_IS_WORKER == true, ENVIRONMENT_IS_PTHREAD == false)
// 3) We could be an application pthread running in a worker. (ENVIRONMENT_IS_WORKER == true and ENVIRONMENT_IS_PTHREAD == true)

if (Module['ENVIRONMENT']) {
  if (Module['ENVIRONMENT'] === 'WEB') {
    ENVIRONMENT_IS_WEB = true;
  } else if (Module['ENVIRONMENT'] === 'WORKER') {
    ENVIRONMENT_IS_WORKER = true;
  } else if (Module['ENVIRONMENT'] === 'NODE') {
    ENVIRONMENT_IS_NODE = true;
  } else if (Module['ENVIRONMENT'] === 'SHELL') {
    ENVIRONMENT_IS_SHELL = true;
  } else {
    throw new Error('The provided Module[\'ENVIRONMENT\'] value is not valid. It must be one of: WEB|WORKER|NODE|SHELL.');
  }
} else {
  ENVIRONMENT_IS_WEB = typeof window === 'object';
  ENVIRONMENT_IS_WORKER = typeof importScripts === 'function';
  ENVIRONMENT_IS_NODE = typeof process === 'object' && typeof require === 'function' && !ENVIRONMENT_IS_WEB && !ENVIRONMENT_IS_WORKER;
  ENVIRONMENT_IS_SHELL = !ENVIRONMENT_IS_WEB && !ENVIRONMENT_IS_NODE && !ENVIRONMENT_IS_WORKER;
}


if (ENVIRONMENT_IS_NODE) {
  // Expose functionality in the same simple way that the shells work
  // Note that we pollute the global namespace here, otherwise we break in node
  if (!Module['print']) Module['print'] = console.log;
  if (!Module['printErr']) Module['printErr'] = console.warn;

  var nodeFS;
  var nodePath;

  Module['read'] = function shell_read(filename, binary) {
    if (!nodeFS) nodeFS = require('fs');
    if (!nodePath) nodePath = require('path');
    filename = nodePath['normalize'](filename);
    var ret = nodeFS['readFileSync'](filename);
    return binary ? ret : ret.toString();
  };

  Module['readBinary'] = function readBinary(filename) {
    var ret = Module['read'](filename, true);
    if (!ret.buffer) {
      ret = new Uint8Array(ret);
    }
    assert(ret.buffer);
    return ret;
  };

  Module['load'] = function load(f) {
    globalEval(read(f));
  };

  if (!Module['thisProgram']) {
    if (process['argv'].length > 1) {
      Module['thisProgram'] = process['argv'][1].replace(/\\/g, '/');
    } else {
      Module['thisProgram'] = 'unknown-program';
    }
  }

  Module['arguments'] = process['argv'].slice(2);

  if (typeof module !== 'undefined') {
    module['exports'] = Module;
  }

  process['on']('uncaughtException', function(ex) {
    // suppress ExitStatus exceptions from showing an error
    if (!(ex instanceof ExitStatus)) {
      throw ex;
    }
  });

  Module['inspect'] = function () { return '[Emscripten Module object]'; };
}
else if (ENVIRONMENT_IS_SHELL) {
  if (!Module['print']) Module['print'] = print;
  if (typeof printErr != 'undefined') Module['printErr'] = printErr; // not present in v8 or older sm

  if (typeof read != 'undefined') {
    Module['read'] = read;
  } else {
    Module['read'] = function shell_read() { throw 'no read() available' };
  }

  Module['readBinary'] = function readBinary(f) {
    if (typeof readbuffer === 'function') {
      return new Uint8Array(readbuffer(f));
    }
    var data = read(f, 'binary');
    assert(typeof data === 'object');
    return data;
  };

  if (typeof scriptArgs != 'undefined') {
    Module['arguments'] = scriptArgs;
  } else if (typeof arguments != 'undefined') {
    Module['arguments'] = arguments;
  }

  if (typeof quit === 'function') {
    Module['quit'] = function(status, toThrow) {
      quit(status);
    }
  }

}
else if (ENVIRONMENT_IS_WEB || ENVIRONMENT_IS_WORKER) {
  Module['read'] = function shell_read(url) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', url, false);
    xhr.send(null);
    return xhr.responseText;
  };

  if (ENVIRONMENT_IS_WORKER) {
    Module['readBinary'] = function readBinary(url) {
      var xhr = new XMLHttpRequest();
      xhr.open('GET', url, false);
      xhr.responseType = 'arraybuffer';
      xhr.send(null);
      return new Uint8Array(xhr.response);
    };
  }

  Module['readAsync'] = function readAsync(url, onload, onerror) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', url, true);
    xhr.responseType = 'arraybuffer';
    xhr.onload = function xhr_onload() {
      if (xhr.status == 200 || (xhr.status == 0 && xhr.response)) { // file URLs can return 0
        onload(xhr.response);
      } else {
        onerror();
      }
    };
    xhr.onerror = onerror;
    xhr.send(null);
  };

  if (typeof arguments != 'undefined') {
    Module['arguments'] = arguments;
  }

  if (typeof console !== 'undefined') {
    if (!Module['print']) Module['print'] = function shell_print(x) {
      console.log(x);
    };
    if (!Module['printErr']) Module['printErr'] = function shell_printErr(x) {
      console.warn(x);
    };
  } else {
    // Probably a worker, and without console.log. We can do very little here...
    var TRY_USE_DUMP = false;
    if (!Module['print']) Module['print'] = (TRY_USE_DUMP && (typeof(dump) !== "undefined") ? (function(x) {
      dump(x);
    }) : (function(x) {
      // self.postMessage(x); // enable this if you want stdout to be sent as messages
    }));
  }

  if (ENVIRONMENT_IS_WORKER) {
    Module['load'] = importScripts;
  }

  if (typeof Module['setWindowTitle'] === 'undefined') {
    Module['setWindowTitle'] = function(title) { document.title = title };
  }
}
else {
  // Unreachable because SHELL is dependant on the others
  throw 'Unknown runtime environment. Where are we?';
}

function globalEval(x) {
  eval.call(null, x);
}
if (!Module['load'] && Module['read']) {
  Module['load'] = function load(f) {
    globalEval(Module['read'](f));
  };
}
if (!Module['print']) {
  Module['print'] = function(){};
}
if (!Module['printErr']) {
  Module['printErr'] = Module['print'];
}
if (!Module['arguments']) {
  Module['arguments'] = [];
}
if (!Module['thisProgram']) {
  Module['thisProgram'] = './this.program';
}
if (!Module['quit']) {
  Module['quit'] = function(status, toThrow) {
    throw toThrow;
  }
}

// *** Environment setup code ***

// Closure helpers
Module.print = Module['print'];
Module.printErr = Module['printErr'];

// Callbacks
Module['preRun'] = [];
Module['postRun'] = [];

// Merge back in the overrides
for (var key in moduleOverrides) {
  if (moduleOverrides.hasOwnProperty(key)) {
    Module[key] = moduleOverrides[key];
  }
}
// Free the object hierarchy contained in the overrides, this lets the GC
// reclaim data used e.g. in memoryInitializerRequest, which is a large typed array.
moduleOverrides = undefined;



// {{PREAMBLE_ADDITIONS}}

// === Preamble library stuff ===

// Documentation for the public APIs defined in this file must be updated in:
//    site/source/docs/api_reference/preamble.js.rst
// A prebuilt local version of the documentation is available at:
//    site/build/text/docs/api_reference/preamble.js.txt
// You can also build docs locally as HTML or other formats in site/
// An online HTML version (which may be of a different version of Emscripten)
//    is up at http://kripken.github.io/emscripten-site/docs/api_reference/preamble.js.html

//========================================
// Runtime code shared with compiler
//========================================

var Runtime = {
  setTempRet0: function (value) {
    tempRet0 = value;
    return value;
  },
  getTempRet0: function () {
    return tempRet0;
  },
  stackSave: function () {
    return STACKTOP;
  },
  stackRestore: function (stackTop) {
    STACKTOP = stackTop;
  },
  getNativeTypeSize: function (type) {
    switch (type) {
      case 'i1': case 'i8': return 1;
      case 'i16': return 2;
      case 'i32': return 4;
      case 'i64': return 8;
      case 'float': return 4;
      case 'double': return 8;
      default: {
        if (type[type.length-1] === '*') {
          return Runtime.QUANTUM_SIZE; // A pointer
        } else if (type[0] === 'i') {
          var bits = parseInt(type.substr(1));
          assert(bits % 8 === 0);
          return bits/8;
        } else {
          return 0;
        }
      }
    }
  },
  getNativeFieldSize: function (type) {
    return Math.max(Runtime.getNativeTypeSize(type), Runtime.QUANTUM_SIZE);
  },
  STACK_ALIGN: 16,
  prepVararg: function (ptr, type) {
    if (type === 'double' || type === 'i64') {
      // move so the load is aligned
      if (ptr & 7) {
        assert((ptr & 7) === 4);
        ptr += 4;
      }
    } else {
      assert((ptr & 3) === 0);
    }
    return ptr;
  },
  getAlignSize: function (type, size, vararg) {
    // we align i64s and doubles on 64-bit boundaries, unlike x86
    if (!vararg && (type == 'i64' || type == 'double')) return 8;
    if (!type) return Math.min(size, 8); // align structures internally to 64 bits
    return Math.min(size || (type ? Runtime.getNativeFieldSize(type) : 0), Runtime.QUANTUM_SIZE);
  },
  dynCall: function (sig, ptr, args) {
    if (args && args.length) {
      assert(args.length == sig.length-1);
      assert(('dynCall_' + sig) in Module, 'bad function pointer type - no table for sig \'' + sig + '\'');
      return Module['dynCall_' + sig].apply(null, [ptr].concat(args));
    } else {
      assert(sig.length == 1);
      assert(('dynCall_' + sig) in Module, 'bad function pointer type - no table for sig \'' + sig + '\'');
      return Module['dynCall_' + sig].call(null, ptr);
    }
  },
  functionPointers: [],
  addFunction: function (func) {
    for (var i = 0; i < Runtime.functionPointers.length; i++) {
      if (!Runtime.functionPointers[i]) {
        Runtime.functionPointers[i] = func;
        return 2*(1 + i);
      }
    }
    throw 'Finished up all reserved function pointers. Use a higher value for RESERVED_FUNCTION_POINTERS.';
  },
  removeFunction: function (index) {
    Runtime.functionPointers[(index-2)/2] = null;
  },
  warnOnce: function (text) {
    if (!Runtime.warnOnce.shown) Runtime.warnOnce.shown = {};
    if (!Runtime.warnOnce.shown[text]) {
      Runtime.warnOnce.shown[text] = 1;
      Module.printErr(text);
    }
  },
  funcWrappers: {},
  getFuncWrapper: function (func, sig) {
    if (!func) return; // on null pointer, return undefined
    assert(sig);
    if (!Runtime.funcWrappers[sig]) {
      Runtime.funcWrappers[sig] = {};
    }
    var sigCache = Runtime.funcWrappers[sig];
    if (!sigCache[func]) {
      // optimize away arguments usage in common cases
      if (sig.length === 1) {
        sigCache[func] = function dynCall_wrapper() {
          return Runtime.dynCall(sig, func);
        };
      } else if (sig.length === 2) {
        sigCache[func] = function dynCall_wrapper(arg) {
          return Runtime.dynCall(sig, func, [arg]);
        };
      } else {
        // general case
        sigCache[func] = function dynCall_wrapper() {
          return Runtime.dynCall(sig, func, Array.prototype.slice.call(arguments));
        };
      }
    }
    return sigCache[func];
  },
  getCompilerSetting: function (name) {
    throw 'You must build with -s RETAIN_COMPILER_SETTINGS=1 for Runtime.getCompilerSetting or emscripten_get_compiler_setting to work';
  },
  stackAlloc: function (size) { var ret = STACKTOP;STACKTOP = (STACKTOP + size)|0;STACKTOP = (((STACKTOP)+15)&-16);(assert((((STACKTOP|0) < (STACK_MAX|0))|0))|0); return ret; },
  staticAlloc: function (size) { var ret = STATICTOP;STATICTOP = (STATICTOP + (assert(!staticSealed),size))|0;STATICTOP = (((STATICTOP)+15)&-16); return ret; },
  dynamicAlloc: function (size) { assert(DYNAMICTOP_PTR);var ret = HEAP32[DYNAMICTOP_PTR>>2];var end = (((ret + size + 15)|0) & -16);HEAP32[DYNAMICTOP_PTR>>2] = end;if (end >= TOTAL_MEMORY) {var success = enlargeMemory();if (!success) {HEAP32[DYNAMICTOP_PTR>>2] = ret;return 0;}}return ret;},
  alignMemory: function (size,quantum) { var ret = size = Math.ceil((size)/(quantum ? quantum : 16))*(quantum ? quantum : 16); return ret; },
  makeBigInt: function (low,high,unsigned) { var ret = (unsigned ? ((+((low>>>0)))+((+((high>>>0)))*(+4294967296))) : ((+((low>>>0)))+((+((high|0)))*(+4294967296)))); return ret; },
  GLOBAL_BASE: 8,
  QUANTUM_SIZE: 4,
  __dummy__: 0
}



Module["Runtime"] = Runtime;


function getSafeHeapType(bytes, isFloat) {
  switch (bytes) {
    case 1: return 'i8';
    case 2: return 'i16';
    case 4: return isFloat ? 'float' : 'i32';
    case 8: return 'double';
    default: assert(0);
  }
}


function SAFE_HEAP_STORE(dest, value, bytes, isFloat) {
  if (dest <= 0) abort('segmentation fault storing ' + bytes + ' bytes to address ' + dest);
  if (dest % bytes !== 0) abort('alignment error storing to address ' + dest + ', which was expected to be aligned to a multiple of ' + bytes);
  if (staticSealed) {
    if (dest + bytes > HEAP32[DYNAMICTOP_PTR>>2]) abort('segmentation fault, exceeded the top of the available dynamic heap when storing ' + bytes + ' bytes to address ' + dest + '. STATICTOP=' + STATICTOP + ', DYNAMICTOP=' + HEAP32[DYNAMICTOP_PTR>>2]);
    assert(DYNAMICTOP_PTR);
    assert(HEAP32[DYNAMICTOP_PTR>>2] <= TOTAL_MEMORY);
  } else {
    if (dest + bytes > STATICTOP) abort('segmentation fault, exceeded the top of the available static heap when storing ' + bytes + ' bytes to address ' + dest + '. STATICTOP=' + STATICTOP);
  }
  setValue(dest, value, getSafeHeapType(bytes, isFloat), 1);
}
function SAFE_HEAP_STORE_D(dest, value, bytes) {
  SAFE_HEAP_STORE(dest, value, bytes, true);
}

function SAFE_HEAP_LOAD(dest, bytes, unsigned, isFloat) {
  if (dest <= 0) abort('segmentation fault loading ' + bytes + ' bytes from address ' + dest);
  if (dest % bytes !== 0) abort('alignment error loading from address ' + dest + ', which was expected to be aligned to a multiple of ' + bytes);
  if (staticSealed) {
    if (dest + bytes > HEAP32[DYNAMICTOP_PTR>>2]) abort('segmentation fault, exceeded the top of the available dynamic heap when loading ' + bytes + ' bytes from address ' + dest + '. STATICTOP=' + STATICTOP + ', DYNAMICTOP=' + HEAP32[DYNAMICTOP_PTR>>2]);
    assert(DYNAMICTOP_PTR);
    assert(HEAP32[DYNAMICTOP_PTR>>2] <= TOTAL_MEMORY);
  } else {
    if (dest + bytes > STATICTOP) abort('segmentation fault, exceeded the top of the available static heap when loading ' + bytes + ' bytes from address ' + dest + '. STATICTOP=' + STATICTOP);
  }
  var type = getSafeHeapType(bytes, isFloat);
  var ret = getValue(dest, type, 1);
  if (unsigned) ret = unSign(ret, parseInt(type.substr(1)), 1);
  return ret;
}
function SAFE_HEAP_LOAD_D(dest, bytes, unsigned) {
  return SAFE_HEAP_LOAD(dest, bytes, unsigned, true);
}

function SAFE_FT_MASK(value, mask) {
  var ret = value & mask;
  if (ret !== value) {
    abort('Function table mask error: function pointer is ' + value + ' which is masked by ' + mask + ', the likely cause of this is that the function pointer is being called by the wrong type.');
  }
  return ret;
}

function segfault() {
  abort('segmentation fault');
}
function alignfault() {
  abort('alignment fault');
}
function ftfault() {
  abort('Function table mask error');
}

//========================================
// Runtime essentials
//========================================

var ABORT = 0; // whether we are quitting the application. no code should run after this. set in exit() and abort()
var EXITSTATUS = 0;

/** @type {function(*, string=)} */
function assert(condition, text) {
  if (!condition) {
    abort('Assertion failed: ' + text);
  }
}

var globalScope = this;

// Returns the C function with a specified identifier (for C++, you need to do manual name mangling)
function getCFunc(ident) {
  var func = Module['_' + ident]; // closure exported function
  if (!func) {
    try { func = eval('_' + ident); } catch(e) {}
  }
  assert(func, 'Cannot call unknown function ' + ident + ' (perhaps LLVM optimizations or closure removed it?)');
  return func;
}

var cwrap, ccall;
(function(){
  var JSfuncs = {
    // Helpers for cwrap -- it can't refer to Runtime directly because it might
    // be renamed by closure, instead it calls JSfuncs['stackSave'].body to find
    // out what the minified function name is.
    'stackSave': function() {
      Runtime.stackSave()
    },
    'stackRestore': function() {
      Runtime.stackRestore()
    },
    // type conversion from js to c
    'arrayToC' : function(arr) {
      var ret = Runtime.stackAlloc(arr.length);
      writeArrayToMemory(arr, ret);
      return ret;
    },
    'stringToC' : function(str) {
      var ret = 0;
      if (str !== null && str !== undefined && str !== 0) { // null string
        // at most 4 bytes per UTF-8 code point, +1 for the trailing '\0'
        var len = (str.length << 2) + 1;
        ret = Runtime.stackAlloc(len);
        stringToUTF8(str, ret, len);
      }
      return ret;
    }
  };
  // For fast lookup of conversion functions
  var toC = {'string' : JSfuncs['stringToC'], 'array' : JSfuncs['arrayToC']};

  // C calling interface.
  ccall = function ccallFunc(ident, returnType, argTypes, args, opts) {
    var func = getCFunc(ident);
    var cArgs = [];
    var stack = 0;
    assert(returnType !== 'array', 'Return type should not be "array".');
    if (args) {
      for (var i = 0; i < args.length; i++) {
        var converter = toC[argTypes[i]];
        if (converter) {
          if (stack === 0) stack = Runtime.stackSave();
          cArgs[i] = converter(args[i]);
        } else {
          cArgs[i] = args[i];
        }
      }
    }
    var ret = func.apply(null, cArgs);
    if ((!opts || !opts.async) && typeof EmterpreterAsync === 'object') {
      assert(!EmterpreterAsync.state, 'cannot start async op with normal JS calling ccall');
    }
    if (opts && opts.async) assert(!returnType, 'async ccalls cannot return values');
    if (returnType === 'string') ret = Pointer_stringify(ret);
    if (stack !== 0) {
      if (opts && opts.async) {
        EmterpreterAsync.asyncFinalizers.push(function() {
          Runtime.stackRestore(stack);
        });
        return;
      }
      Runtime.stackRestore(stack);
    }
    return ret;
  }

  var sourceRegex = /^function\s*[a-zA-Z$_0-9]*\s*\(([^)]*)\)\s*{\s*([^*]*?)[\s;]*(?:return\s*(.*?)[;\s]*)?}$/;
  function parseJSFunc(jsfunc) {
    // Match the body and the return value of a javascript function source
    var parsed = jsfunc.toString().match(sourceRegex).slice(1);
    return {arguments : parsed[0], body : parsed[1], returnValue: parsed[2]}
  }

  // sources of useful functions. we create this lazily as it can trigger a source decompression on this entire file
  var JSsource = null;
  function ensureJSsource() {
    if (!JSsource) {
      JSsource = {};
      for (var fun in JSfuncs) {
        if (JSfuncs.hasOwnProperty(fun)) {
          // Elements of toCsource are arrays of three items:
          // the code, and the return value
          JSsource[fun] = parseJSFunc(JSfuncs[fun]);
        }
      }
    }
  }

  cwrap = function cwrap(ident, returnType, argTypes) {
    argTypes = argTypes || [];
    var cfunc = getCFunc(ident);
    // When the function takes numbers and returns a number, we can just return
    // the original function
    var numericArgs = argTypes.every(function(type){ return type === 'number'});
    var numericRet = (returnType !== 'string');
    if ( numericRet && numericArgs) {
      return cfunc;
    }
    // Creation of the arguments list (["$1","$2",...,"$nargs"])
    var argNames = argTypes.map(function(x,i){return '$'+i});
    var funcstr = "(function(" + argNames.join(',') + ") {";
    var nargs = argTypes.length;
    if (!numericArgs) {
      // Generate the code needed to convert the arguments from javascript
      // values to pointers
      ensureJSsource();
      funcstr += 'var stack = ' + JSsource['stackSave'].body + ';';
      for (var i = 0; i < nargs; i++) {
        var arg = argNames[i], type = argTypes[i];
        if (type === 'number') continue;
        var convertCode = JSsource[type + 'ToC']; // [code, return]
        funcstr += 'var ' + convertCode.arguments + ' = ' + arg + ';';
        funcstr += convertCode.body + ';';
        funcstr += arg + '=(' + convertCode.returnValue + ');';
      }
    }

    // When the code is compressed, the name of cfunc is not literally 'cfunc' anymore
    var cfuncname = parseJSFunc(function(){return cfunc}).returnValue;
    // Call the function
    funcstr += 'var ret = ' + cfuncname + '(' + argNames.join(',') + ');';
    if (!numericRet) { // Return type can only by 'string' or 'number'
      // Convert the result to a string
      var strgfy = parseJSFunc(function(){return Pointer_stringify}).returnValue;
      funcstr += 'ret = ' + strgfy + '(ret);';
    }
    funcstr += "if (typeof EmterpreterAsync === 'object') { assert(!EmterpreterAsync.state, 'cannot start async op with normal JS calling cwrap') }";
    if (!numericArgs) {
      // If we had a stack, restore it
      ensureJSsource();
      funcstr += JSsource['stackRestore'].body.replace('()', '(stack)') + ';';
    }
    funcstr += 'return ret})';
    return eval(funcstr);
  };
})();
Module["ccall"] = ccall;
Module["cwrap"] = cwrap;

/** @type {function(number, number, string, boolean=)} */
function setValue(ptr, value, type, noSafe) {
  type = type || 'i8';
  if (type.charAt(type.length-1) === '*') type = 'i32'; // pointers are 32-bit
  if (noSafe) {
    switch(type) {
      case 'i1': HEAP8[((ptr)>>0)]=value; break;
      case 'i8': HEAP8[((ptr)>>0)]=value; break;
      case 'i16': HEAP16[((ptr)>>1)]=value; break;
      case 'i32': HEAP32[((ptr)>>2)]=value; break;
      case 'i64': (tempI64 = [value>>>0,(tempDouble=value,(+(Math_abs(tempDouble))) >= (+1) ? (tempDouble > (+0) ? ((Math_min((+(Math_floor((tempDouble)/(+4294967296)))), (+4294967295)))|0)>>>0 : (~~((+(Math_ceil((tempDouble - +(((~~(tempDouble)))>>>0))/(+4294967296))))))>>>0) : 0)],HEAP32[((ptr)>>2)]=tempI64[0],HEAP32[(((ptr)+(4))>>2)]=tempI64[1]); break;
      case 'float': HEAPF32[((ptr)>>2)]=value; break;
      case 'double': HEAPF64[((ptr)>>3)]=value; break;
      default: abort('invalid type for setValue: ' + type);
    }
  } else {
    switch(type) {
      case 'i1': SAFE_HEAP_STORE(((ptr)|0), ((value)|0), 1); break;
      case 'i8': SAFE_HEAP_STORE(((ptr)|0), ((value)|0), 1); break;
      case 'i16': SAFE_HEAP_STORE(((ptr)|0), ((value)|0), 2); break;
      case 'i32': SAFE_HEAP_STORE(((ptr)|0), ((value)|0), 4); break;
      case 'i64': (tempI64 = [value>>>0,(tempDouble=value,(+(Math_abs(tempDouble))) >= (+1) ? (tempDouble > (+0) ? ((Math_min((+(Math_floor((tempDouble)/(+4294967296)))), (+4294967295)))|0)>>>0 : (~~((+(Math_ceil((tempDouble - +(((~~(tempDouble)))>>>0))/(+4294967296))))))>>>0) : 0)],SAFE_HEAP_STORE(((ptr)|0), ((tempI64[0])|0), 4),SAFE_HEAP_STORE((((ptr)+(4))|0), ((tempI64[1])|0), 4)); break;
      case 'float': SAFE_HEAP_STORE_D(((ptr)|0), (+(value)), 4); break;
      case 'double': SAFE_HEAP_STORE_D(((ptr)|0), (+(value)), 8); break;
      default: abort('invalid type for setValue: ' + type);
    }
  }
}
Module["setValue"] = setValue;

/** @type {function(number, string, boolean=)} */
function getValue(ptr, type, noSafe) {
  type = type || 'i8';
  if (type.charAt(type.length-1) === '*') type = 'i32'; // pointers are 32-bit
  if (noSafe) {
    switch(type) {
      case 'i1': return HEAP8[((ptr)>>0)];
      case 'i8': return HEAP8[((ptr)>>0)];
      case 'i16': return HEAP16[((ptr)>>1)];
      case 'i32': return HEAP32[((ptr)>>2)];
      case 'i64': return HEAP32[((ptr)>>2)];
      case 'float': return HEAPF32[((ptr)>>2)];
      case 'double': return HEAPF64[((ptr)>>3)];
      default: abort('invalid type for setValue: ' + type);
    }
  } else {
    switch(type) {
      case 'i1': return ((SAFE_HEAP_LOAD(((ptr)|0), 1, 0))|0);
      case 'i8': return ((SAFE_HEAP_LOAD(((ptr)|0), 1, 0))|0);
      case 'i16': return ((SAFE_HEAP_LOAD(((ptr)|0), 2, 0))|0);
      case 'i32': return ((SAFE_HEAP_LOAD(((ptr)|0), 4, 0))|0);
      case 'i64': return ((SAFE_HEAP_LOAD(((ptr)|0), 8, 0))|0);
      case 'float': return (+(SAFE_HEAP_LOAD_D(((ptr)|0), 4, 0)));
      case 'double': return (+(SAFE_HEAP_LOAD_D(((ptr)|0), 8, 0)));
      default: abort('invalid type for setValue: ' + type);
    }
  }
  return null;
}
Module["getValue"] = getValue;

var ALLOC_NORMAL = 0; // Tries to use _malloc()
var ALLOC_STACK = 1; // Lives for the duration of the current function call
var ALLOC_STATIC = 2; // Cannot be freed
var ALLOC_DYNAMIC = 3; // Cannot be freed except through sbrk
var ALLOC_NONE = 4; // Do not allocate
Module["ALLOC_NORMAL"] = ALLOC_NORMAL;
Module["ALLOC_STACK"] = ALLOC_STACK;
Module["ALLOC_STATIC"] = ALLOC_STATIC;
Module["ALLOC_DYNAMIC"] = ALLOC_DYNAMIC;
Module["ALLOC_NONE"] = ALLOC_NONE;

// allocate(): This is for internal use. You can use it yourself as well, but the interface
//             is a little tricky (see docs right below). The reason is that it is optimized
//             for multiple syntaxes to save space in generated code. So you should
//             normally not use allocate(), and instead allocate memory using _malloc(),
//             initialize it with setValue(), and so forth.
// @slab: An array of data, or a number. If a number, then the size of the block to allocate,
//        in *bytes* (note that this is sometimes confusing: the next parameter does not
//        affect this!)
// @types: Either an array of types, one for each byte (or 0 if no type at that position),
//         or a single type which is used for the entire block. This only matters if there
//         is initial data - if @slab is a number, then this does not matter at all and is
//         ignored.
// @allocator: How to allocate memory, see ALLOC_*
/** @type {function((TypedArray|Array<number>|number), string, number, number=)} */
function allocate(slab, types, allocator, ptr) {
  var zeroinit, size;
  if (typeof slab === 'number') {
    zeroinit = true;
    size = slab;
  } else {
    zeroinit = false;
    size = slab.length;
  }

  var singleType = typeof types === 'string' ? types : null;

  var ret;
  if (allocator == ALLOC_NONE) {
    ret = ptr;
  } else {
    ret = [typeof _malloc === 'function' ? _malloc : Runtime.staticAlloc, Runtime.stackAlloc, Runtime.staticAlloc, Runtime.dynamicAlloc][allocator === undefined ? ALLOC_STATIC : allocator](Math.max(size, singleType ? 1 : types.length));
  }

  if (zeroinit) {
    var ptr = ret, stop;
    assert((ret & 3) == 0);
    stop = ret + (size & ~3);
    for (; ptr < stop; ptr += 4) {
      HEAP32[((ptr)>>2)]=0;
    }
    stop = ret + size;
    while (ptr < stop) {
      HEAP8[((ptr++)>>0)]=0;
    }
    return ret;
  }

  if (singleType === 'i8') {
    if (slab.subarray || slab.slice) {
      HEAPU8.set(/** @type {!Uint8Array} */ (slab), ret);
    } else {
      HEAPU8.set(new Uint8Array(slab), ret);
    }
    return ret;
  }

  var i = 0, type, typeSize, previousType;
  while (i < size) {
    var curr = slab[i];

    if (typeof curr === 'function') {
      curr = Runtime.getFunctionIndex(curr);
    }

    type = singleType || types[i];
    if (type === 0) {
      i++;
      continue;
    }
    assert(type, 'Must know what type to store in allocate!');

    if (type == 'i64') type = 'i32'; // special case: we have one i32 here, and one i32 later

    setValue(ret+i, curr, type);

    // no need to look up size unless type changes, so cache it
    if (previousType !== type) {
      typeSize = Runtime.getNativeTypeSize(type);
      previousType = type;
    }
    i += typeSize;
  }

  return ret;
}
Module["allocate"] = allocate;

// Allocate memory during any stage of startup - static memory early on, dynamic memory later, malloc when ready
function getMemory(size) {
  if (!staticSealed) return Runtime.staticAlloc(size);
  if (!runtimeInitialized) return Runtime.dynamicAlloc(size);
  return _malloc(size);
}
Module["getMemory"] = getMemory;

/** @type {function(number, number=)} */
function Pointer_stringify(ptr, length) {
  if (length === 0 || !ptr) return '';
  // TODO: use TextDecoder
  // Find the length, and check for UTF while doing so
  var hasUtf = 0;
  var t;
  var i = 0;
  while (1) {
    assert(ptr + i < TOTAL_MEMORY);
    t = ((SAFE_HEAP_LOAD((((ptr)+(i))|0), 1, 1))|0);
    hasUtf |= t;
    if (t == 0 && !length) break;
    i++;
    if (length && i == length) break;
  }
  if (!length) length = i;

  var ret = '';

  if (hasUtf < 128) {
    var MAX_CHUNK = 1024; // split up into chunks, because .apply on a huge string can overflow the stack
    var curr;
    while (length > 0) {
      curr = String.fromCharCode.apply(String, HEAPU8.subarray(ptr, ptr + Math.min(length, MAX_CHUNK)));
      ret = ret ? ret + curr : curr;
      ptr += MAX_CHUNK;
      length -= MAX_CHUNK;
    }
    return ret;
  }
  return Module['UTF8ToString'](ptr);
}
Module["Pointer_stringify"] = Pointer_stringify;

// Given a pointer 'ptr' to a null-terminated ASCII-encoded string in the emscripten HEAP, returns
// a copy of that string as a Javascript String object.

function AsciiToString(ptr) {
  var str = '';
  while (1) {
    var ch = ((SAFE_HEAP_LOAD(((ptr++)|0), 1, 0))|0);
    if (!ch) return str;
    str += String.fromCharCode(ch);
  }
}
Module["AsciiToString"] = AsciiToString;

// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in ASCII form. The copy will require at most str.length+1 bytes of space in the HEAP.

function stringToAscii(str, outPtr) {
  return writeAsciiToMemory(str, outPtr, false);
}
Module["stringToAscii"] = stringToAscii;

// Given a pointer 'ptr' to a null-terminated UTF8-encoded string in the given array that contains uint8 values, returns
// a copy of that string as a Javascript String object.

var UTF8Decoder = typeof TextDecoder !== 'undefined' ? new TextDecoder('utf8') : undefined;
function UTF8ArrayToString(u8Array, idx) {
  var endPtr = idx;
  // TextDecoder needs to know the byte length in advance, it doesn't stop on null terminator by itself.
  // Also, use the length info to avoid running tiny strings through TextDecoder, since .subarray() allocates garbage.
  while (u8Array[endPtr]) ++endPtr;

  if (endPtr - idx > 16 && u8Array.subarray && UTF8Decoder) {
    return UTF8Decoder.decode(u8Array.subarray(idx, endPtr));
  } else {
    var u0, u1, u2, u3, u4, u5;

    var str = '';
    while (1) {
      // For UTF8 byte structure, see http://en.wikipedia.org/wiki/UTF-8#Description and https://www.ietf.org/rfc/rfc2279.txt and https://tools.ietf.org/html/rfc3629
      u0 = u8Array[idx++];
      if (!u0) return str;
      if (!(u0 & 0x80)) { str += String.fromCharCode(u0); continue; }
      u1 = u8Array[idx++] & 63;
      if ((u0 & 0xE0) == 0xC0) { str += String.fromCharCode(((u0 & 31) << 6) | u1); continue; }
      u2 = u8Array[idx++] & 63;
      if ((u0 & 0xF0) == 0xE0) {
        u0 = ((u0 & 15) << 12) | (u1 << 6) | u2;
      } else {
        u3 = u8Array[idx++] & 63;
        if ((u0 & 0xF8) == 0xF0) {
          u0 = ((u0 & 7) << 18) | (u1 << 12) | (u2 << 6) | u3;
        } else {
          u4 = u8Array[idx++] & 63;
          if ((u0 & 0xFC) == 0xF8) {
            u0 = ((u0 & 3) << 24) | (u1 << 18) | (u2 << 12) | (u3 << 6) | u4;
          } else {
            u5 = u8Array[idx++] & 63;
            u0 = ((u0 & 1) << 30) | (u1 << 24) | (u2 << 18) | (u3 << 12) | (u4 << 6) | u5;
          }
        }
      }
      if (u0 < 0x10000) {
        str += String.fromCharCode(u0);
      } else {
        var ch = u0 - 0x10000;
        str += String.fromCharCode(0xD800 | (ch >> 10), 0xDC00 | (ch & 0x3FF));
      }
    }
  }
}
Module["UTF8ArrayToString"] = UTF8ArrayToString;

// Given a pointer 'ptr' to a null-terminated UTF8-encoded string in the emscripten HEAP, returns
// a copy of that string as a Javascript String object.

function UTF8ToString(ptr) {
  return UTF8ArrayToString(HEAPU8,ptr);
}
Module["UTF8ToString"] = UTF8ToString;

// Copies the given Javascript String object 'str' to the given byte array at address 'outIdx',
// encoded in UTF8 form and null-terminated. The copy will require at most str.length*4+1 bytes of space in the HEAP.
// Use the function lengthBytesUTF8 to compute the exact number of bytes (excluding null terminator) that this function will write.
// Parameters:
//   str: the Javascript string to copy.
//   outU8Array: the array to copy to. Each index in this array is assumed to be one 8-byte element.
//   outIdx: The starting offset in the array to begin the copying.
//   maxBytesToWrite: The maximum number of bytes this function can write to the array. This count should include the null
//                    terminator, i.e. if maxBytesToWrite=1, only the null terminator will be written and nothing else.
//                    maxBytesToWrite=0 does not write any bytes to the output, not even the null terminator.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF8Array(str, outU8Array, outIdx, maxBytesToWrite) {
  if (!(maxBytesToWrite > 0)) // Parameter maxBytesToWrite is not optional. Negative values, 0, null, undefined and false each don't write out any bytes.
    return 0;

  var startIdx = outIdx;
  var endIdx = outIdx + maxBytesToWrite - 1; // -1 for string null terminator.
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! So decode UTF16->UTF32->UTF8.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    // For UTF8 byte structure, see http://en.wikipedia.org/wiki/UTF-8#Description and https://www.ietf.org/rfc/rfc2279.txt and https://tools.ietf.org/html/rfc3629
    var u = str.charCodeAt(i); // possibly a lead surrogate
    if (u >= 0xD800 && u <= 0xDFFF) u = 0x10000 + ((u & 0x3FF) << 10) | (str.charCodeAt(++i) & 0x3FF);
    if (u <= 0x7F) {
      if (outIdx >= endIdx) break;
      outU8Array[outIdx++] = u;
    } else if (u <= 0x7FF) {
      if (outIdx + 1 >= endIdx) break;
      outU8Array[outIdx++] = 0xC0 | (u >> 6);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else if (u <= 0xFFFF) {
      if (outIdx + 2 >= endIdx) break;
      outU8Array[outIdx++] = 0xE0 | (u >> 12);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else if (u <= 0x1FFFFF) {
      if (outIdx + 3 >= endIdx) break;
      outU8Array[outIdx++] = 0xF0 | (u >> 18);
      outU8Array[outIdx++] = 0x80 | ((u >> 12) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else if (u <= 0x3FFFFFF) {
      if (outIdx + 4 >= endIdx) break;
      outU8Array[outIdx++] = 0xF8 | (u >> 24);
      outU8Array[outIdx++] = 0x80 | ((u >> 18) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 12) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    } else {
      if (outIdx + 5 >= endIdx) break;
      outU8Array[outIdx++] = 0xFC | (u >> 30);
      outU8Array[outIdx++] = 0x80 | ((u >> 24) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 18) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 12) & 63);
      outU8Array[outIdx++] = 0x80 | ((u >> 6) & 63);
      outU8Array[outIdx++] = 0x80 | (u & 63);
    }
  }
  // Null-terminate the pointer to the buffer.
  outU8Array[outIdx] = 0;
  return outIdx - startIdx;
}
Module["stringToUTF8Array"] = stringToUTF8Array;

// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in UTF8 form. The copy will require at most str.length*4+1 bytes of space in the HEAP.
// Use the function lengthBytesUTF8 to compute the exact number of bytes (excluding null terminator) that this function will write.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF8(str, outPtr, maxBytesToWrite) {
  assert(typeof maxBytesToWrite == 'number', 'stringToUTF8(str, outPtr, maxBytesToWrite) is missing the third parameter that specifies the length of the output buffer!');
  return stringToUTF8Array(str, HEAPU8,outPtr, maxBytesToWrite);
}
Module["stringToUTF8"] = stringToUTF8;

// Returns the number of bytes the given Javascript string takes if encoded as a UTF8 byte array, EXCLUDING the null terminator byte.

function lengthBytesUTF8(str) {
  var len = 0;
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! So decode UTF16->UTF32->UTF8.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    var u = str.charCodeAt(i); // possibly a lead surrogate
    if (u >= 0xD800 && u <= 0xDFFF) u = 0x10000 + ((u & 0x3FF) << 10) | (str.charCodeAt(++i) & 0x3FF);
    if (u <= 0x7F) {
      ++len;
    } else if (u <= 0x7FF) {
      len += 2;
    } else if (u <= 0xFFFF) {
      len += 3;
    } else if (u <= 0x1FFFFF) {
      len += 4;
    } else if (u <= 0x3FFFFFF) {
      len += 5;
    } else {
      len += 6;
    }
  }
  return len;
}
Module["lengthBytesUTF8"] = lengthBytesUTF8;

// Given a pointer 'ptr' to a null-terminated UTF16LE-encoded string in the emscripten HEAP, returns
// a copy of that string as a Javascript String object.

var UTF16Decoder = typeof TextDecoder !== 'undefined' ? new TextDecoder('utf-16le') : undefined;
function UTF16ToString(ptr) {
  assert(ptr % 2 == 0, 'Pointer passed to UTF16ToString must be aligned to two bytes!');
  var endPtr = ptr;
  // TextDecoder needs to know the byte length in advance, it doesn't stop on null terminator by itself.
  // Also, use the length info to avoid running tiny strings through TextDecoder, since .subarray() allocates garbage.
  var idx = endPtr >> 1;
  while (HEAP16[idx]) ++idx;
  endPtr = idx << 1;

  if (endPtr - ptr > 32 && UTF16Decoder) {
    return UTF16Decoder.decode(HEAPU8.subarray(ptr, endPtr));
  } else {
    var i = 0;

    var str = '';
    while (1) {
      var codeUnit = ((SAFE_HEAP_LOAD((((ptr)+(i*2))|0), 2, 0))|0);
      if (codeUnit == 0) return str;
      ++i;
      // fromCharCode constructs a character from a UTF-16 code unit, so we can pass the UTF16 string right through.
      str += String.fromCharCode(codeUnit);
    }
  }
}


// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in UTF16 form. The copy will require at most str.length*4+2 bytes of space in the HEAP.
// Use the function lengthBytesUTF16() to compute the exact number of bytes (excluding null terminator) that this function will write.
// Parameters:
//   str: the Javascript string to copy.
//   outPtr: Byte address in Emscripten HEAP where to write the string to.
//   maxBytesToWrite: The maximum number of bytes this function can write to the array. This count should include the null
//                    terminator, i.e. if maxBytesToWrite=2, only the null terminator will be written and nothing else.
//                    maxBytesToWrite<2 does not write any bytes to the output, not even the null terminator.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF16(str, outPtr, maxBytesToWrite) {
  assert(outPtr % 2 == 0, 'Pointer passed to stringToUTF16 must be aligned to two bytes!');
  assert(typeof maxBytesToWrite == 'number', 'stringToUTF16(str, outPtr, maxBytesToWrite) is missing the third parameter that specifies the length of the output buffer!');
  // Backwards compatibility: if max bytes is not specified, assume unsafe unbounded write is allowed.
  if (maxBytesToWrite === undefined) {
    maxBytesToWrite = 0x7FFFFFFF;
  }
  if (maxBytesToWrite < 2) return 0;
  maxBytesToWrite -= 2; // Null terminator.
  var startPtr = outPtr;
  var numCharsToWrite = (maxBytesToWrite < str.length*2) ? (maxBytesToWrite / 2) : str.length;
  for (var i = 0; i < numCharsToWrite; ++i) {
    // charCodeAt returns a UTF-16 encoded code unit, so it can be directly written to the HEAP.
    var codeUnit = str.charCodeAt(i); // possibly a lead surrogate
    SAFE_HEAP_STORE(((outPtr)|0), ((codeUnit)|0), 2);
    outPtr += 2;
  }
  // Null-terminate the pointer to the HEAP.
  SAFE_HEAP_STORE(((outPtr)|0), ((0)|0), 2);
  return outPtr - startPtr;
}


// Returns the number of bytes the given Javascript string takes if encoded as a UTF16 byte array, EXCLUDING the null terminator byte.

function lengthBytesUTF16(str) {
  return str.length*2;
}


function UTF32ToString(ptr) {
  assert(ptr % 4 == 0, 'Pointer passed to UTF32ToString must be aligned to four bytes!');
  var i = 0;

  var str = '';
  while (1) {
    var utf32 = ((SAFE_HEAP_LOAD((((ptr)+(i*4))|0), 4, 0))|0);
    if (utf32 == 0)
      return str;
    ++i;
    // Gotcha: fromCharCode constructs a character from a UTF-16 encoded code (pair), not from a Unicode code point! So encode the code point to UTF-16 for constructing.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    if (utf32 >= 0x10000) {
      var ch = utf32 - 0x10000;
      str += String.fromCharCode(0xD800 | (ch >> 10), 0xDC00 | (ch & 0x3FF));
    } else {
      str += String.fromCharCode(utf32);
    }
  }
}


// Copies the given Javascript String object 'str' to the emscripten HEAP at address 'outPtr',
// null-terminated and encoded in UTF32 form. The copy will require at most str.length*4+4 bytes of space in the HEAP.
// Use the function lengthBytesUTF32() to compute the exact number of bytes (excluding null terminator) that this function will write.
// Parameters:
//   str: the Javascript string to copy.
//   outPtr: Byte address in Emscripten HEAP where to write the string to.
//   maxBytesToWrite: The maximum number of bytes this function can write to the array. This count should include the null
//                    terminator, i.e. if maxBytesToWrite=4, only the null terminator will be written and nothing else.
//                    maxBytesToWrite<4 does not write any bytes to the output, not even the null terminator.
// Returns the number of bytes written, EXCLUDING the null terminator.

function stringToUTF32(str, outPtr, maxBytesToWrite) {
  assert(outPtr % 4 == 0, 'Pointer passed to stringToUTF32 must be aligned to four bytes!');
  assert(typeof maxBytesToWrite == 'number', 'stringToUTF32(str, outPtr, maxBytesToWrite) is missing the third parameter that specifies the length of the output buffer!');
  // Backwards compatibility: if max bytes is not specified, assume unsafe unbounded write is allowed.
  if (maxBytesToWrite === undefined) {
    maxBytesToWrite = 0x7FFFFFFF;
  }
  if (maxBytesToWrite < 4) return 0;
  var startPtr = outPtr;
  var endPtr = startPtr + maxBytesToWrite - 4;
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! We must decode the string to UTF-32 to the heap.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    var codeUnit = str.charCodeAt(i); // possibly a lead surrogate
    if (codeUnit >= 0xD800 && codeUnit <= 0xDFFF) {
      var trailSurrogate = str.charCodeAt(++i);
      codeUnit = 0x10000 + ((codeUnit & 0x3FF) << 10) | (trailSurrogate & 0x3FF);
    }
    SAFE_HEAP_STORE(((outPtr)|0), ((codeUnit)|0), 4);
    outPtr += 4;
    if (outPtr + 4 > endPtr) break;
  }
  // Null-terminate the pointer to the HEAP.
  SAFE_HEAP_STORE(((outPtr)|0), ((0)|0), 4);
  return outPtr - startPtr;
}


// Returns the number of bytes the given Javascript string takes if encoded as a UTF16 byte array, EXCLUDING the null terminator byte.

function lengthBytesUTF32(str) {
  var len = 0;
  for (var i = 0; i < str.length; ++i) {
    // Gotcha: charCodeAt returns a 16-bit word that is a UTF-16 encoded code unit, not a Unicode code point of the character! We must decode the string to UTF-32 to the heap.
    // See http://unicode.org/faq/utf_bom.html#utf16-3
    var codeUnit = str.charCodeAt(i);
    if (codeUnit >= 0xD800 && codeUnit <= 0xDFFF) ++i; // possibly a lead surrogate, so skip over the tail surrogate.
    len += 4;
  }

  return len;
}


function demangle(func) {
  var __cxa_demangle_func = Module['___cxa_demangle'] || Module['__cxa_demangle'];
  if (__cxa_demangle_func) {
    try {
      var s =
        func.substr(1);
      var len = lengthBytesUTF8(s)+1;
      var buf = _malloc(len);
      stringToUTF8(s, buf, len);
      var status = _malloc(4);
      var ret = __cxa_demangle_func(buf, 0, 0, status);
      if (getValue(status, 'i32') === 0 && ret) {
        return Pointer_stringify(ret);
      }
      // otherwise, libcxxabi failed
    } catch(e) {
      // ignore problems here
    } finally {
      if (buf) _free(buf);
      if (status) _free(status);
      if (ret) _free(ret);
    }
    // failure when using libcxxabi, don't demangle
    return func;
  }
  Runtime.warnOnce('warning: build with  -s DEMANGLE_SUPPORT=1  to link in libcxxabi demangling');
  return func;
}

function demangleAll(text) {
  var regex =
    /__Z[\w\d_]+/g;
  return text.replace(regex,
    function(x) {
      var y = demangle(x);
      return x === y ? x : (x + ' [' + y + ']');
    });
}

function jsStackTrace() {
  var err = new Error();
  if (!err.stack) {
    // IE10+ special cases: It does have callstack info, but it is only populated if an Error object is thrown,
    // so try that as a special-case.
    try {
      throw new Error(0);
    } catch(e) {
      err = e;
    }
    if (!err.stack) {
      return '(no stack trace available)';
    }
  }
  return err.stack.toString();
}

function stackTrace() {
  var js = jsStackTrace();
  if (Module['extraStackTrace']) js += '\n' + Module['extraStackTrace']();
  return demangleAll(js);
}
Module["stackTrace"] = stackTrace;

// Memory management

var PAGE_SIZE = 16384;
var WASM_PAGE_SIZE = 65536;
var ASMJS_PAGE_SIZE = 16777216;
var MIN_TOTAL_MEMORY = 16777216;

function alignUp(x, multiple) {
  if (x % multiple > 0) {
    x += multiple - (x % multiple);
  }
  return x;
}

var HEAP,
/** @type {ArrayBuffer} */
  buffer,
/** @type {Int8Array} */
  HEAP8,
/** @type {Uint8Array} */
  HEAPU8,
/** @type {Int16Array} */
  HEAP16,
/** @type {Uint16Array} */
  HEAPU16,
/** @type {Int32Array} */
  HEAP32,
/** @type {Uint32Array} */
  HEAPU32,
/** @type {Float32Array} */
  HEAPF32,
/** @type {Float64Array} */
  HEAPF64;

function updateGlobalBuffer(buf) {
  Module['buffer'] = buffer = buf;
}

function updateGlobalBufferViews() {
  Module['HEAP8'] = HEAP8 = new Int8Array(buffer);
  Module['HEAP16'] = HEAP16 = new Int16Array(buffer);
  Module['HEAP32'] = HEAP32 = new Int32Array(buffer);
  Module['HEAPU8'] = HEAPU8 = new Uint8Array(buffer);
  Module['HEAPU16'] = HEAPU16 = new Uint16Array(buffer);
  Module['HEAPU32'] = HEAPU32 = new Uint32Array(buffer);
  Module['HEAPF32'] = HEAPF32 = new Float32Array(buffer);
  Module['HEAPF64'] = HEAPF64 = new Float64Array(buffer);
}

var STATIC_BASE, STATICTOP, staticSealed; // static area
var STACK_BASE, STACKTOP, STACK_MAX; // stack area
var DYNAMIC_BASE, DYNAMICTOP_PTR; // dynamic area handled by sbrk

  STATIC_BASE = STATICTOP = STACK_BASE = STACKTOP = STACK_MAX = DYNAMIC_BASE = DYNAMICTOP_PTR = 0;
  staticSealed = false;


// Initializes the stack cookie. Called at the startup of main and at the startup of each thread in pthreads mode.
function writeStackCookie() {
  assert((STACK_MAX & 3) == 0);
  HEAPU32[(STACK_MAX >> 2)-1] = 0x02135467;
  HEAPU32[(STACK_MAX >> 2)-2] = 0x89BACDFE;
}

function checkStackCookie() {
  if (HEAPU32[(STACK_MAX >> 2)-1] != 0x02135467 || HEAPU32[(STACK_MAX >> 2)-2] != 0x89BACDFE) {
    abort('Stack overflow! Stack cookie has been overwritten, expected hex dwords 0x89BACDFE and 0x02135467, but received 0x' + HEAPU32[(STACK_MAX >> 2)-2].toString(16) + ' ' + HEAPU32[(STACK_MAX >> 2)-1].toString(16));
  }
  // Also test the global address 0 for integrity. This check is not compatible with SAFE_SPLIT_MEMORY though, since that mode already tests all address 0 accesses on its own.
  if (HEAP32[0] !== 0x63736d65 /* 'emsc' */) throw 'Runtime error: The application has corrupted its heap memory area (address zero)!';
}

function abortStackOverflow(allocSize) {
  abort('Stack overflow! Attempted to allocate ' + allocSize + ' bytes on the stack, but stack has only ' + (STACK_MAX - Module['asm'].stackSave() + allocSize) + ' bytes available!');
}

function abortOnCannotGrowMemory() {
  abort('Cannot enlarge memory arrays. Either (1) compile with  -s TOTAL_MEMORY=X  with X higher than the current value ' + TOTAL_MEMORY + ', (2) compile with  -s ALLOW_MEMORY_GROWTH=1  which allows increasing the size at runtime but prevents some optimizations, (3) set Module.TOTAL_MEMORY to a higher value before the program runs, or (4) if you want malloc to return NULL (0) instead of this abort, compile with  -s ABORTING_MALLOC=0 ');
}


function enlargeMemory() {
  abortOnCannotGrowMemory();
}


var TOTAL_STACK = Module['TOTAL_STACK'] || 5242880;
var TOTAL_MEMORY = Module['TOTAL_MEMORY'] || 16777216;
if (TOTAL_MEMORY < TOTAL_STACK) Module.printErr('TOTAL_MEMORY should be larger than TOTAL_STACK, was ' + TOTAL_MEMORY + '! (TOTAL_STACK=' + TOTAL_STACK + ')');

// Initialize the runtime's memory
// check for full engine support (use string 'subarray' to avoid closure compiler confusion)
assert(typeof Int32Array !== 'undefined' && typeof Float64Array !== 'undefined' && Int32Array.prototype.subarray !== undefined && Int32Array.prototype.set !== undefined,
       'JS engine does not provide full typed array support');



// Use a provided buffer, if there is one, or else allocate a new one
if (Module['buffer']) {
  buffer = Module['buffer'];
  assert(buffer.byteLength === TOTAL_MEMORY, 'provided buffer should be ' + TOTAL_MEMORY + ' bytes, but it is ' + buffer.byteLength);
} else {
  // Use a WebAssembly memory where available
  {
    buffer = new ArrayBuffer(TOTAL_MEMORY);
  }
  assert(buffer.byteLength === TOTAL_MEMORY);
}
updateGlobalBufferViews();


function getTotalMemory() {
  return TOTAL_MEMORY;
}

// Endianness check (note: assumes compiler arch was little-endian)
  HEAP32[0] = 0x63736d65; /* 'emsc' */
HEAP16[1] = 0x6373;
if (HEAPU8[2] !== 0x73 || HEAPU8[3] !== 0x63) throw 'Runtime error: expected the system to be little-endian!';

Module['HEAP'] = HEAP;
Module['buffer'] = buffer;
Module['HEAP8'] = HEAP8;
Module['HEAP16'] = HEAP16;
Module['HEAP32'] = HEAP32;
Module['HEAPU8'] = HEAPU8;
Module['HEAPU16'] = HEAPU16;
Module['HEAPU32'] = HEAPU32;
Module['HEAPF32'] = HEAPF32;
Module['HEAPF64'] = HEAPF64;

function callRuntimeCallbacks(callbacks) {
  while(callbacks.length > 0) {
    var callback = callbacks.shift();
    if (typeof callback == 'function') {
      callback();
      continue;
    }
    var func = callback.func;
    if (typeof func === 'number') {
      if (callback.arg === undefined) {
        Module['dynCall_v'](func);
      } else {
        Module['dynCall_vi'](func, callback.arg);
      }
    } else {
      func(callback.arg === undefined ? null : callback.arg);
    }
  }
}

var __ATPRERUN__  = []; // functions called before the runtime is initialized
var __ATINIT__    = []; // functions called during startup
var __ATMAIN__    = []; // functions called when main() is to be run
var __ATEXIT__    = []; // functions called during shutdown
var __ATPOSTRUN__ = []; // functions called after the runtime has exited

var runtimeInitialized = false;
var runtimeExited = false;


function preRun() {
  // compatibility - merge in anything from Module['preRun'] at this time
  if (Module['preRun']) {
    if (typeof Module['preRun'] == 'function') Module['preRun'] = [Module['preRun']];
    while (Module['preRun'].length) {
      addOnPreRun(Module['preRun'].shift());
    }
  }
  callRuntimeCallbacks(__ATPRERUN__);
}

function ensureInitRuntime() {
  checkStackCookie();
  if (runtimeInitialized) return;
  runtimeInitialized = true;
  callRuntimeCallbacks(__ATINIT__);
}

function preMain() {
  checkStackCookie();
  callRuntimeCallbacks(__ATMAIN__);
}

function exitRuntime() {
  checkStackCookie();
  callRuntimeCallbacks(__ATEXIT__);
  runtimeExited = true;
}

function postRun() {
  checkStackCookie();
  // compatibility - merge in anything from Module['postRun'] at this time
  if (Module['postRun']) {
    if (typeof Module['postRun'] == 'function') Module['postRun'] = [Module['postRun']];
    while (Module['postRun'].length) {
      addOnPostRun(Module['postRun'].shift());
    }
  }
  callRuntimeCallbacks(__ATPOSTRUN__);
}

function addOnPreRun(cb) {
  __ATPRERUN__.unshift(cb);
}
Module["addOnPreRun"] = addOnPreRun;

function addOnInit(cb) {
  __ATINIT__.unshift(cb);
}
Module["addOnInit"] = addOnInit;

function addOnPreMain(cb) {
  __ATMAIN__.unshift(cb);
}
Module["addOnPreMain"] = addOnPreMain;

function addOnExit(cb) {
  __ATEXIT__.unshift(cb);
}
Module["addOnExit"] = addOnExit;

function addOnPostRun(cb) {
  __ATPOSTRUN__.unshift(cb);
}
Module["addOnPostRun"] = addOnPostRun;

// Tools

/** @type {function(string, boolean=, number=)} */
function intArrayFromString(stringy, dontAddNull, length) {
  var len = length > 0 ? length : lengthBytesUTF8(stringy)+1;
  var u8array = new Array(len);
  var numBytesWritten = stringToUTF8Array(stringy, u8array, 0, u8array.length);
  if (dontAddNull) u8array.length = numBytesWritten;
  return u8array;
}
Module["intArrayFromString"] = intArrayFromString;

function intArrayToString(array) {
  var ret = [];
  for (var i = 0; i < array.length; i++) {
    var chr = array[i];
    if (chr > 0xFF) {
      assert(false, 'Character code ' + chr + ' (' + String.fromCharCode(chr) + ')  at offset ' + i + ' not in 0x00-0xFF.');
      chr &= 0xFF;
    }
    ret.push(String.fromCharCode(chr));
  }
  return ret.join('');
}
Module["intArrayToString"] = intArrayToString;

// Deprecated: This function should not be called because it is unsafe and does not provide
// a maximum length limit of how many bytes it is allowed to write. Prefer calling the
// function stringToUTF8Array() instead, which takes in a maximum length that can be used
// to be secure from out of bounds writes.
/** @deprecated */
function writeStringToMemory(string, buffer, dontAddNull) {
  Runtime.warnOnce('writeStringToMemory is deprecated and should not be called! Use stringToUTF8() instead!');

  var /** @type {number} */ lastChar, /** @type {number} */ end;
  if (dontAddNull) {
    // stringToUTF8Array always appends null. If we don't want to do that, remember the
    // character that existed at the location where the null will be placed, and restore
    // that after the write (below).
    end = buffer + lengthBytesUTF8(string);
    lastChar = HEAP8[end];
  }
  stringToUTF8(string, buffer, Infinity);
  if (dontAddNull) HEAP8[end] = lastChar; // Restore the value under the null character.
}
Module["writeStringToMemory"] = writeStringToMemory;

function writeArrayToMemory(array, buffer) {
  assert(array.length >= 0, 'writeArrayToMemory array must have a length (should be an array or typed array)')
  HEAP8.set(array, buffer);
}
Module["writeArrayToMemory"] = writeArrayToMemory;

function writeAsciiToMemory(str, buffer, dontAddNull) {
  for (var i = 0; i < str.length; ++i) {
    assert(str.charCodeAt(i) === str.charCodeAt(i)&0xff);
    SAFE_HEAP_STORE(((buffer++)|0), ((str.charCodeAt(i))|0), 1);
  }
  // Null-terminate the pointer to the HEAP.
  if (!dontAddNull) SAFE_HEAP_STORE(((buffer)|0), ((0)|0), 1);
}
Module["writeAsciiToMemory"] = writeAsciiToMemory;

function unSign(value, bits, ignore) {
  if (value >= 0) {
    return value;
  }
  return bits <= 32 ? 2*Math.abs(1 << (bits-1)) + value // Need some trickery, since if bits == 32, we are right at the limit of the bits JS uses in bitshifts
                    : Math.pow(2, bits)         + value;
}
function reSign(value, bits, ignore) {
  if (value <= 0) {
    return value;
  }
  var half = bits <= 32 ? Math.abs(1 << (bits-1)) // abs is needed if bits == 32
                        : Math.pow(2, bits-1);
  if (value >= half && (bits <= 32 || value > half)) { // for huge values, we can hit the precision limit and always get true here. so don't do that
                                                       // but, in general there is no perfect solution here. With 64-bit ints, we get rounding and errors
                                                       // TODO: In i64 mode 1, resign the two parts separately and safely
    value = -2*half + value; // Cannot bitshift half, as it may be at the limit of the bits JS uses in bitshifts
  }
  return value;
}

// check for imul support, and also for correctness ( https://bugs.webkit.org/show_bug.cgi?id=126345 )
if (!Math['imul'] || Math['imul'](0xffffffff, 5) !== -5) Math['imul'] = function imul(a, b) {
  var ah  = a >>> 16;
  var al = a & 0xffff;
  var bh  = b >>> 16;
  var bl = b & 0xffff;
  return (al*bl + ((ah*bl + al*bh) << 16))|0;
};
Math.imul = Math['imul'];


if (!Math['clz32']) Math['clz32'] = function(x) {
  x = x >>> 0;
  for (var i = 0; i < 32; i++) {
    if (x & (1 << (31 - i))) return i;
  }
  return 32;
};
Math.clz32 = Math['clz32']

if (!Math['trunc']) Math['trunc'] = function(x) {
  return x < 0 ? Math.ceil(x) : Math.floor(x);
};
Math.trunc = Math['trunc'];

var Math_abs = Math.abs;
var Math_cos = Math.cos;
var Math_sin = Math.sin;
var Math_tan = Math.tan;
var Math_acos = Math.acos;
var Math_asin = Math.asin;
var Math_atan = Math.atan;
var Math_atan2 = Math.atan2;
var Math_exp = Math.exp;
var Math_log = Math.log;
var Math_sqrt = Math.sqrt;
var Math_ceil = Math.ceil;
var Math_floor = Math.floor;
var Math_pow = Math.pow;
var Math_imul = Math.imul;
var Math_fround = Math.fround;
var Math_round = Math.round;
var Math_min = Math.min;
var Math_clz32 = Math.clz32;
var Math_trunc = Math.trunc;

// A counter of dependencies for calling run(). If we need to
// do asynchronous work before running, increment this and
// decrement it. Incrementing must happen in a place like
// PRE_RUN_ADDITIONS (used by emcc to add file preloading).
// Note that you can add dependencies in preRun, even though
// it happens right before run - run will be postponed until
// the dependencies are met.
var runDependencies = 0;
var runDependencyWatcher = null;
var dependenciesFulfilled = null; // overridden to take different actions when all run dependencies are fulfilled
var runDependencyTracking = {};

function getUniqueRunDependency(id) {
  var orig = id;
  while (1) {
    if (!runDependencyTracking[id]) return id;
    id = orig + Math.random();
  }
  return id;
}

function addRunDependency(id) {
  runDependencies++;
  if (Module['monitorRunDependencies']) {
    Module['monitorRunDependencies'](runDependencies);
  }
  if (id) {
    assert(!runDependencyTracking[id]);
    runDependencyTracking[id] = 1;
    if (runDependencyWatcher === null && typeof setInterval !== 'undefined') {
      // Check for missing dependencies every few seconds
      runDependencyWatcher = setInterval(function() {
        if (ABORT) {
          clearInterval(runDependencyWatcher);
          runDependencyWatcher = null;
          return;
        }
        var shown = false;
        for (var dep in runDependencyTracking) {
          if (!shown) {
            shown = true;
            Module.printErr('still waiting on run dependencies:');
          }
          Module.printErr('dependency: ' + dep);
        }
        if (shown) {
          Module.printErr('(end of list)');
        }
      }, 10000);
    }
  } else {
    Module.printErr('warning: run dependency added without ID');
  }
}
Module["addRunDependency"] = addRunDependency;

function removeRunDependency(id) {
  runDependencies--;
  if (Module['monitorRunDependencies']) {
    Module['monitorRunDependencies'](runDependencies);
  }
  if (id) {
    assert(runDependencyTracking[id]);
    delete runDependencyTracking[id];
  } else {
    Module.printErr('warning: run dependency removed without ID');
  }
  if (runDependencies == 0) {
    if (runDependencyWatcher !== null) {
      clearInterval(runDependencyWatcher);
      runDependencyWatcher = null;
    }
    if (dependenciesFulfilled) {
      var callback = dependenciesFulfilled;
      dependenciesFulfilled = null;
      callback(); // can add another dependenciesFulfilled
    }
  }
}
Module["removeRunDependency"] = removeRunDependency;

Module["preloadedImages"] = {}; // maps url to image data
Module["preloadedAudios"] = {}; // maps url to audio data



var memoryInitializer = null;



var /* show errors on likely calls to FS when it was not included */ FS = {
  error: function() {
    abort('Filesystem support (FS) was not included. The problem is that you are using files from JS, but files were not used from C/C++, so filesystem support was not auto-included. You can force-include filesystem support with  -s FORCE_FILESYSTEM=1');
  },
  init: function() { FS.error() },
  createDataFile: function() { FS.error() },
  createPreloadedFile: function() { FS.error() },
  createLazyFile: function() { FS.error() },
  open: function() { FS.error() },
  mkdev: function() { FS.error() },
  registerDevice: function() { FS.error() },
  analyzePath: function() { FS.error() },
  loadFilesFromDB: function() { FS.error() },

  ErrnoError: function ErrnoError() { FS.error() },
};
Module['FS_createDataFile'] = FS.createDataFile;
Module['FS_createPreloadedFile'] = FS.createPreloadedFile;

var cyberDWARFFile = 'timer.html.cd';


// === Body ===

var ASM_CONSTS = [];




STATIC_BASE = Runtime.GLOBAL_BASE;

STATICTOP = STATIC_BASE + 4688;
/* global initializers */  __ATINIT__.push();


/* memory initializer */ allocate([148,1,0,0,153,1,0,0,157,1,0,0,60,14,0,0,168,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,1,0,0,5,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,3,0,0,0,69,14,0,0,0,4,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,1,0,0,114,111,111,116,0,102,111,111,0,117,112,100,97,116,101,32,45,32,49,0,117,112,100,97,116,101,32,45,32,50,0,37,115,10,0,48,49,50,51,52,53,54,55,56,57,0,103,114,111,119,58,32,111,117,116,32,111,102,32,109,101,109,111,114,121,10,0,103,101,116,65,116,58,32,111,117,116,32,111,102,32,98,111,117,110,100,115,10,0,103,114,111,119,58,32,110,101,119,32,115,105,122,101,32,115,109,97,108,108,101,114,32,116,104,97,110,32,111,108,100,32,115,105,122,101,32,37,100,58,37,100,10,0,115,101,116,65,116,58,32,111,117,116,32,111,102,32,98,111,117,110,100,115,32,37,100,58,37,100,10,0,103,101,116,65,116,58,32,118,97,108,117,101,32,105,115,32,110,111,116,32,100,101,102,105,110,101,100,32,97,116,32,37,100,10,0,115,116,114,105,110,103,46,97,100,100,58,32,37,100,32,37,100,10,0,115,116,114,105,110,103,46,97,100,100,58,32,37,100,58,37,100,32,37,100,58,37,100,10,0,17,0,10,0,17,17,17,0,0,0,0,5,0,0,0,0,0,0,9,0,0,0,0,11,0,0,0,0,0,0,0,0,17,0,15,10,17,17,17,3,10,7,0,1,19,9,11,11,0,0,9,6,11,0,0,11,0,6,17,0,0,0,17,17,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,17,0,10,10,17,17,17,0,10,0,0,2,0,9,11,0,0,0,9,0,11,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,12,0,0,0,0,9,12,0,0,0,0,0,12,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,13,0,0,0,4,13,0,0,0,0,9,14,0,0,0,0,0,14,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,15,0,0,0,0,9,16,0,0,0,0,0,16,0,0,16,0,0,18,0,0,0,18,18,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,18,18,18,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,10,0,0,0,0,9,11,0,0,0,0,0,11,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,12,0,0,0,0,9,12,0,0,0,0,0,12,0,0,12,0,0,45,43,32,32,32,48,88,48,120,0,40,110,117,108,108,41,0,45,48,88,43,48,88,32,48,88,45,48,120,43,48,120,32,48,120,0,105,110,102,0,73,78,70,0,110,97,110,0,78,65,78,0,48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,46,0,84,33,34,25,13,1,2,3,17,75,28,12,16,4,11,29,18,30,39,104,110,111,112,113,98,32,5,6,15,19,20,21,26,8,22,7,40,36,23,24,9,10,14,27,31,37,35,131,130,125,38,42,43,60,61,62,63,67,71,74,77,88,89,90,91,92,93,94,95,96,97,99,100,101,102,103,105,106,107,108,114,115,116,121,122,123,124,0,73,108,108,101,103,97,108,32,98,121,116,101,32,115,101,113,117,101,110,99,101,0,68,111,109,97,105,110,32,101,114,114,111,114,0,82,101,115,117,108,116,32,110,111,116,32,114,101,112,114,101,115,101,110,116,97,98,108,101,0,78,111,116,32,97,32,116,116,121,0,80,101,114,109,105,115,115,105,111,110,32,100,101,110,105,101,100,0,79,112,101,114,97,116,105,111,110,32,110,111,116,32,112,101,114,109,105,116,116,101,100,0,78,111,32,115,117,99,104,32,102,105,108,101,32,111,114,32,100,105,114,101,99,116,111,114,121,0,78,111,32,115,117,99,104,32,112,114,111,99,101,115,115,0,70,105,108,101,32,101,120,105,115,116,115,0,86,97,108,117,101,32,116,111,111,32,108,97,114,103,101,32,102,111,114,32,100,97,116,97,32,116,121,112,101,0,78,111,32,115,112,97,99,101,32,108,101,102,116,32,111,110,32,100,101,118,105,99,101,0,79,117,116,32,111,102,32,109,101,109,111,114,121,0,82,101,115,111,117,114,99,101,32,98,117,115,121,0,73,110,116,101,114,114,117,112,116,101,100,32,115,121,115,116,101,109,32,99,97,108,108,0,82,101,115,111,117,114,99,101,32,116,101,109,112,111,114,97,114,105,108,121,32,117,110,97,118,97,105,108,97,98,108,101,0,73,110,118,97,108,105,100,32,115,101,101,107,0,67,114,111,115,115,45,100,101,118,105,99,101,32,108,105,110,107,0,82,101,97,100,45,111,110,108,121,32,102,105,108,101,32,115,121,115,116,101,109,0,68,105,114,101,99,116,111,114,121,32,110,111,116,32,101,109,112,116,121,0,67,111,110,110,101,99,116,105,111,110,32,114,101,115,101,116,32,98,121,32,112,101,101,114,0,79,112,101,114,97,116,105,111,110,32,116,105,109,101,100,32,111,117,116,0,67,111,110,110,101,99,116,105,111,110,32,114,101,102,117,115,101,100,0,72,111,115,116,32,105,115,32,100,111,119,110,0,72,111,115,116,32,105,115,32,117,110,114,101,97,99,104,97,98,108,101,0,65,100,100,114,101,115,115,32,105,110,32,117,115,101,0,66,114,111,107,101,110,32,112,105,112,101,0,73,47,79,32,101,114,114,111,114,0,78,111,32,115,117,99,104,32,100,101,118,105,99,101,32,111,114,32,97,100,100,114,101,115,115,0,66,108,111,99,107,32,100,101,118,105,99,101,32,114,101,113,117,105,114,101,100,0,78,111,32,115,117,99,104,32,100,101,118,105,99,101,0,78,111,116,32,97,32,100,105,114,101,99,116,111,114,121,0,73,115,32,97,32,100,105,114,101,99,116,111,114,121,0,84,101,120,116,32,102,105,108,101,32,98,117,115,121,0,69,120,101,99,32,102,111,114,109,97,116,32,101,114,114,111,114,0,73,110,118,97,108,105,100,32,97,114,103,117,109,101,110,116,0,65,114,103,117,109,101,110,116,32,108,105,115,116,32,116,111,111,32,108,111,110,103,0,83,121,109,98,111,108,105,99,32,108,105,110,107,32,108,111,111,112,0,70,105,108,101,110,97,109,101,32,116,111,111,32,108,111,110,103,0,84,111,111,32,109,97,110,121,32,111,112,101,110,32,102,105,108,101,115,32,105,110,32,115,121,115,116,101,109,0,78,111,32,102,105,108,101,32,100,101,115,99,114,105,112,116,111,114,115,32,97,118,97,105,108,97,98,108,101,0,66,97,100,32,102,105,108,101,32,100,101,115,99,114,105,112,116,111,114,0,78,111,32,99,104,105,108,100,32,112,114,111,99,101,115,115,0,66,97,100,32,97,100,100,114,101,115,115,0,70,105,108,101,32,116,111,111,32,108,97,114,103,101,0,84,111,111,32,109,97,110,121,32,108,105,110,107,115,0,78,111,32,108,111,99,107,115,32,97,118,97,105,108,97,98,108,101,0,82,101,115,111,117,114,99,101,32,100,101,97,100,108,111,99,107,32,119,111,117,108,100,32,111,99,99,117,114,0,83,116,97,116,101,32,110,111,116,32,114,101,99,111,118,101,114,97,98,108,101,0,80,114,101,118,105,111,117,115,32,111,119,110,101,114,32,100,105,101,100,0,79,112,101,114,97,116,105,111,110,32,99,97,110,99,101,108,101,100,0,70,117,110,99,116,105,111,110,32,110,111,116,32,105,109,112,108,101,109,101,110,116,101,100,0,78,111,32,109,101,115,115,97,103,101,32,111,102,32,100,101,115,105,114,101,100,32,116,121,112,101,0,73,100,101,110,116,105,102,105,101,114,32,114,101,109,111,118,101,100,0,68,101,118,105,99,101,32,110,111,116,32,97,32,115,116,114,101,97,109,0,78,111,32,100,97,116,97,32,97,118,97,105,108,97,98,108,101,0,68,101,118,105,99,101,32,116,105,109,101,111,117,116,0,79,117,116,32,111,102,32,115,116,114,101,97,109,115,32,114,101,115,111,117,114,99,101,115,0,76,105,110,107,32,104,97,115,32,98,101,101,110,32,115,101,118,101,114,101,100,0,80,114,111,116,111,99,111,108,32,101,114,114,111,114,0,66,97,100,32,109,101,115,115,97,103,101,0,70,105,108,101,32,100,101,115,99,114,105,112,116,111,114,32,105,110,32,98,97,100,32,115,116,97,116,101,0,78,111,116,32,97,32,115,111,99,107,101,116,0,68,101,115,116,105,110,97,116,105,111,110,32,97,100,100,114,101,115,115,32,114,101,113,117,105,114,101,100,0,77,101,115,115,97,103,101,32,116,111,111,32,108,97,114,103,101,0,80,114,111,116,111,99,111,108,32,119,114,111,110,103,32,116,121,112,101,32,102,111,114,32,115,111,99,107,101,116,0,80,114,111,116,111,99,111,108,32,110,111,116,32,97,118,97,105,108,97,98,108,101,0,80,114,111,116,111,99,111,108,32,110,111,116,32,115,117,112,112,111,114,116,101,100,0,83,111,99,107,101,116,32,116,121,112,101,32,110,111,116,32,115,117,112,112,111,114,116,101,100,0,78,111,116,32,115,117,112,112,111,114,116,101,100,0,80,114,111,116,111,99,111,108,32,102,97,109,105,108,121,32,110,111,116,32,115,117,112,112,111,114,116,101,100,0,65,100,100,114,101,115,115,32,102,97,109,105,108,121,32,110,111,116,32,115,117,112,112,111,114,116,101,100,32,98,121,32,112,114,111,116,111,99,111,108,0,65,100,100,114,101,115,115,32,110,111,116,32,97,118,97,105,108,97,98,108,101,0,78,101,116,119,111,114,107,32,105,115,32,100,111,119,110,0,78,101,116,119,111,114,107,32,117,110,114,101,97,99,104,97,98,108,101,0,67,111,110,110,101,99,116,105,111,110,32,114,101,115,101,116,32,98,121,32,110,101,116,119,111,114,107,0,67,111,110,110,101,99,116,105,111,110,32,97,98,111,114,116,101,100,0,78,111,32,98,117,102,102,101,114,32,115,112,97,99,101,32,97,118,97,105,108,97,98,108,101,0,83,111,99,107,101,116,32,105,115,32,99,111,110,110,101,99,116,101,100,0,83,111,99,107,101,116,32,110,111,116,32,99,111,110,110,101,99,116,101,100,0,67,97,110,110,111,116,32,115,101,110,100,32,97,102,116,101,114,32,115,111,99,107,101,116,32,115,104,117,116,100,111,119,110,0,79,112,101,114,97,116,105,111,110,32,97,108,114,101,97,100,121,32,105,110,32,112,114,111,103,114,101,115,115,0,79,112,101,114,97,116,105,111,110,32,105,110,32,112,114,111,103,114,101,115,115,0,83,116,97,108,101,32,102,105,108,101,32,104,97,110,100,108,101,0,82,101,109,111,116,101,32,73,47,79,32,101,114,114,111,114,0,81,117,111,116,97,32,101,120,99,101,101,100,101,100,0,78,111,32,109,101,100,105,117,109,32,102,111,117,110,100,0,87,114,111,110,103,32,109,101,100,105,117,109,32,116,121,112,101,0,78,111,32,101,114,114,111,114,32,105,110,102,111,114,109,97,116,105,111,110,0,0], "i8", ALLOC_NONE, Runtime.GLOBAL_BASE);





/* no memory initializer */
var tempDoublePtr = STATICTOP; STATICTOP += 16;

assert(tempDoublePtr % 8 == 0);

function copyTempFloat(ptr) { // functions, because inlining this code increases code size too much

  HEAP8[tempDoublePtr] = HEAP8[ptr];

  HEAP8[tempDoublePtr+1] = HEAP8[ptr+1];

  HEAP8[tempDoublePtr+2] = HEAP8[ptr+2];

  HEAP8[tempDoublePtr+3] = HEAP8[ptr+3];

}

function copyTempDouble(ptr) {

  HEAP8[tempDoublePtr] = HEAP8[ptr];

  HEAP8[tempDoublePtr+1] = HEAP8[ptr+1];

  HEAP8[tempDoublePtr+2] = HEAP8[ptr+2];

  HEAP8[tempDoublePtr+3] = HEAP8[ptr+3];

  HEAP8[tempDoublePtr+4] = HEAP8[ptr+4];

  HEAP8[tempDoublePtr+5] = HEAP8[ptr+5];

  HEAP8[tempDoublePtr+6] = HEAP8[ptr+6];

  HEAP8[tempDoublePtr+7] = HEAP8[ptr+7];

}

// {{PRE_LIBRARY}}


   

   

   

   

   

  function _abort() {
      Module['abort']();
    }

  function ___lock() {}

  function ___unlock() {}

  
  var SYSCALLS={varargs:0,get:function (varargs) {
        SYSCALLS.varargs += 4;
        var ret = ((SAFE_HEAP_LOAD((((SYSCALLS.varargs)-(4))|0), 4, 0))|0);
        return ret;
      },getStr:function () {
        var ret = Pointer_stringify(SYSCALLS.get());
        return ret;
      },get64:function () {
        var low = SYSCALLS.get(), high = SYSCALLS.get();
        if (low >= 0) assert(high === 0);
        else assert(high === -1);
        return low;
      },getZero:function () {
        assert(SYSCALLS.get() === 0);
      }};function ___syscall6(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // close
      var stream = SYSCALLS.getStreamFromFD();
      FS.close(stream);
      return 0;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }

  
  
  var cttz_i8 = allocate([8,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,7,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0], "i8", ALLOC_STATIC);   

  function _cyberdwarf_Debugger(cdFileLocation) {
    var BASIC_TYPE = 0,
        DERIVED_TYPE = 1,
        COMPOSITE_TYPE = 2,
        SUBROUTINE_TYPE = 3,
        SUBRANGE_INFO = 4,
        SUBPROGRAM_TYPE = 5,
        ENUMERATOR_TYPE = 6,
        STRING_REFERENCE = 10;
  
    var DW_TAG_array_type = 0x01,
        DW_TAG_class_type = 0x02,
        DW_TAG_entry_point = 0x03,
        DW_TAG_enumeration_type = 0x04,
        DW_TAG_formal_parameter = 0x05,
        DW_TAG_imported_declaration = 0x08,
        DW_TAG_label = 0x0a,
        DW_TAG_lexical_block = 0x0b,
        DW_TAG_member = 0x0d,
        DW_TAG_pointer_type = 0x0f,
        DW_TAG_reference_type = 0x10,
        DW_TAG_compile_unit = 0x11,
        DW_TAG_string_type = 0x12,
        DW_TAG_structure_type = 0x13,
        DW_TAG_subroutine_type = 0x15,
        DW_TAG_typedef = 0x16,
        DW_TAG_union_type = 0x17,
        DW_TAG_unspecified_parameters = 0x18,
        DW_TAG_variant = 0x19,
        DW_TAG_common_block = 0x1a,
        DW_TAG_common_inclusion = 0x1b,
        DW_TAG_inheritance = 0x1c,
        DW_TAG_inlined_subroutine = 0x1d,
        DW_TAG_module = 0x1e,
        DW_TAG_ptr_to_member_type = 0x1f,
        DW_TAG_set_type = 0x20,
        DW_TAG_subrange_type = 0x21,
        DW_TAG_with_stmt = 0x22,
        DW_TAG_access_declaration = 0x23,
        DW_TAG_base_type = 0x24,
        DW_TAG_catch_block = 0x25,
        DW_TAG_const_type = 0x26,
        DW_TAG_constant = 0x27,
        DW_TAG_enumerator = 0x28,
        DW_TAG_file_type = 0x29,
        DW_TAG_friend = 0x2a,
        DW_TAG_namelist = 0x2b,
        DW_TAG_namelist_item = 0x2c,
        DW_TAG_packed_type = 0x2d,
        DW_TAG_subprogram = 0x2e,
        DW_TAG_template_type_parameter = 0x2f,
        DW_TAG_template_value_parameter = 0x30,
        DW_TAG_thrown_type = 0x31,
        DW_TAG_try_block = 0x32,
        DW_TAG_variant_part = 0x33,
        DW_TAG_variable = 0x34,
        DW_TAG_volatile_type = 0x35,
        DW_TAG_dwarf_procedure = 0x36,
        DW_TAG_restrict_type = 0x37,
        DW_TAG_interface_type = 0x38,
        DW_TAG_namespace = 0x39,
        DW_TAG_imported_module = 0x3a,
        DW_TAG_unspecified_type = 0x3b,
        DW_TAG_partial_unit = 0x3c,
        DW_TAG_imported_unit = 0x3d,
        DW_TAG_condition = 0x3f,
        DW_TAG_shared_type = 0x40,
        DW_TAG_lo_user = 0x4080,
        DW_TAG_hi_user = 0xffff;
  
    var DW_ATE_address = 0x01,
        DW_ATE_boolean = 0x02,
        DW_ATE_complex_float = 0x03,
        DW_ATE_float = 0x04,
        DW_ATE_signed = 0x05,
        DW_ATE_signed_char = 0x06,
        DW_ATE_unsigned = 0x07,
        DW_ATE_unsigned_char = 0x08,
        DW_ATE_imaginary_float = 0x09,
        DW_ATE_packed_decimal = 0x0a,
        DW_ATE_numeric_string = 0x0b,
        DW_ATE_edited = 0x0c,
        DW_ATE_signed_fixed = 0x0d,
        DW_ATE_unsigned_fixed = 0x0e,
        DW_ATE_decimal_float = 0x0f,
        DW_ATE_lo_user = 0x80,
        DW_ATE_hi_user = 0xff;
  
    var TYPE_ID_IDX = 0,
        NAME_IDX = 1,
        TAG_IDX = 2,
        BASE_TYPE_IDX = 3,
        OFFSET_IDX = 4,
        SIZE_IDX = 5,
        C_ELEMS_IDX = 7;
  
    function TypedVariable(base_ptr, type_id) {
      this.derives = [];
      this.primary = null;
      this.primary_type_id = "";
      this.base_ptr = base_ptr;
  
      this.type_id = type_id;
      this.built = false;
      this.resolved = false;
      this.name = "";
      this.value = "";
      this.pointerCount = 0;
      this.offset = 0;
      this.size = 0;
      this.standalone_id = 0;
      this.dereference = true;
      this.isMember = false;
      this.isInherited = false
    }
  
    TypedVariable.prototype.toString = function() {
      return "[TypedVariable < " + JSON.stringify(this.derives) + " > " + JSON.stringify(this.primary) + " (&" + this._getMyAddress() + ")]";
    }
  
    TypedVariable.prototype._initialBuild = function() {
      if (this.built) {
        return;
      }
  
      this.built = true;
      this._buildDeriveChain();
      this._processTypes();
    }
  
    TypedVariable.prototype._buildDeriveChain = function() {
      var cur_td = type_id_to_type_descriptor(this.type_id, this.base_ptr);
  
      var ptr = this.base_ptr;
  
      while (cur_td[TYPE_ID_IDX] == 1 || cur_td[TYPE_ID_IDX] == 10) {
        if (cur_td[TYPE_ID_IDX] == 1) {
          this.derives.push(cur_td);
          this.primary_type_id = cur_td[BASE_TYPE_IDX];
          if (cur_td[TAG_IDX] == DW_TAG_member) {
            ptr += cur_td[OFFSET_IDX];
          }
          cur_td = type_id_to_type_descriptor(cur_td[BASE_TYPE_IDX], ptr);
        } else {
          this.primary_type_id = cur_td[1];
          cur_td = type_id_to_type_descriptor(cur_td[1], ptr);
        }
      }
  
      this.primary = cur_td;
    }
  
    TypedVariable.prototype._processTypes = function() {
      var name_vec = [];
  
      for (var i in this.derives) {
        switch (this.derives[i][TAG_IDX]) {
          case DW_TAG_reference_type: {
            name_vec.unshift("&");
            this.pointerCount++;
          } break;
          case DW_TAG_pointer_type: {
            name_vec.unshift("*");
            this.pointerCount++;
          } break;
          case DW_TAG_const_type: {
            name_vec.unshift("const");
          } break;
          case DW_TAG_inheritance: {
            this.isInherited = true;
            name_vec.unshift(">");
            this.offset = this.derives[i][OFFSET_IDX] / 8;
          } break;
          case DW_TAG_member: {
            this.isMember = true;
            name_vec.push(":");
            name_vec.push(this.derives[i][NAME_IDX])
            this.offset = this.derives[i][OFFSET_IDX] / 8;
          } break;
          case DW_TAG_typedef: {
            // Ignoring typedefs for the time being
          } break;
          case DW_TAG_volatile_type: {
            name_vec.unshift("volatile");
          }
          default:
            console.error("Unimplemented " + type_descriptor);
        }
      }
  
      if (this.primary[TYPE_ID_IDX] == BASIC_TYPE) {
        this.size = this.primary[4];
        name_vec.unshift(this.primary[NAME_IDX]);
      } else if (this.primary[TYPE_ID_IDX] == COMPOSITE_TYPE) {
        this.size = this.primary[SIZE_IDX];
        name_vec.unshift(this.primary[NAME_IDX]);
  
        switch (this.primary[TAG_IDX]) {
          case DW_TAG_structure_type: {
            name_vec.unshift("struct");
          } break;
          case DW_TAG_class_type: {
            name_vec.unshift("class");
          } break;
          case DW_TAG_enumeration_type: {
            name_vec.unshift("class");
          } break;
          case DW_TAG_union_type: {
            name_vec.unshift("union");
          } break;
          case DW_TAG_array_type: {
            name_vec.unshift("array");
          } break;
          default:
            console.error("Unimplemented for composite " + this.primary);
        }
      }
  
      this.name = name_vec.join(" ");
    }
  
    TypedVariable.prototype._getMyAddress = function() {
      var base_addr = this.base_ptr + this.offset;
      for (var i = 0; i < this.pointerCount; i++) {
        if (base_addr == 0) {
          return 0;
        }
        base_addr = heap["u32"][base_addr >> 2];
      }
      return base_addr;
    }
  
    TypedVariable.prototype._resolveBaseTypeValue = function() {
      this.resolved = true;
      if (this.primary[TYPE_ID_IDX] == BASIC_TYPE) {
        if (!this.dereference) {
          switch (this.primary[TAG_IDX]) {
            case DW_ATE_unsigned:
            case DW_ATE_float:
            case DW_ATE_signed: {
              this.value = this.base_ptr;
            }; break;
          }
        } else {
          if (this.base_ptr == 0) {
            this.value = null;
          } else {
            var heap_id = type_descriptor_to_heap_id(this.primary);
            var ptr = this._getMyAddress();
            this.value = heap[heap_id][ptr >> heap_shift[heap_id]];
          }
        }
      } else {
        this.value = {};
  
        for (var i in this.primary[C_ELEMS_IDX]) {
          var cur_elem = new TypedVariable(this._getMyAddress(), this.primary[C_ELEMS_IDX][i]);
  
          cur_elem._initialBuild();
  
          if (cur_elem.size > 0 && (cur_elem.isInherited || cur_elem.isMember)) {
            var pointed_elem = new TypedVariable(cur_elem._getMyAddress(), cur_elem.primary_type_id);
            pointed_elem._initialBuild();
            this.value[cur_elem.name] = pointed_elem;
          }
        }
      }
    }
  
    TypedVariable.prototype._buildForPrettyPrint = function(depth) {
      if (typeof(depth) === "undefined") {
        depth = 1;
      }
  
      if (depth < 1) {
        return;
      }
  
      this._initialBuild();
      this._resolveBaseTypeValue();
  
      if (this.primary[TYPE_ID_IDX] != 2 || this._getMyAddress() == 0) {
        return;
      }
  
      for (var i in this.value) {
        this.value[i]._buildForPrettyPrint(depth - 1);
      }
    }
  
    TypedVariable.prototype._prettyPrintToObjectHelper = function() {
  
      if (typeof(this.value) !== "object") {
        return this.value;
      }
  
      if (this.value == null) {
        return "null";
      }
  
      var childNames = Object.keys(this.value);
  
      var retval = {};
  
      for (var i in childNames) {
        if (this.value[childNames[i]].resolved) {
          retval[childNames[i]] = this.value[childNames[i]]._prettyPrintToObjectHelper();
        } else {
          retval[childNames[i]] = "cd_tvptr(0x" + this.value[childNames[i]]._getMyAddress().toString(16) + ",'" + this.value[childNames[i]].type_id + "')";
        }
      }
  
      return retval;
    }
  
    TypedVariable.prototype.prettyPrintToObject = function(depth) {
      this._buildForPrettyPrint(depth);
      var retval = {};
      retval[this.name] = this._prettyPrintToObjectHelper();
      return retval;
    }
  
    var heap = {};
    var cyberdwarf = undefined;
    var heap_shift = {
      "u8" : 0,
      "u16": 1,
      "u32": 2,
      "i8" : 0,
      "i16": 1,
      "i32": 2,
      "f32": 2,
      "f64": 3
    }
    function install_heap($heap) {
      heap = {
        "u8" : new Uint8Array($heap),
        "u16": new Uint16Array($heap),
        "u32": new Uint32Array($heap),
        "i8" : new Int8Array($heap),
        "i16": new Int16Array($heap),
        "i32": new Int32Array($heap),
        "f32": new Float32Array($heap),
        "f64": new Float64Array($heap)
      };
    }
  
    var symbols = {};
  
    function install_cyberdwarf(data_cd) {
      cyberdwarf = JSON.parse(data_cd)["cyberdwarf"];
      invert_vtables();
    }
  
    function type_descriptor_to_heap_id(type_descriptor) {
      var id = "";
      switch (type_descriptor[TAG_IDX]) {
        case DW_ATE_unsigned: case DW_ATE_unsigned_char: id = "u"; break;
        case DW_ATE_signed: case DW_ATE_signed_char: id = "i"; break;
        case DW_ATE_float: id = "f"; break;
      }
      id += type_descriptor[4];
      return id;
    }
  
    function type_id_to_type_descriptor(type_id, ptr, dit) {
      if (!isNaN(+type_id)) {
        return cyberdwarf["types"][type_id];
      }
      if (typeof(type_id) === "string") {
        if (dit) {
          type_id = resolve_from_vtable(ptr, type_id);
        }
        type_id = cyberdwarf["type_name_map"][type_id];
      }
      return cyberdwarf["types"][type_id];
    }
  
    function invert_vtables() {
      cyberdwarf["has_vtable"] = {};
      for (var i in cyberdwarf["vtable_offsets"]) {
        cyberdwarf["has_vtable"][cyberdwarf["vtable_offsets"][i]] = true;
      }
    }
  
    function resolve_from_vtable(val, type_name) {
      var lookup_name = "_ZTV" + type_name.substr(4);
      if (cyberdwarf["has_vtable"][lookup_name]) {
        var potential_vtable = "" + (heap["u32"][val >> 2] - 8);
        if (cyberdwarf["vtable_offsets"][potential_vtable]) {
          var ans = type_name.substr(0,4) + cyberdwarf["vtable_offsets"][potential_vtable].substr(4);
          return ans;
        }
      }
      return type_name;
    }
  
    var current_function = "";
    function set_current_function(func_name) {
      if (typeof(cyberdwarf["function_name_map"][func_name]) !== "undefined") {
        func_name = cyberdwarf["function_name_map"][func_name];
      }
      if (func_name.substring(0,1) == "_") {
        func_name = func_name.substring(1);
      }
      current_function = cyberdwarf["functions"][func_name];
    }
  
    function pretty_print_to_object(val, type_id, depth) {
      install_heap(Module.HEAPU8.buffer);
      var base_type = new TypedVariable(val, current_function[type_id]);
      return base_type.prettyPrintToObject(depth);
    }
  
    function pretty_print_from_typename(val, type_name, depth) {
      install_heap(Module.HEAPU8.buffer);
      var base_type = new TypedVariable(val, type_name);
      return base_type.prettyPrintToObject(depth);
    }
  
    function stack_decoder(val, name, depth, on_heap) {
      var stack_frames = jsStackTrace().split("\n");
  
      // To find the function that called us, look for the first reference to calling an EM_ASM block
      var stack_offset = 0;
      for (; stack_offset < stack_frames.length; stack_offset++) {
          if (stack_frames[stack_offset].match("emscripten_asm_const")) break;
      }
  
      // Subtract 1 since we shouldn't have found it on the last frame
      if (stack_offset == stack_frames.length - 1) {
        console.error("Couldn't find the function the decoder was called from");
        return {};
      }
  
      var func_finder = new RegExp("at (?:Object\\.|)([^\\s]+)", "g");
      var result = func_finder.exec(stack_frames[stack_offset + 1]);
  
      if (result.length > 1) {
        set_current_function(result[1]);
      }
  
      var decoded = pretty_print_to_object(val, name, depth);
      return decoded;
    }
  
    function initialize_debugger(cb) {
      var cdFile;
      if (typeof Module['locateFile'] === 'function') {
        cdFileLocation = Module['locateFile'](cdFileLocation);
      } else if (Module['cdInitializerPrefixURL']) {
        cdFileLocation = Module['cdInitializerPrefixURL'] + cdFileLocation;
      }
      if (ENVIRONMENT_IS_NODE || ENVIRONMENT_IS_SHELL) {
        var data = Module['read'](cdFileLocation);
        install_cyberdwarf(data);
      } else {
        var applyCDFile = function(data) {
          var decoder = new TextDecoder("utf8");
          install_cyberdwarf(decoder.decode(data));
          console.info("Debugger ready");
          if (typeof(cb) !== "undefined") {
            cb();
          }
        }
        function doBrowserLoad() {
          Module['readAsync'](cdFileLocation, applyCDFile, function() {
            throw 'could not load debug data ' + cdFileLocation;
          });
        }
        // fetch it from the network ourselves
        doBrowserLoad();
      }
    }
  
    return {
      "decode_from_stack": stack_decoder,
      "initialize_debugger": initialize_debugger,
      "set_current_function": set_current_function,
      "decode_var_by_var_name": pretty_print_to_object,
      "decode_var_by_type_name": pretty_print_from_typename
    };
  }

  
  function ___setErrNo(value) {
      if (Module['___errno_location']) SAFE_HEAP_STORE(((Module['___errno_location']())|0), ((value)|0), 4);
      else Module.printErr('failed to set errno from JS');
      return value;
    } 

   

  
  function _emscripten_memcpy_big(dest, src, num) {
      HEAPU8.set(HEAPU8.subarray(src, src+num), dest);
      return dest;
    } 

  
  function __exit(status) {
      // void _exit(int status);
      // http://pubs.opengroup.org/onlinepubs/000095399/functions/exit.html
      Module['exit'](status);
    }function _exit(status) {
      __exit(status);
    }

   

  function ___syscall140(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // llseek
      var stream = SYSCALLS.getStreamFromFD(), offset_high = SYSCALLS.get(), offset_low = SYSCALLS.get(), result = SYSCALLS.get(), whence = SYSCALLS.get();
      // NOTE: offset_high is unused - Emscripten's off_t is 32-bit
      var offset = offset_low;
      FS.llseek(stream, offset, whence);
      SAFE_HEAP_STORE(((result)|0), ((stream.position)|0), 4);
      if (stream.getdents && offset === 0 && whence === 0) stream.getdents = null; // reset readdir state
      return 0;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }

  function ___syscall146(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // writev
      // hack to support printf in NO_FILESYSTEM
      var stream = SYSCALLS.get(), iov = SYSCALLS.get(), iovcnt = SYSCALLS.get();
      var ret = 0;
      if (!___syscall146.buffer) {
        ___syscall146.buffers = [null, [], []]; // 1 => stdout, 2 => stderr
        ___syscall146.printChar = function(stream, curr) {
          var buffer = ___syscall146.buffers[stream];
          assert(buffer);
          if (curr === 0 || curr === 10) {
            (stream === 1 ? Module['print'] : Module['printErr'])(UTF8ArrayToString(buffer, 0));
            buffer.length = 0;
          } else {
            buffer.push(curr);
          }
        };
      }
      for (var i = 0; i < iovcnt; i++) {
        var ptr = ((SAFE_HEAP_LOAD((((iov)+(i*8))|0), 4, 0))|0);
        var len = ((SAFE_HEAP_LOAD((((iov)+(i*8 + 4))|0), 4, 0))|0);
        for (var j = 0; j < len; j++) {
          ___syscall146.printChar(stream, HEAPU8[ptr+j]);
        }
        ret += len;
      }
      return ret;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }

  function ___syscall54(which, varargs) {SYSCALLS.varargs = varargs;
  try {
   // ioctl
      return 0;
    } catch (e) {
    if (typeof FS === 'undefined' || !(e instanceof FS.ErrnoError)) abort(e);
    return -e.errno;
  }
  }
/* flush anything remaining in the buffer during shutdown */ __ATEXIT__.push(function() { var fflush = Module["_fflush"]; if (fflush) fflush(0); var printChar = ___syscall146.printChar; if (!printChar) return; var buffers = ___syscall146.buffers; if (buffers[1].length) printChar(1, 10); if (buffers[2].length) printChar(2, 10); });;
DYNAMICTOP_PTR = allocate(1, "i32", ALLOC_STATIC);

STACK_BASE = STACKTOP = Runtime.alignMemory(STATICTOP);

STACK_MAX = STACK_BASE + TOTAL_STACK;

DYNAMIC_BASE = Runtime.alignMemory(STACK_MAX);

HEAP32[DYNAMICTOP_PTR>>2] = DYNAMIC_BASE;

staticSealed = true; // seal the static portion of memory

assert(DYNAMIC_BASE < TOTAL_MEMORY, "TOTAL_MEMORY not big enough for stack");


function nullFunc_ii(x) { Module["printErr"]("Invalid function pointer called with signature 'ii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_iiii(x) { Module["printErr"]("Invalid function pointer called with signature 'iiii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_vii(x) { Module["printErr"]("Invalid function pointer called with signature 'vii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_iii(x) { Module["printErr"]("Invalid function pointer called with signature 'iii'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function nullFunc_vi(x) { Module["printErr"]("Invalid function pointer called with signature 'vi'. Perhaps this is an invalid value (e.g. caused by calling a virtual method on a NULL pointer)? Or calling a function with an incorrect type, which will fail? (it is worth building your source files with -Werror (warnings are errors), as warnings can indicate undefined behavior which can cause this)");  Module["printErr"]("Build with ASSERTIONS=2 for more info.");abort(x) }

function invoke_ii(index,a1) {
  try {
    return Module["dynCall_ii"](index,a1);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    Module["setThrew"](1, 0);
  }
}

function invoke_iiii(index,a1,a2,a3) {
  try {
    return Module["dynCall_iiii"](index,a1,a2,a3);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    Module["setThrew"](1, 0);
  }
}

function invoke_vii(index,a1,a2) {
  try {
    Module["dynCall_vii"](index,a1,a2);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    Module["setThrew"](1, 0);
  }
}

function invoke_iii(index,a1,a2) {
  try {
    return Module["dynCall_iii"](index,a1,a2);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    Module["setThrew"](1, 0);
  }
}

function invoke_vi(index,a1) {
  try {
    Module["dynCall_vi"](index,a1);
  } catch(e) {
    if (typeof e !== 'number' && e !== 'longjmp') throw e;
    Module["setThrew"](1, 0);
  }
}

Module.asmGlobalArg = { "Math": Math, "Int8Array": Int8Array, "Int16Array": Int16Array, "Int32Array": Int32Array, "Uint8Array": Uint8Array, "Uint16Array": Uint16Array, "Uint32Array": Uint32Array, "Float32Array": Float32Array, "Float64Array": Float64Array, "NaN": NaN, "Infinity": Infinity };

Module.asmLibraryArg = { "abort": abort, "assert": assert, "enlargeMemory": enlargeMemory, "getTotalMemory": getTotalMemory, "abortOnCannotGrowMemory": abortOnCannotGrowMemory, "abortStackOverflow": abortStackOverflow, "segfault": segfault, "alignfault": alignfault, "ftfault": ftfault, "nullFunc_ii": nullFunc_ii, "nullFunc_iiii": nullFunc_iiii, "nullFunc_vii": nullFunc_vii, "nullFunc_iii": nullFunc_iii, "nullFunc_vi": nullFunc_vi, "invoke_ii": invoke_ii, "invoke_iiii": invoke_iiii, "invoke_vii": invoke_vii, "invoke_iii": invoke_iii, "invoke_vi": invoke_vi, "_cyberdwarf_Debugger": _cyberdwarf_Debugger, "___lock": ___lock, "_abort": _abort, "___setErrNo": ___setErrNo, "___syscall6": ___syscall6, "___syscall140": ___syscall140, "_emscripten_memcpy_big": _emscripten_memcpy_big, "___syscall54": ___syscall54, "___unlock": ___unlock, "_exit": _exit, "__exit": __exit, "___syscall146": ___syscall146, "DYNAMICTOP_PTR": DYNAMICTOP_PTR, "tempDoublePtr": tempDoublePtr, "ABORT": ABORT, "STACKTOP": STACKTOP, "STACK_MAX": STACK_MAX, "cttz_i8": cttz_i8 };
// EMSCRIPTEN_START_ASM
var asm = (function(global, env, buffer) {
'almost asm';


  var HEAP8 = new global.Int8Array(buffer);
  var HEAP16 = new global.Int16Array(buffer);
  var HEAP32 = new global.Int32Array(buffer);
  var HEAPU8 = new global.Uint8Array(buffer);
  var HEAPU16 = new global.Uint16Array(buffer);
  var HEAPU32 = new global.Uint32Array(buffer);
  var HEAPF32 = new global.Float32Array(buffer);
  var HEAPF64 = new global.Float64Array(buffer);

  var DYNAMICTOP_PTR=env.DYNAMICTOP_PTR|0;
  var tempDoublePtr=env.tempDoublePtr|0;
  var ABORT=env.ABORT|0;
  var STACKTOP=env.STACKTOP|0;
  var STACK_MAX=env.STACK_MAX|0;
  var cttz_i8=env.cttz_i8|0;

  var __THREW__ = 0;
  var threwValue = 0;
  var setjmpId = 0;
  var undef = 0;
  var nan = global.NaN, inf = global.Infinity;
  var tempInt = 0, tempBigInt = 0, tempBigIntS = 0, tempValue = 0, tempDouble = 0.0;
  var tempRet0 = 0;

  var Math_floor=global.Math.floor;
  var Math_abs=global.Math.abs;
  var Math_sqrt=global.Math.sqrt;
  var Math_pow=global.Math.pow;
  var Math_cos=global.Math.cos;
  var Math_sin=global.Math.sin;
  var Math_tan=global.Math.tan;
  var Math_acos=global.Math.acos;
  var Math_asin=global.Math.asin;
  var Math_atan=global.Math.atan;
  var Math_atan2=global.Math.atan2;
  var Math_exp=global.Math.exp;
  var Math_log=global.Math.log;
  var Math_ceil=global.Math.ceil;
  var Math_imul=global.Math.imul;
  var Math_min=global.Math.min;
  var Math_max=global.Math.max;
  var Math_clz32=global.Math.clz32;
  var abort=env.abort;
  var assert=env.assert;
  var enlargeMemory=env.enlargeMemory;
  var getTotalMemory=env.getTotalMemory;
  var abortOnCannotGrowMemory=env.abortOnCannotGrowMemory;
  var abortStackOverflow=env.abortStackOverflow;
  var segfault=env.segfault;
  var alignfault=env.alignfault;
  var ftfault=env.ftfault;
  var nullFunc_ii=env.nullFunc_ii;
  var nullFunc_iiii=env.nullFunc_iiii;
  var nullFunc_vii=env.nullFunc_vii;
  var nullFunc_iii=env.nullFunc_iii;
  var nullFunc_vi=env.nullFunc_vi;
  var invoke_ii=env.invoke_ii;
  var invoke_iiii=env.invoke_iiii;
  var invoke_vii=env.invoke_vii;
  var invoke_iii=env.invoke_iii;
  var invoke_vi=env.invoke_vi;
  var _cyberdwarf_Debugger=env._cyberdwarf_Debugger;
  var ___lock=env.___lock;
  var _abort=env._abort;
  var ___setErrNo=env.___setErrNo;
  var ___syscall6=env.___syscall6;
  var ___syscall140=env.___syscall140;
  var _emscripten_memcpy_big=env._emscripten_memcpy_big;
  var ___syscall54=env.___syscall54;
  var ___unlock=env.___unlock;
  var _exit=env._exit;
  var __exit=env.__exit;
  var ___syscall146=env.___syscall146;
  var tempFloat = 0.0;

// EMSCRIPTEN_START_FUNCS

function _malloc($0) {
 $0 = $0 | 0;
 var $$$0192$i = 0, $$$0193$i = 0, $$$4236$i = 0, $$$4351$i = 0, $$$i = 0, $$0 = 0, $$0$i$i = 0, $$0$i$i$i = 0, $$0$i18$i = 0, $$01$i$i = 0, $$0189$i = 0, $$0192$lcssa$i = 0, $$01928$i = 0, $$0193$lcssa$i = 0, $$01937$i = 0, $$0197 = 0, $$0199 = 0, $$0206$i$i = 0, $$0207$i$i = 0, $$0211$i$i = 0;
 var $$0212$i$i = 0, $$024371$i = 0, $$0287$i$i = 0, $$0288$i$i = 0, $$0289$i$i = 0, $$0295$i$i = 0, $$0296$i$i = 0, $$0342$i = 0, $$0344$i = 0, $$0345$i = 0, $$0347$i = 0, $$0353$i = 0, $$0358$i = 0, $$0359$$i = 0, $$0359$i = 0, $$0361$i = 0, $$0362$i = 0, $$0368$i = 0, $$1196$i = 0, $$1198$i = 0;
 var $$124470$i = 0, $$1291$i$i = 0, $$1293$i$i = 0, $$1343$i = 0, $$1348$i = 0, $$1363$i = 0, $$1370$i = 0, $$1374$i = 0, $$2234253237$i = 0, $$2247$ph$i = 0, $$2253$ph$i = 0, $$2355$i = 0, $$3$i = 0, $$3$i$i = 0, $$3$i201 = 0, $$3350$i = 0, $$3372$i = 0, $$4$lcssa$i = 0, $$4$ph$i = 0, $$415$i = 0;
 var $$4236$i = 0, $$4351$lcssa$i = 0, $$435114$i = 0, $$4357$$4$i = 0, $$4357$ph$i = 0, $$435713$i = 0, $$723948$i = 0, $$749$i = 0, $$pre = 0, $$pre$i = 0, $$pre$i$i = 0, $$pre$i19$i = 0, $$pre$i210 = 0, $$pre$i212 = 0, $$pre$phi$i$iZ2D = 0, $$pre$phi$i20$iZ2D = 0, $$pre$phi$i211Z2D = 0, $$pre$phi$iZ2D = 0, $$pre$phi11$i$iZ2D = 0, $$pre$phiZ2D = 0;
 var $$pre10$i$i = 0, $$sink1$i = 0, $$sink1$i$i = 0, $$sink16$i = 0, $$sink2$i = 0, $$sink2$i204 = 0, $$sink3$i = 0, $1 = 0, $10 = 0, $100 = 0, $1000 = 0, $1001 = 0, $1002 = 0, $1003 = 0, $1004 = 0, $1005 = 0, $1006 = 0, $1007 = 0, $1008 = 0, $1009 = 0;
 var $101 = 0, $1010 = 0, $1011 = 0, $1012 = 0, $1013 = 0, $1014 = 0, $1015 = 0, $1016 = 0, $1017 = 0, $1018 = 0, $1019 = 0, $102 = 0, $1020 = 0, $1021 = 0, $1022 = 0, $1023 = 0, $1024 = 0, $1025 = 0, $1026 = 0, $1027 = 0;
 var $1028 = 0, $1029 = 0, $103 = 0, $1030 = 0, $1031 = 0, $1032 = 0, $1033 = 0, $1034 = 0, $1035 = 0, $1036 = 0, $1037 = 0, $1038 = 0, $1039 = 0, $104 = 0, $1040 = 0, $1041 = 0, $1042 = 0, $1043 = 0, $1044 = 0, $1045 = 0;
 var $1046 = 0, $1047 = 0, $1048 = 0, $1049 = 0, $105 = 0, $1050 = 0, $1051 = 0, $1052 = 0, $1053 = 0, $1054 = 0, $1055 = 0, $1056 = 0, $1057 = 0, $1058 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0;
 var $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0, $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0;
 var $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0;
 var $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0;
 var $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0, $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0;
 var $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0, $189 = 0, $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0, $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $2 = 0, $20 = 0, $200 = 0;
 var $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0, $206 = 0, $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0, $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0;
 var $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0, $224 = 0, $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0, $23 = 0, $230 = 0, $231 = 0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0;
 var $238 = 0, $239 = 0, $24 = 0, $240 = 0, $241 = 0, $242 = 0, $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0, $249 = 0, $25 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0;
 var $256 = 0, $257 = 0, $258 = 0, $259 = 0, $26 = 0, $260 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0, $267 = 0, $268 = 0, $269 = 0, $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0;
 var $274 = 0, $275 = 0, $276 = 0, $277 = 0, $278 = 0, $279 = 0, $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0, $284 = 0, $285 = 0, $286 = 0, $287 = 0, $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0;
 var $292 = 0, $293 = 0, $294 = 0, $295 = 0, $296 = 0, $297 = 0, $298 = 0, $299 = 0, $3 = 0, $30 = 0, $300 = 0, $301 = 0, $302 = 0, $303 = 0, $304 = 0, $305 = 0, $306 = 0, $307 = 0, $308 = 0, $309 = 0;
 var $31 = 0, $310 = 0, $311 = 0, $312 = 0, $313 = 0, $314 = 0, $315 = 0, $316 = 0, $317 = 0, $318 = 0, $319 = 0, $32 = 0, $320 = 0, $321 = 0, $322 = 0, $323 = 0, $324 = 0, $325 = 0, $326 = 0, $327 = 0;
 var $328 = 0, $329 = 0, $33 = 0, $330 = 0, $331 = 0, $332 = 0, $333 = 0, $334 = 0, $335 = 0, $336 = 0, $337 = 0, $338 = 0, $339 = 0, $34 = 0, $340 = 0, $341 = 0, $342 = 0, $343 = 0, $344 = 0, $345 = 0;
 var $346 = 0, $347 = 0, $348 = 0, $349 = 0, $35 = 0, $350 = 0, $351 = 0, $352 = 0, $353 = 0, $354 = 0, $355 = 0, $356 = 0, $357 = 0, $358 = 0, $359 = 0, $36 = 0, $360 = 0, $361 = 0, $362 = 0, $363 = 0;
 var $364 = 0, $365 = 0, $366 = 0, $367 = 0, $368 = 0, $369 = 0, $37 = 0, $370 = 0, $371 = 0, $372 = 0, $373 = 0, $374 = 0, $375 = 0, $376 = 0, $377 = 0, $378 = 0, $379 = 0, $38 = 0, $380 = 0, $381 = 0;
 var $382 = 0, $383 = 0, $384 = 0, $385 = 0, $386 = 0, $387 = 0, $388 = 0, $389 = 0, $39 = 0, $390 = 0, $391 = 0, $392 = 0, $393 = 0, $394 = 0, $395 = 0, $396 = 0, $397 = 0, $398 = 0, $399 = 0, $4 = 0;
 var $40 = 0, $400 = 0, $401 = 0, $402 = 0, $403 = 0, $404 = 0, $405 = 0, $406 = 0, $407 = 0, $408 = 0, $409 = 0, $41 = 0, $410 = 0, $411 = 0, $412 = 0, $413 = 0, $414 = 0, $415 = 0, $416 = 0, $417 = 0;
 var $418 = 0, $419 = 0, $42 = 0, $420 = 0, $421 = 0, $422 = 0, $423 = 0, $424 = 0, $425 = 0, $426 = 0, $427 = 0, $428 = 0, $429 = 0, $43 = 0, $430 = 0, $431 = 0, $432 = 0, $433 = 0, $434 = 0, $435 = 0;
 var $436 = 0, $437 = 0, $438 = 0, $439 = 0, $44 = 0, $440 = 0, $441 = 0, $442 = 0, $443 = 0, $444 = 0, $445 = 0, $446 = 0, $447 = 0, $448 = 0, $449 = 0, $45 = 0, $450 = 0, $451 = 0, $452 = 0, $453 = 0;
 var $454 = 0, $455 = 0, $456 = 0, $457 = 0, $458 = 0, $459 = 0, $46 = 0, $460 = 0, $461 = 0, $462 = 0, $463 = 0, $464 = 0, $465 = 0, $466 = 0, $467 = 0, $468 = 0, $469 = 0, $47 = 0, $470 = 0, $471 = 0;
 var $472 = 0, $473 = 0, $474 = 0, $475 = 0, $476 = 0, $477 = 0, $478 = 0, $479 = 0, $48 = 0, $480 = 0, $481 = 0, $482 = 0, $483 = 0, $484 = 0, $485 = 0, $486 = 0, $487 = 0, $488 = 0, $489 = 0, $49 = 0;
 var $490 = 0, $491 = 0, $492 = 0, $493 = 0, $494 = 0, $495 = 0, $496 = 0, $497 = 0, $498 = 0, $499 = 0, $5 = 0, $50 = 0, $500 = 0, $501 = 0, $502 = 0, $503 = 0, $504 = 0, $505 = 0, $506 = 0, $507 = 0;
 var $508 = 0, $509 = 0, $51 = 0, $510 = 0, $511 = 0, $512 = 0, $513 = 0, $514 = 0, $515 = 0, $516 = 0, $517 = 0, $518 = 0, $519 = 0, $52 = 0, $520 = 0, $521 = 0, $522 = 0, $523 = 0, $524 = 0, $525 = 0;
 var $526 = 0, $527 = 0, $528 = 0, $529 = 0, $53 = 0, $530 = 0, $531 = 0, $532 = 0, $533 = 0, $534 = 0, $535 = 0, $536 = 0, $537 = 0, $538 = 0, $539 = 0, $54 = 0, $540 = 0, $541 = 0, $542 = 0, $543 = 0;
 var $544 = 0, $545 = 0, $546 = 0, $547 = 0, $548 = 0, $549 = 0, $55 = 0, $550 = 0, $551 = 0, $552 = 0, $553 = 0, $554 = 0, $555 = 0, $556 = 0, $557 = 0, $558 = 0, $559 = 0, $56 = 0, $560 = 0, $561 = 0;
 var $562 = 0, $563 = 0, $564 = 0, $565 = 0, $566 = 0, $567 = 0, $568 = 0, $569 = 0, $57 = 0, $570 = 0, $571 = 0, $572 = 0, $573 = 0, $574 = 0, $575 = 0, $576 = 0, $577 = 0, $578 = 0, $579 = 0, $58 = 0;
 var $580 = 0, $581 = 0, $582 = 0, $583 = 0, $584 = 0, $585 = 0, $586 = 0, $587 = 0, $588 = 0, $589 = 0, $59 = 0, $590 = 0, $591 = 0, $592 = 0, $593 = 0, $594 = 0, $595 = 0, $596 = 0, $597 = 0, $598 = 0;
 var $599 = 0, $6 = 0, $60 = 0, $600 = 0, $601 = 0, $602 = 0, $603 = 0, $604 = 0, $605 = 0, $606 = 0, $607 = 0, $608 = 0, $609 = 0, $61 = 0, $610 = 0, $611 = 0, $612 = 0, $613 = 0, $614 = 0, $615 = 0;
 var $616 = 0, $617 = 0, $618 = 0, $619 = 0, $62 = 0, $620 = 0, $621 = 0, $622 = 0, $623 = 0, $624 = 0, $625 = 0, $626 = 0, $627 = 0, $628 = 0, $629 = 0, $63 = 0, $630 = 0, $631 = 0, $632 = 0, $633 = 0;
 var $634 = 0, $635 = 0, $636 = 0, $637 = 0, $638 = 0, $639 = 0, $64 = 0, $640 = 0, $641 = 0, $642 = 0, $643 = 0, $644 = 0, $645 = 0, $646 = 0, $647 = 0, $648 = 0, $649 = 0, $65 = 0, $650 = 0, $651 = 0;
 var $652 = 0, $653 = 0, $654 = 0, $655 = 0, $656 = 0, $657 = 0, $658 = 0, $659 = 0, $66 = 0, $660 = 0, $661 = 0, $662 = 0, $663 = 0, $664 = 0, $665 = 0, $666 = 0, $667 = 0, $668 = 0, $669 = 0, $67 = 0;
 var $670 = 0, $671 = 0, $672 = 0, $673 = 0, $674 = 0, $675 = 0, $676 = 0, $677 = 0, $678 = 0, $679 = 0, $68 = 0, $680 = 0, $681 = 0, $682 = 0, $683 = 0, $684 = 0, $685 = 0, $686 = 0, $687 = 0, $688 = 0;
 var $689 = 0, $69 = 0, $690 = 0, $691 = 0, $692 = 0, $693 = 0, $694 = 0, $695 = 0, $696 = 0, $697 = 0, $698 = 0, $699 = 0, $7 = 0, $70 = 0, $700 = 0, $701 = 0, $702 = 0, $703 = 0, $704 = 0, $705 = 0;
 var $706 = 0, $707 = 0, $708 = 0, $709 = 0, $71 = 0, $710 = 0, $711 = 0, $712 = 0, $713 = 0, $714 = 0, $715 = 0, $716 = 0, $717 = 0, $718 = 0, $719 = 0, $72 = 0, $720 = 0, $721 = 0, $722 = 0, $723 = 0;
 var $724 = 0, $725 = 0, $726 = 0, $727 = 0, $728 = 0, $729 = 0, $73 = 0, $730 = 0, $731 = 0, $732 = 0, $733 = 0, $734 = 0, $735 = 0, $736 = 0, $737 = 0, $738 = 0, $739 = 0, $74 = 0, $740 = 0, $741 = 0;
 var $742 = 0, $743 = 0, $744 = 0, $745 = 0, $746 = 0, $747 = 0, $748 = 0, $749 = 0, $75 = 0, $750 = 0, $751 = 0, $752 = 0, $753 = 0, $754 = 0, $755 = 0, $756 = 0, $757 = 0, $758 = 0, $759 = 0, $76 = 0;
 var $760 = 0, $761 = 0, $762 = 0, $763 = 0, $764 = 0, $765 = 0, $766 = 0, $767 = 0, $768 = 0, $769 = 0, $77 = 0, $770 = 0, $771 = 0, $772 = 0, $773 = 0, $774 = 0, $775 = 0, $776 = 0, $777 = 0, $778 = 0;
 var $779 = 0, $78 = 0, $780 = 0, $781 = 0, $782 = 0, $783 = 0, $784 = 0, $785 = 0, $786 = 0, $787 = 0, $788 = 0, $789 = 0, $79 = 0, $790 = 0, $791 = 0, $792 = 0, $793 = 0, $794 = 0, $795 = 0, $796 = 0;
 var $797 = 0, $798 = 0, $799 = 0, $8 = 0, $80 = 0, $800 = 0, $801 = 0, $802 = 0, $803 = 0, $804 = 0, $805 = 0, $806 = 0, $807 = 0, $808 = 0, $809 = 0, $81 = 0, $810 = 0, $811 = 0, $812 = 0, $813 = 0;
 var $814 = 0, $815 = 0, $816 = 0, $817 = 0, $818 = 0, $819 = 0, $82 = 0, $820 = 0, $821 = 0, $822 = 0, $823 = 0, $824 = 0, $825 = 0, $826 = 0, $827 = 0, $828 = 0, $829 = 0, $83 = 0, $830 = 0, $831 = 0;
 var $832 = 0, $833 = 0, $834 = 0, $835 = 0, $836 = 0, $837 = 0, $838 = 0, $839 = 0, $84 = 0, $840 = 0, $841 = 0, $842 = 0, $843 = 0, $844 = 0, $845 = 0, $846 = 0, $847 = 0, $848 = 0, $849 = 0, $85 = 0;
 var $850 = 0, $851 = 0, $852 = 0, $853 = 0, $854 = 0, $855 = 0, $856 = 0, $857 = 0, $858 = 0, $859 = 0, $86 = 0, $860 = 0, $861 = 0, $862 = 0, $863 = 0, $864 = 0, $865 = 0, $866 = 0, $867 = 0, $868 = 0;
 var $869 = 0, $87 = 0, $870 = 0, $871 = 0, $872 = 0, $873 = 0, $874 = 0, $875 = 0, $876 = 0, $877 = 0, $878 = 0, $879 = 0, $88 = 0, $880 = 0, $881 = 0, $882 = 0, $883 = 0, $884 = 0, $885 = 0, $886 = 0;
 var $887 = 0, $888 = 0, $889 = 0, $89 = 0, $890 = 0, $891 = 0, $892 = 0, $893 = 0, $894 = 0, $895 = 0, $896 = 0, $897 = 0, $898 = 0, $899 = 0, $9 = 0, $90 = 0, $900 = 0, $901 = 0, $902 = 0, $903 = 0;
 var $904 = 0, $905 = 0, $906 = 0, $907 = 0, $908 = 0, $909 = 0, $91 = 0, $910 = 0, $911 = 0, $912 = 0, $913 = 0, $914 = 0, $915 = 0, $916 = 0, $917 = 0, $918 = 0, $919 = 0, $92 = 0, $920 = 0, $921 = 0;
 var $922 = 0, $923 = 0, $924 = 0, $925 = 0, $926 = 0, $927 = 0, $928 = 0, $929 = 0, $93 = 0, $930 = 0, $931 = 0, $932 = 0, $933 = 0, $934 = 0, $935 = 0, $936 = 0, $937 = 0, $938 = 0, $939 = 0, $94 = 0;
 var $940 = 0, $941 = 0, $942 = 0, $943 = 0, $944 = 0, $945 = 0, $946 = 0, $947 = 0, $948 = 0, $949 = 0, $95 = 0, $950 = 0, $951 = 0, $952 = 0, $953 = 0, $954 = 0, $955 = 0, $956 = 0, $957 = 0, $958 = 0;
 var $959 = 0, $96 = 0, $960 = 0, $961 = 0, $962 = 0, $963 = 0, $964 = 0, $965 = 0, $966 = 0, $967 = 0, $968 = 0, $969 = 0, $97 = 0, $970 = 0, $971 = 0, $972 = 0, $973 = 0, $974 = 0, $975 = 0, $976 = 0;
 var $977 = 0, $978 = 0, $979 = 0, $98 = 0, $980 = 0, $981 = 0, $982 = 0, $983 = 0, $984 = 0, $985 = 0, $986 = 0, $987 = 0, $988 = 0, $989 = 0, $99 = 0, $990 = 0, $991 = 0, $992 = 0, $993 = 0, $994 = 0;
 var $995 = 0, $996 = 0, $997 = 0, $998 = 0, $999 = 0, $cond$i = 0, $cond$i$i = 0, $cond$i208 = 0, $exitcond$i$i = 0, $not$$i = 0, $not$$i$i = 0, $not$$i17$i = 0, $not$$i209 = 0, $not$$i216 = 0, $not$1$i = 0, $not$1$i203 = 0, $not$5$i = 0, $not$7$i$i = 0, $not$8$i = 0, $not$9$i = 0;
 var $or$cond$i = 0, $or$cond$i214 = 0, $or$cond1$i = 0, $or$cond10$i = 0, $or$cond11$i = 0, $or$cond11$not$i = 0, $or$cond12$i = 0, $or$cond2$i = 0, $or$cond2$i215 = 0, $or$cond5$i = 0, $or$cond50$i = 0, $or$cond51$i = 0, $or$cond7$i = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = sp;
 $2 = $0 >>> 0 < 245;
 do {
  if ($2) {
   $3 = $0 >>> 0 < 11;
   $4 = $0 + 11 | 0;
   $5 = $4 & -8;
   $6 = $3 ? 16 : $5;
   $7 = $6 >>> 3;
   $8 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
   $9 = $8 >>> $7;
   $10 = $9 & 3;
   $11 = ($10 | 0) == 0;
   if (!$11) {
    $12 = $9 & 1;
    $13 = $12 ^ 1;
    $14 = $13 + $7 | 0;
    $15 = $14 << 1;
    $16 = 3112 + ($15 << 2) | 0;
    $17 = $16 + 8 | 0;
    $18 = SAFE_HEAP_LOAD($17 | 0, 4, 0) | 0 | 0;
    $19 = $18 + 8 | 0;
    $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
    $21 = ($16 | 0) == ($20 | 0);
    do {
     if ($21) {
      $22 = 1 << $14;
      $23 = $22 ^ -1;
      $24 = $8 & $23;
      SAFE_HEAP_STORE(768 * 4 | 0, $24 | 0, 4);
     } else {
      $25 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $26 = $20 >>> 0 < $25 >>> 0;
      if ($26) {
       _abort();
      }
      $27 = $20 + 12 | 0;
      $28 = SAFE_HEAP_LOAD($27 | 0, 4, 0) | 0 | 0;
      $29 = ($28 | 0) == ($18 | 0);
      if ($29) {
       SAFE_HEAP_STORE($27 | 0, $16 | 0, 4);
       SAFE_HEAP_STORE($17 | 0, $20 | 0, 4);
       break;
      } else {
       _abort();
      }
     }
    } while (0);
    $30 = $14 << 3;
    $31 = $30 | 3;
    $32 = $18 + 4 | 0;
    SAFE_HEAP_STORE($32 | 0, $31 | 0, 4);
    $33 = $18 + $30 | 0;
    $34 = $33 + 4 | 0;
    $35 = SAFE_HEAP_LOAD($34 | 0, 4, 0) | 0 | 0;
    $36 = $35 | 1;
    SAFE_HEAP_STORE($34 | 0, $36 | 0, 4);
    $$0 = $19;
    STACKTOP = sp;
    return $$0 | 0;
   }
   $37 = SAFE_HEAP_LOAD(3080 | 0, 4, 0) | 0 | 0;
   $38 = $6 >>> 0 > $37 >>> 0;
   if ($38) {
    $39 = ($9 | 0) == 0;
    if (!$39) {
     $40 = $9 << $7;
     $41 = 2 << $7;
     $42 = 0 - $41 | 0;
     $43 = $41 | $42;
     $44 = $40 & $43;
     $45 = 0 - $44 | 0;
     $46 = $44 & $45;
     $47 = $46 + -1 | 0;
     $48 = $47 >>> 12;
     $49 = $48 & 16;
     $50 = $47 >>> $49;
     $51 = $50 >>> 5;
     $52 = $51 & 8;
     $53 = $52 | $49;
     $54 = $50 >>> $52;
     $55 = $54 >>> 2;
     $56 = $55 & 4;
     $57 = $53 | $56;
     $58 = $54 >>> $56;
     $59 = $58 >>> 1;
     $60 = $59 & 2;
     $61 = $57 | $60;
     $62 = $58 >>> $60;
     $63 = $62 >>> 1;
     $64 = $63 & 1;
     $65 = $61 | $64;
     $66 = $62 >>> $64;
     $67 = $65 + $66 | 0;
     $68 = $67 << 1;
     $69 = 3112 + ($68 << 2) | 0;
     $70 = $69 + 8 | 0;
     $71 = SAFE_HEAP_LOAD($70 | 0, 4, 0) | 0 | 0;
     $72 = $71 + 8 | 0;
     $73 = SAFE_HEAP_LOAD($72 | 0, 4, 0) | 0 | 0;
     $74 = ($69 | 0) == ($73 | 0);
     do {
      if ($74) {
       $75 = 1 << $67;
       $76 = $75 ^ -1;
       $77 = $8 & $76;
       SAFE_HEAP_STORE(768 * 4 | 0, $77 | 0, 4);
       $98 = $77;
      } else {
       $78 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
       $79 = $73 >>> 0 < $78 >>> 0;
       if ($79) {
        _abort();
       }
       $80 = $73 + 12 | 0;
       $81 = SAFE_HEAP_LOAD($80 | 0, 4, 0) | 0 | 0;
       $82 = ($81 | 0) == ($71 | 0);
       if ($82) {
        SAFE_HEAP_STORE($80 | 0, $69 | 0, 4);
        SAFE_HEAP_STORE($70 | 0, $73 | 0, 4);
        $98 = $8;
        break;
       } else {
        _abort();
       }
      }
     } while (0);
     $83 = $67 << 3;
     $84 = $83 - $6 | 0;
     $85 = $6 | 3;
     $86 = $71 + 4 | 0;
     SAFE_HEAP_STORE($86 | 0, $85 | 0, 4);
     $87 = $71 + $6 | 0;
     $88 = $84 | 1;
     $89 = $87 + 4 | 0;
     SAFE_HEAP_STORE($89 | 0, $88 | 0, 4);
     $90 = $87 + $84 | 0;
     SAFE_HEAP_STORE($90 | 0, $84 | 0, 4);
     $91 = ($37 | 0) == 0;
     if (!$91) {
      $92 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
      $93 = $37 >>> 3;
      $94 = $93 << 1;
      $95 = 3112 + ($94 << 2) | 0;
      $96 = 1 << $93;
      $97 = $98 & $96;
      $99 = ($97 | 0) == 0;
      if ($99) {
       $100 = $98 | $96;
       SAFE_HEAP_STORE(768 * 4 | 0, $100 | 0, 4);
       $$pre = $95 + 8 | 0;
       $$0199 = $95;
       $$pre$phiZ2D = $$pre;
      } else {
       $101 = $95 + 8 | 0;
       $102 = SAFE_HEAP_LOAD($101 | 0, 4, 0) | 0 | 0;
       $103 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
       $104 = $102 >>> 0 < $103 >>> 0;
       if ($104) {
        _abort();
       } else {
        $$0199 = $102;
        $$pre$phiZ2D = $101;
       }
      }
      SAFE_HEAP_STORE($$pre$phiZ2D | 0, $92 | 0, 4);
      $105 = $$0199 + 12 | 0;
      SAFE_HEAP_STORE($105 | 0, $92 | 0, 4);
      $106 = $92 + 8 | 0;
      SAFE_HEAP_STORE($106 | 0, $$0199 | 0, 4);
      $107 = $92 + 12 | 0;
      SAFE_HEAP_STORE($107 | 0, $95 | 0, 4);
     }
     SAFE_HEAP_STORE(3080 | 0, $84 | 0, 4);
     SAFE_HEAP_STORE(3092 | 0, $87 | 0, 4);
     $$0 = $72;
     STACKTOP = sp;
     return $$0 | 0;
    }
    $108 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
    $109 = ($108 | 0) == 0;
    if ($109) {
     $$0197 = $6;
    } else {
     $110 = 0 - $108 | 0;
     $111 = $108 & $110;
     $112 = $111 + -1 | 0;
     $113 = $112 >>> 12;
     $114 = $113 & 16;
     $115 = $112 >>> $114;
     $116 = $115 >>> 5;
     $117 = $116 & 8;
     $118 = $117 | $114;
     $119 = $115 >>> $117;
     $120 = $119 >>> 2;
     $121 = $120 & 4;
     $122 = $118 | $121;
     $123 = $119 >>> $121;
     $124 = $123 >>> 1;
     $125 = $124 & 2;
     $126 = $122 | $125;
     $127 = $123 >>> $125;
     $128 = $127 >>> 1;
     $129 = $128 & 1;
     $130 = $126 | $129;
     $131 = $127 >>> $129;
     $132 = $130 + $131 | 0;
     $133 = 3376 + ($132 << 2) | 0;
     $134 = SAFE_HEAP_LOAD($133 | 0, 4, 0) | 0 | 0;
     $135 = $134 + 4 | 0;
     $136 = SAFE_HEAP_LOAD($135 | 0, 4, 0) | 0 | 0;
     $137 = $136 & -8;
     $138 = $137 - $6 | 0;
     $139 = $134 + 16 | 0;
     $140 = SAFE_HEAP_LOAD($139 | 0, 4, 0) | 0 | 0;
     $not$5$i = ($140 | 0) == (0 | 0);
     $$sink16$i = $not$5$i & 1;
     $141 = ($134 + 16 | 0) + ($$sink16$i << 2) | 0;
     $142 = SAFE_HEAP_LOAD($141 | 0, 4, 0) | 0 | 0;
     $143 = ($142 | 0) == (0 | 0);
     if ($143) {
      $$0192$lcssa$i = $134;
      $$0193$lcssa$i = $138;
     } else {
      $$01928$i = $134;
      $$01937$i = $138;
      $145 = $142;
      while (1) {
       $144 = $145 + 4 | 0;
       $146 = SAFE_HEAP_LOAD($144 | 0, 4, 0) | 0 | 0;
       $147 = $146 & -8;
       $148 = $147 - $6 | 0;
       $149 = $148 >>> 0 < $$01937$i >>> 0;
       $$$0193$i = $149 ? $148 : $$01937$i;
       $$$0192$i = $149 ? $145 : $$01928$i;
       $150 = $145 + 16 | 0;
       $151 = SAFE_HEAP_LOAD($150 | 0, 4, 0) | 0 | 0;
       $not$$i = ($151 | 0) == (0 | 0);
       $$sink1$i = $not$$i & 1;
       $152 = ($145 + 16 | 0) + ($$sink1$i << 2) | 0;
       $153 = SAFE_HEAP_LOAD($152 | 0, 4, 0) | 0 | 0;
       $154 = ($153 | 0) == (0 | 0);
       if ($154) {
        $$0192$lcssa$i = $$$0192$i;
        $$0193$lcssa$i = $$$0193$i;
        break;
       } else {
        $$01928$i = $$$0192$i;
        $$01937$i = $$$0193$i;
        $145 = $153;
       }
      }
     }
     $155 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $156 = $$0192$lcssa$i >>> 0 < $155 >>> 0;
     if ($156) {
      _abort();
     }
     $157 = $$0192$lcssa$i + $6 | 0;
     $158 = $$0192$lcssa$i >>> 0 < $157 >>> 0;
     if (!$158) {
      _abort();
     }
     $159 = $$0192$lcssa$i + 24 | 0;
     $160 = SAFE_HEAP_LOAD($159 | 0, 4, 0) | 0 | 0;
     $161 = $$0192$lcssa$i + 12 | 0;
     $162 = SAFE_HEAP_LOAD($161 | 0, 4, 0) | 0 | 0;
     $163 = ($162 | 0) == ($$0192$lcssa$i | 0);
     do {
      if ($163) {
       $173 = $$0192$lcssa$i + 20 | 0;
       $174 = SAFE_HEAP_LOAD($173 | 0, 4, 0) | 0 | 0;
       $175 = ($174 | 0) == (0 | 0);
       if ($175) {
        $176 = $$0192$lcssa$i + 16 | 0;
        $177 = SAFE_HEAP_LOAD($176 | 0, 4, 0) | 0 | 0;
        $178 = ($177 | 0) == (0 | 0);
        if ($178) {
         $$3$i = 0;
         break;
        } else {
         $$1196$i = $177;
         $$1198$i = $176;
        }
       } else {
        $$1196$i = $174;
        $$1198$i = $173;
       }
       while (1) {
        $179 = $$1196$i + 20 | 0;
        $180 = SAFE_HEAP_LOAD($179 | 0, 4, 0) | 0 | 0;
        $181 = ($180 | 0) == (0 | 0);
        if (!$181) {
         $$1196$i = $180;
         $$1198$i = $179;
         continue;
        }
        $182 = $$1196$i + 16 | 0;
        $183 = SAFE_HEAP_LOAD($182 | 0, 4, 0) | 0 | 0;
        $184 = ($183 | 0) == (0 | 0);
        if ($184) {
         break;
        } else {
         $$1196$i = $183;
         $$1198$i = $182;
        }
       }
       $185 = $$1198$i >>> 0 < $155 >>> 0;
       if ($185) {
        _abort();
       } else {
        SAFE_HEAP_STORE($$1198$i | 0, 0 | 0, 4);
        $$3$i = $$1196$i;
        break;
       }
      } else {
       $164 = $$0192$lcssa$i + 8 | 0;
       $165 = SAFE_HEAP_LOAD($164 | 0, 4, 0) | 0 | 0;
       $166 = $165 >>> 0 < $155 >>> 0;
       if ($166) {
        _abort();
       }
       $167 = $165 + 12 | 0;
       $168 = SAFE_HEAP_LOAD($167 | 0, 4, 0) | 0 | 0;
       $169 = ($168 | 0) == ($$0192$lcssa$i | 0);
       if (!$169) {
        _abort();
       }
       $170 = $162 + 8 | 0;
       $171 = SAFE_HEAP_LOAD($170 | 0, 4, 0) | 0 | 0;
       $172 = ($171 | 0) == ($$0192$lcssa$i | 0);
       if ($172) {
        SAFE_HEAP_STORE($167 | 0, $162 | 0, 4);
        SAFE_HEAP_STORE($170 | 0, $165 | 0, 4);
        $$3$i = $162;
        break;
       } else {
        _abort();
       }
      }
     } while (0);
     $186 = ($160 | 0) == (0 | 0);
     L73 : do {
      if (!$186) {
       $187 = $$0192$lcssa$i + 28 | 0;
       $188 = SAFE_HEAP_LOAD($187 | 0, 4, 0) | 0 | 0;
       $189 = 3376 + ($188 << 2) | 0;
       $190 = SAFE_HEAP_LOAD($189 | 0, 4, 0) | 0 | 0;
       $191 = ($$0192$lcssa$i | 0) == ($190 | 0);
       do {
        if ($191) {
         SAFE_HEAP_STORE($189 | 0, $$3$i | 0, 4);
         $cond$i = ($$3$i | 0) == (0 | 0);
         if ($cond$i) {
          $192 = 1 << $188;
          $193 = $192 ^ -1;
          $194 = $108 & $193;
          SAFE_HEAP_STORE(3076 | 0, $194 | 0, 4);
          break L73;
         }
        } else {
         $195 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
         $196 = $160 >>> 0 < $195 >>> 0;
         if ($196) {
          _abort();
         } else {
          $197 = $160 + 16 | 0;
          $198 = SAFE_HEAP_LOAD($197 | 0, 4, 0) | 0 | 0;
          $not$1$i = ($198 | 0) != ($$0192$lcssa$i | 0);
          $$sink2$i = $not$1$i & 1;
          $199 = ($160 + 16 | 0) + ($$sink2$i << 2) | 0;
          SAFE_HEAP_STORE($199 | 0, $$3$i | 0, 4);
          $200 = ($$3$i | 0) == (0 | 0);
          if ($200) {
           break L73;
          } else {
           break;
          }
         }
        }
       } while (0);
       $201 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
       $202 = $$3$i >>> 0 < $201 >>> 0;
       if ($202) {
        _abort();
       }
       $203 = $$3$i + 24 | 0;
       SAFE_HEAP_STORE($203 | 0, $160 | 0, 4);
       $204 = $$0192$lcssa$i + 16 | 0;
       $205 = SAFE_HEAP_LOAD($204 | 0, 4, 0) | 0 | 0;
       $206 = ($205 | 0) == (0 | 0);
       do {
        if (!$206) {
         $207 = $205 >>> 0 < $201 >>> 0;
         if ($207) {
          _abort();
         } else {
          $208 = $$3$i + 16 | 0;
          SAFE_HEAP_STORE($208 | 0, $205 | 0, 4);
          $209 = $205 + 24 | 0;
          SAFE_HEAP_STORE($209 | 0, $$3$i | 0, 4);
          break;
         }
        }
       } while (0);
       $210 = $$0192$lcssa$i + 20 | 0;
       $211 = SAFE_HEAP_LOAD($210 | 0, 4, 0) | 0 | 0;
       $212 = ($211 | 0) == (0 | 0);
       if (!$212) {
        $213 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
        $214 = $211 >>> 0 < $213 >>> 0;
        if ($214) {
         _abort();
        } else {
         $215 = $$3$i + 20 | 0;
         SAFE_HEAP_STORE($215 | 0, $211 | 0, 4);
         $216 = $211 + 24 | 0;
         SAFE_HEAP_STORE($216 | 0, $$3$i | 0, 4);
         break;
        }
       }
      }
     } while (0);
     $217 = $$0193$lcssa$i >>> 0 < 16;
     if ($217) {
      $218 = $$0193$lcssa$i + $6 | 0;
      $219 = $218 | 3;
      $220 = $$0192$lcssa$i + 4 | 0;
      SAFE_HEAP_STORE($220 | 0, $219 | 0, 4);
      $221 = $$0192$lcssa$i + $218 | 0;
      $222 = $221 + 4 | 0;
      $223 = SAFE_HEAP_LOAD($222 | 0, 4, 0) | 0 | 0;
      $224 = $223 | 1;
      SAFE_HEAP_STORE($222 | 0, $224 | 0, 4);
     } else {
      $225 = $6 | 3;
      $226 = $$0192$lcssa$i + 4 | 0;
      SAFE_HEAP_STORE($226 | 0, $225 | 0, 4);
      $227 = $$0193$lcssa$i | 1;
      $228 = $157 + 4 | 0;
      SAFE_HEAP_STORE($228 | 0, $227 | 0, 4);
      $229 = $157 + $$0193$lcssa$i | 0;
      SAFE_HEAP_STORE($229 | 0, $$0193$lcssa$i | 0, 4);
      $230 = ($37 | 0) == 0;
      if (!$230) {
       $231 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
       $232 = $37 >>> 3;
       $233 = $232 << 1;
       $234 = 3112 + ($233 << 2) | 0;
       $235 = 1 << $232;
       $236 = $8 & $235;
       $237 = ($236 | 0) == 0;
       if ($237) {
        $238 = $8 | $235;
        SAFE_HEAP_STORE(768 * 4 | 0, $238 | 0, 4);
        $$pre$i = $234 + 8 | 0;
        $$0189$i = $234;
        $$pre$phi$iZ2D = $$pre$i;
       } else {
        $239 = $234 + 8 | 0;
        $240 = SAFE_HEAP_LOAD($239 | 0, 4, 0) | 0 | 0;
        $241 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
        $242 = $240 >>> 0 < $241 >>> 0;
        if ($242) {
         _abort();
        } else {
         $$0189$i = $240;
         $$pre$phi$iZ2D = $239;
        }
       }
       SAFE_HEAP_STORE($$pre$phi$iZ2D | 0, $231 | 0, 4);
       $243 = $$0189$i + 12 | 0;
       SAFE_HEAP_STORE($243 | 0, $231 | 0, 4);
       $244 = $231 + 8 | 0;
       SAFE_HEAP_STORE($244 | 0, $$0189$i | 0, 4);
       $245 = $231 + 12 | 0;
       SAFE_HEAP_STORE($245 | 0, $234 | 0, 4);
      }
      SAFE_HEAP_STORE(3080 | 0, $$0193$lcssa$i | 0, 4);
      SAFE_HEAP_STORE(3092 | 0, $157 | 0, 4);
     }
     $246 = $$0192$lcssa$i + 8 | 0;
     $$0 = $246;
     STACKTOP = sp;
     return $$0 | 0;
    }
   } else {
    $$0197 = $6;
   }
  } else {
   $247 = $0 >>> 0 > 4294967231;
   if ($247) {
    $$0197 = -1;
   } else {
    $248 = $0 + 11 | 0;
    $249 = $248 & -8;
    $250 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
    $251 = ($250 | 0) == 0;
    if ($251) {
     $$0197 = $249;
    } else {
     $252 = 0 - $249 | 0;
     $253 = $248 >>> 8;
     $254 = ($253 | 0) == 0;
     if ($254) {
      $$0358$i = 0;
     } else {
      $255 = $249 >>> 0 > 16777215;
      if ($255) {
       $$0358$i = 31;
      } else {
       $256 = $253 + 1048320 | 0;
       $257 = $256 >>> 16;
       $258 = $257 & 8;
       $259 = $253 << $258;
       $260 = $259 + 520192 | 0;
       $261 = $260 >>> 16;
       $262 = $261 & 4;
       $263 = $262 | $258;
       $264 = $259 << $262;
       $265 = $264 + 245760 | 0;
       $266 = $265 >>> 16;
       $267 = $266 & 2;
       $268 = $263 | $267;
       $269 = 14 - $268 | 0;
       $270 = $264 << $267;
       $271 = $270 >>> 15;
       $272 = $269 + $271 | 0;
       $273 = $272 << 1;
       $274 = $272 + 7 | 0;
       $275 = $249 >>> $274;
       $276 = $275 & 1;
       $277 = $276 | $273;
       $$0358$i = $277;
      }
     }
     $278 = 3376 + ($$0358$i << 2) | 0;
     $279 = SAFE_HEAP_LOAD($278 | 0, 4, 0) | 0 | 0;
     $280 = ($279 | 0) == (0 | 0);
     L117 : do {
      if ($280) {
       $$2355$i = 0;
       $$3$i201 = 0;
       $$3350$i = $252;
       label = 81;
      } else {
       $281 = ($$0358$i | 0) == 31;
       $282 = $$0358$i >>> 1;
       $283 = 25 - $282 | 0;
       $284 = $281 ? 0 : $283;
       $285 = $249 << $284;
       $$0342$i = 0;
       $$0347$i = $252;
       $$0353$i = $279;
       $$0359$i = $285;
       $$0362$i = 0;
       while (1) {
        $286 = $$0353$i + 4 | 0;
        $287 = SAFE_HEAP_LOAD($286 | 0, 4, 0) | 0 | 0;
        $288 = $287 & -8;
        $289 = $288 - $249 | 0;
        $290 = $289 >>> 0 < $$0347$i >>> 0;
        if ($290) {
         $291 = ($289 | 0) == 0;
         if ($291) {
          $$415$i = $$0353$i;
          $$435114$i = 0;
          $$435713$i = $$0353$i;
          label = 85;
          break L117;
         } else {
          $$1343$i = $$0353$i;
          $$1348$i = $289;
         }
        } else {
         $$1343$i = $$0342$i;
         $$1348$i = $$0347$i;
        }
        $292 = $$0353$i + 20 | 0;
        $293 = SAFE_HEAP_LOAD($292 | 0, 4, 0) | 0 | 0;
        $294 = $$0359$i >>> 31;
        $295 = ($$0353$i + 16 | 0) + ($294 << 2) | 0;
        $296 = SAFE_HEAP_LOAD($295 | 0, 4, 0) | 0 | 0;
        $297 = ($293 | 0) == (0 | 0);
        $298 = ($293 | 0) == ($296 | 0);
        $or$cond2$i = $297 | $298;
        $$1363$i = $or$cond2$i ? $$0362$i : $293;
        $299 = ($296 | 0) == (0 | 0);
        $not$8$i = $299 ^ 1;
        $300 = $not$8$i & 1;
        $$0359$$i = $$0359$i << $300;
        if ($299) {
         $$2355$i = $$1363$i;
         $$3$i201 = $$1343$i;
         $$3350$i = $$1348$i;
         label = 81;
         break;
        } else {
         $$0342$i = $$1343$i;
         $$0347$i = $$1348$i;
         $$0353$i = $296;
         $$0359$i = $$0359$$i;
         $$0362$i = $$1363$i;
        }
       }
      }
     } while (0);
     if ((label | 0) == 81) {
      $301 = ($$2355$i | 0) == (0 | 0);
      $302 = ($$3$i201 | 0) == (0 | 0);
      $or$cond$i = $301 & $302;
      if ($or$cond$i) {
       $303 = 2 << $$0358$i;
       $304 = 0 - $303 | 0;
       $305 = $303 | $304;
       $306 = $250 & $305;
       $307 = ($306 | 0) == 0;
       if ($307) {
        $$0197 = $249;
        break;
       }
       $308 = 0 - $306 | 0;
       $309 = $306 & $308;
       $310 = $309 + -1 | 0;
       $311 = $310 >>> 12;
       $312 = $311 & 16;
       $313 = $310 >>> $312;
       $314 = $313 >>> 5;
       $315 = $314 & 8;
       $316 = $315 | $312;
       $317 = $313 >>> $315;
       $318 = $317 >>> 2;
       $319 = $318 & 4;
       $320 = $316 | $319;
       $321 = $317 >>> $319;
       $322 = $321 >>> 1;
       $323 = $322 & 2;
       $324 = $320 | $323;
       $325 = $321 >>> $323;
       $326 = $325 >>> 1;
       $327 = $326 & 1;
       $328 = $324 | $327;
       $329 = $325 >>> $327;
       $330 = $328 + $329 | 0;
       $331 = 3376 + ($330 << 2) | 0;
       $332 = SAFE_HEAP_LOAD($331 | 0, 4, 0) | 0 | 0;
       $$4$ph$i = 0;
       $$4357$ph$i = $332;
      } else {
       $$4$ph$i = $$3$i201;
       $$4357$ph$i = $$2355$i;
      }
      $333 = ($$4357$ph$i | 0) == (0 | 0);
      if ($333) {
       $$4$lcssa$i = $$4$ph$i;
       $$4351$lcssa$i = $$3350$i;
      } else {
       $$415$i = $$4$ph$i;
       $$435114$i = $$3350$i;
       $$435713$i = $$4357$ph$i;
       label = 85;
      }
     }
     if ((label | 0) == 85) {
      while (1) {
       label = 0;
       $334 = $$435713$i + 4 | 0;
       $335 = SAFE_HEAP_LOAD($334 | 0, 4, 0) | 0 | 0;
       $336 = $335 & -8;
       $337 = $336 - $249 | 0;
       $338 = $337 >>> 0 < $$435114$i >>> 0;
       $$$4351$i = $338 ? $337 : $$435114$i;
       $$4357$$4$i = $338 ? $$435713$i : $$415$i;
       $339 = $$435713$i + 16 | 0;
       $340 = SAFE_HEAP_LOAD($339 | 0, 4, 0) | 0 | 0;
       $not$1$i203 = ($340 | 0) == (0 | 0);
       $$sink2$i204 = $not$1$i203 & 1;
       $341 = ($$435713$i + 16 | 0) + ($$sink2$i204 << 2) | 0;
       $342 = SAFE_HEAP_LOAD($341 | 0, 4, 0) | 0 | 0;
       $343 = ($342 | 0) == (0 | 0);
       if ($343) {
        $$4$lcssa$i = $$4357$$4$i;
        $$4351$lcssa$i = $$$4351$i;
        break;
       } else {
        $$415$i = $$4357$$4$i;
        $$435114$i = $$$4351$i;
        $$435713$i = $342;
        label = 85;
       }
      }
     }
     $344 = ($$4$lcssa$i | 0) == (0 | 0);
     if ($344) {
      $$0197 = $249;
     } else {
      $345 = SAFE_HEAP_LOAD(3080 | 0, 4, 0) | 0 | 0;
      $346 = $345 - $249 | 0;
      $347 = $$4351$lcssa$i >>> 0 < $346 >>> 0;
      if ($347) {
       $348 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
       $349 = $$4$lcssa$i >>> 0 < $348 >>> 0;
       if ($349) {
        _abort();
       }
       $350 = $$4$lcssa$i + $249 | 0;
       $351 = $$4$lcssa$i >>> 0 < $350 >>> 0;
       if (!$351) {
        _abort();
       }
       $352 = $$4$lcssa$i + 24 | 0;
       $353 = SAFE_HEAP_LOAD($352 | 0, 4, 0) | 0 | 0;
       $354 = $$4$lcssa$i + 12 | 0;
       $355 = SAFE_HEAP_LOAD($354 | 0, 4, 0) | 0 | 0;
       $356 = ($355 | 0) == ($$4$lcssa$i | 0);
       do {
        if ($356) {
         $366 = $$4$lcssa$i + 20 | 0;
         $367 = SAFE_HEAP_LOAD($366 | 0, 4, 0) | 0 | 0;
         $368 = ($367 | 0) == (0 | 0);
         if ($368) {
          $369 = $$4$lcssa$i + 16 | 0;
          $370 = SAFE_HEAP_LOAD($369 | 0, 4, 0) | 0 | 0;
          $371 = ($370 | 0) == (0 | 0);
          if ($371) {
           $$3372$i = 0;
           break;
          } else {
           $$1370$i = $370;
           $$1374$i = $369;
          }
         } else {
          $$1370$i = $367;
          $$1374$i = $366;
         }
         while (1) {
          $372 = $$1370$i + 20 | 0;
          $373 = SAFE_HEAP_LOAD($372 | 0, 4, 0) | 0 | 0;
          $374 = ($373 | 0) == (0 | 0);
          if (!$374) {
           $$1370$i = $373;
           $$1374$i = $372;
           continue;
          }
          $375 = $$1370$i + 16 | 0;
          $376 = SAFE_HEAP_LOAD($375 | 0, 4, 0) | 0 | 0;
          $377 = ($376 | 0) == (0 | 0);
          if ($377) {
           break;
          } else {
           $$1370$i = $376;
           $$1374$i = $375;
          }
         }
         $378 = $$1374$i >>> 0 < $348 >>> 0;
         if ($378) {
          _abort();
         } else {
          SAFE_HEAP_STORE($$1374$i | 0, 0 | 0, 4);
          $$3372$i = $$1370$i;
          break;
         }
        } else {
         $357 = $$4$lcssa$i + 8 | 0;
         $358 = SAFE_HEAP_LOAD($357 | 0, 4, 0) | 0 | 0;
         $359 = $358 >>> 0 < $348 >>> 0;
         if ($359) {
          _abort();
         }
         $360 = $358 + 12 | 0;
         $361 = SAFE_HEAP_LOAD($360 | 0, 4, 0) | 0 | 0;
         $362 = ($361 | 0) == ($$4$lcssa$i | 0);
         if (!$362) {
          _abort();
         }
         $363 = $355 + 8 | 0;
         $364 = SAFE_HEAP_LOAD($363 | 0, 4, 0) | 0 | 0;
         $365 = ($364 | 0) == ($$4$lcssa$i | 0);
         if ($365) {
          SAFE_HEAP_STORE($360 | 0, $355 | 0, 4);
          SAFE_HEAP_STORE($363 | 0, $358 | 0, 4);
          $$3372$i = $355;
          break;
         } else {
          _abort();
         }
        }
       } while (0);
       $379 = ($353 | 0) == (0 | 0);
       L164 : do {
        if ($379) {
         $470 = $250;
        } else {
         $380 = $$4$lcssa$i + 28 | 0;
         $381 = SAFE_HEAP_LOAD($380 | 0, 4, 0) | 0 | 0;
         $382 = 3376 + ($381 << 2) | 0;
         $383 = SAFE_HEAP_LOAD($382 | 0, 4, 0) | 0 | 0;
         $384 = ($$4$lcssa$i | 0) == ($383 | 0);
         do {
          if ($384) {
           SAFE_HEAP_STORE($382 | 0, $$3372$i | 0, 4);
           $cond$i208 = ($$3372$i | 0) == (0 | 0);
           if ($cond$i208) {
            $385 = 1 << $381;
            $386 = $385 ^ -1;
            $387 = $250 & $386;
            SAFE_HEAP_STORE(3076 | 0, $387 | 0, 4);
            $470 = $387;
            break L164;
           }
          } else {
           $388 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
           $389 = $353 >>> 0 < $388 >>> 0;
           if ($389) {
            _abort();
           } else {
            $390 = $353 + 16 | 0;
            $391 = SAFE_HEAP_LOAD($390 | 0, 4, 0) | 0 | 0;
            $not$$i209 = ($391 | 0) != ($$4$lcssa$i | 0);
            $$sink3$i = $not$$i209 & 1;
            $392 = ($353 + 16 | 0) + ($$sink3$i << 2) | 0;
            SAFE_HEAP_STORE($392 | 0, $$3372$i | 0, 4);
            $393 = ($$3372$i | 0) == (0 | 0);
            if ($393) {
             $470 = $250;
             break L164;
            } else {
             break;
            }
           }
          }
         } while (0);
         $394 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
         $395 = $$3372$i >>> 0 < $394 >>> 0;
         if ($395) {
          _abort();
         }
         $396 = $$3372$i + 24 | 0;
         SAFE_HEAP_STORE($396 | 0, $353 | 0, 4);
         $397 = $$4$lcssa$i + 16 | 0;
         $398 = SAFE_HEAP_LOAD($397 | 0, 4, 0) | 0 | 0;
         $399 = ($398 | 0) == (0 | 0);
         do {
          if (!$399) {
           $400 = $398 >>> 0 < $394 >>> 0;
           if ($400) {
            _abort();
           } else {
            $401 = $$3372$i + 16 | 0;
            SAFE_HEAP_STORE($401 | 0, $398 | 0, 4);
            $402 = $398 + 24 | 0;
            SAFE_HEAP_STORE($402 | 0, $$3372$i | 0, 4);
            break;
           }
          }
         } while (0);
         $403 = $$4$lcssa$i + 20 | 0;
         $404 = SAFE_HEAP_LOAD($403 | 0, 4, 0) | 0 | 0;
         $405 = ($404 | 0) == (0 | 0);
         if ($405) {
          $470 = $250;
         } else {
          $406 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
          $407 = $404 >>> 0 < $406 >>> 0;
          if ($407) {
           _abort();
          } else {
           $408 = $$3372$i + 20 | 0;
           SAFE_HEAP_STORE($408 | 0, $404 | 0, 4);
           $409 = $404 + 24 | 0;
           SAFE_HEAP_STORE($409 | 0, $$3372$i | 0, 4);
           $470 = $250;
           break;
          }
         }
        }
       } while (0);
       $410 = $$4351$lcssa$i >>> 0 < 16;
       do {
        if ($410) {
         $411 = $$4351$lcssa$i + $249 | 0;
         $412 = $411 | 3;
         $413 = $$4$lcssa$i + 4 | 0;
         SAFE_HEAP_STORE($413 | 0, $412 | 0, 4);
         $414 = $$4$lcssa$i + $411 | 0;
         $415 = $414 + 4 | 0;
         $416 = SAFE_HEAP_LOAD($415 | 0, 4, 0) | 0 | 0;
         $417 = $416 | 1;
         SAFE_HEAP_STORE($415 | 0, $417 | 0, 4);
        } else {
         $418 = $249 | 3;
         $419 = $$4$lcssa$i + 4 | 0;
         SAFE_HEAP_STORE($419 | 0, $418 | 0, 4);
         $420 = $$4351$lcssa$i | 1;
         $421 = $350 + 4 | 0;
         SAFE_HEAP_STORE($421 | 0, $420 | 0, 4);
         $422 = $350 + $$4351$lcssa$i | 0;
         SAFE_HEAP_STORE($422 | 0, $$4351$lcssa$i | 0, 4);
         $423 = $$4351$lcssa$i >>> 3;
         $424 = $$4351$lcssa$i >>> 0 < 256;
         if ($424) {
          $425 = $423 << 1;
          $426 = 3112 + ($425 << 2) | 0;
          $427 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
          $428 = 1 << $423;
          $429 = $427 & $428;
          $430 = ($429 | 0) == 0;
          if ($430) {
           $431 = $427 | $428;
           SAFE_HEAP_STORE(768 * 4 | 0, $431 | 0, 4);
           $$pre$i210 = $426 + 8 | 0;
           $$0368$i = $426;
           $$pre$phi$i211Z2D = $$pre$i210;
          } else {
           $432 = $426 + 8 | 0;
           $433 = SAFE_HEAP_LOAD($432 | 0, 4, 0) | 0 | 0;
           $434 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
           $435 = $433 >>> 0 < $434 >>> 0;
           if ($435) {
            _abort();
           } else {
            $$0368$i = $433;
            $$pre$phi$i211Z2D = $432;
           }
          }
          SAFE_HEAP_STORE($$pre$phi$i211Z2D | 0, $350 | 0, 4);
          $436 = $$0368$i + 12 | 0;
          SAFE_HEAP_STORE($436 | 0, $350 | 0, 4);
          $437 = $350 + 8 | 0;
          SAFE_HEAP_STORE($437 | 0, $$0368$i | 0, 4);
          $438 = $350 + 12 | 0;
          SAFE_HEAP_STORE($438 | 0, $426 | 0, 4);
          break;
         }
         $439 = $$4351$lcssa$i >>> 8;
         $440 = ($439 | 0) == 0;
         if ($440) {
          $$0361$i = 0;
         } else {
          $441 = $$4351$lcssa$i >>> 0 > 16777215;
          if ($441) {
           $$0361$i = 31;
          } else {
           $442 = $439 + 1048320 | 0;
           $443 = $442 >>> 16;
           $444 = $443 & 8;
           $445 = $439 << $444;
           $446 = $445 + 520192 | 0;
           $447 = $446 >>> 16;
           $448 = $447 & 4;
           $449 = $448 | $444;
           $450 = $445 << $448;
           $451 = $450 + 245760 | 0;
           $452 = $451 >>> 16;
           $453 = $452 & 2;
           $454 = $449 | $453;
           $455 = 14 - $454 | 0;
           $456 = $450 << $453;
           $457 = $456 >>> 15;
           $458 = $455 + $457 | 0;
           $459 = $458 << 1;
           $460 = $458 + 7 | 0;
           $461 = $$4351$lcssa$i >>> $460;
           $462 = $461 & 1;
           $463 = $462 | $459;
           $$0361$i = $463;
          }
         }
         $464 = 3376 + ($$0361$i << 2) | 0;
         $465 = $350 + 28 | 0;
         SAFE_HEAP_STORE($465 | 0, $$0361$i | 0, 4);
         $466 = $350 + 16 | 0;
         $467 = $466 + 4 | 0;
         SAFE_HEAP_STORE($467 | 0, 0 | 0, 4);
         SAFE_HEAP_STORE($466 | 0, 0 | 0, 4);
         $468 = 1 << $$0361$i;
         $469 = $470 & $468;
         $471 = ($469 | 0) == 0;
         if ($471) {
          $472 = $470 | $468;
          SAFE_HEAP_STORE(3076 | 0, $472 | 0, 4);
          SAFE_HEAP_STORE($464 | 0, $350 | 0, 4);
          $473 = $350 + 24 | 0;
          SAFE_HEAP_STORE($473 | 0, $464 | 0, 4);
          $474 = $350 + 12 | 0;
          SAFE_HEAP_STORE($474 | 0, $350 | 0, 4);
          $475 = $350 + 8 | 0;
          SAFE_HEAP_STORE($475 | 0, $350 | 0, 4);
          break;
         }
         $476 = SAFE_HEAP_LOAD($464 | 0, 4, 0) | 0 | 0;
         $477 = ($$0361$i | 0) == 31;
         $478 = $$0361$i >>> 1;
         $479 = 25 - $478 | 0;
         $480 = $477 ? 0 : $479;
         $481 = $$4351$lcssa$i << $480;
         $$0344$i = $481;
         $$0345$i = $476;
         while (1) {
          $482 = $$0345$i + 4 | 0;
          $483 = SAFE_HEAP_LOAD($482 | 0, 4, 0) | 0 | 0;
          $484 = $483 & -8;
          $485 = ($484 | 0) == ($$4351$lcssa$i | 0);
          if ($485) {
           label = 139;
           break;
          }
          $486 = $$0344$i >>> 31;
          $487 = ($$0345$i + 16 | 0) + ($486 << 2) | 0;
          $488 = $$0344$i << 1;
          $489 = SAFE_HEAP_LOAD($487 | 0, 4, 0) | 0 | 0;
          $490 = ($489 | 0) == (0 | 0);
          if ($490) {
           label = 136;
           break;
          } else {
           $$0344$i = $488;
           $$0345$i = $489;
          }
         }
         if ((label | 0) == 136) {
          $491 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
          $492 = $487 >>> 0 < $491 >>> 0;
          if ($492) {
           _abort();
          } else {
           SAFE_HEAP_STORE($487 | 0, $350 | 0, 4);
           $493 = $350 + 24 | 0;
           SAFE_HEAP_STORE($493 | 0, $$0345$i | 0, 4);
           $494 = $350 + 12 | 0;
           SAFE_HEAP_STORE($494 | 0, $350 | 0, 4);
           $495 = $350 + 8 | 0;
           SAFE_HEAP_STORE($495 | 0, $350 | 0, 4);
           break;
          }
         } else if ((label | 0) == 139) {
          $496 = $$0345$i + 8 | 0;
          $497 = SAFE_HEAP_LOAD($496 | 0, 4, 0) | 0 | 0;
          $498 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
          $499 = $497 >>> 0 >= $498 >>> 0;
          $not$9$i = $$0345$i >>> 0 >= $498 >>> 0;
          $500 = $499 & $not$9$i;
          if ($500) {
           $501 = $497 + 12 | 0;
           SAFE_HEAP_STORE($501 | 0, $350 | 0, 4);
           SAFE_HEAP_STORE($496 | 0, $350 | 0, 4);
           $502 = $350 + 8 | 0;
           SAFE_HEAP_STORE($502 | 0, $497 | 0, 4);
           $503 = $350 + 12 | 0;
           SAFE_HEAP_STORE($503 | 0, $$0345$i | 0, 4);
           $504 = $350 + 24 | 0;
           SAFE_HEAP_STORE($504 | 0, 0 | 0, 4);
           break;
          } else {
           _abort();
          }
         }
        }
       } while (0);
       $505 = $$4$lcssa$i + 8 | 0;
       $$0 = $505;
       STACKTOP = sp;
       return $$0 | 0;
      } else {
       $$0197 = $249;
      }
     }
    }
   }
  }
 } while (0);
 $506 = SAFE_HEAP_LOAD(3080 | 0, 4, 0) | 0 | 0;
 $507 = $506 >>> 0 < $$0197 >>> 0;
 if (!$507) {
  $508 = $506 - $$0197 | 0;
  $509 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
  $510 = $508 >>> 0 > 15;
  if ($510) {
   $511 = $509 + $$0197 | 0;
   SAFE_HEAP_STORE(3092 | 0, $511 | 0, 4);
   SAFE_HEAP_STORE(3080 | 0, $508 | 0, 4);
   $512 = $508 | 1;
   $513 = $511 + 4 | 0;
   SAFE_HEAP_STORE($513 | 0, $512 | 0, 4);
   $514 = $511 + $508 | 0;
   SAFE_HEAP_STORE($514 | 0, $508 | 0, 4);
   $515 = $$0197 | 3;
   $516 = $509 + 4 | 0;
   SAFE_HEAP_STORE($516 | 0, $515 | 0, 4);
  } else {
   SAFE_HEAP_STORE(3080 | 0, 0 | 0, 4);
   SAFE_HEAP_STORE(3092 | 0, 0 | 0, 4);
   $517 = $506 | 3;
   $518 = $509 + 4 | 0;
   SAFE_HEAP_STORE($518 | 0, $517 | 0, 4);
   $519 = $509 + $506 | 0;
   $520 = $519 + 4 | 0;
   $521 = SAFE_HEAP_LOAD($520 | 0, 4, 0) | 0 | 0;
   $522 = $521 | 1;
   SAFE_HEAP_STORE($520 | 0, $522 | 0, 4);
  }
  $523 = $509 + 8 | 0;
  $$0 = $523;
  STACKTOP = sp;
  return $$0 | 0;
 }
 $524 = SAFE_HEAP_LOAD(3084 | 0, 4, 0) | 0 | 0;
 $525 = $524 >>> 0 > $$0197 >>> 0;
 if ($525) {
  $526 = $524 - $$0197 | 0;
  SAFE_HEAP_STORE(3084 | 0, $526 | 0, 4);
  $527 = SAFE_HEAP_LOAD(3096 | 0, 4, 0) | 0 | 0;
  $528 = $527 + $$0197 | 0;
  SAFE_HEAP_STORE(3096 | 0, $528 | 0, 4);
  $529 = $526 | 1;
  $530 = $528 + 4 | 0;
  SAFE_HEAP_STORE($530 | 0, $529 | 0, 4);
  $531 = $$0197 | 3;
  $532 = $527 + 4 | 0;
  SAFE_HEAP_STORE($532 | 0, $531 | 0, 4);
  $533 = $527 + 8 | 0;
  $$0 = $533;
  STACKTOP = sp;
  return $$0 | 0;
 }
 $534 = SAFE_HEAP_LOAD(886 * 4 | 0, 4, 0) | 0 | 0;
 $535 = ($534 | 0) == 0;
 if ($535) {
  SAFE_HEAP_STORE(3552 | 0, 4096 | 0, 4);
  SAFE_HEAP_STORE(3548 | 0, 4096 | 0, 4);
  SAFE_HEAP_STORE(3556 | 0, -1 | 0, 4);
  SAFE_HEAP_STORE(3560 | 0, -1 | 0, 4);
  SAFE_HEAP_STORE(3564 | 0, 0 | 0, 4);
  SAFE_HEAP_STORE(3516 | 0, 0 | 0, 4);
  $536 = $1;
  $537 = $536 & -16;
  $538 = $537 ^ 1431655768;
  SAFE_HEAP_STORE($1 | 0, $538 | 0, 4);
  SAFE_HEAP_STORE(886 * 4 | 0, $538 | 0, 4);
  $542 = 4096;
 } else {
  $$pre$i212 = SAFE_HEAP_LOAD(3552 | 0, 4, 0) | 0 | 0;
  $542 = $$pre$i212;
 }
 $539 = $$0197 + 48 | 0;
 $540 = $$0197 + 47 | 0;
 $541 = $542 + $540 | 0;
 $543 = 0 - $542 | 0;
 $544 = $541 & $543;
 $545 = $544 >>> 0 > $$0197 >>> 0;
 if (!$545) {
  $$0 = 0;
  STACKTOP = sp;
  return $$0 | 0;
 }
 $546 = SAFE_HEAP_LOAD(3512 | 0, 4, 0) | 0 | 0;
 $547 = ($546 | 0) == 0;
 if (!$547) {
  $548 = SAFE_HEAP_LOAD(3504 | 0, 4, 0) | 0 | 0;
  $549 = $548 + $544 | 0;
  $550 = $549 >>> 0 <= $548 >>> 0;
  $551 = $549 >>> 0 > $546 >>> 0;
  $or$cond1$i = $550 | $551;
  if ($or$cond1$i) {
   $$0 = 0;
   STACKTOP = sp;
   return $$0 | 0;
  }
 }
 $552 = SAFE_HEAP_LOAD(3516 | 0, 4, 0) | 0 | 0;
 $553 = $552 & 4;
 $554 = ($553 | 0) == 0;
 L244 : do {
  if ($554) {
   $555 = SAFE_HEAP_LOAD(3096 | 0, 4, 0) | 0 | 0;
   $556 = ($555 | 0) == (0 | 0);
   L246 : do {
    if ($556) {
     label = 163;
    } else {
     $$0$i$i = 3520;
     while (1) {
      $557 = SAFE_HEAP_LOAD($$0$i$i | 0, 4, 0) | 0 | 0;
      $558 = $557 >>> 0 > $555 >>> 0;
      if (!$558) {
       $559 = $$0$i$i + 4 | 0;
       $560 = SAFE_HEAP_LOAD($559 | 0, 4, 0) | 0 | 0;
       $561 = $557 + $560 | 0;
       $562 = $561 >>> 0 > $555 >>> 0;
       if ($562) {
        break;
       }
      }
      $563 = $$0$i$i + 8 | 0;
      $564 = SAFE_HEAP_LOAD($563 | 0, 4, 0) | 0 | 0;
      $565 = ($564 | 0) == (0 | 0);
      if ($565) {
       label = 163;
       break L246;
      } else {
       $$0$i$i = $564;
      }
     }
     $588 = $541 - $524 | 0;
     $589 = $588 & $543;
     $590 = $589 >>> 0 < 2147483647;
     if ($590) {
      $591 = _sbrk($589 | 0) | 0;
      $592 = SAFE_HEAP_LOAD($$0$i$i | 0, 4, 0) | 0 | 0;
      $593 = SAFE_HEAP_LOAD($559 | 0, 4, 0) | 0 | 0;
      $594 = $592 + $593 | 0;
      $595 = ($591 | 0) == ($594 | 0);
      if ($595) {
       $596 = ($591 | 0) == (-1 | 0);
       if ($596) {
        $$2234253237$i = $589;
       } else {
        $$723948$i = $589;
        $$749$i = $591;
        label = 180;
        break L244;
       }
      } else {
       $$2247$ph$i = $591;
       $$2253$ph$i = $589;
       label = 171;
      }
     } else {
      $$2234253237$i = 0;
     }
    }
   } while (0);
   do {
    if ((label | 0) == 163) {
     $566 = _sbrk(0) | 0;
     $567 = ($566 | 0) == (-1 | 0);
     if ($567) {
      $$2234253237$i = 0;
     } else {
      $568 = $566;
      $569 = SAFE_HEAP_LOAD(3548 | 0, 4, 0) | 0 | 0;
      $570 = $569 + -1 | 0;
      $571 = $570 & $568;
      $572 = ($571 | 0) == 0;
      $573 = $570 + $568 | 0;
      $574 = 0 - $569 | 0;
      $575 = $573 & $574;
      $576 = $575 - $568 | 0;
      $577 = $572 ? 0 : $576;
      $$$i = $577 + $544 | 0;
      $578 = SAFE_HEAP_LOAD(3504 | 0, 4, 0) | 0 | 0;
      $579 = $$$i + $578 | 0;
      $580 = $$$i >>> 0 > $$0197 >>> 0;
      $581 = $$$i >>> 0 < 2147483647;
      $or$cond$i214 = $580 & $581;
      if ($or$cond$i214) {
       $582 = SAFE_HEAP_LOAD(3512 | 0, 4, 0) | 0 | 0;
       $583 = ($582 | 0) == 0;
       if (!$583) {
        $584 = $579 >>> 0 <= $578 >>> 0;
        $585 = $579 >>> 0 > $582 >>> 0;
        $or$cond2$i215 = $584 | $585;
        if ($or$cond2$i215) {
         $$2234253237$i = 0;
         break;
        }
       }
       $586 = _sbrk($$$i | 0) | 0;
       $587 = ($586 | 0) == ($566 | 0);
       if ($587) {
        $$723948$i = $$$i;
        $$749$i = $566;
        label = 180;
        break L244;
       } else {
        $$2247$ph$i = $586;
        $$2253$ph$i = $$$i;
        label = 171;
       }
      } else {
       $$2234253237$i = 0;
      }
     }
    }
   } while (0);
   do {
    if ((label | 0) == 171) {
     $597 = 0 - $$2253$ph$i | 0;
     $598 = ($$2247$ph$i | 0) != (-1 | 0);
     $599 = $$2253$ph$i >>> 0 < 2147483647;
     $or$cond7$i = $599 & $598;
     $600 = $539 >>> 0 > $$2253$ph$i >>> 0;
     $or$cond10$i = $600 & $or$cond7$i;
     if (!$or$cond10$i) {
      $610 = ($$2247$ph$i | 0) == (-1 | 0);
      if ($610) {
       $$2234253237$i = 0;
       break;
      } else {
       $$723948$i = $$2253$ph$i;
       $$749$i = $$2247$ph$i;
       label = 180;
       break L244;
      }
     }
     $601 = SAFE_HEAP_LOAD(3552 | 0, 4, 0) | 0 | 0;
     $602 = $540 - $$2253$ph$i | 0;
     $603 = $602 + $601 | 0;
     $604 = 0 - $601 | 0;
     $605 = $603 & $604;
     $606 = $605 >>> 0 < 2147483647;
     if (!$606) {
      $$723948$i = $$2253$ph$i;
      $$749$i = $$2247$ph$i;
      label = 180;
      break L244;
     }
     $607 = _sbrk($605 | 0) | 0;
     $608 = ($607 | 0) == (-1 | 0);
     if ($608) {
      _sbrk($597 | 0) | 0;
      $$2234253237$i = 0;
      break;
     } else {
      $609 = $605 + $$2253$ph$i | 0;
      $$723948$i = $609;
      $$749$i = $$2247$ph$i;
      label = 180;
      break L244;
     }
    }
   } while (0);
   $611 = SAFE_HEAP_LOAD(3516 | 0, 4, 0) | 0 | 0;
   $612 = $611 | 4;
   SAFE_HEAP_STORE(3516 | 0, $612 | 0, 4);
   $$4236$i = $$2234253237$i;
   label = 178;
  } else {
   $$4236$i = 0;
   label = 178;
  }
 } while (0);
 if ((label | 0) == 178) {
  $613 = $544 >>> 0 < 2147483647;
  if ($613) {
   $614 = _sbrk($544 | 0) | 0;
   $615 = _sbrk(0) | 0;
   $616 = ($614 | 0) != (-1 | 0);
   $617 = ($615 | 0) != (-1 | 0);
   $or$cond5$i = $616 & $617;
   $618 = $614 >>> 0 < $615 >>> 0;
   $or$cond11$i = $618 & $or$cond5$i;
   $619 = $615;
   $620 = $614;
   $621 = $619 - $620 | 0;
   $622 = $$0197 + 40 | 0;
   $623 = $621 >>> 0 > $622 >>> 0;
   $$$4236$i = $623 ? $621 : $$4236$i;
   $or$cond11$not$i = $or$cond11$i ^ 1;
   $624 = ($614 | 0) == (-1 | 0);
   $not$$i216 = $623 ^ 1;
   $625 = $624 | $not$$i216;
   $or$cond50$i = $625 | $or$cond11$not$i;
   if (!$or$cond50$i) {
    $$723948$i = $$$4236$i;
    $$749$i = $614;
    label = 180;
   }
  }
 }
 if ((label | 0) == 180) {
  $626 = SAFE_HEAP_LOAD(3504 | 0, 4, 0) | 0 | 0;
  $627 = $626 + $$723948$i | 0;
  SAFE_HEAP_STORE(3504 | 0, $627 | 0, 4);
  $628 = SAFE_HEAP_LOAD(3508 | 0, 4, 0) | 0 | 0;
  $629 = $627 >>> 0 > $628 >>> 0;
  if ($629) {
   SAFE_HEAP_STORE(3508 | 0, $627 | 0, 4);
  }
  $630 = SAFE_HEAP_LOAD(3096 | 0, 4, 0) | 0 | 0;
  $631 = ($630 | 0) == (0 | 0);
  do {
   if ($631) {
    $632 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
    $633 = ($632 | 0) == (0 | 0);
    $634 = $$749$i >>> 0 < $632 >>> 0;
    $or$cond12$i = $633 | $634;
    if ($or$cond12$i) {
     SAFE_HEAP_STORE(3088 | 0, $$749$i | 0, 4);
    }
    SAFE_HEAP_STORE(3520 | 0, $$749$i | 0, 4);
    SAFE_HEAP_STORE(3524 | 0, $$723948$i | 0, 4);
    SAFE_HEAP_STORE(3532 | 0, 0 | 0, 4);
    $635 = SAFE_HEAP_LOAD(886 * 4 | 0, 4, 0) | 0 | 0;
    SAFE_HEAP_STORE(3108 | 0, $635 | 0, 4);
    SAFE_HEAP_STORE(3104 | 0, -1 | 0, 4);
    $$01$i$i = 0;
    while (1) {
     $636 = $$01$i$i << 1;
     $637 = 3112 + ($636 << 2) | 0;
     $638 = $637 + 12 | 0;
     SAFE_HEAP_STORE($638 | 0, $637 | 0, 4);
     $639 = $637 + 8 | 0;
     SAFE_HEAP_STORE($639 | 0, $637 | 0, 4);
     $640 = $$01$i$i + 1 | 0;
     $exitcond$i$i = ($640 | 0) == 32;
     if ($exitcond$i$i) {
      break;
     } else {
      $$01$i$i = $640;
     }
    }
    $641 = $$723948$i + -40 | 0;
    $642 = $$749$i + 8 | 0;
    $643 = $642;
    $644 = $643 & 7;
    $645 = ($644 | 0) == 0;
    $646 = 0 - $643 | 0;
    $647 = $646 & 7;
    $648 = $645 ? 0 : $647;
    $649 = $$749$i + $648 | 0;
    $650 = $641 - $648 | 0;
    SAFE_HEAP_STORE(3096 | 0, $649 | 0, 4);
    SAFE_HEAP_STORE(3084 | 0, $650 | 0, 4);
    $651 = $650 | 1;
    $652 = $649 + 4 | 0;
    SAFE_HEAP_STORE($652 | 0, $651 | 0, 4);
    $653 = $649 + $650 | 0;
    $654 = $653 + 4 | 0;
    SAFE_HEAP_STORE($654 | 0, 40 | 0, 4);
    $655 = SAFE_HEAP_LOAD(3560 | 0, 4, 0) | 0 | 0;
    SAFE_HEAP_STORE(3100 | 0, $655 | 0, 4);
   } else {
    $$024371$i = 3520;
    while (1) {
     $656 = SAFE_HEAP_LOAD($$024371$i | 0, 4, 0) | 0 | 0;
     $657 = $$024371$i + 4 | 0;
     $658 = SAFE_HEAP_LOAD($657 | 0, 4, 0) | 0 | 0;
     $659 = $656 + $658 | 0;
     $660 = ($$749$i | 0) == ($659 | 0);
     if ($660) {
      label = 190;
      break;
     }
     $661 = $$024371$i + 8 | 0;
     $662 = SAFE_HEAP_LOAD($661 | 0, 4, 0) | 0 | 0;
     $663 = ($662 | 0) == (0 | 0);
     if ($663) {
      break;
     } else {
      $$024371$i = $662;
     }
    }
    if ((label | 0) == 190) {
     $664 = $$024371$i + 12 | 0;
     $665 = SAFE_HEAP_LOAD($664 | 0, 4, 0) | 0 | 0;
     $666 = $665 & 8;
     $667 = ($666 | 0) == 0;
     if ($667) {
      $668 = $630 >>> 0 >= $656 >>> 0;
      $669 = $630 >>> 0 < $$749$i >>> 0;
      $or$cond51$i = $669 & $668;
      if ($or$cond51$i) {
       $670 = $658 + $$723948$i | 0;
       SAFE_HEAP_STORE($657 | 0, $670 | 0, 4);
       $671 = SAFE_HEAP_LOAD(3084 | 0, 4, 0) | 0 | 0;
       $672 = $630 + 8 | 0;
       $673 = $672;
       $674 = $673 & 7;
       $675 = ($674 | 0) == 0;
       $676 = 0 - $673 | 0;
       $677 = $676 & 7;
       $678 = $675 ? 0 : $677;
       $679 = $630 + $678 | 0;
       $680 = $$723948$i - $678 | 0;
       $681 = $671 + $680 | 0;
       SAFE_HEAP_STORE(3096 | 0, $679 | 0, 4);
       SAFE_HEAP_STORE(3084 | 0, $681 | 0, 4);
       $682 = $681 | 1;
       $683 = $679 + 4 | 0;
       SAFE_HEAP_STORE($683 | 0, $682 | 0, 4);
       $684 = $679 + $681 | 0;
       $685 = $684 + 4 | 0;
       SAFE_HEAP_STORE($685 | 0, 40 | 0, 4);
       $686 = SAFE_HEAP_LOAD(3560 | 0, 4, 0) | 0 | 0;
       SAFE_HEAP_STORE(3100 | 0, $686 | 0, 4);
       break;
      }
     }
    }
    $687 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
    $688 = $$749$i >>> 0 < $687 >>> 0;
    if ($688) {
     SAFE_HEAP_STORE(3088 | 0, $$749$i | 0, 4);
     $752 = $$749$i;
    } else {
     $752 = $687;
    }
    $689 = $$749$i + $$723948$i | 0;
    $$124470$i = 3520;
    while (1) {
     $690 = SAFE_HEAP_LOAD($$124470$i | 0, 4, 0) | 0 | 0;
     $691 = ($690 | 0) == ($689 | 0);
     if ($691) {
      label = 198;
      break;
     }
     $692 = $$124470$i + 8 | 0;
     $693 = SAFE_HEAP_LOAD($692 | 0, 4, 0) | 0 | 0;
     $694 = ($693 | 0) == (0 | 0);
     if ($694) {
      break;
     } else {
      $$124470$i = $693;
     }
    }
    if ((label | 0) == 198) {
     $695 = $$124470$i + 12 | 0;
     $696 = SAFE_HEAP_LOAD($695 | 0, 4, 0) | 0 | 0;
     $697 = $696 & 8;
     $698 = ($697 | 0) == 0;
     if ($698) {
      SAFE_HEAP_STORE($$124470$i | 0, $$749$i | 0, 4);
      $699 = $$124470$i + 4 | 0;
      $700 = SAFE_HEAP_LOAD($699 | 0, 4, 0) | 0 | 0;
      $701 = $700 + $$723948$i | 0;
      SAFE_HEAP_STORE($699 | 0, $701 | 0, 4);
      $702 = $$749$i + 8 | 0;
      $703 = $702;
      $704 = $703 & 7;
      $705 = ($704 | 0) == 0;
      $706 = 0 - $703 | 0;
      $707 = $706 & 7;
      $708 = $705 ? 0 : $707;
      $709 = $$749$i + $708 | 0;
      $710 = $689 + 8 | 0;
      $711 = $710;
      $712 = $711 & 7;
      $713 = ($712 | 0) == 0;
      $714 = 0 - $711 | 0;
      $715 = $714 & 7;
      $716 = $713 ? 0 : $715;
      $717 = $689 + $716 | 0;
      $718 = $717;
      $719 = $709;
      $720 = $718 - $719 | 0;
      $721 = $709 + $$0197 | 0;
      $722 = $720 - $$0197 | 0;
      $723 = $$0197 | 3;
      $724 = $709 + 4 | 0;
      SAFE_HEAP_STORE($724 | 0, $723 | 0, 4);
      $725 = ($717 | 0) == ($630 | 0);
      do {
       if ($725) {
        $726 = SAFE_HEAP_LOAD(3084 | 0, 4, 0) | 0 | 0;
        $727 = $726 + $722 | 0;
        SAFE_HEAP_STORE(3084 | 0, $727 | 0, 4);
        SAFE_HEAP_STORE(3096 | 0, $721 | 0, 4);
        $728 = $727 | 1;
        $729 = $721 + 4 | 0;
        SAFE_HEAP_STORE($729 | 0, $728 | 0, 4);
       } else {
        $730 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
        $731 = ($717 | 0) == ($730 | 0);
        if ($731) {
         $732 = SAFE_HEAP_LOAD(3080 | 0, 4, 0) | 0 | 0;
         $733 = $732 + $722 | 0;
         SAFE_HEAP_STORE(3080 | 0, $733 | 0, 4);
         SAFE_HEAP_STORE(3092 | 0, $721 | 0, 4);
         $734 = $733 | 1;
         $735 = $721 + 4 | 0;
         SAFE_HEAP_STORE($735 | 0, $734 | 0, 4);
         $736 = $721 + $733 | 0;
         SAFE_HEAP_STORE($736 | 0, $733 | 0, 4);
         break;
        }
        $737 = $717 + 4 | 0;
        $738 = SAFE_HEAP_LOAD($737 | 0, 4, 0) | 0 | 0;
        $739 = $738 & 3;
        $740 = ($739 | 0) == 1;
        if ($740) {
         $741 = $738 & -8;
         $742 = $738 >>> 3;
         $743 = $738 >>> 0 < 256;
         L314 : do {
          if ($743) {
           $744 = $717 + 8 | 0;
           $745 = SAFE_HEAP_LOAD($744 | 0, 4, 0) | 0 | 0;
           $746 = $717 + 12 | 0;
           $747 = SAFE_HEAP_LOAD($746 | 0, 4, 0) | 0 | 0;
           $748 = $742 << 1;
           $749 = 3112 + ($748 << 2) | 0;
           $750 = ($745 | 0) == ($749 | 0);
           do {
            if (!$750) {
             $751 = $745 >>> 0 < $752 >>> 0;
             if ($751) {
              _abort();
             }
             $753 = $745 + 12 | 0;
             $754 = SAFE_HEAP_LOAD($753 | 0, 4, 0) | 0 | 0;
             $755 = ($754 | 0) == ($717 | 0);
             if ($755) {
              break;
             }
             _abort();
            }
           } while (0);
           $756 = ($747 | 0) == ($745 | 0);
           if ($756) {
            $757 = 1 << $742;
            $758 = $757 ^ -1;
            $759 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
            $760 = $759 & $758;
            SAFE_HEAP_STORE(768 * 4 | 0, $760 | 0, 4);
            break;
           }
           $761 = ($747 | 0) == ($749 | 0);
           do {
            if ($761) {
             $$pre10$i$i = $747 + 8 | 0;
             $$pre$phi11$i$iZ2D = $$pre10$i$i;
            } else {
             $762 = $747 >>> 0 < $752 >>> 0;
             if ($762) {
              _abort();
             }
             $763 = $747 + 8 | 0;
             $764 = SAFE_HEAP_LOAD($763 | 0, 4, 0) | 0 | 0;
             $765 = ($764 | 0) == ($717 | 0);
             if ($765) {
              $$pre$phi11$i$iZ2D = $763;
              break;
             }
             _abort();
            }
           } while (0);
           $766 = $745 + 12 | 0;
           SAFE_HEAP_STORE($766 | 0, $747 | 0, 4);
           SAFE_HEAP_STORE($$pre$phi11$i$iZ2D | 0, $745 | 0, 4);
          } else {
           $767 = $717 + 24 | 0;
           $768 = SAFE_HEAP_LOAD($767 | 0, 4, 0) | 0 | 0;
           $769 = $717 + 12 | 0;
           $770 = SAFE_HEAP_LOAD($769 | 0, 4, 0) | 0 | 0;
           $771 = ($770 | 0) == ($717 | 0);
           do {
            if ($771) {
             $781 = $717 + 16 | 0;
             $782 = $781 + 4 | 0;
             $783 = SAFE_HEAP_LOAD($782 | 0, 4, 0) | 0 | 0;
             $784 = ($783 | 0) == (0 | 0);
             if ($784) {
              $785 = SAFE_HEAP_LOAD($781 | 0, 4, 0) | 0 | 0;
              $786 = ($785 | 0) == (0 | 0);
              if ($786) {
               $$3$i$i = 0;
               break;
              } else {
               $$1291$i$i = $785;
               $$1293$i$i = $781;
              }
             } else {
              $$1291$i$i = $783;
              $$1293$i$i = $782;
             }
             while (1) {
              $787 = $$1291$i$i + 20 | 0;
              $788 = SAFE_HEAP_LOAD($787 | 0, 4, 0) | 0 | 0;
              $789 = ($788 | 0) == (0 | 0);
              if (!$789) {
               $$1291$i$i = $788;
               $$1293$i$i = $787;
               continue;
              }
              $790 = $$1291$i$i + 16 | 0;
              $791 = SAFE_HEAP_LOAD($790 | 0, 4, 0) | 0 | 0;
              $792 = ($791 | 0) == (0 | 0);
              if ($792) {
               break;
              } else {
               $$1291$i$i = $791;
               $$1293$i$i = $790;
              }
             }
             $793 = $$1293$i$i >>> 0 < $752 >>> 0;
             if ($793) {
              _abort();
             } else {
              SAFE_HEAP_STORE($$1293$i$i | 0, 0 | 0, 4);
              $$3$i$i = $$1291$i$i;
              break;
             }
            } else {
             $772 = $717 + 8 | 0;
             $773 = SAFE_HEAP_LOAD($772 | 0, 4, 0) | 0 | 0;
             $774 = $773 >>> 0 < $752 >>> 0;
             if ($774) {
              _abort();
             }
             $775 = $773 + 12 | 0;
             $776 = SAFE_HEAP_LOAD($775 | 0, 4, 0) | 0 | 0;
             $777 = ($776 | 0) == ($717 | 0);
             if (!$777) {
              _abort();
             }
             $778 = $770 + 8 | 0;
             $779 = SAFE_HEAP_LOAD($778 | 0, 4, 0) | 0 | 0;
             $780 = ($779 | 0) == ($717 | 0);
             if ($780) {
              SAFE_HEAP_STORE($775 | 0, $770 | 0, 4);
              SAFE_HEAP_STORE($778 | 0, $773 | 0, 4);
              $$3$i$i = $770;
              break;
             } else {
              _abort();
             }
            }
           } while (0);
           $794 = ($768 | 0) == (0 | 0);
           if ($794) {
            break;
           }
           $795 = $717 + 28 | 0;
           $796 = SAFE_HEAP_LOAD($795 | 0, 4, 0) | 0 | 0;
           $797 = 3376 + ($796 << 2) | 0;
           $798 = SAFE_HEAP_LOAD($797 | 0, 4, 0) | 0 | 0;
           $799 = ($717 | 0) == ($798 | 0);
           do {
            if ($799) {
             SAFE_HEAP_STORE($797 | 0, $$3$i$i | 0, 4);
             $cond$i$i = ($$3$i$i | 0) == (0 | 0);
             if (!$cond$i$i) {
              break;
             }
             $800 = 1 << $796;
             $801 = $800 ^ -1;
             $802 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
             $803 = $802 & $801;
             SAFE_HEAP_STORE(3076 | 0, $803 | 0, 4);
             break L314;
            } else {
             $804 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
             $805 = $768 >>> 0 < $804 >>> 0;
             if ($805) {
              _abort();
             } else {
              $806 = $768 + 16 | 0;
              $807 = SAFE_HEAP_LOAD($806 | 0, 4, 0) | 0 | 0;
              $not$$i17$i = ($807 | 0) != ($717 | 0);
              $$sink1$i$i = $not$$i17$i & 1;
              $808 = ($768 + 16 | 0) + ($$sink1$i$i << 2) | 0;
              SAFE_HEAP_STORE($808 | 0, $$3$i$i | 0, 4);
              $809 = ($$3$i$i | 0) == (0 | 0);
              if ($809) {
               break L314;
              } else {
               break;
              }
             }
            }
           } while (0);
           $810 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
           $811 = $$3$i$i >>> 0 < $810 >>> 0;
           if ($811) {
            _abort();
           }
           $812 = $$3$i$i + 24 | 0;
           SAFE_HEAP_STORE($812 | 0, $768 | 0, 4);
           $813 = $717 + 16 | 0;
           $814 = SAFE_HEAP_LOAD($813 | 0, 4, 0) | 0 | 0;
           $815 = ($814 | 0) == (0 | 0);
           do {
            if (!$815) {
             $816 = $814 >>> 0 < $810 >>> 0;
             if ($816) {
              _abort();
             } else {
              $817 = $$3$i$i + 16 | 0;
              SAFE_HEAP_STORE($817 | 0, $814 | 0, 4);
              $818 = $814 + 24 | 0;
              SAFE_HEAP_STORE($818 | 0, $$3$i$i | 0, 4);
              break;
             }
            }
           } while (0);
           $819 = $813 + 4 | 0;
           $820 = SAFE_HEAP_LOAD($819 | 0, 4, 0) | 0 | 0;
           $821 = ($820 | 0) == (0 | 0);
           if ($821) {
            break;
           }
           $822 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
           $823 = $820 >>> 0 < $822 >>> 0;
           if ($823) {
            _abort();
           } else {
            $824 = $$3$i$i + 20 | 0;
            SAFE_HEAP_STORE($824 | 0, $820 | 0, 4);
            $825 = $820 + 24 | 0;
            SAFE_HEAP_STORE($825 | 0, $$3$i$i | 0, 4);
            break;
           }
          }
         } while (0);
         $826 = $717 + $741 | 0;
         $827 = $741 + $722 | 0;
         $$0$i18$i = $826;
         $$0287$i$i = $827;
        } else {
         $$0$i18$i = $717;
         $$0287$i$i = $722;
        }
        $828 = $$0$i18$i + 4 | 0;
        $829 = SAFE_HEAP_LOAD($828 | 0, 4, 0) | 0 | 0;
        $830 = $829 & -2;
        SAFE_HEAP_STORE($828 | 0, $830 | 0, 4);
        $831 = $$0287$i$i | 1;
        $832 = $721 + 4 | 0;
        SAFE_HEAP_STORE($832 | 0, $831 | 0, 4);
        $833 = $721 + $$0287$i$i | 0;
        SAFE_HEAP_STORE($833 | 0, $$0287$i$i | 0, 4);
        $834 = $$0287$i$i >>> 3;
        $835 = $$0287$i$i >>> 0 < 256;
        if ($835) {
         $836 = $834 << 1;
         $837 = 3112 + ($836 << 2) | 0;
         $838 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
         $839 = 1 << $834;
         $840 = $838 & $839;
         $841 = ($840 | 0) == 0;
         do {
          if ($841) {
           $842 = $838 | $839;
           SAFE_HEAP_STORE(768 * 4 | 0, $842 | 0, 4);
           $$pre$i19$i = $837 + 8 | 0;
           $$0295$i$i = $837;
           $$pre$phi$i20$iZ2D = $$pre$i19$i;
          } else {
           $843 = $837 + 8 | 0;
           $844 = SAFE_HEAP_LOAD($843 | 0, 4, 0) | 0 | 0;
           $845 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
           $846 = $844 >>> 0 < $845 >>> 0;
           if (!$846) {
            $$0295$i$i = $844;
            $$pre$phi$i20$iZ2D = $843;
            break;
           }
           _abort();
          }
         } while (0);
         SAFE_HEAP_STORE($$pre$phi$i20$iZ2D | 0, $721 | 0, 4);
         $847 = $$0295$i$i + 12 | 0;
         SAFE_HEAP_STORE($847 | 0, $721 | 0, 4);
         $848 = $721 + 8 | 0;
         SAFE_HEAP_STORE($848 | 0, $$0295$i$i | 0, 4);
         $849 = $721 + 12 | 0;
         SAFE_HEAP_STORE($849 | 0, $837 | 0, 4);
         break;
        }
        $850 = $$0287$i$i >>> 8;
        $851 = ($850 | 0) == 0;
        do {
         if ($851) {
          $$0296$i$i = 0;
         } else {
          $852 = $$0287$i$i >>> 0 > 16777215;
          if ($852) {
           $$0296$i$i = 31;
           break;
          }
          $853 = $850 + 1048320 | 0;
          $854 = $853 >>> 16;
          $855 = $854 & 8;
          $856 = $850 << $855;
          $857 = $856 + 520192 | 0;
          $858 = $857 >>> 16;
          $859 = $858 & 4;
          $860 = $859 | $855;
          $861 = $856 << $859;
          $862 = $861 + 245760 | 0;
          $863 = $862 >>> 16;
          $864 = $863 & 2;
          $865 = $860 | $864;
          $866 = 14 - $865 | 0;
          $867 = $861 << $864;
          $868 = $867 >>> 15;
          $869 = $866 + $868 | 0;
          $870 = $869 << 1;
          $871 = $869 + 7 | 0;
          $872 = $$0287$i$i >>> $871;
          $873 = $872 & 1;
          $874 = $873 | $870;
          $$0296$i$i = $874;
         }
        } while (0);
        $875 = 3376 + ($$0296$i$i << 2) | 0;
        $876 = $721 + 28 | 0;
        SAFE_HEAP_STORE($876 | 0, $$0296$i$i | 0, 4);
        $877 = $721 + 16 | 0;
        $878 = $877 + 4 | 0;
        SAFE_HEAP_STORE($878 | 0, 0 | 0, 4);
        SAFE_HEAP_STORE($877 | 0, 0 | 0, 4);
        $879 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
        $880 = 1 << $$0296$i$i;
        $881 = $879 & $880;
        $882 = ($881 | 0) == 0;
        if ($882) {
         $883 = $879 | $880;
         SAFE_HEAP_STORE(3076 | 0, $883 | 0, 4);
         SAFE_HEAP_STORE($875 | 0, $721 | 0, 4);
         $884 = $721 + 24 | 0;
         SAFE_HEAP_STORE($884 | 0, $875 | 0, 4);
         $885 = $721 + 12 | 0;
         SAFE_HEAP_STORE($885 | 0, $721 | 0, 4);
         $886 = $721 + 8 | 0;
         SAFE_HEAP_STORE($886 | 0, $721 | 0, 4);
         break;
        }
        $887 = SAFE_HEAP_LOAD($875 | 0, 4, 0) | 0 | 0;
        $888 = ($$0296$i$i | 0) == 31;
        $889 = $$0296$i$i >>> 1;
        $890 = 25 - $889 | 0;
        $891 = $888 ? 0 : $890;
        $892 = $$0287$i$i << $891;
        $$0288$i$i = $892;
        $$0289$i$i = $887;
        while (1) {
         $893 = $$0289$i$i + 4 | 0;
         $894 = SAFE_HEAP_LOAD($893 | 0, 4, 0) | 0 | 0;
         $895 = $894 & -8;
         $896 = ($895 | 0) == ($$0287$i$i | 0);
         if ($896) {
          label = 265;
          break;
         }
         $897 = $$0288$i$i >>> 31;
         $898 = ($$0289$i$i + 16 | 0) + ($897 << 2) | 0;
         $899 = $$0288$i$i << 1;
         $900 = SAFE_HEAP_LOAD($898 | 0, 4, 0) | 0 | 0;
         $901 = ($900 | 0) == (0 | 0);
         if ($901) {
          label = 262;
          break;
         } else {
          $$0288$i$i = $899;
          $$0289$i$i = $900;
         }
        }
        if ((label | 0) == 262) {
         $902 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
         $903 = $898 >>> 0 < $902 >>> 0;
         if ($903) {
          _abort();
         } else {
          SAFE_HEAP_STORE($898 | 0, $721 | 0, 4);
          $904 = $721 + 24 | 0;
          SAFE_HEAP_STORE($904 | 0, $$0289$i$i | 0, 4);
          $905 = $721 + 12 | 0;
          SAFE_HEAP_STORE($905 | 0, $721 | 0, 4);
          $906 = $721 + 8 | 0;
          SAFE_HEAP_STORE($906 | 0, $721 | 0, 4);
          break;
         }
        } else if ((label | 0) == 265) {
         $907 = $$0289$i$i + 8 | 0;
         $908 = SAFE_HEAP_LOAD($907 | 0, 4, 0) | 0 | 0;
         $909 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
         $910 = $908 >>> 0 >= $909 >>> 0;
         $not$7$i$i = $$0289$i$i >>> 0 >= $909 >>> 0;
         $911 = $910 & $not$7$i$i;
         if ($911) {
          $912 = $908 + 12 | 0;
          SAFE_HEAP_STORE($912 | 0, $721 | 0, 4);
          SAFE_HEAP_STORE($907 | 0, $721 | 0, 4);
          $913 = $721 + 8 | 0;
          SAFE_HEAP_STORE($913 | 0, $908 | 0, 4);
          $914 = $721 + 12 | 0;
          SAFE_HEAP_STORE($914 | 0, $$0289$i$i | 0, 4);
          $915 = $721 + 24 | 0;
          SAFE_HEAP_STORE($915 | 0, 0 | 0, 4);
          break;
         } else {
          _abort();
         }
        }
       }
      } while (0);
      $1047 = $709 + 8 | 0;
      $$0 = $1047;
      STACKTOP = sp;
      return $$0 | 0;
     }
    }
    $$0$i$i$i = 3520;
    while (1) {
     $916 = SAFE_HEAP_LOAD($$0$i$i$i | 0, 4, 0) | 0 | 0;
     $917 = $916 >>> 0 > $630 >>> 0;
     if (!$917) {
      $918 = $$0$i$i$i + 4 | 0;
      $919 = SAFE_HEAP_LOAD($918 | 0, 4, 0) | 0 | 0;
      $920 = $916 + $919 | 0;
      $921 = $920 >>> 0 > $630 >>> 0;
      if ($921) {
       break;
      }
     }
     $922 = $$0$i$i$i + 8 | 0;
     $923 = SAFE_HEAP_LOAD($922 | 0, 4, 0) | 0 | 0;
     $$0$i$i$i = $923;
    }
    $924 = $920 + -47 | 0;
    $925 = $924 + 8 | 0;
    $926 = $925;
    $927 = $926 & 7;
    $928 = ($927 | 0) == 0;
    $929 = 0 - $926 | 0;
    $930 = $929 & 7;
    $931 = $928 ? 0 : $930;
    $932 = $924 + $931 | 0;
    $933 = $630 + 16 | 0;
    $934 = $932 >>> 0 < $933 >>> 0;
    $935 = $934 ? $630 : $932;
    $936 = $935 + 8 | 0;
    $937 = $935 + 24 | 0;
    $938 = $$723948$i + -40 | 0;
    $939 = $$749$i + 8 | 0;
    $940 = $939;
    $941 = $940 & 7;
    $942 = ($941 | 0) == 0;
    $943 = 0 - $940 | 0;
    $944 = $943 & 7;
    $945 = $942 ? 0 : $944;
    $946 = $$749$i + $945 | 0;
    $947 = $938 - $945 | 0;
    SAFE_HEAP_STORE(3096 | 0, $946 | 0, 4);
    SAFE_HEAP_STORE(3084 | 0, $947 | 0, 4);
    $948 = $947 | 1;
    $949 = $946 + 4 | 0;
    SAFE_HEAP_STORE($949 | 0, $948 | 0, 4);
    $950 = $946 + $947 | 0;
    $951 = $950 + 4 | 0;
    SAFE_HEAP_STORE($951 | 0, 40 | 0, 4);
    $952 = SAFE_HEAP_LOAD(3560 | 0, 4, 0) | 0 | 0;
    SAFE_HEAP_STORE(3100 | 0, $952 | 0, 4);
    $953 = $935 + 4 | 0;
    SAFE_HEAP_STORE($953 | 0, 27 | 0, 4);
    {}
    SAFE_HEAP_STORE($936 | 0, SAFE_HEAP_LOAD(3520 | 0, 4, 0) | 0 | 0 | 0, 4);
    SAFE_HEAP_STORE($936 + 4 | 0, SAFE_HEAP_LOAD(3520 + 4 | 0, 4, 0) | 0 | 0 | 0, 4);
    SAFE_HEAP_STORE($936 + 8 | 0, SAFE_HEAP_LOAD(3520 + 8 | 0, 4, 0) | 0 | 0 | 0, 4);
    SAFE_HEAP_STORE($936 + 12 | 0, SAFE_HEAP_LOAD(3520 + 12 | 0, 4, 0) | 0 | 0 | 0, 4);
    SAFE_HEAP_STORE(3520 | 0, $$749$i | 0, 4);
    SAFE_HEAP_STORE(3524 | 0, $$723948$i | 0, 4);
    SAFE_HEAP_STORE(3532 | 0, 0 | 0, 4);
    SAFE_HEAP_STORE(3528 | 0, $936 | 0, 4);
    $955 = $937;
    while (1) {
     $954 = $955 + 4 | 0;
     SAFE_HEAP_STORE($954 | 0, 7 | 0, 4);
     $956 = $955 + 8 | 0;
     $957 = $956 >>> 0 < $920 >>> 0;
     if ($957) {
      $955 = $954;
     } else {
      break;
     }
    }
    $958 = ($935 | 0) == ($630 | 0);
    if (!$958) {
     $959 = $935;
     $960 = $630;
     $961 = $959 - $960 | 0;
     $962 = SAFE_HEAP_LOAD($953 | 0, 4, 0) | 0 | 0;
     $963 = $962 & -2;
     SAFE_HEAP_STORE($953 | 0, $963 | 0, 4);
     $964 = $961 | 1;
     $965 = $630 + 4 | 0;
     SAFE_HEAP_STORE($965 | 0, $964 | 0, 4);
     SAFE_HEAP_STORE($935 | 0, $961 | 0, 4);
     $966 = $961 >>> 3;
     $967 = $961 >>> 0 < 256;
     if ($967) {
      $968 = $966 << 1;
      $969 = 3112 + ($968 << 2) | 0;
      $970 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
      $971 = 1 << $966;
      $972 = $970 & $971;
      $973 = ($972 | 0) == 0;
      if ($973) {
       $974 = $970 | $971;
       SAFE_HEAP_STORE(768 * 4 | 0, $974 | 0, 4);
       $$pre$i$i = $969 + 8 | 0;
       $$0211$i$i = $969;
       $$pre$phi$i$iZ2D = $$pre$i$i;
      } else {
       $975 = $969 + 8 | 0;
       $976 = SAFE_HEAP_LOAD($975 | 0, 4, 0) | 0 | 0;
       $977 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
       $978 = $976 >>> 0 < $977 >>> 0;
       if ($978) {
        _abort();
       } else {
        $$0211$i$i = $976;
        $$pre$phi$i$iZ2D = $975;
       }
      }
      SAFE_HEAP_STORE($$pre$phi$i$iZ2D | 0, $630 | 0, 4);
      $979 = $$0211$i$i + 12 | 0;
      SAFE_HEAP_STORE($979 | 0, $630 | 0, 4);
      $980 = $630 + 8 | 0;
      SAFE_HEAP_STORE($980 | 0, $$0211$i$i | 0, 4);
      $981 = $630 + 12 | 0;
      SAFE_HEAP_STORE($981 | 0, $969 | 0, 4);
      break;
     }
     $982 = $961 >>> 8;
     $983 = ($982 | 0) == 0;
     if ($983) {
      $$0212$i$i = 0;
     } else {
      $984 = $961 >>> 0 > 16777215;
      if ($984) {
       $$0212$i$i = 31;
      } else {
       $985 = $982 + 1048320 | 0;
       $986 = $985 >>> 16;
       $987 = $986 & 8;
       $988 = $982 << $987;
       $989 = $988 + 520192 | 0;
       $990 = $989 >>> 16;
       $991 = $990 & 4;
       $992 = $991 | $987;
       $993 = $988 << $991;
       $994 = $993 + 245760 | 0;
       $995 = $994 >>> 16;
       $996 = $995 & 2;
       $997 = $992 | $996;
       $998 = 14 - $997 | 0;
       $999 = $993 << $996;
       $1000 = $999 >>> 15;
       $1001 = $998 + $1000 | 0;
       $1002 = $1001 << 1;
       $1003 = $1001 + 7 | 0;
       $1004 = $961 >>> $1003;
       $1005 = $1004 & 1;
       $1006 = $1005 | $1002;
       $$0212$i$i = $1006;
      }
     }
     $1007 = 3376 + ($$0212$i$i << 2) | 0;
     $1008 = $630 + 28 | 0;
     SAFE_HEAP_STORE($1008 | 0, $$0212$i$i | 0, 4);
     $1009 = $630 + 20 | 0;
     SAFE_HEAP_STORE($1009 | 0, 0 | 0, 4);
     SAFE_HEAP_STORE($933 | 0, 0 | 0, 4);
     $1010 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
     $1011 = 1 << $$0212$i$i;
     $1012 = $1010 & $1011;
     $1013 = ($1012 | 0) == 0;
     if ($1013) {
      $1014 = $1010 | $1011;
      SAFE_HEAP_STORE(3076 | 0, $1014 | 0, 4);
      SAFE_HEAP_STORE($1007 | 0, $630 | 0, 4);
      $1015 = $630 + 24 | 0;
      SAFE_HEAP_STORE($1015 | 0, $1007 | 0, 4);
      $1016 = $630 + 12 | 0;
      SAFE_HEAP_STORE($1016 | 0, $630 | 0, 4);
      $1017 = $630 + 8 | 0;
      SAFE_HEAP_STORE($1017 | 0, $630 | 0, 4);
      break;
     }
     $1018 = SAFE_HEAP_LOAD($1007 | 0, 4, 0) | 0 | 0;
     $1019 = ($$0212$i$i | 0) == 31;
     $1020 = $$0212$i$i >>> 1;
     $1021 = 25 - $1020 | 0;
     $1022 = $1019 ? 0 : $1021;
     $1023 = $961 << $1022;
     $$0206$i$i = $1023;
     $$0207$i$i = $1018;
     while (1) {
      $1024 = $$0207$i$i + 4 | 0;
      $1025 = SAFE_HEAP_LOAD($1024 | 0, 4, 0) | 0 | 0;
      $1026 = $1025 & -8;
      $1027 = ($1026 | 0) == ($961 | 0);
      if ($1027) {
       label = 292;
       break;
      }
      $1028 = $$0206$i$i >>> 31;
      $1029 = ($$0207$i$i + 16 | 0) + ($1028 << 2) | 0;
      $1030 = $$0206$i$i << 1;
      $1031 = SAFE_HEAP_LOAD($1029 | 0, 4, 0) | 0 | 0;
      $1032 = ($1031 | 0) == (0 | 0);
      if ($1032) {
       label = 289;
       break;
      } else {
       $$0206$i$i = $1030;
       $$0207$i$i = $1031;
      }
     }
     if ((label | 0) == 289) {
      $1033 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $1034 = $1029 >>> 0 < $1033 >>> 0;
      if ($1034) {
       _abort();
      } else {
       SAFE_HEAP_STORE($1029 | 0, $630 | 0, 4);
       $1035 = $630 + 24 | 0;
       SAFE_HEAP_STORE($1035 | 0, $$0207$i$i | 0, 4);
       $1036 = $630 + 12 | 0;
       SAFE_HEAP_STORE($1036 | 0, $630 | 0, 4);
       $1037 = $630 + 8 | 0;
       SAFE_HEAP_STORE($1037 | 0, $630 | 0, 4);
       break;
      }
     } else if ((label | 0) == 292) {
      $1038 = $$0207$i$i + 8 | 0;
      $1039 = SAFE_HEAP_LOAD($1038 | 0, 4, 0) | 0 | 0;
      $1040 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $1041 = $1039 >>> 0 >= $1040 >>> 0;
      $not$$i$i = $$0207$i$i >>> 0 >= $1040 >>> 0;
      $1042 = $1041 & $not$$i$i;
      if ($1042) {
       $1043 = $1039 + 12 | 0;
       SAFE_HEAP_STORE($1043 | 0, $630 | 0, 4);
       SAFE_HEAP_STORE($1038 | 0, $630 | 0, 4);
       $1044 = $630 + 8 | 0;
       SAFE_HEAP_STORE($1044 | 0, $1039 | 0, 4);
       $1045 = $630 + 12 | 0;
       SAFE_HEAP_STORE($1045 | 0, $$0207$i$i | 0, 4);
       $1046 = $630 + 24 | 0;
       SAFE_HEAP_STORE($1046 | 0, 0 | 0, 4);
       break;
      } else {
       _abort();
      }
     }
    }
   }
  } while (0);
  $1048 = SAFE_HEAP_LOAD(3084 | 0, 4, 0) | 0 | 0;
  $1049 = $1048 >>> 0 > $$0197 >>> 0;
  if ($1049) {
   $1050 = $1048 - $$0197 | 0;
   SAFE_HEAP_STORE(3084 | 0, $1050 | 0, 4);
   $1051 = SAFE_HEAP_LOAD(3096 | 0, 4, 0) | 0 | 0;
   $1052 = $1051 + $$0197 | 0;
   SAFE_HEAP_STORE(3096 | 0, $1052 | 0, 4);
   $1053 = $1050 | 1;
   $1054 = $1052 + 4 | 0;
   SAFE_HEAP_STORE($1054 | 0, $1053 | 0, 4);
   $1055 = $$0197 | 3;
   $1056 = $1051 + 4 | 0;
   SAFE_HEAP_STORE($1056 | 0, $1055 | 0, 4);
   $1057 = $1051 + 8 | 0;
   $$0 = $1057;
   STACKTOP = sp;
   return $$0 | 0;
  }
 }
 $1058 = ___errno_location() | 0;
 SAFE_HEAP_STORE($1058 | 0, 12 | 0, 4);
 $$0 = 0;
 STACKTOP = sp;
 return $$0 | 0;
}

function _fmt_fp($0, $1, $2, $3, $4, $5) {
 $0 = $0 | 0;
 $1 = +$1;
 $2 = $2 | 0;
 $3 = $3 | 0;
 $4 = $4 | 0;
 $5 = $5 | 0;
 var $$ = 0, $$$ = 0, $$$$559 = 0.0, $$$3484 = 0, $$$3484691 = 0, $$$3484692 = 0, $$$3501 = 0, $$$4502 = 0, $$$542 = 0.0, $$$559 = 0.0, $$0 = 0, $$0463$lcssa = 0, $$0463584 = 0, $$0464594 = 0, $$0471 = 0.0, $$0479 = 0, $$0487642 = 0, $$0488 = 0, $$0488653 = 0, $$0488655 = 0;
 var $$0496$$9 = 0, $$0497654 = 0, $$0498 = 0, $$0509582 = 0.0, $$0510 = 0, $$0511 = 0, $$0514637 = 0, $$0520 = 0, $$0521 = 0, $$0521$ = 0, $$0523 = 0, $$0525 = 0, $$0527 = 0, $$0527629 = 0, $$0527631 = 0, $$0530636 = 0, $$1465 = 0, $$1467 = 0.0, $$1469 = 0.0, $$1472 = 0.0;
 var $$1480 = 0, $$1482$lcssa = 0, $$1482661 = 0, $$1489641 = 0, $$1499$lcssa = 0, $$1499660 = 0, $$1508583 = 0, $$1512$lcssa = 0, $$1512607 = 0, $$1515 = 0, $$1524 = 0, $$1526 = 0, $$1528614 = 0, $$1531$lcssa = 0, $$1531630 = 0, $$1598 = 0, $$2 = 0, $$2473 = 0.0, $$2476 = 0, $$2476$$547 = 0;
 var $$2476$$549 = 0, $$2483$ph = 0, $$2500 = 0, $$2513 = 0, $$2516618 = 0, $$2529 = 0, $$2532617 = 0, $$3 = 0.0, $$3477 = 0, $$3484$lcssa = 0, $$3484648 = 0, $$3501$lcssa = 0, $$3501647 = 0, $$3533613 = 0, $$4 = 0.0, $$4478$lcssa = 0, $$4478590 = 0, $$4492 = 0, $$4502 = 0, $$4518 = 0;
 var $$5$lcssa = 0, $$534$ = 0, $$539 = 0, $$539$ = 0, $$542 = 0.0, $$546 = 0, $$548 = 0, $$5486$lcssa = 0, $$5486623 = 0, $$5493597 = 0, $$5519$ph = 0, $$555 = 0, $$556 = 0, $$559 = 0.0, $$5602 = 0, $$6 = 0, $$6494589 = 0, $$7495601 = 0, $$7505 = 0, $$7505$ = 0;
 var $$7505$ph = 0, $$8 = 0, $$9$ph = 0, $$lcssa673 = 0, $$neg = 0, $$neg567 = 0, $$pn = 0, $$pn566 = 0, $$pr = 0, $$pr564 = 0, $$pre = 0, $$pre$phi690Z2D = 0, $$pre689 = 0, $$sink545$lcssa = 0, $$sink545622 = 0, $$sink562 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0;
 var $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0.0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0.0, $117 = 0.0, $118 = 0.0, $119 = 0, $12 = 0, $120 = 0;
 var $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0;
 var $14 = 0.0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0;
 var $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0;
 var $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0, $189 = 0, $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0;
 var $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0, $206 = 0, $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0;
 var $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0, $224 = 0, $225 = 0, $226 = 0, $227 = 0, $228 = 0.0, $229 = 0.0, $23 = 0;
 var $230 = 0, $231 = 0.0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0, $238 = 0, $239 = 0, $24 = 0, $240 = 0, $241 = 0, $242 = 0, $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0;
 var $249 = 0, $25 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0, $259 = 0, $26 = 0, $260 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0;
 var $267 = 0, $268 = 0, $269 = 0, $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0, $274 = 0, $275 = 0, $276 = 0, $277 = 0, $278 = 0, $279 = 0, $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0, $284 = 0;
 var $285 = 0, $286 = 0, $287 = 0, $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0, $292 = 0, $293 = 0, $294 = 0, $295 = 0, $296 = 0, $297 = 0, $298 = 0, $299 = 0, $30 = 0, $300 = 0, $301 = 0, $302 = 0;
 var $303 = 0, $304 = 0, $305 = 0, $306 = 0, $307 = 0, $308 = 0, $309 = 0, $31 = 0, $310 = 0, $311 = 0, $312 = 0, $313 = 0, $314 = 0, $315 = 0, $316 = 0, $317 = 0, $318 = 0, $319 = 0, $32 = 0, $320 = 0;
 var $321 = 0, $322 = 0, $323 = 0, $324 = 0, $325 = 0, $326 = 0, $327 = 0, $328 = 0, $329 = 0, $33 = 0, $330 = 0, $331 = 0, $332 = 0, $333 = 0, $334 = 0, $335 = 0, $336 = 0, $337 = 0, $338 = 0, $339 = 0;
 var $34 = 0, $340 = 0, $341 = 0, $342 = 0, $343 = 0, $344 = 0, $345 = 0, $346 = 0, $347 = 0, $348 = 0, $349 = 0, $35 = 0.0, $350 = 0, $351 = 0, $352 = 0, $353 = 0, $354 = 0, $355 = 0, $356 = 0, $357 = 0;
 var $358 = 0, $359 = 0, $36 = 0.0, $360 = 0, $361 = 0, $362 = 0, $363 = 0, $364 = 0, $365 = 0, $366 = 0, $367 = 0, $368 = 0, $369 = 0, $37 = 0, $370 = 0, $371 = 0, $372 = 0, $373 = 0, $374 = 0, $375 = 0;
 var $376 = 0, $377 = 0, $378 = 0, $379 = 0, $38 = 0, $380 = 0, $381 = 0, $382 = 0, $383 = 0, $384 = 0, $385 = 0, $386 = 0, $387 = 0, $388 = 0, $39 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0;
 var $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $50 = 0, $51 = 0.0, $52 = 0, $53 = 0, $54 = 0, $55 = 0.0, $56 = 0.0, $57 = 0.0, $58 = 0.0, $59 = 0.0, $6 = 0, $60 = 0.0, $61 = 0, $62 = 0, $63 = 0;
 var $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0;
 var $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0.0, $88 = 0.0, $89 = 0.0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, $exitcond = 0;
 var $narrow = 0, $not$ = 0, $notlhs = 0, $notrhs = 0, $or$cond = 0, $or$cond3$not = 0, $or$cond537 = 0, $or$cond541 = 0, $or$cond544 = 0, $or$cond554 = 0, $or$cond6 = 0, $scevgep684 = 0, $scevgep684685 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 560 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(560 | 0);
 $6 = sp + 8 | 0;
 $7 = sp;
 $8 = sp + 524 | 0;
 $9 = $8;
 $10 = sp + 512 | 0;
 SAFE_HEAP_STORE($7 | 0, 0 | 0, 4);
 $11 = $10 + 12 | 0;
 ___DOUBLE_BITS_685($1) | 0;
 $12 = tempRet0;
 $13 = ($12 | 0) < 0;
 if ($13) {
  $14 = -$1;
  $$0471 = $14;
  $$0520 = 1;
  $$0521 = 1125;
 } else {
  $15 = $4 & 2048;
  $16 = ($15 | 0) == 0;
  $17 = $4 & 1;
  $18 = ($17 | 0) == 0;
  $$ = $18 ? 1126 : 1131;
  $$$ = $16 ? $$ : 1128;
  $19 = $4 & 2049;
  $narrow = ($19 | 0) != 0;
  $$534$ = $narrow & 1;
  $$0471 = $1;
  $$0520 = $$534$;
  $$0521 = $$$;
 }
 ___DOUBLE_BITS_685($$0471) | 0;
 $20 = tempRet0;
 $21 = $20 & 2146435072;
 $22 = $21 >>> 0 < 2146435072;
 $23 = 0 < 0;
 $24 = ($21 | 0) == 2146435072;
 $25 = $24 & $23;
 $26 = $22 | $25;
 do {
  if ($26) {
   $35 = +_frexpl($$0471, $7);
   $36 = $35 * 2.0;
   $37 = $36 != 0.0;
   if ($37) {
    $38 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
    $39 = $38 + -1 | 0;
    SAFE_HEAP_STORE($7 | 0, $39 | 0, 4);
   }
   $40 = $5 | 32;
   $41 = ($40 | 0) == 97;
   if ($41) {
    $42 = $5 & 32;
    $43 = ($42 | 0) == 0;
    $44 = $$0521 + 9 | 0;
    $$0521$ = $43 ? $$0521 : $44;
    $45 = $$0520 | 2;
    $46 = $3 >>> 0 > 11;
    $47 = 12 - $3 | 0;
    $48 = ($47 | 0) == 0;
    $49 = $46 | $48;
    do {
     if ($49) {
      $$1472 = $36;
     } else {
      $$0509582 = 8.0;
      $$1508583 = $47;
      while (1) {
       $50 = $$1508583 + -1 | 0;
       $51 = $$0509582 * 16.0;
       $52 = ($50 | 0) == 0;
       if ($52) {
        break;
       } else {
        $$0509582 = $51;
        $$1508583 = $50;
       }
      }
      $53 = SAFE_HEAP_LOAD($$0521$ >> 0 | 0, 1, 0) | 0 | 0;
      $54 = $53 << 24 >> 24 == 45;
      if ($54) {
       $55 = -$36;
       $56 = $55 - $51;
       $57 = $51 + $56;
       $58 = -$57;
       $$1472 = $58;
       break;
      } else {
       $59 = $36 + $51;
       $60 = $59 - $51;
       $$1472 = $60;
       break;
      }
     }
    } while (0);
    $61 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
    $62 = ($61 | 0) < 0;
    $63 = 0 - $61 | 0;
    $64 = $62 ? $63 : $61;
    $65 = ($64 | 0) < 0;
    $66 = $65 << 31 >> 31;
    $67 = _fmt_u($64, $66, $11) | 0;
    $68 = ($67 | 0) == ($11 | 0);
    if ($68) {
     $69 = $10 + 11 | 0;
     SAFE_HEAP_STORE($69 >> 0 | 0, 48 | 0, 1);
     $$0511 = $69;
    } else {
     $$0511 = $67;
    }
    $70 = $61 >> 31;
    $71 = $70 & 2;
    $72 = $71 + 43 | 0;
    $73 = $72 & 255;
    $74 = $$0511 + -1 | 0;
    SAFE_HEAP_STORE($74 >> 0 | 0, $73 | 0, 1);
    $75 = $5 + 15 | 0;
    $76 = $75 & 255;
    $77 = $$0511 + -2 | 0;
    SAFE_HEAP_STORE($77 >> 0 | 0, $76 | 0, 1);
    $notrhs = ($3 | 0) < 1;
    $78 = $4 & 8;
    $79 = ($78 | 0) == 0;
    $$0523 = $8;
    $$2473 = $$1472;
    while (1) {
     $80 = ~~$$2473;
     $81 = 1160 + $80 | 0;
     $82 = SAFE_HEAP_LOAD($81 >> 0 | 0, 1, 0) | 0 | 0;
     $83 = $82 & 255;
     $84 = $83 | $42;
     $85 = $84 & 255;
     $86 = $$0523 + 1 | 0;
     SAFE_HEAP_STORE($$0523 >> 0 | 0, $85 | 0, 1);
     $87 = +($80 | 0);
     $88 = $$2473 - $87;
     $89 = $88 * 16.0;
     $90 = $86;
     $91 = $90 - $9 | 0;
     $92 = ($91 | 0) == 1;
     if ($92) {
      $notlhs = $89 == 0.0;
      $or$cond3$not = $notrhs & $notlhs;
      $or$cond = $79 & $or$cond3$not;
      if ($or$cond) {
       $$1524 = $86;
      } else {
       $93 = $$0523 + 2 | 0;
       SAFE_HEAP_STORE($86 >> 0 | 0, 46 | 0, 1);
       $$1524 = $93;
      }
     } else {
      $$1524 = $86;
     }
     $94 = $89 != 0.0;
     if ($94) {
      $$0523 = $$1524;
      $$2473 = $89;
     } else {
      break;
     }
    }
    $95 = ($3 | 0) != 0;
    $96 = $77;
    $97 = $11;
    $98 = $$1524;
    $99 = $98 - $9 | 0;
    $100 = $97 - $96 | 0;
    $101 = $99 + -2 | 0;
    $102 = ($101 | 0) < ($3 | 0);
    $or$cond537 = $95 & $102;
    $103 = $3 + 2 | 0;
    $$pn = $or$cond537 ? $103 : $99;
    $$0525 = $100 + $45 | 0;
    $104 = $$0525 + $$pn | 0;
    _pad_684($0, 32, $2, $104, $4);
    _out($0, $$0521$, $45);
    $105 = $4 ^ 65536;
    _pad_684($0, 48, $2, $104, $105);
    _out($0, $8, $99);
    $106 = $$pn - $99 | 0;
    _pad_684($0, 48, $106, 0, 0);
    _out($0, $77, $100);
    $107 = $4 ^ 8192;
    _pad_684($0, 32, $2, $104, $107);
    $$sink562 = $104;
    break;
   }
   $108 = ($3 | 0) < 0;
   $$539 = $108 ? 6 : $3;
   if ($37) {
    $109 = $36 * 268435456.0;
    $110 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
    $111 = $110 + -28 | 0;
    SAFE_HEAP_STORE($7 | 0, $111 | 0, 4);
    $$3 = $109;
    $$pr = $111;
   } else {
    $$pre = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
    $$3 = $36;
    $$pr = $$pre;
   }
   $112 = ($$pr | 0) < 0;
   $113 = $6 + 288 | 0;
   $$556 = $112 ? $6 : $113;
   $$0498 = $$556;
   $$4 = $$3;
   while (1) {
    $114 = ~~$$4 >>> 0;
    SAFE_HEAP_STORE($$0498 | 0, $114 | 0, 4);
    $115 = $$0498 + 4 | 0;
    $116 = +($114 >>> 0);
    $117 = $$4 - $116;
    $118 = $117 * 1.0e9;
    $119 = $118 != 0.0;
    if ($119) {
     $$0498 = $115;
     $$4 = $118;
    } else {
     break;
    }
   }
   $120 = ($$pr | 0) > 0;
   if ($120) {
    $$1482661 = $$556;
    $$1499660 = $115;
    $122 = $$pr;
    while (1) {
     $121 = ($122 | 0) < 29;
     $123 = $121 ? $122 : 29;
     $$0488653 = $$1499660 + -4 | 0;
     $124 = $$0488653 >>> 0 < $$1482661 >>> 0;
     if ($124) {
      $$2483$ph = $$1482661;
     } else {
      $$0488655 = $$0488653;
      $$0497654 = 0;
      while (1) {
       $125 = SAFE_HEAP_LOAD($$0488655 | 0, 4, 0) | 0 | 0;
       $126 = _bitshift64Shl($125 | 0, 0, $123 | 0) | 0;
       $127 = tempRet0;
       $128 = _i64Add($126 | 0, $127 | 0, $$0497654 | 0, 0) | 0;
       $129 = tempRet0;
       $130 = ___uremdi3($128 | 0, $129 | 0, 1e9, 0) | 0;
       $131 = tempRet0;
       SAFE_HEAP_STORE($$0488655 | 0, $130 | 0, 4);
       $132 = ___udivdi3($128 | 0, $129 | 0, 1e9, 0) | 0;
       $133 = tempRet0;
       $$0488 = $$0488655 + -4 | 0;
       $134 = $$0488 >>> 0 < $$1482661 >>> 0;
       if ($134) {
        break;
       } else {
        $$0488655 = $$0488;
        $$0497654 = $132;
       }
      }
      $135 = ($132 | 0) == 0;
      if ($135) {
       $$2483$ph = $$1482661;
      } else {
       $136 = $$1482661 + -4 | 0;
       SAFE_HEAP_STORE($136 | 0, $132 | 0, 4);
       $$2483$ph = $136;
      }
     }
     $$2500 = $$1499660;
     while (1) {
      $137 = $$2500 >>> 0 > $$2483$ph >>> 0;
      if (!$137) {
       break;
      }
      $138 = $$2500 + -4 | 0;
      $139 = SAFE_HEAP_LOAD($138 | 0, 4, 0) | 0 | 0;
      $140 = ($139 | 0) == 0;
      if ($140) {
       $$2500 = $138;
      } else {
       break;
      }
     }
     $141 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
     $142 = $141 - $123 | 0;
     SAFE_HEAP_STORE($7 | 0, $142 | 0, 4);
     $143 = ($142 | 0) > 0;
     if ($143) {
      $$1482661 = $$2483$ph;
      $$1499660 = $$2500;
      $122 = $142;
     } else {
      $$1482$lcssa = $$2483$ph;
      $$1499$lcssa = $$2500;
      $$pr564 = $142;
      break;
     }
    }
   } else {
    $$1482$lcssa = $$556;
    $$1499$lcssa = $115;
    $$pr564 = $$pr;
   }
   $144 = ($$pr564 | 0) < 0;
   if ($144) {
    $145 = $$539 + 25 | 0;
    $146 = ($145 | 0) / 9 & -1;
    $147 = $146 + 1 | 0;
    $148 = ($40 | 0) == 102;
    $$3484648 = $$1482$lcssa;
    $$3501647 = $$1499$lcssa;
    $150 = $$pr564;
    while (1) {
     $149 = 0 - $150 | 0;
     $151 = ($149 | 0) < 9;
     $152 = $151 ? $149 : 9;
     $153 = $$3484648 >>> 0 < $$3501647 >>> 0;
     if ($153) {
      $157 = 1 << $152;
      $158 = $157 + -1 | 0;
      $159 = 1e9 >>> $152;
      $$0487642 = 0;
      $$1489641 = $$3484648;
      while (1) {
       $160 = SAFE_HEAP_LOAD($$1489641 | 0, 4, 0) | 0 | 0;
       $161 = $160 & $158;
       $162 = $160 >>> $152;
       $163 = $162 + $$0487642 | 0;
       SAFE_HEAP_STORE($$1489641 | 0, $163 | 0, 4);
       $164 = Math_imul($161, $159) | 0;
       $165 = $$1489641 + 4 | 0;
       $166 = $165 >>> 0 < $$3501647 >>> 0;
       if ($166) {
        $$0487642 = $164;
        $$1489641 = $165;
       } else {
        break;
       }
      }
      $167 = SAFE_HEAP_LOAD($$3484648 | 0, 4, 0) | 0 | 0;
      $168 = ($167 | 0) == 0;
      $169 = $$3484648 + 4 | 0;
      $$$3484 = $168 ? $169 : $$3484648;
      $170 = ($164 | 0) == 0;
      if ($170) {
       $$$3484692 = $$$3484;
       $$4502 = $$3501647;
      } else {
       $171 = $$3501647 + 4 | 0;
       SAFE_HEAP_STORE($$3501647 | 0, $164 | 0, 4);
       $$$3484692 = $$$3484;
       $$4502 = $171;
      }
     } else {
      $154 = SAFE_HEAP_LOAD($$3484648 | 0, 4, 0) | 0 | 0;
      $155 = ($154 | 0) == 0;
      $156 = $$3484648 + 4 | 0;
      $$$3484691 = $155 ? $156 : $$3484648;
      $$$3484692 = $$$3484691;
      $$4502 = $$3501647;
     }
     $172 = $148 ? $$556 : $$$3484692;
     $173 = $$4502;
     $174 = $172;
     $175 = $173 - $174 | 0;
     $176 = $175 >> 2;
     $177 = ($176 | 0) > ($147 | 0);
     $178 = $172 + ($147 << 2) | 0;
     $$$4502 = $177 ? $178 : $$4502;
     $179 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
     $180 = $179 + $152 | 0;
     SAFE_HEAP_STORE($7 | 0, $180 | 0, 4);
     $181 = ($180 | 0) < 0;
     if ($181) {
      $$3484648 = $$$3484692;
      $$3501647 = $$$4502;
      $150 = $180;
     } else {
      $$3484$lcssa = $$$3484692;
      $$3501$lcssa = $$$4502;
      break;
     }
    }
   } else {
    $$3484$lcssa = $$1482$lcssa;
    $$3501$lcssa = $$1499$lcssa;
   }
   $182 = $$3484$lcssa >>> 0 < $$3501$lcssa >>> 0;
   $183 = $$556;
   if ($182) {
    $184 = $$3484$lcssa;
    $185 = $183 - $184 | 0;
    $186 = $185 >> 2;
    $187 = $186 * 9 | 0;
    $188 = SAFE_HEAP_LOAD($$3484$lcssa | 0, 4, 0) | 0 | 0;
    $189 = $188 >>> 0 < 10;
    if ($189) {
     $$1515 = $187;
    } else {
     $$0514637 = $187;
     $$0530636 = 10;
     while (1) {
      $190 = $$0530636 * 10 | 0;
      $191 = $$0514637 + 1 | 0;
      $192 = $188 >>> 0 < $190 >>> 0;
      if ($192) {
       $$1515 = $191;
       break;
      } else {
       $$0514637 = $191;
       $$0530636 = $190;
      }
     }
    }
   } else {
    $$1515 = 0;
   }
   $193 = ($40 | 0) != 102;
   $194 = $193 ? $$1515 : 0;
   $195 = $$539 - $194 | 0;
   $196 = ($40 | 0) == 103;
   $197 = ($$539 | 0) != 0;
   $198 = $197 & $196;
   $$neg = $198 << 31 >> 31;
   $199 = $195 + $$neg | 0;
   $200 = $$3501$lcssa;
   $201 = $200 - $183 | 0;
   $202 = $201 >> 2;
   $203 = $202 * 9 | 0;
   $204 = $203 + -9 | 0;
   $205 = ($199 | 0) < ($204 | 0);
   if ($205) {
    $206 = $$556 + 4 | 0;
    $207 = $199 + 9216 | 0;
    $208 = ($207 | 0) / 9 & -1;
    $209 = $208 + -1024 | 0;
    $210 = $206 + ($209 << 2) | 0;
    $211 = ($207 | 0) % 9 & -1;
    $$0527629 = $211 + 1 | 0;
    $212 = ($$0527629 | 0) < 9;
    if ($212) {
     $$0527631 = $$0527629;
     $$1531630 = 10;
     while (1) {
      $213 = $$1531630 * 10 | 0;
      $$0527 = $$0527631 + 1 | 0;
      $exitcond = ($$0527 | 0) == 9;
      if ($exitcond) {
       $$1531$lcssa = $213;
       break;
      } else {
       $$0527631 = $$0527;
       $$1531630 = $213;
      }
     }
    } else {
     $$1531$lcssa = 10;
    }
    $214 = SAFE_HEAP_LOAD($210 | 0, 4, 0) | 0 | 0;
    $215 = ($214 >>> 0) % ($$1531$lcssa >>> 0) & -1;
    $216 = ($215 | 0) == 0;
    $217 = $210 + 4 | 0;
    $218 = ($217 | 0) == ($$3501$lcssa | 0);
    $or$cond541 = $218 & $216;
    if ($or$cond541) {
     $$4492 = $210;
     $$4518 = $$1515;
     $$8 = $$3484$lcssa;
    } else {
     $219 = ($214 >>> 0) / ($$1531$lcssa >>> 0) & -1;
     $220 = $219 & 1;
     $221 = ($220 | 0) == 0;
     $$542 = $221 ? 9007199254740992.0 : 9007199254740994.0;
     $222 = ($$1531$lcssa | 0) / 2 & -1;
     $223 = $215 >>> 0 < $222 >>> 0;
     $224 = ($215 | 0) == ($222 | 0);
     $or$cond544 = $218 & $224;
     $$559 = $or$cond544 ? 1.0 : 1.5;
     $$$559 = $223 ? .5 : $$559;
     $225 = ($$0520 | 0) == 0;
     if ($225) {
      $$1467 = $$$559;
      $$1469 = $$542;
     } else {
      $226 = SAFE_HEAP_LOAD($$0521 >> 0 | 0, 1, 0) | 0 | 0;
      $227 = $226 << 24 >> 24 == 45;
      $228 = -$$542;
      $229 = -$$$559;
      $$$542 = $227 ? $228 : $$542;
      $$$$559 = $227 ? $229 : $$$559;
      $$1467 = $$$$559;
      $$1469 = $$$542;
     }
     $230 = $214 - $215 | 0;
     SAFE_HEAP_STORE($210 | 0, $230 | 0, 4);
     $231 = $$1469 + $$1467;
     $232 = $231 != $$1469;
     if ($232) {
      $233 = $230 + $$1531$lcssa | 0;
      SAFE_HEAP_STORE($210 | 0, $233 | 0, 4);
      $234 = $233 >>> 0 > 999999999;
      if ($234) {
       $$5486623 = $$3484$lcssa;
       $$sink545622 = $210;
       while (1) {
        $235 = $$sink545622 + -4 | 0;
        SAFE_HEAP_STORE($$sink545622 | 0, 0 | 0, 4);
        $236 = $235 >>> 0 < $$5486623 >>> 0;
        if ($236) {
         $237 = $$5486623 + -4 | 0;
         SAFE_HEAP_STORE($237 | 0, 0 | 0, 4);
         $$6 = $237;
        } else {
         $$6 = $$5486623;
        }
        $238 = SAFE_HEAP_LOAD($235 | 0, 4, 0) | 0 | 0;
        $239 = $238 + 1 | 0;
        SAFE_HEAP_STORE($235 | 0, $239 | 0, 4);
        $240 = $239 >>> 0 > 999999999;
        if ($240) {
         $$5486623 = $$6;
         $$sink545622 = $235;
        } else {
         $$5486$lcssa = $$6;
         $$sink545$lcssa = $235;
         break;
        }
       }
      } else {
       $$5486$lcssa = $$3484$lcssa;
       $$sink545$lcssa = $210;
      }
      $241 = $$5486$lcssa;
      $242 = $183 - $241 | 0;
      $243 = $242 >> 2;
      $244 = $243 * 9 | 0;
      $245 = SAFE_HEAP_LOAD($$5486$lcssa | 0, 4, 0) | 0 | 0;
      $246 = $245 >>> 0 < 10;
      if ($246) {
       $$4492 = $$sink545$lcssa;
       $$4518 = $244;
       $$8 = $$5486$lcssa;
      } else {
       $$2516618 = $244;
       $$2532617 = 10;
       while (1) {
        $247 = $$2532617 * 10 | 0;
        $248 = $$2516618 + 1 | 0;
        $249 = $245 >>> 0 < $247 >>> 0;
        if ($249) {
         $$4492 = $$sink545$lcssa;
         $$4518 = $248;
         $$8 = $$5486$lcssa;
         break;
        } else {
         $$2516618 = $248;
         $$2532617 = $247;
        }
       }
      }
     } else {
      $$4492 = $210;
      $$4518 = $$1515;
      $$8 = $$3484$lcssa;
     }
    }
    $250 = $$4492 + 4 | 0;
    $251 = $$3501$lcssa >>> 0 > $250 >>> 0;
    $$$3501 = $251 ? $250 : $$3501$lcssa;
    $$5519$ph = $$4518;
    $$7505$ph = $$$3501;
    $$9$ph = $$8;
   } else {
    $$5519$ph = $$1515;
    $$7505$ph = $$3501$lcssa;
    $$9$ph = $$3484$lcssa;
   }
   $$7505 = $$7505$ph;
   while (1) {
    $252 = $$7505 >>> 0 > $$9$ph >>> 0;
    if (!$252) {
     $$lcssa673 = 0;
     break;
    }
    $253 = $$7505 + -4 | 0;
    $254 = SAFE_HEAP_LOAD($253 | 0, 4, 0) | 0 | 0;
    $255 = ($254 | 0) == 0;
    if ($255) {
     $$7505 = $253;
    } else {
     $$lcssa673 = 1;
     break;
    }
   }
   $256 = 0 - $$5519$ph | 0;
   do {
    if ($196) {
     $not$ = $197 ^ 1;
     $257 = $not$ & 1;
     $$539$ = $257 + $$539 | 0;
     $258 = ($$539$ | 0) > ($$5519$ph | 0);
     $259 = ($$5519$ph | 0) > -5;
     $or$cond6 = $258 & $259;
     if ($or$cond6) {
      $260 = $5 + -1 | 0;
      $$neg567 = $$539$ + -1 | 0;
      $261 = $$neg567 - $$5519$ph | 0;
      $$0479 = $260;
      $$2476 = $261;
     } else {
      $262 = $5 + -2 | 0;
      $263 = $$539$ + -1 | 0;
      $$0479 = $262;
      $$2476 = $263;
     }
     $264 = $4 & 8;
     $265 = ($264 | 0) == 0;
     if ($265) {
      if ($$lcssa673) {
       $266 = $$7505 + -4 | 0;
       $267 = SAFE_HEAP_LOAD($266 | 0, 4, 0) | 0 | 0;
       $268 = ($267 | 0) == 0;
       if ($268) {
        $$2529 = 9;
       } else {
        $269 = ($267 >>> 0) % 10 & -1;
        $270 = ($269 | 0) == 0;
        if ($270) {
         $$1528614 = 0;
         $$3533613 = 10;
         while (1) {
          $271 = $$3533613 * 10 | 0;
          $272 = $$1528614 + 1 | 0;
          $273 = ($267 >>> 0) % ($271 >>> 0) & -1;
          $274 = ($273 | 0) == 0;
          if ($274) {
           $$1528614 = $272;
           $$3533613 = $271;
          } else {
           $$2529 = $272;
           break;
          }
         }
        } else {
         $$2529 = 0;
        }
       }
      } else {
       $$2529 = 9;
      }
      $275 = $$0479 | 32;
      $276 = ($275 | 0) == 102;
      $277 = $$7505;
      $278 = $277 - $183 | 0;
      $279 = $278 >> 2;
      $280 = $279 * 9 | 0;
      $281 = $280 + -9 | 0;
      if ($276) {
       $282 = $281 - $$2529 | 0;
       $283 = ($282 | 0) > 0;
       $$546 = $283 ? $282 : 0;
       $284 = ($$2476 | 0) < ($$546 | 0);
       $$2476$$547 = $284 ? $$2476 : $$546;
       $$1480 = $$0479;
       $$3477 = $$2476$$547;
       $$pre$phi690Z2D = 0;
       break;
      } else {
       $285 = $281 + $$5519$ph | 0;
       $286 = $285 - $$2529 | 0;
       $287 = ($286 | 0) > 0;
       $$548 = $287 ? $286 : 0;
       $288 = ($$2476 | 0) < ($$548 | 0);
       $$2476$$549 = $288 ? $$2476 : $$548;
       $$1480 = $$0479;
       $$3477 = $$2476$$549;
       $$pre$phi690Z2D = 0;
       break;
      }
     } else {
      $$1480 = $$0479;
      $$3477 = $$2476;
      $$pre$phi690Z2D = $264;
     }
    } else {
     $$pre689 = $4 & 8;
     $$1480 = $5;
     $$3477 = $$539;
     $$pre$phi690Z2D = $$pre689;
    }
   } while (0);
   $289 = $$3477 | $$pre$phi690Z2D;
   $290 = ($289 | 0) != 0;
   $291 = $290 & 1;
   $292 = $$1480 | 32;
   $293 = ($292 | 0) == 102;
   if ($293) {
    $294 = ($$5519$ph | 0) > 0;
    $295 = $294 ? $$5519$ph : 0;
    $$2513 = 0;
    $$pn566 = $295;
   } else {
    $296 = ($$5519$ph | 0) < 0;
    $297 = $296 ? $256 : $$5519$ph;
    $298 = ($297 | 0) < 0;
    $299 = $298 << 31 >> 31;
    $300 = _fmt_u($297, $299, $11) | 0;
    $301 = $11;
    $302 = $300;
    $303 = $301 - $302 | 0;
    $304 = ($303 | 0) < 2;
    if ($304) {
     $$1512607 = $300;
     while (1) {
      $305 = $$1512607 + -1 | 0;
      SAFE_HEAP_STORE($305 >> 0 | 0, 48 | 0, 1);
      $306 = $305;
      $307 = $301 - $306 | 0;
      $308 = ($307 | 0) < 2;
      if ($308) {
       $$1512607 = $305;
      } else {
       $$1512$lcssa = $305;
       break;
      }
     }
    } else {
     $$1512$lcssa = $300;
    }
    $309 = $$5519$ph >> 31;
    $310 = $309 & 2;
    $311 = $310 + 43 | 0;
    $312 = $311 & 255;
    $313 = $$1512$lcssa + -1 | 0;
    SAFE_HEAP_STORE($313 >> 0 | 0, $312 | 0, 1);
    $314 = $$1480 & 255;
    $315 = $$1512$lcssa + -2 | 0;
    SAFE_HEAP_STORE($315 >> 0 | 0, $314 | 0, 1);
    $316 = $315;
    $317 = $301 - $316 | 0;
    $$2513 = $315;
    $$pn566 = $317;
   }
   $318 = $$0520 + 1 | 0;
   $319 = $318 + $$3477 | 0;
   $$1526 = $319 + $291 | 0;
   $320 = $$1526 + $$pn566 | 0;
   _pad_684($0, 32, $2, $320, $4);
   _out($0, $$0521, $$0520);
   $321 = $4 ^ 65536;
   _pad_684($0, 48, $2, $320, $321);
   if ($293) {
    $322 = $$9$ph >>> 0 > $$556 >>> 0;
    $$0496$$9 = $322 ? $$556 : $$9$ph;
    $323 = $8 + 9 | 0;
    $324 = $323;
    $325 = $8 + 8 | 0;
    $$5493597 = $$0496$$9;
    while (1) {
     $326 = SAFE_HEAP_LOAD($$5493597 | 0, 4, 0) | 0 | 0;
     $327 = _fmt_u($326, 0, $323) | 0;
     $328 = ($$5493597 | 0) == ($$0496$$9 | 0);
     if ($328) {
      $334 = ($327 | 0) == ($323 | 0);
      if ($334) {
       SAFE_HEAP_STORE($325 >> 0 | 0, 48 | 0, 1);
       $$1465 = $325;
      } else {
       $$1465 = $327;
      }
     } else {
      $329 = $327 >>> 0 > $8 >>> 0;
      if ($329) {
       $330 = $327;
       $331 = $330 - $9 | 0;
       _memset($8 | 0, 48, $331 | 0) | 0;
       $$0464594 = $327;
       while (1) {
        $332 = $$0464594 + -1 | 0;
        $333 = $332 >>> 0 > $8 >>> 0;
        if ($333) {
         $$0464594 = $332;
        } else {
         $$1465 = $332;
         break;
        }
       }
      } else {
       $$1465 = $327;
      }
     }
     $335 = $$1465;
     $336 = $324 - $335 | 0;
     _out($0, $$1465, $336);
     $337 = $$5493597 + 4 | 0;
     $338 = $337 >>> 0 > $$556 >>> 0;
     if ($338) {
      break;
     } else {
      $$5493597 = $337;
     }
    }
    $339 = ($289 | 0) == 0;
    if (!$339) {
     _out($0, 1176, 1);
    }
    $340 = $337 >>> 0 < $$7505 >>> 0;
    $341 = ($$3477 | 0) > 0;
    $342 = $340 & $341;
    if ($342) {
     $$4478590 = $$3477;
     $$6494589 = $337;
     while (1) {
      $343 = SAFE_HEAP_LOAD($$6494589 | 0, 4, 0) | 0 | 0;
      $344 = _fmt_u($343, 0, $323) | 0;
      $345 = $344 >>> 0 > $8 >>> 0;
      if ($345) {
       $346 = $344;
       $347 = $346 - $9 | 0;
       _memset($8 | 0, 48, $347 | 0) | 0;
       $$0463584 = $344;
       while (1) {
        $348 = $$0463584 + -1 | 0;
        $349 = $348 >>> 0 > $8 >>> 0;
        if ($349) {
         $$0463584 = $348;
        } else {
         $$0463$lcssa = $348;
         break;
        }
       }
      } else {
       $$0463$lcssa = $344;
      }
      $350 = ($$4478590 | 0) < 9;
      $351 = $350 ? $$4478590 : 9;
      _out($0, $$0463$lcssa, $351);
      $352 = $$6494589 + 4 | 0;
      $353 = $$4478590 + -9 | 0;
      $354 = $352 >>> 0 < $$7505 >>> 0;
      $355 = ($$4478590 | 0) > 9;
      $356 = $354 & $355;
      if ($356) {
       $$4478590 = $353;
       $$6494589 = $352;
      } else {
       $$4478$lcssa = $353;
       break;
      }
     }
    } else {
     $$4478$lcssa = $$3477;
    }
    $357 = $$4478$lcssa + 9 | 0;
    _pad_684($0, 48, $357, 9, 0);
   } else {
    $358 = $$9$ph + 4 | 0;
    $$7505$ = $$lcssa673 ? $$7505 : $358;
    $359 = ($$3477 | 0) > -1;
    if ($359) {
     $360 = $8 + 9 | 0;
     $361 = ($$pre$phi690Z2D | 0) == 0;
     $362 = $360;
     $363 = 0 - $9 | 0;
     $364 = $8 + 8 | 0;
     $$5602 = $$3477;
     $$7495601 = $$9$ph;
     while (1) {
      $365 = SAFE_HEAP_LOAD($$7495601 | 0, 4, 0) | 0 | 0;
      $366 = _fmt_u($365, 0, $360) | 0;
      $367 = ($366 | 0) == ($360 | 0);
      if ($367) {
       SAFE_HEAP_STORE($364 >> 0 | 0, 48 | 0, 1);
       $$0 = $364;
      } else {
       $$0 = $366;
      }
      $368 = ($$7495601 | 0) == ($$9$ph | 0);
      do {
       if ($368) {
        $372 = $$0 + 1 | 0;
        _out($0, $$0, 1);
        $373 = ($$5602 | 0) < 1;
        $or$cond554 = $361 & $373;
        if ($or$cond554) {
         $$2 = $372;
         break;
        }
        _out($0, 1176, 1);
        $$2 = $372;
       } else {
        $369 = $$0 >>> 0 > $8 >>> 0;
        if (!$369) {
         $$2 = $$0;
         break;
        }
        $scevgep684 = $$0 + $363 | 0;
        $scevgep684685 = $scevgep684;
        _memset($8 | 0, 48, $scevgep684685 | 0) | 0;
        $$1598 = $$0;
        while (1) {
         $370 = $$1598 + -1 | 0;
         $371 = $370 >>> 0 > $8 >>> 0;
         if ($371) {
          $$1598 = $370;
         } else {
          $$2 = $370;
          break;
         }
        }
       }
      } while (0);
      $374 = $$2;
      $375 = $362 - $374 | 0;
      $376 = ($$5602 | 0) > ($375 | 0);
      $377 = $376 ? $375 : $$5602;
      _out($0, $$2, $377);
      $378 = $$5602 - $375 | 0;
      $379 = $$7495601 + 4 | 0;
      $380 = $379 >>> 0 < $$7505$ >>> 0;
      $381 = ($378 | 0) > -1;
      $382 = $380 & $381;
      if ($382) {
       $$5602 = $378;
       $$7495601 = $379;
      } else {
       $$5$lcssa = $378;
       break;
      }
     }
    } else {
     $$5$lcssa = $$3477;
    }
    $383 = $$5$lcssa + 18 | 0;
    _pad_684($0, 48, $383, 18, 0);
    $384 = $11;
    $385 = $$2513;
    $386 = $384 - $385 | 0;
    _out($0, $$2513, $386);
   }
   $387 = $4 ^ 8192;
   _pad_684($0, 32, $2, $320, $387);
   $$sink562 = $320;
  } else {
   $27 = $5 & 32;
   $28 = ($27 | 0) != 0;
   $29 = $28 ? 1144 : 1148;
   $30 = $$0471 != $$0471 | 0.0 != 0.0;
   $31 = $28 ? 1152 : 1156;
   $$0510 = $30 ? $31 : $29;
   $32 = $$0520 + 3 | 0;
   $33 = $4 & -65537;
   _pad_684($0, 32, $2, $32, $33);
   _out($0, $$0521, $$0520);
   _out($0, $$0510, 3);
   $34 = $4 ^ 8192;
   _pad_684($0, 32, $2, $32, $34);
   $$sink562 = $32;
  }
 } while (0);
 $388 = ($$sink562 | 0) < ($2 | 0);
 $$555 = $388 ? $2 : $$sink562;
 STACKTOP = sp;
 return $$555 | 0;
}

function _printf_core($0, $1, $2, $3, $4) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 $3 = $3 | 0;
 $4 = $4 | 0;
 var $$ = 0, $$$ = 0, $$$0259 = 0, $$$0262 = 0, $$$0269 = 0, $$$4266 = 0, $$$5 = 0, $$0 = 0, $$0228 = 0, $$0228$ = 0, $$0229322 = 0, $$0232 = 0, $$0235 = 0, $$0237 = 0, $$0240$lcssa = 0, $$0240$lcssa357 = 0, $$0240321 = 0, $$0243 = 0, $$0247 = 0, $$0249$lcssa = 0;
 var $$0249306 = 0, $$0252 = 0, $$0253 = 0, $$0254 = 0, $$0254$$0254$ = 0, $$0259 = 0, $$0262$lcssa = 0, $$0262311 = 0, $$0269 = 0, $$0269$phi = 0, $$1 = 0, $$1230333 = 0, $$1233 = 0, $$1236 = 0, $$1238 = 0, $$1241332 = 0, $$1244320 = 0, $$1248 = 0, $$1250 = 0, $$1255 = 0;
 var $$1260 = 0, $$1263 = 0, $$1263$ = 0, $$1270 = 0, $$2 = 0, $$2234 = 0, $$2239 = 0, $$2242305 = 0, $$2245 = 0, $$2251 = 0, $$2256 = 0, $$2256$ = 0, $$2256$$$2256 = 0, $$2261 = 0, $$2271 = 0, $$284$ = 0, $$289 = 0, $$290 = 0, $$3257 = 0, $$3265 = 0;
 var $$3272 = 0, $$3303 = 0, $$377 = 0, $$4258355 = 0, $$4266 = 0, $$5 = 0, $$6268 = 0, $$lcssa295 = 0, $$pre = 0, $$pre346 = 0, $$pre347 = 0, $$pre347$pre = 0, $$pre349 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0;
 var $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0, $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0;
 var $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0;
 var $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0;
 var $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0, $176 = 0, $177 = 0, $178 = 0;
 var $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0, $189 = 0, $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0, $194 = 0, $195 = 0, $196 = 0;
 var $197 = 0, $198 = 0, $199 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0, $206 = 0, $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0, $212 = 0, $213 = 0, $214 = 0;
 var $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0, $224 = 0, $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0, $23 = 0, $230 = 0, $231 = 0, $232 = 0;
 var $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0, $238 = 0, $239 = 0, $24 = 0, $240 = 0, $241 = 0, $242 = 0, $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0, $249 = 0, $25 = 0, $250 = 0;
 var $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0, $259 = 0, $26 = 0, $260 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0, $267 = 0, $268 = 0, $269 = 0;
 var $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0, $274 = 0, $275 = 0, $276 = 0, $277 = 0, $278 = 0, $279 = 0, $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0, $284 = 0, $285 = 0, $286 = 0, $287 = 0;
 var $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0, $292 = 0, $293 = 0, $294 = 0, $295 = 0, $296 = 0, $297 = 0, $298 = 0, $299 = 0, $30 = 0, $300 = 0, $301 = 0, $302 = 0, $303 = 0, $304 = 0, $305 = 0;
 var $306 = 0.0, $307 = 0, $308 = 0, $309 = 0, $31 = 0, $310 = 0, $311 = 0, $312 = 0, $313 = 0, $314 = 0, $315 = 0, $316 = 0, $317 = 0, $318 = 0, $319 = 0, $32 = 0, $320 = 0, $321 = 0, $322 = 0, $323 = 0;
 var $324 = 0, $325 = 0, $326 = 0, $327 = 0, $328 = 0, $329 = 0, $33 = 0, $330 = 0, $331 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0;
 var $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0;
 var $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0;
 var $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0;
 var $arglist_current = 0, $arglist_current2 = 0, $arglist_next = 0, $arglist_next3 = 0, $expanded = 0, $expanded10 = 0, $expanded11 = 0, $expanded13 = 0, $expanded14 = 0, $expanded15 = 0, $expanded4 = 0, $expanded6 = 0, $expanded7 = 0, $expanded8 = 0, $isdigit = 0, $isdigit275 = 0, $isdigit277 = 0, $isdigittmp = 0, $isdigittmp$ = 0, $isdigittmp274 = 0;
 var $isdigittmp276 = 0, $narrow = 0, $or$cond = 0, $or$cond281 = 0, $or$cond283 = 0, $or$cond286 = 0, $storemerge = 0, $storemerge273310 = 0, $storemerge278 = 0, $trunc = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 64 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(64 | 0);
 $5 = sp + 16 | 0;
 $6 = sp;
 $7 = sp + 24 | 0;
 $8 = sp + 8 | 0;
 $9 = sp + 20 | 0;
 SAFE_HEAP_STORE($5 | 0, $1 | 0, 4);
 $10 = ($0 | 0) != (0 | 0);
 $11 = $7 + 40 | 0;
 $12 = $11;
 $13 = $7 + 39 | 0;
 $14 = $8 + 4 | 0;
 $$0243 = 0;
 $$0247 = 0;
 $$0269 = 0;
 $21 = $1;
 L1 : while (1) {
  $15 = ($$0247 | 0) > -1;
  do {
   if ($15) {
    $16 = 2147483647 - $$0247 | 0;
    $17 = ($$0243 | 0) > ($16 | 0);
    if ($17) {
     $18 = ___errno_location() | 0;
     SAFE_HEAP_STORE($18 | 0, 75 | 0, 4);
     $$1248 = -1;
     break;
    } else {
     $19 = $$0243 + $$0247 | 0;
     $$1248 = $19;
     break;
    }
   } else {
    $$1248 = $$0247;
   }
  } while (0);
  $20 = SAFE_HEAP_LOAD($21 >> 0 | 0, 1, 0) | 0 | 0;
  $22 = $20 << 24 >> 24 == 0;
  if ($22) {
   label = 87;
   break;
  } else {
   $23 = $20;
   $25 = $21;
  }
  L9 : while (1) {
   switch ($23 << 24 >> 24) {
   case 37:
    {
     $$0249306 = $25;
     $27 = $25;
     label = 9;
     break L9;
     break;
    }
   case 0:
    {
     $$0249$lcssa = $25;
     $39 = $25;
     break L9;
     break;
    }
   default:
    {}
   }
   $24 = $25 + 1 | 0;
   SAFE_HEAP_STORE($5 | 0, $24 | 0, 4);
   $$pre = SAFE_HEAP_LOAD($24 >> 0 | 0, 1, 0) | 0 | 0;
   $23 = $$pre;
   $25 = $24;
  }
  L12 : do {
   if ((label | 0) == 9) {
    while (1) {
     label = 0;
     $26 = $27 + 1 | 0;
     $28 = SAFE_HEAP_LOAD($26 >> 0 | 0, 1, 0) | 0 | 0;
     $29 = $28 << 24 >> 24 == 37;
     if (!$29) {
      $$0249$lcssa = $$0249306;
      $39 = $27;
      break L12;
     }
     $30 = $$0249306 + 1 | 0;
     $31 = $27 + 2 | 0;
     SAFE_HEAP_STORE($5 | 0, $31 | 0, 4);
     $32 = SAFE_HEAP_LOAD($31 >> 0 | 0, 1, 0) | 0 | 0;
     $33 = $32 << 24 >> 24 == 37;
     if ($33) {
      $$0249306 = $30;
      $27 = $31;
      label = 9;
     } else {
      $$0249$lcssa = $30;
      $39 = $31;
      break;
     }
    }
   }
  } while (0);
  $34 = $$0249$lcssa;
  $35 = $21;
  $36 = $34 - $35 | 0;
  if ($10) {
   _out($0, $21, $36);
  }
  $37 = ($36 | 0) == 0;
  if (!$37) {
   $$0269$phi = $$0269;
   $$0243 = $36;
   $$0247 = $$1248;
   $21 = $39;
   $$0269 = $$0269$phi;
   continue;
  }
  $38 = $39 + 1 | 0;
  $40 = SAFE_HEAP_LOAD($38 >> 0 | 0, 1, 0) | 0 | 0;
  $41 = $40 << 24 >> 24;
  $isdigittmp = $41 + -48 | 0;
  $isdigit = $isdigittmp >>> 0 < 10;
  if ($isdigit) {
   $42 = $39 + 2 | 0;
   $43 = SAFE_HEAP_LOAD($42 >> 0 | 0, 1, 0) | 0 | 0;
   $44 = $43 << 24 >> 24 == 36;
   $45 = $39 + 3 | 0;
   $$377 = $44 ? $45 : $38;
   $$$0269 = $44 ? 1 : $$0269;
   $isdigittmp$ = $44 ? $isdigittmp : -1;
   $$0253 = $isdigittmp$;
   $$1270 = $$$0269;
   $storemerge = $$377;
  } else {
   $$0253 = -1;
   $$1270 = $$0269;
   $storemerge = $38;
  }
  SAFE_HEAP_STORE($5 | 0, $storemerge | 0, 4);
  $46 = SAFE_HEAP_LOAD($storemerge >> 0 | 0, 1, 0) | 0 | 0;
  $47 = $46 << 24 >> 24;
  $48 = $47 + -32 | 0;
  $49 = $48 >>> 0 < 32;
  L24 : do {
   if ($49) {
    $$0262311 = 0;
    $329 = $46;
    $51 = $48;
    $storemerge273310 = $storemerge;
    while (1) {
     $50 = 1 << $51;
     $52 = $50 & 75913;
     $53 = ($52 | 0) == 0;
     if ($53) {
      $$0262$lcssa = $$0262311;
      $$lcssa295 = $329;
      $62 = $storemerge273310;
      break L24;
     }
     $54 = $50 | $$0262311;
     $55 = $storemerge273310 + 1 | 0;
     SAFE_HEAP_STORE($5 | 0, $55 | 0, 4);
     $56 = SAFE_HEAP_LOAD($55 >> 0 | 0, 1, 0) | 0 | 0;
     $57 = $56 << 24 >> 24;
     $58 = $57 + -32 | 0;
     $59 = $58 >>> 0 < 32;
     if ($59) {
      $$0262311 = $54;
      $329 = $56;
      $51 = $58;
      $storemerge273310 = $55;
     } else {
      $$0262$lcssa = $54;
      $$lcssa295 = $56;
      $62 = $55;
      break;
     }
    }
   } else {
    $$0262$lcssa = 0;
    $$lcssa295 = $46;
    $62 = $storemerge;
   }
  } while (0);
  $60 = $$lcssa295 << 24 >> 24 == 42;
  if ($60) {
   $61 = $62 + 1 | 0;
   $63 = SAFE_HEAP_LOAD($61 >> 0 | 0, 1, 0) | 0 | 0;
   $64 = $63 << 24 >> 24;
   $isdigittmp276 = $64 + -48 | 0;
   $isdigit277 = $isdigittmp276 >>> 0 < 10;
   if ($isdigit277) {
    $65 = $62 + 2 | 0;
    $66 = SAFE_HEAP_LOAD($65 >> 0 | 0, 1, 0) | 0 | 0;
    $67 = $66 << 24 >> 24 == 36;
    if ($67) {
     $68 = $4 + ($isdigittmp276 << 2) | 0;
     SAFE_HEAP_STORE($68 | 0, 10 | 0, 4);
     $69 = SAFE_HEAP_LOAD($61 >> 0 | 0, 1, 0) | 0 | 0;
     $70 = $69 << 24 >> 24;
     $71 = $70 + -48 | 0;
     $72 = $3 + ($71 << 3) | 0;
     $73 = $72;
     $74 = $73;
     $75 = SAFE_HEAP_LOAD($74 | 0, 4, 0) | 0 | 0;
     $76 = $73 + 4 | 0;
     $77 = $76;
     $78 = SAFE_HEAP_LOAD($77 | 0, 4, 0) | 0 | 0;
     $79 = $62 + 3 | 0;
     $$0259 = $75;
     $$2271 = 1;
     $storemerge278 = $79;
    } else {
     label = 23;
    }
   } else {
    label = 23;
   }
   if ((label | 0) == 23) {
    label = 0;
    $80 = ($$1270 | 0) == 0;
    if (!$80) {
     $$0 = -1;
     break;
    }
    if ($10) {
     $arglist_current = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
     $81 = $arglist_current;
     $82 = 0 + 4 | 0;
     $expanded4 = $82;
     $expanded = $expanded4 - 1 | 0;
     $83 = $81 + $expanded | 0;
     $84 = 0 + 4 | 0;
     $expanded8 = $84;
     $expanded7 = $expanded8 - 1 | 0;
     $expanded6 = $expanded7 ^ -1;
     $85 = $83 & $expanded6;
     $86 = $85;
     $87 = SAFE_HEAP_LOAD($86 | 0, 4, 0) | 0 | 0;
     $arglist_next = $86 + 4 | 0;
     SAFE_HEAP_STORE($2 | 0, $arglist_next | 0, 4);
     $$0259 = $87;
     $$2271 = 0;
     $storemerge278 = $61;
    } else {
     $$0259 = 0;
     $$2271 = 0;
     $storemerge278 = $61;
    }
   }
   SAFE_HEAP_STORE($5 | 0, $storemerge278 | 0, 4);
   $88 = ($$0259 | 0) < 0;
   $89 = $$0262$lcssa | 8192;
   $90 = 0 - $$0259 | 0;
   $$$0262 = $88 ? $89 : $$0262$lcssa;
   $$$0259 = $88 ? $90 : $$0259;
   $$1260 = $$$0259;
   $$1263 = $$$0262;
   $$3272 = $$2271;
   $94 = $storemerge278;
  } else {
   $91 = _getint($5) | 0;
   $92 = ($91 | 0) < 0;
   if ($92) {
    $$0 = -1;
    break;
   }
   $$pre346 = SAFE_HEAP_LOAD($5 | 0, 4, 0) | 0 | 0;
   $$1260 = $91;
   $$1263 = $$0262$lcssa;
   $$3272 = $$1270;
   $94 = $$pre346;
  }
  $93 = SAFE_HEAP_LOAD($94 >> 0 | 0, 1, 0) | 0 | 0;
  $95 = $93 << 24 >> 24 == 46;
  do {
   if ($95) {
    $96 = $94 + 1 | 0;
    $97 = SAFE_HEAP_LOAD($96 >> 0 | 0, 1, 0) | 0 | 0;
    $98 = $97 << 24 >> 24 == 42;
    if (!$98) {
     $125 = $94 + 1 | 0;
     SAFE_HEAP_STORE($5 | 0, $125 | 0, 4);
     $126 = _getint($5) | 0;
     $$pre347$pre = SAFE_HEAP_LOAD($5 | 0, 4, 0) | 0 | 0;
     $$0254 = $126;
     $$pre347 = $$pre347$pre;
     break;
    }
    $99 = $94 + 2 | 0;
    $100 = SAFE_HEAP_LOAD($99 >> 0 | 0, 1, 0) | 0 | 0;
    $101 = $100 << 24 >> 24;
    $isdigittmp274 = $101 + -48 | 0;
    $isdigit275 = $isdigittmp274 >>> 0 < 10;
    if ($isdigit275) {
     $102 = $94 + 3 | 0;
     $103 = SAFE_HEAP_LOAD($102 >> 0 | 0, 1, 0) | 0 | 0;
     $104 = $103 << 24 >> 24 == 36;
     if ($104) {
      $105 = $4 + ($isdigittmp274 << 2) | 0;
      SAFE_HEAP_STORE($105 | 0, 10 | 0, 4);
      $106 = SAFE_HEAP_LOAD($99 >> 0 | 0, 1, 0) | 0 | 0;
      $107 = $106 << 24 >> 24;
      $108 = $107 + -48 | 0;
      $109 = $3 + ($108 << 3) | 0;
      $110 = $109;
      $111 = $110;
      $112 = SAFE_HEAP_LOAD($111 | 0, 4, 0) | 0 | 0;
      $113 = $110 + 4 | 0;
      $114 = $113;
      $115 = SAFE_HEAP_LOAD($114 | 0, 4, 0) | 0 | 0;
      $116 = $94 + 4 | 0;
      SAFE_HEAP_STORE($5 | 0, $116 | 0, 4);
      $$0254 = $112;
      $$pre347 = $116;
      break;
     }
    }
    $117 = ($$3272 | 0) == 0;
    if (!$117) {
     $$0 = -1;
     break L1;
    }
    if ($10) {
     $arglist_current2 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
     $118 = $arglist_current2;
     $119 = 0 + 4 | 0;
     $expanded11 = $119;
     $expanded10 = $expanded11 - 1 | 0;
     $120 = $118 + $expanded10 | 0;
     $121 = 0 + 4 | 0;
     $expanded15 = $121;
     $expanded14 = $expanded15 - 1 | 0;
     $expanded13 = $expanded14 ^ -1;
     $122 = $120 & $expanded13;
     $123 = $122;
     $124 = SAFE_HEAP_LOAD($123 | 0, 4, 0) | 0 | 0;
     $arglist_next3 = $123 + 4 | 0;
     SAFE_HEAP_STORE($2 | 0, $arglist_next3 | 0, 4);
     $330 = $124;
    } else {
     $330 = 0;
    }
    SAFE_HEAP_STORE($5 | 0, $99 | 0, 4);
    $$0254 = $330;
    $$pre347 = $99;
   } else {
    $$0254 = -1;
    $$pre347 = $94;
   }
  } while (0);
  $$0252 = 0;
  $128 = $$pre347;
  while (1) {
   $127 = SAFE_HEAP_LOAD($128 >> 0 | 0, 1, 0) | 0 | 0;
   $129 = $127 << 24 >> 24;
   $130 = $129 + -65 | 0;
   $131 = $130 >>> 0 > 57;
   if ($131) {
    $$0 = -1;
    break L1;
   }
   $132 = $128 + 1 | 0;
   SAFE_HEAP_STORE($5 | 0, $132 | 0, 4);
   $133 = SAFE_HEAP_LOAD($128 >> 0 | 0, 1, 0) | 0 | 0;
   $134 = $133 << 24 >> 24;
   $135 = $134 + -65 | 0;
   $136 = (644 + ($$0252 * 58 | 0) | 0) + $135 | 0;
   $137 = SAFE_HEAP_LOAD($136 >> 0 | 0, 1, 0) | 0 | 0;
   $138 = $137 & 255;
   $139 = $138 + -1 | 0;
   $140 = $139 >>> 0 < 8;
   if ($140) {
    $$0252 = $138;
    $128 = $132;
   } else {
    break;
   }
  }
  $141 = $137 << 24 >> 24 == 0;
  if ($141) {
   $$0 = -1;
   break;
  }
  $142 = $137 << 24 >> 24 == 19;
  $143 = ($$0253 | 0) > -1;
  do {
   if ($142) {
    if ($143) {
     $$0 = -1;
     break L1;
    } else {
     label = 49;
    }
   } else {
    if ($143) {
     $144 = $4 + ($$0253 << 2) | 0;
     SAFE_HEAP_STORE($144 | 0, $138 | 0, 4);
     $145 = $3 + ($$0253 << 3) | 0;
     $146 = $145;
     $147 = $146;
     $148 = SAFE_HEAP_LOAD($147 | 0, 4, 0) | 0 | 0;
     $149 = $146 + 4 | 0;
     $150 = $149;
     $151 = SAFE_HEAP_LOAD($150 | 0, 4, 0) | 0 | 0;
     $152 = $6;
     $153 = $152;
     SAFE_HEAP_STORE($153 | 0, $148 | 0, 4);
     $154 = $152 + 4 | 0;
     $155 = $154;
     SAFE_HEAP_STORE($155 | 0, $151 | 0, 4);
     label = 49;
     break;
    }
    if (!$10) {
     $$0 = 0;
     break L1;
    }
    _pop_arg($6, $138, $2);
   }
  } while (0);
  if ((label | 0) == 49) {
   label = 0;
   if (!$10) {
    $$0243 = 0;
    $$0247 = $$1248;
    $$0269 = $$3272;
    $21 = $132;
    continue;
   }
  }
  $156 = SAFE_HEAP_LOAD($128 >> 0 | 0, 1, 0) | 0 | 0;
  $157 = $156 << 24 >> 24;
  $158 = ($$0252 | 0) != 0;
  $159 = $157 & 15;
  $160 = ($159 | 0) == 3;
  $or$cond281 = $158 & $160;
  $161 = $157 & -33;
  $$0235 = $or$cond281 ? $161 : $157;
  $162 = $$1263 & 8192;
  $163 = ($162 | 0) == 0;
  $164 = $$1263 & -65537;
  $$1263$ = $163 ? $$1263 : $164;
  L71 : do {
   switch ($$0235 | 0) {
   case 110:
    {
     $trunc = $$0252 & 255;
     switch ($trunc << 24 >> 24) {
     case 0:
      {
       $171 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
       SAFE_HEAP_STORE($171 | 0, $$1248 | 0, 4);
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
       break;
      }
     case 1:
      {
       $172 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
       SAFE_HEAP_STORE($172 | 0, $$1248 | 0, 4);
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
       break;
      }
     case 2:
      {
       $173 = ($$1248 | 0) < 0;
       $174 = $173 << 31 >> 31;
       $175 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
       $176 = $175;
       $177 = $176;
       SAFE_HEAP_STORE($177 | 0, $$1248 | 0, 4);
       $178 = $176 + 4 | 0;
       $179 = $178;
       SAFE_HEAP_STORE($179 | 0, $174 | 0, 4);
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
       break;
      }
     case 3:
      {
       $180 = $$1248 & 65535;
       $181 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
       SAFE_HEAP_STORE($181 | 0, $180 | 0, 2);
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
       break;
      }
     case 4:
      {
       $182 = $$1248 & 255;
       $183 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
       SAFE_HEAP_STORE($183 >> 0 | 0, $182 | 0, 1);
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
       break;
      }
     case 6:
      {
       $184 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
       SAFE_HEAP_STORE($184 | 0, $$1248 | 0, 4);
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
       break;
      }
     case 7:
      {
       $185 = ($$1248 | 0) < 0;
       $186 = $185 << 31 >> 31;
       $187 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
       $188 = $187;
       $189 = $188;
       SAFE_HEAP_STORE($189 | 0, $$1248 | 0, 4);
       $190 = $188 + 4 | 0;
       $191 = $190;
       SAFE_HEAP_STORE($191 | 0, $186 | 0, 4);
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
       break;
      }
     default:
      {
       $$0243 = 0;
       $$0247 = $$1248;
       $$0269 = $$3272;
       $21 = $132;
       continue L1;
      }
     }
     break;
    }
   case 112:
    {
     $192 = $$0254 >>> 0 > 8;
     $193 = $192 ? $$0254 : 8;
     $194 = $$1263$ | 8;
     $$1236 = 120;
     $$1255 = $193;
     $$3265 = $194;
     label = 61;
     break;
    }
   case 88:
   case 120:
    {
     $$1236 = $$0235;
     $$1255 = $$0254;
     $$3265 = $$1263$;
     label = 61;
     break;
    }
   case 111:
    {
     $210 = $6;
     $211 = $210;
     $212 = SAFE_HEAP_LOAD($211 | 0, 4, 0) | 0 | 0;
     $213 = $210 + 4 | 0;
     $214 = $213;
     $215 = SAFE_HEAP_LOAD($214 | 0, 4, 0) | 0 | 0;
     $216 = _fmt_o($212, $215, $11) | 0;
     $217 = $$1263$ & 8;
     $218 = ($217 | 0) == 0;
     $219 = $216;
     $220 = $12 - $219 | 0;
     $221 = ($$0254 | 0) > ($220 | 0);
     $222 = $220 + 1 | 0;
     $223 = $218 | $221;
     $$0254$$0254$ = $223 ? $$0254 : $222;
     $$0228 = $216;
     $$1233 = 0;
     $$1238 = 1108;
     $$2256 = $$0254$$0254$;
     $$4266 = $$1263$;
     $248 = $212;
     $250 = $215;
     label = 67;
     break;
    }
   case 105:
   case 100:
    {
     $224 = $6;
     $225 = $224;
     $226 = SAFE_HEAP_LOAD($225 | 0, 4, 0) | 0 | 0;
     $227 = $224 + 4 | 0;
     $228 = $227;
     $229 = SAFE_HEAP_LOAD($228 | 0, 4, 0) | 0 | 0;
     $230 = ($229 | 0) < 0;
     if ($230) {
      $231 = _i64Subtract(0, 0, $226 | 0, $229 | 0) | 0;
      $232 = tempRet0;
      $233 = $6;
      $234 = $233;
      SAFE_HEAP_STORE($234 | 0, $231 | 0, 4);
      $235 = $233 + 4 | 0;
      $236 = $235;
      SAFE_HEAP_STORE($236 | 0, $232 | 0, 4);
      $$0232 = 1;
      $$0237 = 1108;
      $242 = $231;
      $243 = $232;
      label = 66;
      break L71;
     } else {
      $237 = $$1263$ & 2048;
      $238 = ($237 | 0) == 0;
      $239 = $$1263$ & 1;
      $240 = ($239 | 0) == 0;
      $$ = $240 ? 1108 : 1110;
      $$$ = $238 ? $$ : 1109;
      $241 = $$1263$ & 2049;
      $narrow = ($241 | 0) != 0;
      $$284$ = $narrow & 1;
      $$0232 = $$284$;
      $$0237 = $$$;
      $242 = $226;
      $243 = $229;
      label = 66;
      break L71;
     }
     break;
    }
   case 117:
    {
     $165 = $6;
     $166 = $165;
     $167 = SAFE_HEAP_LOAD($166 | 0, 4, 0) | 0 | 0;
     $168 = $165 + 4 | 0;
     $169 = $168;
     $170 = SAFE_HEAP_LOAD($169 | 0, 4, 0) | 0 | 0;
     $$0232 = 0;
     $$0237 = 1108;
     $242 = $167;
     $243 = $170;
     label = 66;
     break;
    }
   case 99:
    {
     $259 = $6;
     $260 = $259;
     $261 = SAFE_HEAP_LOAD($260 | 0, 4, 0) | 0 | 0;
     $262 = $259 + 4 | 0;
     $263 = $262;
     $264 = SAFE_HEAP_LOAD($263 | 0, 4, 0) | 0 | 0;
     $265 = $261 & 255;
     SAFE_HEAP_STORE($13 >> 0 | 0, $265 | 0, 1);
     $$2 = $13;
     $$2234 = 0;
     $$2239 = 1108;
     $$2251 = $11;
     $$5 = 1;
     $$6268 = $164;
     break;
    }
   case 109:
    {
     $266 = ___errno_location() | 0;
     $267 = SAFE_HEAP_LOAD($266 | 0, 4, 0) | 0 | 0;
     $268 = _strerror($267) | 0;
     $$1 = $268;
     label = 71;
     break;
    }
   case 115:
    {
     $269 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
     $270 = ($269 | 0) != (0 | 0);
     $271 = $270 ? $269 : 1118;
     $$1 = $271;
     label = 71;
     break;
    }
   case 67:
    {
     $278 = $6;
     $279 = $278;
     $280 = SAFE_HEAP_LOAD($279 | 0, 4, 0) | 0 | 0;
     $281 = $278 + 4 | 0;
     $282 = $281;
     $283 = SAFE_HEAP_LOAD($282 | 0, 4, 0) | 0 | 0;
     SAFE_HEAP_STORE($8 | 0, $280 | 0, 4);
     SAFE_HEAP_STORE($14 | 0, 0 | 0, 4);
     SAFE_HEAP_STORE($6 | 0, $8 | 0, 4);
     $$4258355 = -1;
     $331 = $8;
     label = 75;
     break;
    }
   case 83:
    {
     $$pre349 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
     $284 = ($$0254 | 0) == 0;
     if ($284) {
      _pad_684($0, 32, $$1260, 0, $$1263$);
      $$0240$lcssa357 = 0;
      label = 84;
     } else {
      $$4258355 = $$0254;
      $331 = $$pre349;
      label = 75;
     }
     break;
    }
   case 65:
   case 71:
   case 70:
   case 69:
   case 97:
   case 103:
   case 102:
   case 101:
    {
     $306 = +(+SAFE_HEAP_LOAD_D($6 | 0, 8));
     $307 = _fmt_fp($0, $306, $$1260, $$0254, $$1263$, $$0235) | 0;
     $$0243 = $307;
     $$0247 = $$1248;
     $$0269 = $$3272;
     $21 = $132;
     continue L1;
     break;
    }
   default:
    {
     $$2 = $21;
     $$2234 = 0;
     $$2239 = 1108;
     $$2251 = $11;
     $$5 = $$0254;
     $$6268 = $$1263$;
    }
   }
  } while (0);
  L95 : do {
   if ((label | 0) == 61) {
    label = 0;
    $195 = $6;
    $196 = $195;
    $197 = SAFE_HEAP_LOAD($196 | 0, 4, 0) | 0 | 0;
    $198 = $195 + 4 | 0;
    $199 = $198;
    $200 = SAFE_HEAP_LOAD($199 | 0, 4, 0) | 0 | 0;
    $201 = $$1236 & 32;
    $202 = _fmt_x($197, $200, $11, $201) | 0;
    $203 = ($197 | 0) == 0;
    $204 = ($200 | 0) == 0;
    $205 = $203 & $204;
    $206 = $$3265 & 8;
    $207 = ($206 | 0) == 0;
    $or$cond283 = $207 | $205;
    $208 = $$1236 >> 4;
    $209 = 1108 + $208 | 0;
    $$289 = $or$cond283 ? 1108 : $209;
    $$290 = $or$cond283 ? 0 : 2;
    $$0228 = $202;
    $$1233 = $$290;
    $$1238 = $$289;
    $$2256 = $$1255;
    $$4266 = $$3265;
    $248 = $197;
    $250 = $200;
    label = 67;
   } else if ((label | 0) == 66) {
    label = 0;
    $244 = _fmt_u($242, $243, $11) | 0;
    $$0228 = $244;
    $$1233 = $$0232;
    $$1238 = $$0237;
    $$2256 = $$0254;
    $$4266 = $$1263$;
    $248 = $242;
    $250 = $243;
    label = 67;
   } else if ((label | 0) == 71) {
    label = 0;
    $272 = _memchr($$1, 0, $$0254) | 0;
    $273 = ($272 | 0) == (0 | 0);
    $274 = $272;
    $275 = $$1;
    $276 = $274 - $275 | 0;
    $277 = $$1 + $$0254 | 0;
    $$3257 = $273 ? $$0254 : $276;
    $$1250 = $273 ? $277 : $272;
    $$2 = $$1;
    $$2234 = 0;
    $$2239 = 1108;
    $$2251 = $$1250;
    $$5 = $$3257;
    $$6268 = $164;
   } else if ((label | 0) == 75) {
    label = 0;
    $$0229322 = $331;
    $$0240321 = 0;
    $$1244320 = 0;
    while (1) {
     $285 = SAFE_HEAP_LOAD($$0229322 | 0, 4, 0) | 0 | 0;
     $286 = ($285 | 0) == 0;
     if ($286) {
      $$0240$lcssa = $$0240321;
      $$2245 = $$1244320;
      break;
     }
     $287 = _wctomb($9, $285) | 0;
     $288 = ($287 | 0) < 0;
     $289 = $$4258355 - $$0240321 | 0;
     $290 = $287 >>> 0 > $289 >>> 0;
     $or$cond286 = $288 | $290;
     if ($or$cond286) {
      $$0240$lcssa = $$0240321;
      $$2245 = $287;
      break;
     }
     $291 = $$0229322 + 4 | 0;
     $292 = $287 + $$0240321 | 0;
     $293 = $$4258355 >>> 0 > $292 >>> 0;
     if ($293) {
      $$0229322 = $291;
      $$0240321 = $292;
      $$1244320 = $287;
     } else {
      $$0240$lcssa = $292;
      $$2245 = $287;
      break;
     }
    }
    $294 = ($$2245 | 0) < 0;
    if ($294) {
     $$0 = -1;
     break L1;
    }
    _pad_684($0, 32, $$1260, $$0240$lcssa, $$1263$);
    $295 = ($$0240$lcssa | 0) == 0;
    if ($295) {
     $$0240$lcssa357 = 0;
     label = 84;
    } else {
     $$1230333 = $331;
     $$1241332 = 0;
     while (1) {
      $296 = SAFE_HEAP_LOAD($$1230333 | 0, 4, 0) | 0 | 0;
      $297 = ($296 | 0) == 0;
      if ($297) {
       $$0240$lcssa357 = $$0240$lcssa;
       label = 84;
       break L95;
      }
      $298 = _wctomb($9, $296) | 0;
      $299 = $298 + $$1241332 | 0;
      $300 = ($299 | 0) > ($$0240$lcssa | 0);
      if ($300) {
       $$0240$lcssa357 = $$0240$lcssa;
       label = 84;
       break L95;
      }
      $301 = $$1230333 + 4 | 0;
      _out($0, $9, $298);
      $302 = $299 >>> 0 < $$0240$lcssa >>> 0;
      if ($302) {
       $$1230333 = $301;
       $$1241332 = $299;
      } else {
       $$0240$lcssa357 = $$0240$lcssa;
       label = 84;
       break;
      }
     }
    }
   }
  } while (0);
  if ((label | 0) == 67) {
   label = 0;
   $245 = ($$2256 | 0) > -1;
   $246 = $$4266 & -65537;
   $$$4266 = $245 ? $246 : $$4266;
   $247 = ($248 | 0) != 0;
   $249 = ($250 | 0) != 0;
   $251 = $247 | $249;
   $252 = ($$2256 | 0) != 0;
   $or$cond = $252 | $251;
   $253 = $$0228;
   $254 = $12 - $253 | 0;
   $255 = $251 ^ 1;
   $256 = $255 & 1;
   $257 = $256 + $254 | 0;
   $258 = ($$2256 | 0) > ($257 | 0);
   $$2256$ = $258 ? $$2256 : $257;
   $$2256$$$2256 = $or$cond ? $$2256$ : $$2256;
   $$0228$ = $or$cond ? $$0228 : $11;
   $$2 = $$0228$;
   $$2234 = $$1233;
   $$2239 = $$1238;
   $$2251 = $11;
   $$5 = $$2256$$$2256;
   $$6268 = $$$4266;
  } else if ((label | 0) == 84) {
   label = 0;
   $303 = $$1263$ ^ 8192;
   _pad_684($0, 32, $$1260, $$0240$lcssa357, $303);
   $304 = ($$1260 | 0) > ($$0240$lcssa357 | 0);
   $305 = $304 ? $$1260 : $$0240$lcssa357;
   $$0243 = $305;
   $$0247 = $$1248;
   $$0269 = $$3272;
   $21 = $132;
   continue;
  }
  $308 = $$2251;
  $309 = $$2;
  $310 = $308 - $309 | 0;
  $311 = ($$5 | 0) < ($310 | 0);
  $$$5 = $311 ? $310 : $$5;
  $312 = $$$5 + $$2234 | 0;
  $313 = ($$1260 | 0) < ($312 | 0);
  $$2261 = $313 ? $312 : $$1260;
  _pad_684($0, 32, $$2261, $312, $$6268);
  _out($0, $$2239, $$2234);
  $314 = $$6268 ^ 65536;
  _pad_684($0, 48, $$2261, $312, $314);
  _pad_684($0, 48, $$$5, $310, 0);
  _out($0, $$2, $310);
  $315 = $$6268 ^ 8192;
  _pad_684($0, 32, $$2261, $312, $315);
  $$0243 = $$2261;
  $$0247 = $$1248;
  $$0269 = $$3272;
  $21 = $132;
 }
 L114 : do {
  if ((label | 0) == 87) {
   $316 = ($0 | 0) == (0 | 0);
   if ($316) {
    $317 = ($$0269 | 0) == 0;
    if ($317) {
     $$0 = 0;
    } else {
     $$2242305 = 1;
     while (1) {
      $318 = $4 + ($$2242305 << 2) | 0;
      $319 = SAFE_HEAP_LOAD($318 | 0, 4, 0) | 0 | 0;
      $320 = ($319 | 0) == 0;
      if ($320) {
       $$3303 = $$2242305;
       break;
      }
      $321 = $3 + ($$2242305 << 3) | 0;
      _pop_arg($321, $319, $2);
      $322 = $$2242305 + 1 | 0;
      $323 = ($322 | 0) < 10;
      if ($323) {
       $$2242305 = $322;
      } else {
       $$0 = 1;
       break L114;
      }
     }
     while (1) {
      $326 = $4 + ($$3303 << 2) | 0;
      $327 = SAFE_HEAP_LOAD($326 | 0, 4, 0) | 0 | 0;
      $328 = ($327 | 0) == 0;
      $325 = $$3303 + 1 | 0;
      if (!$328) {
       $$0 = -1;
       break L114;
      }
      $324 = ($325 | 0) < 10;
      if ($324) {
       $$3303 = $325;
      } else {
       $$0 = 1;
       break;
      }
     }
    }
   } else {
    $$0 = $$1248;
   }
  }
 } while (0);
 STACKTOP = sp;
 return $$0 | 0;
}

function _free($0) {
 $0 = $0 | 0;
 var $$0212$i = 0, $$0212$in$i = 0, $$0383 = 0, $$0384 = 0, $$0396 = 0, $$0403 = 0, $$1 = 0, $$1382 = 0, $$1387 = 0, $$1390 = 0, $$1398 = 0, $$1402 = 0, $$2 = 0, $$3 = 0, $$3400 = 0, $$pre = 0, $$pre$phi443Z2D = 0, $$pre$phi445Z2D = 0, $$pre$phiZ2D = 0, $$pre442 = 0;
 var $$pre444 = 0, $$sink3 = 0, $$sink5 = 0, $1 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0;
 var $114 = 0, $115 = 0, $116 = 0, $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0;
 var $132 = 0, $133 = 0, $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0;
 var $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0;
 var $169 = 0, $17 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0, $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0;
 var $187 = 0, $188 = 0, $189 = 0, $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0, $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $2 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0;
 var $204 = 0, $205 = 0, $206 = 0, $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0, $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0;
 var $222 = 0, $223 = 0, $224 = 0, $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0, $23 = 0, $230 = 0, $231 = 0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0, $238 = 0, $239 = 0, $24 = 0;
 var $240 = 0, $241 = 0, $242 = 0, $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0, $249 = 0, $25 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0;
 var $259 = 0, $26 = 0, $260 = 0, $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0, $267 = 0, $268 = 0, $269 = 0, $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0, $274 = 0, $275 = 0, $276 = 0;
 var $277 = 0, $278 = 0, $279 = 0, $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0, $284 = 0, $285 = 0, $286 = 0, $287 = 0, $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0, $292 = 0, $293 = 0, $294 = 0;
 var $295 = 0, $296 = 0, $297 = 0, $298 = 0, $299 = 0, $3 = 0, $30 = 0, $300 = 0, $301 = 0, $302 = 0, $303 = 0, $304 = 0, $305 = 0, $306 = 0, $307 = 0, $308 = 0, $309 = 0, $31 = 0, $310 = 0, $311 = 0;
 var $312 = 0, $313 = 0, $314 = 0, $315 = 0, $316 = 0, $317 = 0, $318 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0;
 var $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0;
 var $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0;
 var $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0;
 var $99 = 0, $cond421 = 0, $cond422 = 0, $not$ = 0, $not$405 = 0, $not$437 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ($0 | 0) == (0 | 0);
 if ($1) {
  return;
 }
 $2 = $0 + -8 | 0;
 $3 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
 $4 = $2 >>> 0 < $3 >>> 0;
 if ($4) {
  _abort();
 }
 $5 = $0 + -4 | 0;
 $6 = SAFE_HEAP_LOAD($5 | 0, 4, 0) | 0 | 0;
 $7 = $6 & 3;
 $8 = ($7 | 0) == 1;
 if ($8) {
  _abort();
 }
 $9 = $6 & -8;
 $10 = $2 + $9 | 0;
 $11 = $6 & 1;
 $12 = ($11 | 0) == 0;
 L10 : do {
  if ($12) {
   $13 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
   $14 = ($7 | 0) == 0;
   if ($14) {
    return;
   }
   $15 = 0 - $13 | 0;
   $16 = $2 + $15 | 0;
   $17 = $13 + $9 | 0;
   $18 = $16 >>> 0 < $3 >>> 0;
   if ($18) {
    _abort();
   }
   $19 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
   $20 = ($16 | 0) == ($19 | 0);
   if ($20) {
    $104 = $10 + 4 | 0;
    $105 = SAFE_HEAP_LOAD($104 | 0, 4, 0) | 0 | 0;
    $106 = $105 & 3;
    $107 = ($106 | 0) == 3;
    if (!$107) {
     $$1 = $16;
     $$1382 = $17;
     $113 = $16;
     break;
    }
    $108 = $16 + $17 | 0;
    $109 = $16 + 4 | 0;
    $110 = $17 | 1;
    $111 = $105 & -2;
    SAFE_HEAP_STORE(3080 | 0, $17 | 0, 4);
    SAFE_HEAP_STORE($104 | 0, $111 | 0, 4);
    SAFE_HEAP_STORE($109 | 0, $110 | 0, 4);
    SAFE_HEAP_STORE($108 | 0, $17 | 0, 4);
    return;
   }
   $21 = $13 >>> 3;
   $22 = $13 >>> 0 < 256;
   if ($22) {
    $23 = $16 + 8 | 0;
    $24 = SAFE_HEAP_LOAD($23 | 0, 4, 0) | 0 | 0;
    $25 = $16 + 12 | 0;
    $26 = SAFE_HEAP_LOAD($25 | 0, 4, 0) | 0 | 0;
    $27 = $21 << 1;
    $28 = 3112 + ($27 << 2) | 0;
    $29 = ($24 | 0) == ($28 | 0);
    if (!$29) {
     $30 = $24 >>> 0 < $3 >>> 0;
     if ($30) {
      _abort();
     }
     $31 = $24 + 12 | 0;
     $32 = SAFE_HEAP_LOAD($31 | 0, 4, 0) | 0 | 0;
     $33 = ($32 | 0) == ($16 | 0);
     if (!$33) {
      _abort();
     }
    }
    $34 = ($26 | 0) == ($24 | 0);
    if ($34) {
     $35 = 1 << $21;
     $36 = $35 ^ -1;
     $37 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
     $38 = $37 & $36;
     SAFE_HEAP_STORE(768 * 4 | 0, $38 | 0, 4);
     $$1 = $16;
     $$1382 = $17;
     $113 = $16;
     break;
    }
    $39 = ($26 | 0) == ($28 | 0);
    if ($39) {
     $$pre444 = $26 + 8 | 0;
     $$pre$phi445Z2D = $$pre444;
    } else {
     $40 = $26 >>> 0 < $3 >>> 0;
     if ($40) {
      _abort();
     }
     $41 = $26 + 8 | 0;
     $42 = SAFE_HEAP_LOAD($41 | 0, 4, 0) | 0 | 0;
     $43 = ($42 | 0) == ($16 | 0);
     if ($43) {
      $$pre$phi445Z2D = $41;
     } else {
      _abort();
     }
    }
    $44 = $24 + 12 | 0;
    SAFE_HEAP_STORE($44 | 0, $26 | 0, 4);
    SAFE_HEAP_STORE($$pre$phi445Z2D | 0, $24 | 0, 4);
    $$1 = $16;
    $$1382 = $17;
    $113 = $16;
    break;
   }
   $45 = $16 + 24 | 0;
   $46 = SAFE_HEAP_LOAD($45 | 0, 4, 0) | 0 | 0;
   $47 = $16 + 12 | 0;
   $48 = SAFE_HEAP_LOAD($47 | 0, 4, 0) | 0 | 0;
   $49 = ($48 | 0) == ($16 | 0);
   do {
    if ($49) {
     $59 = $16 + 16 | 0;
     $60 = $59 + 4 | 0;
     $61 = SAFE_HEAP_LOAD($60 | 0, 4, 0) | 0 | 0;
     $62 = ($61 | 0) == (0 | 0);
     if ($62) {
      $63 = SAFE_HEAP_LOAD($59 | 0, 4, 0) | 0 | 0;
      $64 = ($63 | 0) == (0 | 0);
      if ($64) {
       $$3 = 0;
       break;
      } else {
       $$1387 = $63;
       $$1390 = $59;
      }
     } else {
      $$1387 = $61;
      $$1390 = $60;
     }
     while (1) {
      $65 = $$1387 + 20 | 0;
      $66 = SAFE_HEAP_LOAD($65 | 0, 4, 0) | 0 | 0;
      $67 = ($66 | 0) == (0 | 0);
      if (!$67) {
       $$1387 = $66;
       $$1390 = $65;
       continue;
      }
      $68 = $$1387 + 16 | 0;
      $69 = SAFE_HEAP_LOAD($68 | 0, 4, 0) | 0 | 0;
      $70 = ($69 | 0) == (0 | 0);
      if ($70) {
       break;
      } else {
       $$1387 = $69;
       $$1390 = $68;
      }
     }
     $71 = $$1390 >>> 0 < $3 >>> 0;
     if ($71) {
      _abort();
     } else {
      SAFE_HEAP_STORE($$1390 | 0, 0 | 0, 4);
      $$3 = $$1387;
      break;
     }
    } else {
     $50 = $16 + 8 | 0;
     $51 = SAFE_HEAP_LOAD($50 | 0, 4, 0) | 0 | 0;
     $52 = $51 >>> 0 < $3 >>> 0;
     if ($52) {
      _abort();
     }
     $53 = $51 + 12 | 0;
     $54 = SAFE_HEAP_LOAD($53 | 0, 4, 0) | 0 | 0;
     $55 = ($54 | 0) == ($16 | 0);
     if (!$55) {
      _abort();
     }
     $56 = $48 + 8 | 0;
     $57 = SAFE_HEAP_LOAD($56 | 0, 4, 0) | 0 | 0;
     $58 = ($57 | 0) == ($16 | 0);
     if ($58) {
      SAFE_HEAP_STORE($53 | 0, $48 | 0, 4);
      SAFE_HEAP_STORE($56 | 0, $51 | 0, 4);
      $$3 = $48;
      break;
     } else {
      _abort();
     }
    }
   } while (0);
   $72 = ($46 | 0) == (0 | 0);
   if ($72) {
    $$1 = $16;
    $$1382 = $17;
    $113 = $16;
   } else {
    $73 = $16 + 28 | 0;
    $74 = SAFE_HEAP_LOAD($73 | 0, 4, 0) | 0 | 0;
    $75 = 3376 + ($74 << 2) | 0;
    $76 = SAFE_HEAP_LOAD($75 | 0, 4, 0) | 0 | 0;
    $77 = ($16 | 0) == ($76 | 0);
    do {
     if ($77) {
      SAFE_HEAP_STORE($75 | 0, $$3 | 0, 4);
      $cond421 = ($$3 | 0) == (0 | 0);
      if ($cond421) {
       $78 = 1 << $74;
       $79 = $78 ^ -1;
       $80 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
       $81 = $80 & $79;
       SAFE_HEAP_STORE(3076 | 0, $81 | 0, 4);
       $$1 = $16;
       $$1382 = $17;
       $113 = $16;
       break L10;
      }
     } else {
      $82 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $83 = $46 >>> 0 < $82 >>> 0;
      if ($83) {
       _abort();
      } else {
       $84 = $46 + 16 | 0;
       $85 = SAFE_HEAP_LOAD($84 | 0, 4, 0) | 0 | 0;
       $not$405 = ($85 | 0) != ($16 | 0);
       $$sink3 = $not$405 & 1;
       $86 = ($46 + 16 | 0) + ($$sink3 << 2) | 0;
       SAFE_HEAP_STORE($86 | 0, $$3 | 0, 4);
       $87 = ($$3 | 0) == (0 | 0);
       if ($87) {
        $$1 = $16;
        $$1382 = $17;
        $113 = $16;
        break L10;
       } else {
        break;
       }
      }
     }
    } while (0);
    $88 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
    $89 = $$3 >>> 0 < $88 >>> 0;
    if ($89) {
     _abort();
    }
    $90 = $$3 + 24 | 0;
    SAFE_HEAP_STORE($90 | 0, $46 | 0, 4);
    $91 = $16 + 16 | 0;
    $92 = SAFE_HEAP_LOAD($91 | 0, 4, 0) | 0 | 0;
    $93 = ($92 | 0) == (0 | 0);
    do {
     if (!$93) {
      $94 = $92 >>> 0 < $88 >>> 0;
      if ($94) {
       _abort();
      } else {
       $95 = $$3 + 16 | 0;
       SAFE_HEAP_STORE($95 | 0, $92 | 0, 4);
       $96 = $92 + 24 | 0;
       SAFE_HEAP_STORE($96 | 0, $$3 | 0, 4);
       break;
      }
     }
    } while (0);
    $97 = $91 + 4 | 0;
    $98 = SAFE_HEAP_LOAD($97 | 0, 4, 0) | 0 | 0;
    $99 = ($98 | 0) == (0 | 0);
    if ($99) {
     $$1 = $16;
     $$1382 = $17;
     $113 = $16;
    } else {
     $100 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $101 = $98 >>> 0 < $100 >>> 0;
     if ($101) {
      _abort();
     } else {
      $102 = $$3 + 20 | 0;
      SAFE_HEAP_STORE($102 | 0, $98 | 0, 4);
      $103 = $98 + 24 | 0;
      SAFE_HEAP_STORE($103 | 0, $$3 | 0, 4);
      $$1 = $16;
      $$1382 = $17;
      $113 = $16;
      break;
     }
    }
   }
  } else {
   $$1 = $2;
   $$1382 = $9;
   $113 = $2;
  }
 } while (0);
 $112 = $113 >>> 0 < $10 >>> 0;
 if (!$112) {
  _abort();
 }
 $114 = $10 + 4 | 0;
 $115 = SAFE_HEAP_LOAD($114 | 0, 4, 0) | 0 | 0;
 $116 = $115 & 1;
 $117 = ($116 | 0) == 0;
 if ($117) {
  _abort();
 }
 $118 = $115 & 2;
 $119 = ($118 | 0) == 0;
 if ($119) {
  $120 = SAFE_HEAP_LOAD(3096 | 0, 4, 0) | 0 | 0;
  $121 = ($10 | 0) == ($120 | 0);
  $122 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
  if ($121) {
   $123 = SAFE_HEAP_LOAD(3084 | 0, 4, 0) | 0 | 0;
   $124 = $123 + $$1382 | 0;
   SAFE_HEAP_STORE(3084 | 0, $124 | 0, 4);
   SAFE_HEAP_STORE(3096 | 0, $$1 | 0, 4);
   $125 = $124 | 1;
   $126 = $$1 + 4 | 0;
   SAFE_HEAP_STORE($126 | 0, $125 | 0, 4);
   $127 = ($$1 | 0) == ($122 | 0);
   if (!$127) {
    return;
   }
   SAFE_HEAP_STORE(3092 | 0, 0 | 0, 4);
   SAFE_HEAP_STORE(3080 | 0, 0 | 0, 4);
   return;
  }
  $128 = ($10 | 0) == ($122 | 0);
  if ($128) {
   $129 = SAFE_HEAP_LOAD(3080 | 0, 4, 0) | 0 | 0;
   $130 = $129 + $$1382 | 0;
   SAFE_HEAP_STORE(3080 | 0, $130 | 0, 4);
   SAFE_HEAP_STORE(3092 | 0, $113 | 0, 4);
   $131 = $130 | 1;
   $132 = $$1 + 4 | 0;
   SAFE_HEAP_STORE($132 | 0, $131 | 0, 4);
   $133 = $113 + $130 | 0;
   SAFE_HEAP_STORE($133 | 0, $130 | 0, 4);
   return;
  }
  $134 = $115 & -8;
  $135 = $134 + $$1382 | 0;
  $136 = $115 >>> 3;
  $137 = $115 >>> 0 < 256;
  L108 : do {
   if ($137) {
    $138 = $10 + 8 | 0;
    $139 = SAFE_HEAP_LOAD($138 | 0, 4, 0) | 0 | 0;
    $140 = $10 + 12 | 0;
    $141 = SAFE_HEAP_LOAD($140 | 0, 4, 0) | 0 | 0;
    $142 = $136 << 1;
    $143 = 3112 + ($142 << 2) | 0;
    $144 = ($139 | 0) == ($143 | 0);
    if (!$144) {
     $145 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $146 = $139 >>> 0 < $145 >>> 0;
     if ($146) {
      _abort();
     }
     $147 = $139 + 12 | 0;
     $148 = SAFE_HEAP_LOAD($147 | 0, 4, 0) | 0 | 0;
     $149 = ($148 | 0) == ($10 | 0);
     if (!$149) {
      _abort();
     }
    }
    $150 = ($141 | 0) == ($139 | 0);
    if ($150) {
     $151 = 1 << $136;
     $152 = $151 ^ -1;
     $153 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
     $154 = $153 & $152;
     SAFE_HEAP_STORE(768 * 4 | 0, $154 | 0, 4);
     break;
    }
    $155 = ($141 | 0) == ($143 | 0);
    if ($155) {
     $$pre442 = $141 + 8 | 0;
     $$pre$phi443Z2D = $$pre442;
    } else {
     $156 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $157 = $141 >>> 0 < $156 >>> 0;
     if ($157) {
      _abort();
     }
     $158 = $141 + 8 | 0;
     $159 = SAFE_HEAP_LOAD($158 | 0, 4, 0) | 0 | 0;
     $160 = ($159 | 0) == ($10 | 0);
     if ($160) {
      $$pre$phi443Z2D = $158;
     } else {
      _abort();
     }
    }
    $161 = $139 + 12 | 0;
    SAFE_HEAP_STORE($161 | 0, $141 | 0, 4);
    SAFE_HEAP_STORE($$pre$phi443Z2D | 0, $139 | 0, 4);
   } else {
    $162 = $10 + 24 | 0;
    $163 = SAFE_HEAP_LOAD($162 | 0, 4, 0) | 0 | 0;
    $164 = $10 + 12 | 0;
    $165 = SAFE_HEAP_LOAD($164 | 0, 4, 0) | 0 | 0;
    $166 = ($165 | 0) == ($10 | 0);
    do {
     if ($166) {
      $177 = $10 + 16 | 0;
      $178 = $177 + 4 | 0;
      $179 = SAFE_HEAP_LOAD($178 | 0, 4, 0) | 0 | 0;
      $180 = ($179 | 0) == (0 | 0);
      if ($180) {
       $181 = SAFE_HEAP_LOAD($177 | 0, 4, 0) | 0 | 0;
       $182 = ($181 | 0) == (0 | 0);
       if ($182) {
        $$3400 = 0;
        break;
       } else {
        $$1398 = $181;
        $$1402 = $177;
       }
      } else {
       $$1398 = $179;
       $$1402 = $178;
      }
      while (1) {
       $183 = $$1398 + 20 | 0;
       $184 = SAFE_HEAP_LOAD($183 | 0, 4, 0) | 0 | 0;
       $185 = ($184 | 0) == (0 | 0);
       if (!$185) {
        $$1398 = $184;
        $$1402 = $183;
        continue;
       }
       $186 = $$1398 + 16 | 0;
       $187 = SAFE_HEAP_LOAD($186 | 0, 4, 0) | 0 | 0;
       $188 = ($187 | 0) == (0 | 0);
       if ($188) {
        break;
       } else {
        $$1398 = $187;
        $$1402 = $186;
       }
      }
      $189 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $190 = $$1402 >>> 0 < $189 >>> 0;
      if ($190) {
       _abort();
      } else {
       SAFE_HEAP_STORE($$1402 | 0, 0 | 0, 4);
       $$3400 = $$1398;
       break;
      }
     } else {
      $167 = $10 + 8 | 0;
      $168 = SAFE_HEAP_LOAD($167 | 0, 4, 0) | 0 | 0;
      $169 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $170 = $168 >>> 0 < $169 >>> 0;
      if ($170) {
       _abort();
      }
      $171 = $168 + 12 | 0;
      $172 = SAFE_HEAP_LOAD($171 | 0, 4, 0) | 0 | 0;
      $173 = ($172 | 0) == ($10 | 0);
      if (!$173) {
       _abort();
      }
      $174 = $165 + 8 | 0;
      $175 = SAFE_HEAP_LOAD($174 | 0, 4, 0) | 0 | 0;
      $176 = ($175 | 0) == ($10 | 0);
      if ($176) {
       SAFE_HEAP_STORE($171 | 0, $165 | 0, 4);
       SAFE_HEAP_STORE($174 | 0, $168 | 0, 4);
       $$3400 = $165;
       break;
      } else {
       _abort();
      }
     }
    } while (0);
    $191 = ($163 | 0) == (0 | 0);
    if (!$191) {
     $192 = $10 + 28 | 0;
     $193 = SAFE_HEAP_LOAD($192 | 0, 4, 0) | 0 | 0;
     $194 = 3376 + ($193 << 2) | 0;
     $195 = SAFE_HEAP_LOAD($194 | 0, 4, 0) | 0 | 0;
     $196 = ($10 | 0) == ($195 | 0);
     do {
      if ($196) {
       SAFE_HEAP_STORE($194 | 0, $$3400 | 0, 4);
       $cond422 = ($$3400 | 0) == (0 | 0);
       if ($cond422) {
        $197 = 1 << $193;
        $198 = $197 ^ -1;
        $199 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
        $200 = $199 & $198;
        SAFE_HEAP_STORE(3076 | 0, $200 | 0, 4);
        break L108;
       }
      } else {
       $201 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
       $202 = $163 >>> 0 < $201 >>> 0;
       if ($202) {
        _abort();
       } else {
        $203 = $163 + 16 | 0;
        $204 = SAFE_HEAP_LOAD($203 | 0, 4, 0) | 0 | 0;
        $not$ = ($204 | 0) != ($10 | 0);
        $$sink5 = $not$ & 1;
        $205 = ($163 + 16 | 0) + ($$sink5 << 2) | 0;
        SAFE_HEAP_STORE($205 | 0, $$3400 | 0, 4);
        $206 = ($$3400 | 0) == (0 | 0);
        if ($206) {
         break L108;
        } else {
         break;
        }
       }
      }
     } while (0);
     $207 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $208 = $$3400 >>> 0 < $207 >>> 0;
     if ($208) {
      _abort();
     }
     $209 = $$3400 + 24 | 0;
     SAFE_HEAP_STORE($209 | 0, $163 | 0, 4);
     $210 = $10 + 16 | 0;
     $211 = SAFE_HEAP_LOAD($210 | 0, 4, 0) | 0 | 0;
     $212 = ($211 | 0) == (0 | 0);
     do {
      if (!$212) {
       $213 = $211 >>> 0 < $207 >>> 0;
       if ($213) {
        _abort();
       } else {
        $214 = $$3400 + 16 | 0;
        SAFE_HEAP_STORE($214 | 0, $211 | 0, 4);
        $215 = $211 + 24 | 0;
        SAFE_HEAP_STORE($215 | 0, $$3400 | 0, 4);
        break;
       }
      }
     } while (0);
     $216 = $210 + 4 | 0;
     $217 = SAFE_HEAP_LOAD($216 | 0, 4, 0) | 0 | 0;
     $218 = ($217 | 0) == (0 | 0);
     if (!$218) {
      $219 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $220 = $217 >>> 0 < $219 >>> 0;
      if ($220) {
       _abort();
      } else {
       $221 = $$3400 + 20 | 0;
       SAFE_HEAP_STORE($221 | 0, $217 | 0, 4);
       $222 = $217 + 24 | 0;
       SAFE_HEAP_STORE($222 | 0, $$3400 | 0, 4);
       break;
      }
     }
    }
   }
  } while (0);
  $223 = $135 | 1;
  $224 = $$1 + 4 | 0;
  SAFE_HEAP_STORE($224 | 0, $223 | 0, 4);
  $225 = $113 + $135 | 0;
  SAFE_HEAP_STORE($225 | 0, $135 | 0, 4);
  $226 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
  $227 = ($$1 | 0) == ($226 | 0);
  if ($227) {
   SAFE_HEAP_STORE(3080 | 0, $135 | 0, 4);
   return;
  } else {
   $$2 = $135;
  }
 } else {
  $228 = $115 & -2;
  SAFE_HEAP_STORE($114 | 0, $228 | 0, 4);
  $229 = $$1382 | 1;
  $230 = $$1 + 4 | 0;
  SAFE_HEAP_STORE($230 | 0, $229 | 0, 4);
  $231 = $113 + $$1382 | 0;
  SAFE_HEAP_STORE($231 | 0, $$1382 | 0, 4);
  $$2 = $$1382;
 }
 $232 = $$2 >>> 3;
 $233 = $$2 >>> 0 < 256;
 if ($233) {
  $234 = $232 << 1;
  $235 = 3112 + ($234 << 2) | 0;
  $236 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
  $237 = 1 << $232;
  $238 = $236 & $237;
  $239 = ($238 | 0) == 0;
  if ($239) {
   $240 = $236 | $237;
   SAFE_HEAP_STORE(768 * 4 | 0, $240 | 0, 4);
   $$pre = $235 + 8 | 0;
   $$0403 = $235;
   $$pre$phiZ2D = $$pre;
  } else {
   $241 = $235 + 8 | 0;
   $242 = SAFE_HEAP_LOAD($241 | 0, 4, 0) | 0 | 0;
   $243 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
   $244 = $242 >>> 0 < $243 >>> 0;
   if ($244) {
    _abort();
   } else {
    $$0403 = $242;
    $$pre$phiZ2D = $241;
   }
  }
  SAFE_HEAP_STORE($$pre$phiZ2D | 0, $$1 | 0, 4);
  $245 = $$0403 + 12 | 0;
  SAFE_HEAP_STORE($245 | 0, $$1 | 0, 4);
  $246 = $$1 + 8 | 0;
  SAFE_HEAP_STORE($246 | 0, $$0403 | 0, 4);
  $247 = $$1 + 12 | 0;
  SAFE_HEAP_STORE($247 | 0, $235 | 0, 4);
  return;
 }
 $248 = $$2 >>> 8;
 $249 = ($248 | 0) == 0;
 if ($249) {
  $$0396 = 0;
 } else {
  $250 = $$2 >>> 0 > 16777215;
  if ($250) {
   $$0396 = 31;
  } else {
   $251 = $248 + 1048320 | 0;
   $252 = $251 >>> 16;
   $253 = $252 & 8;
   $254 = $248 << $253;
   $255 = $254 + 520192 | 0;
   $256 = $255 >>> 16;
   $257 = $256 & 4;
   $258 = $257 | $253;
   $259 = $254 << $257;
   $260 = $259 + 245760 | 0;
   $261 = $260 >>> 16;
   $262 = $261 & 2;
   $263 = $258 | $262;
   $264 = 14 - $263 | 0;
   $265 = $259 << $262;
   $266 = $265 >>> 15;
   $267 = $264 + $266 | 0;
   $268 = $267 << 1;
   $269 = $267 + 7 | 0;
   $270 = $$2 >>> $269;
   $271 = $270 & 1;
   $272 = $271 | $268;
   $$0396 = $272;
  }
 }
 $273 = 3376 + ($$0396 << 2) | 0;
 $274 = $$1 + 28 | 0;
 SAFE_HEAP_STORE($274 | 0, $$0396 | 0, 4);
 $275 = $$1 + 16 | 0;
 $276 = $$1 + 20 | 0;
 SAFE_HEAP_STORE($276 | 0, 0 | 0, 4);
 SAFE_HEAP_STORE($275 | 0, 0 | 0, 4);
 $277 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
 $278 = 1 << $$0396;
 $279 = $277 & $278;
 $280 = ($279 | 0) == 0;
 do {
  if ($280) {
   $281 = $277 | $278;
   SAFE_HEAP_STORE(3076 | 0, $281 | 0, 4);
   SAFE_HEAP_STORE($273 | 0, $$1 | 0, 4);
   $282 = $$1 + 24 | 0;
   SAFE_HEAP_STORE($282 | 0, $273 | 0, 4);
   $283 = $$1 + 12 | 0;
   SAFE_HEAP_STORE($283 | 0, $$1 | 0, 4);
   $284 = $$1 + 8 | 0;
   SAFE_HEAP_STORE($284 | 0, $$1 | 0, 4);
  } else {
   $285 = SAFE_HEAP_LOAD($273 | 0, 4, 0) | 0 | 0;
   $286 = ($$0396 | 0) == 31;
   $287 = $$0396 >>> 1;
   $288 = 25 - $287 | 0;
   $289 = $286 ? 0 : $288;
   $290 = $$2 << $289;
   $$0383 = $290;
   $$0384 = $285;
   while (1) {
    $291 = $$0384 + 4 | 0;
    $292 = SAFE_HEAP_LOAD($291 | 0, 4, 0) | 0 | 0;
    $293 = $292 & -8;
    $294 = ($293 | 0) == ($$2 | 0);
    if ($294) {
     label = 124;
     break;
    }
    $295 = $$0383 >>> 31;
    $296 = ($$0384 + 16 | 0) + ($295 << 2) | 0;
    $297 = $$0383 << 1;
    $298 = SAFE_HEAP_LOAD($296 | 0, 4, 0) | 0 | 0;
    $299 = ($298 | 0) == (0 | 0);
    if ($299) {
     label = 121;
     break;
    } else {
     $$0383 = $297;
     $$0384 = $298;
    }
   }
   if ((label | 0) == 121) {
    $300 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
    $301 = $296 >>> 0 < $300 >>> 0;
    if ($301) {
     _abort();
    } else {
     SAFE_HEAP_STORE($296 | 0, $$1 | 0, 4);
     $302 = $$1 + 24 | 0;
     SAFE_HEAP_STORE($302 | 0, $$0384 | 0, 4);
     $303 = $$1 + 12 | 0;
     SAFE_HEAP_STORE($303 | 0, $$1 | 0, 4);
     $304 = $$1 + 8 | 0;
     SAFE_HEAP_STORE($304 | 0, $$1 | 0, 4);
     break;
    }
   } else if ((label | 0) == 124) {
    $305 = $$0384 + 8 | 0;
    $306 = SAFE_HEAP_LOAD($305 | 0, 4, 0) | 0 | 0;
    $307 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
    $308 = $306 >>> 0 >= $307 >>> 0;
    $not$437 = $$0384 >>> 0 >= $307 >>> 0;
    $309 = $308 & $not$437;
    if ($309) {
     $310 = $306 + 12 | 0;
     SAFE_HEAP_STORE($310 | 0, $$1 | 0, 4);
     SAFE_HEAP_STORE($305 | 0, $$1 | 0, 4);
     $311 = $$1 + 8 | 0;
     SAFE_HEAP_STORE($311 | 0, $306 | 0, 4);
     $312 = $$1 + 12 | 0;
     SAFE_HEAP_STORE($312 | 0, $$0384 | 0, 4);
     $313 = $$1 + 24 | 0;
     SAFE_HEAP_STORE($313 | 0, 0 | 0, 4);
     break;
    } else {
     _abort();
    }
   }
  }
 } while (0);
 $314 = SAFE_HEAP_LOAD(3104 | 0, 4, 0) | 0 | 0;
 $315 = $314 + -1 | 0;
 SAFE_HEAP_STORE(3104 | 0, $315 | 0, 4);
 $316 = ($315 | 0) == 0;
 if ($316) {
  $$0212$in$i = 3528;
 } else {
  return;
 }
 while (1) {
  $$0212$i = SAFE_HEAP_LOAD($$0212$in$i | 0, 4, 0) | 0 | 0;
  $317 = ($$0212$i | 0) == (0 | 0);
  $318 = $$0212$i + 8 | 0;
  if ($317) {
   break;
  } else {
   $$0212$in$i = $318;
  }
 }
 SAFE_HEAP_STORE(3104 | 0, -1 | 0, 4);
 return;
}

function _dispose_chunk($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$0419 = 0, $$0420 = 0, $$0431 = 0, $$0438 = 0, $$1 = 0, $$1418 = 0, $$1426 = 0, $$1429 = 0, $$1433 = 0, $$1437 = 0, $$2 = 0, $$3 = 0, $$3435 = 0, $$pre = 0, $$pre$phi24Z2D = 0, $$pre$phi26Z2D = 0, $$pre$phiZ2D = 0, $$pre23 = 0, $$pre25 = 0, $$sink2 = 0;
 var $$sink4 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0;
 var $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0;
 var $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0;
 var $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0;
 var $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0, $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0, $189 = 0;
 var $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0, $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $2 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0, $206 = 0;
 var $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0, $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0, $224 = 0;
 var $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0, $23 = 0, $230 = 0, $231 = 0, $232 = 0, $233 = 0, $234 = 0, $235 = 0, $236 = 0, $237 = 0, $238 = 0, $239 = 0, $24 = 0, $240 = 0, $241 = 0, $242 = 0;
 var $243 = 0, $244 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0, $249 = 0, $25 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0, $259 = 0, $26 = 0, $260 = 0;
 var $261 = 0, $262 = 0, $263 = 0, $264 = 0, $265 = 0, $266 = 0, $267 = 0, $268 = 0, $269 = 0, $27 = 0, $270 = 0, $271 = 0, $272 = 0, $273 = 0, $274 = 0, $275 = 0, $276 = 0, $277 = 0, $278 = 0, $279 = 0;
 var $28 = 0, $280 = 0, $281 = 0, $282 = 0, $283 = 0, $284 = 0, $285 = 0, $286 = 0, $287 = 0, $288 = 0, $289 = 0, $29 = 0, $290 = 0, $291 = 0, $292 = 0, $293 = 0, $294 = 0, $295 = 0, $296 = 0, $297 = 0;
 var $298 = 0, $299 = 0, $3 = 0, $30 = 0, $300 = 0, $301 = 0, $302 = 0, $303 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0;
 var $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0;
 var $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0;
 var $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0;
 var $97 = 0, $98 = 0, $99 = 0, $cond = 0, $cond17 = 0, $not$ = 0, $not$1 = 0, $not$19 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = $0 + $1 | 0;
 $3 = $0 + 4 | 0;
 $4 = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
 $5 = $4 & 1;
 $6 = ($5 | 0) == 0;
 L1 : do {
  if ($6) {
   $7 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
   $8 = $4 & 3;
   $9 = ($8 | 0) == 0;
   if ($9) {
    return;
   }
   $10 = 0 - $7 | 0;
   $11 = $0 + $10 | 0;
   $12 = $7 + $1 | 0;
   $13 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
   $14 = $11 >>> 0 < $13 >>> 0;
   if ($14) {
    _abort();
   }
   $15 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
   $16 = ($11 | 0) == ($15 | 0);
   if ($16) {
    $100 = $2 + 4 | 0;
    $101 = SAFE_HEAP_LOAD($100 | 0, 4, 0) | 0 | 0;
    $102 = $101 & 3;
    $103 = ($102 | 0) == 3;
    if (!$103) {
     $$1 = $11;
     $$1418 = $12;
     break;
    }
    $104 = $11 + $12 | 0;
    $105 = $11 + 4 | 0;
    $106 = $12 | 1;
    $107 = $101 & -2;
    SAFE_HEAP_STORE(3080 | 0, $12 | 0, 4);
    SAFE_HEAP_STORE($100 | 0, $107 | 0, 4);
    SAFE_HEAP_STORE($105 | 0, $106 | 0, 4);
    SAFE_HEAP_STORE($104 | 0, $12 | 0, 4);
    return;
   }
   $17 = $7 >>> 3;
   $18 = $7 >>> 0 < 256;
   if ($18) {
    $19 = $11 + 8 | 0;
    $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
    $21 = $11 + 12 | 0;
    $22 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
    $23 = $17 << 1;
    $24 = 3112 + ($23 << 2) | 0;
    $25 = ($20 | 0) == ($24 | 0);
    if (!$25) {
     $26 = $20 >>> 0 < $13 >>> 0;
     if ($26) {
      _abort();
     }
     $27 = $20 + 12 | 0;
     $28 = SAFE_HEAP_LOAD($27 | 0, 4, 0) | 0 | 0;
     $29 = ($28 | 0) == ($11 | 0);
     if (!$29) {
      _abort();
     }
    }
    $30 = ($22 | 0) == ($20 | 0);
    if ($30) {
     $31 = 1 << $17;
     $32 = $31 ^ -1;
     $33 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
     $34 = $33 & $32;
     SAFE_HEAP_STORE(768 * 4 | 0, $34 | 0, 4);
     $$1 = $11;
     $$1418 = $12;
     break;
    }
    $35 = ($22 | 0) == ($24 | 0);
    if ($35) {
     $$pre25 = $22 + 8 | 0;
     $$pre$phi26Z2D = $$pre25;
    } else {
     $36 = $22 >>> 0 < $13 >>> 0;
     if ($36) {
      _abort();
     }
     $37 = $22 + 8 | 0;
     $38 = SAFE_HEAP_LOAD($37 | 0, 4, 0) | 0 | 0;
     $39 = ($38 | 0) == ($11 | 0);
     if ($39) {
      $$pre$phi26Z2D = $37;
     } else {
      _abort();
     }
    }
    $40 = $20 + 12 | 0;
    SAFE_HEAP_STORE($40 | 0, $22 | 0, 4);
    SAFE_HEAP_STORE($$pre$phi26Z2D | 0, $20 | 0, 4);
    $$1 = $11;
    $$1418 = $12;
    break;
   }
   $41 = $11 + 24 | 0;
   $42 = SAFE_HEAP_LOAD($41 | 0, 4, 0) | 0 | 0;
   $43 = $11 + 12 | 0;
   $44 = SAFE_HEAP_LOAD($43 | 0, 4, 0) | 0 | 0;
   $45 = ($44 | 0) == ($11 | 0);
   do {
    if ($45) {
     $55 = $11 + 16 | 0;
     $56 = $55 + 4 | 0;
     $57 = SAFE_HEAP_LOAD($56 | 0, 4, 0) | 0 | 0;
     $58 = ($57 | 0) == (0 | 0);
     if ($58) {
      $59 = SAFE_HEAP_LOAD($55 | 0, 4, 0) | 0 | 0;
      $60 = ($59 | 0) == (0 | 0);
      if ($60) {
       $$3 = 0;
       break;
      } else {
       $$1426 = $59;
       $$1429 = $55;
      }
     } else {
      $$1426 = $57;
      $$1429 = $56;
     }
     while (1) {
      $61 = $$1426 + 20 | 0;
      $62 = SAFE_HEAP_LOAD($61 | 0, 4, 0) | 0 | 0;
      $63 = ($62 | 0) == (0 | 0);
      if (!$63) {
       $$1426 = $62;
       $$1429 = $61;
       continue;
      }
      $64 = $$1426 + 16 | 0;
      $65 = SAFE_HEAP_LOAD($64 | 0, 4, 0) | 0 | 0;
      $66 = ($65 | 0) == (0 | 0);
      if ($66) {
       break;
      } else {
       $$1426 = $65;
       $$1429 = $64;
      }
     }
     $67 = $$1429 >>> 0 < $13 >>> 0;
     if ($67) {
      _abort();
     } else {
      SAFE_HEAP_STORE($$1429 | 0, 0 | 0, 4);
      $$3 = $$1426;
      break;
     }
    } else {
     $46 = $11 + 8 | 0;
     $47 = SAFE_HEAP_LOAD($46 | 0, 4, 0) | 0 | 0;
     $48 = $47 >>> 0 < $13 >>> 0;
     if ($48) {
      _abort();
     }
     $49 = $47 + 12 | 0;
     $50 = SAFE_HEAP_LOAD($49 | 0, 4, 0) | 0 | 0;
     $51 = ($50 | 0) == ($11 | 0);
     if (!$51) {
      _abort();
     }
     $52 = $44 + 8 | 0;
     $53 = SAFE_HEAP_LOAD($52 | 0, 4, 0) | 0 | 0;
     $54 = ($53 | 0) == ($11 | 0);
     if ($54) {
      SAFE_HEAP_STORE($49 | 0, $44 | 0, 4);
      SAFE_HEAP_STORE($52 | 0, $47 | 0, 4);
      $$3 = $44;
      break;
     } else {
      _abort();
     }
    }
   } while (0);
   $68 = ($42 | 0) == (0 | 0);
   if ($68) {
    $$1 = $11;
    $$1418 = $12;
   } else {
    $69 = $11 + 28 | 0;
    $70 = SAFE_HEAP_LOAD($69 | 0, 4, 0) | 0 | 0;
    $71 = 3376 + ($70 << 2) | 0;
    $72 = SAFE_HEAP_LOAD($71 | 0, 4, 0) | 0 | 0;
    $73 = ($11 | 0) == ($72 | 0);
    do {
     if ($73) {
      SAFE_HEAP_STORE($71 | 0, $$3 | 0, 4);
      $cond = ($$3 | 0) == (0 | 0);
      if ($cond) {
       $74 = 1 << $70;
       $75 = $74 ^ -1;
       $76 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
       $77 = $76 & $75;
       SAFE_HEAP_STORE(3076 | 0, $77 | 0, 4);
       $$1 = $11;
       $$1418 = $12;
       break L1;
      }
     } else {
      $78 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $79 = $42 >>> 0 < $78 >>> 0;
      if ($79) {
       _abort();
      } else {
       $80 = $42 + 16 | 0;
       $81 = SAFE_HEAP_LOAD($80 | 0, 4, 0) | 0 | 0;
       $not$1 = ($81 | 0) != ($11 | 0);
       $$sink2 = $not$1 & 1;
       $82 = ($42 + 16 | 0) + ($$sink2 << 2) | 0;
       SAFE_HEAP_STORE($82 | 0, $$3 | 0, 4);
       $83 = ($$3 | 0) == (0 | 0);
       if ($83) {
        $$1 = $11;
        $$1418 = $12;
        break L1;
       } else {
        break;
       }
      }
     }
    } while (0);
    $84 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
    $85 = $$3 >>> 0 < $84 >>> 0;
    if ($85) {
     _abort();
    }
    $86 = $$3 + 24 | 0;
    SAFE_HEAP_STORE($86 | 0, $42 | 0, 4);
    $87 = $11 + 16 | 0;
    $88 = SAFE_HEAP_LOAD($87 | 0, 4, 0) | 0 | 0;
    $89 = ($88 | 0) == (0 | 0);
    do {
     if (!$89) {
      $90 = $88 >>> 0 < $84 >>> 0;
      if ($90) {
       _abort();
      } else {
       $91 = $$3 + 16 | 0;
       SAFE_HEAP_STORE($91 | 0, $88 | 0, 4);
       $92 = $88 + 24 | 0;
       SAFE_HEAP_STORE($92 | 0, $$3 | 0, 4);
       break;
      }
     }
    } while (0);
    $93 = $87 + 4 | 0;
    $94 = SAFE_HEAP_LOAD($93 | 0, 4, 0) | 0 | 0;
    $95 = ($94 | 0) == (0 | 0);
    if ($95) {
     $$1 = $11;
     $$1418 = $12;
    } else {
     $96 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $97 = $94 >>> 0 < $96 >>> 0;
     if ($97) {
      _abort();
     } else {
      $98 = $$3 + 20 | 0;
      SAFE_HEAP_STORE($98 | 0, $94 | 0, 4);
      $99 = $94 + 24 | 0;
      SAFE_HEAP_STORE($99 | 0, $$3 | 0, 4);
      $$1 = $11;
      $$1418 = $12;
      break;
     }
    }
   }
  } else {
   $$1 = $0;
   $$1418 = $1;
  }
 } while (0);
 $108 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
 $109 = $2 >>> 0 < $108 >>> 0;
 if ($109) {
  _abort();
 }
 $110 = $2 + 4 | 0;
 $111 = SAFE_HEAP_LOAD($110 | 0, 4, 0) | 0 | 0;
 $112 = $111 & 2;
 $113 = ($112 | 0) == 0;
 if ($113) {
  $114 = SAFE_HEAP_LOAD(3096 | 0, 4, 0) | 0 | 0;
  $115 = ($2 | 0) == ($114 | 0);
  $116 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
  if ($115) {
   $117 = SAFE_HEAP_LOAD(3084 | 0, 4, 0) | 0 | 0;
   $118 = $117 + $$1418 | 0;
   SAFE_HEAP_STORE(3084 | 0, $118 | 0, 4);
   SAFE_HEAP_STORE(3096 | 0, $$1 | 0, 4);
   $119 = $118 | 1;
   $120 = $$1 + 4 | 0;
   SAFE_HEAP_STORE($120 | 0, $119 | 0, 4);
   $121 = ($$1 | 0) == ($116 | 0);
   if (!$121) {
    return;
   }
   SAFE_HEAP_STORE(3092 | 0, 0 | 0, 4);
   SAFE_HEAP_STORE(3080 | 0, 0 | 0, 4);
   return;
  }
  $122 = ($2 | 0) == ($116 | 0);
  if ($122) {
   $123 = SAFE_HEAP_LOAD(3080 | 0, 4, 0) | 0 | 0;
   $124 = $123 + $$1418 | 0;
   SAFE_HEAP_STORE(3080 | 0, $124 | 0, 4);
   SAFE_HEAP_STORE(3092 | 0, $$1 | 0, 4);
   $125 = $124 | 1;
   $126 = $$1 + 4 | 0;
   SAFE_HEAP_STORE($126 | 0, $125 | 0, 4);
   $127 = $$1 + $124 | 0;
   SAFE_HEAP_STORE($127 | 0, $124 | 0, 4);
   return;
  }
  $128 = $111 & -8;
  $129 = $128 + $$1418 | 0;
  $130 = $111 >>> 3;
  $131 = $111 >>> 0 < 256;
  L96 : do {
   if ($131) {
    $132 = $2 + 8 | 0;
    $133 = SAFE_HEAP_LOAD($132 | 0, 4, 0) | 0 | 0;
    $134 = $2 + 12 | 0;
    $135 = SAFE_HEAP_LOAD($134 | 0, 4, 0) | 0 | 0;
    $136 = $130 << 1;
    $137 = 3112 + ($136 << 2) | 0;
    $138 = ($133 | 0) == ($137 | 0);
    if (!$138) {
     $139 = $133 >>> 0 < $108 >>> 0;
     if ($139) {
      _abort();
     }
     $140 = $133 + 12 | 0;
     $141 = SAFE_HEAP_LOAD($140 | 0, 4, 0) | 0 | 0;
     $142 = ($141 | 0) == ($2 | 0);
     if (!$142) {
      _abort();
     }
    }
    $143 = ($135 | 0) == ($133 | 0);
    if ($143) {
     $144 = 1 << $130;
     $145 = $144 ^ -1;
     $146 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
     $147 = $146 & $145;
     SAFE_HEAP_STORE(768 * 4 | 0, $147 | 0, 4);
     break;
    }
    $148 = ($135 | 0) == ($137 | 0);
    if ($148) {
     $$pre23 = $135 + 8 | 0;
     $$pre$phi24Z2D = $$pre23;
    } else {
     $149 = $135 >>> 0 < $108 >>> 0;
     if ($149) {
      _abort();
     }
     $150 = $135 + 8 | 0;
     $151 = SAFE_HEAP_LOAD($150 | 0, 4, 0) | 0 | 0;
     $152 = ($151 | 0) == ($2 | 0);
     if ($152) {
      $$pre$phi24Z2D = $150;
     } else {
      _abort();
     }
    }
    $153 = $133 + 12 | 0;
    SAFE_HEAP_STORE($153 | 0, $135 | 0, 4);
    SAFE_HEAP_STORE($$pre$phi24Z2D | 0, $133 | 0, 4);
   } else {
    $154 = $2 + 24 | 0;
    $155 = SAFE_HEAP_LOAD($154 | 0, 4, 0) | 0 | 0;
    $156 = $2 + 12 | 0;
    $157 = SAFE_HEAP_LOAD($156 | 0, 4, 0) | 0 | 0;
    $158 = ($157 | 0) == ($2 | 0);
    do {
     if ($158) {
      $168 = $2 + 16 | 0;
      $169 = $168 + 4 | 0;
      $170 = SAFE_HEAP_LOAD($169 | 0, 4, 0) | 0 | 0;
      $171 = ($170 | 0) == (0 | 0);
      if ($171) {
       $172 = SAFE_HEAP_LOAD($168 | 0, 4, 0) | 0 | 0;
       $173 = ($172 | 0) == (0 | 0);
       if ($173) {
        $$3435 = 0;
        break;
       } else {
        $$1433 = $172;
        $$1437 = $168;
       }
      } else {
       $$1433 = $170;
       $$1437 = $169;
      }
      while (1) {
       $174 = $$1433 + 20 | 0;
       $175 = SAFE_HEAP_LOAD($174 | 0, 4, 0) | 0 | 0;
       $176 = ($175 | 0) == (0 | 0);
       if (!$176) {
        $$1433 = $175;
        $$1437 = $174;
        continue;
       }
       $177 = $$1433 + 16 | 0;
       $178 = SAFE_HEAP_LOAD($177 | 0, 4, 0) | 0 | 0;
       $179 = ($178 | 0) == (0 | 0);
       if ($179) {
        break;
       } else {
        $$1433 = $178;
        $$1437 = $177;
       }
      }
      $180 = $$1437 >>> 0 < $108 >>> 0;
      if ($180) {
       _abort();
      } else {
       SAFE_HEAP_STORE($$1437 | 0, 0 | 0, 4);
       $$3435 = $$1433;
       break;
      }
     } else {
      $159 = $2 + 8 | 0;
      $160 = SAFE_HEAP_LOAD($159 | 0, 4, 0) | 0 | 0;
      $161 = $160 >>> 0 < $108 >>> 0;
      if ($161) {
       _abort();
      }
      $162 = $160 + 12 | 0;
      $163 = SAFE_HEAP_LOAD($162 | 0, 4, 0) | 0 | 0;
      $164 = ($163 | 0) == ($2 | 0);
      if (!$164) {
       _abort();
      }
      $165 = $157 + 8 | 0;
      $166 = SAFE_HEAP_LOAD($165 | 0, 4, 0) | 0 | 0;
      $167 = ($166 | 0) == ($2 | 0);
      if ($167) {
       SAFE_HEAP_STORE($162 | 0, $157 | 0, 4);
       SAFE_HEAP_STORE($165 | 0, $160 | 0, 4);
       $$3435 = $157;
       break;
      } else {
       _abort();
      }
     }
    } while (0);
    $181 = ($155 | 0) == (0 | 0);
    if (!$181) {
     $182 = $2 + 28 | 0;
     $183 = SAFE_HEAP_LOAD($182 | 0, 4, 0) | 0 | 0;
     $184 = 3376 + ($183 << 2) | 0;
     $185 = SAFE_HEAP_LOAD($184 | 0, 4, 0) | 0 | 0;
     $186 = ($2 | 0) == ($185 | 0);
     do {
      if ($186) {
       SAFE_HEAP_STORE($184 | 0, $$3435 | 0, 4);
       $cond17 = ($$3435 | 0) == (0 | 0);
       if ($cond17) {
        $187 = 1 << $183;
        $188 = $187 ^ -1;
        $189 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
        $190 = $189 & $188;
        SAFE_HEAP_STORE(3076 | 0, $190 | 0, 4);
        break L96;
       }
      } else {
       $191 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
       $192 = $155 >>> 0 < $191 >>> 0;
       if ($192) {
        _abort();
       } else {
        $193 = $155 + 16 | 0;
        $194 = SAFE_HEAP_LOAD($193 | 0, 4, 0) | 0 | 0;
        $not$ = ($194 | 0) != ($2 | 0);
        $$sink4 = $not$ & 1;
        $195 = ($155 + 16 | 0) + ($$sink4 << 2) | 0;
        SAFE_HEAP_STORE($195 | 0, $$3435 | 0, 4);
        $196 = ($$3435 | 0) == (0 | 0);
        if ($196) {
         break L96;
        } else {
         break;
        }
       }
      }
     } while (0);
     $197 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $198 = $$3435 >>> 0 < $197 >>> 0;
     if ($198) {
      _abort();
     }
     $199 = $$3435 + 24 | 0;
     SAFE_HEAP_STORE($199 | 0, $155 | 0, 4);
     $200 = $2 + 16 | 0;
     $201 = SAFE_HEAP_LOAD($200 | 0, 4, 0) | 0 | 0;
     $202 = ($201 | 0) == (0 | 0);
     do {
      if (!$202) {
       $203 = $201 >>> 0 < $197 >>> 0;
       if ($203) {
        _abort();
       } else {
        $204 = $$3435 + 16 | 0;
        SAFE_HEAP_STORE($204 | 0, $201 | 0, 4);
        $205 = $201 + 24 | 0;
        SAFE_HEAP_STORE($205 | 0, $$3435 | 0, 4);
        break;
       }
      }
     } while (0);
     $206 = $200 + 4 | 0;
     $207 = SAFE_HEAP_LOAD($206 | 0, 4, 0) | 0 | 0;
     $208 = ($207 | 0) == (0 | 0);
     if (!$208) {
      $209 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $210 = $207 >>> 0 < $209 >>> 0;
      if ($210) {
       _abort();
      } else {
       $211 = $$3435 + 20 | 0;
       SAFE_HEAP_STORE($211 | 0, $207 | 0, 4);
       $212 = $207 + 24 | 0;
       SAFE_HEAP_STORE($212 | 0, $$3435 | 0, 4);
       break;
      }
     }
    }
   }
  } while (0);
  $213 = $129 | 1;
  $214 = $$1 + 4 | 0;
  SAFE_HEAP_STORE($214 | 0, $213 | 0, 4);
  $215 = $$1 + $129 | 0;
  SAFE_HEAP_STORE($215 | 0, $129 | 0, 4);
  $216 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
  $217 = ($$1 | 0) == ($216 | 0);
  if ($217) {
   SAFE_HEAP_STORE(3080 | 0, $129 | 0, 4);
   return;
  } else {
   $$2 = $129;
  }
 } else {
  $218 = $111 & -2;
  SAFE_HEAP_STORE($110 | 0, $218 | 0, 4);
  $219 = $$1418 | 1;
  $220 = $$1 + 4 | 0;
  SAFE_HEAP_STORE($220 | 0, $219 | 0, 4);
  $221 = $$1 + $$1418 | 0;
  SAFE_HEAP_STORE($221 | 0, $$1418 | 0, 4);
  $$2 = $$1418;
 }
 $222 = $$2 >>> 3;
 $223 = $$2 >>> 0 < 256;
 if ($223) {
  $224 = $222 << 1;
  $225 = 3112 + ($224 << 2) | 0;
  $226 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
  $227 = 1 << $222;
  $228 = $226 & $227;
  $229 = ($228 | 0) == 0;
  if ($229) {
   $230 = $226 | $227;
   SAFE_HEAP_STORE(768 * 4 | 0, $230 | 0, 4);
   $$pre = $225 + 8 | 0;
   $$0438 = $225;
   $$pre$phiZ2D = $$pre;
  } else {
   $231 = $225 + 8 | 0;
   $232 = SAFE_HEAP_LOAD($231 | 0, 4, 0) | 0 | 0;
   $233 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
   $234 = $232 >>> 0 < $233 >>> 0;
   if ($234) {
    _abort();
   } else {
    $$0438 = $232;
    $$pre$phiZ2D = $231;
   }
  }
  SAFE_HEAP_STORE($$pre$phiZ2D | 0, $$1 | 0, 4);
  $235 = $$0438 + 12 | 0;
  SAFE_HEAP_STORE($235 | 0, $$1 | 0, 4);
  $236 = $$1 + 8 | 0;
  SAFE_HEAP_STORE($236 | 0, $$0438 | 0, 4);
  $237 = $$1 + 12 | 0;
  SAFE_HEAP_STORE($237 | 0, $225 | 0, 4);
  return;
 }
 $238 = $$2 >>> 8;
 $239 = ($238 | 0) == 0;
 if ($239) {
  $$0431 = 0;
 } else {
  $240 = $$2 >>> 0 > 16777215;
  if ($240) {
   $$0431 = 31;
  } else {
   $241 = $238 + 1048320 | 0;
   $242 = $241 >>> 16;
   $243 = $242 & 8;
   $244 = $238 << $243;
   $245 = $244 + 520192 | 0;
   $246 = $245 >>> 16;
   $247 = $246 & 4;
   $248 = $247 | $243;
   $249 = $244 << $247;
   $250 = $249 + 245760 | 0;
   $251 = $250 >>> 16;
   $252 = $251 & 2;
   $253 = $248 | $252;
   $254 = 14 - $253 | 0;
   $255 = $249 << $252;
   $256 = $255 >>> 15;
   $257 = $254 + $256 | 0;
   $258 = $257 << 1;
   $259 = $257 + 7 | 0;
   $260 = $$2 >>> $259;
   $261 = $260 & 1;
   $262 = $261 | $258;
   $$0431 = $262;
  }
 }
 $263 = 3376 + ($$0431 << 2) | 0;
 $264 = $$1 + 28 | 0;
 SAFE_HEAP_STORE($264 | 0, $$0431 | 0, 4);
 $265 = $$1 + 16 | 0;
 $266 = $$1 + 20 | 0;
 SAFE_HEAP_STORE($266 | 0, 0 | 0, 4);
 SAFE_HEAP_STORE($265 | 0, 0 | 0, 4);
 $267 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
 $268 = 1 << $$0431;
 $269 = $267 & $268;
 $270 = ($269 | 0) == 0;
 if ($270) {
  $271 = $267 | $268;
  SAFE_HEAP_STORE(3076 | 0, $271 | 0, 4);
  SAFE_HEAP_STORE($263 | 0, $$1 | 0, 4);
  $272 = $$1 + 24 | 0;
  SAFE_HEAP_STORE($272 | 0, $263 | 0, 4);
  $273 = $$1 + 12 | 0;
  SAFE_HEAP_STORE($273 | 0, $$1 | 0, 4);
  $274 = $$1 + 8 | 0;
  SAFE_HEAP_STORE($274 | 0, $$1 | 0, 4);
  return;
 }
 $275 = SAFE_HEAP_LOAD($263 | 0, 4, 0) | 0 | 0;
 $276 = ($$0431 | 0) == 31;
 $277 = $$0431 >>> 1;
 $278 = 25 - $277 | 0;
 $279 = $276 ? 0 : $278;
 $280 = $$2 << $279;
 $$0419 = $280;
 $$0420 = $275;
 while (1) {
  $281 = $$0420 + 4 | 0;
  $282 = SAFE_HEAP_LOAD($281 | 0, 4, 0) | 0 | 0;
  $283 = $282 & -8;
  $284 = ($283 | 0) == ($$2 | 0);
  if ($284) {
   label = 121;
   break;
  }
  $285 = $$0419 >>> 31;
  $286 = ($$0420 + 16 | 0) + ($285 << 2) | 0;
  $287 = $$0419 << 1;
  $288 = SAFE_HEAP_LOAD($286 | 0, 4, 0) | 0 | 0;
  $289 = ($288 | 0) == (0 | 0);
  if ($289) {
   label = 118;
   break;
  } else {
   $$0419 = $287;
   $$0420 = $288;
  }
 }
 if ((label | 0) == 118) {
  $290 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
  $291 = $286 >>> 0 < $290 >>> 0;
  if ($291) {
   _abort();
  }
  SAFE_HEAP_STORE($286 | 0, $$1 | 0, 4);
  $292 = $$1 + 24 | 0;
  SAFE_HEAP_STORE($292 | 0, $$0420 | 0, 4);
  $293 = $$1 + 12 | 0;
  SAFE_HEAP_STORE($293 | 0, $$1 | 0, 4);
  $294 = $$1 + 8 | 0;
  SAFE_HEAP_STORE($294 | 0, $$1 | 0, 4);
  return;
 } else if ((label | 0) == 121) {
  $295 = $$0420 + 8 | 0;
  $296 = SAFE_HEAP_LOAD($295 | 0, 4, 0) | 0 | 0;
  $297 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
  $298 = $296 >>> 0 >= $297 >>> 0;
  $not$19 = $$0420 >>> 0 >= $297 >>> 0;
  $299 = $298 & $not$19;
  if (!$299) {
   _abort();
  }
  $300 = $296 + 12 | 0;
  SAFE_HEAP_STORE($300 | 0, $$1 | 0, 4);
  SAFE_HEAP_STORE($295 | 0, $$1 | 0, 4);
  $301 = $$1 + 8 | 0;
  SAFE_HEAP_STORE($301 | 0, $296 | 0, 4);
  $302 = $$1 + 12 | 0;
  SAFE_HEAP_STORE($302 | 0, $$0420 | 0, 4);
  $303 = $$1 + 24 | 0;
  SAFE_HEAP_STORE($303 | 0, 0 | 0, 4);
  return;
 }
}

function _sjf_element_update($0) {
 $0 = $0 | 0;
 var $1 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0;
 var $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0;
 var $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0;
 var $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0;
 var $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0, $176 = 0, $177 = 0, $178 = 0, $179 = 0, $18 = 0, $180 = 0, $181 = 0, $182 = 0, $183 = 0, $184 = 0, $185 = 0, $186 = 0, $187 = 0, $188 = 0, $189 = 0;
 var $19 = 0, $190 = 0, $191 = 0, $192 = 0, $193 = 0, $194 = 0, $195 = 0, $196 = 0, $197 = 0, $198 = 0, $199 = 0, $2 = 0, $20 = 0, $200 = 0, $201 = 0, $202 = 0, $203 = 0, $204 = 0, $205 = 0, $206 = 0;
 var $207 = 0, $208 = 0, $209 = 0, $21 = 0, $210 = 0, $211 = 0, $212 = 0, $213 = 0, $214 = 0, $215 = 0, $216 = 0, $217 = 0, $218 = 0, $219 = 0, $22 = 0, $220 = 0, $221 = 0, $222 = 0, $223 = 0, $224 = 0;
 var $225 = 0, $226 = 0, $227 = 0, $228 = 0, $229 = 0, $23 = 0, $230 = 0, $231 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0;
 var $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0;
 var $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0;
 var $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0;
 var $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 96 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(96 | 0);
 $9 = sp + 56 | 0;
 $10 = sp + 52 | 0;
 $11 = sp + 48 | 0;
 $12 = sp + 44 | 0;
 $13 = sp + 40 | 0;
 $14 = sp + 36 | 0;
 $20 = sp + 12 | 0;
 $21 = sp + 8 | 0;
 $22 = sp + 4 | 0;
 $1 = $0;
 $24 = $1;
 $25 = $24 + 4 | 0;
 $26 = SAFE_HEAP_LOAD($25 | 0, 4, 0) | 0 | 0;
 $15 = $26;
 $27 = $15;
 $28 = $27 + 8 | 0;
 $29 = SAFE_HEAP_LOAD($28 | 0, 4, 0) | 0 | 0;
 $2 = $29;
 $30 = _malloc(16) | 0;
 SAFE_HEAP_STORE($9 | 0, $30 | 0, 4);
 $31 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($31 | 0, 1 | 0, 4);
 $32 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $33 = $32 + 4 | 0;
 SAFE_HEAP_STORE($33 | 0, 11 | 0, 4);
 $34 = SAFE_HEAP_LOAD(4 * 4 | 0, 4, 0) | 0 | 0;
 $35 = $34;
 $36 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $37 = $36 + 8 | 0;
 SAFE_HEAP_STORE($37 | 0, $35 | 0, 4);
 $38 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $39 = $38 + 12 | 0;
 SAFE_HEAP_STORE($39 >> 0 | 0, 0 | 0, 1);
 $40 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 _sjf_array_char($40, $9);
 $41 = _malloc(16) | 0;
 SAFE_HEAP_STORE($10 | 0, $41 | 0, 4);
 $42 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($42 | 0, 1 | 0, 4);
 $43 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $44 = $43 + 8 | 0;
 SAFE_HEAP_STORE($44 | 0, 10 | 0, 4);
 $45 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $46 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $47 = $46 + 12 | 0;
 SAFE_HEAP_STORE($47 | 0, $45 | 0, 4);
 $48 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $49 = $48 + 12 | 0;
 $50 = SAFE_HEAP_LOAD($49 | 0, 4, 0) | 0 | 0;
 $51 = SAFE_HEAP_LOAD($50 | 0, 4, 0) | 0 | 0;
 $52 = $51 + 1 | 0;
 SAFE_HEAP_STORE($50 | 0, $52 | 0, 4);
 $53 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 _sjf_string($53, $10);
 $54 = $2;
 $55 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 _sjf_anon1_write($54, $55);
 $56 = _malloc(16) | 0;
 SAFE_HEAP_STORE($11 | 0, $56 | 0, 4);
 $57 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($57 | 0, 1 | 0, 4);
 $58 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $59 = $58 + 4 | 0;
 SAFE_HEAP_STORE($59 | 0, 1 | 0, 4);
 $60 = SAFE_HEAP_LOAD(5 * 4 | 0, 4, 0) | 0 | 0;
 $61 = $60;
 $62 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $63 = $62 + 8 | 0;
 SAFE_HEAP_STORE($63 | 0, $61 | 0, 4);
 $64 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $65 = $64 + 12 | 0;
 SAFE_HEAP_STORE($65 >> 0 | 0, 0 | 0, 1);
 $66 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 _sjf_array_char($66, $11);
 $67 = _malloc(16) | 0;
 SAFE_HEAP_STORE($12 | 0, $67 | 0, 4);
 $68 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($68 | 0, 1 | 0, 4);
 $69 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 $70 = $69 + 8 | 0;
 SAFE_HEAP_STORE($70 | 0, 0 | 0, 4);
 $71 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $72 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 $73 = $72 + 12 | 0;
 SAFE_HEAP_STORE($73 | 0, $71 | 0, 4);
 $74 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 $75 = $74 + 12 | 0;
 $76 = SAFE_HEAP_LOAD($75 | 0, 4, 0) | 0 | 0;
 $77 = SAFE_HEAP_LOAD($76 | 0, 4, 0) | 0 | 0;
 $78 = $77 + 1 | 0;
 SAFE_HEAP_STORE($76 | 0, $78 | 0, 4);
 $79 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 _sjf_string($79, $12);
 $80 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 $6 = $80;
 $81 = $6;
 $82 = SAFE_HEAP_LOAD($81 | 0, 4, 0) | 0 | 0;
 $83 = $82 + 1 | 0;
 SAFE_HEAP_STORE($81 | 0, $83 | 0, 4);
 $7 = 0;
 $84 = $1;
 $85 = $84 + 12 | 0;
 $86 = SAFE_HEAP_LOAD($85 | 0, 4, 0) | 0 | 0;
 $3 = $86;
 $87 = $3;
 $88 = $87 + 4 | 0;
 $89 = SAFE_HEAP_LOAD($88 | 0, 4, 0) | 0 | 0;
 $4 = $89;
 $90 = $4;
 $8 = $90;
 while (1) {
  $91 = $7;
  $92 = $8;
  $93 = ($91 | 0) < ($92 | 0);
  $94 = $1;
  if (!$93) {
   break;
  }
  $95 = $94 + 12 | 0;
  $96 = SAFE_HEAP_LOAD($95 | 0, 4, 0) | 0 | 0;
  $18 = $96;
  SAFE_HEAP_STORE($20 | 0, 0 | 0, 4);
  $97 = $18;
  $98 = $7;
  _sjf_array_sji_element_getAt($97, $98, $20);
  $99 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
  $17 = $99;
  $100 = $17;
  $101 = SAFE_HEAP_LOAD($100 | 0, 4, 0) | 0 | 0;
  $102 = $101 + 1 | 0;
  SAFE_HEAP_STORE($100 | 0, $102 | 0, 4);
  SAFE_HEAP_STORE($21 | 0, 0 | 0, 4);
  SAFE_HEAP_STORE($22 | 0, 0 | 0, 4);
  $103 = $17;
  $104 = $103 + 16 | 0;
  $105 = SAFE_HEAP_LOAD($104 | 0, 4, 0) | 0 | 0;
  $106 = $17;
  $107 = $106 + 4 | 0;
  $108 = SAFE_HEAP_LOAD($107 | 0, 4, 0) | 0 | 0;
  FUNCTION_TABLE_vii[(SAFE_FT_MASK($105 | 0, 7 | 0) | 0) & 7]($108, $22);
  $109 = $6;
  $110 = SAFE_HEAP_LOAD($22 | 0, 4, 0) | 0 | 0;
  _sjf_string_add($109, $110, $21);
  $111 = $1;
  $112 = $111 + 4 | 0;
  $113 = SAFE_HEAP_LOAD($112 | 0, 4, 0) | 0 | 0;
  $23 = $113;
  $114 = $23;
  $115 = $114 + 8 | 0;
  $116 = SAFE_HEAP_LOAD($115 | 0, 4, 0) | 0 | 0;
  $19 = $116;
  $117 = $19;
  $118 = $6;
  _sjf_anon1_write($117, $118);
  $119 = $7;
  $120 = $119 + 1 | 0;
  $7 = $120;
  $121 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
  $122 = SAFE_HEAP_LOAD($121 | 0, 4, 0) | 0 | 0;
  $123 = $122 + -1 | 0;
  SAFE_HEAP_STORE($121 | 0, $123 | 0, 4);
  $124 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
  $125 = SAFE_HEAP_LOAD($124 | 0, 4, 0) | 0 | 0;
  $126 = ($125 | 0) <= 0;
  if ($126) {
   $127 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
   _sji_element_destroy($127);
   $128 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
   _free($128);
  }
  $129 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
  $130 = SAFE_HEAP_LOAD($129 | 0, 4, 0) | 0 | 0;
  $131 = $130 + -1 | 0;
  SAFE_HEAP_STORE($129 | 0, $131 | 0, 4);
  $132 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
  $133 = SAFE_HEAP_LOAD($132 | 0, 4, 0) | 0 | 0;
  $134 = ($133 | 0) <= 0;
  if ($134) {
   $135 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
   _sjf_string_destroy($135);
   $136 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
   _free($136);
  }
  $137 = SAFE_HEAP_LOAD($22 | 0, 4, 0) | 0 | 0;
  $138 = SAFE_HEAP_LOAD($137 | 0, 4, 0) | 0 | 0;
  $139 = $138 + -1 | 0;
  SAFE_HEAP_STORE($137 | 0, $139 | 0, 4);
  $140 = SAFE_HEAP_LOAD($22 | 0, 4, 0) | 0 | 0;
  $141 = SAFE_HEAP_LOAD($140 | 0, 4, 0) | 0 | 0;
  $142 = ($141 | 0) <= 0;
  if (!$142) {
   continue;
  }
  $143 = SAFE_HEAP_LOAD($22 | 0, 4, 0) | 0 | 0;
  _sjf_string_destroy($143);
  $144 = SAFE_HEAP_LOAD($22 | 0, 4, 0) | 0 | 0;
  _free($144);
 }
 $145 = $94 + 4 | 0;
 $146 = SAFE_HEAP_LOAD($145 | 0, 4, 0) | 0 | 0;
 $16 = $146;
 $147 = $16;
 $148 = $147 + 8 | 0;
 $149 = SAFE_HEAP_LOAD($148 | 0, 4, 0) | 0 | 0;
 $5 = $149;
 $150 = _malloc(16) | 0;
 SAFE_HEAP_STORE($13 | 0, $150 | 0, 4);
 $151 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($151 | 0, 1 | 0, 4);
 $152 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $153 = $152 + 4 | 0;
 SAFE_HEAP_STORE($153 | 0, 11 | 0, 4);
 $154 = SAFE_HEAP_LOAD(6 * 4 | 0, 4, 0) | 0 | 0;
 $155 = $154;
 $156 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $157 = $156 + 8 | 0;
 SAFE_HEAP_STORE($157 | 0, $155 | 0, 4);
 $158 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $159 = $158 + 12 | 0;
 SAFE_HEAP_STORE($159 >> 0 | 0, 0 | 0, 1);
 $160 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 _sjf_array_char($160, $13);
 $161 = _malloc(16) | 0;
 SAFE_HEAP_STORE($14 | 0, $161 | 0, 4);
 $162 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($162 | 0, 1 | 0, 4);
 $163 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $164 = $163 + 8 | 0;
 SAFE_HEAP_STORE($164 | 0, 10 | 0, 4);
 $165 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $166 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $167 = $166 + 12 | 0;
 SAFE_HEAP_STORE($167 | 0, $165 | 0, 4);
 $168 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $169 = $168 + 12 | 0;
 $170 = SAFE_HEAP_LOAD($169 | 0, 4, 0) | 0 | 0;
 $171 = SAFE_HEAP_LOAD($170 | 0, 4, 0) | 0 | 0;
 $172 = $171 + 1 | 0;
 SAFE_HEAP_STORE($170 | 0, $172 | 0, 4);
 $173 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 _sjf_string($173, $14);
 $174 = $5;
 $175 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 _sjf_anon1_write($174, $175);
 $176 = $6;
 $177 = SAFE_HEAP_LOAD($176 | 0, 4, 0) | 0 | 0;
 $178 = $177 + -1 | 0;
 SAFE_HEAP_STORE($176 | 0, $178 | 0, 4);
 $179 = $6;
 $180 = SAFE_HEAP_LOAD($179 | 0, 4, 0) | 0 | 0;
 $181 = ($180 | 0) <= 0;
 if ($181) {
  $182 = $6;
  _sjf_string_destroy($182);
  $183 = $6;
  _free($183);
 }
 $184 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $185 = SAFE_HEAP_LOAD($184 | 0, 4, 0) | 0 | 0;
 $186 = $185 + -1 | 0;
 SAFE_HEAP_STORE($184 | 0, $186 | 0, 4);
 $187 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $188 = SAFE_HEAP_LOAD($187 | 0, 4, 0) | 0 | 0;
 $189 = ($188 | 0) <= 0;
 if ($189) {
  $190 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
  _sjf_array_char_destroy($190);
  $191 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
  _free($191);
 }
 $192 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $193 = SAFE_HEAP_LOAD($192 | 0, 4, 0) | 0 | 0;
 $194 = $193 + -1 | 0;
 SAFE_HEAP_STORE($192 | 0, $194 | 0, 4);
 $195 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $196 = SAFE_HEAP_LOAD($195 | 0, 4, 0) | 0 | 0;
 $197 = ($196 | 0) <= 0;
 if ($197) {
  $198 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
  _sjf_string_destroy($198);
  $199 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
  _free($199);
 }
 $200 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $201 = SAFE_HEAP_LOAD($200 | 0, 4, 0) | 0 | 0;
 $202 = $201 + -1 | 0;
 SAFE_HEAP_STORE($200 | 0, $202 | 0, 4);
 $203 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $204 = SAFE_HEAP_LOAD($203 | 0, 4, 0) | 0 | 0;
 $205 = ($204 | 0) <= 0;
 if ($205) {
  $206 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
  _sjf_array_char_destroy($206);
  $207 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
  _free($207);
 }
 $208 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 $209 = SAFE_HEAP_LOAD($208 | 0, 4, 0) | 0 | 0;
 $210 = $209 + -1 | 0;
 SAFE_HEAP_STORE($208 | 0, $210 | 0, 4);
 $211 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
 $212 = SAFE_HEAP_LOAD($211 | 0, 4, 0) | 0 | 0;
 $213 = ($212 | 0) <= 0;
 if ($213) {
  $214 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
  _sjf_string_destroy($214);
  $215 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
  _free($215);
 }
 $216 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $217 = SAFE_HEAP_LOAD($216 | 0, 4, 0) | 0 | 0;
 $218 = $217 + -1 | 0;
 SAFE_HEAP_STORE($216 | 0, $218 | 0, 4);
 $219 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $220 = SAFE_HEAP_LOAD($219 | 0, 4, 0) | 0 | 0;
 $221 = ($220 | 0) <= 0;
 if ($221) {
  $222 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
  _sjf_array_char_destroy($222);
  $223 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
  _free($223);
 }
 $224 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $225 = SAFE_HEAP_LOAD($224 | 0, 4, 0) | 0 | 0;
 $226 = $225 + -1 | 0;
 SAFE_HEAP_STORE($224 | 0, $226 | 0, 4);
 $227 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $228 = SAFE_HEAP_LOAD($227 | 0, 4, 0) | 0 | 0;
 $229 = ($228 | 0) <= 0;
 if (!$229) {
  STACKTOP = sp;
  return;
 }
 $230 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 _sjf_string_destroy($230);
 $231 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 _free($231);
 STACKTOP = sp;
 return;
}

function _try_realloc_chunk($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$1272 = 0, $$1275 = 0, $$2 = 0, $$3 = 0, $$pre = 0, $$pre$phiZ2D = 0, $$sink1 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0;
 var $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0, $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0;
 var $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0;
 var $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $16 = 0, $160 = 0, $161 = 0, $162 = 0, $163 = 0, $164 = 0, $165 = 0;
 var $166 = 0, $167 = 0, $168 = 0, $169 = 0, $17 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0;
 var $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0;
 var $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0;
 var $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0;
 var $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0;
 var $cond = 0, $not$ = 0, $notlhs = 0, $notrhs = 0, $or$cond$not = 0, $or$cond3 = 0, $storemerge = 0, $storemerge1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = $0 + 4 | 0;
 $3 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
 $4 = $3 & -8;
 $5 = $0 + $4 | 0;
 $6 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
 $7 = $3 & 3;
 $notlhs = $0 >>> 0 >= $6 >>> 0;
 $notrhs = ($7 | 0) != 1;
 $or$cond$not = $notrhs & $notlhs;
 $8 = $0 >>> 0 < $5 >>> 0;
 $or$cond3 = $or$cond$not & $8;
 if (!$or$cond3) {
  _abort();
 }
 $9 = $5 + 4 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = $10 & 1;
 $12 = ($11 | 0) == 0;
 if ($12) {
  _abort();
 }
 $13 = ($7 | 0) == 0;
 if ($13) {
  $14 = $1 >>> 0 < 256;
  if ($14) {
   $$2 = 0;
   return $$2 | 0;
  }
  $15 = $1 + 4 | 0;
  $16 = $4 >>> 0 < $15 >>> 0;
  if (!$16) {
   $17 = $4 - $1 | 0;
   $18 = SAFE_HEAP_LOAD(3552 | 0, 4, 0) | 0 | 0;
   $19 = $18 << 1;
   $20 = $17 >>> 0 > $19 >>> 0;
   if (!$20) {
    $$2 = $0;
    return $$2 | 0;
   }
  }
  $$2 = 0;
  return $$2 | 0;
 }
 $21 = $4 >>> 0 < $1 >>> 0;
 if (!$21) {
  $22 = $4 - $1 | 0;
  $23 = $22 >>> 0 > 15;
  if (!$23) {
   $$2 = $0;
   return $$2 | 0;
  }
  $24 = $0 + $1 | 0;
  $25 = $3 & 1;
  $26 = $25 | $1;
  $27 = $26 | 2;
  SAFE_HEAP_STORE($2 | 0, $27 | 0, 4);
  $28 = $24 + 4 | 0;
  $29 = $22 | 3;
  SAFE_HEAP_STORE($28 | 0, $29 | 0, 4);
  $30 = $24 + $22 | 0;
  $31 = $30 + 4 | 0;
  $32 = SAFE_HEAP_LOAD($31 | 0, 4, 0) | 0 | 0;
  $33 = $32 | 1;
  SAFE_HEAP_STORE($31 | 0, $33 | 0, 4);
  _dispose_chunk($24, $22);
  $$2 = $0;
  return $$2 | 0;
 }
 $34 = SAFE_HEAP_LOAD(3096 | 0, 4, 0) | 0 | 0;
 $35 = ($5 | 0) == ($34 | 0);
 if ($35) {
  $36 = SAFE_HEAP_LOAD(3084 | 0, 4, 0) | 0 | 0;
  $37 = $36 + $4 | 0;
  $38 = $37 >>> 0 > $1 >>> 0;
  $39 = $37 - $1 | 0;
  $40 = $0 + $1 | 0;
  if (!$38) {
   $$2 = 0;
   return $$2 | 0;
  }
  $41 = $39 | 1;
  $42 = $40 + 4 | 0;
  $43 = $3 & 1;
  $44 = $43 | $1;
  $45 = $44 | 2;
  SAFE_HEAP_STORE($2 | 0, $45 | 0, 4);
  SAFE_HEAP_STORE($42 | 0, $41 | 0, 4);
  SAFE_HEAP_STORE(3096 | 0, $40 | 0, 4);
  SAFE_HEAP_STORE(3084 | 0, $39 | 0, 4);
  $$2 = $0;
  return $$2 | 0;
 }
 $46 = SAFE_HEAP_LOAD(3092 | 0, 4, 0) | 0 | 0;
 $47 = ($5 | 0) == ($46 | 0);
 if ($47) {
  $48 = SAFE_HEAP_LOAD(3080 | 0, 4, 0) | 0 | 0;
  $49 = $48 + $4 | 0;
  $50 = $49 >>> 0 < $1 >>> 0;
  if ($50) {
   $$2 = 0;
   return $$2 | 0;
  }
  $51 = $49 - $1 | 0;
  $52 = $51 >>> 0 > 15;
  $53 = $3 & 1;
  if ($52) {
   $54 = $0 + $1 | 0;
   $55 = $54 + $51 | 0;
   $56 = $53 | $1;
   $57 = $56 | 2;
   SAFE_HEAP_STORE($2 | 0, $57 | 0, 4);
   $58 = $54 + 4 | 0;
   $59 = $51 | 1;
   SAFE_HEAP_STORE($58 | 0, $59 | 0, 4);
   SAFE_HEAP_STORE($55 | 0, $51 | 0, 4);
   $60 = $55 + 4 | 0;
   $61 = SAFE_HEAP_LOAD($60 | 0, 4, 0) | 0 | 0;
   $62 = $61 & -2;
   SAFE_HEAP_STORE($60 | 0, $62 | 0, 4);
   $storemerge = $54;
   $storemerge1 = $51;
  } else {
   $63 = $53 | $49;
   $64 = $63 | 2;
   SAFE_HEAP_STORE($2 | 0, $64 | 0, 4);
   $65 = $0 + $49 | 0;
   $66 = $65 + 4 | 0;
   $67 = SAFE_HEAP_LOAD($66 | 0, 4, 0) | 0 | 0;
   $68 = $67 | 1;
   SAFE_HEAP_STORE($66 | 0, $68 | 0, 4);
   $storemerge = 0;
   $storemerge1 = 0;
  }
  SAFE_HEAP_STORE(3080 | 0, $storemerge1 | 0, 4);
  SAFE_HEAP_STORE(3092 | 0, $storemerge | 0, 4);
  $$2 = $0;
  return $$2 | 0;
 }
 $69 = $10 & 2;
 $70 = ($69 | 0) == 0;
 if (!$70) {
  $$2 = 0;
  return $$2 | 0;
 }
 $71 = $10 & -8;
 $72 = $71 + $4 | 0;
 $73 = $72 >>> 0 < $1 >>> 0;
 if ($73) {
  $$2 = 0;
  return $$2 | 0;
 }
 $74 = $72 - $1 | 0;
 $75 = $10 >>> 3;
 $76 = $10 >>> 0 < 256;
 L49 : do {
  if ($76) {
   $77 = $5 + 8 | 0;
   $78 = SAFE_HEAP_LOAD($77 | 0, 4, 0) | 0 | 0;
   $79 = $5 + 12 | 0;
   $80 = SAFE_HEAP_LOAD($79 | 0, 4, 0) | 0 | 0;
   $81 = $75 << 1;
   $82 = 3112 + ($81 << 2) | 0;
   $83 = ($78 | 0) == ($82 | 0);
   if (!$83) {
    $84 = $78 >>> 0 < $6 >>> 0;
    if ($84) {
     _abort();
    }
    $85 = $78 + 12 | 0;
    $86 = SAFE_HEAP_LOAD($85 | 0, 4, 0) | 0 | 0;
    $87 = ($86 | 0) == ($5 | 0);
    if (!$87) {
     _abort();
    }
   }
   $88 = ($80 | 0) == ($78 | 0);
   if ($88) {
    $89 = 1 << $75;
    $90 = $89 ^ -1;
    $91 = SAFE_HEAP_LOAD(768 * 4 | 0, 4, 0) | 0 | 0;
    $92 = $91 & $90;
    SAFE_HEAP_STORE(768 * 4 | 0, $92 | 0, 4);
    break;
   }
   $93 = ($80 | 0) == ($82 | 0);
   if ($93) {
    $$pre = $80 + 8 | 0;
    $$pre$phiZ2D = $$pre;
   } else {
    $94 = $80 >>> 0 < $6 >>> 0;
    if ($94) {
     _abort();
    }
    $95 = $80 + 8 | 0;
    $96 = SAFE_HEAP_LOAD($95 | 0, 4, 0) | 0 | 0;
    $97 = ($96 | 0) == ($5 | 0);
    if ($97) {
     $$pre$phiZ2D = $95;
    } else {
     _abort();
    }
   }
   $98 = $78 + 12 | 0;
   SAFE_HEAP_STORE($98 | 0, $80 | 0, 4);
   SAFE_HEAP_STORE($$pre$phiZ2D | 0, $78 | 0, 4);
  } else {
   $99 = $5 + 24 | 0;
   $100 = SAFE_HEAP_LOAD($99 | 0, 4, 0) | 0 | 0;
   $101 = $5 + 12 | 0;
   $102 = SAFE_HEAP_LOAD($101 | 0, 4, 0) | 0 | 0;
   $103 = ($102 | 0) == ($5 | 0);
   do {
    if ($103) {
     $113 = $5 + 16 | 0;
     $114 = $113 + 4 | 0;
     $115 = SAFE_HEAP_LOAD($114 | 0, 4, 0) | 0 | 0;
     $116 = ($115 | 0) == (0 | 0);
     if ($116) {
      $117 = SAFE_HEAP_LOAD($113 | 0, 4, 0) | 0 | 0;
      $118 = ($117 | 0) == (0 | 0);
      if ($118) {
       $$3 = 0;
       break;
      } else {
       $$1272 = $117;
       $$1275 = $113;
      }
     } else {
      $$1272 = $115;
      $$1275 = $114;
     }
     while (1) {
      $119 = $$1272 + 20 | 0;
      $120 = SAFE_HEAP_LOAD($119 | 0, 4, 0) | 0 | 0;
      $121 = ($120 | 0) == (0 | 0);
      if (!$121) {
       $$1272 = $120;
       $$1275 = $119;
       continue;
      }
      $122 = $$1272 + 16 | 0;
      $123 = SAFE_HEAP_LOAD($122 | 0, 4, 0) | 0 | 0;
      $124 = ($123 | 0) == (0 | 0);
      if ($124) {
       break;
      } else {
       $$1272 = $123;
       $$1275 = $122;
      }
     }
     $125 = $$1275 >>> 0 < $6 >>> 0;
     if ($125) {
      _abort();
     } else {
      SAFE_HEAP_STORE($$1275 | 0, 0 | 0, 4);
      $$3 = $$1272;
      break;
     }
    } else {
     $104 = $5 + 8 | 0;
     $105 = SAFE_HEAP_LOAD($104 | 0, 4, 0) | 0 | 0;
     $106 = $105 >>> 0 < $6 >>> 0;
     if ($106) {
      _abort();
     }
     $107 = $105 + 12 | 0;
     $108 = SAFE_HEAP_LOAD($107 | 0, 4, 0) | 0 | 0;
     $109 = ($108 | 0) == ($5 | 0);
     if (!$109) {
      _abort();
     }
     $110 = $102 + 8 | 0;
     $111 = SAFE_HEAP_LOAD($110 | 0, 4, 0) | 0 | 0;
     $112 = ($111 | 0) == ($5 | 0);
     if ($112) {
      SAFE_HEAP_STORE($107 | 0, $102 | 0, 4);
      SAFE_HEAP_STORE($110 | 0, $105 | 0, 4);
      $$3 = $102;
      break;
     } else {
      _abort();
     }
    }
   } while (0);
   $126 = ($100 | 0) == (0 | 0);
   if (!$126) {
    $127 = $5 + 28 | 0;
    $128 = SAFE_HEAP_LOAD($127 | 0, 4, 0) | 0 | 0;
    $129 = 3376 + ($128 << 2) | 0;
    $130 = SAFE_HEAP_LOAD($129 | 0, 4, 0) | 0 | 0;
    $131 = ($5 | 0) == ($130 | 0);
    do {
     if ($131) {
      SAFE_HEAP_STORE($129 | 0, $$3 | 0, 4);
      $cond = ($$3 | 0) == (0 | 0);
      if ($cond) {
       $132 = 1 << $128;
       $133 = $132 ^ -1;
       $134 = SAFE_HEAP_LOAD(3076 | 0, 4, 0) | 0 | 0;
       $135 = $134 & $133;
       SAFE_HEAP_STORE(3076 | 0, $135 | 0, 4);
       break L49;
      }
     } else {
      $136 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
      $137 = $100 >>> 0 < $136 >>> 0;
      if ($137) {
       _abort();
      } else {
       $138 = $100 + 16 | 0;
       $139 = SAFE_HEAP_LOAD($138 | 0, 4, 0) | 0 | 0;
       $not$ = ($139 | 0) != ($5 | 0);
       $$sink1 = $not$ & 1;
       $140 = ($100 + 16 | 0) + ($$sink1 << 2) | 0;
       SAFE_HEAP_STORE($140 | 0, $$3 | 0, 4);
       $141 = ($$3 | 0) == (0 | 0);
       if ($141) {
        break L49;
       } else {
        break;
       }
      }
     }
    } while (0);
    $142 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
    $143 = $$3 >>> 0 < $142 >>> 0;
    if ($143) {
     _abort();
    }
    $144 = $$3 + 24 | 0;
    SAFE_HEAP_STORE($144 | 0, $100 | 0, 4);
    $145 = $5 + 16 | 0;
    $146 = SAFE_HEAP_LOAD($145 | 0, 4, 0) | 0 | 0;
    $147 = ($146 | 0) == (0 | 0);
    do {
     if (!$147) {
      $148 = $146 >>> 0 < $142 >>> 0;
      if ($148) {
       _abort();
      } else {
       $149 = $$3 + 16 | 0;
       SAFE_HEAP_STORE($149 | 0, $146 | 0, 4);
       $150 = $146 + 24 | 0;
       SAFE_HEAP_STORE($150 | 0, $$3 | 0, 4);
       break;
      }
     }
    } while (0);
    $151 = $145 + 4 | 0;
    $152 = SAFE_HEAP_LOAD($151 | 0, 4, 0) | 0 | 0;
    $153 = ($152 | 0) == (0 | 0);
    if (!$153) {
     $154 = SAFE_HEAP_LOAD(3088 | 0, 4, 0) | 0 | 0;
     $155 = $152 >>> 0 < $154 >>> 0;
     if ($155) {
      _abort();
     } else {
      $156 = $$3 + 20 | 0;
      SAFE_HEAP_STORE($156 | 0, $152 | 0, 4);
      $157 = $152 + 24 | 0;
      SAFE_HEAP_STORE($157 | 0, $$3 | 0, 4);
      break;
     }
    }
   }
  }
 } while (0);
 $158 = $74 >>> 0 < 16;
 $159 = $3 & 1;
 if ($158) {
  $160 = $72 | $159;
  $161 = $160 | 2;
  SAFE_HEAP_STORE($2 | 0, $161 | 0, 4);
  $162 = $0 + $72 | 0;
  $163 = $162 + 4 | 0;
  $164 = SAFE_HEAP_LOAD($163 | 0, 4, 0) | 0 | 0;
  $165 = $164 | 1;
  SAFE_HEAP_STORE($163 | 0, $165 | 0, 4);
  $$2 = $0;
  return $$2 | 0;
 } else {
  $166 = $0 + $1 | 0;
  $167 = $159 | $1;
  $168 = $167 | 2;
  SAFE_HEAP_STORE($2 | 0, $168 | 0, 4);
  $169 = $166 + 4 | 0;
  $170 = $74 | 3;
  SAFE_HEAP_STORE($169 | 0, $170 | 0, 4);
  $171 = $166 + $74 | 0;
  $172 = $171 + 4 | 0;
  $173 = SAFE_HEAP_LOAD($172 | 0, 4, 0) | 0 | 0;
  $174 = $173 | 1;
  SAFE_HEAP_STORE($172 | 0, $174 | 0, 4);
  _dispose_chunk($166, $74);
  $$2 = $0;
  return $$2 | 0;
 }
 return 0 | 0;
}

function _pop_arg($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$mask = 0, $$mask31 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0.0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0;
 var $116 = 0.0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0;
 var $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0;
 var $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0;
 var $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0;
 var $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, $arglist_current = 0, $arglist_current11 = 0, $arglist_current14 = 0, $arglist_current17 = 0;
 var $arglist_current2 = 0, $arglist_current20 = 0, $arglist_current23 = 0, $arglist_current26 = 0, $arglist_current5 = 0, $arglist_current8 = 0, $arglist_next = 0, $arglist_next12 = 0, $arglist_next15 = 0, $arglist_next18 = 0, $arglist_next21 = 0, $arglist_next24 = 0, $arglist_next27 = 0, $arglist_next3 = 0, $arglist_next6 = 0, $arglist_next9 = 0, $expanded = 0, $expanded28 = 0, $expanded30 = 0, $expanded31 = 0;
 var $expanded32 = 0, $expanded34 = 0, $expanded35 = 0, $expanded37 = 0, $expanded38 = 0, $expanded39 = 0, $expanded41 = 0, $expanded42 = 0, $expanded44 = 0, $expanded45 = 0, $expanded46 = 0, $expanded48 = 0, $expanded49 = 0, $expanded51 = 0, $expanded52 = 0, $expanded53 = 0, $expanded55 = 0, $expanded56 = 0, $expanded58 = 0, $expanded59 = 0;
 var $expanded60 = 0, $expanded62 = 0, $expanded63 = 0, $expanded65 = 0, $expanded66 = 0, $expanded67 = 0, $expanded69 = 0, $expanded70 = 0, $expanded72 = 0, $expanded73 = 0, $expanded74 = 0, $expanded76 = 0, $expanded77 = 0, $expanded79 = 0, $expanded80 = 0, $expanded81 = 0, $expanded83 = 0, $expanded84 = 0, $expanded86 = 0, $expanded87 = 0;
 var $expanded88 = 0, $expanded90 = 0, $expanded91 = 0, $expanded93 = 0, $expanded94 = 0, $expanded95 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = $1 >>> 0 > 20;
 L1 : do {
  if (!$3) {
   do {
    switch ($1 | 0) {
    case 9:
     {
      $arglist_current = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $4 = $arglist_current;
      $5 = 0 + 4 | 0;
      $expanded28 = $5;
      $expanded = $expanded28 - 1 | 0;
      $6 = $4 + $expanded | 0;
      $7 = 0 + 4 | 0;
      $expanded32 = $7;
      $expanded31 = $expanded32 - 1 | 0;
      $expanded30 = $expanded31 ^ -1;
      $8 = $6 & $expanded30;
      $9 = $8;
      $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
      $arglist_next = $9 + 4 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next | 0, 4);
      SAFE_HEAP_STORE($0 | 0, $10 | 0, 4);
      break L1;
      break;
     }
    case 10:
     {
      $arglist_current2 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $11 = $arglist_current2;
      $12 = 0 + 4 | 0;
      $expanded35 = $12;
      $expanded34 = $expanded35 - 1 | 0;
      $13 = $11 + $expanded34 | 0;
      $14 = 0 + 4 | 0;
      $expanded39 = $14;
      $expanded38 = $expanded39 - 1 | 0;
      $expanded37 = $expanded38 ^ -1;
      $15 = $13 & $expanded37;
      $16 = $15;
      $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
      $arglist_next3 = $16 + 4 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next3 | 0, 4);
      $18 = ($17 | 0) < 0;
      $19 = $18 << 31 >> 31;
      $20 = $0;
      $21 = $20;
      SAFE_HEAP_STORE($21 | 0, $17 | 0, 4);
      $22 = $20 + 4 | 0;
      $23 = $22;
      SAFE_HEAP_STORE($23 | 0, $19 | 0, 4);
      break L1;
      break;
     }
    case 11:
     {
      $arglist_current5 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $24 = $arglist_current5;
      $25 = 0 + 4 | 0;
      $expanded42 = $25;
      $expanded41 = $expanded42 - 1 | 0;
      $26 = $24 + $expanded41 | 0;
      $27 = 0 + 4 | 0;
      $expanded46 = $27;
      $expanded45 = $expanded46 - 1 | 0;
      $expanded44 = $expanded45 ^ -1;
      $28 = $26 & $expanded44;
      $29 = $28;
      $30 = SAFE_HEAP_LOAD($29 | 0, 4, 0) | 0 | 0;
      $arglist_next6 = $29 + 4 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next6 | 0, 4);
      $31 = $0;
      $32 = $31;
      SAFE_HEAP_STORE($32 | 0, $30 | 0, 4);
      $33 = $31 + 4 | 0;
      $34 = $33;
      SAFE_HEAP_STORE($34 | 0, 0 | 0, 4);
      break L1;
      break;
     }
    case 12:
     {
      $arglist_current8 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $35 = $arglist_current8;
      $36 = 0 + 8 | 0;
      $expanded49 = $36;
      $expanded48 = $expanded49 - 1 | 0;
      $37 = $35 + $expanded48 | 0;
      $38 = 0 + 8 | 0;
      $expanded53 = $38;
      $expanded52 = $expanded53 - 1 | 0;
      $expanded51 = $expanded52 ^ -1;
      $39 = $37 & $expanded51;
      $40 = $39;
      $41 = $40;
      $42 = $41;
      $43 = SAFE_HEAP_LOAD($42 | 0, 4, 0) | 0 | 0;
      $44 = $41 + 4 | 0;
      $45 = $44;
      $46 = SAFE_HEAP_LOAD($45 | 0, 4, 0) | 0 | 0;
      $arglist_next9 = $40 + 8 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next9 | 0, 4);
      $47 = $0;
      $48 = $47;
      SAFE_HEAP_STORE($48 | 0, $43 | 0, 4);
      $49 = $47 + 4 | 0;
      $50 = $49;
      SAFE_HEAP_STORE($50 | 0, $46 | 0, 4);
      break L1;
      break;
     }
    case 13:
     {
      $arglist_current11 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $51 = $arglist_current11;
      $52 = 0 + 4 | 0;
      $expanded56 = $52;
      $expanded55 = $expanded56 - 1 | 0;
      $53 = $51 + $expanded55 | 0;
      $54 = 0 + 4 | 0;
      $expanded60 = $54;
      $expanded59 = $expanded60 - 1 | 0;
      $expanded58 = $expanded59 ^ -1;
      $55 = $53 & $expanded58;
      $56 = $55;
      $57 = SAFE_HEAP_LOAD($56 | 0, 4, 0) | 0 | 0;
      $arglist_next12 = $56 + 4 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next12 | 0, 4);
      $58 = $57 & 65535;
      $59 = $58 << 16 >> 16;
      $60 = ($59 | 0) < 0;
      $61 = $60 << 31 >> 31;
      $62 = $0;
      $63 = $62;
      SAFE_HEAP_STORE($63 | 0, $59 | 0, 4);
      $64 = $62 + 4 | 0;
      $65 = $64;
      SAFE_HEAP_STORE($65 | 0, $61 | 0, 4);
      break L1;
      break;
     }
    case 14:
     {
      $arglist_current14 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $66 = $arglist_current14;
      $67 = 0 + 4 | 0;
      $expanded63 = $67;
      $expanded62 = $expanded63 - 1 | 0;
      $68 = $66 + $expanded62 | 0;
      $69 = 0 + 4 | 0;
      $expanded67 = $69;
      $expanded66 = $expanded67 - 1 | 0;
      $expanded65 = $expanded66 ^ -1;
      $70 = $68 & $expanded65;
      $71 = $70;
      $72 = SAFE_HEAP_LOAD($71 | 0, 4, 0) | 0 | 0;
      $arglist_next15 = $71 + 4 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next15 | 0, 4);
      $$mask31 = $72 & 65535;
      $73 = $0;
      $74 = $73;
      SAFE_HEAP_STORE($74 | 0, $$mask31 | 0, 4);
      $75 = $73 + 4 | 0;
      $76 = $75;
      SAFE_HEAP_STORE($76 | 0, 0 | 0, 4);
      break L1;
      break;
     }
    case 15:
     {
      $arglist_current17 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $77 = $arglist_current17;
      $78 = 0 + 4 | 0;
      $expanded70 = $78;
      $expanded69 = $expanded70 - 1 | 0;
      $79 = $77 + $expanded69 | 0;
      $80 = 0 + 4 | 0;
      $expanded74 = $80;
      $expanded73 = $expanded74 - 1 | 0;
      $expanded72 = $expanded73 ^ -1;
      $81 = $79 & $expanded72;
      $82 = $81;
      $83 = SAFE_HEAP_LOAD($82 | 0, 4, 0) | 0 | 0;
      $arglist_next18 = $82 + 4 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next18 | 0, 4);
      $84 = $83 & 255;
      $85 = $84 << 24 >> 24;
      $86 = ($85 | 0) < 0;
      $87 = $86 << 31 >> 31;
      $88 = $0;
      $89 = $88;
      SAFE_HEAP_STORE($89 | 0, $85 | 0, 4);
      $90 = $88 + 4 | 0;
      $91 = $90;
      SAFE_HEAP_STORE($91 | 0, $87 | 0, 4);
      break L1;
      break;
     }
    case 16:
     {
      $arglist_current20 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $92 = $arglist_current20;
      $93 = 0 + 4 | 0;
      $expanded77 = $93;
      $expanded76 = $expanded77 - 1 | 0;
      $94 = $92 + $expanded76 | 0;
      $95 = 0 + 4 | 0;
      $expanded81 = $95;
      $expanded80 = $expanded81 - 1 | 0;
      $expanded79 = $expanded80 ^ -1;
      $96 = $94 & $expanded79;
      $97 = $96;
      $98 = SAFE_HEAP_LOAD($97 | 0, 4, 0) | 0 | 0;
      $arglist_next21 = $97 + 4 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next21 | 0, 4);
      $$mask = $98 & 255;
      $99 = $0;
      $100 = $99;
      SAFE_HEAP_STORE($100 | 0, $$mask | 0, 4);
      $101 = $99 + 4 | 0;
      $102 = $101;
      SAFE_HEAP_STORE($102 | 0, 0 | 0, 4);
      break L1;
      break;
     }
    case 17:
     {
      $arglist_current23 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $103 = $arglist_current23;
      $104 = 0 + 8 | 0;
      $expanded84 = $104;
      $expanded83 = $expanded84 - 1 | 0;
      $105 = $103 + $expanded83 | 0;
      $106 = 0 + 8 | 0;
      $expanded88 = $106;
      $expanded87 = $expanded88 - 1 | 0;
      $expanded86 = $expanded87 ^ -1;
      $107 = $105 & $expanded86;
      $108 = $107;
      $109 = +(+SAFE_HEAP_LOAD_D($108 | 0, 8));
      $arglist_next24 = $108 + 8 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next24 | 0, 4);
      SAFE_HEAP_STORE_D($0 | 0, +$109, 8);
      break L1;
      break;
     }
    case 18:
     {
      $arglist_current26 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
      $110 = $arglist_current26;
      $111 = 0 + 8 | 0;
      $expanded91 = $111;
      $expanded90 = $expanded91 - 1 | 0;
      $112 = $110 + $expanded90 | 0;
      $113 = 0 + 8 | 0;
      $expanded95 = $113;
      $expanded94 = $expanded95 - 1 | 0;
      $expanded93 = $expanded94 ^ -1;
      $114 = $112 & $expanded93;
      $115 = $114;
      $116 = +(+SAFE_HEAP_LOAD_D($115 | 0, 8));
      $arglist_next27 = $115 + 8 | 0;
      SAFE_HEAP_STORE($2 | 0, $arglist_next27 | 0, 4);
      SAFE_HEAP_STORE_D($0 | 0, +$116, 8);
      break L1;
      break;
     }
    default:
     {
      break L1;
     }
    }
   } while (0);
  }
 } while (0);
 return;
}

function _sjf_global($0) {
 $0 = $0 | 0;
 var $1 = 0, $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0;
 var $117 = 0, $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0;
 var $135 = 0, $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $150 = 0, $151 = 0, $152 = 0;
 var $153 = 0, $154 = 0, $155 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0;
 var $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0;
 var $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0;
 var $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0;
 var $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(128 | 0);
 $2 = sp + 116 | 0;
 $3 = sp + 112 | 0;
 $4 = sp + 96 | 0;
 $5 = sp + 80 | 0;
 $6 = sp + 64 | 0;
 $13 = sp + 32 | 0;
 $14 = sp + 28 | 0;
 $15 = sp + 24 | 0;
 $16 = sp + 20 | 0;
 $17 = sp + 16 | 0;
 $18 = sp + 12 | 0;
 $19 = sp + 8 | 0;
 $20 = sp + 4 | 0;
 $21 = sp;
 $1 = $0;
 $22 = _malloc(8) | 0;
 SAFE_HEAP_STORE($13 | 0, $22 | 0, 4);
 $23 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($23 | 0, 1 | 0, 4);
 $24 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 _sjf_anon4($24, $13);
 $25 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $26 = $1;
 $27 = $26 + 4 | 0;
 SAFE_HEAP_STORE($27 | 0, $25 | 0, 4);
 $28 = $1;
 $29 = $28 + 4 | 0;
 $30 = SAFE_HEAP_LOAD($29 | 0, 4, 0) | 0 | 0;
 $31 = SAFE_HEAP_LOAD($30 | 0, 4, 0) | 0 | 0;
 $32 = $31 + 1 | 0;
 SAFE_HEAP_STORE($30 | 0, $32 | 0, 4);
 SAFE_HEAP_STORE($16 | 0, $2 | 0, 4);
 $33 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($33 | 0, 1 | 0, 4);
 $34 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
 _sjf_anon3($34, $16);
 $35 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
 $8 = $35;
 $36 = $8;
 $37 = SAFE_HEAP_LOAD($36 | 0, 4, 0) | 0 | 0;
 $38 = $37 + 1 | 0;
 SAFE_HEAP_STORE($36 | 0, $38 | 0, 4);
 SAFE_HEAP_STORE($17 | 0, $3 | 0, 4);
 $39 = SAFE_HEAP_LOAD($17 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($39 | 0, 1 | 0, 4);
 $40 = SAFE_HEAP_LOAD($17 | 0, 4, 0) | 0 | 0;
 _sjf_anon2($40, $17);
 $41 = SAFE_HEAP_LOAD($17 | 0, 4, 0) | 0 | 0;
 $7 = $41;
 $42 = $7;
 $43 = SAFE_HEAP_LOAD($42 | 0, 4, 0) | 0 | 0;
 $44 = $43 + 1 | 0;
 SAFE_HEAP_STORE($42 | 0, $44 | 0, 4);
 $45 = _malloc(4) | 0;
 SAFE_HEAP_STORE($18 | 0, $45 | 0, 4);
 $46 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($46 | 0, 1 | 0, 4);
 $47 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
 _sjf_anon1($47, $18);
 $48 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
 $49 = $1;
 $50 = $49 + 8 | 0;
 SAFE_HEAP_STORE($50 | 0, $48 | 0, 4);
 $51 = $1;
 $52 = $51 + 8 | 0;
 $53 = SAFE_HEAP_LOAD($52 | 0, 4, 0) | 0 | 0;
 $54 = SAFE_HEAP_LOAD($53 | 0, 4, 0) | 0 | 0;
 $55 = $54 + 1 | 0;
 SAFE_HEAP_STORE($53 | 0, $55 | 0, 4);
 $56 = _malloc(16) | 0;
 SAFE_HEAP_STORE($19 | 0, $56 | 0, 4);
 $57 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($57 | 0, 1 | 0, 4);
 $58 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 $59 = $58 + 4 | 0;
 SAFE_HEAP_STORE($59 | 0, 5 | 0, 4);
 $60 = SAFE_HEAP_LOAD(2 * 4 | 0, 4, 0) | 0 | 0;
 $61 = $60;
 $62 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 $63 = $62 + 8 | 0;
 SAFE_HEAP_STORE($63 | 0, $61 | 0, 4);
 $64 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 $65 = $64 + 12 | 0;
 SAFE_HEAP_STORE($65 >> 0 | 0, 0 | 0, 1);
 $66 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 _sjf_array_char($66, $19);
 $67 = _malloc(16) | 0;
 SAFE_HEAP_STORE($20 | 0, $67 | 0, 4);
 $68 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($68 | 0, 1 | 0, 4);
 $69 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 $70 = $69 + 8 | 0;
 SAFE_HEAP_STORE($70 | 0, 4 | 0, 4);
 $71 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 $72 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 $73 = $72 + 12 | 0;
 SAFE_HEAP_STORE($73 | 0, $71 | 0, 4);
 $74 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 $75 = $74 + 12 | 0;
 $76 = SAFE_HEAP_LOAD($75 | 0, 4, 0) | 0 | 0;
 $77 = SAFE_HEAP_LOAD($76 | 0, 4, 0) | 0 | 0;
 $78 = $77 + 1 | 0;
 SAFE_HEAP_STORE($76 | 0, $78 | 0, 4);
 $79 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 _sjf_string($79, $20);
 $9 = 0;
 SAFE_HEAP_STORE($21 | 0, $4 | 0, 4);
 $80 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($80 | 0, 1 | 0, 4);
 $81 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
 $82 = $81 + 4 | 0;
 SAFE_HEAP_STORE($82 | 0, 1 | 0, 4);
 $83 = $9;
 $84 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
 $85 = $84 + 8 | 0;
 SAFE_HEAP_STORE($85 | 0, $83 | 0, 4);
 $86 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
 $87 = $86 + 12 | 0;
 SAFE_HEAP_STORE($87 >> 0 | 0, 0 | 0, 1);
 $88 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
 _sjf_array_sji_element($88, $21);
 $89 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
 $12 = $89;
 $90 = $12;
 $91 = SAFE_HEAP_LOAD($90 | 0, 4, 0) | 0 | 0;
 $92 = $91 + 1 | 0;
 SAFE_HEAP_STORE($90 | 0, $92 | 0, 4);
 SAFE_HEAP_STORE($14 | 0, $5 | 0, 4);
 $93 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($93 | 0, 1 | 0, 4);
 $94 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $95 = $94 + 8 | 0;
 SAFE_HEAP_STORE($95 | 0, 0 | 0, 4);
 $96 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 _sjf_timerElement($96, $14);
 $97 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $98 = _sjf_timerElement_as_sji_element($97) | 0;
 $10 = $98;
 $99 = $12;
 $100 = $10;
 _sjf_array_sji_element_setAt($99, 0, $100);
 SAFE_HEAP_STORE($15 | 0, $6 | 0, 4);
 $101 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($101 | 0, 1 | 0, 4);
 $102 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 $103 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
 $104 = $103 + 8 | 0;
 SAFE_HEAP_STORE($104 | 0, $102 | 0, 4);
 $105 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
 $106 = $105 + 8 | 0;
 $107 = SAFE_HEAP_LOAD($106 | 0, 4, 0) | 0 | 0;
 $108 = SAFE_HEAP_LOAD($107 | 0, 4, 0) | 0 | 0;
 $109 = $108 + 1 | 0;
 SAFE_HEAP_STORE($107 | 0, $109 | 0, 4);
 $110 = $12;
 $111 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
 $112 = $111 + 12 | 0;
 SAFE_HEAP_STORE($112 | 0, $110 | 0, 4);
 $113 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
 $114 = $113 + 12 | 0;
 $115 = SAFE_HEAP_LOAD($114 | 0, 4, 0) | 0 | 0;
 $116 = SAFE_HEAP_LOAD($115 | 0, 4, 0) | 0 | 0;
 $117 = $116 + 1 | 0;
 SAFE_HEAP_STORE($115 | 0, $117 | 0, 4);
 $118 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
 _sjf_element($118, $15);
 $119 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
 $11 = $119;
 $120 = $11;
 $121 = SAFE_HEAP_LOAD($120 | 0, 4, 0) | 0 | 0;
 $122 = $121 + 1 | 0;
 SAFE_HEAP_STORE($120 | 0, $122 | 0, 4);
 $123 = $11;
 _sjf_element_update($123);
 $124 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $125 = SAFE_HEAP_LOAD($124 | 0, 4, 0) | 0 | 0;
 $126 = $125 + -1 | 0;
 SAFE_HEAP_STORE($124 | 0, $126 | 0, 4);
 $127 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $128 = SAFE_HEAP_LOAD($127 | 0, 4, 0) | 0 | 0;
 $129 = ($128 | 0) <= 0;
 if ($129) {
  $130 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
  _sjf_anon4_destroy($130);
  $131 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
  _free($131);
 }
 $132 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
 $133 = SAFE_HEAP_LOAD($132 | 0, 4, 0) | 0 | 0;
 $134 = $133 + -1 | 0;
 SAFE_HEAP_STORE($132 | 0, $134 | 0, 4);
 $135 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
 $136 = SAFE_HEAP_LOAD($135 | 0, 4, 0) | 0 | 0;
 $137 = ($136 | 0) <= 0;
 if ($137) {
  $138 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
  _sjf_anon1_destroy($138);
  $139 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
  _free($139);
 }
 $140 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 $141 = SAFE_HEAP_LOAD($140 | 0, 4, 0) | 0 | 0;
 $142 = $141 + -1 | 0;
 SAFE_HEAP_STORE($140 | 0, $142 | 0, 4);
 $143 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 $144 = SAFE_HEAP_LOAD($143 | 0, 4, 0) | 0 | 0;
 $145 = ($144 | 0) <= 0;
 if ($145) {
  $146 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
  _sjf_array_char_destroy($146);
  $147 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
  _free($147);
 }
 $148 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 $149 = SAFE_HEAP_LOAD($148 | 0, 4, 0) | 0 | 0;
 $150 = $149 + -1 | 0;
 SAFE_HEAP_STORE($148 | 0, $150 | 0, 4);
 $151 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 $152 = SAFE_HEAP_LOAD($151 | 0, 4, 0) | 0 | 0;
 $153 = ($152 | 0) <= 0;
 if (!$153) {
  _sjf_anon3_destroy($2);
  _sjf_anon2_destroy($3);
  _sjf_array_sji_element_destroy($4);
  _sjf_timerElement_destroy($5);
  _sjf_element_destroy($6);
  STACKTOP = sp;
  return;
 }
 $154 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 _sjf_string_destroy($154);
 $155 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 _free($155);
 _sjf_anon3_destroy($2);
 _sjf_anon2_destroy($3);
 _sjf_array_sji_element_destroy($4);
 _sjf_timerElement_destroy($5);
 _sjf_element_destroy($6);
 STACKTOP = sp;
 return;
}

function ___udivmoddi4($a$0, $a$1, $b$0, $b$1, $rem) {
 $a$0 = $a$0 | 0;
 $a$1 = $a$1 | 0;
 $b$0 = $b$0 | 0;
 $b$1 = $b$1 | 0;
 $rem = $rem | 0;
 var $n_sroa_0_0_extract_trunc = 0, $n_sroa_1_4_extract_shift$0 = 0, $n_sroa_1_4_extract_trunc = 0, $d_sroa_0_0_extract_trunc = 0, $d_sroa_1_4_extract_shift$0 = 0, $d_sroa_1_4_extract_trunc = 0, $4 = 0, $17 = 0, $37 = 0, $49 = 0, $51 = 0, $57 = 0, $58 = 0, $66 = 0, $78 = 0, $86 = 0, $88 = 0, $89 = 0, $91 = 0, $92 = 0, $95 = 0, $105 = 0, $117 = 0, $119 = 0, $125 = 0, $126 = 0, $130 = 0, $q_sroa_1_1_ph = 0, $q_sroa_0_1_ph = 0, $r_sroa_1_1_ph = 0, $r_sroa_0_1_ph = 0, $sr_1_ph = 0, $d_sroa_0_0_insert_insert99$0 = 0, $d_sroa_0_0_insert_insert99$1 = 0, $137$0 = 0, $137$1 = 0, $carry_0203 = 0, $sr_1202 = 0, $r_sroa_0_1201 = 0, $r_sroa_1_1200 = 0, $q_sroa_0_1199 = 0, $q_sroa_1_1198 = 0, $147 = 0, $149 = 0, $r_sroa_0_0_insert_insert42$0 = 0, $r_sroa_0_0_insert_insert42$1 = 0, $150$1 = 0, $151$0 = 0, $152 = 0, $154$0 = 0, $r_sroa_0_0_extract_trunc = 0, $r_sroa_1_4_extract_trunc = 0, $155 = 0, $carry_0_lcssa$0 = 0, $carry_0_lcssa$1 = 0, $r_sroa_0_1_lcssa = 0, $r_sroa_1_1_lcssa = 0, $q_sroa_0_1_lcssa = 0, $q_sroa_1_1_lcssa = 0, $q_sroa_0_0_insert_ext75$0 = 0, $q_sroa_0_0_insert_ext75$1 = 0, $q_sroa_0_0_insert_insert77$1 = 0, $_0$0 = 0, $_0$1 = 0;
 $n_sroa_0_0_extract_trunc = $a$0;
 $n_sroa_1_4_extract_shift$0 = $a$1;
 $n_sroa_1_4_extract_trunc = $n_sroa_1_4_extract_shift$0;
 $d_sroa_0_0_extract_trunc = $b$0;
 $d_sroa_1_4_extract_shift$0 = $b$1;
 $d_sroa_1_4_extract_trunc = $d_sroa_1_4_extract_shift$0;
 if (($n_sroa_1_4_extract_trunc | 0) == 0) {
  $4 = ($rem | 0) != 0;
  if (($d_sroa_1_4_extract_trunc | 0) == 0) {
   if ($4) {
    SAFE_HEAP_STORE($rem | 0, ($n_sroa_0_0_extract_trunc >>> 0) % ($d_sroa_0_0_extract_trunc >>> 0) | 0, 4);
    SAFE_HEAP_STORE($rem + 4 | 0, 0 | 0, 4);
   }
   $_0$1 = 0;
   $_0$0 = ($n_sroa_0_0_extract_trunc >>> 0) / ($d_sroa_0_0_extract_trunc >>> 0) >>> 0;
   return (tempRet0 = $_0$1, $_0$0) | 0;
  } else {
   if (!$4) {
    $_0$1 = 0;
    $_0$0 = 0;
    return (tempRet0 = $_0$1, $_0$0) | 0;
   }
   SAFE_HEAP_STORE($rem | 0, $a$0 & -1 | 0, 4);
   SAFE_HEAP_STORE($rem + 4 | 0, $a$1 & 0 | 0, 4);
   $_0$1 = 0;
   $_0$0 = 0;
   return (tempRet0 = $_0$1, $_0$0) | 0;
  }
 }
 $17 = ($d_sroa_1_4_extract_trunc | 0) == 0;
 do {
  if (($d_sroa_0_0_extract_trunc | 0) == 0) {
   if ($17) {
    if (($rem | 0) != 0) {
     SAFE_HEAP_STORE($rem | 0, ($n_sroa_1_4_extract_trunc >>> 0) % ($d_sroa_0_0_extract_trunc >>> 0) | 0, 4);
     SAFE_HEAP_STORE($rem + 4 | 0, 0 | 0, 4);
    }
    $_0$1 = 0;
    $_0$0 = ($n_sroa_1_4_extract_trunc >>> 0) / ($d_sroa_0_0_extract_trunc >>> 0) >>> 0;
    return (tempRet0 = $_0$1, $_0$0) | 0;
   }
   if (($n_sroa_0_0_extract_trunc | 0) == 0) {
    if (($rem | 0) != 0) {
     SAFE_HEAP_STORE($rem | 0, 0 | 0, 4);
     SAFE_HEAP_STORE($rem + 4 | 0, ($n_sroa_1_4_extract_trunc >>> 0) % ($d_sroa_1_4_extract_trunc >>> 0) | 0, 4);
    }
    $_0$1 = 0;
    $_0$0 = ($n_sroa_1_4_extract_trunc >>> 0) / ($d_sroa_1_4_extract_trunc >>> 0) >>> 0;
    return (tempRet0 = $_0$1, $_0$0) | 0;
   }
   $37 = $d_sroa_1_4_extract_trunc - 1 | 0;
   if (($37 & $d_sroa_1_4_extract_trunc | 0) == 0) {
    if (($rem | 0) != 0) {
     SAFE_HEAP_STORE($rem | 0, 0 | $a$0 & -1 | 0, 4);
     SAFE_HEAP_STORE($rem + 4 | 0, $37 & $n_sroa_1_4_extract_trunc | $a$1 & 0 | 0, 4);
    }
    $_0$1 = 0;
    $_0$0 = $n_sroa_1_4_extract_trunc >>> ((_llvm_cttz_i32($d_sroa_1_4_extract_trunc | 0) | 0) >>> 0);
    return (tempRet0 = $_0$1, $_0$0) | 0;
   }
   $49 = Math_clz32($d_sroa_1_4_extract_trunc | 0) | 0;
   $51 = $49 - (Math_clz32($n_sroa_1_4_extract_trunc | 0) | 0) | 0;
   if ($51 >>> 0 <= 30) {
    $57 = $51 + 1 | 0;
    $58 = 31 - $51 | 0;
    $sr_1_ph = $57;
    $r_sroa_0_1_ph = $n_sroa_1_4_extract_trunc << $58 | $n_sroa_0_0_extract_trunc >>> ($57 >>> 0);
    $r_sroa_1_1_ph = $n_sroa_1_4_extract_trunc >>> ($57 >>> 0);
    $q_sroa_0_1_ph = 0;
    $q_sroa_1_1_ph = $n_sroa_0_0_extract_trunc << $58;
    break;
   }
   if (($rem | 0) == 0) {
    $_0$1 = 0;
    $_0$0 = 0;
    return (tempRet0 = $_0$1, $_0$0) | 0;
   }
   SAFE_HEAP_STORE($rem | 0, 0 | $a$0 & -1 | 0, 4);
   SAFE_HEAP_STORE($rem + 4 | 0, $n_sroa_1_4_extract_shift$0 | $a$1 & 0 | 0, 4);
   $_0$1 = 0;
   $_0$0 = 0;
   return (tempRet0 = $_0$1, $_0$0) | 0;
  } else {
   if (!$17) {
    $117 = Math_clz32($d_sroa_1_4_extract_trunc | 0) | 0;
    $119 = $117 - (Math_clz32($n_sroa_1_4_extract_trunc | 0) | 0) | 0;
    if ($119 >>> 0 <= 31) {
     $125 = $119 + 1 | 0;
     $126 = 31 - $119 | 0;
     $130 = $119 - 31 >> 31;
     $sr_1_ph = $125;
     $r_sroa_0_1_ph = $n_sroa_0_0_extract_trunc >>> ($125 >>> 0) & $130 | $n_sroa_1_4_extract_trunc << $126;
     $r_sroa_1_1_ph = $n_sroa_1_4_extract_trunc >>> ($125 >>> 0) & $130;
     $q_sroa_0_1_ph = 0;
     $q_sroa_1_1_ph = $n_sroa_0_0_extract_trunc << $126;
     break;
    }
    if (($rem | 0) == 0) {
     $_0$1 = 0;
     $_0$0 = 0;
     return (tempRet0 = $_0$1, $_0$0) | 0;
    }
    SAFE_HEAP_STORE($rem | 0, 0 | $a$0 & -1 | 0, 4);
    SAFE_HEAP_STORE($rem + 4 | 0, $n_sroa_1_4_extract_shift$0 | $a$1 & 0 | 0, 4);
    $_0$1 = 0;
    $_0$0 = 0;
    return (tempRet0 = $_0$1, $_0$0) | 0;
   }
   $66 = $d_sroa_0_0_extract_trunc - 1 | 0;
   if (($66 & $d_sroa_0_0_extract_trunc | 0) != 0) {
    $86 = (Math_clz32($d_sroa_0_0_extract_trunc | 0) | 0) + 33 | 0;
    $88 = $86 - (Math_clz32($n_sroa_1_4_extract_trunc | 0) | 0) | 0;
    $89 = 64 - $88 | 0;
    $91 = 32 - $88 | 0;
    $92 = $91 >> 31;
    $95 = $88 - 32 | 0;
    $105 = $95 >> 31;
    $sr_1_ph = $88;
    $r_sroa_0_1_ph = $91 - 1 >> 31 & $n_sroa_1_4_extract_trunc >>> ($95 >>> 0) | ($n_sroa_1_4_extract_trunc << $91 | $n_sroa_0_0_extract_trunc >>> ($88 >>> 0)) & $105;
    $r_sroa_1_1_ph = $105 & $n_sroa_1_4_extract_trunc >>> ($88 >>> 0);
    $q_sroa_0_1_ph = $n_sroa_0_0_extract_trunc << $89 & $92;
    $q_sroa_1_1_ph = ($n_sroa_1_4_extract_trunc << $89 | $n_sroa_0_0_extract_trunc >>> ($95 >>> 0)) & $92 | $n_sroa_0_0_extract_trunc << $91 & $88 - 33 >> 31;
    break;
   }
   if (($rem | 0) != 0) {
    SAFE_HEAP_STORE($rem | 0, $66 & $n_sroa_0_0_extract_trunc | 0, 4);
    SAFE_HEAP_STORE($rem + 4 | 0, 0 | 0, 4);
   }
   if (($d_sroa_0_0_extract_trunc | 0) == 1) {
    $_0$1 = $n_sroa_1_4_extract_shift$0 | $a$1 & 0;
    $_0$0 = 0 | $a$0 & -1;
    return (tempRet0 = $_0$1, $_0$0) | 0;
   } else {
    $78 = _llvm_cttz_i32($d_sroa_0_0_extract_trunc | 0) | 0;
    $_0$1 = 0 | $n_sroa_1_4_extract_trunc >>> ($78 >>> 0);
    $_0$0 = $n_sroa_1_4_extract_trunc << 32 - $78 | $n_sroa_0_0_extract_trunc >>> ($78 >>> 0) | 0;
    return (tempRet0 = $_0$1, $_0$0) | 0;
   }
  }
 } while (0);
 if (($sr_1_ph | 0) == 0) {
  $q_sroa_1_1_lcssa = $q_sroa_1_1_ph;
  $q_sroa_0_1_lcssa = $q_sroa_0_1_ph;
  $r_sroa_1_1_lcssa = $r_sroa_1_1_ph;
  $r_sroa_0_1_lcssa = $r_sroa_0_1_ph;
  $carry_0_lcssa$1 = 0;
  $carry_0_lcssa$0 = 0;
 } else {
  $d_sroa_0_0_insert_insert99$0 = 0 | $b$0 & -1;
  $d_sroa_0_0_insert_insert99$1 = $d_sroa_1_4_extract_shift$0 | $b$1 & 0;
  $137$0 = _i64Add($d_sroa_0_0_insert_insert99$0 | 0, $d_sroa_0_0_insert_insert99$1 | 0, -1, -1) | 0;
  $137$1 = tempRet0;
  $q_sroa_1_1198 = $q_sroa_1_1_ph;
  $q_sroa_0_1199 = $q_sroa_0_1_ph;
  $r_sroa_1_1200 = $r_sroa_1_1_ph;
  $r_sroa_0_1201 = $r_sroa_0_1_ph;
  $sr_1202 = $sr_1_ph;
  $carry_0203 = 0;
  while (1) {
   $147 = $q_sroa_0_1199 >>> 31 | $q_sroa_1_1198 << 1;
   $149 = $carry_0203 | $q_sroa_0_1199 << 1;
   $r_sroa_0_0_insert_insert42$0 = 0 | ($r_sroa_0_1201 << 1 | $q_sroa_1_1198 >>> 31);
   $r_sroa_0_0_insert_insert42$1 = $r_sroa_0_1201 >>> 31 | $r_sroa_1_1200 << 1 | 0;
   _i64Subtract($137$0 | 0, $137$1 | 0, $r_sroa_0_0_insert_insert42$0 | 0, $r_sroa_0_0_insert_insert42$1 | 0) | 0;
   $150$1 = tempRet0;
   $151$0 = $150$1 >> 31 | (($150$1 | 0) < 0 ? -1 : 0) << 1;
   $152 = $151$0 & 1;
   $154$0 = _i64Subtract($r_sroa_0_0_insert_insert42$0 | 0, $r_sroa_0_0_insert_insert42$1 | 0, $151$0 & $d_sroa_0_0_insert_insert99$0 | 0, ((($150$1 | 0) < 0 ? -1 : 0) >> 31 | (($150$1 | 0) < 0 ? -1 : 0) << 1) & $d_sroa_0_0_insert_insert99$1 | 0) | 0;
   $r_sroa_0_0_extract_trunc = $154$0;
   $r_sroa_1_4_extract_trunc = tempRet0;
   $155 = $sr_1202 - 1 | 0;
   if (($155 | 0) == 0) {
    break;
   } else {
    $q_sroa_1_1198 = $147;
    $q_sroa_0_1199 = $149;
    $r_sroa_1_1200 = $r_sroa_1_4_extract_trunc;
    $r_sroa_0_1201 = $r_sroa_0_0_extract_trunc;
    $sr_1202 = $155;
    $carry_0203 = $152;
   }
  }
  $q_sroa_1_1_lcssa = $147;
  $q_sroa_0_1_lcssa = $149;
  $r_sroa_1_1_lcssa = $r_sroa_1_4_extract_trunc;
  $r_sroa_0_1_lcssa = $r_sroa_0_0_extract_trunc;
  $carry_0_lcssa$1 = 0;
  $carry_0_lcssa$0 = $152;
 }
 $q_sroa_0_0_insert_ext75$0 = $q_sroa_0_1_lcssa;
 $q_sroa_0_0_insert_ext75$1 = 0;
 $q_sroa_0_0_insert_insert77$1 = $q_sroa_1_1_lcssa | $q_sroa_0_0_insert_ext75$1;
 if (($rem | 0) != 0) {
  SAFE_HEAP_STORE($rem | 0, 0 | $r_sroa_0_1_lcssa | 0, 4);
  SAFE_HEAP_STORE($rem + 4 | 0, $r_sroa_1_1_lcssa | 0 | 0, 4);
 }
 $_0$1 = (0 | $q_sroa_0_0_insert_ext75$0) >>> 31 | $q_sroa_0_0_insert_insert77$1 << 1 | ($q_sroa_0_0_insert_ext75$1 << 1 | $q_sroa_0_0_insert_ext75$0 >>> 31) & 0 | $carry_0_lcssa$1;
 $_0$0 = ($q_sroa_0_0_insert_ext75$0 << 1 | 0 >>> 31) & -2 | $carry_0_lcssa$0;
 return (tempRet0 = $_0$1, $_0$0) | 0;
}

function _sjf_string_add($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $100 = 0, $101 = 0, $102 = 0, $103 = 0, $104 = 0, $105 = 0, $106 = 0, $107 = 0, $108 = 0, $109 = 0, $11 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0, $117 = 0;
 var $118 = 0, $119 = 0, $12 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $126 = 0, $127 = 0, $128 = 0, $129 = 0, $13 = 0, $130 = 0, $131 = 0, $132 = 0, $133 = 0, $134 = 0, $135 = 0;
 var $136 = 0, $137 = 0, $138 = 0, $139 = 0, $14 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0;
 var $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0;
 var $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0;
 var $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0;
 var $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0;
 var $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, $vararg_buffer = 0, $vararg_buffer2 = 0, $vararg_ptr1 = 0, $vararg_ptr5 = 0, $vararg_ptr6 = 0, $vararg_ptr7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 128 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(128 | 0);
 $vararg_buffer2 = sp + 8 | 0;
 $vararg_buffer = sp;
 $24 = sp + 48 | 0;
 $30 = sp + 124 | 0;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $32 = $4;
 $33 = $32 + 8 | 0;
 $34 = SAFE_HEAP_LOAD($33 | 0, 4, 0) | 0 | 0;
 $6 = $34;
 $35 = $6;
 $36 = ($35 | 0) > 0;
 $37 = $36 & 1;
 $7 = $37;
 $38 = $7;
 $39 = $38 & 1;
 if (!$39) {
  $145 = $3;
  $146 = SAFE_HEAP_LOAD($145 | 0, 4, 0) | 0 | 0;
  $147 = $146 + 1 | 0;
  SAFE_HEAP_STORE($145 | 0, $147 | 0, 4);
  $148 = $3;
  $149 = $5;
  SAFE_HEAP_STORE($149 | 0, $148 | 0, 4);
  STACKTOP = sp;
  return;
 }
 $40 = $3;
 $41 = $40 + 8 | 0;
 $42 = SAFE_HEAP_LOAD($41 | 0, 4, 0) | 0 | 0;
 $11 = $42;
 $43 = $4;
 $44 = $43 + 8 | 0;
 $45 = SAFE_HEAP_LOAD($44 | 0, 4, 0) | 0 | 0;
 $12 = $45;
 $46 = $11;
 $47 = $12;
 $48 = $46 + $47 | 0;
 $18 = $48;
 $49 = $18;
 $50 = $49 + 1 | 0;
 $19 = $50;
 $51 = $3;
 $52 = $51 + 12 | 0;
 $53 = SAFE_HEAP_LOAD($52 | 0, 4, 0) | 0 | 0;
 $13 = $53;
 $54 = $13;
 $55 = $54 + 4 | 0;
 $56 = SAFE_HEAP_LOAD($55 | 0, 4, 0) | 0 | 0;
 $14 = $56;
 $57 = $19;
 $58 = $14;
 $59 = ($57 | 0) > ($58 | 0);
 $60 = $59 & 1;
 $20 = $60;
 $61 = $20;
 $62 = $61 & 1;
 if ($62) {
  $63 = $3;
  $64 = $63 + 12 | 0;
  $65 = SAFE_HEAP_LOAD($64 | 0, 4, 0) | 0 | 0;
  $66 = $65 + 4 | 0;
  $67 = SAFE_HEAP_LOAD($66 | 0, 4, 0) | 0 | 0;
  $68 = $4;
  $69 = $68 + 8 | 0;
  $70 = SAFE_HEAP_LOAD($69 | 0, 4, 0) | 0 | 0;
  SAFE_HEAP_STORE($vararg_buffer | 0, $67 | 0, 4);
  $vararg_ptr1 = $vararg_buffer + 4 | 0;
  SAFE_HEAP_STORE($vararg_ptr1 | 0, $70 | 0, 4);
  _printf(600, $vararg_buffer) | 0;
  $71 = $3;
  $72 = $71 + 12 | 0;
  $73 = SAFE_HEAP_LOAD($72 | 0, 4, 0) | 0 | 0;
  $22 = $73;
  SAFE_HEAP_STORE($24 | 0, 0 | 0, 4);
  $74 = $3;
  $75 = $74 + 8 | 0;
  $76 = SAFE_HEAP_LOAD($75 | 0, 4, 0) | 0 | 0;
  $23 = $76;
  $77 = $4;
  $78 = $77 + 8 | 0;
  $79 = SAFE_HEAP_LOAD($78 | 0, 4, 0) | 0 | 0;
  $21 = $79;
  $80 = $23;
  $81 = $21;
  $82 = $80 + $81 | 0;
  $25 = $82;
  $83 = $25;
  $84 = $83 + 1 | 0;
  $26 = $84;
  $85 = $22;
  $86 = $26;
  _sjf_array_char_grow($85, $86, $24);
  $87 = SAFE_HEAP_LOAD($24 | 0, 4, 0) | 0 | 0;
  $88 = SAFE_HEAP_LOAD($87 | 0, 4, 0) | 0 | 0;
  $89 = $88 + -1 | 0;
  SAFE_HEAP_STORE($87 | 0, $89 | 0, 4);
  $90 = SAFE_HEAP_LOAD($24 | 0, 4, 0) | 0 | 0;
  $91 = SAFE_HEAP_LOAD($90 | 0, 4, 0) | 0 | 0;
  $92 = ($91 | 0) <= 0;
  if ($92) {
   $93 = SAFE_HEAP_LOAD($24 | 0, 4, 0) | 0 | 0;
   _sjf_array_char_destroy($93);
   $94 = SAFE_HEAP_LOAD($24 | 0, 4, 0) | 0 | 0;
   _free($94);
  }
 }
 $15 = 0;
 $95 = $4;
 $96 = $95 + 8 | 0;
 $97 = SAFE_HEAP_LOAD($96 | 0, 4, 0) | 0 | 0;
 $8 = $97;
 $98 = $8;
 $16 = $98;
 while (1) {
  $99 = $15;
  $100 = $16;
  $101 = ($99 | 0) < ($100 | 0);
  $102 = $3;
  if (!$101) {
   break;
  }
  $103 = $102 + 8 | 0;
  $104 = SAFE_HEAP_LOAD($103 | 0, 4, 0) | 0 | 0;
  $105 = $3;
  $106 = $105 + 12 | 0;
  $107 = SAFE_HEAP_LOAD($106 | 0, 4, 0) | 0 | 0;
  $108 = $107 + 4 | 0;
  $109 = SAFE_HEAP_LOAD($108 | 0, 4, 0) | 0 | 0;
  $110 = $15;
  $111 = $4;
  $112 = $111 + 12 | 0;
  $113 = SAFE_HEAP_LOAD($112 | 0, 4, 0) | 0 | 0;
  $114 = $113 + 4 | 0;
  $115 = SAFE_HEAP_LOAD($114 | 0, 4, 0) | 0 | 0;
  SAFE_HEAP_STORE($vararg_buffer2 | 0, $104 | 0, 4);
  $vararg_ptr5 = $vararg_buffer2 + 4 | 0;
  SAFE_HEAP_STORE($vararg_ptr5 | 0, $109 | 0, 4);
  $vararg_ptr6 = $vararg_buffer2 + 8 | 0;
  SAFE_HEAP_STORE($vararg_ptr6 | 0, $110 | 0, 4);
  $vararg_ptr7 = $vararg_buffer2 + 12 | 0;
  SAFE_HEAP_STORE($vararg_ptr7 | 0, $115 | 0, 4);
  _printf(619, $vararg_buffer2) | 0;
  $116 = $3;
  $117 = $116 + 12 | 0;
  $118 = SAFE_HEAP_LOAD($117 | 0, 4, 0) | 0 | 0;
  $27 = $118;
  $119 = $3;
  $120 = $119 + 8 | 0;
  $121 = SAFE_HEAP_LOAD($120 | 0, 4, 0) | 0 | 0;
  $28 = $121;
  SAFE_HEAP_STORE($30 >> 0 | 0, 0 | 0, 1);
  $122 = $4;
  $123 = $15;
  _sjf_string_getAt($122, $123, $30);
  $124 = $27;
  $125 = $28;
  $126 = SAFE_HEAP_LOAD($30 >> 0 | 0, 1, 0) | 0 | 0;
  _sjf_array_char_setAt($124, $125, $126);
  $127 = $3;
  $128 = $127 + 8 | 0;
  $129 = SAFE_HEAP_LOAD($128 | 0, 4, 0) | 0 | 0;
  $29 = $129;
  $130 = $29;
  $131 = $130 + 1 | 0;
  $31 = $131;
  $132 = $31;
  $133 = $3;
  $134 = $133 + 8 | 0;
  SAFE_HEAP_STORE($134 | 0, $132 | 0, 4);
  $135 = $15;
  $136 = $135 + 1 | 0;
  $15 = $136;
 }
 $137 = $102 + 12 | 0;
 $138 = SAFE_HEAP_LOAD($137 | 0, 4, 0) | 0 | 0;
 $9 = $138;
 $139 = $3;
 $140 = $139 + 8 | 0;
 $141 = SAFE_HEAP_LOAD($140 | 0, 4, 0) | 0 | 0;
 $10 = $141;
 $17 = 0;
 $142 = $9;
 $143 = $10;
 $144 = $17;
 _sjf_array_char_setAt($142, $143, $144);
 $145 = $3;
 $146 = SAFE_HEAP_LOAD($145 | 0, 4, 0) | 0 | 0;
 $147 = $146 + 1 | 0;
 SAFE_HEAP_STORE($145 | 0, $147 | 0, 4);
 $148 = $3;
 $149 = $5;
 SAFE_HEAP_STORE($149 | 0, $148 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_timerElement_toHTML($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0;
 var $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0;
 var $65 = 0, $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0;
 var $83 = 0, $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, $92 = 0, $93 = 0, $94 = 0, $95 = 0, $96 = 0, $97 = 0, $98 = 0, $99 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(48 | 0);
 $8 = sp + 16 | 0;
 $9 = sp + 12 | 0;
 $10 = sp + 8 | 0;
 $11 = sp + 4 | 0;
 $2 = $0;
 $3 = $1;
 $13 = $2;
 $14 = $13 + 4 | 0;
 $15 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $12 = $15;
 $16 = $12;
 $17 = $16 + 4 | 0;
 $18 = SAFE_HEAP_LOAD($17 | 0, 4, 0) | 0 | 0;
 $6 = $18;
 SAFE_HEAP_STORE($8 | 0, 0 | 0, 4);
 $19 = $2;
 $20 = $19 + 8 | 0;
 $21 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
 $7 = $21;
 $22 = $6;
 $23 = $7;
 _sjf_anon4_i32toString($22, $23, $8);
 $24 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
 $4 = $24;
 $25 = $4;
 $26 = SAFE_HEAP_LOAD($25 | 0, 4, 0) | 0 | 0;
 $27 = $26 + 1 | 0;
 SAFE_HEAP_STORE($25 | 0, $27 | 0, 4);
 $28 = _malloc(16) | 0;
 SAFE_HEAP_STORE($10 | 0, $28 | 0, 4);
 $29 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($29 | 0, 1 | 0, 4);
 $30 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $31 = $30 + 4 | 0;
 SAFE_HEAP_STORE($31 | 0, 4 | 0, 4);
 $32 = SAFE_HEAP_LOAD(3 * 4 | 0, 4, 0) | 0 | 0;
 $33 = $32;
 $34 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $35 = $34 + 8 | 0;
 SAFE_HEAP_STORE($35 | 0, $33 | 0, 4);
 $36 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $37 = $36 + 12 | 0;
 SAFE_HEAP_STORE($37 >> 0 | 0, 0 | 0, 1);
 $38 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 _sjf_array_char($38, $10);
 $39 = _malloc(16) | 0;
 SAFE_HEAP_STORE($11 | 0, $39 | 0, 4);
 $40 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($40 | 0, 1 | 0, 4);
 $41 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $42 = $41 + 8 | 0;
 SAFE_HEAP_STORE($42 | 0, 3 | 0, 4);
 $43 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $44 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $45 = $44 + 12 | 0;
 SAFE_HEAP_STORE($45 | 0, $43 | 0, 4);
 $46 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $47 = $46 + 12 | 0;
 $48 = SAFE_HEAP_LOAD($47 | 0, 4, 0) | 0 | 0;
 $49 = SAFE_HEAP_LOAD($48 | 0, 4, 0) | 0 | 0;
 $50 = $49 + 1 | 0;
 SAFE_HEAP_STORE($48 | 0, $50 | 0, 4);
 $51 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 _sjf_string($51, $11);
 $52 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $5 = $52;
 $53 = $5;
 $54 = SAFE_HEAP_LOAD($53 | 0, 4, 0) | 0 | 0;
 $55 = $54 + 1 | 0;
 SAFE_HEAP_STORE($53 | 0, $55 | 0, 4);
 SAFE_HEAP_STORE($9 | 0, 0 | 0, 4);
 $56 = $5;
 $57 = $4;
 _sjf_string_add($56, $57, $9);
 $58 = $4;
 $59 = SAFE_HEAP_LOAD($58 | 0, 4, 0) | 0 | 0;
 $60 = $59 + -1 | 0;
 SAFE_HEAP_STORE($58 | 0, $60 | 0, 4);
 $61 = $4;
 $62 = SAFE_HEAP_LOAD($61 | 0, 4, 0) | 0 | 0;
 $63 = ($62 | 0) <= 0;
 if ($63) {
  $64 = $4;
  _sjf_string_destroy($64);
  $65 = $4;
  _free($65);
 }
 $66 = $5;
 $67 = SAFE_HEAP_LOAD($66 | 0, 4, 0) | 0 | 0;
 $68 = $67 + -1 | 0;
 SAFE_HEAP_STORE($66 | 0, $68 | 0, 4);
 $69 = $5;
 $70 = SAFE_HEAP_LOAD($69 | 0, 4, 0) | 0 | 0;
 $71 = ($70 | 0) <= 0;
 if ($71) {
  $72 = $5;
  _sjf_string_destroy($72);
  $73 = $5;
  _free($73);
 }
 $74 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
 $75 = SAFE_HEAP_LOAD($74 | 0, 4, 0) | 0 | 0;
 $76 = $75 + -1 | 0;
 SAFE_HEAP_STORE($74 | 0, $76 | 0, 4);
 $77 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
 $78 = SAFE_HEAP_LOAD($77 | 0, 4, 0) | 0 | 0;
 $79 = ($78 | 0) <= 0;
 if ($79) {
  $80 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
  _sjf_string_destroy($80);
  $81 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
  _free($81);
 }
 $82 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $83 = SAFE_HEAP_LOAD($82 | 0, 4, 0) | 0 | 0;
 $84 = $83 + -1 | 0;
 SAFE_HEAP_STORE($82 | 0, $84 | 0, 4);
 $85 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $86 = SAFE_HEAP_LOAD($85 | 0, 4, 0) | 0 | 0;
 $87 = ($86 | 0) <= 0;
 if ($87) {
  $88 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
  _sjf_array_char_destroy($88);
  $89 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
  _free($89);
 }
 $90 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $91 = SAFE_HEAP_LOAD($90 | 0, 4, 0) | 0 | 0;
 $92 = $91 + -1 | 0;
 SAFE_HEAP_STORE($90 | 0, $92 | 0, 4);
 $93 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $94 = SAFE_HEAP_LOAD($93 | 0, 4, 0) | 0 | 0;
 $95 = ($94 | 0) <= 0;
 if (!$95) {
  $98 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
  $99 = $3;
  SAFE_HEAP_STORE($99 | 0, $98 | 0, 4);
  STACKTOP = sp;
  return;
 }
 $96 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 _sjf_string_destroy($96);
 $97 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 _free($97);
 $98 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $99 = $3;
 SAFE_HEAP_STORE($99 | 0, $98 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_anon4_i32toString($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0;
 var $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0;
 var $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0;
 var $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $81 = 0, $82 = 0, $83 = 0;
 var $84 = 0, $85 = 0, $86 = 0, $87 = 0, $88 = 0, $89 = 0, $9 = 0, $90 = 0, $91 = 0, dest = 0, label = 0, sp = 0, stop = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 80 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(80 | 0);
 $10 = sp + 8 | 0;
 $11 = sp + 4 | 0;
 $12 = sp + 40 | 0;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $6 = 0;
 $8 = 0;
 $14 = $8;
 $7 = $14;
 dest = $12;
 stop = dest + 32 | 0;
 do {
  SAFE_HEAP_STORE(dest >> 0 | 0, 0 | 0 | 0, 1);
  dest = dest + 1 | 0;
 } while ((dest | 0) < (stop | 0));
 $13 = 30;
 while (1) {
  $15 = $4;
  $16 = ($15 | 0) % 10 & -1;
  $17 = 439 + $16 | 0;
  $18 = SAFE_HEAP_LOAD($17 >> 0 | 0, 1, 0) | 0 | 0;
  $19 = $13;
  $20 = $12 + $19 | 0;
  SAFE_HEAP_STORE($20 >> 0 | 0, $18 | 0, 1);
  $21 = $13;
  $22 = $21 + -1 | 0;
  $13 = $22;
  $23 = $4;
  $24 = ($23 | 0) / 10 & -1;
  $4 = $24;
  $25 = $4;
  $26 = ($25 | 0) != 0;
  $27 = $13;
  $28 = ($27 | 0) != 0;
  $29 = $26 ? $28 : 0;
  if (!$29) {
   break;
  }
 }
 $30 = $13;
 $31 = 30 - $30 | 0;
 $6 = $31;
 $32 = $6;
 $33 = $32 + 1 | 0;
 $34 = $33;
 $35 = _malloc($34) | 0;
 $36 = $35;
 $7 = $36;
 $37 = $7;
 $38 = $37;
 $39 = $13;
 $40 = $39 + 1 | 0;
 $41 = $12 + $40 | 0;
 $42 = $6;
 $43 = $42 + 1 | 0;
 _memcpy($38 | 0, $41 | 0, $43 | 0) | 0;
 $44 = $6;
 $45 = $44 + 1 | 0;
 $9 = $45;
 $46 = _malloc(16) | 0;
 SAFE_HEAP_STORE($10 | 0, $46 | 0, 4);
 $47 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($47 | 0, 1 | 0, 4);
 $48 = $9;
 $49 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $50 = $49 + 4 | 0;
 SAFE_HEAP_STORE($50 | 0, $48 | 0, 4);
 $51 = $7;
 $52 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $53 = $52 + 8 | 0;
 SAFE_HEAP_STORE($53 | 0, $51 | 0, 4);
 $54 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $55 = $54 + 12 | 0;
 SAFE_HEAP_STORE($55 >> 0 | 0, 0 | 0, 1);
 $56 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 _sjf_array_char($56, $10);
 $57 = _malloc(16) | 0;
 SAFE_HEAP_STORE($11 | 0, $57 | 0, 4);
 $58 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($58 | 0, 1 | 0, 4);
 $59 = $6;
 $60 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $61 = $60 + 8 | 0;
 SAFE_HEAP_STORE($61 | 0, $59 | 0, 4);
 $62 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $63 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $64 = $63 + 12 | 0;
 SAFE_HEAP_STORE($64 | 0, $62 | 0, 4);
 $65 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $66 = $65 + 12 | 0;
 $67 = SAFE_HEAP_LOAD($66 | 0, 4, 0) | 0 | 0;
 $68 = SAFE_HEAP_LOAD($67 | 0, 4, 0) | 0 | 0;
 $69 = $68 + 1 | 0;
 SAFE_HEAP_STORE($67 | 0, $69 | 0, 4);
 $70 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 _sjf_string($70, $11);
 $71 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $72 = SAFE_HEAP_LOAD($71 | 0, 4, 0) | 0 | 0;
 $73 = $72 + 1 | 0;
 SAFE_HEAP_STORE($71 | 0, $73 | 0, 4);
 $74 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $75 = SAFE_HEAP_LOAD($74 | 0, 4, 0) | 0 | 0;
 $76 = $75 + -1 | 0;
 SAFE_HEAP_STORE($74 | 0, $76 | 0, 4);
 $77 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $78 = SAFE_HEAP_LOAD($77 | 0, 4, 0) | 0 | 0;
 $79 = ($78 | 0) <= 0;
 if ($79) {
  $80 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
  _sjf_array_char_destroy($80);
  $81 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
  _free($81);
 }
 $82 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $83 = SAFE_HEAP_LOAD($82 | 0, 4, 0) | 0 | 0;
 $84 = $83 + -1 | 0;
 SAFE_HEAP_STORE($82 | 0, $84 | 0, 4);
 $85 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $86 = SAFE_HEAP_LOAD($85 | 0, 4, 0) | 0 | 0;
 $87 = ($86 | 0) <= 0;
 if (!$87) {
  $90 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
  $91 = $5;
  SAFE_HEAP_STORE($91 | 0, $90 | 0, 4);
  STACKTOP = sp;
  return;
 }
 $88 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 _sjf_string_destroy($88);
 $89 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 _free($89);
 $90 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $91 = $5;
 SAFE_HEAP_STORE($91 | 0, $90 | 0, 4);
 STACKTOP = sp;
 return;
}

function ___stdio_write($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$0 = 0, $$04756 = 0, $$04855 = 0, $$04954 = 0, $$051 = 0, $$1 = 0, $$150 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0;
 var $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0;
 var $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, $vararg_buffer3 = 0, $vararg_ptr1 = 0, $vararg_ptr2 = 0, $vararg_ptr6 = 0;
 var $vararg_ptr7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(48 | 0);
 $vararg_buffer3 = sp + 16 | 0;
 $vararg_buffer = sp;
 $3 = sp + 32 | 0;
 $4 = $0 + 28 | 0;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($3 | 0, $5 | 0, 4);
 $6 = $3 + 4 | 0;
 $7 = $0 + 20 | 0;
 $8 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
 $9 = $8 - $5 | 0;
 SAFE_HEAP_STORE($6 | 0, $9 | 0, 4);
 $10 = $3 + 8 | 0;
 SAFE_HEAP_STORE($10 | 0, $1 | 0, 4);
 $11 = $3 + 12 | 0;
 SAFE_HEAP_STORE($11 | 0, $2 | 0, 4);
 $12 = $9 + $2 | 0;
 $13 = $0 + 60 | 0;
 $14 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $15 = $3;
 SAFE_HEAP_STORE($vararg_buffer | 0, $14 | 0, 4);
 $vararg_ptr1 = $vararg_buffer + 4 | 0;
 SAFE_HEAP_STORE($vararg_ptr1 | 0, $15 | 0, 4);
 $vararg_ptr2 = $vararg_buffer + 8 | 0;
 SAFE_HEAP_STORE($vararg_ptr2 | 0, 2 | 0, 4);
 $16 = ___syscall146(146, $vararg_buffer | 0) | 0;
 $17 = ___syscall_ret($16) | 0;
 $18 = ($12 | 0) == ($17 | 0);
 L1 : do {
  if ($18) {
   label = 3;
  } else {
   $$04756 = 2;
   $$04855 = $12;
   $$04954 = $3;
   $26 = $17;
   while (1) {
    $25 = ($26 | 0) < 0;
    if ($25) {
     break;
    }
    $34 = $$04855 - $26 | 0;
    $35 = $$04954 + 4 | 0;
    $36 = SAFE_HEAP_LOAD($35 | 0, 4, 0) | 0 | 0;
    $37 = $26 >>> 0 > $36 >>> 0;
    $38 = $$04954 + 8 | 0;
    $$150 = $37 ? $38 : $$04954;
    $39 = $37 << 31 >> 31;
    $$1 = $39 + $$04756 | 0;
    $40 = $37 ? $36 : 0;
    $$0 = $26 - $40 | 0;
    $41 = SAFE_HEAP_LOAD($$150 | 0, 4, 0) | 0 | 0;
    $42 = $41 + $$0 | 0;
    SAFE_HEAP_STORE($$150 | 0, $42 | 0, 4);
    $43 = $$150 + 4 | 0;
    $44 = SAFE_HEAP_LOAD($43 | 0, 4, 0) | 0 | 0;
    $45 = $44 - $$0 | 0;
    SAFE_HEAP_STORE($43 | 0, $45 | 0, 4);
    $46 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
    $47 = $$150;
    SAFE_HEAP_STORE($vararg_buffer3 | 0, $46 | 0, 4);
    $vararg_ptr6 = $vararg_buffer3 + 4 | 0;
    SAFE_HEAP_STORE($vararg_ptr6 | 0, $47 | 0, 4);
    $vararg_ptr7 = $vararg_buffer3 + 8 | 0;
    SAFE_HEAP_STORE($vararg_ptr7 | 0, $$1 | 0, 4);
    $48 = ___syscall146(146, $vararg_buffer3 | 0) | 0;
    $49 = ___syscall_ret($48) | 0;
    $50 = ($34 | 0) == ($49 | 0);
    if ($50) {
     label = 3;
     break L1;
    } else {
     $$04756 = $$1;
     $$04855 = $34;
     $$04954 = $$150;
     $26 = $49;
    }
   }
   $27 = $0 + 16 | 0;
   SAFE_HEAP_STORE($27 | 0, 0 | 0, 4);
   SAFE_HEAP_STORE($4 | 0, 0 | 0, 4);
   SAFE_HEAP_STORE($7 | 0, 0 | 0, 4);
   $28 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
   $29 = $28 | 32;
   SAFE_HEAP_STORE($0 | 0, $29 | 0, 4);
   $30 = ($$04756 | 0) == 2;
   if ($30) {
    $$051 = 0;
   } else {
    $31 = $$04954 + 4 | 0;
    $32 = SAFE_HEAP_LOAD($31 | 0, 4, 0) | 0 | 0;
    $33 = $2 - $32 | 0;
    $$051 = $33;
   }
  }
 } while (0);
 if ((label | 0) == 3) {
  $19 = $0 + 44 | 0;
  $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
  $21 = $0 + 48 | 0;
  $22 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
  $23 = $20 + $22 | 0;
  $24 = $0 + 16 | 0;
  SAFE_HEAP_STORE($24 | 0, $23 | 0, 4);
  SAFE_HEAP_STORE($4 | 0, $20 | 0, 4);
  SAFE_HEAP_STORE($7 | 0, $20 | 0, 4);
  $$051 = $2;
 }
 STACKTOP = sp;
 return $$051 | 0;
}

function _sjf_array_char_grow($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0;
 var $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0;
 var $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0, $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $65 = 0;
 var $66 = 0, $67 = 0, $68 = 0, $69 = 0, $7 = 0, $70 = 0, $71 = 0, $72 = 0, $73 = 0, $74 = 0, $75 = 0, $76 = 0, $77 = 0, $78 = 0, $79 = 0, $8 = 0, $80 = 0, $9 = 0, $vararg_buffer = 0, $vararg_buffer2 = 0;
 var $vararg_buffer4 = 0, $vararg_ptr1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 48 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(48 | 0);
 $vararg_buffer4 = sp + 16 | 0;
 $vararg_buffer2 = sp + 8 | 0;
 $vararg_buffer = sp;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $7 = $3;
 $8 = $7 + 4 | 0;
 $9 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
 $10 = $4;
 $11 = ($9 | 0) != ($10 | 0);
 if (!$11) {
  $79 = $3;
  $80 = $5;
  SAFE_HEAP_STORE($80 | 0, $79 | 0, 4);
  STACKTOP = sp;
  return;
 }
 $12 = $4;
 $13 = $3;
 $14 = $13 + 4 | 0;
 $15 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $16 = ($12 | 0) < ($15 | 0);
 if ($16) {
  $17 = $4;
  $18 = $3;
  $19 = $18 + 4 | 0;
  $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
  SAFE_HEAP_STORE($vararg_buffer | 0, $17 | 0, 4);
  $vararg_ptr1 = $vararg_buffer + 4 | 0;
  SAFE_HEAP_STORE($vararg_ptr1 | 0, $20 | 0, 4);
  _printf(493, $vararg_buffer) | 0;
  _exit(-1);
 }
 $21 = $3;
 $22 = $21 + 12 | 0;
 $23 = SAFE_HEAP_LOAD($22 >> 0 | 0, 1, 0) | 0 | 0;
 $24 = $23 & 1;
 $25 = $3;
 do {
  if ($24) {
   $26 = $25 + 12 | 0;
   SAFE_HEAP_STORE($26 >> 0 | 0, 0 | 0, 1);
   $27 = $3;
   $28 = $27 + 8 | 0;
   $29 = SAFE_HEAP_LOAD($28 | 0, 4, 0) | 0 | 0;
   $30 = $29;
   $6 = $30;
   $31 = $4;
   $32 = $31;
   $33 = _calloc($32, 1) | 0;
   $34 = $33;
   $35 = $3;
   $36 = $35 + 8 | 0;
   SAFE_HEAP_STORE($36 | 0, $34 | 0, 4);
   $37 = $3;
   $38 = $37 + 8 | 0;
   $39 = SAFE_HEAP_LOAD($38 | 0, 4, 0) | 0 | 0;
   $40 = ($39 | 0) != 0;
   if ($40) {
    $41 = $3;
    $42 = $41 + 8 | 0;
    $43 = SAFE_HEAP_LOAD($42 | 0, 4, 0) | 0 | 0;
    $44 = $43;
    $45 = $6;
    $46 = $3;
    $47 = $46 + 4 | 0;
    $48 = SAFE_HEAP_LOAD($47 | 0, 4, 0) | 0 | 0;
    $49 = $48;
    _memcpy($44 | 0, $45 | 0, $49 | 0) | 0;
    break;
   } else {
    _printf(450, $vararg_buffer2) | 0;
    _exit(-1);
   }
  } else {
   $50 = $25 + 8 | 0;
   $51 = SAFE_HEAP_LOAD($50 | 0, 4, 0) | 0 | 0;
   $52 = $51;
   $53 = $4;
   $54 = $53;
   $55 = _realloc($52, $54) | 0;
   $56 = $55;
   $57 = $3;
   $58 = $57 + 8 | 0;
   SAFE_HEAP_STORE($58 | 0, $56 | 0, 4);
   $59 = $3;
   $60 = $59 + 8 | 0;
   $61 = SAFE_HEAP_LOAD($60 | 0, 4, 0) | 0 | 0;
   $62 = ($61 | 0) != 0;
   if ($62) {
    $63 = $3;
    $64 = $63 + 8 | 0;
    $65 = SAFE_HEAP_LOAD($64 | 0, 4, 0) | 0 | 0;
    $66 = $65;
    $67 = $3;
    $68 = $67 + 4 | 0;
    $69 = SAFE_HEAP_LOAD($68 | 0, 4, 0) | 0 | 0;
    $70 = $66 + $69 | 0;
    $71 = $4;
    $72 = $3;
    $73 = $72 + 4 | 0;
    $74 = SAFE_HEAP_LOAD($73 | 0, 4, 0) | 0 | 0;
    $75 = $71 - $74 | 0;
    _memset($70 | 0, 0, $75 | 0) | 0;
    break;
   } else {
    _printf(450, $vararg_buffer4) | 0;
    _exit(-1);
   }
  }
 } while (0);
 $76 = $4;
 $77 = $3;
 $78 = $77 + 4 | 0;
 SAFE_HEAP_STORE($78 | 0, $76 | 0, 4);
 $79 = $3;
 $80 = $5;
 SAFE_HEAP_STORE($80 | 0, $79 | 0, 4);
 STACKTOP = sp;
 return;
}

function _memchr($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$0$lcssa = 0, $$035$lcssa = 0, $$035$lcssa65 = 0, $$03555 = 0, $$036$lcssa = 0, $$036$lcssa64 = 0, $$03654 = 0, $$046 = 0, $$137$lcssa = 0, $$13745 = 0, $$140 = 0, $$2 = 0, $$23839 = 0, $$3 = 0, $$lcssa = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0;
 var $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0;
 var $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $or$cond53 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = $1 & 255;
 $4 = $0;
 $5 = $4 & 3;
 $6 = ($5 | 0) != 0;
 $7 = ($2 | 0) != 0;
 $or$cond53 = $7 & $6;
 L1 : do {
  if ($or$cond53) {
   $8 = $1 & 255;
   $$03555 = $0;
   $$03654 = $2;
   while (1) {
    $9 = SAFE_HEAP_LOAD($$03555 >> 0 | 0, 1, 0) | 0 | 0;
    $10 = $9 << 24 >> 24 == $8 << 24 >> 24;
    if ($10) {
     $$035$lcssa65 = $$03555;
     $$036$lcssa64 = $$03654;
     label = 6;
     break L1;
    }
    $11 = $$03555 + 1 | 0;
    $12 = $$03654 + -1 | 0;
    $13 = $11;
    $14 = $13 & 3;
    $15 = ($14 | 0) != 0;
    $16 = ($12 | 0) != 0;
    $or$cond = $16 & $15;
    if ($or$cond) {
     $$03555 = $11;
     $$03654 = $12;
    } else {
     $$035$lcssa = $11;
     $$036$lcssa = $12;
     $$lcssa = $16;
     label = 5;
     break;
    }
   }
  } else {
   $$035$lcssa = $0;
   $$036$lcssa = $2;
   $$lcssa = $7;
   label = 5;
  }
 } while (0);
 if ((label | 0) == 5) {
  if ($$lcssa) {
   $$035$lcssa65 = $$035$lcssa;
   $$036$lcssa64 = $$036$lcssa;
   label = 6;
  } else {
   $$2 = $$035$lcssa;
   $$3 = 0;
  }
 }
 L8 : do {
  if ((label | 0) == 6) {
   $17 = SAFE_HEAP_LOAD($$035$lcssa65 >> 0 | 0, 1, 0) | 0 | 0;
   $18 = $1 & 255;
   $19 = $17 << 24 >> 24 == $18 << 24 >> 24;
   if ($19) {
    $$2 = $$035$lcssa65;
    $$3 = $$036$lcssa64;
   } else {
    $20 = Math_imul($3, 16843009) | 0;
    $21 = $$036$lcssa64 >>> 0 > 3;
    L11 : do {
     if ($21) {
      $$046 = $$035$lcssa65;
      $$13745 = $$036$lcssa64;
      while (1) {
       $22 = SAFE_HEAP_LOAD($$046 | 0, 4, 0) | 0 | 0;
       $23 = $22 ^ $20;
       $24 = $23 + -16843009 | 0;
       $25 = $23 & -2139062144;
       $26 = $25 ^ -2139062144;
       $27 = $26 & $24;
       $28 = ($27 | 0) == 0;
       if (!$28) {
        break;
       }
       $29 = $$046 + 4 | 0;
       $30 = $$13745 + -4 | 0;
       $31 = $30 >>> 0 > 3;
       if ($31) {
        $$046 = $29;
        $$13745 = $30;
       } else {
        $$0$lcssa = $29;
        $$137$lcssa = $30;
        label = 11;
        break L11;
       }
      }
      $$140 = $$046;
      $$23839 = $$13745;
     } else {
      $$0$lcssa = $$035$lcssa65;
      $$137$lcssa = $$036$lcssa64;
      label = 11;
     }
    } while (0);
    if ((label | 0) == 11) {
     $32 = ($$137$lcssa | 0) == 0;
     if ($32) {
      $$2 = $$0$lcssa;
      $$3 = 0;
      break;
     } else {
      $$140 = $$0$lcssa;
      $$23839 = $$137$lcssa;
     }
    }
    while (1) {
     $33 = SAFE_HEAP_LOAD($$140 >> 0 | 0, 1, 0) | 0 | 0;
     $34 = $33 << 24 >> 24 == $18 << 24 >> 24;
     if ($34) {
      $$2 = $$140;
      $$3 = $$23839;
      break L8;
     }
     $35 = $$140 + 1 | 0;
     $36 = $$23839 + -1 | 0;
     $37 = ($36 | 0) == 0;
     if ($37) {
      $$2 = $35;
      $$3 = 0;
      break;
     } else {
      $$140 = $35;
      $$23839 = $36;
     }
    }
   }
  }
 } while (0);
 $38 = ($$3 | 0) != 0;
 $39 = $38 ? $$2 : 0;
 return $39 | 0;
}

function ___mo_lookup($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$ = 0, $$090 = 0, $$094 = 0, $$191 = 0, $$195 = 0, $$4 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0;
 var $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0;
 var $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $57 = 0, $58 = 0, $59 = 0, $6 = 0;
 var $60 = 0, $61 = 0, $62 = 0, $63 = 0, $64 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $or$cond102 = 0, $or$cond104 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
 $4 = $3 + 1794895138 | 0;
 $5 = $0 + 8 | 0;
 $6 = SAFE_HEAP_LOAD($5 | 0, 4, 0) | 0 | 0;
 $7 = _swapc($6, $4) | 0;
 $8 = $0 + 12 | 0;
 $9 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
 $10 = _swapc($9, $4) | 0;
 $11 = $0 + 16 | 0;
 $12 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $13 = _swapc($12, $4) | 0;
 $14 = $1 >>> 2;
 $15 = $7 >>> 0 < $14 >>> 0;
 L1 : do {
  if ($15) {
   $16 = $7 << 2;
   $17 = $1 - $16 | 0;
   $18 = $10 >>> 0 < $17 >>> 0;
   $19 = $13 >>> 0 < $17 >>> 0;
   $or$cond = $18 & $19;
   if ($or$cond) {
    $20 = $13 | $10;
    $21 = $20 & 3;
    $22 = ($21 | 0) == 0;
    if ($22) {
     $23 = $10 >>> 2;
     $24 = $13 >>> 2;
     $$090 = 0;
     $$094 = $7;
     while (1) {
      $25 = $$094 >>> 1;
      $26 = $$090 + $25 | 0;
      $27 = $26 << 1;
      $28 = $27 + $23 | 0;
      $29 = $0 + ($28 << 2) | 0;
      $30 = SAFE_HEAP_LOAD($29 | 0, 4, 0) | 0 | 0;
      $31 = _swapc($30, $4) | 0;
      $32 = $28 + 1 | 0;
      $33 = $0 + ($32 << 2) | 0;
      $34 = SAFE_HEAP_LOAD($33 | 0, 4, 0) | 0 | 0;
      $35 = _swapc($34, $4) | 0;
      $36 = $35 >>> 0 < $1 >>> 0;
      $37 = $1 - $35 | 0;
      $38 = $31 >>> 0 < $37 >>> 0;
      $or$cond102 = $36 & $38;
      if (!$or$cond102) {
       $$4 = 0;
       break L1;
      }
      $39 = $35 + $31 | 0;
      $40 = $0 + $39 | 0;
      $41 = SAFE_HEAP_LOAD($40 >> 0 | 0, 1, 0) | 0 | 0;
      $42 = $41 << 24 >> 24 == 0;
      if (!$42) {
       $$4 = 0;
       break L1;
      }
      $43 = $0 + $35 | 0;
      $44 = _strcmp($2, $43) | 0;
      $45 = ($44 | 0) == 0;
      if ($45) {
       break;
      }
      $62 = ($$094 | 0) == 1;
      $63 = ($44 | 0) < 0;
      $64 = $$094 - $25 | 0;
      $$195 = $63 ? $25 : $64;
      $$191 = $63 ? $$090 : $26;
      if ($62) {
       $$4 = 0;
       break L1;
      } else {
       $$090 = $$191;
       $$094 = $$195;
      }
     }
     $46 = $27 + $24 | 0;
     $47 = $0 + ($46 << 2) | 0;
     $48 = SAFE_HEAP_LOAD($47 | 0, 4, 0) | 0 | 0;
     $49 = _swapc($48, $4) | 0;
     $50 = $46 + 1 | 0;
     $51 = $0 + ($50 << 2) | 0;
     $52 = SAFE_HEAP_LOAD($51 | 0, 4, 0) | 0 | 0;
     $53 = _swapc($52, $4) | 0;
     $54 = $53 >>> 0 < $1 >>> 0;
     $55 = $1 - $53 | 0;
     $56 = $49 >>> 0 < $55 >>> 0;
     $or$cond104 = $54 & $56;
     if ($or$cond104) {
      $57 = $0 + $53 | 0;
      $58 = $53 + $49 | 0;
      $59 = $0 + $58 | 0;
      $60 = SAFE_HEAP_LOAD($59 >> 0 | 0, 1, 0) | 0 | 0;
      $61 = $60 << 24 >> 24 == 0;
      $$ = $61 ? $57 : 0;
      $$4 = $$;
     } else {
      $$4 = 0;
     }
    } else {
     $$4 = 0;
    }
   } else {
    $$4 = 0;
   }
  } else {
   $$4 = 0;
  }
 } while (0);
 return $$4 | 0;
}

function _wcrtomb($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$0 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0;
 var $47 = 0, $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $54 = 0, $55 = 0, $56 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $not$ = 0, $or$cond = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = ($0 | 0) == (0 | 0);
 do {
  if ($3) {
   $$0 = 1;
  } else {
   $4 = $1 >>> 0 < 128;
   if ($4) {
    $5 = $1 & 255;
    SAFE_HEAP_STORE($0 >> 0 | 0, $5 | 0, 1);
    $$0 = 1;
    break;
   }
   $6 = ___pthread_self_431() | 0;
   $7 = $6 + 188 | 0;
   $8 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
   $9 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
   $not$ = ($9 | 0) == (0 | 0);
   if ($not$) {
    $10 = $1 & -128;
    $11 = ($10 | 0) == 57216;
    if ($11) {
     $13 = $1 & 255;
     SAFE_HEAP_STORE($0 >> 0 | 0, $13 | 0, 1);
     $$0 = 1;
     break;
    } else {
     $12 = ___errno_location() | 0;
     SAFE_HEAP_STORE($12 | 0, 84 | 0, 4);
     $$0 = -1;
     break;
    }
   }
   $14 = $1 >>> 0 < 2048;
   if ($14) {
    $15 = $1 >>> 6;
    $16 = $15 | 192;
    $17 = $16 & 255;
    $18 = $0 + 1 | 0;
    SAFE_HEAP_STORE($0 >> 0 | 0, $17 | 0, 1);
    $19 = $1 & 63;
    $20 = $19 | 128;
    $21 = $20 & 255;
    SAFE_HEAP_STORE($18 >> 0 | 0, $21 | 0, 1);
    $$0 = 2;
    break;
   }
   $22 = $1 >>> 0 < 55296;
   $23 = $1 & -8192;
   $24 = ($23 | 0) == 57344;
   $or$cond = $22 | $24;
   if ($or$cond) {
    $25 = $1 >>> 12;
    $26 = $25 | 224;
    $27 = $26 & 255;
    $28 = $0 + 1 | 0;
    SAFE_HEAP_STORE($0 >> 0 | 0, $27 | 0, 1);
    $29 = $1 >>> 6;
    $30 = $29 & 63;
    $31 = $30 | 128;
    $32 = $31 & 255;
    $33 = $0 + 2 | 0;
    SAFE_HEAP_STORE($28 >> 0 | 0, $32 | 0, 1);
    $34 = $1 & 63;
    $35 = $34 | 128;
    $36 = $35 & 255;
    SAFE_HEAP_STORE($33 >> 0 | 0, $36 | 0, 1);
    $$0 = 3;
    break;
   }
   $37 = $1 + -65536 | 0;
   $38 = $37 >>> 0 < 1048576;
   if ($38) {
    $39 = $1 >>> 18;
    $40 = $39 | 240;
    $41 = $40 & 255;
    $42 = $0 + 1 | 0;
    SAFE_HEAP_STORE($0 >> 0 | 0, $41 | 0, 1);
    $43 = $1 >>> 12;
    $44 = $43 & 63;
    $45 = $44 | 128;
    $46 = $45 & 255;
    $47 = $0 + 2 | 0;
    SAFE_HEAP_STORE($42 >> 0 | 0, $46 | 0, 1);
    $48 = $1 >>> 6;
    $49 = $48 & 63;
    $50 = $49 | 128;
    $51 = $50 & 255;
    $52 = $0 + 3 | 0;
    SAFE_HEAP_STORE($47 >> 0 | 0, $51 | 0, 1);
    $53 = $1 & 63;
    $54 = $53 | 128;
    $55 = $54 & 255;
    SAFE_HEAP_STORE($52 >> 0 | 0, $55 | 0, 1);
    $$0 = 4;
    break;
   } else {
    $56 = ___errno_location() | 0;
    SAFE_HEAP_STORE($56 | 0, 84 | 0, 4);
    $$0 = -1;
    break;
   }
  }
 } while (0);
 return $$0 | 0;
}

function _vfprintf($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$ = 0, $$0 = 0, $$1 = 0, $$1$ = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0;
 var $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $5 = 0, $6 = 0, $7 = 0;
 var $8 = 0, $9 = 0, $vacopy_currentptr = 0, dest = 0, label = 0, sp = 0, stop = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 224 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(224 | 0);
 $3 = sp + 120 | 0;
 $4 = sp + 80 | 0;
 $5 = sp;
 $6 = sp + 136 | 0;
 dest = $4;
 stop = dest + 40 | 0;
 do {
  SAFE_HEAP_STORE(dest | 0, 0 | 0 | 0, 4);
  dest = dest + 4 | 0;
 } while ((dest | 0) < (stop | 0));
 $vacopy_currentptr = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
 SAFE_HEAP_STORE($3 | 0, $vacopy_currentptr | 0, 4);
 $7 = _printf_core(0, $1, $3, $5, $4) | 0;
 $8 = ($7 | 0) < 0;
 if ($8) {
  $$0 = -1;
 } else {
  $9 = $0 + 76 | 0;
  $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
  $11 = ($10 | 0) > -1;
  if ($11) {
   $12 = ___lockfile($0) | 0;
   $40 = $12;
  } else {
   $40 = 0;
  }
  $13 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
  $14 = $13 & 32;
  $15 = $0 + 74 | 0;
  $16 = SAFE_HEAP_LOAD($15 >> 0 | 0, 1, 0) | 0 | 0;
  $17 = $16 << 24 >> 24 < 1;
  if ($17) {
   $18 = $13 & -33;
   SAFE_HEAP_STORE($0 | 0, $18 | 0, 4);
  }
  $19 = $0 + 48 | 0;
  $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
  $21 = ($20 | 0) == 0;
  if ($21) {
   $23 = $0 + 44 | 0;
   $24 = SAFE_HEAP_LOAD($23 | 0, 4, 0) | 0 | 0;
   SAFE_HEAP_STORE($23 | 0, $6 | 0, 4);
   $25 = $0 + 28 | 0;
   SAFE_HEAP_STORE($25 | 0, $6 | 0, 4);
   $26 = $0 + 20 | 0;
   SAFE_HEAP_STORE($26 | 0, $6 | 0, 4);
   SAFE_HEAP_STORE($19 | 0, 80 | 0, 4);
   $27 = $6 + 80 | 0;
   $28 = $0 + 16 | 0;
   SAFE_HEAP_STORE($28 | 0, $27 | 0, 4);
   $29 = _printf_core($0, $1, $3, $5, $4) | 0;
   $30 = ($24 | 0) == (0 | 0);
   if ($30) {
    $$1 = $29;
   } else {
    $31 = $0 + 36 | 0;
    $32 = SAFE_HEAP_LOAD($31 | 0, 4, 0) | 0 | 0;
    FUNCTION_TABLE_iiii[(SAFE_FT_MASK($32 | 0, 7 | 0) | 0) & 7]($0, 0, 0) | 0;
    $33 = SAFE_HEAP_LOAD($26 | 0, 4, 0) | 0 | 0;
    $34 = ($33 | 0) == (0 | 0);
    $$ = $34 ? -1 : $29;
    SAFE_HEAP_STORE($23 | 0, $24 | 0, 4);
    SAFE_HEAP_STORE($19 | 0, 0 | 0, 4);
    SAFE_HEAP_STORE($28 | 0, 0 | 0, 4);
    SAFE_HEAP_STORE($25 | 0, 0 | 0, 4);
    SAFE_HEAP_STORE($26 | 0, 0 | 0, 4);
    $$1 = $$;
   }
  } else {
   $22 = _printf_core($0, $1, $3, $5, $4) | 0;
   $$1 = $22;
  }
  $35 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
  $36 = $35 & 32;
  $37 = ($36 | 0) == 0;
  $$1$ = $37 ? $$1 : -1;
  $38 = $35 | $14;
  SAFE_HEAP_STORE($0 | 0, $38 | 0, 4);
  $39 = ($40 | 0) == 0;
  if (!$39) {
   ___unlockfile($0);
  }
  $$0 = $$1$;
 }
 STACKTOP = sp;
 return $$0 | 0;
}

function _memcpy(dest, src, num) {
 dest = dest | 0;
 src = src | 0;
 num = num | 0;
 var ret = 0;
 var aligned_dest_end = 0;
 var block_aligned_dest_end = 0;
 var dest_end = 0;
 if ((num | 0) >= 8192) {
  return _emscripten_memcpy_big(dest | 0, src | 0, num | 0) | 0;
 }
 ret = dest | 0;
 dest_end = dest + num | 0;
 if ((dest & 3) == (src & 3)) {
  while (dest & 3) {
   if ((num | 0) == 0) return ret | 0;
   SAFE_HEAP_STORE(dest | 0, SAFE_HEAP_LOAD(src | 0, 1, 0) | 0 | 0, 1);
   dest = dest + 1 | 0;
   src = src + 1 | 0;
   num = num - 1 | 0;
  }
  aligned_dest_end = dest_end & -4 | 0;
  block_aligned_dest_end = aligned_dest_end - 64 | 0;
  while ((dest | 0) <= (block_aligned_dest_end | 0)) {
   SAFE_HEAP_STORE(dest | 0, SAFE_HEAP_LOAD(src | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 4 | 0, SAFE_HEAP_LOAD(src + 4 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 8 | 0, SAFE_HEAP_LOAD(src + 8 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 12 | 0, SAFE_HEAP_LOAD(src + 12 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 16 | 0, SAFE_HEAP_LOAD(src + 16 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 20 | 0, SAFE_HEAP_LOAD(src + 20 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 24 | 0, SAFE_HEAP_LOAD(src + 24 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 28 | 0, SAFE_HEAP_LOAD(src + 28 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 32 | 0, SAFE_HEAP_LOAD(src + 32 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 36 | 0, SAFE_HEAP_LOAD(src + 36 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 40 | 0, SAFE_HEAP_LOAD(src + 40 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 44 | 0, SAFE_HEAP_LOAD(src + 44 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 48 | 0, SAFE_HEAP_LOAD(src + 48 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 52 | 0, SAFE_HEAP_LOAD(src + 52 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 56 | 0, SAFE_HEAP_LOAD(src + 56 | 0, 4, 0) | 0 | 0, 4);
   SAFE_HEAP_STORE(dest + 60 | 0, SAFE_HEAP_LOAD(src + 60 | 0, 4, 0) | 0 | 0, 4);
   dest = dest + 64 | 0;
   src = src + 64 | 0;
  }
  while ((dest | 0) < (aligned_dest_end | 0)) {
   SAFE_HEAP_STORE(dest | 0, SAFE_HEAP_LOAD(src | 0, 4, 0) | 0 | 0, 4);
   dest = dest + 4 | 0;
   src = src + 4 | 0;
  }
 } else {
  aligned_dest_end = dest_end - 4 | 0;
  while ((dest | 0) < (aligned_dest_end | 0)) {
   SAFE_HEAP_STORE(dest | 0, SAFE_HEAP_LOAD(src | 0, 1, 0) | 0 | 0, 1);
   SAFE_HEAP_STORE(dest + 1 | 0, SAFE_HEAP_LOAD(src + 1 | 0, 1, 0) | 0 | 0, 1);
   SAFE_HEAP_STORE(dest + 2 | 0, SAFE_HEAP_LOAD(src + 2 | 0, 1, 0) | 0 | 0, 1);
   SAFE_HEAP_STORE(dest + 3 | 0, SAFE_HEAP_LOAD(src + 3 | 0, 1, 0) | 0 | 0, 1);
   dest = dest + 4 | 0;
   src = src + 4 | 0;
  }
 }
 while ((dest | 0) < (dest_end | 0)) {
  SAFE_HEAP_STORE(dest | 0, SAFE_HEAP_LOAD(src | 0, 1, 0) | 0 | 0, 1);
  dest = dest + 1 | 0;
  src = src + 1 | 0;
 }
 return ret | 0;
}

function ___fwritex($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$038 = 0, $$042 = 0, $$1 = 0, $$139 = 0, $$141 = 0, $$143 = 0, $$pre = 0, $$pre47 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0;
 var $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 $3 = $2 + 16 | 0;
 $4 = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
 $5 = ($4 | 0) == (0 | 0);
 if ($5) {
  $7 = ___towrite($2) | 0;
  $8 = ($7 | 0) == 0;
  if ($8) {
   $$pre = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
   $12 = $$pre;
   label = 5;
  } else {
   $$1 = 0;
  }
 } else {
  $6 = $4;
  $12 = $6;
  label = 5;
 }
 L5 : do {
  if ((label | 0) == 5) {
   $9 = $2 + 20 | 0;
   $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
   $11 = $12 - $10 | 0;
   $13 = $11 >>> 0 < $1 >>> 0;
   $14 = $10;
   if ($13) {
    $15 = $2 + 36 | 0;
    $16 = SAFE_HEAP_LOAD($15 | 0, 4, 0) | 0 | 0;
    $17 = FUNCTION_TABLE_iiii[(SAFE_FT_MASK($16 | 0, 7 | 0) | 0) & 7]($2, $0, $1) | 0;
    $$1 = $17;
    break;
   }
   $18 = $2 + 75 | 0;
   $19 = SAFE_HEAP_LOAD($18 >> 0 | 0, 1, 0) | 0 | 0;
   $20 = $19 << 24 >> 24 > -1;
   L10 : do {
    if ($20) {
     $$038 = $1;
     while (1) {
      $21 = ($$038 | 0) == 0;
      if ($21) {
       $$139 = 0;
       $$141 = $0;
       $$143 = $1;
       $31 = $14;
       break L10;
      }
      $22 = $$038 + -1 | 0;
      $23 = $0 + $22 | 0;
      $24 = SAFE_HEAP_LOAD($23 >> 0 | 0, 1, 0) | 0 | 0;
      $25 = $24 << 24 >> 24 == 10;
      if ($25) {
       break;
      } else {
       $$038 = $22;
      }
     }
     $26 = $2 + 36 | 0;
     $27 = SAFE_HEAP_LOAD($26 | 0, 4, 0) | 0 | 0;
     $28 = FUNCTION_TABLE_iiii[(SAFE_FT_MASK($27 | 0, 7 | 0) | 0) & 7]($2, $0, $$038) | 0;
     $29 = $28 >>> 0 < $$038 >>> 0;
     if ($29) {
      $$1 = $28;
      break L5;
     }
     $30 = $0 + $$038 | 0;
     $$042 = $1 - $$038 | 0;
     $$pre47 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
     $$139 = $$038;
     $$141 = $30;
     $$143 = $$042;
     $31 = $$pre47;
    } else {
     $$139 = 0;
     $$141 = $0;
     $$143 = $1;
     $31 = $14;
    }
   } while (0);
   _memcpy($31 | 0, $$141 | 0, $$143 | 0) | 0;
   $32 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
   $33 = $32 + $$143 | 0;
   SAFE_HEAP_STORE($9 | 0, $33 | 0, 4);
   $34 = $$139 + $$143 | 0;
   $$1 = $34;
  }
 } while (0);
 return $$1 | 0;
}

function _sjf_array_sji_element_setAt($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0;
 var $3 = 0, $30 = 0, $31 = 0, $32 = 0, $33 = 0, $34 = 0, $35 = 0, $36 = 0, $37 = 0, $38 = 0, $39 = 0, $4 = 0, $40 = 0, $41 = 0, $42 = 0, $43 = 0, $44 = 0, $45 = 0, $46 = 0, $47 = 0;
 var $48 = 0, $49 = 0, $5 = 0, $50 = 0, $51 = 0, $52 = 0, $53 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $vararg_buffer = 0, $vararg_ptr2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $vararg_buffer = sp;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $7 = $4;
 $8 = $3;
 $9 = $8 + 4 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = ($7 | 0) >= ($10 | 0);
 $12 = $4;
 $13 = ($12 | 0) < 0;
 $or$cond = $11 | $13;
 if ($or$cond) {
  $14 = $4;
  $15 = $3;
  $16 = $15 + 4 | 0;
  $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
  SAFE_HEAP_STORE($vararg_buffer | 0, $14 | 0, 4);
  $vararg_ptr2 = $vararg_buffer + 4 | 0;
  SAFE_HEAP_STORE($vararg_ptr2 | 0, $17 | 0, 4);
  _printf(537, $vararg_buffer) | 0;
  _exit(-1);
 }
 $18 = $3;
 $19 = $18 + 8 | 0;
 $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 $21 = $20;
 $6 = $21;
 $22 = $6;
 $23 = $4;
 $24 = $22 + ($23 << 2) | 0;
 $25 = SAFE_HEAP_LOAD($24 | 0, 4, 0) | 0 | 0;
 $26 = ($25 | 0) != (0 | 0);
 if ($26) {
  $27 = $6;
  $28 = $4;
  $29 = $27 + ($28 << 2) | 0;
  $30 = SAFE_HEAP_LOAD($29 | 0, 4, 0) | 0 | 0;
  $31 = SAFE_HEAP_LOAD($30 | 0, 4, 0) | 0 | 0;
  $32 = $31 + -1 | 0;
  SAFE_HEAP_STORE($30 | 0, $32 | 0, 4);
  $33 = $6;
  $34 = $4;
  $35 = $33 + ($34 << 2) | 0;
  $36 = SAFE_HEAP_LOAD($35 | 0, 4, 0) | 0 | 0;
  $37 = SAFE_HEAP_LOAD($36 | 0, 4, 0) | 0 | 0;
  $38 = ($37 | 0) <= 0;
  if ($38) {
   $39 = $6;
   $40 = $4;
   $41 = $39 + ($40 << 2) | 0;
   $42 = SAFE_HEAP_LOAD($41 | 0, 4, 0) | 0 | 0;
   _sji_element_destroy($42);
   $43 = $6;
   $44 = $4;
   $45 = $43 + ($44 << 2) | 0;
   $46 = SAFE_HEAP_LOAD($45 | 0, 4, 0) | 0 | 0;
   _free($46);
  }
 }
 $47 = $5;
 $48 = SAFE_HEAP_LOAD($47 | 0, 4, 0) | 0 | 0;
 $49 = $48 + 1 | 0;
 SAFE_HEAP_STORE($47 | 0, $49 | 0, 4);
 $50 = $5;
 $51 = $6;
 $52 = $4;
 $53 = $51 + ($52 << 2) | 0;
 SAFE_HEAP_STORE($53 | 0, $50 | 0, 4);
 STACKTOP = sp;
 return;
}

function _fflush($0) {
 $0 = $0 | 0;
 var $$0 = 0, $$023 = 0, $$02325 = 0, $$02327 = 0, $$024$lcssa = 0, $$02426 = 0, $$1 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0;
 var $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $29 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $phitmp = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ($0 | 0) == (0 | 0);
 do {
  if ($1) {
   $8 = SAFE_HEAP_LOAD(100 * 4 | 0, 4, 0) | 0 | 0;
   $9 = ($8 | 0) == (0 | 0);
   if ($9) {
    $29 = 0;
   } else {
    $10 = SAFE_HEAP_LOAD(100 * 4 | 0, 4, 0) | 0 | 0;
    $11 = _fflush($10) | 0;
    $29 = $11;
   }
   $12 = ___ofl_lock() | 0;
   $$02325 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
   $13 = ($$02325 | 0) == (0 | 0);
   if ($13) {
    $$024$lcssa = $29;
   } else {
    $$02327 = $$02325;
    $$02426 = $29;
    while (1) {
     $14 = $$02327 + 76 | 0;
     $15 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
     $16 = ($15 | 0) > -1;
     if ($16) {
      $17 = ___lockfile($$02327) | 0;
      $26 = $17;
     } else {
      $26 = 0;
     }
     $18 = $$02327 + 20 | 0;
     $19 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
     $20 = $$02327 + 28 | 0;
     $21 = SAFE_HEAP_LOAD($20 | 0, 4, 0) | 0 | 0;
     $22 = $19 >>> 0 > $21 >>> 0;
     if ($22) {
      $23 = ___fflush_unlocked($$02327) | 0;
      $24 = $23 | $$02426;
      $$1 = $24;
     } else {
      $$1 = $$02426;
     }
     $25 = ($26 | 0) == 0;
     if (!$25) {
      ___unlockfile($$02327);
     }
     $27 = $$02327 + 56 | 0;
     $$023 = SAFE_HEAP_LOAD($27 | 0, 4, 0) | 0 | 0;
     $28 = ($$023 | 0) == (0 | 0);
     if ($28) {
      $$024$lcssa = $$1;
      break;
     } else {
      $$02327 = $$023;
      $$02426 = $$1;
     }
    }
   }
   ___ofl_unlock();
   $$0 = $$024$lcssa;
  } else {
   $2 = $0 + 76 | 0;
   $3 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
   $4 = ($3 | 0) > -1;
   if (!$4) {
    $5 = ___fflush_unlocked($0) | 0;
    $$0 = $5;
    break;
   }
   $6 = ___lockfile($0) | 0;
   $phitmp = ($6 | 0) == 0;
   $7 = ___fflush_unlocked($0) | 0;
   if ($phitmp) {
    $$0 = $7;
   } else {
    ___unlockfile($0);
    $$0 = $7;
   }
  }
 } while (0);
 return $$0 | 0;
}

function _fmt_u($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$010$lcssa$off0 = 0, $$012 = 0, $$09$lcssa = 0, $$0914 = 0, $$1$lcssa = 0, $$111 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0;
 var $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = $1 >>> 0 > 0;
 $4 = $0 >>> 0 > 4294967295;
 $5 = ($1 | 0) == 0;
 $6 = $5 & $4;
 $7 = $3 | $6;
 if ($7) {
  $$0914 = $2;
  $8 = $0;
  $9 = $1;
  while (1) {
   $10 = ___uremdi3($8 | 0, $9 | 0, 10, 0) | 0;
   $11 = tempRet0;
   $12 = $10 & 255;
   $13 = $12 | 48;
   $14 = $$0914 + -1 | 0;
   SAFE_HEAP_STORE($14 >> 0 | 0, $13 | 0, 1);
   $15 = ___udivdi3($8 | 0, $9 | 0, 10, 0) | 0;
   $16 = tempRet0;
   $17 = $9 >>> 0 > 9;
   $18 = $8 >>> 0 > 4294967295;
   $19 = ($9 | 0) == 9;
   $20 = $19 & $18;
   $21 = $17 | $20;
   if ($21) {
    $$0914 = $14;
    $8 = $15;
    $9 = $16;
   } else {
    break;
   }
  }
  $$010$lcssa$off0 = $15;
  $$09$lcssa = $14;
 } else {
  $$010$lcssa$off0 = $0;
  $$09$lcssa = $2;
 }
 $22 = ($$010$lcssa$off0 | 0) == 0;
 if ($22) {
  $$1$lcssa = $$09$lcssa;
 } else {
  $$012 = $$010$lcssa$off0;
  $$111 = $$09$lcssa;
  while (1) {
   $23 = ($$012 >>> 0) % 10 & -1;
   $24 = $23 | 48;
   $25 = $24 & 255;
   $26 = $$111 + -1 | 0;
   SAFE_HEAP_STORE($26 >> 0 | 0, $25 | 0, 1);
   $27 = ($$012 >>> 0) / 10 & -1;
   $28 = $$012 >>> 0 < 10;
   if ($28) {
    $$1$lcssa = $26;
    break;
   } else {
    $$012 = $27;
    $$111 = $26;
   }
  }
 }
 return $$1$lcssa | 0;
}

function _memset(ptr, value, num) {
 ptr = ptr | 0;
 value = value | 0;
 num = num | 0;
 var end = 0, aligned_end = 0, block_aligned_end = 0, value4 = 0;
 end = ptr + num | 0;
 value = value & 255;
 if ((num | 0) >= 67) {
  while ((ptr & 3) != 0) {
   SAFE_HEAP_STORE(ptr | 0, value | 0, 1);
   ptr = ptr + 1 | 0;
  }
  aligned_end = end & -4 | 0;
  block_aligned_end = aligned_end - 64 | 0;
  value4 = value | value << 8 | value << 16 | value << 24;
  while ((ptr | 0) <= (block_aligned_end | 0)) {
   SAFE_HEAP_STORE(ptr | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 4 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 8 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 12 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 16 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 20 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 24 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 28 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 32 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 36 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 40 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 44 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 48 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 52 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 56 | 0, value4 | 0, 4);
   SAFE_HEAP_STORE(ptr + 60 | 0, value4 | 0, 4);
   ptr = ptr + 64 | 0;
  }
  while ((ptr | 0) < (aligned_end | 0)) {
   SAFE_HEAP_STORE(ptr | 0, value4 | 0, 4);
   ptr = ptr + 4 | 0;
  }
 }
 while ((ptr | 0) < (end | 0)) {
  SAFE_HEAP_STORE(ptr | 0, value | 0, 1);
  ptr = ptr + 1 | 0;
 }
 return end - num | 0;
}

function _sjf_array_sji_element($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $vararg_buffer = sp;
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $4 + 4 | 0;
 $6 = SAFE_HEAP_LOAD($5 | 0, 4, 0) | 0 | 0;
 $7 = ($6 | 0) < 0;
 if ($7) {
  _exit(-1);
 }
 $8 = $2;
 $9 = $8 + 8 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = ($10 | 0) != 0;
 $12 = $2;
 if ($11) {
  $13 = $12 + 12 | 0;
  SAFE_HEAP_STORE($13 >> 0 | 0, 1 | 0, 1);
 } else {
  $14 = $12 + 4 | 0;
  $15 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
  $16 = $15 << 2;
  $17 = _calloc($16, 1) | 0;
  $18 = $17;
  $19 = $2;
  $20 = $19 + 8 | 0;
  SAFE_HEAP_STORE($20 | 0, $18 | 0, 4);
  $21 = $2;
  $22 = $21 + 8 | 0;
  $23 = SAFE_HEAP_LOAD($22 | 0, 4, 0) | 0 | 0;
  $24 = ($23 | 0) != 0;
  if (!$24) {
   _printf(450, $vararg_buffer) | 0;
   _exit(-1);
  }
 }
 $25 = $2;
 $26 = SAFE_HEAP_LOAD($25 | 0, 4, 0) | 0 | 0;
 $27 = $26 + 1 | 0;
 SAFE_HEAP_STORE($25 | 0, $27 | 0, 4);
 $28 = $2;
 $29 = $3;
 SAFE_HEAP_STORE($29 | 0, $28 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_array_char($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $28 = 0;
 var $29 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $vararg_buffer = sp;
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = $4 + 4 | 0;
 $6 = SAFE_HEAP_LOAD($5 | 0, 4, 0) | 0 | 0;
 $7 = ($6 | 0) < 0;
 if ($7) {
  _exit(-1);
 }
 $8 = $2;
 $9 = $8 + 8 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = ($10 | 0) != 0;
 $12 = $2;
 if ($11) {
  $13 = $12 + 12 | 0;
  SAFE_HEAP_STORE($13 >> 0 | 0, 1 | 0, 1);
 } else {
  $14 = $12 + 4 | 0;
  $15 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
  $16 = $15;
  $17 = _calloc($16, 1) | 0;
  $18 = $17;
  $19 = $2;
  $20 = $19 + 8 | 0;
  SAFE_HEAP_STORE($20 | 0, $18 | 0, 4);
  $21 = $2;
  $22 = $21 + 8 | 0;
  $23 = SAFE_HEAP_LOAD($22 | 0, 4, 0) | 0 | 0;
  $24 = ($23 | 0) != 0;
  if (!$24) {
   _printf(450, $vararg_buffer) | 0;
   _exit(-1);
  }
 }
 $25 = $2;
 $26 = SAFE_HEAP_LOAD($25 | 0, 4, 0) | 0 | 0;
 $27 = $26 + 1 | 0;
 SAFE_HEAP_STORE($25 | 0, $27 | 0, 4);
 $28 = $2;
 $29 = $3;
 SAFE_HEAP_STORE($29 | 0, $28 | 0, 4);
 STACKTOP = sp;
 return;
}

function ___fflush_unlocked($0) {
 $0 = $0 | 0;
 var $$0 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0;
 var $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = $0 + 20 | 0;
 $2 = SAFE_HEAP_LOAD($1 | 0, 4, 0) | 0 | 0;
 $3 = $0 + 28 | 0;
 $4 = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
 $5 = $2 >>> 0 > $4 >>> 0;
 if ($5) {
  $6 = $0 + 36 | 0;
  $7 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
  FUNCTION_TABLE_iiii[(SAFE_FT_MASK($7 | 0, 7 | 0) | 0) & 7]($0, 0, 0) | 0;
  $8 = SAFE_HEAP_LOAD($1 | 0, 4, 0) | 0 | 0;
  $9 = ($8 | 0) == (0 | 0);
  if ($9) {
   $$0 = -1;
  } else {
   label = 3;
  }
 } else {
  label = 3;
 }
 if ((label | 0) == 3) {
  $10 = $0 + 4 | 0;
  $11 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
  $12 = $0 + 8 | 0;
  $13 = SAFE_HEAP_LOAD($12 | 0, 4, 0) | 0 | 0;
  $14 = $11 >>> 0 < $13 >>> 0;
  if ($14) {
   $15 = $11;
   $16 = $13;
   $17 = $15 - $16 | 0;
   $18 = $0 + 40 | 0;
   $19 = SAFE_HEAP_LOAD($18 | 0, 4, 0) | 0 | 0;
   FUNCTION_TABLE_iiii[(SAFE_FT_MASK($19 | 0, 7 | 0) | 0) & 7]($0, $17, 1) | 0;
  }
  $20 = $0 + 16 | 0;
  SAFE_HEAP_STORE($20 | 0, 0 | 0, 4);
  SAFE_HEAP_STORE($3 | 0, 0 | 0, 4);
  SAFE_HEAP_STORE($1 | 0, 0 | 0, 4);
  SAFE_HEAP_STORE($12 | 0, 0 | 0, 4);
  SAFE_HEAP_STORE($10 | 0, 0 | 0, 4);
  $$0 = 0;
 }
 return $$0 | 0;
}

function ___strerror_l($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$012$lcssa = 0, $$01214 = 0, $$016 = 0, $$113 = 0, $$115 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 $$016 = 0;
 while (1) {
  $3 = 1178 + $$016 | 0;
  $4 = SAFE_HEAP_LOAD($3 >> 0 | 0, 1, 0) | 0 | 0;
  $5 = $4 & 255;
  $6 = ($5 | 0) == ($0 | 0);
  if ($6) {
   label = 2;
   break;
  }
  $7 = $$016 + 1 | 0;
  $8 = ($7 | 0) == 87;
  if ($8) {
   $$01214 = 1266;
   $$115 = 87;
   label = 5;
   break;
  } else {
   $$016 = $7;
  }
 }
 if ((label | 0) == 2) {
  $2 = ($$016 | 0) == 0;
  if ($2) {
   $$012$lcssa = 1266;
  } else {
   $$01214 = 1266;
   $$115 = $$016;
   label = 5;
  }
 }
 if ((label | 0) == 5) {
  while (1) {
   label = 0;
   $$113 = $$01214;
   while (1) {
    $9 = SAFE_HEAP_LOAD($$113 >> 0 | 0, 1, 0) | 0 | 0;
    $10 = $9 << 24 >> 24 == 0;
    $11 = $$113 + 1 | 0;
    if ($10) {
     break;
    } else {
     $$113 = $11;
    }
   }
   $12 = $$115 + -1 | 0;
   $13 = ($12 | 0) == 0;
   if ($13) {
    $$012$lcssa = $11;
    break;
   } else {
    $$01214 = $11;
    $$115 = $12;
    label = 5;
   }
  }
 }
 $14 = $1 + 20 | 0;
 $15 = SAFE_HEAP_LOAD($14 | 0, 4, 0) | 0 | 0;
 $16 = ___lctrans($$012$lcssa, $15) | 0;
 return $16 | 0;
}

function _frexp($0, $1) {
 $0 = +$0;
 $1 = $1 | 0;
 var $$0 = 0.0, $$016 = 0.0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0.0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0.0, $9 = 0.0, $storemerge = 0, $trunc$clear = 0, label = 0;
 var sp = 0;
 sp = STACKTOP;
 SAFE_HEAP_STORE_D(tempDoublePtr | 0, +$0, 8);
 $2 = SAFE_HEAP_LOAD(tempDoublePtr | 0, 4, 0) | 0 | 0;
 $3 = SAFE_HEAP_LOAD(tempDoublePtr + 4 | 0, 4, 0) | 0 | 0;
 $4 = _bitshift64Lshr($2 | 0, $3 | 0, 52) | 0;
 $5 = tempRet0;
 $6 = $4 & 65535;
 $trunc$clear = $6 & 2047;
 switch ($trunc$clear << 16 >> 16) {
 case 0:
  {
   $7 = $0 != 0.0;
   if ($7) {
    $8 = $0 * 18446744073709551616.0;
    $9 = +_frexp($8, $1);
    $10 = SAFE_HEAP_LOAD($1 | 0, 4, 0) | 0 | 0;
    $11 = $10 + -64 | 0;
    $$016 = $9;
    $storemerge = $11;
   } else {
    $$016 = $0;
    $storemerge = 0;
   }
   SAFE_HEAP_STORE($1 | 0, $storemerge | 0, 4);
   $$0 = $$016;
   break;
  }
 case 2047:
  {
   $$0 = $0;
   break;
  }
 default:
  {
   $12 = $4 & 2047;
   $13 = $12 + -1022 | 0;
   SAFE_HEAP_STORE($1 | 0, $13 | 0, 4);
   $14 = $3 & -2146435073;
   $15 = $14 | 1071644672;
   SAFE_HEAP_STORE(tempDoublePtr | 0, $2 | 0, 4);
   SAFE_HEAP_STORE(tempDoublePtr + 4 | 0, $15 | 0, 4);
   $16 = +(+SAFE_HEAP_LOAD_D(tempDoublePtr | 0, 8));
   $$0 = $16;
  }
 }
 return +$$0;
}

function _sjf_array_sji_element_getAt($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $26 = 0, $27 = 0, $3 = 0, $4 = 0;
 var $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $vararg_buffer = 0, $vararg_buffer2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $vararg_buffer2 = sp + 8 | 0;
 $vararg_buffer = sp;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $8 = $4;
 $9 = $3;
 $10 = $9 + 4 | 0;
 $11 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $12 = ($8 | 0) >= ($11 | 0);
 $13 = $4;
 $14 = ($13 | 0) < 0;
 $or$cond = $12 | $14;
 if ($or$cond) {
  _printf(471, $vararg_buffer) | 0;
  _exit(-1);
 }
 $15 = $3;
 $16 = $15 + 8 | 0;
 $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
 $18 = $17;
 $6 = $18;
 $19 = $6;
 $20 = $4;
 $21 = $19 + ($20 << 2) | 0;
 $22 = SAFE_HEAP_LOAD($21 | 0, 4, 0) | 0 | 0;
 $7 = $22;
 $23 = $7;
 $24 = ($23 | 0) == (0 | 0);
 if ($24) {
  $25 = $4;
  SAFE_HEAP_STORE($vararg_buffer2 | 0, $25 | 0, 4);
  _printf(565, $vararg_buffer2) | 0;
  _exit(-1);
 } else {
  $26 = $7;
  $27 = $5;
  SAFE_HEAP_STORE($27 | 0, $26 | 0, 4);
  STACKTOP = sp;
  return;
 }
}

function _sjf_array_char_setAt($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $25 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0;
 var $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $vararg_buffer = 0, $vararg_ptr2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $vararg_buffer = sp;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $7 = $4;
 $8 = $3;
 $9 = $8 + 4 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = ($7 | 0) >= ($10 | 0);
 $12 = $4;
 $13 = ($12 | 0) < 0;
 $or$cond = $11 | $13;
 if ($or$cond) {
  $14 = $4;
  $15 = $3;
  $16 = $15 + 4 | 0;
  $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
  SAFE_HEAP_STORE($vararg_buffer | 0, $14 | 0, 4);
  $vararg_ptr2 = $vararg_buffer + 4 | 0;
  SAFE_HEAP_STORE($vararg_ptr2 | 0, $17 | 0, 4);
  _printf(537, $vararg_buffer) | 0;
  _exit(-1);
 } else {
  $18 = $3;
  $19 = $18 + 8 | 0;
  $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
  $21 = $20;
  $6 = $21;
  $22 = $5;
  $23 = $6;
  $24 = $4;
  $25 = $23 + $24 | 0;
  SAFE_HEAP_STORE($25 >> 0 | 0, $22 | 0, 1);
  STACKTOP = sp;
  return;
 }
}

function _realloc($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $3 = 0, $4 = 0, $5 = 0;
 var $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ($0 | 0) == (0 | 0);
 if ($2) {
  $3 = _malloc($1) | 0;
  $$1 = $3;
  return $$1 | 0;
 }
 $4 = $1 >>> 0 > 4294967231;
 if ($4) {
  $5 = ___errno_location() | 0;
  SAFE_HEAP_STORE($5 | 0, 12 | 0, 4);
  $$1 = 0;
  return $$1 | 0;
 }
 $6 = $1 >>> 0 < 11;
 $7 = $1 + 11 | 0;
 $8 = $7 & -8;
 $9 = $6 ? 16 : $8;
 $10 = $0 + -8 | 0;
 $11 = _try_realloc_chunk($10, $9) | 0;
 $12 = ($11 | 0) == (0 | 0);
 if (!$12) {
  $13 = $11 + 8 | 0;
  $$1 = $13;
  return $$1 | 0;
 }
 $14 = _malloc($1) | 0;
 $15 = ($14 | 0) == (0 | 0);
 if ($15) {
  $$1 = 0;
  return $$1 | 0;
 }
 $16 = $0 + -4 | 0;
 $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
 $18 = $17 & -8;
 $19 = $17 & 3;
 $20 = ($19 | 0) == 0;
 $21 = $20 ? 8 : 4;
 $22 = $18 - $21 | 0;
 $23 = $22 >>> 0 < $1 >>> 0;
 $24 = $23 ? $22 : $1;
 _memcpy($14 | 0, $0 | 0, $24 | 0) | 0;
 _free($0);
 $$1 = $14;
 return $$1 | 0;
}

function ___stdio_seek($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$pre = 0, $10 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, $vararg_ptr1 = 0, $vararg_ptr2 = 0, $vararg_ptr3 = 0, $vararg_ptr4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $vararg_buffer = sp;
 $3 = sp + 20 | 0;
 $4 = $0 + 60 | 0;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $3;
 SAFE_HEAP_STORE($vararg_buffer | 0, $5 | 0, 4);
 $vararg_ptr1 = $vararg_buffer + 4 | 0;
 SAFE_HEAP_STORE($vararg_ptr1 | 0, 0 | 0, 4);
 $vararg_ptr2 = $vararg_buffer + 8 | 0;
 SAFE_HEAP_STORE($vararg_ptr2 | 0, $1 | 0, 4);
 $vararg_ptr3 = $vararg_buffer + 12 | 0;
 SAFE_HEAP_STORE($vararg_ptr3 | 0, $6 | 0, 4);
 $vararg_ptr4 = $vararg_buffer + 16 | 0;
 SAFE_HEAP_STORE($vararg_ptr4 | 0, $2 | 0, 4);
 $7 = ___syscall140(140, $vararg_buffer | 0) | 0;
 $8 = ___syscall_ret($7) | 0;
 $9 = ($8 | 0) < 0;
 if ($9) {
  SAFE_HEAP_STORE($3 | 0, -1 | 0, 4);
  $10 = -1;
 } else {
  $$pre = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
  $10 = $$pre;
 }
 STACKTOP = sp;
 return $10 | 0;
}

function ___stdout_write($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, $vararg_ptr1 = 0, $vararg_ptr2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $vararg_buffer = sp;
 $3 = sp + 16 | 0;
 $4 = $0 + 36 | 0;
 SAFE_HEAP_STORE($4 | 0, 7 | 0, 4);
 $5 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
 $6 = $5 & 64;
 $7 = ($6 | 0) == 0;
 if ($7) {
  $8 = $0 + 60 | 0;
  $9 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
  $10 = $3;
  SAFE_HEAP_STORE($vararg_buffer | 0, $9 | 0, 4);
  $vararg_ptr1 = $vararg_buffer + 4 | 0;
  SAFE_HEAP_STORE($vararg_ptr1 | 0, 21523 | 0, 4);
  $vararg_ptr2 = $vararg_buffer + 8 | 0;
  SAFE_HEAP_STORE($vararg_ptr2 | 0, $10 | 0, 4);
  $11 = ___syscall54(54, $vararg_buffer | 0) | 0;
  $12 = ($11 | 0) == 0;
  if (!$12) {
   $13 = $0 + 75 | 0;
   SAFE_HEAP_STORE($13 >> 0 | 0, -1 | 0, 1);
  }
 }
 $14 = ___stdio_write($0, $1, $2) | 0;
 STACKTOP = sp;
 return $14 | 0;
}

function ___towrite($0) {
 $0 = $0 | 0;
 var $$0 = 0, $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0;
 var $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = $0 + 74 | 0;
 $2 = SAFE_HEAP_LOAD($1 >> 0 | 0, 1, 0) | 0 | 0;
 $3 = $2 << 24 >> 24;
 $4 = $3 + 255 | 0;
 $5 = $4 | $3;
 $6 = $5 & 255;
 SAFE_HEAP_STORE($1 >> 0 | 0, $6 | 0, 1);
 $7 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
 $8 = $7 & 8;
 $9 = ($8 | 0) == 0;
 if ($9) {
  $11 = $0 + 8 | 0;
  SAFE_HEAP_STORE($11 | 0, 0 | 0, 4);
  $12 = $0 + 4 | 0;
  SAFE_HEAP_STORE($12 | 0, 0 | 0, 4);
  $13 = $0 + 44 | 0;
  $14 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
  $15 = $0 + 28 | 0;
  SAFE_HEAP_STORE($15 | 0, $14 | 0, 4);
  $16 = $0 + 20 | 0;
  SAFE_HEAP_STORE($16 | 0, $14 | 0, 4);
  $17 = $0 + 48 | 0;
  $18 = SAFE_HEAP_LOAD($17 | 0, 4, 0) | 0 | 0;
  $19 = $14 + $18 | 0;
  $20 = $0 + 16 | 0;
  SAFE_HEAP_STORE($20 | 0, $19 | 0, 4);
  $$0 = 0;
 } else {
  $10 = $7 | 32;
  SAFE_HEAP_STORE($0 | 0, $10 | 0, 4);
  $$0 = -1;
 }
 return $$0 | 0;
}

function _sjf_array_char_getAt($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $21 = 0, $22 = 0, $23 = 0, $24 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0;
 var $8 = 0, $9 = 0, $or$cond = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $vararg_buffer = sp;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $8 = $4;
 $9 = $3;
 $10 = $9 + 4 | 0;
 $11 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $12 = ($8 | 0) >= ($11 | 0);
 $13 = $4;
 $14 = ($13 | 0) < 0;
 $or$cond = $12 | $14;
 if ($or$cond) {
  _printf(471, $vararg_buffer) | 0;
  _exit(-1);
 } else {
  $15 = $3;
  $16 = $15 + 8 | 0;
  $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
  $18 = $17;
  $6 = $18;
  $19 = $6;
  $20 = $4;
  $21 = $19 + $20 | 0;
  $22 = SAFE_HEAP_LOAD($21 >> 0 | 0, 1, 0) | 0 | 0;
  $7 = $22;
  $23 = $7;
  $24 = $5;
  SAFE_HEAP_STORE($24 >> 0 | 0, $23 | 0, 1);
  STACKTOP = sp;
  return;
 }
}

function _sji_element_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $20 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 $2 = $1;
 $3 = $2 + 4 | 0;
 $4 = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + -1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $1;
 $8 = $7 + 4 | 0;
 $9 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = ($10 | 0) <= 0;
 if (!$11) {
  STACKTOP = sp;
  return;
 }
 $12 = $1;
 $13 = $12 + 8 | 0;
 $14 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 $15 = $1;
 $16 = $15 + 4 | 0;
 $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
 FUNCTION_TABLE_vi[(SAFE_FT_MASK($14 | 0, 7 | 0) | 0) & 7]($17);
 $18 = $1;
 $19 = $18 + 4 | 0;
 $20 = SAFE_HEAP_LOAD($19 | 0, 4, 0) | 0 | 0;
 _free($20);
 STACKTOP = sp;
 return;
}

function _strcmp($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$011 = 0, $$0710 = 0, $$lcssa = 0, $$lcssa8 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, $or$cond9 = 0, label = 0;
 var sp = 0;
 sp = STACKTOP;
 $2 = SAFE_HEAP_LOAD($0 >> 0 | 0, 1, 0) | 0 | 0;
 $3 = SAFE_HEAP_LOAD($1 >> 0 | 0, 1, 0) | 0 | 0;
 $4 = $2 << 24 >> 24 != $3 << 24 >> 24;
 $5 = $2 << 24 >> 24 == 0;
 $or$cond9 = $5 | $4;
 if ($or$cond9) {
  $$lcssa = $3;
  $$lcssa8 = $2;
 } else {
  $$011 = $1;
  $$0710 = $0;
  while (1) {
   $6 = $$0710 + 1 | 0;
   $7 = $$011 + 1 | 0;
   $8 = SAFE_HEAP_LOAD($6 >> 0 | 0, 1, 0) | 0 | 0;
   $9 = SAFE_HEAP_LOAD($7 >> 0 | 0, 1, 0) | 0 | 0;
   $10 = $8 << 24 >> 24 != $9 << 24 >> 24;
   $11 = $8 << 24 >> 24 == 0;
   $or$cond = $11 | $10;
   if ($or$cond) {
    $$lcssa = $9;
    $$lcssa8 = $8;
    break;
   } else {
    $$011 = $7;
    $$0710 = $6;
   }
  }
 }
 $12 = $$lcssa8 & 255;
 $13 = $$lcssa & 255;
 $14 = $12 - $13 | 0;
 return $14 | 0;
}

function _pad_684($0, $1, $2, $3, $4) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 $3 = $3 | 0;
 $4 = $4 | 0;
 var $$0$lcssa = 0, $$011 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $or$cond = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 256 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(256 | 0);
 $5 = sp;
 $6 = $4 & 73728;
 $7 = ($6 | 0) == 0;
 $8 = ($2 | 0) > ($3 | 0);
 $or$cond = $8 & $7;
 if ($or$cond) {
  $9 = $2 - $3 | 0;
  $10 = $9 >>> 0 < 256;
  $11 = $10 ? $9 : 256;
  _memset($5 | 0, $1 | 0, $11 | 0) | 0;
  $12 = $9 >>> 0 > 255;
  if ($12) {
   $13 = $2 - $3 | 0;
   $$011 = $9;
   while (1) {
    _out($0, $5, 256);
    $14 = $$011 + -256 | 0;
    $15 = $14 >>> 0 > 255;
    if ($15) {
     $$011 = $14;
    } else {
     break;
    }
   }
   $16 = $13 & 255;
   $$0$lcssa = $16;
  } else {
   $$0$lcssa = $9;
  }
  _out($0, $5, $$0$lcssa);
 }
 STACKTOP = sp;
 return;
}

function _getint($0) {
 $0 = $0 | 0;
 var $$0$lcssa = 0, $$06 = 0, $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $isdigit = 0, $isdigit5 = 0, $isdigittmp = 0, $isdigittmp4 = 0, $isdigittmp7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
 $2 = SAFE_HEAP_LOAD($1 >> 0 | 0, 1, 0) | 0 | 0;
 $3 = $2 << 24 >> 24;
 $isdigittmp4 = $3 + -48 | 0;
 $isdigit5 = $isdigittmp4 >>> 0 < 10;
 if ($isdigit5) {
  $$06 = 0;
  $7 = $1;
  $isdigittmp7 = $isdigittmp4;
  while (1) {
   $4 = $$06 * 10 | 0;
   $5 = $isdigittmp7 + $4 | 0;
   $6 = $7 + 1 | 0;
   SAFE_HEAP_STORE($0 | 0, $6 | 0, 4);
   $8 = SAFE_HEAP_LOAD($6 >> 0 | 0, 1, 0) | 0 | 0;
   $9 = $8 << 24 >> 24;
   $isdigittmp = $9 + -48 | 0;
   $isdigit = $isdigittmp >>> 0 < 10;
   if ($isdigit) {
    $$06 = $5;
    $7 = $6;
    $isdigittmp7 = $isdigittmp;
   } else {
    $$0$lcssa = $5;
    break;
   }
  }
 } else {
  $$0$lcssa = 0;
 }
 return $$0$lcssa | 0;
}

function _sjf_timerElement_as_sji_element($0) {
 $0 = $0 | 0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0;
 var sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 $3 = _malloc(20) | 0;
 $2 = $3;
 $4 = $2;
 SAFE_HEAP_STORE($4 | 0, 1 | 0, 4);
 $5 = $1;
 $6 = $2;
 $7 = $6 + 4 | 0;
 SAFE_HEAP_STORE($7 | 0, $5 | 0, 4);
 $8 = $2;
 $9 = $8 + 4 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $12 = $11 + 1 | 0;
 SAFE_HEAP_STORE($10 | 0, $12 | 0, 4);
 $13 = $2;
 $14 = $13 + 8 | 0;
 SAFE_HEAP_STORE($14 | 0, 4 | 0, 4);
 $15 = $2;
 $16 = $15 + 12 | 0;
 SAFE_HEAP_STORE($16 | 0, 5 | 0, 4);
 $17 = $2;
 $18 = $17 + 16 | 0;
 SAFE_HEAP_STORE($18 | 0, 6 | 0, 4);
 $19 = $2;
 STACKTOP = sp;
 return $19 | 0;
}

function _fmt_x($0, $1, $2, $3) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 $3 = $3 | 0;
 var $$05$lcssa = 0, $$056 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $18 = 0, $19 = 0, $20 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0;
 var sp = 0;
 sp = STACKTOP;
 $4 = ($0 | 0) == 0;
 $5 = ($1 | 0) == 0;
 $6 = $4 & $5;
 if ($6) {
  $$05$lcssa = $2;
 } else {
  $$056 = $2;
  $15 = $1;
  $8 = $0;
  while (1) {
   $7 = $8 & 15;
   $9 = 1160 + $7 | 0;
   $10 = SAFE_HEAP_LOAD($9 >> 0 | 0, 1, 0) | 0 | 0;
   $11 = $10 & 255;
   $12 = $11 | $3;
   $13 = $12 & 255;
   $14 = $$056 + -1 | 0;
   SAFE_HEAP_STORE($14 >> 0 | 0, $13 | 0, 1);
   $16 = _bitshift64Lshr($8 | 0, $15 | 0, 4) | 0;
   $17 = tempRet0;
   $18 = ($16 | 0) == 0;
   $19 = ($17 | 0) == 0;
   $20 = $18 & $19;
   if ($20) {
    $$05$lcssa = $14;
    break;
   } else {
    $$056 = $14;
    $15 = $17;
    $8 = $16;
   }
  }
 }
 return $$05$lcssa | 0;
}

function _sjf_string_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $17 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 $2 = $1;
 $3 = $2 + 12 | 0;
 $4 = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + -1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $1;
 $8 = $7 + 12 | 0;
 $9 = SAFE_HEAP_LOAD($8 | 0, 4, 0) | 0 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $11 = ($10 | 0) <= 0;
 if (!$11) {
  STACKTOP = sp;
  return;
 }
 $12 = $1;
 $13 = $12 + 12 | 0;
 $14 = SAFE_HEAP_LOAD($13 | 0, 4, 0) | 0 | 0;
 _sjf_array_char_destroy($14);
 $15 = $1;
 $16 = $15 + 12 | 0;
 $17 = SAFE_HEAP_LOAD($16 | 0, 4, 0) | 0 | 0;
 _free($17);
 STACKTOP = sp;
 return;
}

function _fmt_o($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $$0$lcssa = 0, $$06 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $16 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = ($0 | 0) == 0;
 $4 = ($1 | 0) == 0;
 $5 = $3 & $4;
 if ($5) {
  $$0$lcssa = $2;
 } else {
  $$06 = $2;
  $11 = $1;
  $7 = $0;
  while (1) {
   $6 = $7 & 255;
   $8 = $6 & 7;
   $9 = $8 | 48;
   $10 = $$06 + -1 | 0;
   SAFE_HEAP_STORE($10 >> 0 | 0, $9 | 0, 1);
   $12 = _bitshift64Lshr($7 | 0, $11 | 0, 3) | 0;
   $13 = tempRet0;
   $14 = ($12 | 0) == 0;
   $15 = ($13 | 0) == 0;
   $16 = $14 & $15;
   if ($16) {
    $$0$lcssa = $10;
    break;
   } else {
    $$06 = $10;
    $11 = $13;
    $7 = $12;
   }
  }
 }
 return $$0$lcssa | 0;
}

function _sjf_array_sji_element_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 $2 = $1;
 $3 = $2 + 12 | 0;
 $4 = SAFE_HEAP_LOAD($3 >> 0 | 0, 1, 0) | 0 | 0;
 $5 = $4 & 1;
 if ($5) {
  STACKTOP = sp;
  return;
 }
 $6 = $1;
 $7 = $6 + 8 | 0;
 $8 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
 $9 = ($8 | 0) != 0;
 if (!$9) {
  STACKTOP = sp;
  return;
 }
 $10 = $1;
 $11 = $10 + 8 | 0;
 $12 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $13 = $12;
 _free($13);
 $14 = $1;
 $15 = $14 + 8 | 0;
 SAFE_HEAP_STORE($15 | 0, 0 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_array_char_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $15 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 $2 = $1;
 $3 = $2 + 12 | 0;
 $4 = SAFE_HEAP_LOAD($3 >> 0 | 0, 1, 0) | 0 | 0;
 $5 = $4 & 1;
 if ($5) {
  STACKTOP = sp;
  return;
 }
 $6 = $1;
 $7 = $6 + 8 | 0;
 $8 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
 $9 = ($8 | 0) != 0;
 if (!$9) {
  STACKTOP = sp;
  return;
 }
 $10 = $1;
 $11 = $10 + 8 | 0;
 $12 = SAFE_HEAP_LOAD($11 | 0, 4, 0) | 0 | 0;
 $13 = $12;
 _free($13);
 $14 = $1;
 $15 = $14 + 8 | 0;
 SAFE_HEAP_STORE($15 | 0, 0 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sbrk(increment) {
 increment = increment | 0;
 var oldDynamicTop = 0;
 var oldDynamicTopOnChange = 0;
 var newDynamicTop = 0;
 var totalMemory = 0;
 increment = increment + 15 & -16 | 0;
 oldDynamicTop = SAFE_HEAP_LOAD(DYNAMICTOP_PTR | 0, 4, 0) | 0 | 0;
 newDynamicTop = oldDynamicTop + increment | 0;
 if ((increment | 0) > 0 & (newDynamicTop | 0) < (oldDynamicTop | 0) | (newDynamicTop | 0) < 0) {
  abortOnCannotGrowMemory() | 0;
  ___setErrNo(12);
  return -1;
 }
 SAFE_HEAP_STORE(DYNAMICTOP_PTR | 0, newDynamicTop | 0, 4);
 totalMemory = getTotalMemory() | 0;
 if ((newDynamicTop | 0) > (totalMemory | 0)) {
  if ((enlargeMemory() | 0) == 0) {
   SAFE_HEAP_STORE(DYNAMICTOP_PTR | 0, oldDynamicTop | 0, 4);
   ___setErrNo(12);
   return -1;
  }
 }
 return oldDynamicTop | 0;
}

function _calloc($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$ = 0, $$0 = 0, $10 = 0, $11 = 0, $12 = 0, $13 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ($0 | 0) == 0;
 if ($2) {
  $$0 = 0;
 } else {
  $3 = Math_imul($1, $0) | 0;
  $4 = $1 | $0;
  $5 = $4 >>> 0 > 65535;
  if ($5) {
   $6 = ($3 >>> 0) / ($0 >>> 0) & -1;
   $7 = ($6 | 0) == ($1 | 0);
   $$ = $7 ? $3 : -1;
   $$0 = $$;
  } else {
   $$0 = $3;
  }
 }
 $8 = _malloc($$0) | 0;
 $9 = ($8 | 0) == (0 | 0);
 if ($9) {
  return $8 | 0;
 }
 $10 = $8 + -4 | 0;
 $11 = SAFE_HEAP_LOAD($10 | 0, 4, 0) | 0 | 0;
 $12 = $11 & 3;
 $13 = ($12 | 0) == 0;
 if ($13) {
  return $8 | 0;
 }
 _memset($8 | 0, 0, $$0 | 0) | 0;
 return $8 | 0;
}

function _sjf_string_getAt($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $10 = 0, $11 = 0, $12 = 0, $13 = 0, $14 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $7 = sp + 16 | 0;
 $3 = $0;
 $4 = $1;
 $5 = $2;
 $8 = $3;
 $9 = $8 + 12 | 0;
 $10 = SAFE_HEAP_LOAD($9 | 0, 4, 0) | 0 | 0;
 $6 = $10;
 SAFE_HEAP_STORE($7 >> 0 | 0, 0 | 0, 1);
 $11 = $6;
 $12 = $4;
 _sjf_array_char_getAt($11, $12, $7);
 $13 = SAFE_HEAP_LOAD($7 >> 0 | 0, 1, 0) | 0 | 0;
 $14 = $5;
 SAFE_HEAP_STORE($14 >> 0 | 0, $13 | 0, 1);
 STACKTOP = sp;
 return;
}

function _sjf_anon1_write($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $9 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $vararg_buffer = sp;
 $2 = $0;
 $3 = $1;
 $4 = $3;
 $5 = $4 + 12 | 0;
 $6 = SAFE_HEAP_LOAD($5 | 0, 4, 0) | 0 | 0;
 $7 = $6 + 8 | 0;
 $8 = SAFE_HEAP_LOAD($7 | 0, 4, 0) | 0 | 0;
 $9 = $8;
 SAFE_HEAP_STORE($vararg_buffer | 0, $9 | 0, 4);
 _printf(435, $vararg_buffer) | 0;
 STACKTOP = sp;
 return;
}

function SAFE_HEAP_LOAD(dest, bytes, unsigned) {
 dest = dest | 0;
 bytes = bytes | 0;
 unsigned = unsigned | 0;
 if ((dest | 0) <= 0) segfault();
 if ((dest + bytes | 0) > (HEAP32[DYNAMICTOP_PTR >> 2] | 0)) segfault();
 if ((bytes | 0) == 4) {
  if (dest & 3) alignfault();
  return HEAP32[dest >> 2] | 0;
 } else if ((bytes | 0) == 1) {
  if (unsigned) {
   return HEAPU8[dest >> 0] | 0;
  } else {
   return HEAP8[dest >> 0] | 0;
  }
 }
 if (dest & 1) alignfault();
 if (unsigned) return HEAPU16[dest >> 1] | 0;
 return HEAP16[dest >> 1] | 0;
}

function ___stdio_close($0) {
 $0 = $0 | 0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $vararg_buffer = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $vararg_buffer = sp;
 $1 = $0 + 60 | 0;
 $2 = SAFE_HEAP_LOAD($1 | 0, 4, 0) | 0 | 0;
 $3 = _dummy_570($2) | 0;
 SAFE_HEAP_STORE($vararg_buffer | 0, $3 | 0, 4);
 $4 = ___syscall6(6, $vararg_buffer | 0) | 0;
 $5 = ___syscall_ret($4) | 0;
 STACKTOP = sp;
 return $5 | 0;
}

function _sjf_element_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 $2 = $1;
 $3 = $2 + 8 | 0;
 $4 = SAFE_HEAP_LOAD($3 | 0, 4, 0) | 0 | 0;
 _sjf_string_destroy($4);
 $5 = $1;
 $6 = $5 + 12 | 0;
 $7 = SAFE_HEAP_LOAD($6 | 0, 4, 0) | 0 | 0;
 _sjf_array_sji_element_destroy($7);
 STACKTOP = sp;
 return;
}

function _sjf_timerElement_asInterface($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, $cond = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $3 = $0;
 $4 = $1;
 $5 = $4;
 $cond = ($5 | 0) == 1;
 if ($cond) {
  $6 = $3;
  $7 = _sjf_timerElement_as_sji_element($6) | 0;
  $2 = $7;
 } else {
  $2 = 0;
 }
 $8 = $2;
 STACKTOP = sp;
 return $8 | 0;
}

function _sjf_timerElement($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + 1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $2;
 $8 = $3;
 SAFE_HEAP_STORE($8 | 0, $7 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_element($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + 1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $2;
 $8 = $3;
 SAFE_HEAP_STORE($8 | 0, $7 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_string($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + 1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $2;
 $8 = $3;
 SAFE_HEAP_STORE($8 | 0, $7 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_anon4($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + 1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $2;
 $8 = $3;
 SAFE_HEAP_STORE($8 | 0, $7 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_anon3($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + 1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $2;
 $8 = $3;
 SAFE_HEAP_STORE($8 | 0, $7 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_anon2($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + 1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $2;
 $8 = $3;
 SAFE_HEAP_STORE($8 | 0, $7 | 0, 4);
 STACKTOP = sp;
 return;
}

function _sjf_anon1($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $2 = $0;
 $3 = $1;
 $4 = $2;
 $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
 $6 = $5 + 1 | 0;
 SAFE_HEAP_STORE($4 | 0, $6 | 0, 4);
 $7 = $2;
 $8 = $3;
 SAFE_HEAP_STORE($8 | 0, $7 | 0, 4);
 STACKTOP = sp;
 return;
}

function ___lctrans_impl($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$0 = 0, $2 = 0, $3 = 0, $4 = 0, $5 = 0, $6 = 0, $7 = 0, $8 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ($1 | 0) == (0 | 0);
 if ($2) {
  $$0 = 0;
 } else {
  $3 = SAFE_HEAP_LOAD($1 | 0, 4, 0) | 0 | 0;
  $4 = $1 + 4 | 0;
  $5 = SAFE_HEAP_LOAD($4 | 0, 4, 0) | 0 | 0;
  $6 = ___mo_lookup($3, $5, $0) | 0;
  $$0 = $6;
 }
 $7 = ($$0 | 0) != (0 | 0);
 $8 = $7 ? $$0 : $0;
 return $8 | 0;
}

function _llvm_cttz_i32(x) {
 x = x | 0;
 var ret = 0;
 ret = SAFE_HEAP_LOAD(cttz_i8 + (x & 255) | 0, 1, 0) | 0;
 if ((ret | 0) < 8) return ret | 0;
 ret = SAFE_HEAP_LOAD(cttz_i8 + (x >> 8 & 255) | 0, 1, 0) | 0;
 if ((ret | 0) < 8) return ret + 8 | 0;
 ret = SAFE_HEAP_LOAD(cttz_i8 + (x >> 16 & 255) | 0, 1, 0) | 0;
 if ((ret | 0) < 8) return ret + 16 | 0;
 return (SAFE_HEAP_LOAD(cttz_i8 + (x >>> 24) | 0, 1, 0) | 0) + 24 | 0;
}

function SAFE_HEAP_STORE(dest, value, bytes) {
 dest = dest | 0;
 value = value | 0;
 bytes = bytes | 0;
 if ((dest | 0) <= 0) segfault();
 if ((dest + bytes | 0) > (HEAP32[DYNAMICTOP_PTR >> 2] | 0)) segfault();
 if ((bytes | 0) == 4) {
  if (dest & 3) alignfault();
  HEAP32[dest >> 2] = value;
 } else if ((bytes | 0) == 1) {
  HEAP8[dest >> 0] = value;
 } else {
  if (dest & 1) alignfault();
  HEAP16[dest >> 1] = value;
 }
}

function ___uremdi3($a$0, $a$1, $b$0, $b$1) {
 $a$0 = $a$0 | 0;
 $a$1 = $a$1 | 0;
 $b$0 = $b$0 | 0;
 $b$1 = $b$1 | 0;
 var $rem = 0, __stackBase__ = 0;
 __stackBase__ = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 $rem = __stackBase__ | 0;
 ___udivmoddi4($a$0, $a$1, $b$0, $b$1, $rem) | 0;
 STACKTOP = __stackBase__;
 return (tempRet0 = SAFE_HEAP_LOAD($rem + 4 | 0, 4, 0) | 0 | 0, SAFE_HEAP_LOAD($rem | 0, 4, 0) | 0 | 0) | 0;
}

function _printf($0, $varargs) {
 $0 = $0 | 0;
 $varargs = $varargs | 0;
 var $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = sp;
 SAFE_HEAP_STORE($1 | 0, $varargs | 0, 4);
 $2 = SAFE_HEAP_LOAD(68 * 4 | 0, 4, 0) | 0 | 0;
 $3 = _vfprintf($2, $0, $1) | 0;
 STACKTOP = sp;
 return $3 | 0;
}

function SAFE_HEAP_STORE_D(dest, value, bytes) {
 dest = dest | 0;
 value = +value;
 bytes = bytes | 0;
 if ((dest | 0) <= 0) segfault();
 if ((dest + bytes | 0) > (HEAP32[DYNAMICTOP_PTR >> 2] | 0)) segfault();
 if ((bytes | 0) == 8) {
  if (dest & 7) alignfault();
  HEAPF64[dest >> 3] = value;
 } else {
  if (dest & 3) alignfault();
  HEAPF32[dest >> 2] = value;
 }
}

function _main() {
 var $0 = 0, $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 32 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(32 | 0);
 $1 = sp + 4 | 0;
 $0 = 0;
 $2 = $1;
 $3 = $2;
 SAFE_HEAP_STORE($3 | 0, 1 | 0, 4);
 $4 = $2;
 _sjf_global($4);
 _sjf_global_destroy($1);
 STACKTOP = sp;
 return 0;
}

function SAFE_HEAP_LOAD_D(dest, bytes) {
 dest = dest | 0;
 bytes = bytes | 0;
 if ((dest | 0) <= 0) segfault();
 if ((dest + bytes | 0) > (HEAP32[DYNAMICTOP_PTR >> 2] | 0)) segfault();
 if ((bytes | 0) == 8) {
  if (dest & 7) alignfault();
  return +HEAPF64[dest >> 3];
 }
 if (dest & 3) alignfault();
 return +HEAPF32[dest >> 2];
}

function _bitshift64Shl(low, high, bits) {
 low = low | 0;
 high = high | 0;
 bits = bits | 0;
 var ander = 0;
 if ((bits | 0) < 32) {
  ander = (1 << bits) - 1 | 0;
  tempRet0 = high << bits | (low & ander << 32 - bits) >>> 32 - bits;
  return low << bits;
 }
 tempRet0 = low << bits - 32;
 return 0;
}

function ___syscall_ret($0) {
 $0 = $0 | 0;
 var $$0 = 0, $1 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = $0 >>> 0 > 4294963200;
 if ($1) {
  $2 = 0 - $0 | 0;
  $3 = ___errno_location() | 0;
  SAFE_HEAP_STORE($3 | 0, $2 | 0, 4);
  $$0 = -1;
 } else {
  $$0 = $0;
 }
 return $$0 | 0;
}

function _bitshift64Lshr(low, high, bits) {
 low = low | 0;
 high = high | 0;
 bits = bits | 0;
 var ander = 0;
 if ((bits | 0) < 32) {
  ander = (1 << bits) - 1 | 0;
  tempRet0 = high >>> bits;
  return low >>> bits | (high & ander) << 32 - bits;
 }
 tempRet0 = 0;
 return high >>> bits - 32 | 0;
}

function ___DOUBLE_BITS_685($0) {
 $0 = +$0;
 var $1 = 0, $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 SAFE_HEAP_STORE_D(tempDoublePtr | 0, +$0, 8);
 $1 = SAFE_HEAP_LOAD(tempDoublePtr | 0, 4, 0) | 0 | 0;
 $2 = SAFE_HEAP_LOAD(tempDoublePtr + 4 | 0, 4, 0) | 0 | 0;
 tempRet0 = $2;
 return $1 | 0;
}

function _out($0, $1, $2) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 $2 = $2 | 0;
 var $3 = 0, $4 = 0, $5 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $3 = SAFE_HEAP_LOAD($0 | 0, 4, 0) | 0 | 0;
 $4 = $3 & 32;
 $5 = ($4 | 0) == 0;
 if ($5) {
  ___fwritex($1, $2, $0) | 0;
 }
 return;
}

function _strerror($0) {
 $0 = $0 | 0;
 var $1 = 0, $2 = 0, $3 = 0, $4 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $1 = ___pthread_self_104() | 0;
 $2 = $1 + 188 | 0;
 $3 = SAFE_HEAP_LOAD($2 | 0, 4, 0) | 0 | 0;
 $4 = ___strerror_l($0, $3) | 0;
 return $4 | 0;
}

function runPostSets() {}
function _i64Subtract(a, b, c, d) {
 a = a | 0;
 b = b | 0;
 c = c | 0;
 d = d | 0;
 var l = 0, h = 0;
 l = a - c >>> 0;
 h = b - d >>> 0;
 h = b - d - (c >>> 0 > a >>> 0 | 0) >>> 0;
 return (tempRet0 = h, l | 0) | 0;
}

function _wctomb($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$0 = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ($0 | 0) == (0 | 0);
 if ($2) {
  $$0 = 0;
 } else {
  $3 = _wcrtomb($0, $1, 0) | 0;
  $$0 = $3;
 }
 return $$0 | 0;
}

function _sjf_timerElement_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 STACKTOP = sp;
 return;
}

function _sjf_global_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 STACKTOP = sp;
 return;
}

function _sjf_anon4_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 STACKTOP = sp;
 return;
}

function _sjf_anon3_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 STACKTOP = sp;
 return;
}

function _sjf_anon2_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 STACKTOP = sp;
 return;
}

function _sjf_anon1_destroy($0) {
 $0 = $0 | 0;
 var $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 STACKTOP = STACKTOP + 16 | 0;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(16 | 0);
 $1 = $0;
 STACKTOP = sp;
 return;
}
function stackAlloc(size) {
 size = size | 0;
 var ret = 0;
 ret = STACKTOP;
 STACKTOP = STACKTOP + size | 0;
 STACKTOP = STACKTOP + 15 & -16;
 if ((STACKTOP | 0) >= (STACK_MAX | 0)) abortStackOverflow(size | 0);
 return ret | 0;
}

function _swapc($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $$ = 0, $2 = 0, $3 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ($1 | 0) == 0;
 $3 = _llvm_bswap_i32($0 | 0) | 0;
 $$ = $2 ? $0 : $3;
 return $$ | 0;
}

function ___udivdi3($a$0, $a$1, $b$0, $b$1) {
 $a$0 = $a$0 | 0;
 $a$1 = $a$1 | 0;
 $b$0 = $b$0 | 0;
 $b$1 = $b$1 | 0;
 var $1$0 = 0;
 $1$0 = ___udivmoddi4($a$0, $a$1, $b$0, $b$1, 0) | 0;
 return $1$0 | 0;
}

function dynCall_iiii(index, a1, a2, a3) {
 index = index | 0;
 a1 = a1 | 0;
 a2 = a2 | 0;
 a3 = a3 | 0;
 return FUNCTION_TABLE_iiii[(SAFE_FT_MASK(index | 0, 7 | 0) | 0) & 7](a1 | 0, a2 | 0, a3 | 0) | 0;
}

function _i64Add(a, b, c, d) {
 a = a | 0;
 b = b | 0;
 c = c | 0;
 d = d | 0;
 var l = 0, h = 0;
 l = a + c >>> 0;
 h = b + d + (l >>> 0 < a >>> 0 | 0) >>> 0;
 return (tempRet0 = h, l | 0) | 0;
}

function dynCall_iii(index, a1, a2) {
 index = index | 0;
 a1 = a1 | 0;
 a2 = a2 | 0;
 return FUNCTION_TABLE_iii[(SAFE_FT_MASK(index | 0, 7 | 0) | 0) & 7](a1 | 0, a2 | 0) | 0;
}

function SAFE_FT_MASK(value, mask) {
 value = value | 0;
 mask = mask | 0;
 var ret = 0;
 ret = value & mask;
 if ((ret | 0) != (value | 0)) ftfault();
 return ret | 0;
}

function dynCall_vii(index, a1, a2) {
 index = index | 0;
 a1 = a1 | 0;
 a2 = a2 | 0;
 FUNCTION_TABLE_vii[(SAFE_FT_MASK(index | 0, 7 | 0) | 0) & 7](a1 | 0, a2 | 0);
}

function ___lctrans($0, $1) {
 $0 = $0 | 0;
 $1 = $1 | 0;
 var $2 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = ___lctrans_impl($0, $1) | 0;
 return $2 | 0;
}

function ___errno_location() {
 var $0 = 0, $1 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $0 = ___pthread_self_103() | 0;
 $1 = $0 + 64 | 0;
 return $1 | 0;
}

function establishStackSpace(stackBase, stackMax) {
 stackBase = stackBase | 0;
 stackMax = stackMax | 0;
 STACKTOP = stackBase;
 STACK_MAX = stackMax;
}

function setThrew(threw, value) {
 threw = threw | 0;
 value = value | 0;
 if ((__THREW__ | 0) == 0) {
  __THREW__ = threw;
  threwValue = value;
 }
}

function dynCall_ii(index, a1) {
 index = index | 0;
 a1 = a1 | 0;
 return FUNCTION_TABLE_ii[(SAFE_FT_MASK(index | 0, 1 | 0) | 0) & 1](a1 | 0) | 0;
}

function _frexpl($0, $1) {
 $0 = +$0;
 $1 = $1 | 0;
 var $2 = 0.0, label = 0, sp = 0;
 sp = STACKTOP;
 $2 = +_frexp($0, $1);
 return +$2;
}

function dynCall_vi(index, a1) {
 index = index | 0;
 a1 = a1 | 0;
 FUNCTION_TABLE_vi[(SAFE_FT_MASK(index | 0, 7 | 0) | 0) & 7](a1 | 0);
}

function _llvm_bswap_i32(x) {
 x = x | 0;
 return (x & 255) << 24 | (x >> 8 & 255) << 16 | (x >> 16 & 255) << 8 | x >>> 24 | 0;
}

function ___pthread_self_431() {
 var $0 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $0 = _pthread_self() | 0;
 return $0 | 0;
}

function ___pthread_self_104() {
 var $0 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $0 = _pthread_self() | 0;
 return $0 | 0;
}

function ___pthread_self_103() {
 var $0 = 0, label = 0, sp = 0;
 sp = STACKTOP;
 $0 = _pthread_self() | 0;
 return $0 | 0;
}

function setDynamicTop(value) {
 value = value | 0;
 SAFE_HEAP_STORE(DYNAMICTOP_PTR | 0, value | 0, 4);
}

function ___ofl_lock() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 ___lock(3632 | 0);
 return 3640 | 0;
}

function _emscripten_get_global_libc() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 return 3568 | 0;
}

function b1(p0, p1, p2) {
 p0 = p0 | 0;
 p1 = p1 | 0;
 p2 = p2 | 0;
 nullFunc_iiii(1);
 return 0;
}

function ___ofl_unlock() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 ___unlock(3632 | 0);
 return;
}

function _dummy_570($0) {
 $0 = $0 | 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return $0 | 0;
}

function ___unlockfile($0) {
 $0 = $0 | 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return;
}

function ___lockfile($0) {
 $0 = $0 | 0;
 var label = 0, sp = 0;
 sp = STACKTOP;
 return 0;
}

function _pthread_self() {
 var label = 0, sp = 0;
 sp = STACKTOP;
 return 28 | 0;
}

function b3(p0, p1) {
 p0 = p0 | 0;
 p1 = p1 | 0;
 nullFunc_iii(3);
 return 0;
}

function setTempRet0(value) {
 value = value | 0;
 tempRet0 = value;
}

function b2(p0, p1) {
 p0 = p0 | 0;
 p1 = p1 | 0;
 nullFunc_vii(2);
}

function stackRestore(top) {
 top = top | 0;
 STACKTOP = top;
}

function b0(p0) {
 p0 = p0 | 0;
 nullFunc_ii(0);
 return 0;
}

function b4(p0) {
 p0 = p0 | 0;
 nullFunc_vi(4);
}

function getTempRet0() {
 return tempRet0 | 0;
}

function stackSave() {
 return STACKTOP | 0;
}

// EMSCRIPTEN_END_FUNCS
var FUNCTION_TABLE_ii = [b0,___stdio_close];
var FUNCTION_TABLE_iiii = [b1,b1,___stdout_write,___stdio_seek,b1,b1,b1,___stdio_write];
var FUNCTION_TABLE_vii = [b2,b2,b2,b2,b2,b2,_sjf_timerElement_toHTML,b2];
var FUNCTION_TABLE_iii = [b3,b3,b3,b3,b3,_sjf_timerElement_asInterface,b3,b3];
var FUNCTION_TABLE_vi = [b4,b4,b4,b4,_sjf_timerElement_destroy,b4,b4,b4];

  return { _llvm_bswap_i32: _llvm_bswap_i32, _main: _main, _i64Subtract: _i64Subtract, ___udivdi3: ___udivdi3, setThrew: setThrew, _bitshift64Lshr: _bitshift64Lshr, _bitshift64Shl: _bitshift64Shl, _fflush: _fflush, ___errno_location: ___errno_location, _memset: _memset, _sbrk: _sbrk, _memcpy: _memcpy, stackAlloc: stackAlloc, dynCall_vii: dynCall_vii, ___uremdi3: ___uremdi3, dynCall_vi: dynCall_vi, getTempRet0: getTempRet0, setTempRet0: setTempRet0, _i64Add: _i64Add, dynCall_iiii: dynCall_iiii, setDynamicTop: setDynamicTop, _emscripten_get_global_libc: _emscripten_get_global_libc, dynCall_ii: dynCall_ii, stackSave: stackSave, _free: _free, runPostSets: runPostSets, establishStackSpace: establishStackSpace, stackRestore: stackRestore, _malloc: _malloc, dynCall_iii: dynCall_iii };
})
// EMSCRIPTEN_END_ASM
(Module.asmGlobalArg, Module.asmLibraryArg, buffer);

var real__llvm_bswap_i32 = asm["_llvm_bswap_i32"]; asm["_llvm_bswap_i32"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__llvm_bswap_i32.apply(null, arguments);
};

var real__main = asm["_main"]; asm["_main"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__main.apply(null, arguments);
};

var real_setDynamicTop = asm["setDynamicTop"]; asm["setDynamicTop"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_setDynamicTop.apply(null, arguments);
};

var real____udivdi3 = asm["___udivdi3"]; asm["___udivdi3"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real____udivdi3.apply(null, arguments);
};

var real_getTempRet0 = asm["getTempRet0"]; asm["getTempRet0"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_getTempRet0.apply(null, arguments);
};

var real__bitshift64Lshr = asm["_bitshift64Lshr"]; asm["_bitshift64Lshr"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__bitshift64Lshr.apply(null, arguments);
};

var real__bitshift64Shl = asm["_bitshift64Shl"]; asm["_bitshift64Shl"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__bitshift64Shl.apply(null, arguments);
};

var real__fflush = asm["_fflush"]; asm["_fflush"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__fflush.apply(null, arguments);
};

var real__sbrk = asm["_sbrk"]; asm["_sbrk"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__sbrk.apply(null, arguments);
};

var real____errno_location = asm["___errno_location"]; asm["___errno_location"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real____errno_location.apply(null, arguments);
};

var real____uremdi3 = asm["___uremdi3"]; asm["___uremdi3"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real____uremdi3.apply(null, arguments);
};

var real_stackAlloc = asm["stackAlloc"]; asm["stackAlloc"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_stackAlloc.apply(null, arguments);
};

var real__i64Subtract = asm["_i64Subtract"]; asm["_i64Subtract"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__i64Subtract.apply(null, arguments);
};

var real_setTempRet0 = asm["setTempRet0"]; asm["setTempRet0"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_setTempRet0.apply(null, arguments);
};

var real__i64Add = asm["_i64Add"]; asm["_i64Add"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__i64Add.apply(null, arguments);
};

var real__emscripten_get_global_libc = asm["_emscripten_get_global_libc"]; asm["_emscripten_get_global_libc"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__emscripten_get_global_libc.apply(null, arguments);
};

var real_stackSave = asm["stackSave"]; asm["stackSave"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_stackSave.apply(null, arguments);
};

var real__free = asm["_free"]; asm["_free"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__free.apply(null, arguments);
};

var real_setThrew = asm["setThrew"]; asm["setThrew"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_setThrew.apply(null, arguments);
};

var real_establishStackSpace = asm["establishStackSpace"]; asm["establishStackSpace"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_establishStackSpace.apply(null, arguments);
};

var real_stackRestore = asm["stackRestore"]; asm["stackRestore"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real_stackRestore.apply(null, arguments);
};

var real__malloc = asm["_malloc"]; asm["_malloc"] = function() {
  assert(runtimeInitialized, 'you need to wait for the runtime to be ready (e.g. wait for main() to be called)');
  assert(!runtimeExited, 'the runtime was exited (use NO_EXIT_RUNTIME to keep it alive after main() exits)');
  return real__malloc.apply(null, arguments);
};
var _llvm_bswap_i32 = Module["_llvm_bswap_i32"] = asm["_llvm_bswap_i32"];
var _main = Module["_main"] = asm["_main"];
var setDynamicTop = Module["setDynamicTop"] = asm["setDynamicTop"];
var ___udivdi3 = Module["___udivdi3"] = asm["___udivdi3"];
var getTempRet0 = Module["getTempRet0"] = asm["getTempRet0"];
var _bitshift64Lshr = Module["_bitshift64Lshr"] = asm["_bitshift64Lshr"];
var _bitshift64Shl = Module["_bitshift64Shl"] = asm["_bitshift64Shl"];
var _fflush = Module["_fflush"] = asm["_fflush"];
var _memset = Module["_memset"] = asm["_memset"];
var _sbrk = Module["_sbrk"] = asm["_sbrk"];
var _memcpy = Module["_memcpy"] = asm["_memcpy"];
var ___errno_location = Module["___errno_location"] = asm["___errno_location"];
var ___uremdi3 = Module["___uremdi3"] = asm["___uremdi3"];
var stackAlloc = Module["stackAlloc"] = asm["stackAlloc"];
var _i64Subtract = Module["_i64Subtract"] = asm["_i64Subtract"];
var setTempRet0 = Module["setTempRet0"] = asm["setTempRet0"];
var _i64Add = Module["_i64Add"] = asm["_i64Add"];
var _emscripten_get_global_libc = Module["_emscripten_get_global_libc"] = asm["_emscripten_get_global_libc"];
var stackSave = Module["stackSave"] = asm["stackSave"];
var _free = Module["_free"] = asm["_free"];
var runPostSets = Module["runPostSets"] = asm["runPostSets"];
var setThrew = Module["setThrew"] = asm["setThrew"];
var establishStackSpace = Module["establishStackSpace"] = asm["establishStackSpace"];
var stackRestore = Module["stackRestore"] = asm["stackRestore"];
var _malloc = Module["_malloc"] = asm["_malloc"];
var dynCall_ii = Module["dynCall_ii"] = asm["dynCall_ii"];
var dynCall_iiii = Module["dynCall_iiii"] = asm["dynCall_iiii"];
var dynCall_vii = Module["dynCall_vii"] = asm["dynCall_vii"];
var dynCall_iii = Module["dynCall_iii"] = asm["dynCall_iii"];
var dynCall_vi = Module["dynCall_vi"] = asm["dynCall_vi"];
;
Runtime.stackAlloc = Module['stackAlloc'];
Runtime.stackSave = Module['stackSave'];
Runtime.stackRestore = Module['stackRestore'];
Runtime.establishStackSpace = Module['establishStackSpace'];
Runtime.setDynamicTop = Module['setDynamicTop'];
Runtime.setTempRet0 = Module['setTempRet0'];
Runtime.getTempRet0 = Module['getTempRet0'];


// === Auto-generated postamble setup entry stuff ===

Module['asm'] = asm;





  Module['cyberdwarf'] = _cyberdwarf_Debugger(cyberDWARFFile);


/**
 * @constructor
 * @extends {Error}
 */
function ExitStatus(status) {
  this.name = "ExitStatus";
  this.message = "Program terminated with exit(" + status + ")";
  this.status = status;
};
ExitStatus.prototype = new Error();
ExitStatus.prototype.constructor = ExitStatus;

var initialStackTop;
var preloadStartTime = null;
var calledMain = false;

dependenciesFulfilled = function runCaller() {
  // If run has never been called, and we should call run (INVOKE_RUN is true, and Module.noInitialRun is not false)
  if (!Module['calledRun']) run();
  if (!Module['calledRun']) dependenciesFulfilled = runCaller; // try this again later, after new deps are fulfilled
}

Module['callMain'] = Module.callMain = function callMain(args) {
  assert(runDependencies == 0, 'cannot call main when async dependencies remain! (listen on __ATMAIN__)');
  assert(__ATPRERUN__.length == 0, 'cannot call main when preRun functions remain to be called');

  args = args || [];

  ensureInitRuntime();

  var argc = args.length+1;
  function pad() {
    for (var i = 0; i < 4-1; i++) {
      argv.push(0);
    }
  }
  var argv = [allocate(intArrayFromString(Module['thisProgram']), 'i8', ALLOC_NORMAL) ];
  pad();
  for (var i = 0; i < argc-1; i = i + 1) {
    argv.push(allocate(intArrayFromString(args[i]), 'i8', ALLOC_NORMAL));
    pad();
  }
  argv.push(0);
  argv = allocate(argv, 'i32', ALLOC_NORMAL);


  try {

    var ret = Module['_main'](argc, argv, 0);


    // if we're not running an evented main loop, it's time to exit
    exit(ret, /* implicit = */ true);
  }
  catch(e) {
    if (e instanceof ExitStatus) {
      // exit() throws this once it's done to make sure execution
      // has been stopped completely
      return;
    } else if (e == 'SimulateInfiniteLoop') {
      // running an evented main loop, don't immediately exit
      Module['noExitRuntime'] = true;
      return;
    } else {
      var toLog = e;
      if (e && typeof e === 'object' && e.stack) {
        toLog = [e, e.stack];
      }
      Module.printErr('exception thrown: ' + toLog);
      Module['quit'](1, e);
    }
  } finally {
    calledMain = true;
  }
}




/** @type {function(Array=)} */
function run(args) {
  args = args || Module['arguments'];

  if (preloadStartTime === null) preloadStartTime = Date.now();

  if (runDependencies > 0) {
    return;
  }

  writeStackCookie();

  preRun();

  if (runDependencies > 0) return; // a preRun added a dependency, run will be called later
  if (Module['calledRun']) return; // run may have just been called through dependencies being fulfilled just in this very frame

  function doRun() {
    if (Module['calledRun']) return; // run may have just been called while the async setStatus time below was happening
    Module['calledRun'] = true;

    if (ABORT) return;

    ensureInitRuntime();

    preMain();

    if (ENVIRONMENT_IS_WEB && preloadStartTime !== null) {
      Module.printErr('pre-main prep time: ' + (Date.now() - preloadStartTime) + ' ms');
    }

    if (Module['onRuntimeInitialized']) Module['onRuntimeInitialized']();

    if (Module['_main'] && shouldRunNow) Module['callMain'](args);

    postRun();
  }

  if (Module['setStatus']) {
    Module['setStatus']('Running...');
    setTimeout(function() {
      setTimeout(function() {
        Module['setStatus']('');
      }, 1);
      doRun();
    }, 1);
  } else {
    doRun();
  }
  checkStackCookie();
}
Module['run'] = Module.run = run;

function exit(status, implicit) {
  if (implicit && Module['noExitRuntime']) {
    Module.printErr('exit(' + status + ') implicitly called by end of main(), but noExitRuntime, so not exiting the runtime (you can use emscripten_force_exit, if you want to force a true shutdown)');
    return;
  }

  if (Module['noExitRuntime']) {
    Module.printErr('exit(' + status + ') called, but noExitRuntime, so halting execution but not exiting the runtime or preventing further async execution (you can use emscripten_force_exit, if you want to force a true shutdown)');
  } else {

    ABORT = true;
    EXITSTATUS = status;
    STACKTOP = initialStackTop;

    exitRuntime();

    if (Module['onExit']) Module['onExit'](status);
  }

  if (ENVIRONMENT_IS_NODE) {
    process['exit'](status);
  }
  Module['quit'](status, new ExitStatus(status));
}
Module['exit'] = Module.exit = exit;

var abortDecorators = [];

function abort(what) {
  if (Module['onAbort']) {
    Module['onAbort'](what);
  }

  if (what !== undefined) {
    Module.print(what);
    Module.printErr(what);
    what = JSON.stringify(what)
  } else {
    what = '';
  }

  ABORT = true;
  EXITSTATUS = 1;

  var extra = '';

  var output = 'abort(' + what + ') at ' + stackTrace() + extra;
  if (abortDecorators) {
    abortDecorators.forEach(function(decorator) {
      output = decorator(output, what);
    });
  }
  throw output;
}
Module['abort'] = Module.abort = abort;

// {{PRE_RUN_ADDITIONS}}

if (Module['preInit']) {
  if (typeof Module['preInit'] == 'function') Module['preInit'] = [Module['preInit']];
  while (Module['preInit'].length > 0) {
    Module['preInit'].pop()();
  }
}

// shouldRunNow refers to calling main(), not run().
var shouldRunNow = true;
if (Module['noInitialRun']) {
  shouldRunNow = false;
}


run();

// {{POST_RUN_ADDITIONS}}





// {{MODULE_ADDITIONS}}







