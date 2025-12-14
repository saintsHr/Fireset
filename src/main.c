#include <fireset/fireset.h>

int main(void){
    // inits engine
    if (!fsInit()) return 1;

    // creates window
    FsWindow window;
    window.width = 640;
    window.height = 480;
    window.name = "Example Game";
    fsCreateWindow(&window);

    // main loop
    while (!fsWindowShouldClose(window)){
        fsHandleWindow(window);
    }

    // destroy window and closes engine
    fsDestroyWindow(&window);
    fsExit();
    return 0;
}