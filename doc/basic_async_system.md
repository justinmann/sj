// Must be implemented outside of language
 asyncQueue : (
	create :# (name : empty#?string)		// If name is passed, will find existing queue matching name
	queue :# (id : required#int, data : required#blob)
	dequeue :# (id : required#int):blob
	wait :# (ids : required#array<int>)
)

threads : (
	idealCount : 4	// Usually equal to number of cores
)