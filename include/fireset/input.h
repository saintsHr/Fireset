// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

#include <GLFW/glfw3.h>
#include <stdbool.h>

#include "fireset/window.h"

/** 
 * @defgroup Input Input
 * @brief Keyboard input handling.
 * @{
 */

/**
 * @brief Keyboard key codes.
 *
 * Enumeration of keyboard keys used by the engine.
 * Values map directly to GLFW key codes.
 */
typedef enum{
    FS_KEY_A = GLFW_KEY_A,
    FS_KEY_B = GLFW_KEY_B,
    FS_KEY_C = GLFW_KEY_C,
    FS_KEY_D = GLFW_KEY_D,
    FS_KEY_E = GLFW_KEY_E,
    FS_KEY_F = GLFW_KEY_F,
    FS_KEY_G = GLFW_KEY_G,
    FS_KEY_H = GLFW_KEY_H,
    FS_KEY_I = GLFW_KEY_I,
    FS_KEY_J = GLFW_KEY_J,
    FS_KEY_K = GLFW_KEY_K,
    FS_KEY_L = GLFW_KEY_L,
    FS_KEY_M = GLFW_KEY_M,
    FS_KEY_N = GLFW_KEY_N,
    FS_KEY_O = GLFW_KEY_O,
    FS_KEY_P = GLFW_KEY_P,
    FS_KEY_Q = GLFW_KEY_Q,
    FS_KEY_R = GLFW_KEY_R,
    FS_KEY_S = GLFW_KEY_S,
    FS_KEY_T = GLFW_KEY_T,
    FS_KEY_U = GLFW_KEY_U,
    FS_KEY_V = GLFW_KEY_V,
    FS_KEY_W = GLFW_KEY_W,
    FS_KEY_X = GLFW_KEY_X,
    FS_KEY_Y = GLFW_KEY_Y,
    FS_KEY_Z = GLFW_KEY_Z,

    FS_KEY_0 = GLFW_KEY_0,
    FS_KEY_1 = GLFW_KEY_1,
    FS_KEY_2 = GLFW_KEY_2,
    FS_KEY_3 = GLFW_KEY_3,
    FS_KEY_4 = GLFW_KEY_4,
    FS_KEY_5 = GLFW_KEY_5,
    FS_KEY_6 = GLFW_KEY_6,
    FS_KEY_7 = GLFW_KEY_7,
    FS_KEY_8 = GLFW_KEY_8,
    FS_KEY_9 = GLFW_KEY_9,

    FS_KEY_SPACE         = GLFW_KEY_SPACE,
    FS_KEY_MINUS         = GLFW_KEY_MINUS,
    FS_KEY_EQUAL         = GLFW_KEY_EQUAL,
    FS_KEY_LEFT_BRACKET  = GLFW_KEY_LEFT_BRACKET,
    FS_KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
    FS_KEY_BACKSLASH     = GLFW_KEY_BACKSLASH,
    FS_KEY_SEMICOLON     = GLFW_KEY_SEMICOLON,
    FS_KEY_APOSTROPHE    = GLFW_KEY_APOSTROPHE,
    FS_KEY_COMMA         = GLFW_KEY_COMMA,
    FS_KEY_PERIOD        = GLFW_KEY_PERIOD,
    FS_KEY_SLASH         = GLFW_KEY_SLASH,

    FS_KEY_ESCAPE        = GLFW_KEY_ESCAPE,
    FS_KEY_ENTER         = GLFW_KEY_ENTER,
    FS_KEY_TAB           = GLFW_KEY_TAB,
    FS_KEY_BACKSPACE     = GLFW_KEY_BACKSPACE,
    FS_KEY_LEFT_SHIFT    = GLFW_KEY_LEFT_SHIFT,
    FS_KEY_RIGHT_SHIFT   = GLFW_KEY_RIGHT_SHIFT,
    FS_KEY_LEFT_CONTROL  = GLFW_KEY_LEFT_CONTROL,
    FS_KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
    FS_KEY_LEFT_ALT      = GLFW_KEY_LEFT_ALT,
    FS_KEY_RIGHT_ALT     = GLFW_KEY_RIGHT_ALT,
    FS_KEY_LEFT_SUPER    = GLFW_KEY_LEFT_SUPER,
    FS_KEY_RIGHT_SUPER   = GLFW_KEY_RIGHT_SUPER,
    FS_KEY_MENU          = GLFW_KEY_MENU,

    FS_KEY_UP    = GLFW_KEY_UP,
    FS_KEY_DOWN  = GLFW_KEY_DOWN,
    FS_KEY_LEFT  = GLFW_KEY_LEFT,
    FS_KEY_RIGHT = GLFW_KEY_RIGHT,

    FS_KEY_NUM_LOCK    = GLFW_KEY_NUM_LOCK,
    FS_KEY_KP_0        = GLFW_KEY_KP_0,
    FS_KEY_KP_1        = GLFW_KEY_KP_1,
    FS_KEY_KP_2        = GLFW_KEY_KP_2,
    FS_KEY_KP_3        = GLFW_KEY_KP_3,
    FS_KEY_KP_4        = GLFW_KEY_KP_4,
    FS_KEY_KP_5        = GLFW_KEY_KP_5,
    FS_KEY_KP_6        = GLFW_KEY_KP_6,
    FS_KEY_KP_7        = GLFW_KEY_KP_7,
    FS_KEY_KP_8        = GLFW_KEY_KP_8,
    FS_KEY_KP_9        = GLFW_KEY_KP_9,
    FS_KEY_KP_DECIMAL  = GLFW_KEY_KP_DECIMAL,
    FS_KEY_KP_DIVIDE   = GLFW_KEY_KP_DIVIDE,
    FS_KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
    FS_KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT,
    FS_KEY_KP_ADD      = GLFW_KEY_KP_ADD,
    FS_KEY_KP_ENTER    = GLFW_KEY_KP_ENTER,
    FS_KEY_KP_EQUAL    = GLFW_KEY_KP_EQUAL
} FsKey;

/**
 * @brief Updates the keyboard state.
 *
 * Updates internal key state tracking for the given window.
 *
 * @param window Target window.
 */
void fsUpdateKeyboard(FsWindow* window);

/**
 * @brief Checks if a key was just pressed.
 *
 * Returns true if the key transitioned from released to pressed
 * during the current frame.
 *
 * @param key Key to query.
 *
 * @retval true  Key was just pressed.
 * @retval false Key was not just pressed.
 */
bool fsIsKeyJustPressed(FsKey key);

/**
 * @brief Checks if a key was just released.
 *
 * Returns true if the key transitioned from pressed to released
 * during the current frame.
 *
 * @param key Key to query.
 *
 * @retval true  Key was just released.
 * @retval false Key was not just released.
 */
bool fsIsKeyJustReleased(FsKey key);

/**
 * @brief Checks if a key is currently pressed.
 *
 * @param key Key to query.
 *
 * @retval true  Key is pressed.
 * @retval false Key is not pressed.
 */
bool fsIsKeyDown(FsKey key);

/**
 * @brief Checks if a key is currently released.
 *
 * @param key Key to query.
 *
 * @retval true  Key is released.
 * @retval false Key is not released.
 */
bool fsIsKeyUp(FsKey key);

/** @} */