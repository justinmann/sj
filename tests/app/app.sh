emcc -O2 -g app.cpp -o app.html -s USE_SDL=2 -s USE_SDL_TTF=2 --preload-file assets -s WASM=1