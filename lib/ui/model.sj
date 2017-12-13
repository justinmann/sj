#model(
	setWorld(world : 'mat4)'void
	render(sceneRect : 'rect, projection : 'mat4, view : 'mat4, light : 'light)'void
	fireMouseEvent(sceneRect : 'rect, projection : 'mat4, view : 'mat4, point: 'point, eventId : 'i32)'void
)

model #model (
	vertexBuffer : 'vertexBuffer!vertex_location_texture_normal
	shader : 'shader
	texture : 'texture
	scale : 1.0f
	center : vec3()
	world : mat4_identity()
	_parentWorld := mat4()

	setWorld(world : 'mat4)'void {
		_parentWorld = copy world
		void
	}

	render(sceneRect : 'rect, projection : 'mat4, view : 'mat4, light : 'light)'void {
		totalWorld : _parentWorld * world
		viewWorld : view * totalWorld
		normalMat : viewWorld.invert().transpose()
		--c--
        glUseProgram(_parent->shader.id);
        glBindTexture(GL_TEXTURE_2D, _parent->texture.id);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "viewModel" ), 1, 0, (GLfloat*)&sjv_viewWorld);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "normalMat" ), 1, 0, (GLfloat*)&sjv_normalMat);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "projection" ), 1, 0, (GLfloat*)projection);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "lightPos" ), 1, (GLfloat*)&light->pos);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "diffuseColor" ), 1, (GLfloat*)&light->diffuseColor);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "specColor" ), 1, (GLfloat*)&light->specColor);	
        --c--
		vertexBuffer.render()
	}

	fireMouseEvent(sceneRect : 'rect, projection : 'mat4, view : 'mat4, point: 'point, eventId : 'i32)'void {}
) { this }