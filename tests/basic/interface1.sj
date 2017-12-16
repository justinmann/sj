package namespace1 {
	#foo(
		test1()'i32
	)

	class #foo (
		test1() { 5 }
	) { this }
}

package namespace2 {
	#foo(
		test2()'i32
	)

	class #foo (
		test2() { 5 }
	) { this }
}

a: namespace1.class() as namespace1.#foo
b: namespace2.class() as namespace2.#foo