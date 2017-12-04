textShader : shader("shaders/v3f-t2f-c4f.vert", "shaders/v3f-t2f-c4f.frag")

textRenderer(
    text: 'string
    point: 'point
    color: 'color
    font: 'font
    --cvar--
    vertex_buffer_t* buffer;
    --cvar--

    render(surface : 'surface2d)'void {
        --c--
        glBindTexture(GL_TEXTURE_2D, _parent->font.atlas->id);
        glUseProgram(sjv_textShader.id);
        glUniform1i(glGetUniformLocation(sjv_textShader.id, "texture" ), 0 );
        glUniformMatrix4fv(glGetUniformLocation(sjv_textShader.id, "model" ), 1, 0, surface->model.data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_textShader.id, "view" ), 1, 0, surface->view.data);
        glUniformMatrix4fv(glGetUniformLocation(sjv_textShader.id, "projection" ), 1, 0, surface->projection.data);
        vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
        --c--
        void
    }
) { 
    --c--
    vec2 pen = {{ (float)_this->point.x, (float)_this->point.y }};
    vec4 color = {{ _this->color.r, _this->color.g, _this->color.b, _this->color.a }};

    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f,color:4f");
    add_text(_this->buffer, _this->font.font, (char*)_this->text.data.data, &color, &pen);

    glBindTexture(GL_TEXTURE_2D, _this->font.font->atlas->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (int)_this->font.font->atlas->width, (int)_this->font.font->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->font.font->atlas->data );
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
    float r, g, b, a; // color
} vertex3_texture2_color3_t;	
--cstruct--

--cdefine--
void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, vec4 * color, vec2 * pen);	
vec2 get_text_size(texture_font_t * font, char *text);
--cdefine--

--cfunction--
void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, vec4 * color, vec2 * pen) {
    pen->y += (float)(int)font->ascender;
    size_t i;
    float r = color->red, g = color->green, b = color->blue, a = color->alpha;
    for (i = 0; i < strlen(text); ++i) {
        texture_glyph_t *glyph = texture_font_get_glyph( font, text + i );
        if (glyph != NULL) {
            float kerning = 0.0f;
            if( i > 0) {
                kerning = texture_glyph_get_kerning( glyph, text + i - 1 );
            }
            pen->x += kerning;
            float x0 = (float)(int)( pen->x + glyph->offset_x );
            float y0 = (float)(int)( pen->y + glyph->height - glyph->offset_y );
            float x1 = (float)(int)( x0 + glyph->width );
            float y1 = (float)(int)( y0 - glyph->height );
            float s0 = glyph->s0;
            float t0 = glyph->t0;
            float s1 = glyph->s1;
            float t1 = glyph->t1;
            GLuint index = (GLuint)buffer->vertices->size;
            GLuint indices[] = { //
                index, index+1, index+2,
                index, index+2, index+3 };
            vertex3_texture2_color3_t vertices[] = { //
                { x0, y1, 0.0f,  s0,t0,  r,g,b,a },
                { x0, y0, 0.0f,  s0,t1,  r,g,b,a },
                { x1, y0, 0.0f,  s1,t1,  r,g,b,a },
                { x1, y1, 0.0f,  s1,t0,  r,g,b,a } };
            vertex_buffer_push_back_indices( buffer, indices, 6 );
            vertex_buffer_push_back_vertices( buffer, vertices, 4 );
            pen->x += glyph->advance_x;
        }
    }
}	

vec2 get_text_size(texture_font_t * font, char *text) {
    vec2 size = {{ 0, font->height }};
    size_t i;
    for( i = 0; i < strlen(text); ++i ) {
        texture_glyph_t *glyph = texture_font_get_glyph(font, text + i);
        if (glyph != NULL) {
            float kerning = 0.0f;
            if( i > 0) {
                kerning = texture_glyph_get_kerning(glyph, text + i - 1);
            }
            size.x += kerning;
            size.x += glyph->advance_x;
        }
    }
    return size;
}   
--cfunction--