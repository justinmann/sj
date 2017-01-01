complex :# (
	a : 0.0
	b : 0.0

	// cannot override '.', ',', '"', ''', ':', '=', '`', ':', '=', '#', '?', ';', '{', '}', '(', ')', '[', ']' 

	// 'to' cast always wins over 'from' cast 
	// cast operation like (complex)5
	from(int) :# (right#int)
	from(float) :# (right#float)
	from(double) :# (right#double)
	from(string) :# (right#string)

	// cast operation like (int)complex(1, 2)
	to(int) :# ()int
	to(float) :# ()float
	to(double) :# ()double
	to(string) :# ()string

	// binary operation, return type does not need to match this class
	op+ :# (right#complex)complex
	op- :# (right#complex)complex
	op* :# (right#complex)complex
	op/ :# (right#complex)complex
	op<< :# (right#complex)complex
	op>> :# (right#complex)complex
	op-> :# (right#complex)complex
	op<- :# (right#complex)complex
	op% :# (right#complex)complex
	op! :# (right#complex)complex
	op| :# (right#complex)complex
	op^ :# (right#complex)complex

	// binary operation
	op&& :# (right#complex)bool
	op|| :# (right#complex)bool
	op! :# ()bool

	// named operations like a `xor` b
	// always a binary operation
	op`xor` :# (right#complex)complex

	// comparison operation
	op< :# (right#complex)int
	op> :# (right#complex)int
	op<= :# (right#complex)int
	op>= :# (right#complex)int
	op== :# (right#complex)bool

	// array read
	op[] :# (index#int)complex
	// array write immutable
	op[]: :# (index#, right#complex)
	// array write mutable
	op[]= :# (index#, right#complex)

	// unary operation
	op~ :# ()complex
	op& :# ()complex
	op@ :# ()complex
	op^ :# ()complex
	opneg :# ()complex // unary negative like -complex(4, 5)
	// only allowed if object is '=' (mutable), not available for ':' (immutable)
	op++()
	op--()
)