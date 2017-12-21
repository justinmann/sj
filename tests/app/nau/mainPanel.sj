mainPanel #model (
	children : array!heap #model()
	radius : 'f32
	model : mat4_identity()
	_world : mat4_identity()
	_childWorlds : list!mat4()

	update(sceneRect : 'rect, projection : 'mat4, view : 'mat4, world : 'mat4, light : 'light)'void {
		for i : 0 to children.count {
			c : children[i]
			childWorld : _childWorlds[i]
			t : world * model * childWorld
			c.update(sceneRect, projection, view, t, light)
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
) {
	angleIncrement : 0.08f
	angle := (-(children.count) as f32 * angleIncrement) / 2.0f
	for i : 0 to children.count {
		angleOffset : f32_random() * 0.01f
		radiusOffset : f32_random() * 0.5f
		y : (f32_random() - 0.5f) * 0.4f
		x : f32_sin(angle + angleOffset) * (radius + radiusOffset)
		z : f32_cos(angle + angleOffset) * (radius + radiusOffset)
		_childWorlds.add(
			mat4_translate(vec3(x, y, z)) * mat4_rotate(angle, vec3(0.0f, 1.0f, 0.0f))
		)
		angle += angleIncrement
	}
	this
}

