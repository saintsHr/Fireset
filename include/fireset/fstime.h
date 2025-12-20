// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

/** 
 * @defgroup Time Time
 * @brief Time-related functions.
 * @{
 */

/**
 * @brief Returns the current system time.
 *
 * Returns the current system time at the moment this function is called.
 *
 * @return Current system time.
 */
double fsGetSystemTime(void);

/**
 * @brief Returns the delta time.
 *
 * Returns the time difference between the current frame and the previous one.
 *
 * @return Delta time.
 */
double fsGetDeltaTime(void);

/**
 * @brief Initializes the time module.
 *
 * Initializes the internal time tracking used by the engine.
 *
 * This function must be called before using any other time-related function.
 */
void fsTimeInit(void);

/** @} */