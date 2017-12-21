loopLastRect := rect()

mainLoop() {
    ticks := 0
    --c--
    sjv_ticks = SDL_GetTicks();
    --c--
    animator.nextFrame(ticks)

    size : rootWindowRenderer.getSize()
    rootScene.setSize(size)
    rootScene.start()
    rect : rect(0, 0, size.w, size.h)
    if loopLastRect != rect {
        root.setRect(rect)
    }
    root.render(rootScene)
    rootScene.end()
    rootWindowRenderer.present()

    mouseEventType := empty'mouseEventType
    x := 0
    y := 0
    --c--
    SDL_Event e;
    while(SDL_PollEvent( &e ) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("SDL_MOUSEBUTTONDOWN\n");
                sjv_mouseeventtype.isvalid = true;
                sjv_mouseeventtype.value = sjv_mouseeventtype_down;
                sjv_x = e.button.x;
                sjv_y = e.button.y;
                break;
            case SDL_MOUSEBUTTONUP:
                printf("SDL_MOUSEBUTTONUP\n");
                sjv_mouseeventtype.isvalid = true;
                sjv_mouseeventtype.value = sjv_mouseeventtype_up;
                sjv_x = e.button.x;
                sjv_y = e.button.y;
                break;
            case SDL_MOUSEMOTION:
                sjv_mouseeventtype.isvalid = true;
                sjv_mouseeventtype.value = sjv_mouseeventtype_move;
                sjv_x = e.motion.x;
                sjv_y = e.motion.y;
                break;
        }
    }
    --c--

    shouldContinue := true // TODO: should not need this
    ifValid mouseEventType {
        ifValid m : mouse_captureElement {
            shouldContinue = m.fireMouseEvent(mouseEvent(
                type : mouseEventType
                point : point(x, y)
                isCaptured : true
            )) 
            void
        } elseEmpty {
            shouldContinue = root.fireMouseEvent(mouseEvent(
                type : mouseEventType
                point : point(x, y)
                isCaptured : false
            )) 
            void
        }
    }
    void
}

runLoop() {
	--c--
##ifdef EMSCRIPTEN
	emscripten_set_main_loop((em_callback_func)sjf_mainloop, 0, 0);
	exit(0);
##else
	bool quit = false;
    while (!quit) {
        #functionStack(mainLoop)();
    }
##endif	
	--c--
}