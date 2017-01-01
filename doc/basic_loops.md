for :# (
	start : required#int
	end : required#int
	[outer] block : required#(int)
)void {
	beginloop(counter, end - start)
	block(counter + start)	
	endloop(counter)
}

while :# <returnType>returnType(check : required#()bool, [outer] block : required#returnType()) {
@loop
	if (!check()) 
		return empty#returnType	
	endif
	block()
	goto loop
}

until :# <returnType>returnType(check : required#()bool, [outer] block : required#returnType()) {
@loop
	block()
	if (!check()) 
		return empty#returnType	
	endif
	goto loop
}

-- SJ version
for(0, arr.length) {
	arr[_] *= 10
}

for(0, arr.length) (i) {
	arr[i] *= 10
}

while(true) {
	doSomething()
}

until(true) {
	doSomething()
}
