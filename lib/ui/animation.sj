#animation(
	nextFrame()'bool
)

animation!t #animation (
	start : 'i32
	startValue : 't
	end : 'i32
	endValue : 't
	setValue : 'heap (:t)void

	nextFrame(time : 'i32)'bool {
		percent := (time - start) as f32 / (end - start) as f32
		if percent < 0.0f {
			percent = 0.0f
		} else if percent > 1.0f {
			percent = 1.0f
		}

		// interoplate & set value
		setValue(startValue.interpolate(endValue, percent))
		// If after end return false
		percent == 1.0f
	}
) { this }

animator: ^(
	animations : list!#animation()
	current := 0

	nextFrame(time : 'i32) {
		current = time
		// Iterate and remove all that return false
	}
) { this }