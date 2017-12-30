scene2d(
    _size := size()
    model := mat4()
    view := mat4()
    projection := mat4()
    windowRect := rect()

    start()'void {
        windowRect = rect(0, 0, _size.w, _size.h)
        glPushViewport(windowRect, windowRect)
        --c--
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glEnable( GL_TEXTURE_2D );
        glDisable( GL_DEPTH_TEST );
        --c--
        void
    }

    end()'void {
        glPopViewport(windowRect, windowRect)   
    }

    getSize()'size {
        size(_size.w, _size.h)
    }

    setSize(size: 'size)'void {
        if _size != size {
            _size = size
            projection = mat4_orthographic(0.0f, _size.w as f32, (0 - _size.h) as f32, 0.0f, -1.0f, 1.0f)
            model = mat4_scale(1.0f, -1.0f, 1.0f)
            view = mat4_identity()
        }
        void
    }
) { this }
