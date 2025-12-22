// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#include "fireset/vertex.h"
#include "fireset/render.h"

FsVec2 FsVec2_new(float x, float y){
    return (FsVec2){x, y};
}

FsVec2 FsVec2_toScreen(FsVec2 vec, FsWindow* window){
    FsVec2 vecn = (FsVec2){vec.x, window->height - vec.y};
    return vecn;
}