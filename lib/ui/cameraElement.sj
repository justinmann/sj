boringShader : shader("shaders/v3f-n3f.vert", "shaders/v3f-n3f.frag")

cameraElement #element (
	color = colors.white()
	idealSize = size()
	rect = rect()
	_cube : cubeVertexBuffer()

	getSize(maxSize : 'size) {
		idealSize.cap(maxSize)
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		if rect != rect_ {
			rect = copy rect_
			void
		}
		void
	}

	render(scene : 'scene2d)'void {
		--c--
		mat4* projection = mat4_new();
		mat4_set_perspective(projection, 90.0f, 1.0f, 1.0f, 10.0f);

		mat4* view = mat4_new();
		vec3 position = { 0.0f, 0.0f, 10.0f };
		vec3 target = { 0.0f, 0.0f, 0.0f };
		vec3 up = { 0.0f, 1.0f, 0.0f }; 
		mat4_set_lookAtLH(view, &position, &target, &up);

		mat4* world = mat4_new();
		mat4_set_rotation(world, 30.0f, 0.0f, 1.0f, 0.0f);

        glUseProgram(sjv_boringShader.id);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "model" ), 1, 0, world->data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "view" ), 1, 0, view->data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boringShader.id, "projection" ), 1, 0, projection->data);
		--c--
		_cube.render(scene)
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }
