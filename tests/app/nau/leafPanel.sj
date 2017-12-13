leafPanel #model (
	textures : array!texture()
	children := array!#model()

	setWorld(world_ : 'mat4)'void {
		for i : 0 to children.count {
			c : children[i]
			c.setWorld(world_)
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

	_angle := 0.1f;

	textureToModel(texture : 'texture)'model {
	    noise : f32_random() - 0.5f
        x : _angle * 2.0f + noise * 0.2f;
        y : noise * 3.0f;
        z : f32_cos(_angle + noise * 0.2f) * 2.0f;
		_angle += 0.8f;

	    model(
	    	texture : copy texture
	    	shader : copy phongTextureShader
	    	world : mat4_translate(x, y, z)
	    	vertexBuffer : planeVertexBuffer() 
	    ) as #model
	}
) {
	_angle = textures.count as f32 * 0.8f / 2.0f
	children = textures.map!#model(this.textureToModel)
	this
}

