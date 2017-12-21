fadeShader : shader("shaders/v3f-t2f.vert", "shaders/fade.frag")

fadeEffect #effect (
	alpha := 1.0f
	_rect := rect()
	_vertexBuffer := empty'boxVertexBuffer
	_scenebuffer := empty'scenebuffer
	_innerScene : scene2d()

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect, children : 'array!heap #element) {
		if _rect != rect_ {
			_rect = copy rect_

			ifValid t1 : _scenebuffer {
				if t1.size != size(_rect.w, _rect.h) {
					_scenebuffer = empty'frameBuffer
				}
			}

			_vertexBuffer = empty'boxVertexBuffer
		}

		for i : 0 to children.count {
			child : children[i]
			child.setRect(rect(0, 0, _rect.w, _rect.h))
		}	

		void	
	}

	render(scene : 'scene2d, children : 'array!heap #element) {
		if isEmpty(_vertexBuffer) {
			_vertexBuffer = valid(boxVertexBuffer(
				rect : copy _rect
			))
			void
		}

		if isEmpty(_scenebuffer) {
			_scenebuffer = valid(scenebuffer(size(_rect.w, _rect.h)))
		}

		ifValid f1 : _scenebuffer, v : _vertexBuffer {
			glPushFramebuffer(f1.framebuffer)

			_innerScene.setSize(f1.size)
			_innerScene.start()

			for i : 0 to children.count {
				child : children[i]
				child.render(_innerScene)
			}

			_innerScene.end()
			
			glPopFramebuffer(f1.framebuffer)

			glBindTexture(glTexture.GL_TEXTURE_2D, f1.texture)
			glUseProgram(fadeShader)
	        glUniformI32(glGetUniformLocation(fadeShader, "texture"), 0)
			glUniformF32(glGetUniformLocation(fadeShader, "alpha"), alpha)
	        glUniformMat4(glGetUniformLocation(fadeShader, "model"), scene.model)
	        glUniformMat4(glGetUniformLocation(fadeShader, "view"), scene.view)
	        glUniformMat4(glGetUniformLocation(fadeShader, "projection"), scene.projection)
			v.render(scene) 
		}
	}
) { this } 