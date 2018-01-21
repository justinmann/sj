class(
	doThing1() {
		log.info(parent.type, ^{ "doThing1" })	
	}
) { 
	log.info(this.type, ^{ "init" })	
	log.error(this.type, ^{ "oh my god" })
	this 
}

log.minLevel = logLevel.info

c : class()
c.doThing1()