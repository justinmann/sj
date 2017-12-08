scene3dElement #element (
	children : array!#model()
	camera = vec3(0.0f, 0.0f, 10.0f)
	lookAt = vec3(0.0f, 0.0f, 0.0f)
	up = vec3(0.0f, 1.0f, 0.0f)
	fieldOfView = 90.0f
	zNear = 1.0f
	zFar = 10.0f
	lightPos = vec3(1.0f, 1.0f, 1.0f)
	diffuseColor = color(0.5f, 0.5f, 0.0f, 1.0f)
	specColor = color(1.0f, 1.0f, 1.0f, 1.0f)
	projection = mat4()
	view = mat4()
	_rect = rect()
	_angle = 0.0f

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
		_angle += 0.2f
		model : mat4_rotation(_angle, 0.0f, 1.0f, 0.0f)

		--c--
	    glEnable( GL_DEPTH_TEST );
		--c--

		for i (0 to children.size) {
			child : children[i]
			child.render(parent, model)
		}

		--c--
	    glDisable( GL_DEPTH_TEST );
		--c--
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	fireMouseEvent(point: 'point, eventId : 'i32)'void {
		// TODO: convert to 3-d vector and hit test children
	}
) { this }