saturateShader : shader("shaders/v3f-t2f.vert", "shaders/saturate.frag")

saturateEffect #effect (
    amount := 1.0f
    _rect := rect()
    _vertexBuffer := empty'boxVertexBuffer
    _scenebuffer := empty'scenebuffer
    _innerScene : scene2d()

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
            glUseProgram(saturateShader)
            glBlendFunc(glBlendFuncType.GL_SRC_ALPHA, glBlendFuncType.GL_ONE_MINUS_SRC_ALPHA)
            glUniformI32(glGetUniformLocation(saturateShader, "texture"), 0)
            glUniformF32(glGetUniformLocation(saturateShader, "amount"), amount)
            glUniformMat4(glGetUniformLocation(saturateShader, "model"), scene.model)
            glUniformMat4(glGetUniformLocation(saturateShader, "view"), scene.view)
            glUniformMat4(glGetUniformLocation(saturateShader, "projection"), scene.projection)
            v.render(scene) 
        }
    }
) { this } 