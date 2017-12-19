light(
	pos : vec3(1.0f, 1.0f, 1.0f)
	diffuseColor : color(0.5f, 0.5f, 0.0f, 1.0f)
	specColor : color(1.0f, 1.0f, 1.0f, 1.0f)
) { this }

model_hasAlpha(m : '#model) {
	m.hasAlpha
}

scene3dElement #element (
	children : array!heap #model()
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

	getRect()'rect { copy _rect }

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
			child.update(_rect, projection, view, world, light)
		}

	    glEnable(glFeature.GL_DEPTH_TEST)

	    a : list!#model()

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

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
		for i : 0 to children.count {
			child : children[i]
			child.fireMouseEvent(mouseEvent)
		}
	}
) { this }