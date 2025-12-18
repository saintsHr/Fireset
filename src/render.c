#include "fireset/render.h"
#include <math.h>

#define PI 3.14159265359

void fsDrawTriangle(FsTriangle tri){
    glPushMatrix();
        glTranslatef(tri.position.x, tri.position.y, 0.0f);
        glRotatef(tri.angle, 0, 0, 1.0f);
        glScalef(tri.size.x, tri.size.y, 1.0f);

        glColor3f(
            tri.color.r / 255.0f,
            tri.color.g / 255.0f,
            tri.color.b / 255.0f
        );

        glBegin(GL_TRIANGLES);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(1.0f, 0.0f);
            glVertex2f(0.5f, 1.0f);
        glEnd();
    glPopMatrix();
}

void fsDrawPixel(FsPoint p){
    glPushMatrix();
        glTranslatef(p.position.x, p.position.y, 0.0f);

        glColor3f(
            p.color.r / 255.0f,
            p.color.g / 255.0f,
            p.color.b / 255.0f
        );

        glBegin(GL_POINT);
            glVertex2f(0.0f, 0.0f);
        glEnd();
    glPopMatrix();
}

void fsDrawLine(FsLine line){
    glPushMatrix();
        glTranslatef(line.position.x, line.position.y, 0.0f);
        glRotatef(line.angle, 0.0f, 0.0f, 1.0f);
        glScalef(line.length, line.thickness, 1.0f);

        glColor3f(
            line.color.r / 255.0f,
            line.color.g / 255.0f,
            line.color.b / 255.0f
        );

        glBegin(GL_QUADS);
            glVertex2f(0.0f, -0.5f);
            glVertex2f(1.0f, -0.5f);
            glVertex2f(1.0f,  0.5f);
            glVertex2f(0.0f,  0.5f);
        glEnd();
    glPopMatrix();
}

void fsDrawQuad(FsQuad quad){
    glPushMatrix();
        glTranslatef(quad.position.x, quad.position.y, 0.0f);
        glRotatef(quad.angle, 0, 0, 1.0f);
        glScalef(quad.size.x, quad.size.y, 1.0f);

        glColor3f(
            quad.color.r / 255.0f,
            quad.color.g / 255.0f,
            quad.color.b / 255.0f
        );

        glBegin(GL_QUADS);
            glVertex2f(0, 0);
            glVertex2f(1, 0);
            glVertex2f(1, 1);
            glVertex2f(0, 1);
        glEnd();
    glPopMatrix();
}

void fsDrawCircle(FsCircle circle){
    int segments = circle.segments;
    if (segments < 8)   segments = 8;
    if (segments > 128) segments = 128;

    glPushMatrix();
        glTranslatef(circle.position.x, circle.position.y, 0.0f);
        glRotatef(circle.angle, 0.0f, 0.0f, 1.0f);
        glScalef(circle.size.x, circle.size.y, 1.0f);

        glColor3f(
            circle.color.r / 255.0f,
            circle.color.g / 255.0f,
            circle.color.b / 255.0f
        );

        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.5f, 0.5f);
            for(int i = 0; i <= segments; i++){
                float theta = (float)i / (float)segments * 2.0f * PI;
                float x = 0.5f + cosf(theta) * 0.5f;
                float y = 0.5f + sinf(theta) * 0.5f;
                glVertex2f(x, y);
            }
        glEnd();
    glPopMatrix();
}

void fsClear(FsColor color){
    glClearColor(
        color.r / 255.0f,
        color.g / 255.0f,
        color.b / 255.0f,
        1.0f
    );

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void fsSetOrtho(int width, int height){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}