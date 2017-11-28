#surface(
	clear()'void
	present()'void
	getSize()'local size
	fillRect(rect : 'rect, color: 'color)'void
)

htmlCanvas2d #surface(
	ctxVarName : "sjCTX"

	fillRect(rect : 'rect, color: 'color) {
		console.write("fillRect")
		colorText : color.asString()
		void
	}
) { this }

sdlSurace #surface(
	size : size(640, 480)
	win = 0 as ptr
	ren = 0 as ptr

	clear()'void c{
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, 0, 0, 0, 0);
		SDL_RenderClear((SDL_Renderer*)_parent->ren);
	}c

	present()'void c{
		SDL_RenderPresent((SDL_Renderer*)_parent->ren);
	}c

	getSize()'local size {
		size
	}

	fillRect(rect: 'rect, color: 'color)'void c{
		SDL_SetRenderDrawColor((SDL_Renderer*)_parent->ren, color->r, color->g, color->b, color->a);
		SDL_RenderDrawRect((SDL_Renderer*)_parent->ren, rect);
	}c
) {
	c{
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
	        printf("SDL_Init Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    if (TTF_Init() != 0) {
	        printf("TTF_Init Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    _this->win = (uintptr_t)SDL_CreateWindow("Hello World!", 100, 100, _this->size.w, _this->size.h, SDL_WINDOW_SHOWN);
	    if (_this->win == 0) {
	        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	        exit(-1);
	    }

	    _this->ren = (uintptr_t)SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	    if (_this->ren == 0) {
	        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
	        exit(-1);
	    }
	}c
	this
} destroy c{
	SDL_DestroyRenderer((SDL_Renderer*)_this->ren);
	SDL_DestroyWindow((SDL_Window*)_this->win);
}c
