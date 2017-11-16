include "../../lib/common/common.sj"
include "../../lib/ui/ui.sj"

/*
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
*/

root = value(element(
	children : [ button() as #element ]
) as #element)