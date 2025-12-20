// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

/** 
 * @defgroup Vertex Vertex
 * @brief 2D vector types and functions.
 * @{
 */

/**
 * @brief 2D vector.
 *
 * Represents a point, position, or velocity in 2-dimensional space.
 */
typedef struct{
    float x; /**< Horizontal component */
    float y; /**< Vertical component */
} FsVec2;

/**
 * @brief Creates a 2D vector.
 *
 * @param x Horizontal component.
 * @param y Vertical component.
 *
 * @return FsVec2 instance with specified components.
 */
FsVec2 FsVec2_new(float x, float y);

/** @} */