#pragma once

/** 
 * @defgroup Vertex
 * @{
 */

/**
 * @brief 2D Vector.
 * 
 * Used to define a position or velocity on a 2 dimentional space.
 */
typedef struct{
    float x; /**< Horizontal axis. */
    float y; /**< Vertical axis. */
}FsVec2;

/**
 * @brief 3D Vector.
 * 
 * Used to define a position or velocity on a 3 dimentional space.
 */
typedef struct{
    float x; /**< Horizontal axis. */
    float y; /**< Vertical axis. */
    float z; /**< Depth axis. */
}FsVec3;

/** @} */