#model(
	setWorld(world : 'mat4)'void
	render(scene3d : 'scene3dElement)'void
	fireMouseEvent(scene3d : 'scene3dElement, point: 'point, eventId : 'i32)'void
)

model #model (
	vertexBuffer : 'vertexBuffer!vertex_location_texture_normal
	shader : 'shader
	_world := mat4()

	setWorld(world : 'mat4)'void {
		_world = copy world
		void
	}

	render(scene3d : 'scene3dElement, model : 'mat4)'void {
		viewWorld = scene3d.view * _world
		normalMat = viewWorld.invert().transpose()
		--c--
        glUseProgram(_parent->shader.id);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "viewModel" ), 1, 0, (GLfloat*)&sjv_viewWorld);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "normalMat" ), 1, 0, (GLfloat*)&sjv_normalMat);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "projection" ), 1, 0, (GLfloat*)&scene3d->projection);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "lightPos" ), 1, (GLfloat*)&scene3d->lightPos);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "diffuseColor" ), 1, (GLfloat*)&scene3d->diffuseColor);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "specColor" ), 1, (GLfloat*)&scene3d->specColor);	
        --c--
		vertexBuffer.render()
	}

	fireMouseEvent(scene3d : 'scene3dElement, point: 'point, eventId : 'i32)'void {}
) { this }