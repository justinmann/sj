scene2dModel #model (
	vertexBuffer : 'vertexBuffer!vertex_location_texture_normal
	shader : 'shader
	frameBuffer : frameBuffer(size(512, 512))
	children : array!#element()
	_innerScene : scene2d()

	render(scene3d : 'scene3dElement, model : 'mat4)'void {
		--c--
		glBindFramebuffer(GL_FRAMEBUFFER, _parent->frameBuffer.frameBufferId);
		--c--

		_innerScene.setSize(frameBuffer.size)
		_innerScene.clear()
		for i (0 to children.size) {
			child : children[i]
			child.render(_innerScene)
		}

		--c--
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		--c--

		scene3d.updateViewport()
		viewModel : scene3d.view * model
		normalMat : viewModel.invert().transpose()
		--c--
        glUseProgram(_parent->shader.id);
        glBindTexture(GL_TEXTURE_2D, _parent->frameBuffer.textureId);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "viewModel" ), 1, 0, (GLfloat*)&sjv_viewModel);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "normalMat" ), 1, 0, (GLfloat*)&sjv_normalMat);
        glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "projection" ), 1, 0, (GLfloat*)&scene3d->projection);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "lightPos" ), 1, (GLfloat*)&scene3d->lightPos);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "diffuseColor" ), 1, (GLfloat*)&scene3d->diffuseColor);
        glUniform3fv(glGetUniformLocation(_parent->shader.id, "specColor" ), 1, (GLfloat*)&scene3d->specColor);	
        --c--
		vertexBuffer.render()
	}
) { 
	rect : rect(0, 0, frameBuffer.size.w, frameBuffer.size.h)
	for i (0 to children.size) {
		child : children[i]
		child.setRect(rect)
	}
	this 
}