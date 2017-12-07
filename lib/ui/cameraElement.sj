phongShader : shader("shaders/v3f-n3f-phong.vert", "shaders/v3f-n3f-phong.frag")

cameraElement #element (
	rect = rect()
	_cube : cubeVertexBuffer()
	projection = mat4()
	view = mat4()
	model = mat4()
	viewModel = mat4()
	normalMat = mat4()
	angle = 0.0f
	lightPos = vec3(1.0f, 1.0f, 1.0f);
	diffuseColor = color(0.5f, 0.5f, 0.0f, 1.0f);
	specColor = color(1.0f, 1.0f, 1.0f, 1.0f);

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
        glUseProgram(sjv_phongShader.id);
        glUniformMatrix4fv(glGetUniformLocation(sjv_phongShader.id, "viewModel" ), 1, 0, (GLfloat*)&_parent->viewModel);
        glUniformMatrix4fv(glGetUniformLocation(sjv_phongShader.id, "normalMat" ), 1, 0, (GLfloat*)&_parent->normalMat);
        glUniformMatrix4fv(glGetUniformLocation(sjv_phongShader.id, "projection" ), 1, 0, (GLfloat*)&_parent->projection);
        glUniform3fv(glGetUniformLocation(sjv_phongShader.id, "lightPos" ), 1, (GLfloat*)&_parent->lightPos);
        glUniform3fv(glGetUniformLocation(sjv_phongShader.id, "diffuseColor" ), 1, (GLfloat*)&_parent->diffuseColor);
        glUniform3fv(glGetUniformLocation(sjv_phongShader.id, "specColor" ), 1, (GLfloat*)&_parent->specColor);
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
