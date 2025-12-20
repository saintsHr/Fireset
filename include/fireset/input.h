// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

#include <GLFW/glfw3.h>
#include <stdbool.h>

#include "fireset/window.h"
#include "fireset/vertex.h"

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
typedef enum {
    FS_KEY_A = GLFW_KEY_A, /**< Key A */
    FS_KEY_B = GLFW_KEY_B, /**< Key B */
    FS_KEY_C = GLFW_KEY_C, /**< Key C */
    FS_KEY_D = GLFW_KEY_D, /**< Key D */
    FS_KEY_E = GLFW_KEY_E, /**< Key E */
    FS_KEY_F = GLFW_KEY_F, /**< Key F */
    FS_KEY_G = GLFW_KEY_G, /**< Key G */
    FS_KEY_H = GLFW_KEY_H, /**< Key H */
    FS_KEY_I = GLFW_KEY_I, /**< Key I */
    FS_KEY_J = GLFW_KEY_J, /**< Key J */
    FS_KEY_K = GLFW_KEY_K, /**< Key K */
    FS_KEY_L = GLFW_KEY_L, /**< Key L */
    FS_KEY_M = GLFW_KEY_M, /**< Key M */
    FS_KEY_N = GLFW_KEY_N, /**< Key N */
    FS_KEY_O = GLFW_KEY_O, /**< Key O */
    FS_KEY_P = GLFW_KEY_P, /**< Key P */
    FS_KEY_Q = GLFW_KEY_Q, /**< Key Q */
    FS_KEY_R = GLFW_KEY_R, /**< Key R */
    FS_KEY_S = GLFW_KEY_S, /**< Key S */
    FS_KEY_T = GLFW_KEY_T, /**< Key T */
    FS_KEY_U = GLFW_KEY_U, /**< Key U */
    FS_KEY_V = GLFW_KEY_V, /**< Key V */
    FS_KEY_W = GLFW_KEY_W, /**< Key W */
    FS_KEY_X = GLFW_KEY_X, /**< Key X */
    FS_KEY_Y = GLFW_KEY_Y, /**< Key Y */
    FS_KEY_Z = GLFW_KEY_Z, /**< Key Z */

    FS_KEY_0 = GLFW_KEY_0, /**< Key 0 */
    FS_KEY_1 = GLFW_KEY_1, /**< Key 1 */
    FS_KEY_2 = GLFW_KEY_2, /**< Key 2 */
    FS_KEY_3 = GLFW_KEY_3, /**< Key 3 */
    FS_KEY_4 = GLFW_KEY_4, /**< Key 4 */
    FS_KEY_5 = GLFW_KEY_5, /**< Key 5 */
    FS_KEY_6 = GLFW_KEY_6, /**< Key 6 */
    FS_KEY_7 = GLFW_KEY_7, /**< Key 7 */
    FS_KEY_8 = GLFW_KEY_8, /**< Key 8 */
    FS_KEY_9 = GLFW_KEY_9, /**< Key 9 */

    FS_KEY_SPACE         = GLFW_KEY_SPACE,         /**< Space key */
    FS_KEY_MINUS         = GLFW_KEY_MINUS,         /**< Minus (-) key */
    FS_KEY_EQUAL         = GLFW_KEY_EQUAL,         /**< Equal (=) key */
    FS_KEY_LEFT_BRACKET  = GLFW_KEY_LEFT_BRACKET,  /**< Left bracket ([) key */
    FS_KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET, /**< Right bracket (]) key */
    FS_KEY_BACKSLASH     = GLFW_KEY_BACKSLASH,     /**< Backslash (\) key */
    FS_KEY_SEMICOLON     = GLFW_KEY_SEMICOLON,     /**< Semicolon (;) key */
    FS_KEY_APOSTROPHE    = GLFW_KEY_APOSTROPHE,    /**< Apostrophe (') key */
    FS_KEY_COMMA         = GLFW_KEY_COMMA,         /**< Comma (,) key */
    FS_KEY_PERIOD        = GLFW_KEY_PERIOD,        /**< Period (.) key */
    FS_KEY_SLASH         = GLFW_KEY_SLASH,         /**< Slash (/) key */

    FS_KEY_ESCAPE        = GLFW_KEY_ESCAPE,        /**< Escape key */
    FS_KEY_ENTER         = GLFW_KEY_ENTER,         /**< Enter key */
    FS_KEY_TAB           = GLFW_KEY_TAB,           /**< Tab key */
    FS_KEY_BACKSPACE     = GLFW_KEY_BACKSPACE,     /**< Backspace key */
    FS_KEY_LEFT_SHIFT    = GLFW_KEY_LEFT_SHIFT,    /**< Left Shift key */
    FS_KEY_RIGHT_SHIFT   = GLFW_KEY_RIGHT_SHIFT,   /**< Right Shift key */
    FS_KEY_LEFT_CONTROL  = GLFW_KEY_LEFT_CONTROL,  /**< Left Control key */
    FS_KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL, /**< Right Control key */
    FS_KEY_LEFT_ALT      = GLFW_KEY_LEFT_ALT,      /**< Left Alt key */
    FS_KEY_RIGHT_ALT     = GLFW_KEY_RIGHT_ALT,     /**< Right Alt key */
    FS_KEY_LEFT_SUPER    = GLFW_KEY_LEFT_SUPER,    /**< Left Super (Windows/Command) key */
    FS_KEY_RIGHT_SUPER   = GLFW_KEY_RIGHT_SUPER,   /**< Right Super (Windows/Command) key */
    FS_KEY_MENU          = GLFW_KEY_MENU,          /**< Menu key */

    FS_KEY_UP    = GLFW_KEY_UP,    /**< Up arrow key */
    FS_KEY_DOWN  = GLFW_KEY_DOWN,  /**< Down arrow key */
    FS_KEY_LEFT  = GLFW_KEY_LEFT,  /**< Left arrow key */
    FS_KEY_RIGHT = GLFW_KEY_RIGHT, /**< Right arrow key */

    FS_KEY_NUM_LOCK    = GLFW_KEY_NUM_LOCK,    /**< Num Lock key */
    FS_KEY_KP_0        = GLFW_KEY_KP_0,        /**< Keypad 0 */
    FS_KEY_KP_1        = GLFW_KEY_KP_1,        /**< Keypad 1 */
    FS_KEY_KP_2        = GLFW_KEY_KP_2,        /**< Keypad 2 */
    FS_KEY_KP_3        = GLFW_KEY_KP_3,        /**< Keypad 3 */
    FS_KEY_KP_4        = GLFW_KEY_KP_4,        /**< Keypad 4 */
    FS_KEY_KP_5        = GLFW_KEY_KP_5,        /**< Keypad 5 */
    FS_KEY_KP_6        = GLFW_KEY_KP_6,        /**< Keypad 6 */
    FS_KEY_KP_7        = GLFW_KEY_KP_7,        /**< Keypad 7 */
    FS_KEY_KP_8        = GLFW_KEY_KP_8,        /**< Keypad 8 */
    FS_KEY_KP_9        = GLFW_KEY_KP_9,        /**< Keypad 9 */
    FS_KEY_KP_DECIMAL  = GLFW_KEY_KP_DECIMAL,  /**< Keypad decimal (.) */
    FS_KEY_KP_DIVIDE   = GLFW_KEY_KP_DIVIDE,   /**< Keypad divide (/) */
    FS_KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY, /**< Keypad multiply (*) */
    FS_KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT, /**< Keypad subtract (-) */
    FS_KEY_KP_ADD      = GLFW_KEY_KP_ADD,      /**< Keypad add (+) */
    FS_KEY_KP_ENTER    = GLFW_KEY_KP_ENTER,    /**< Keypad enter */
    FS_KEY_KP_EQUAL    = GLFW_KEY_KP_EQUAL     /**< Keypad equal (=) */
} FsKey;

