nauScene3dElement #element (
	children : array!#model()
	lookAtMin := vec3()
	lookAtMax := vec3()
	fieldOfView := 90.0f
	zNear := 1.0f
	zFar := 20.0f
	light := light()
	projection := mat4()
	view := mat4_lookAtLH(vec3(0.0f, 0.0f, -5.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f))
	world := mat4_identity()
	_rect := rect()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { _rect }

	setRect(rect_ : 'rect)'void {
		if _rect != rect_ {
			_rect = copy rect_
			projection = mat4_perspective(fieldOfView, _rect.h as f32 / _rect.w as f32, zNear, zFar)
		}
		void
	}

	render(scene : 'scene2d)'void {
		for i : 0 to children.count {
			child : children[i]
			child.setWorld(world)
		}

		--c--
	    glEnable( GL_DEPTH_TEST );
		--c--

		for i : 0 to children.count {
			child : children[i]
			child.render(projection, view, light)
		}

		--c--
	    glDisable( GL_DEPTH_TEST );
		--c--
	}

	_isDragging := false
	_startDrag := point()
	_lookAt := vec3(0.0f, 0.0f, 0.0f)
	_lookAtDrag := vec3()

	fireMouseEvent(point: 'point, eventId : 'i32)'void {
		if eventId == mouseEvent_down {
			_isDragging = true
			_startDrag = copy point
			_lookAtDrag = copy _lookAt
		}

		if eventId == mouseEvent_move && _isDragging {
			_lookAt = vec3_min(lookAtMax, vec3_max(lookAtMin, _lookAtDrag + vec3(
				(_startDrag.x - point.x) as f32 / _rect.w as f32 * 2.0f
				(point.y - _startDrag.y) as f32 / _rect.h as f32 * 2.0f
				0.0f
			)))
			camera : _lookAt - vec3(0.0f, 0.0f, 5.0f)
			view = mat4_lookAtLH(camera, _lookAt, vec3(0.0f, 1.0f, 0.0f))
		}

		if eventId == mouseEvent_up {
			_isDragging = false
		}

		for i : 0 to children.count {
			child : children[i]
			child.fireMouseEvent(_rect, projection, view, point, eventId)
		}
	}

	updateViewport()'void {
		--c--
	    glViewport(_parent->_rect.x, _parent->_rect.y, _parent->_rect.w, _parent->_rect.h);
	    glEnable( GL_DEPTH_TEST );
		--c--	
	}
) { this }