enum logLevel(
	trace
	debug
	info
	warn
	error
	fatal
)

//log_includeAll : empty'hash![type, bool]
//log_excludeAll : valid(hash![type, bool]())

log(
	minLevel := logLevel.warn
//	infoIncludes := log_includeAll

    info(cb : '()string) {
    	if logLevel.info >= minLevel {
//    		isValid : infoIncludes?.getAt(t)?:false
//    		if isValid {
    			_write(logLevel.info, cb)
//    		}
    	}
    }

    _write(level : 'logLevel, cb : '()string) {
    	debug.writeLine("[" + level.asString() + "] " + cb())
    }
) { this }

log : log()