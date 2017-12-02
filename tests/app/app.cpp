#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <OpenGL/gl3.h>
#else
#include <SDL.h>
#include <SDL_ttf.h>
#endif
#include <iostream>
#include <string>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

void logSDLError(std::ostream &os, const std::string &msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color,
    int fontSize, SDL_Renderer *renderer)
{
    //Open the font
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr) {
        logSDLError(std::cout, "TTF_OpenFont");
        return nullptr;
    }
    //We need to first render to a surface as that's what TTF_RenderText returns, then
    //load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr) {
        TTF_CloseFont(font);
        logSDLError(std::cout, "TTF_RenderText");
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        logSDLError(std::cout, "CreateTexture");
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

SDL_Window *win;
SDL_Renderer *ren;
SDL_Surface *bmp;
SDL_Texture *tex;
SDL_Texture *image;

void main_loop();
void main_destroy();

void main_loop() {
    //First clear the renderer
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 0.0, 0.0, 0.0);

    SDL_Rect dst;
    dst.x = rand() % 2;
    dst.y = rand() % 2;

    SDL_QueryTexture(image, NULL, NULL, &dst.w, &dst.h);

    //Draw the texture
//        SDL_RenderCopy(ren, tex, NULL, &dst);

    //Draw the texture
    SDL_RenderCopy(ren, image, NULL, &dst);

    //Update the screen
    SDL_GL_SwapWindow(win);
    //Take a quick break after all that hard work
    SDL_Delay(100);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //Also need to init SDL_ttf
    if (TTF_Init() != 0) {
        logSDLError(std::cout, "TTF_Init");
        SDL_Quit();
        return 1;
    }

#ifdef __APPLE__
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_GLContext context = SDL_GL_CreateContext(win);

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    std::string imagePath = "assets/hello2.bmp";
    bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr) {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Color color = { 255, 255, 255, 255 };
    image = renderText("Mallory & Madison is awesome!", "assets/sample.ttf", color, 32, ren);
    if (image == nullptr) {
        TTF_Quit();
        SDL_Quit();
        return 1;
    }    
    

#ifdef EMSCRIPTEN
    emscripten_set_main_loop(main_loop, 0, 0);
#else
    //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    while (true) {
        main_loop();

        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            //if( e.type == SDL_QUIT ) {
            //    quit = true;
            //}
        }

    }

    main_destroy();
#endif
    return 0;
}

void main_destroy() {
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
