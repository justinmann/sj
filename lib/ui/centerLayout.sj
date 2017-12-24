centerLayout #element (
    children : array!heap #element()
    margin := margin()
    centerX := empty'f32
    centery := empty'f32
    _rect := rect()

    getSize(maxSize : 'size) {
        size := size()
        innerSize : maxSize - margin
        for i : 0 to children.count {
            child : children[i]         
            size = size.max(child.getSize(innerSize))
        }
        size + margin
    }

    getRect()'rect { copy _rect }

    setRect(rect_ : 'rect) {
        _rect = copy rect_
        innerRect : _rect - margin
        for i : 0 to children.count {
            child : children[i]
            childSize : child.getSize(size(innerRect.w, innerRect.h))

            x := innerRect.x
            w := innerRect.w
            ifValid centerX {
                x = innerRect.x + ((innerRect.w - childSize.w) as f32 * centerX) as i32
                w = childSize.w
            }

            y := innerRect.y
            h := innerRect.h
            ifValid centerY {
                y = innerRect.y + ((innerRect.h - childSize.h) as f32 * centerY) as i32
                h = childSize.h
            }

            child.setRect(rect(x, y, w, h))
        }   
        void    
    }

    render(scene : 'scene2d) {
        for i : 0 to children.count {
            child : children[i]
            child.render(scene)
        }
    }

    fireMouseEvent(mouseEvent : 'mouseEvent) {
        mouseEvent.fireChildren(children)
    }
) { this }