#pragma once

#include <GLFW/glfw3.h>
#include <stdbool.h>

typedef struct{
    GLFWwindow* handle;
    int width;
    int height;
    char* name;
}FsWindow;

FsWindow* fsCreateWindow(FsWindow* window);
void fsHandleWindow(FsWindow window);

static inline void fsDestroyWindow(FsWindow* window){
    glfwDestroyWindow(window->handle);
}

static inline bool fsWindowShouldClose(FsWindow window){
    return glfwWindowShouldClose(window.handle);
}