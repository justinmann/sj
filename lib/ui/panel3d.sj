panel3d #model(
	world : mat4_identity()
	children : array!#model()

	setWorld(world_ : 'mat4)'void {
		totalWorld : world_ * world 
		for i : 0 to children.count {
			c : children[i]
			c.setWorld(totalWorld)
		}
		void
	}

	render(projection : 'mat4, view : 'mat4, light : 'light)'void {
		for i : 0 to children.count {
			c : children[i]
			c.render(projection, view, light)
		}
	}

	fireMouseEvent(sceneRect : 'rect, projection : 'mat4, view : 'mat4, point: 'point, eventId : 'i32)'void {
		for i : 0 to children.count {
			c : children[i]
			c.fireMouseEvent(sceneRect, projection, view, point, eventId)
		}
	}
) { this }