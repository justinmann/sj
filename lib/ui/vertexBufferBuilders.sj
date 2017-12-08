vertex_location_texture_normal_format : "vertex:3f,tex_coord:2f,normal:3f"
vertex_location_texture_normal(
    location : vec3()
    texture : vec2()
    normal : vec3()
) { this }

cubeVertexBuffer(    
    x0 : -1.0f
    x1 : 1.0f
    y0 : -1.0f
    y1 : 1.0f
    z0 : -1.0f
    z1 : 1.0f
    s0 : 0.0f
    s1 : 1.0f
    t0 : 0.0f
    t1 : 1.0f
) { 
    vertexBuffer!vertex_location_texture_normal(
        format : copy vertex_location_texture_normal_format
        indices : [
             0,  1,  2 // front
             0,  2,  3
             4,  5,  6 // back
             4,  6,  7
             8,  9, 10 // left
             8, 10, 11
            12, 13, 14 // right
            12, 14, 15
            16, 17, 18 // bottom
            16, 18, 19
            20, 21, 22 // top
            20, 22, 23
        ]
        vertices : [
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(0.0f, 0.0f, -1.0f)) // front
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s1, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s1, t0), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x0, y0, z1), vec2(s0, t0), vec3(0.0f, 0.0f,  1.0f)) // back
            vertex_location_texture_normal(vec3(x0, y1, z1), vec2(s0, t1), vec3(0.0f, 0.0f,  1.0f))
            vertex_location_texture_normal(vec3(x1, y1, z1), vec2(s1, t1), vec3(0.0f, 0.0f,  1.0f))
            vertex_location_texture_normal(vec3(x1, y0, z1), vec2(s1, t0), vec3(0.0f, 0.0f,  1.0f))
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(-1.0f, 0.0f, 0.0f)) // left
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t1), vec3(-1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y1, z1), vec2(s1, t1), vec3(-1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y0, z1), vec2(s1, t0), vec3(-1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s0, t0), vec3( 1.0f, 0.0f, 0.0f)) // right
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s0, t1), vec3( 1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y1, z1), vec2(s1, t1), vec3( 1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z1), vec2(s1, t0), vec3( 1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(0.0f, -1.0f, 0.0f)) // bottom
            vertex_location_texture_normal(vec3(x0, y0, z1), vec2(s0, t1), vec3(0.0f, -1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z1), vec2(s1, t1), vec3(0.0f, -1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s1, t0), vec3(0.0f, -1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t0), vec3(0.0f,  1.0f, 0.0f)) // top
            vertex_location_texture_normal(vec3(x0, y1, z1), vec2(s0, t1), vec3(0.0f,  1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y1, z1), vec2(s1, t1), vec3(0.0f,  1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s1, t0), vec3(0.0f,  1.0f, 0.0f))
        ]
    )
}

planeVertexBuffer(    
    x0 : -1.0f
    x1 : 1.0f
    y0 : -1.0f
    y1 : 1.0f
    z0 : 0.0f
    s0 : 0.0f
    s1 : 1.0f
    t0 : 0.0f
    t1 : 1.0f
) { 
    vertexBuffer!vertex_location_texture_normal(
        format : copy vertex_location_texture_normal_format
        indices : [
            0, 1, 2
            0, 2, 3
        ]
        vertices : [
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s1, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s1, t0), vec3(0.0f, 0.0f, -1.0f))
        ]
    )
}