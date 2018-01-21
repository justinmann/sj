class(
	x : 'i32
) { this }

a : list!heap class()
for i : 0 to 100 {
	a.add(heap class(i))
}
