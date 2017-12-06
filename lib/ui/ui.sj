include "windowRenderer.sj"
include "scene2d.sj"
include "buttonElement.sj"
include "fillElement.sj"
include "imageElement.sj"
include "textElement.sj"
include "color.sj"
include "element.sj"
include "rect.sj"
include "style.sj"
include "size.sj"
include "image.sj"
include "texture.sj"
include "font.sj"
include "mouseHandler.sj"
include "point.sj"
include "borderLayout.sj"
include "boxElement.sj"
include "margin.sj"
include "cameraElement.sj"
include "cubeVertexBuffer.sj"
include "shader.sj"
include "textureAtlas.sj"
include "textureFont.sj"
include "vector.sj"
include "vectorAttribute.sj"
include "vertexBuffer.sj"
include "utf8.sj"
include "distanceField.sj"
include "edtaa3func.sj"
include "mat4.sj"
include "textRenderer.sj"
include "boxRenderer.sj"
include "imageRenderer.sj"
include "blurElement.sj"
include "frameBuffer.sj"
include "boxVertexBuffer.sj"

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

onClick(timestemp: 'f64, x: 'i32, y: 'i32) {
	console.write("click")
}

fireMouseUp(element :'#element, point: 'point) {
    mouseHandler : element as #mouseHandler?
    if element.getRect().containsPoint(point) {
        mouseHandler?.onMouseUp(point)
    }
    children : element.getChildren()
    if !isEmpty(children) {
        c : getValue(children)
        for i (0 to c.size) {
            fireMouseUp(c[i], point)
        }
    }
    void
}

fireMouseDown(element :'#element, point: 'point) {
    mouseHandler : element as #mouseHandler?
    if element.getRect().containsPoint(point) {
        mouseHandler?.onMouseDown(point)
    }
    children : element.getChildren()
    if !isEmpty(children) {
        c : getValue(children)
        for i (0 to c.size) {
            fireMouseDown(c[i], point)
        }
    }
    void
}

frame = 0

rootWindowRenderer : windowRenderer()
rootScene : scene2d()

mainLoop() {
//  console.write("mainLoop - " + convert.i32toString(frame))

    size : rootWindowRenderer.getSize()
    rootScene.setSize(size)
    rootScene.clear()
    rect : rect(0, 0, size.w, size.h)
    root.setRect(rect)
    root.render(rootScene)
    rootWindowRenderer.present()

    isMouseUp = false
    isMouseDown = false
    x = 0
    y = 0
    --c--
    SDL_Event e;
    while(SDL_PollEvent( &e ) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("SDL_MOUSEBUTTONDOWN\n");
                sjv_isMouseDown = true;
                sjv_x = e.button.x;
                sjv_y = e.button.x;
                break;
            case SDL_MOUSEBUTTONUP:
                printf("SDL_MOUSEBUTTONUP\n");
                sjv_isMouseUp = true;
                sjv_x = e.button.x;
                sjv_y = e.button.x;
                break;
        }
    }
    --c--

    if isMouseUp {
        fireMouseUp(root, point(x, y)) 
    }
    if isMouseDown {
        fireMouseDown(root, point(x, y)) 
    }

    frame++
    void
}

runLoop() {
	--c--
##ifdef EMSCRIPTEN
	emscripten_set_main_loop((em_callback_func)sjf_mainLoop, 0, 0);
	exit(0);
##else
	bool quit = false;
    while (!quit) {
        sjf_mainLoop();
    }
##endif	
	--c--
}