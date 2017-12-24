bar(f := foo(1)) { this }
foo(x : 0) { this }

func(b : 'bar)'foo {
  b.f = foo(2) // callvar("foo") is heap because it is store in a non-local var
  copy b.f
}

b : bar() // callvar("boo") is stack because it is stored in a local var
func(b).x