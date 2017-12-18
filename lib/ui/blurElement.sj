blurElement #element (
	children : array!#element()
	radius := 0.0f
	up := true
	_rect := rect()
	_vertexBuffer := empty'boxVertexBuffer
	_frameBuffer1 := empty'frameBuffer
	_frameBuffer2 := empty'frameBuffer
	_innerScene : scene2d()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { _rect }

	setRect(rect_ : 'rect) {
		if _rect != rect_ {
			_rect = copy rect_
			for i : 0 to children.size {
				child : children[i]
				child.setRect(_rect)
			}	

			if !isEmpty(_frameBuffer1) {
				t1 : getValue(_frameBuffer1)			
				if t1.size != size(_rect.w, _rect.h) {
					_frameBuffer1 = empty'frameBuffer
				}
			}

			if !isEmpty(_frameBuffer2) {
				t2 : getValue(_frameBuffer2)			
				if t2.size != size(_rect.w, _rect.h) {
					_frameBuffer2 = empty'frameBuffer
				}
			}

			if isEmpty(_frameBuffer1) {
				_frameBuffer1 = value(frameBuffer(size(_rect.w, _rect.h)))
			}

			if isEmpty(_frameBuffer2) {
				_frameBuffer2 = value(frameBuffer(size(_rect.w, _rect.h)))
			}

			_vertexBuffer = empty'boxVertexBuffer
		}
		void	
	}

	render(scene : 'scene2d) {
		if up {
			radius = radius + 0.03f
			if radius > 5.0f {
				up = false
			}
		} else {
			radius = radius - 0.03f
			if radius <= 0.0f {
				radius = 0.0f
				up = true
			}
		}

		if isEmpty(_vertexBuffer) {
			_vertexBuffer = value(heap boxVertexBuffer(
				rect : copy _rect
			))
			void
		}

		if radius == 0.0f {
			for i : 0 to children.size {
				child : children[i]
				child.render(scene)
			}
		} else if !isEmpty(_frameBuffer1) && !isEmpty(_frameBuffer2) {
			f1 : getValue(_frameBuffer1)
			f2 : getValue(_frameBuffer2)
			--c--
			glBindFramebuffer(GL_FRAMEBUFFER, _parent->_frameBuffer1->frameBufferId);
			--c--

			_innerScene.setSize(f1.size)
			_innerScene.clear()
			for i : 0 to children.size {
				child : children[i]
				child.render(_innerScene)
			}

			--c--
			glBindFramebuffer(GL_FRAMEBUFFER, _parent->_frameBuffer2->frameBufferId);
			--c--

			_innerScene.setSize(f2.size)
			_innerScene.clear()

			--c--
	        glBindTexture(GL_TEXTURE_2D, _parent->_frameBuffer1->textureId);
	        glUseProgram(sjv_blurVerticalShader.id);
	        glUniform1i(glGetUniformLocation(sjv_blurVerticalShader.id, "texture" ), 0 );
	        glUniform1f(glGetUniformLocation(sjv_blurVerticalShader.id, "sigma" ), _parent->radius );
	        glUniform1f(glGetUniformLocation(sjv_blurVerticalShader.id, "blurSize" ), 1.0f / (float)_parent->_frameBuffer1->size.h );
	        glUniformMatrix4fv(glGetUniformLocation(sjv_blurVerticalShader.id, "model" ), 1, 0, (GLfloat*)&scene->model.m00);
	        glUniformMatrix4fv(glGetUniformLocation(sjv_blurVerticalShader.id, "view" ), 1, 0, (GLfloat*)&scene->view.m00);
	        glUniformMatrix4fv(glGetUniformLocation(sjv_blurVerticalShader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection.m00);
			--c--
			_vertexBuffer?.render(scene)

			--c--
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			--c--

			scene.updateViewport()

			--c--
	        glBindTexture(GL_TEXTURE_2D, _parent->_frameBuffer2->textureId);
	        glUseProgram(sjv_blurHorizontalShader.id);
	        glUniform1i(glGetUniformLocation(sjv_blurHorizontalShader.id, "texture" ), 0 );
	        glUniform1f(glGetUniformLocation(sjv_blurHorizontalShader.id, "sigma" ), _parent->radius );
	        glUniform1f(glGetUniformLocation(sjv_blurHorizontalShader.id, "blurSize" ), 1.0f / (float)_parent->_frameBuffer2->size.w );
	        glUniformMatrix4fv(glGetUniformLocation(sjv_blurHorizontalShader.id, "model" ), 1, 0, (GLfloat*)&scene->model.m00);
	        glUniformMatrix4fv(glGetUniformLocation(sjv_blurHorizontalShader.id, "view" ), 1, 0, (GLfloat*)&scene->view.m00);
	        glUniformMatrix4fv(glGetUniformLocation(sjv_blurHorizontalShader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection.m00);
			--c--
			_vertexBuffer?.render(scene)
		}
	}

	getChildren()'local array?!#element {
		a : local children
		value(a)
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
		for i : 0 to children.size {
			child : children[i]
			child.fireMouseEvent(mouseEvent)
		}	
	}
) { this } 