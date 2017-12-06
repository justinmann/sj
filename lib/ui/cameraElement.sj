boringShader : shader("shaders/v3f-n3f-phong.vert", "shaders/v3f-n3f-phong.frag")

cameraElement #element (
	rect = rect()
	_cube : cubeVertexBuffer()
	projection = mat4()
	view = mat4()
	model = mat4()
	viewModel = mat4()
	normalMat = mat4()
	angle = 0.0f

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		if rect != rect_ {
			rect = copy rect_
			projection = mat4_perspective(90.0f, rect.h as f32 / rect.w as f32, 1.0f, 10.0f)
			view = mat4_lookAtLH(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f))
			model = mat4_rotation(30.0f, 0.0f, 1.0f, 0.0f)
			viewModel = view * model
			normalMat = viewModel.invert().transpose()
			void
		}
		void
	}

	render(scene : 'scene2d)'void {
		angle += 0.2f

		model = mat4_rotation(angle, 0.0f, 1.0f, 0.0f)
		viewModel = view * model
		normalMat = viewModel.invert().transpose()
		--c--
	    glEnable( GL_DEPTH_TEST );
        glUseProgram(sjv_boringShader.id);
        // glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "model" ), 1, 0, (GLfloat*)&_parent->world);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "viewModel" ), 1, 0, (GLfloat*)&_parent->viewModel);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "normalMat" ), 1, 0, (GLfloat*)&_parent->normalMat);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "projection" ), 1, 0, (GLfloat*)&_parent->projection);
		--c--
		_cube.render(scene)
		--c--
	    glDisable( GL_DEPTH_TEST );
		--c--
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }
