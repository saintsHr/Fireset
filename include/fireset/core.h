// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

#include "fireset/window.h"

#include <GLFW/glfw3.h>
#include <stdbool.h>

/** 
 * @defgroup Core
 * @{
 */

/**
 * @brief Initializes the engine, should be called on the very start of the program,
 * before using the engine.
 * 
 * @retval true success, engine initialized
 * @retval false failed, engine not initialized
 */
bool fsInit(void);

/**
 * @brief Shutdowns the engine, should be called on the end of the program, after using
 * the engine
 */
void fsExit(void);

/** @} */