surface2d(
	size : size(640, 480)
	--cvar--
	SDL_Window* win;
	SDL_Renderer* ren;
	GLuint textShader;
	mat4 model;
	mat4 view;
	mat4 projection;
	--cvar--

	clear()'void {
		--c--
		int32_t w, h;
		SDL_GetRendererOutputSize(_parent->ren, &w, &h);
	    glViewport(0, 0, w, h);

	    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	    glEnable( GL_TEXTURE_2D );
	    glDisable( GL_DEPTH_TEST );

	    mat4_set_orthographic( &_parent->projection, 0.0f, (float)w, (float)-h, 0.0f, -1.0f, 1.0f);
	    mat4_set_identity( &_parent->model );
	    mat4_scale(&_parent->model, 1.0f, -1.0f, 1.0f);
	    mat4_set_identity( &_parent->view );
		--c--
		void
	}

	present()'void {
		--c--
		SDL_GL_SwapWindow((SDL_Window*)_parent->win);
		--c--
		void
	}

	getSize()'size {
		w = 0
		h = 0
		--c-- 
		SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
		--c--
		size(w, h)
	}

	drawRect(rect: 'rect, color: 'color)'void --c--
/*
		SDL_SetRenderDrawColor(_parent->ren, color->r, color->g, color->b, color->a);
		SDL_RenderFillRect(_parent->ren, (SDL_Rect*)rect);
*/
	--c--

	drawImage(rect: 'rect, image: 'image)'void --c--
