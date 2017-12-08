scene3dElement #element (
	children : array!#model()
	camera = vec3(0.0f, 0.0f, -5.0f)
	lookAt = vec3(0.0f, 0.0f, 0.0f)
	up = vec3(0.0f, 1.0f, 0.0f)
	fieldOfView = 90.0f
	zNear = 1.0f
	zFar = 20.0f
	lightPos = vec3(1.0f, 1.0f, 1.0f)
	diffuseColor = color(0.5f, 0.5f, 0.0f, 1.0f)
	specColor = color(1.0f, 1.0f, 1.0f, 1.0f)
	projection = mat4()
	view = mat4()
	_rect = rect()
	_angle = 0.0f
	_isUp = true

	_cube : cubeVertexBuffer()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { _rect }

	setRect(rect_ : 'rect)'void {
		if _rect != rect_ {
			_rect = copy rect_
			projection = mat4_perspective(fieldOfView, _rect.h as f32 / _rect.w as f32, zNear, zFar)
			view = mat4_lookAtLH(camera, lookAt, up)
			void
		}
		void
	}

	render(scene : 'scene2d)'void {
		if _isUp { 
			_angle += 0.2f
			if _angle >= 90.0f {
				_isUp = false
			}
		} else {
			_angle -= 0.2f
			if _angle <= -90.0f {
				_isUp = true
			}
		}
		world : mat4_rotation(_angle, 0.0f, 1.0f, 0.0f)
		for i (0 to children.size) {
			child : children[i]
			child.setWorld(world)
		}

		--c--
	    glEnable( GL_DEPTH_TEST );
		--c--

		for i (0 to children.size) {
			child2 : children[i]
			child2.render(parent)
		}

		--c--
	    glDisable( GL_DEPTH_TEST );
		--c--
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	fireMouseEvent(point: 'point, eventId : 'i32)'void {
		for i (0 to children.size) {
			child : children[i]
			child.fireMouseEvent(parent, point, eventId)
		}
	}

	updateViewport()'void {
		--c--
	    glViewport(_parent->_rect.x, _parent->_rect.y, _parent->_rect.w, _parent->_rect.h);
		--c--	
	}
) { this }