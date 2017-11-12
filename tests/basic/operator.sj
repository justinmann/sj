fancyMath(
	x =' i32

	add(num :' fancyMath) {
		fancyMath(x + num.x + 1)
	}

	subtract(num :' fancyMath) {
		fancyMath(x - num.x + 1)
	}

	multiply(num :' fancyMath) {
		fancyMath(x * num.x + 1)
	}

	divide(num :' fancyMath) {
		fancyMath(x / num.x + 1)
	}

	modulus(num :' fancyMath) {
		fancyMath(x % num.x + 1)
	}

	increment() {
		fancyMath(x + 1)
	}

	decrement() {
		fancyMath(x - 1)
	}

	getX() {
		x
	}

	setBob(i : 0) {
		x = i
	}
) { this }

a : fancyMath(1)
b : fancyMath(2)
c = a + b
d = a - b
e = a * b
f = a / b
g = a % b
c += c
d -= d
d *= d
d /= d
e ++
f ++
i = f.x
j = a.bob = 12