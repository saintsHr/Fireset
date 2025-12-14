#include "fireset/window.h"

#include <stdbool.h>

FsWindow* fsCreateWindow(FsWindow* window){
    // creates window object and set context
    window->handle = glfwCreateWindow(window->width, window->height, window->name, NULL, NULL);
    if (!window->handle){
        glfwTerminate();
        return window;
    }

    // sets context
    glfwMakeContextCurrent(window->handle);

    // enables depth test for 3D
    glEnable(GL_DEPTH_TEST);

    return window;
}

void fsHandleWindow(FsWindow window){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window.handle);
    glfwPollEvents();
}