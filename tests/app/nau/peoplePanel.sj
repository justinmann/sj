peoplePanel #model (
    model : mat4_identity()
    children : array!heap #model()
    _childrenModel := array!mat4()
    _world := mat4_identity()

    update(sceneRect : 'rect, projection : 'mat4, view : 'mat4, world : 'mat4, light : 'light)'void {
        _world = copy world
        for i : 0 to children.count {
            c : children[i]
            childModel : _childrenModel[i]
            newWorld : world * model * childModel
            c.update(sceneRect, projection, view, newWorld, light)
        }
        void
    }

    getZ() { 0.0f }
    getCenter() { vec3() }
    getWorld() { _world * model }

    renderOrQueue(zqueue : 'list!heap #model)'void {
        for i : 0 to children.count {
            c : children[i]
            c.renderOrQueue(zqueue)
        }
    }

    render() {
        void
    }

    fireMouseEvent(mouseEvent : 'mouseEvent)'void {
        for i : 0 to children.count {
            c : children[i]
            c.fireMouseEvent(mouseEvent)
        }
    }

    _index := 0
    _depth : 4;
    _xincrement : 8.0f;
    _zincrement : 2.0f;
    _xoffset := 0.0f;

    getModelMatrix(model : '#model)'mat4 {
        noise : f32_random() - 0.5f
        row : f32_floor(_index as f32 / _depth as f32)
        col : _index % _depth
        x := row * _xincrement + _xoffset + noise
        if col % 2 == 1 {
            x += _xincrement / 2.0f;
        }

        z : col as f32 * _zincrement + noise * 0.2f;

        _index++

        mat4_translate(vec3(x, 0.0f, z))
    }
) {
    _xoffset = -(_xincrement * f32_ceil(children.count as f32 / _depth as f32) / 2.0f)
    _childrenModel = copy children.map!mat4(this.getModelMatrix)
    this
}

