// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#include "fireset/input.h"
#include "fireset/vertex.h"

typedef struct{
    bool pressed;
    bool just_pressed;
    bool just_released;
}KeyState;

#define NUM_KEYS (GLFW_KEY_LAST + 1)
static KeyState keys[NUM_KEYS];

void fsUpdateInput(FsWindow* window){
    for (int k = 0; k < NUM_KEYS; k++){
        bool isDown = glfwGetKey(window->handle, k) == GLFW_PRESS;

        keys[k].just_pressed  = (!keys[k].pressed && isDown);
        keys[k].just_released = (keys[k].pressed && !isDown);
        keys[k].pressed       = isDown;
    }
}

bool fsIsKeyJustPressed(FsKey key){
    return keys[key].just_pressed;
}

bool fsIsKeyJustReleased(FsKey key){
    return keys[key].just_released;
}

bool fsIsKeyDown(FsKey key){
    return keys[key].pressed;
}

FsVec2 fsGetCursorPos(const FsWindow* window){
    double x, y;

    glfwGetCursorPos(window->handle, &x, &y);

    float fx = (float)x;
    float fy = (float)y;

    FsVec2 vec = FsVec2_new(fx, fy);
    return vec;
}

bool fsIsMouseButtonDown(const FsWindow* window, FsMouseButton bt){
    if (bt == FS_LMB && glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS){
        return true;
    }
    if (bt == FS_RMB && glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS){
        return true;
    }
    if (bt == FS_MMB && glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS){
        return true;
    }
    return false;
}

bool fsMouseButtonJustPressed(const FsWindow* window, FsMouseButton bt){
    static bool wasPressed = false;
    bool isPressed = fsIsMouseButtonDown(window->handle, bt);
    bool justPressed = isPressed && !wasPressed;
    wasPressed = isPressed;
    return justPressed;
}

bool fsMouseButtonJustReleased(const FsWindow* window, FsMouseButton bt) {
    static bool wasPressed = false;
    bool isPressed = fsIsMouseButtonDown(window->handle, bt);
    bool justReleased = !isPressed && wasPressed;
    wasPressed = isPressed;
    return justReleased;
}