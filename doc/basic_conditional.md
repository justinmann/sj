match
---
case :# <returnType> (
	check : required#()bool
	[outer] result : required#()returnType
)

match :# <returnType>(
	[outer] cases : required#array<case<returnType>>
	[outer] else : required#()ret 
)returnType {
	items.findAndRun(check: {
		_.check()
	}, run: {
		_.result()
	}, else: default)
}

if :# <returnType>(
	[outer] check : required#()bool
	[outer] resultTrue : required#()returnType
	[outer] resultFalse : empty#?()returnType
)returnType {
	gotoifnot(check(), checkFalse)
	exit(resultTrue())
@checkFalse
	gotoif(resultFalse == empty, noFalse)
	exit(resultFalse())
@noFalse
	exit(default#returnType) // This does nothing since the return value is always default if not specified 
}


-- examples
if { true } { doThis() }

if (true) { doThis() }
if (true) { 
	doThis() 
} {
	elseDoThis()
}

if (true) { 
	doThis() 
} {
	if (true) { 
		elseIfdoThis() 
	} {
		elseDoThis()
	}
}

if (
	check: true
	resultTrue: doThis()
	resultFalse: elseDoThis()
)

match [
	case(a == 1) { 11 }
	case(a == 2) { 12 }
	case(a == 3) { a + 13 }
] { 0 }

match(
	cases: [
		case(a == 1) { 11 }
		case(a == 2) { 12 }
		case(a == 3) { a + 13 }
	]
	else: 0
)