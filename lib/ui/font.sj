font(
	src : 'string
	size : 'f32
    --cvar--
	texture_font_t* font;
	texture_atlas_t* atlas;
    --cvar--

    getTexture()'texture {
        w := 0
        h := 0
        id := 0u
        --c--
        sjv_w = _parent->atlas->width;
        sjv_h = _parent->atlas->height;
        sjv_id = _parent->atlas->id;
        --c--
        texture(size(w, h), id)
    }

    getTextSize(str : 'string)'size {
        w := 0
        h := 0
        --c--
        vec2 size = get_text_size(_parent->font, (char*)str->data.data);
        sjv_w = (int)size.x;
        sjv_h = (int)size.y;
        --c--
        size(w, h)
    }
) {
    --c--
    _this->atlas = texture_atlas_new( 512, 512, 3 );
    _this->font = texture_font_new_from_file(_this->atlas, _this->size, (char*)_this->src.data.data);
    if (_this->font == 0) {
        printf("texture_font_new_from_file Error\n");
    }	

    glGenTextures( 1, &_this->atlas->id );
    glBindTexture( GL_TEXTURE_2D, _this->atlas->id );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, (int)_this->atlas->width, (int)_this->atlas->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _this->atlas->data );
    --c--
	this
} copy {
    --c--
    _this->atlas = _from->atlas;
    ptr_retain(_this->atlas);

    _this->font = _from->font;
    ptr_retain(_this->font);
    --c--
} destroy {
    --c--
    if (ptr_release(_this->atlas)) {
	   texture_atlas_delete(_this->atlas);
    }

    if (ptr_release(_this->font)) {
	   texture_font_delete(_this->font);
    }
    --c--
}