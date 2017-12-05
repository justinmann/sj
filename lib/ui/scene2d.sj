scene2d(
	_size = size()
	--cvar--
	mat4 model;
	mat4 view;
	mat4 projection;
	--cvar--

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
			--c--
		    mat4_set_orthographic( &_parent->projection, 0.0f, (float)_parent->_size.w, (float)-_parent->_size.h, 0.0f, -1.0f, 1.0f);
		    mat4_set_identity( &_parent->model );
		    mat4_scale(&_parent->model, 1.0f, -1.0f, 1.0f);
		    mat4_set_identity( &_parent->view );
		    --c--
		    void
	    }
	}
) { this }
