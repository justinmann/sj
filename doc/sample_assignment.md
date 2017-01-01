main(
	classA(
		w : required'object
		x = required'object
		
		funcB(y : required'stack object) {
			classA(null, y)
		}
	)

	b = null'object
	c : list<object>()
) {
	a : classA(w : null, x = null)
	b = classA()		// b out of function scope so it must be on heap
	c.add(a)			// invalid since c is out of scope and a is stack it cannot be stored
	c.add(b)
}

stack any assignment using :
* can be stored in scope variables
* can be passed in as variable if also stack

heap any assignment using =
* can be stored in any variable
* can be passed in as any variable

-----
class complex {
	complex(int real, int imag) {
		this.real = real;
		this.imag = imag;
	}

	int add(int real, int imag) {
		return new complex(this.real + real, this.imag + iaag);
	}
}

int main() {
	complex* a = new complex(1, 2); // 1 + 2i
	complex* c = a->add(2, 3);
	delete a;
	delete c;
}