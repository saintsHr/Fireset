#include "fireset/render.h"

void fsDrawTriangle(const FsVec2f* vertices){
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(vertices[0].x, vertices[0].y);
        glVertex2f(vertices[1].x, vertices[1].y);
        glVertex2f(vertices[2].x, vertices[2].y);
    glEnd();
}

void fsDrawQuad(const FsVec2f* vertices){
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(vertices[0].x, vertices[0].y);
        glVertex2f(vertices[1].x, vertices[1].y);
        glVertex2f(vertices[2].x, vertices[2].y);
        glVertex2f(vertices[3].x, vertices[3].y);
    glEnd();
}

void fsClear(int red, int green, int blue){
    glClearColor(red / 255.0f, green / 255.0f, blue / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}