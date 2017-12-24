boxVertexBuffer(
    rect : 'rect
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
    float x0 = (float)_this->rect.x;
    float x1 = (float)(_this->rect.x + _this->rect.w);

    float y0 = (float)_this->rect.y;
    float y1 = (float)(_this->rect.y + _this->rect.h);

    float s0 = 0.0f;
    float s1 = 1.0f;

    float t1 = 0.0f;
    float t0 = 1.0f;

    GLuint index = (GLuint)_this->buffer->vertices->size;
    GLuint indices[] = { //
        index, index+1, index+2,
        index, index+2, index+3 };
    vertex3_texture2_t vertices[] = { //
        { x0, y0, 0.0f,  s0, t0 },
        { x0, y1, 0.0f,  s0, t1 },
        { x1, y1, 0.0f,  s1, t1 },
        { x1, y0, 0.0f,  s1, t0 } };        
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
    --c--
    this 
} copy {
    --c--
    _this->buffer = _from->buffer;
    ptr_retain(_this->buffer);
    --c--
} destroy {
    --c--
    if (ptr_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }  
    --c--
}