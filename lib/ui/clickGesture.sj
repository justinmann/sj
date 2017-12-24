enum clickState (
    none
    entered
    pressed
)

#clickable(
    onClickGestureEnter(element : '#element)'void
    onClickGestureLeave(element : '#element)'void
    onClickGesturePress(element : '#element)'void
    onClickGestureClick(element : '#element)'void
)

clickGesture(
    element : empty'weak #element
    clickable : empty'weak #clickable
    rect := rect()
    _state := clickState.none

    getState() { _state }

    fireMouseEvent(mouseEvent : 'mouseEvent)'bool {
        ifValid e : heap element {
            if rect.containsPoint(mouseEvent.point) {
                switch mouseEvent.type {
                    mouseEventType.up {
                        _state = clickState.none
                        mouse_release(e)
                        clickable?.onClickGestureClick(e)
                        false
                    }
                    mouseEventType.down {
                        _state = clickState.pressed
                        mouse_capture(e)
                        clickable?.onClickGesturePress(e)
                        false
                    }
                    mouseEventType.move {
                        if _state == clickState.none {
                            if mouseEvent.isLeftDown {
                                _state = clickState.pressed
                            } else {
                                _state = clickState.entered
                            }
                            clickable?.onClickGestureEnter(e)
                        }
                        mouse_hasCapture(e)
                    }
                    default { 
                        true
                    }
                }
            } else {
                if _state == clickState.entered || _state == clickState.pressed {
                    clickable?.onClickGestureLeave(e)
                    _state = clickState.none
                }

                if mouseEvent.type == mouseEventType.up && mouse_hasCapture(e) {
                    mouse_release(e)    
                    false               
                } else {
                    mouse_hasCapture(e)
                }
            }
        } elseEmpty {
            true
        }
    }
) { this }