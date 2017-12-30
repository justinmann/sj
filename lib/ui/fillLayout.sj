fillLayout #element (
    children : array!heap #element()
    margin := margin()
    effect := empty'heap #effect
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

    getRect()'rect { _rect }

    setRect(rect_ : 'rect) {
        _rect = rect_
        innerRect : _rect - margin

        ifValid effect {
            effect.setRect(innerRect, parent.setRectInner)
        } elseEmpty {
            setRectInner(innerRect)
        }

        void    
    }

    setRectInner(innerRect : 'rect) {
        for i : 0 to children.count {
            child : children[i]
            child.setRect(innerRect)
        }   
        void    
    }

    render(scene : 'scene2d) {
        ifValid effect {
            effect.render(scene, parent.renderInner)
        } elseEmpty {
            renderInner(scene)
        }
    }

    renderInner(scene : 'scene2d) {
        for i : 0 to children.count {
            child : children[i]
            child.render(scene)
        }   
    }

    fireMouseEvent(mouseEvent : 'mouseEvent) {
        mouseEvent.fireChildren(children)
    }
) { this }