vertex_location_texture_format : "vertex:3f,tex_coord:2f"
vertex_location_texture(
    location : vec3()
    texture : vec2()
) { this }

cubeVertexBuffer() { 
    x0 = -1.0f
    x1 = 1.0f
    y0 = -1.0f
    y1 = 1.0f
    z0 = -1.0f
    z1 = 1.0f
    s0 = 0.0f
    s1 = 1.0f
    t0 = 0.0f
    t1 = 1.0f

    vertexBuffer!vertex_location_texture(
        format : copy vertex_location_texture_format
        indices : [
            0, 1, 2,
            0, 2, 3,
            4, 5, 6,
            4, 6, 7,
            0, 1, 5,
            0, 5, 4,
            3, 2, 6,
            3, 6, 7,
            1, 5, 6,
            1, 6, 2,
            0, 4, 7,
            0, 7, 3
        ]
        vertices : [
            vertex_location_texture(vec3(x0, y0, z0), vec2(s0, t0)),
            vertex_location_texture(vec3(x0, y1, z0), vec2(s0, t1)),
            vertex_location_texture(vec3(x1, y1, z0), vec2(s1, t1)),
            vertex_location_texture(vec3(x1, y0, z0), vec2(s1, t0)),
            vertex_location_texture(vec3(x0, y0, z1), vec2(s0, t0)),
            vertex_location_texture(vec3(x0, y1, z1), vec2(s0, t1)),
            vertex_location_texture(vec3(x1, y1, z1), vec2(s1, t1)),
            vertex_location_texture(vec3(x1, y0, z1), vec2(s1, t0))
        ]
    )
}

planeVertexBuffer() { 
    x0 = -1.0f
    x1 = 1.0f
    y0 = -1.0f
    y1 = 1.0f
    s0 = 0.0f
    s1 = 1.0f
    t0 = 0.0f
    t1 = 1.0f

    vertexBuffer!vertex_location_texture(
        format : copy vertex_location_texture_format
        indices : [
            0, 1, 2,
            0, 2, 3
        ]
        vertices : [
            vertex_location_texture(vec3(x0, y0, z0), vec2(s0, t0)),
            vertex_location_texture(vec3(x0, y1, z0), vec2(s0, t1)),
            vertex_location_texture(vec3(x1, y1, z0), vec2(s1, t1)),
            vertex_location_texture(vec3(x1, y0, z0), vec2(s1, t0))
        ]
    )
}