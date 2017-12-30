property!t(
    t := 't
    invalidate : list![()void]()
    _isDirty := false

    get() { local t }

    set(x : 't) { 
        if (t != x) {
            t = x
            _isDirty = true
            for i : 0 to invalidate.count {
                cb : invalidate[i]
                cb()
            } 
        }
        void
    }

    animate(x : 't, duration : 'i32) {
        animator.animations.add(animation!t(
            start : animator.current
            startValue : t
            end : animator.current + duration
            endValue : x
            setValue : heap parent.set
        ) as #animation)
        void
    }   

    getIsDirty() {
        if _isDirty {
            _isDirty = false
            true
        } else {
            false
        }
    }
) { this }