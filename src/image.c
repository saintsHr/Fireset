#include "fireset/image.h"

#include "fireset/stb_image.h"

FsImage fsImageLoad(const char* filename){
    FsImage image = {0};

    image.buffer = stbi_load(
        filename,
        &image.width,
        &image.height,
        NULL,
        4
    );

    return image;
}

FsTexture fsTextureLoad(const char* filename){
    FsImage image = fsImageLoad(filename);

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        image.width,
        image.height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        image.buffer
    );

    glBindTexture(GL_TEXTURE_2D, tex);
    
    FsTexture texture = {
        tex,
        image.width,
        image.height
    };

    return texture;
}