/*
		if (image->texture.tex) {
			if (image->margin.l > 0) {
				if (image->margin.t > 0) {
					SDL_Rect leftTopSrcRect;
					leftTopSrcRect.x = image->rect.x;
					leftTopSrcRect.y = image->rect.y;
					leftTopSrcRect.w = image->margin.l;
					leftTopSrcRect.h = image->margin.t;

					SDL_Rect leftTopDestRect;
					leftTopDestRect.x = rect->x;
					leftTopDestRect.y = rect->y;
					leftTopDestRect.w = image->margin.l;
					leftTopDestRect.h = image->margin.t;
					SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &leftTopSrcRect, &leftTopDestRect);
				}

				SDL_Rect leftSrcRect;
				leftSrcRect.x = image->rect.x;
				leftSrcRect.y = image->rect.y + image->margin.t;
				leftSrcRect.w = image->margin.l;
				leftSrcRect.h = image->rect.h - image->margin.t - image->margin.b;

				SDL_Rect leftDestRect;
				leftDestRect.x = rect->x;
				leftDestRect.y = rect->y + image->margin.t;
				leftDestRect.w = image->margin.l;
				leftDestRect.h = rect->h - image->margin.t - image->margin.b;
				SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &leftSrcRect, &leftDestRect);

				if (image->margin.b > 0) {
					SDL_Rect leftBottomSrcRect;
					leftBottomSrcRect.x = image->rect.x;
					leftBottomSrcRect.y = image->rect.y + image->rect.h - image->margin.b;
					leftBottomSrcRect.w = image->margin.l;
					leftBottomSrcRect.h = image->margin.b;

					SDL_Rect leftBottomDestRect;
					leftBottomDestRect.x = rect->x;
					leftBottomDestRect.y = rect->y + rect->h - image->margin.b;
					leftBottomDestRect.w = image->margin.l;
					leftBottomDestRect.h = image->margin.b;
					SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &leftBottomSrcRect, &leftBottomDestRect);
				}
			}

			if (image->margin.r > 0) {
				if (image->margin.t > 0) {
					SDL_Rect rightTopSrcRect;
					rightTopSrcRect.x = image->rect.x + image->rect.w - image->margin.r;
					rightTopSrcRect.y = image->rect.y;
					rightTopSrcRect.w = image->margin.r;
					rightTopSrcRect.h = image->margin.t;

					SDL_Rect rightTopDestRect;
					rightTopDestRect.x = rect->x + rect->w - image->margin.r;
					rightTopDestRect.y = rect->y;
					rightTopDestRect.w = image->margin.r;
					rightTopDestRect.h = image->margin.t;
					SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &rightTopSrcRect, &rightTopDestRect);
				}

				SDL_Rect rightSrcRect;
				rightSrcRect.x = image->rect.x + image->rect.w - image->margin.r;
				rightSrcRect.y = image->rect.y + image->margin.t;
				rightSrcRect.w = image->margin.r;
				rightSrcRect.h = image->rect.h - image->margin.t - image->margin.b;

				SDL_Rect rightDestRect;
				rightDestRect.x = rect->x + rect->w - image->margin.r;
				rightDestRect.y = rect->y + image->margin.t;
				rightDestRect.w = image->margin.r;
				rightDestRect.h = rect->h - image->margin.t - image->margin.b;
				SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &rightSrcRect, &rightDestRect);

				if (image->margin.b > 0) {
					SDL_Rect rightBottomSrcRect;
					rightBottomSrcRect.x = image->rect.x + image->rect.w - image->margin.r;
					rightBottomSrcRect.y = image->rect.y + image->rect.h - image->margin.b;
					rightBottomSrcRect.w = image->margin.r;
					rightBottomSrcRect.h = image->margin.b;

					SDL_Rect rightBottomDestRect;
					rightBottomDestRect.x = rect->x + rect->w - image->margin.r;
					rightBottomDestRect.y = rect->y + rect->h - image->margin.b;
					rightBottomDestRect.w = image->margin.r;
					rightBottomDestRect.h = image->margin.b;
					SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &rightBottomSrcRect, &rightBottomDestRect);
				}
			}

			if (image->margin.t > 0) {
				SDL_Rect middleTopSrcRect;
				middleTopSrcRect.x = image->rect.x + image->margin.l;
				middleTopSrcRect.y = image->rect.y;
				middleTopSrcRect.w = image->rect.w - image->margin.l - image->margin.r;
				middleTopSrcRect.h = image->margin.t;

				SDL_Rect middleTopDestRect;
				middleTopDestRect.x = rect->x + image->margin.l;
				middleTopDestRect.y = rect->y;
				middleTopDestRect.w = rect->w - image->margin.l - image->margin.r;
				middleTopDestRect.h = image->margin.t;
				SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &middleTopSrcRect, &middleTopDestRect);
			}

			SDL_Rect middleSrcRect;
			middleSrcRect.x = image->rect.x + image->margin.l;
			middleSrcRect.y = image->rect.y + image->margin.t;
			middleSrcRect.w = image->rect.w - image->margin.l - image->margin.r;
			middleSrcRect.h = image->rect.h - image->margin.t - image->margin.b;

			SDL_Rect middleDestRect;
			middleDestRect.x = rect->x + image->margin.l;
			middleDestRect.y = rect->y + image->margin.t;
			middleDestRect.w = rect->w - image->margin.l - image->margin.r;
			middleDestRect.h = rect->h - image->margin.t - image->margin.b;
			SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &middleSrcRect, &middleDestRect);

			if (image->margin.b > 0) {
				SDL_Rect middleBottomSrcRect;
				middleBottomSrcRect.x = image->rect.x + image->margin.l;
				middleBottomSrcRect.y = image->rect.y + image->rect.h - image->margin.b;
				middleBottomSrcRect.w = image->rect.w - image->margin.l - image->margin.r;
				middleBottomSrcRect.h = image->margin.b;

				SDL_Rect middleBottomDestRect;
				middleBottomDestRect.x = rect->x + image->margin.l;
				middleBottomDestRect.y = rect->y + rect->h - image->margin.b;
				middleBottomDestRect.w = rect->w - image->margin.l - image->margin.r;
				middleBottomDestRect.h = image->margin.b;
				SDL_RenderCopy(_parent->ren, (SDL_Texture*)image->texture.tex, &middleBottomSrcRect, &middleBottomDestRect);
			}
		}
*/
	--c--

	drawVertexBuffer(vertexBuffer: '#vertexBuffer, texture : 'texture)'void {
		--c--
	    glBindTexture(GL_TEXTURE_2D, texture->id);
		glUseProgram(_parent->textShader);
        glUniform1i(glGetUniformLocation(_parent->textShader, "texture" ), 0 );
        glUniformMatrix4fv(glGetUniformLocation(_parent->textShader, "model" ), 1, 0, _parent->model.data);
        glUniformMatrix4fv(glGetUniformLocation(_parent->textShader, "view" ), 1, 0, _parent->view.data);
        glUniformMatrix4fv(glGetUniformLocation(_parent->textShader, "projection" ), 1, 0, _parent->projection.data);
		--c--
		vertexBuffer.render()
	}

	getTextSize(font: 'font, text: 'string)'size {
		w = 0
		h = 0
/*		--c--
			TTF_SizeUTF8((TTF_Font*)font->data, (char*)text->data.data, &sjv_w, &sjv_h);
		--c--
*/
		size(w, h)
	}

	getTexture(src: 'string)'texture {
		tex = 0 as ptr
/*
		--c--
		    SDL_Surface* bmp = IMG_Load((char*)src->data.data);
		    if (bmp == 0) {
		        printf("IMG_Load Error: %s for '%s'\n", SDL_GetError(), (char*)src->data.data);
		    }

		    sjv_tex = (uintptr_t)SDL_CreateTextureFromSurface(_parent->ren, bmp);
		    SDL_FreeSurface(bmp);
		    if (sjv_tex == 0) {
		        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		    }
		--c--
*/
		texture(tex : tex)
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

    _this->win = SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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

    glClearColor( 1.0, 0.0, 1.0, 1.0 );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );

    _this->textShader = shader_load("shaders/v3f-t2f-c4f.vert", "shaders/v3f-t2f-c4f.frag");
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
