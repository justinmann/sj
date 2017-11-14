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

		console.write(html)
		/* c{
			#include(<emscripten.h>)

			EM_ASM_({
				document.getElementById(UTF8ToString($0)).innerHTML = UTF8ToString($1);
			}, _parent->id->data, html->data);
		}c */
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

rootElement : element(
	id : "root"
	children : [ timerElement() as #element ]
)

rootElement.update()