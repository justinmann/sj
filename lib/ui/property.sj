property!t(
	t := 't
	invalidate : list![()void]()

	get() { local t }

	set(x : 't) { 
		if (t != x) {
			t = copy x
			for i (0 to invalidate.count) {
				cb : invalidate[i]
				cb()
			} 
		}
		void
	}

	animate(x : 't, duration : 'i32) {
		animator.animations.add(animation!t(
			start : animator.current
			startValue : copy t
			end : animator.current + duration
			endValue : copy x
			setValue : set
		) as #animation)
		void
	}	
) { this }