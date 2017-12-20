--cinclude--
#include(<emscripten.h>, EMSCRIPTEN)
#include(<emscripten/html5.h>, EMSCRIPTEN)
#include(<SDL.h>, EMSCRIPTEN)
#include(<SDL.h>, WIN32)
#include(<SDL2/SDL.h>, __APPLE__)
#include(<OpenGL/gl.h>, __APPLE__)
#include(<GLES3/gl3.h>, EMSCRIPTEN)
#include(<float.h>)
##ifdef WIN32
##pragma warning(disable:4996)
##define GLEW_STATIC
##include <windows.h>
##include <GL/glew.h>
##include <GL/gl.h>
##include <GL/glu.h>
##endif
--cinclude--

rootWindowRenderer : windowRenderer()
rootScene : scene2d()
modelsById : hash![string, weak #model]()
elementsById : hash![string, weak #element]()