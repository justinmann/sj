imageShader : shader("shaders/v3f-t2f.vert", "shaders/v3f-t2f.frag")

imageRenderer(
    rect: 'rect
    image: 'image
    --cvar--
    vertex_buffer_t* buffer;
    --cvar--

    render(surface : 'surface2d)'void {
        --c--
        glBindTexture(GL_TEXTURE_2D, _parent->image.texture.id);
        glUseProgram(sjv_imageShader.id);
        glUniform1i(glGetUniformLocation(sjv_imageShader.id, "texture" ), 0 );
        glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "model" ), 1, 0, surface->model.data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "view" ), 1, 0, surface->view.data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "projection" ), 1, 0, surface->projection.data);
        vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
        --c--
        void
    }
) { 
    --c--
    _this->buffer = vertex_buffer_new("vertex:3f,texture:2f");
    float x0 = (float)_this->rect.x;
    float y0 = (float)(_this->rect.y + _this->rect.h);
    float x1 = (float)(_this->rect.x + _this->rect.w);
    float y1 = (float)_this->rect.y;
    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
    float t0 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
    float s1 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;
    GLuint index = (GLuint)_this->buffer->vertices->size;
    GLuint indices[] = { //
        index, index+1, index+2,
        index, index+2, index+3 };
    vertex3_texture2_t vertices[] = { //
        { x0, y1, 0.0f,  s0, t0 },
        { x0, y0, 0.0f,  s0, t1 },
        { x1, y0, 0.0f,  s1, t1 },
        { x1, y1, 0.0f,  s1, t0 } };
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
    float s, t;       // texture
} vertex3_texture2_t;	
--cstruct--