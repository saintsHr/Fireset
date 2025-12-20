// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

#include "fireset/window.h"

#include <GLFW/glfw3.h>
#include <stdbool.h>

/** 
 * @defgroup Core Core
 * @brief Engine core lifecycle functions.
 * @{
 */

/**
 * @brief Initializes the Fireset engine core.
 *
 * This function must be called exactly once, at the very beginning of the program,
 * before calling any other Fireset API function.
 *
 * It initializes internal engine state and third-party dependencies
 * such as the windowing system.
 *
 * @retval true  Engine initialized successfully.
 * @retval false Initialization failed. No other Fireset function is safe to call.
 *
 * @note Calling this function more than once results in undefined behavior.
 */
bool fsInit(void);

/**
 * @brief Shuts down the Fireset engine core.
 *
 * Releases all internal resources and shuts down third-party systems
 * initialized by fsInit().
 *
 * This function should be called once, at the very end of the program,
 * after all engine usage has finished.
 *
 * @note After calling this function, no Fireset API function is valid.
 */
void fsExit(void);

/** @} */