imageRenderer(
    rect : 'rect
    image : 'image
    --cvar--
    vertex_buffer_t* buffer;
    --cvar--

    render(scene : 'scene2d)'void {
        --c--
        glBindTexture(GL_TEXTURE_2D, _parent->image.texture.id);
        glUseProgram(sjv_imageshader.id);
        glUniform1i(glGetUniformLocation(sjv_imageshader.id, "texture" ), 0 );
        glUniformMatrix4fv(glGetUniformLocation(sjv_imageshader.id, "model" ), 1, 0, (GLfloat*)&scene->model);
        glUniformMatrix4fv(glGetUniformLocation(sjv_imageshader.id, "view" ), 1, 0, (GLfloat*)&scene->view);
        glUniformMatrix4fv(glGetUniformLocation(sjv_imageshader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection);
        vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
        --c--
        void
    }
) { 
    --c--
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
    float x0 = (float)_this->rect.x;
    float x1 = (float)(_this->rect.x + _this->image.margin.l);
    float x2 = (float)(_this->rect.x + _this->rect.w - _this->image.margin.r);
    float x3 = (float)(_this->rect.x + _this->rect.w);

    float y0 = (float)_this->rect.y;
    float y1 = (float)(_this->rect.y + _this->image.margin.t);
    float y2 = (float)(_this->rect.y + _this->rect.h - _this->image.margin.b);
    float y3 = (float)(_this->rect.y + _this->rect.h);

    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
    float s1 = (float)(_this->image.rect.x + _this->image.margin.l) / (float)_this->image.texture.size.w;
    float s2 = (float)(_this->image.rect.x + _this->image.rect.w - _this->image.margin.r) / (float)_this->image.texture.size.w;
    float s3 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;

    float t3 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
    float t2 = (float)(_this->image.rect.y + _this->image.margin.b) / (float)_this->image.texture.size.h;
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h - _this->image.margin.t) / (float)_this->image.texture.size.h;
    float t0 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;

    if (_this->image.margin.t > 0) {
        if (_this->image.margin.l > 0) {
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
        }

        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x1, y0, 0.0f,  s1, t0 },
                { x1, y1, 0.0f,  s1, t1 },
                { x2, y1, 0.0f,  s2, t1 },
                { x2, y0, 0.0f,  s2, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }

        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x2, y0, 0.0f,  s2, t0 },
                { x2, y1, 0.0f,  s2, t1 },
                { x3, y1, 0.0f,  s3, t1 },
                { x3, y0, 0.0f,  s3, t0 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }

    {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x0, y1, 0.0f,  s0, t1 },
                { x0, y2, 0.0f,  s0, t2 },
                { x1, y2, 0.0f,  s1, t2 },
                { x1, y1, 0.0f,  s1, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }

        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x1, y1, 0.0f,  s1, t1 },
                { x1, y2, 0.0f,  s1, t2 },
                { x2, y2, 0.0f,  s2, t2 },
                { x2, y1, 0.0f,  s2, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }

        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x2, y1, 0.0f,  s2, t1 },
                { x2, y2, 0.0f,  s2, t2 },
                { x3, y2, 0.0f,  s3, t2 },
                { x3, y1, 0.0f,  s3, t1 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }

    if (_this->image.margin.b > 0) {
        if (_this->image.margin.l > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x0, y2, 0.0f,  s0, t2 },
                { x0, y3, 0.0f,  s0, t3 },
                { x1, y3, 0.0f,  s1, t3 },
                { x1, y2, 0.0f,  s1, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }

        {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x1, y2, 0.0f,  s1, t2 },
                { x1, y3, 0.0f,  s1, t3 },
                { x2, y3, 0.0f,  s2, t3 },
                { x2, y2, 0.0f,  s2, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }

        if (_this->image.margin.r > 0) {
            GLuint index = (GLuint)_this->buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_t vertices[] = { //
                { x2, y2, 0.0f,  s2, t2 },
                { x2, y3, 0.0f,  s2, t3 },
                { x3, y3, 0.0f,  s3, t3 },
                { x3, y2, 0.0f,  s3, t2 } };        
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
        }
    }

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