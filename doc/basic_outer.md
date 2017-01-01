control :# (
	onClick = empty#()
	[outer] children = empty#array<control>
)

-- examples

control(onClick = clicked()) [
	control(onClick = clicked())
]

c: f1			// (array<int>)(int)'bool
d: f1(1)		// bool, b is default
e: f1(1, 2)		// bool, b is 2
f: f1(1) { 2 }	// bool, b is 2
g: f1(1) [ 2 ]	// bool, b is [2]
