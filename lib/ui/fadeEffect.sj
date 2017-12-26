fadeShader : shader("shaders/v3f-t2f.vert", "shaders/fade.frag")

@heap
fadeEffect #effect (
    alpha := 1.0f
    _rect := rect()
    _vertexBuffer := empty'boxVertexBuffer
    _scenebuffer := empty'scenebuffer
    _innerScene : scene2d()

    setAlpha(a : 'f32) { alpha = a; void }

    animateAlpha(a : 'f32, duration : 'i32) {
        animator.animations.add(
            heap animation!f32(
                startValue : alpha
                endValue : a
                start : animator.current
                end : animator.current + duration
                setValue : parent.setAlpha
            ) as #animation
        )
        void
    }
    
    getRect()'rect { copy _rect }

    setRect(rect_ : 'rect, cb : '(:rect)void) {
        if _rect != rect_ {
            _rect = copy rect_

            ifValid t1 : _scenebuffer {
                if t1.size != size(_rect.w, _rect.h) {
                    _scenebuffer = empty'frameBuffer
                }
            }

            _vertexBuffer = empty'boxVertexBuffer
        }

        cb(rect(0, 0, _rect.w, _rect.h))

        void    
    }

    render(scene : 'scene2d, cb : '(:scene2d)void) {
        if isEmpty(_vertexBuffer) {
            _vertexBuffer = valid(copy boxVertexBuffer(
                rect : copy _rect
            ))
            void
        }

        if isEmpty(_scenebuffer) {
            _scenebuffer = valid(copy scenebuffer(size(_rect.w, _rect.h)))
        }

        ifValid f1 : _scenebuffer, v : _vertexBuffer {
            glPushFramebuffer(f1.framebuffer)

            _innerScene.setSize(f1.size)
            _innerScene.start()

            cb(_innerScene)

            _innerScene.end()
            
            glPopFramebuffer(f1.framebuffer)

            glBindTexture(glTexture.GL_TEXTURE_2D, f1.texture)
            glUseProgram(fadeShader)
            glBlendFunc(glBlendFuncType.GL_SRC_ALPHA, glBlendFuncType.GL_ONE_MINUS_SRC_ALPHA)
            glUniformI32(glGetUniformLocation(fadeShader, "texture"), 0)
            glUniformF32(glGetUniformLocation(fadeShader, "alpha"), alpha)
            glUniformMat4(glGetUniformLocation(fadeShader, "model"), scene.model)
            glUniformMat4(glGetUniformLocation(fadeShader, "view"), scene.view)
            glUniformMat4(glGetUniformLocation(fadeShader, "projection"), scene.projection)
            v.render(scene) 
        }
    }
) { this } 