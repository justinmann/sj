--cinclude--
##ifdef __GNUC__
	##if __x86_64__ 
		##define __LINUX__
		##define __64__
	##elif __i386__ 
		##define __LINUX__
		##define __32__
	##else
		Invalid bits
	##endif
##elif _MSC_VER
	##if _WIN64 
		##define __WINDOWS__
		##define __64__
	##elif _WIN32 
		##define __WINDOWS__
		##define __32__
	##else
		Invalid bits
	##endif
##else
	Invalid compiler
##endif


#include(<stdio.h>)
#include(<stdarg.h>)
#include(<stdint.h>)
#include(<stdlib.h>)
#include(<string.h>)
#include(<windows.h>, __WINDOWS__)
--cinclude--


include "khash.sj"
include "array.sj"
include "bool.sj"
include "console.sj"
include "debug.sj"
include "f32.sj"
include "halt.sj"
include "hash.sj"
include "i32.sj"
include "list.sj"
include "string.sj"
include "tuple.sj"
include "weakptr.sj"
