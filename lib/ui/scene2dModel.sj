scene2dModel #model (
	vertexBuffer : 'vertexBuffer!vertex_location_texture_normal
	shader : 'shader
	frameBuffer : frameBuffer(size(512, 512))
	children : array!#element()
	_innerScene : scene2d()
	_world := mat4()

	setWorld(world : 'mat4) {
		_world = copy world
		void
	}

	render(projection : 'mat4, view : 'mat4, light : 'light)'void {
		--c--
		glBindFramebuffer(GL_FRAMEBUFFER, _parent->frameBuffer.frameBufferId);
		--c--

		_innerScene.setSize(frameBuffer.size)
		_innerScene.clear()
		for i : 0 to children.count {
			child : children[i]
			child.render(_innerScene)
		}

		--c--
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		--c--

		scene3d.updateViewport()
		viewWorld : scene3d.view * _world
		normalMat : viewWorld.invert().transpose()
		--c--
        glUseProgram(_parent->shader.id);
        glBindTexture(GL_TEXTURE_2D, _parent->frameBuffer.textureId);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "viewModel" ), 1, 0, (GLfloat*)&sjv_viewWorld);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "normalMat" ), 1, 0, (GLfloat*)&sjv_normalMat);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "projection" ), 1, 0, (GLfloat*)projection);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "lightPos" ), 1, (GLfloat*)&light->pos);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "diffuseColor" ), 1, (GLfloat*)&light->diffuseColor);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "specColor" ), 1, (GLfloat*)&light->specColor);	
        --c--
		vertexBuffer.render()
	}

	fireMouseEvent(sceneRect : 'rect, projection : 'mat4, view : 'mat4, point: 'point, eventId : 'i32)'void {
		texture : vertexBuffer.translateScreenToTexture(point, sceneRect, projection, view, _world)
		if !isEmpty(texture) {
			scenePoint : point(
				(texture.x * frameBuffer.size.w as f32) as i32
				(texture.y * frameBuffer.size.h as f32) as i32)
			for i : 0 to children.count {
				child : children[i]
				child.fireMouseEvent(scenePoint, eventId)
			}
		}
	}
) { 
	rect : rect(0, 0, frameBuffer.size.w, frameBuffer.size.h)
	for i : 0 to children.count {
		child : children[i]
		child.setRect(rect)
	}
	this 
}