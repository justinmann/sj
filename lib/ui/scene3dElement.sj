light(
	pos : vec3(1.0f, 1.0f, 1.0f)
	diffuseColor : color(0.5f, 0.5f, 0.0f, 1.0f)
	specColor : color(1.0f, 1.0f, 1.0f, 1.0f)
) { this }

scene3dElement #element (
	children : array!#model()
	camera := vec3(0.0f, 0.0f, -5.0f)
	lookAt := vec3(0.0f, 0.0f, 0.0f)
	up := vec3(0.0f, 1.0f, 0.0f)
	fieldOfView := 90.0f
	zNear := 1.0f
	zFar := 20.0f
	light := light()
	projection := mat4()
	view := mat4()
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
			view = mat4_lookAtLH(camera, lookAt, up)
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
			child.render(_rect, projection, view, light)
		}

		--c--
	    glDisable( GL_DEPTH_TEST );
		--c--
	}

	fireMouseEvent(point: 'point, eventId : 'i32)'void {
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