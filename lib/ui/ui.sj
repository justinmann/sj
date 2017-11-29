include "buttonElement.sj"
include "fillElement.sj"
include "imageElement.sj"
include "textElement.sj"
include "color.sj"
include "element.sj"
include "rect.sj"
include "style.sj"
include "surface.sj"
include "size.sj"
include "image.sj"
include "texture.sj"
include "font.sj"

onClick(timestemp: 'f64, x: 'i32, y: 'i32) {
	console.write("click")
}

frame = 0

mainLoop() {
	console.write("mainLoop - " + convert.i32toString(frame))

	rootSurface.clear()
	size : rootSurface.getSize()
	rect : rect(0, 0, size.w, size.h)
	root.setRect(rect)
	root.render(rootSurface)
	rootSurface.present()

	frame++
	void
}

cdefine{
	#include(<emscripten.h>, EMSCRIPTEN)
	#include(<emscripten/html5.h>, EMSCRIPTEN)
	#include(<SDL.h>, EMSCRIPTEN)
	#include(<SDL_ttf.h>, EMSCRIPTEN)
	#include(<SDL.h>, WIN32)
	#include(<SDL_ttf.h>, WIN32)
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

runLoop() {
	c{
##ifdef EMSCRIPTEN
	emscripten_set_main_loop_arg((em_arg_callback_func)sjf_mainLoop, &global, 0, 0);
	exit(0);
##else
	bool quit = false;
    while (!quit) {
        sjf_mainLoop();

        //Handle events on queue
		SDL_Event e;
        while(SDL_PollEvent( &e ) != 0) {
            //User requests quit
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
        }
    }
##endif	
	}c
}