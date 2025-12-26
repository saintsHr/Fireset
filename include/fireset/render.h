// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

#include <GL/gl.h>
#include <stdint.h>
#include "fireset/vertex.h"
#include "fireset/image.h"

/** 
 * @defgroup Render Render
 * @brief Basic 2D rendering primitives.
 * @{
 */

/**
 * @brief RGB color representation.
 *
 * Represents a color using three 8-bit integer components
 * in the RGB color space.
 */
typedef struct{
    uint8_t r; /**< Red component (0–255) */
    uint8_t g; /**< Green component (0–255) */
    uint8_t b; /**< Blue component (0–255) */
}FsColor;

/**
 * @brief Quadrilateral primitive.
 *
 * Represents a quadrilateral used for rendering and transformations.
 */
typedef struct{
    FsVec2 position; /**< Position in window space */
    FsVec2 size;     /**< Size in window space */
    FsColor color;   /**< Color */
    float angle;     /**< Rotation angle */
}FsQuad;

/**
 * @brief Triangle primitive.
 *
 * Represents a triangle used for rendering and transformations.
 */
typedef struct{
    FsVec2 position; /**< Position in window space */
    FsVec2 size;     /**< Size in window space */
    FsColor color;   /**< Color */
    float angle;     /**< Rotation angle */
}FsTriangle;

/**
 * @brief Point primitive.
 *
 * Represents a single point used for rendering.
 */
typedef struct{
    FsVec2 position; /**< Position in window space */
    FsColor color;   /**< Color */
}FsPoint;

/**
 * @brief Circle primitive.
 *
 * Represents a circle used for rendering and transformations.
 */
typedef struct{
    FsVec2 position; /**< Position in window space */
    FsVec2 size;     /**< Size in window space */
    FsColor color;   /**< Color */
    float angle;     /**< Rotation angle */
    int segments;    /**< Number of segments used to approximate the circle */
}FsCircle;

/**
 * @brief Line primitive.
 *
 * Represents a line used for rendering and transformations.
 */
typedef struct{
    FsVec2 position; /**< Starting position in window space */
    float length;    /**< Line length */
    float angle;     /**< Rotation angle */
    float thickness; /**< Line thickness */
    FsColor color;   /**< Color */
}FsLine;

typedef struct{
    FsVec2 position;
    FsVec2 size;
    FsTexture* texture;
    float angle;
} FsSprite;

/**
 * @brief Draws a pixel.
 *
 * Draws a colored point at the specified position.
 *
 * @param p Point to draw.
 */
void fsDrawPixel(const FsPoint* p);

/**
 * @brief Draws a line.
 *
 * Draws a colored line using the provided line parameters.
 *
 * @param line Line to draw.
 */
void fsDrawLine(const FsLine* line);

/**
 * @brief Draws a triangle.
 *
 * Draws a colored triangle.
 *
 * @param tri Triangle to draw.
 */
void fsDrawTriangle(const FsTriangle* tri);

/**
 * @brief Draws a quadrilateral.
 *
 * Draws a colored quadrilateral.
 *
 * @param quad Quadrilateral to draw.
 */
void fsDrawQuad(const FsQuad* quad);

/**
 * @brief Draws a circle.
 *
 * Draws a colored circle.
 *
 * @param circle Circle to draw.
 */
void fsDrawCircle(const FsCircle* circle);

void fsDrawSprite(const FsSprite* sprite);

/**
 * @brief Sets the orthographic projection.
 *
 * Defines the orthographic rendering view for the current window.
 *
 * @param width  Width of the orthographic view.
 * @param height Height of the orthographic view.
 */
void fsOrthoSet(int width, int height);

/**
 * @brief Clears the window.
 *
 * Clears the window and the OpenGL context using the specified color.
 *
 * @param color Clear color.
 */
void fsClear(FsColor color);

/**
 * @brief Creates a color.
 *
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 *
 * @return Resulting color.
 */
FsColor FsColor_new(uint8_t r, uint8_t g, uint8_t b);

/** @} */
