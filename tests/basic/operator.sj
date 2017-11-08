fancyMath(
	x :' i32

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