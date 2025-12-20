// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

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

/**
 * @brief Represents Quads.
 * 
 * Represents a quadrilateral object, used on rendering and transforms
 */
typedef struct{
    FsVec2 position; /**< Position of the object in the window */
    FsVec2 size;     /**< Size of the object in the window */
    FsColor color;   /**< Color of the object in the window */
    float angle;     /**< Angle of the object in the window */
}FsQuad;

/**
 * @brief Represents Triangles.
 * 
 * Represents a triangle object, used on rendering and transforms
 */
typedef struct{
    FsVec2 position; /**< Position of the object in the window */
    FsVec2 size;     /**< Size of the object in the window */
    FsColor color;   /**< Color of the object in the window */
    float angle;     /**< Angle of the object in the window */
}FsTriangle;

/**
 * @brief Represents Point.
 * 
 * Represents a single point object, used on rendering and transforms
 */
typedef struct{
    FsVec2 position; /**< Position of the object in the window */
    FsColor color;   /**< Color of the object in the window */
}FsPoint;

/**
 * @brief Represents a Circle.
 * 
 * Represents a circle object, used on rendering and transforms
 */
typedef struct{
    FsVec2 position; /**< Position of the object in the window */
    FsVec2 size;     /**< Size of the object in the window */
    FsColor color;   /**< Color of the object in the window */
    float angle;     /**< Angle of the object in the window */
    int segments;    /**< Ammount of segments in the circle */
}FsCircle;

/**
 * @brief Represents Lines.
 * 
 * Represents a line obhect, used on rendering and transforms
 */
typedef struct {
    FsVec2 position; /**< Position of the object in the window */
    float length;    /**< Total lenght of the line (starting from position) */
    float angle;     /**< Angle of the object in the window */
    float thickness; /**< Thickness of the line in the window */
    FsColor color;   /**< Color of the object in the window */
}FsLine;

/**
 * @brief Draws a pixel.
 * 
 * Draws a colored point/pixel on a specific position on the window.
 * 
 * @param p Object to draw.
 */
void fsDrawPixel(const FsPoint* p);

/**
 * @brief Draws a line.
 * 
 * Draws a colored line between 2 points on the window.
 * 
 * @param line Object to draw.
 */
void fsDrawLine(const FsLine* line);

/**
 * @brief Draws a triangle.
 * 
 * Draws a colored triangle on the window.
 * 
 * @param tri Object to draw.
 */
void fsDrawTriangle(const FsTriangle* tri);

/**
 * @brief Draws a quadrilateral.
 * 
 * Draws a colored quadrilateral on the window.
 * 
 * @param quad Object to draw.
 */
void fsDrawQuad(const FsQuad* quad);

/**
 * @brief Draws a circle.
 * 
 * Draws a colored circle on the window.
 * 
 * @param circle Object to draw.
 */
void fsDrawCircle(const FsCircle* circle);

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

FsColor FsColor_new(float r, float g, float b);

/** @} */