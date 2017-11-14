include "../../lib/common/common.sj"

#element(
	toHTML()'string
)

element #element (
	id : 'string
	children : array!#element()

	update() {
		html : ""
		for i (0 to children.size) {
			child : children[i]
			html.add(child.toHTML())
		}

		// console.write(html)
		c{
			#include(<emscripten.h>)

			EM_ASM_({
				document.body.innerHTML = UTF8ToString($1);
			}, _parent->id->data->data, html->data->data);
		}c
	}

	toHTML() {
		"hi"
	}
) { this }

timerElement #element (
	counter = 0

	toHTML() {
		a : convert.i32toString(counter)
		b : "foo"
		b + a
	}

	onTick() {
		counter++
	}
) { 
	// timer.setTimer(100, onTick)
	this 
}

timerElement : timerElement()

rootElement : element(
	id : "root"
	children : [ timerElement as #element ]
)

cdefine{
	#include(<emscripten/html5.h>)

	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);
}cdefine

cfunction{
	EM_BOOL em_onClick(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
		#function(onClick)(&global, mouseEvent->timestamp, mouseEvent->targetX, mouseEvent->targetY);
		return true;
	}
}cfunction

c{
	emscripten_set_click_callback(0, &global, false, em_onClick);
}c

onClick(timestemp: 'f64, x: 'i32, y: 'i32) {
	console.write("click")
}

mainLoop() {
	// console.write("foo")
	timerElement.onTick()
	rootElement.update()
	void
}