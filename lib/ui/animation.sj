#animation(
    nextFrame(time : 'i32)'bool
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

 animator(
    animations : list!heap #animation()
    current := 0

    nextFrame(time : 'i32) {
        current = time
        if animations.count > 0 {
            // Iterate and remove all that return false
            for i : 0 toReverse animations.count {
                a : animations[i]
                if a.nextFrame(time) {
                    animations.removeAt(i)
                }
            }
        }
        void
    }
) { this }

animator : animator()

i32_interpolate(x : 'i32, y : 'i32, percent : 'f32) {
    (x as f32 * (1.0f - percent) + y as f32 * percent) as i32
}

f32_interpolate(x : 'f32, y : 'f32, percent : 'f32) {
    x * (1.0f - percent) + y * percent
}