/**
 * @brief Mouse buttons enumeration.
 *
 * Defines mouse buttons used by the engine. Values map directly
 * to GLFW mouse button codes.
 */
typedef enum {
    FS_LMB = GLFW_MOUSE_BUTTON_LEFT,    /**< Left mouse button */
    FS_RMB = GLFW_MOUSE_BUTTON_RIGHT,   /**< Right mouse button */
    FS_MMB = GLFW_MOUSE_BUTTON_MIDDLE   /**< Middle mouse button */
} FsMouseButton;

/**
 * @brief Updates the input state.
 *
 * Updates internal input state tracking for the given window.
 *
 * @param window Target window.
 */
void fsUpdateInput(FsWindow* window);

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
 * @brief Gets the current cursor position.
 *
 * Returns the position of the cursor relative to the top-left corner
 * of the specified window.
 *
 * @param window Pointer to the window to query.
 * @return FsVec2 representing the cursor position in pixels.
 */
FsVec2 fsGetCursorPos(const FsWindow* window);

/**
 * @brief Checks if a specific mouse button is currently pressed.
 *
 * Returns true if the specified mouse button is being pressed
 * for the given window.
 *
 * @param window Pointer to the window to query.
 * @param bt Mouse button to check (FS_LMB, FS_RMB, FS_MMB).
 * @return true if the button is pressed, false otherwise.
 */
bool fsIsMouseButtonDown(const FsWindow* window, FsMouseButton bt);

/**
 * @brief Checks if a mouse button was just pressed.
 *
 * Returns true if the specified mouse button transitioned from released
 * to pressed in the current frame.
 *
 * @param window Pointer to the window to query.
 * @param bt Mouse button to check (FS_LMB, FS_RMB, FS_MMB).
 * @return true if the button was just pressed, false otherwise.
 */
bool fsMouseButtonJustPressed(const FsWindow* window, FsMouseButton bt);

/**
 * @brief Checks if a mouse button was just released.
 *
 * Returns true if the specified mouse button transitioned from pressed
 * to released in the current frame.
 *
 * @param window Pointer to the window to query.
 * @param bt Mouse button to check (FS_LMB, FS_RMB, FS_MMB).
 * @return true if the button was just released, false otherwise.
 */
bool fsMouseButtonJustReleased(const FsWindow* window, FsMouseButton bt);

/** @} */