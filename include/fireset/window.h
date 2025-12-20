#pragma once

#include <GLFW/glfw3.h>
#include <stdbool.h>

/** 
 * @defgroup Window Window
 * @brief Window management functions and types.
 * @{
 */

/**
 * @brief Window object.
 *
 * Represents a window and its associated backend handle.
 */
typedef struct{
    GLFWwindow* handle; /**< Backend window handle. */
    int width;          /**< Width of the window in pixels. */
    int height;         /**< Height of the window in pixels. */
    char* name;         /**< Window title. */
} FsWindow;

/**
 * @brief Creates a window.
 *
 * Initializes a window using the provided data.
 *
 * @param window Pointer to a FsWindow struct containing the desired parameters.
 * @return Pointer to the created window (same as input).
 */
FsWindow* fsCreateWindow(FsWindow* window);

/**
 * @brief Updates a window.
 *
 * Processes events and updates the internal state of the window.
 *
 * @param window Window to update.
 */
void fsHandleWindow(FsWindow* window);

/**
 * @brief Destroys a window.
 *
 * Closes the window and releases its resources.
 *
 * @param window Window to destroy.
 */
void fsDestroyWindow(FsWindow* window);

/**
 * @brief Checks if a window should close.
 *
 * Queries the window to determine if a close request has been issued.
 *
 * @param window Window to check.
 * @return true if the window should close, false otherwise.
 */
bool fsWindowShouldClose(FsWindow* window);

/** @} */