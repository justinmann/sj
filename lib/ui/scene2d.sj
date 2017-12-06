scene2d(
	_size = size()
	model = mat4()
	view = mat4()
	projection = mat4()

	clear()'void {
	    --c--
	    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	    glEnable( GL_TEXTURE_2D );
	    glDisable( GL_DEPTH_TEST );
		--c--
		updateViewport()
		void
	}

	updateViewport()'void {
		--c--
	    glViewport(0, 0, _parent->_size.w, _parent->_size.h);
		--c--	
	}

	getSize()'size {
		size(_size.w, _size.h)
	}

	setSize(size: 'size)'void {
		if _size != size {
			_size = copy size
			projection = mat4_orthographic(0.0f, _size.w as f32, _size.h as f32, 0.0f, -1.0f, 1.0f)
			model = mat4_scale(1.0f, -1.0f, 1.0f)
			view = mat4_identity()
		    void
	    }
	}
) { this }
