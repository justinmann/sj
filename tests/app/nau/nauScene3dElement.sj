@heap
nauScene3dElement #element (
    children : array!heap #model()
    lookAtMin := vec3()
    lookAtMax := vec3()
    cameraDistance := 5.0f
    fieldOfView := 90.0f
    zNear := 1.0f
    zFar := 100.0f
    light := light()
    projection := mat4()
    view := mat4_lookAtLH(vec3(0.0f, 0.0f, -5.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f))
    world := mat4_identity()
    _rect := rect()

    getSize(maxSize : 'size) {
        size(maxSize.w, maxSize.h)
    }

    getRect()'rect { copy _rect }

    setRect(rect_ : 'rect)'void {
        if _rect != rect_ {
            _rect = copy rect_
            projection = copy mat4_perspective(fieldOfView, _rect.h as f32 / _rect.w as f32, zNear, zFar)
        }
        void
    }

    animateLookAt(v : 'vec3, duration : 'i32) {
        animator.animations.add(
            heap animation!vec3(
                startValue : copy _lookAt
                endValue : copy v
                start : animator.current
                end : animator.current + duration
                setValue : parent.setLookAt
            ) as #animation
        )
        void
    }

    animateCameraDistance(v : 'f32, duration : 'i32) {
        animator.animations.add(
            heap animation!f32(
                startValue : cameraDistance
                endValue : v
                start : animator.current
                end : animator.current + duration
                setValue : parent.setCameraDistance
            ) as #animation
        )
        void
    }

    setCameraDistance(v : 'f32) {
        cameraDistance = v
        void
    }

    setLookAt(v : 'vec3) {
        _lookAt = copy v
        void
    }

    render(scene : 'scene2d)'void {
        camera : _lookAt - vec3(0.0f, 0.0f, cameraDistance)
        view = copy mat4_lookAtLH(camera, _lookAt, vec3(0.0f, 1.0f, 0.0f))

        for i : 0 to children.count {
            child : children[i]
            child.update(_rect, projection, view, world, light)
        }

        glEnable(glFeature.GL_DEPTH_TEST)

        a : list!heap #model()

        for i : 0 to children.count {
            child : children[i]
            child.renderOrQueue(a)
        }

        a.sortcb(model_zsort)
        for i : 0 toReverse a.count {
            child : a[i]
            child.render()
        }

        glDisable(glFeature.GL_DEPTH_TEST)
    }

    _isDragging := false
    _startDrag := point()
    _lookAt := vec3(0.0f, 0.0f, 0.0f)
    _lookAtDrag := vec3()

    fireMouseEvent(mouseEvent : 'mouseEvent) {
        switch mouseEvent.type {
            mouseEventType.down {
                _startDrag = copy mouseEvent.point
                _lookAtDrag = copy _lookAt
                mouse_capture(parent as #element)
            }

            mouseEventType.move {
                if mouse_hasCapture(parent as #element) {
                    _lookAt = copy vec3_min(lookAtMax, vec3_max(lookAtMin, _lookAtDrag + vec3(
                        (_startDrag.x - mouseEvent.point.x) as f32 / _rect.w as f32 * 2.0f
                        (mouseEvent.point.y - _startDrag.y) as f32 / _rect.h as f32 * 2.0f
                        0.0f
                    )))
                    camera : _lookAt - vec3(0.0f, 0.0f, cameraDistance)
                    view = copy mat4_lookAtLH(camera, _lookAt, vec3(0.0f, 1.0f, 0.0f))
                    void
                }
            }

            mouseEventType.up {
                mouse_release(parent as #element)
            }
        }

        if !mouse_hasCapture(parent as #element) {
            for i : 0 to children.count {
                child : children[i]
                child.fireMouseEvent(mouseEvent)
            }
        }

        true
    }
) { this }