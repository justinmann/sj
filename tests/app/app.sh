emcc -O2 -g timer.c -o timer.html -s USE_SDL=2 -s USE_FREETYPE=1 -s USE_LIBPNG=1 -s USE_WEBGL2=1 --preload-file assets --preload-file shaders -s WASM=1 -I../..

emcc -O2 -g effect.c -o effect.html -s USE_SDL=2 -s USE_FREETYPE=1 -s USE_LIBPNG=1 -s USE_WEBGL2=1 --preload-file assets --preload-file shaders -s WASM=1 -I../..

emcc -O2 -g layout.c -o layout.html -s USE_SDL=2 -s USE_FREETYPE=1 -s USE_LIBPNG=1 -s USE_WEBGL2=1 --preload-file assets --preload-file shaders -s WASM=1 -I../..

emcc -O2 -g nau.c -o nau.html -s USE_SDL=2 -s USE_FREETYPE=1 -s USE_LIBPNG=1 -s USE_WEBGL2=1 --preload-file assets --preload-file shaders -s WASM=1 -I../..