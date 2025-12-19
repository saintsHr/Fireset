#include "fireset/input.h"

bool fsIsKeyDown(FsWindow w, FsKey k){
    return glfwGetKey(w.handle, k) == GLFW_PRESS;
}