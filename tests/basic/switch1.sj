class(
	bob : 1
	isEqual(r : 'class) {
		bob == r.bob
	}
) { this }

a : class(3)
y : switch a {
	class(4)		{ 1 } 
	_ == class(2)   { 2 }
	default 		{ 3 }
}