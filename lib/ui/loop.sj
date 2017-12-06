mainLoop() {
    size : rootWindowRenderer.getSize()
    rootScene.setSize(size)
    rootScene.clear()
    rect : rect(0, 0, size.w, size.h)
    root.setRect(rect)
    root.render(rootScene)
    rootWindowRenderer.present()

    isMouseUp = false
    isMouseDown = false
    x = 0
    y = 0
    --c--
    SDL_Event e;
    while(SDL_PollEvent( &e ) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("SDL_MOUSEBUTTONDOWN\n");
                sjv_isMouseDown = true;
                sjv_x = e.button.x;
                sjv_y = e.button.x;
                break;
            case SDL_MOUSEBUTTONUP:
                printf("SDL_MOUSEBUTTONUP\n");
                sjv_isMouseUp = true;
                sjv_x = e.button.x;
                sjv_y = e.button.x;
                break;
        }
    }
    --c--

    if isMouseUp {
        fireMouseUp(root, point(x, y)) 
    }
    if isMouseDown {
        fireMouseDown(root, point(x, y)) 
    }
    void
}

runLoop() {
	--c--
##ifdef EMSCRIPTEN
	emscripten_set_main_loop((em_callback_func)sjf_mainLoop, 0, 0);
	exit(0);
##else
	bool quit = false;
    while (!quit) {
        sjf_mainLoop();
    }
##endif	
	--c--
}