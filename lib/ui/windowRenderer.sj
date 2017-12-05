windowRenderer(
	--cvar--
	SDL_Window* win;
	SDL_Renderer* ren;
	--cvar--

	getSize()'size {
		w = 0
		h = 0
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
        printf("SDL_Init Error: %s\n", SDL_GetError());
        exit(-1);
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
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        exit(-1);
    }

    SDL_GL_CreateContext((SDL_Window*)_this->win);
##ifdef WIN32
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult) 
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}
##endif

    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_this->ren == 0) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        exit(-1);
    }

    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
	--c--
	this
} copy {
	--c--
	_this->ren = _from->ren;
	_retain(_this->ren);
	_this->win = _from->win;
	_retain(_this->win);
	--c--
} destroy {
	--c--
	if (_release(_this->ren)) {
		SDL_DestroyRenderer(_this->ren);
	}
	if (_release(_this->win)) {
		SDL_DestroyWindow(_this->win);
	}
	--c--
}

--cstruct--
typedef struct GLid_td GLid_s;

struct GLid_td {
    GLuint id;
    int refCount;
    UT_hash_handle hh;
};

GLid_s* g_GLids = 0;
--cstruct--

--cdefine--
void _retainGLid(GLuint id);
bool _releaseGLid(GLuint id);
--cdefine--

--cfunction--
void _retainGLid(GLuint id) {
  GLid_s* p;
  HASH_FIND_PTR(g_GLids, &id, p);
  if (p) {
    p->refCount++;
  } else {
    p = (GLid_s*)malloc(sizeof(GLid_s));
    p->id = id;
    p->refCount = 1;
    HASH_ADD_PTR(g_GLids, id, p);    
  }
}

bool _releaseGLid(GLuint id) {
  GLid_s* p;
  HASH_FIND_PTR(g_GLids, &id, p);
  if (p) {
    p->refCount--;
    if (p->refCount == 0) {
      HASH_DEL(g_GLids, p);
      free(p);
    }
    return false;
  }
  return true;
}
--cfunction--