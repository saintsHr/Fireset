#pragma once

#include <stdint.h>
#include "GL/gl.h"

typedef struct{
    uint8_t* buffer;
    int width;
    int height;
}FsImage;

typedef struct{
    GLuint id;
    int width;
    int height;
}FsTexture;

FsImage fsImageLoad(const char* filename);
FsTexture fsTextureLoad(const char* filename);