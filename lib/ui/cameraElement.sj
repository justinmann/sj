boringShader : shader("shaders/v3f-n3f.vert", "shaders/v3f-n3f.frag")

cameraElement #element (
	rect = rect()
	_cube : cubeVertexBuffer()
	projection = mat4()
	view = mat4()
	world = mat4()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		if rect != rect_ {
			rect = copy rect_
			projection = mat4_perspective(90.0f, rect.h as f32 / rect.w as f32, 1.0f, 10.0f)
			view = mat4_lookAtLH(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f))
			world = mat4_rotation(30.0f, 0.0f, 1.0f, 0.0f)
			void
		}
		void
	}

	render(scene : 'scene2d)'void {
		--c--
        glUseProgram(sjv_boringShader.id);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "model" ), 1, 0, (GLfloat*)&_parent->world);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "view" ), 1, 0, (GLfloat*)&_parent->view);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "projection" ), 1, 0, (GLfloat*)&_parent->projection);
		--c--
		_cube.render(scene)
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }
