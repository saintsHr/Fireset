// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#include "fireset/core.h"
#include "fireset/fstime.h"

bool fsInit(void){
    if(!glfwInit()) return false;
    fsTimeInit();
    return true;
}

void fsExit(void){
    glfwTerminate();
}