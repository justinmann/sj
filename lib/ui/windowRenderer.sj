windowRenderer(
	--cvar--
	SDL_Window* win;
	SDL_Renderer* ren;
	--cvar--

	getSize()'size {
		w := 0
		h := 0
		--c--
		SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
		--c--
		size(w, h)
	}

	present()'void {
		--c--
		SDL_GL_SwapWindow((SDL_Window*)_parent->win);
		--c--
		void
	}
) {
	--c--
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        halt("SDL_Init Error: %s\n", SDL_GetError());
    }

##ifdef __APPLE__
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
##else
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
##endif
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (_this->win == 0) {
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
    }

    SDL_GL_CreateContext((SDL_Window*)_this->win);
##ifdef WIN32
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult) 
	{
		halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
	}
##endif

    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_this->ren == 0) {
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }

    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
	--c--
	this
} copy {
	--c--
	_this->ren = _from->ren;
	ptr_retain(_this->ren);
	_this->win = _from->win;
	ptr_retain(_this->win);
	--c--
} destroy {
	--c--
	if (ptr_release(_this->ren)) {
		SDL_DestroyRenderer(_this->ren);
	}
	if (ptr_release(_this->win)) {
		SDL_DestroyWindow(_this->win);
	}
	--c--
}