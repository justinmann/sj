enum logLevel(
	trace
	debug
	info
	warn
	error
	fatal
)

log_includeAll : empty'hash![type, bool]
log_excludeAll : valid(hash![type, bool]())

log(
	minLevel := logLevel.warn
    traceIncludes := copy log_includeAll
    debugIncludes := copy log_includeAll
    infoIncludes := copy log_includeAll
    warnIncludes := copy log_includeAll
    errorIncludes := copy log_includeAll
    fatalIncludes := copy log_includeAll

    trace(t : 'type, cb : '()string) {
        _write(logLevel.trace, traceIncludes, t, cb)
    }

    debug(t : 'type, cb : '()string) {
        _write(logLevel.debug, debugIncludes, t, cb)
    }

    info(t : 'type, cb : '()string) {
        _write(logLevel.info, infoIncludes, t, cb)
    }

    warn(t : 'type, cb : '()string) {
        _write(logLevel.warn, warnIncludes, t, cb)
    }

    error(t : 'type, cb : '()string) {
        _write(logLevel.error, errorIncludes, t, cb)
    }

    fatal(t : 'type, cb : '()string) {
        _write(logLevel.fatal, fatalIncludes, t, cb)
    }

    _write(level : 'logLevel, includes : 'hash?![type, bool], t : 'type, cb : '()string) {
        if level >= minLevel {
            ifValid includes {
                if includes[t]?:false {
                    debug.writeLine(level.asString().toUpperCase() + " [" + t.asString() + "] " + cb())
                }
            } elseEmpty {            
                debug.writeLine(level.asString().toUpperCase() + " [" + t.asString() + "] " + cb())
            }
        }
    }
) { this }

log : log()