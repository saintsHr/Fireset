// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#define STB_IMAGE_IMPLEMENTATION
#include "fireset/stb_image.h"

#include "fireset/core.h"
#include "fireset/fstime.h"

bool fsInit(void){
    if(!glfwInit()) return false;
    fsTimeInit();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    return true;
}

void fsExit(void){
    glfwTerminate();
}