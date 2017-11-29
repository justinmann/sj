texture(
	tex : 0 as ptr

	getSize() {
		w = 0
		h = 0
		c{
			if (_parent->tex) {
				SDL_QueryTexture((SDL_Texture*)_parent->tex, NULL, NULL, &sjv_w, &sjv_h);
			}
		}c
		size(w, h)
	}
) {
	this
} destroy c{
	if (_this->tex) {
		SDL_DestroyTexture((SDL_Texture*)_this->tex);	
	}
}c