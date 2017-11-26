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
	#include(<emscripten.h>)
	#include(<emscripten/html5.h>)

	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
}cdefine

cfunction{
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
		#functionStack(onClick)(&global, mouseEvent->timestamp, mouseEvent->targetX, mouseEvent->targetY);
		return true;
	}
}cfunction

c{
	emscripten_set_click_callback(0, &global, false, em_onClick);
}c