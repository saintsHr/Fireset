#pragma once

/** 
 * @defgroup Time
 * @{
 */

/**
 * @brief Gets time.
 * 
 * Gets the real system time on the function call.
*/
double fsGetSystemTime(void);

/**
 * @brief Gets delta time.
 * 
 * Gets the delta time on the function call.
*/
double fsGetDeltaTime(void);

/**
 * @brief Inits time module.
 * 
 * Initializes the time module of the engine.
*/
void fsTimeInit(void);

/** @} */