panel3d #model(
	model : mat4_identity()
	children : array!heap #model()
	_world := mat4_identity()

	update(sceneRect : 'rect, projection : 'mat4, view : 'mat4, world : 'mat4, light : 'light)'void {
		_world = copy world
		childWorld : world * model 
		for i : 0 to children.count {
			c : children[i]
			c.update(sceneRect, projection, view, childWorld, light)
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

	render()'void {

	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
		for i : 0 to children.count {
			c : children[i]
			c.fireMouseEvent(mouseEvent)
		}
	}
) { this }