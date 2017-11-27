include "button.sj"
include "color.sj"
include "element.sj"
include "rect.sj"
include "style.sj"
include "surface.sj"

root = empty'#element
rootCanvas : htmlCanvas2d() as #surface

onClick(timestemp: 'f64, x: 'i32, y: 'i32) {
	console.write("click")
}

mainLoop() {
	console.write("mainLoop - 1")
	// timerElement.onTick()
	root?.setRect(rect(0, 0, 100, 100))
	root?.render(rootCanvas)
	void
}

cdefine{
	#include(<emscripten.h>, EMSCRIPTEN)
	#include(<emscripten/html5.h>, EMSCRIPTEN)
	#include(<SDL.h>, EMSCRIPTEN)
	#include(<SDL_ttf.h>, EMSCRIPTEN)
	#include(<SDL.h>, __MSVC__)
	#include(<SDL_ttf.h>, __MSVC__)
	#include(<SDL2/SDL.h>, __APPLE__)
	#include(<SDL2_ttf/SDL_ttf.h>, __APPLE__)

##ifdef EMSCRIPTEN
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
##endif	
	SDL_Texture* renderText(const char* message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);
}cdefine

cfunction{
##ifdef EMSCRIPTEN
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
		#functionStack(onClick)(&global, mouseEvent->timestamp, mouseEvent->targetX, mouseEvent->targetY);
		return true;
	}
##endif	

SDL_Texture* renderText(const char* message, const char* fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer) {
    //Open the font
    TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
    if (font == 0) {
        printf("TTF_OpenFont Error: %s\n", SDL_GetError());
        return 0;
    }
    //We need to first render to a surface as that's what TTF_RenderText returns, then
    //load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, message, color);
    if (surf == 0) {
        TTF_CloseFont(font);
        printf("TTF_RenderText Error: %s\n", SDL_GetError());
        return 0;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == 0) {
        printf("CreateTexture Error: %s\n", SDL_GetError());
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

}cfunction

c{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() != 0) {
        printf("TTF_Init Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == 0) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == 0) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface* bmp = SDL_LoadBMP("assets/hello2.bmp");
    if (bmp == 0) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == 0) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Texture* image = renderText("Mallory & Madison is awesome!", "assets/sample.ttf", color, 32, ren);
    if (image == 0) {
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
}c

runLoop() {
	c{
##ifdef EMSCRIPTEN
	emscripten_set_main_loop_arg((em_arg_callback_func)sjf_mainLoop, &global, 0, 0);
	exit(0);
##else
    while (true) {
        sjf_mainLoop();
    }
##endif	
	}c
}