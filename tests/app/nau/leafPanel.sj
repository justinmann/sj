leafPanel #model (
	textures : array!texture()
	children := array!heap #model()
	_world : mat4_identity()

	update(sceneRect : 'rect, projection : 'mat4, view : 'mat4, world : 'mat4, light : 'light)'void {
		for i : 0 to children.count {
			c : children[i]
			c.update(sceneRect, projection, view, world, light)
		}
		void
	}

	getZ() { 0.0f }
	getCenter() { vec3() }
	getWorld() { copy _world }

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

	_angle := 0.1f;

	textureToModel(texture : 'texture) {
	    noise : f32_random() - 0.5f
        x : _angle * 2.0f + noise * 0.2f;
        y : noise * 3.0f;
        z : f32_cos(_angle + noise * 0.2f) * 2.0f;
		_angle += 0.8f;

	    heap model(
	    	id : valid("leaf" + z.asString())
	    	texture : copy texture
	    	shader : copy phongTextureShader
	    	model : mat4_translate(vec3(x, y, z))
	    	vertexBuffer : planeVertexBuffer() 
        	hasAlpha : true
	    ) as #model
	}
) {
	_angle = textures.count as f32 * 0.8f / 2.0f
	children = textures.map!heap #model(this.textureToModel)
	this
}

