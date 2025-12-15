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

    FsVec2f vertices[4] = {
        {-0.5f, -0.5f },
        { 0.5f, -0.5f },
        { 0.5f,  0.5f },
        {-0.5f,  0.5f }
    };

    // main loop
    while (!fsWindowShouldClose(window)){
        fsClear(0, 0, 0);

        fsDrawQuad(vertices);

        fsHandleWindow(&window);
    }

    // destroy window and closes engine
    fsDestroyWindow(&window);
    fsExit();
    return 0;
}