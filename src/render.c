#include "fireset/render.h"
#include <math.h>

#define PI 3.14159265359

void fsDrawTriangle(const FsVec2* vertices, FsColor color){
    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(vertices[0].x, vertices[0].y);
        glVertex2f(vertices[1].x, vertices[1].y);
        glVertex2f(vertices[2].x, vertices[2].y);
    glEnd();
}

void fsDrawPixel(FsVec2 pos, FsColor color){
    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
    glBegin(GL_POINT);
        glVertex2f(pos.x, pos.y);
    glEnd();
}

void fsDrawLine(FsVec2 p1, FsVec2 p2, FsColor color){
    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
    glBegin(GL_LINE);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
    glEnd();
}

void fsDrawQuad(const FsVec2* vertices, FsColor color){
    glColor3f(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f);
    glBegin(GL_QUADS);
        glVertex2f(vertices[0].x, vertices[0].y);
        glVertex2f(vertices[1].x, vertices[1].y);
        glVertex2f(vertices[2].x, vertices[2].y);
        glVertex2f(vertices[3].x, vertices[3].y);
    glEnd();
}

void fsDrawCircle(FsVec2 center, int radius, int segments, FsColor color){
    if (segments < 8) segments = 8;
    if (segments > 128) segments = 128;

    FsVec2 vertices[segments];

    for (int i = 0; i < segments; i++){
        float theta = i * 2.0f * PI / segments;
        vertices[i].x = center.x + radius * cos(theta);
        vertices[i].y = center.y + radius * sin(theta);
    }

    for (int i = 0; i < segments; i++){
        int next = (i + 1) % segments;
        FsVec2 triangle[3] = {center, vertices[i], vertices[next]};
        fsDrawTriangle(triangle, color);
    }
}

void fsDrawPolygon(const FsVec2* vertices, int count, FsColor color){
    if(count < 3) return;

    FsVec2 center = vertices[0];

    for(int i = 1; i < count - 1; i++){
        FsVec2 triangle[3] = {center, vertices[i], vertices[i+1]};
        fsDrawTriangle(triangle, color);
    }
}

void fsClear(FsColor color){
    glClearColor(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void fsSetOrtho(int width, int height){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void fsBeginTransform(){
    glPushMatrix();
}

void fsStopTransform(){
    glPopMatrix();
}

void fsMove(float x, float y, float z){
    glTranslatef(x, y, z);
}