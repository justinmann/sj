boxShader : shader("shaders/v3f-c4f.vert", "shaders/v3f-c4f.frag")

boxRenderer(
    rect: 'rect
    color: 'color
    --cvar--
    vertex_buffer_t* buffer;
    --cvar--

    render(surface : 'surface2d)'void {
        --c--
        glUseProgram(sjv_boxShader.id);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "model" ), 1, 0, surface->model.data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "view" ), 1, 0, surface->view.data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "projection" ), 1, 0, surface->projection.data);
        vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
        --c--
        void
    }
) { 
    --c--
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
    float x0 = (float)_this->rect.x;
    float y0 = (float)(_this->rect.y + _this->rect.h);
    float x1 = (float)(_this->rect.x + _this->rect.w);
    float y1 = (float)_this->rect.y;
    GLuint index = (GLuint)_this->buffer->vertices->size;
    GLuint indices[] = { //
        index, index+1, index+2,
        index, index+2, index+3 };
    vertex3_color4_t vertices[] = { //
        { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
        { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
        { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
        { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
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

--cstruct--
typedef struct {
    float x, y, z;    // position
    float r, g, b, a; // color
} vertex3_color4_t;	
--cstruct--
