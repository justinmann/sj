blurHorizontalShader : shader("shaders/v3f-t2f.vert", "shaders/blur-horizontal.frag")
blurVerticalShader : shader("shaders/v3f-t2f.vert", "shaders/blur-vertical.frag")

blurEffect #effect (
	radius := 0.0f
	up := true
	_rect := rect()
	_vertexBuffer1 := empty'boxVertexBuffer
	_vertexBuffer2 := empty'boxVertexBuffer
	_scenebuffer1 := empty'scenebuffer
	_scenebuffer2 := empty'scenebuffer
	_innerScene : scene2d()

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect, children : 'array!heap #element) {
		if _rect != rect_ {
			_rect = copy rect_

			ifValid t1 : _scenebuffer1 {
				if t1.size != size(_rect.w, _rect.h) {
					_scenebuffer1 = empty'scenebuffer
					_vertexBuffer1 = empty'boxVertexBuffer
				}
			}

			ifValid t2 : _scenebuffer2 {
				if t2.size != size(_rect.w, _rect.h) {
					_scenebuffer2 = empty'scenebuffer
				}
			}

			_vertexBuffer2 = empty'boxVertexBuffer
		}

		for i : 0 to children.count {
			child : children[i]
			child.setRect(rect(0, 0, _rect.w, _rect.h))
		}	

		void	
	}

	render(scene : 'scene2d, children : 'array!heap #element) {
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

		if isEmpty(_vertexBuffer1) {
			_vertexBuffer1 = valid(boxVertexBuffer(
				rect : rect(0, 0, _rect.w, _rect.h)
			))
			void
		}

		if isEmpty(_vertexBuffer2) {
			_vertexBuffer2 = valid(boxVertexBuffer(
				rect : copy _rect
			))
			void
		}

		if isEmpty(_scenebuffer1) {
			_scenebuffer1 = valid(scenebuffer(size(_rect.w, _rect.h)))
		}

		if isEmpty(_scenebuffer2) {
			_scenebuffer2 = valid(scenebuffer(size(_rect.w, _rect.h)))
		}

		ifValid f1 : _scenebuffer1, f2 : _scenebuffer2, v1 : _vertexBuffer1, v2 : _vertexBuffer2 {
			glPushFramebuffer(f1.framebuffer)
			_innerScene.setSize(f1.size)
			_innerScene.start()

			for i : 0 to children.count {
				child : children[i]
				child.render(_innerScene)
			}

			_innerScene.end()
			glPopFramebuffer(f1.framebuffer)

			if radius != 0.0f {
				glPushFramebuffer(f2.framebuffer)
				_innerScene.setSize(f2.size)
				_innerScene.start()
				
		        glBindTexture(glTexture.GL_TEXTURE_2D, f1.texture)
		        glUseProgram(blurVerticalShader)
		        glUniformI32(glGetUniformLocation(blurVerticalShader, "texture"), 0)
		        glUniformF32(glGetUniformLocation(blurVerticalShader, "sigma"), radius)
		        glUniformF32(glGetUniformLocation(blurVerticalShader, "blurSize"), 1.0f / f1.size.h as f32)
		        glUniformMat4(glGetUniformLocation(blurVerticalShader, "model"), _innerScene.model)
		        glUniformMat4(glGetUniformLocation(blurVerticalShader, "view"), _innerScene.view)
		        glUniformMat4(glGetUniformLocation(blurVerticalShader, "projection"), _innerScene.projection)
				v1.render(_innerScene)			

				_innerScene.end()
				glPopFramebuffer(f2.framebuffer)

		        glBindTexture(glTexture.GL_TEXTURE_2D, f2.texture)
		        glUseProgram(blurHorizontalShader)
		        glUniformI32(glGetUniformLocation(blurHorizontalShader, "texture"), 0)
		        glUniformF32(glGetUniformLocation(blurHorizontalShader, "sigma"), radius)
		        glUniformF32(glGetUniformLocation(blurHorizontalShader, "blurSize"), 1.0f / f2.size.w as f32)
		        glUniformMat4(glGetUniformLocation(blurHorizontalShader, "model"), scene.model)
		        glUniformMat4(glGetUniformLocation(blurHorizontalShader, "view"), scene.view)
		        glUniformMat4(glGetUniformLocation(blurHorizontalShader, "projection"), scene.projection)
				v2.render(scene)			
			} else {
		        glBindTexture(glTexture.GL_TEXTURE_2D, f1.texture)
		        glUseProgram(imageShader)
		        glUniformMat4(glGetUniformLocation(imageShader, "model"), scene.model)
		        glUniformMat4(glGetUniformLocation(imageShader, "view"), scene.view)
		        glUniformMat4(glGetUniformLocation(imageShader, "projection"), scene.projection)			
				v2.render(scene)			
			}
		}
	}
) { this } 