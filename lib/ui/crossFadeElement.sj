crossFadeElement #element (
	fromElement : 'heap #element
	toElement : 'heap #element
	_rect := rect()
	_fromEffect : fadeEffect()

	getSize(maxSize : 'size) {
		copy maxSize
	}

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect) {
		_rect = copy rect_

		_fromEffect.setRect(_rect, parent.setRectInner)
		toElement.setRect(_rect)
		void	
	}

	setRectInner(innerRect : 'rect) {
		fromElement.setRect(innerRect)
	}

	setAmount(amount : 'f32) {
		debug.writeLine("crossFadeElement:setAmount:" + amount.asString())
		_fromEffect.alpha = 1.0f - amount
		void
	}

	render(scene : 'scene2d) {
		toElement.render(scene)
		_fromEffect.render(scene, parent.renderInner)
	}

	renderInner(scene : 'scene2d) {
		fromElement.render(scene)
	}

	fireMouseEvent(mouseEvent : 'mouseEvent) {
		fromElement.fireMouseEvent(mouseEvent)
		toElement.fireMouseEvent(mouseEvent)
	}
) { this }