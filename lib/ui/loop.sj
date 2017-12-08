mouseEvent_move : 0
mouseEvent_up : 1
mouseEvent_down : 2

mainLoop() {
    size : rootWindowRenderer.getSize()
    rootScene.setSize(size)
    rootScene.clear()
    rect : rect(0, 0, size.w, size.h)
    root.setRect(rect)
    root.render(rootScene)
    rootWindowRenderer.present()

    mouseEvent = -1
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
                sjv_mouseEvent = sjv_mouseEvent_down;
                sjv_x = e.button.x;
                sjv_y = e.button.y;
                break;
            case SDL_MOUSEBUTTONUP:
                printf("SDL_MOUSEBUTTONUP\n");
                sjv_mouseEvent = sjv_mouseEvent_up;
                sjv_x = e.button.x;
                sjv_y = e.button.y;
                break;
            case SDL_MOUSEMOTION:
                printf("SDL_MOUSEMOTION\n");
                sjv_mouseEvent = sjv_mouseEvent_move;
                sjv_x = e.motion.x;
                sjv_y = e.motion.y;
                break;
        }
    }
    --c--

    if mouseEvent != -1 {
        root.fireMouseEvent(point(x, y), mouseEvent) 
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