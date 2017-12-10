rootWindowRenderer : windowRenderer()
rootScene : scene2d()

include "animation.sj"
include "blurElement.sj"
include "borderLayout.sj"
include "boxElement.sj"
include "boxRenderer.sj"
include "boxVertexBuffer.sj"
include "buttonElement.sj"
include "color.sj"
include "crossHairsElement.sj"
include "distanceField.sj"
include "edtaa3func.sj"
include "element.sj"
include "fillElement.sj"
include "font.sj"
include "frameBuffer.sj"
include "glid.sj"
include "image.sj"
include "imageElement.sj"
include "imageRenderer.sj"
include "loop.sj"
include "margin.sj"
include "mat4.sj"
include "model.sj"
include "point.sj"
include "property.sj"
include "rect.sj"
include "scene2d.sj"
include "scene3dElement.sj"
include "shader.sj"
include "size.sj"
include "style.sj"
include "textElement.sj"
include "textRenderer.sj"
include "texture.sj"
include "textureAtlas.sj"
include "textureFont.sj"
include "utf8.sj"
include "vec2.sj"
include "vec3.sj"
include "vector.sj"
include "vectorAttribute.sj"
include "vertexBuffer.sj"
include "vertexBufferBuilders.sj"
include "windowRenderer.sj"
include "scene2dModel.sj"

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