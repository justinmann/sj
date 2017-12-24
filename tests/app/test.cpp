#include <emscripten.h>
#include <emscripten/html5.h>

EM_BOOL onClick(int eventType, const EmscriptenMouseEvent* event, void* userData) {
    EM_ASM_({
        console.log(UTF8ToString($0));
    }, "OnClick");  

    return true;
}

void mainloop()
{
}

int main(void) {
    // EM_ASM_({
    //  document.open();
    //  document.write(UTF8ToString($0));
    //  document.close();
    // }, "Hello There");

    emscripten_set_click_callback(0, 0, false, onClick);

    emscripten_set_main_loop(mainloop, 10, 0);

    return 0;
}