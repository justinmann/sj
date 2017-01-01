classA () {
	
}

classB'classA () {
	
}

functionByValue()'classA {
	classA()	// return location is pre-allocated on stack/heap depending on caller
}

functionByValue()'classA {
	classB()	// illegal: when return by value type must be an exact match
}

functionByRef()'ref classA {
	classA()	// allocated on heap
}

functionByRef()'ref classA {
	classB()	// allocated on heap
}