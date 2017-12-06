cubeVertexBuffer(
    --cvar--
    vertex_buffer_t* buffer;
    --cvar--

    render(scene : 'scene2d)'void {
        --c--
        vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
        --c--
        void
    }
) { 
    --c--
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
    float x0 = -1.0f;
    float x1 = 1.0f;

    float y0 = -1.0f;
    float y1 = 1.0f;

    float z0 = -1.0f;
    float z1 = 1.0f;

    float s0 = 0.0f;
    float s1 = 1.0f;

    float t0 = 0.0f;
    float t1 = 1.0f;

    GLuint index = (GLuint)_this->buffer->vertices->size;
    GLuint indices[] = { //
        index+0, index+1, index+2,
        index+0, index+2, index+3,

        index+4, index+5, index+6,
        index+4, index+6, index+7,

        index+0, index+1, index+5,
        index+0, index+5, index+4,

        index+3, index+2, index+6,
        index+3, index+6, index+7,

        index+1, index+5, index+6,
        index+1, index+6, index+2,

        index+0, index+4, index+7,
        index+0, index+7, index+3,

         };
    vertex3_texture2_t vertices[] = { //
        { x0, y0, z0,  s0, t0 },
        { x0, y1, z0,  s0, t1 },
        { x1, y1, z0,  s1, t1 },
        { x1, y0, z0,  s1, t0 },
        { x0, y0, z1,  s0, t0 },
        { x0, y1, z1,  s0, t1 },
        { x1, y1, z1,  s1, t1 },
        { x1, y0, z1,  s1, t0 }};        
    vertex_buffer_push_back_indices( _this->buffer, indices, 36 );
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 8 );
    --c--
    this 
} copy {
    --c--
    _this->buffer = _from->buffer;
    _retain(_this->buffer);
    --c--
} destroy {
    --c--
    if (_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }  
    --c--
}