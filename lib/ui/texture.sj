texture(
	tex : 'ptr

	getSize() {
		w = 0
		h = 0
		c{
			SDL_QueryTexture((SDL_Texture*)_parent->tex, NULL, NULL, &sjv_w, &sjv_h);
		}c
		size(w, h)
	}
) {
	this
} destroy c{
	SDL_DestroyTexture((SDL_Texture*)_this->tex);	
}c