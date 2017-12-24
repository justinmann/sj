personElement #element (
    id : empty'string
    _rect := rect()

    getSize(maxSize : 'size) {
        copy maxSize
    }

    getRect()'rect { 
        copy _rect 
    }

    setRect(rect_ : 'rect) {
        if _rect != rect_ {
            _rect = copy rect_
        }
        void
    }

    render(scene : 'scene2d) {
        void
    }

    onMouseUp(point : 'point)'void {
        debug.writeLine("personElement onMouseUp " + point.x.asString() + ", " + point.y.asString())
        void
    }

    onMouseDown(point : 'point)'void {
        debug.writeLine("personElement onMouseDown")

        ifValid id {
            ifValid m : modelsById[id] {
                c : m.getCenter()
                w : m.getWorld()
                l : w * c.asVec4()
                d : l.asVec3()

                debug.writeLine(c.asString() + " => " + l.asString() + " & " + d.asString())

                fieldScene.animateLookAt(d, 2000)
            } elseEmpty {
                debug.writeLine("cannot find parent mode by id: " + id)     
            }
        } elseEmpty {
            debug.writeLine("personElement has no id")      
        }

        void
    }

    onMouseMove(point : 'point)'void {
        debug.writeLine("personElement onMouseMove")
        void
    }

    fireMouseEvent(mouseEvent : 'mouseEvent) {
        debug.writeLine("personElement " + mouseEvent.point.asString())
        if _rect.containsPoint(mouseEvent.point) {
            if mouseEvent.type == mouseEventType.up {
                onMouseUp(mouseEvent.point)
            } else if mouseEvent.type == mouseEventType.down {
                onMouseDown(mouseEvent.point)
            } else if mouseEvent.type == mouseEventType.move {
                onMouseMove(mouseEvent.point)
            }
        }

        true
    }
) { this }