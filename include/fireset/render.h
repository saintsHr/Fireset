#pragma once

#include <GL/gl.h>
#include "stdint.h"
#include "fireset/vertex.h"

/** 
 * @defgroup Render
 * @{
 */

/**
 * @brief Represents Color.
 * 
 * The main color format of the library, uses 3, 8-bit integers
 * to represent colors in te RGB format, used for many things such as
 * primitive drawing, window background, clear color, etc. 
 */
typedef struct{
    uint8_t r; /**< Red (0-255) */
    uint8_t g; /**< Green (0-255) */
    uint8_t b; /**< Blue (0-255) */
}FsColor;

typedef struct{
    FsVec2 position;
    FsVec2 size;
    FsColor color;
    float angle;
}FsQuad;

typedef struct{
    FsVec2 position;
    FsVec2 size;
    FsColor color;
    float angle;
}FsTriangle;

typedef struct{
    FsVec2 position;
    FsColor color;
}FsPoint;

typedef struct{
    FsVec2 position;
    FsVec2 size;
    FsColor color;
    float angle;
    int segments;
}FsCircle;

typedef struct {
    FsVec2 position;
    float length;
    float angle;
    float thickness;
    FsColor color;
}FsLine;

/**
 * @brief Draws a pixel.
 * 
 * Draws a colored point/pixel on a specific position on the window.
 * 
 * @param pos The position to plot the pixel on the window.
 * @param color The color of the pixel to be plotted on the window.
 */
void fsDrawPixel(FsPoint p);

/**
 * @brief Draws a line.
 * 
 * Draws a colored, 1 pixel width line between 2 points on the window.
 * 
 * @param p1 The first point used to draw the line.
 * @param p2 The second point used to draw the line.
 * @param color Color used to draw the line.
 */
void fsDrawLine(FsLine line);

/**
 * @brief Draws a triangle.
 * 
 * Draws a colored triangle on the window.
 * 
 * @param vertices The 3 vertices used to draw the triangle.
 * @param color Color used to draw the triangle.
 */
void fsDrawTriangle(FsTriangle tri);

/**
 * @brief Draws a quadrilateral.
 * 
 * Draws a colored quadrilateral on the window.
 * 
 * @param vertices The 4 vertices used to draw the quadrilateral.
 * @param color Color used to draw the quadrilateral.
 */
void fsDrawQuad(const FsQuad quad);

/**
 * @brief Draws a circle.
 * 
 * Draws a colored circle on the window.
 * 
 * @param center The center of the circle.
 * @param radius The radius of the circle.
 * @param segments The amount of segments used to draw the circle.
 * @param color Color used to draw the circle.
 */
void fsDrawCircle(FsCircle circle);

/**
 * @brief Sets ortographic view.
 * 
 * Defines the orthographic view/rendering of the window.
 * 
 * @param width the width of the orthograpich view.
 * @param height the height of the orthograpich view.
 */
void fsSetOrtho(int width, int height);

/**
 * @brief Clears the window.
 * 
 * Clears the window & OpenGL context, removing any rendering done.
 * 
 * @param color The color used to clear the window.
 */
void fsClear(FsColor color);

/** @} */