// this file is just for internal testing, its not important for the engine
// but needed for compiling, you can just left it as is or use as
// example for using the engine, or even to test modifications on the engine.

#include <fireset/fireset.h>
#include <stdio.h>

int main(void){
    // inits engine
    if (!fsInit()) return 1;

    // creates window
    FsWindow window;
    window.width = 800;
    window.height = 600;
    window.name = "Example Game";
    fsCreateWindow(&window);

    FsVec2 vertices[4] = {
        {300, 400},
        {500, 400},
        {500, 200},
        {300, 200},
    };

    FsColor color = {255, 128, 0};

    // main loop
    while (!fsWindowShouldClose(window)){
        fsClear((FsColor){0, 0, 0});

        fsDrawQuad(vertices, color);

        fsHandleWindow(&window);
    }

    // destroy window and closes engine
    fsDestroyWindow(&window);
    fsExit();
    return 0;
}