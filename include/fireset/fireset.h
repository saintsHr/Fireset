// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

#include "fireset/window.h"
#include "fireset/core.h"
#include "fireset/render.h"
#include "fireset/vertex.h"
#include "fireset/fstime.h"
#include "fireset/input.h"

/**
 * \mainpage Fireset
 *
 * ---
 *
 * <div style="float:left; margin-right:20px;">
 *     <img src="logo.png" width="150"/>
 * </div>
 *
 * \section Introduction
 * **Fireset** is a game engine written in **C**.
 *
 * Its main purpose is to make game development more **approachable** while preserving
 * a classic, old-school rendering style.
 *
 * This documentation describes all public functions, types, and structures provided
 * by the engine, as well as practical guides for getting started.
 *
 * ---
 *
 * \section Installing
 *
 * \subsection Debian
 * - Go to the Fireset repository on GitHub.
 * - Open the **Releases** tab and download the latest stable version.
 * - Install the `.deb` package:
 * ```bash
 * sudo apt install ./fireset-dev.deb
 * ```
 * - Compile your project using:
 * ```bash
 * -Ifireset -lfireset -lglfw -lGL -lm
 * ```
 * or, preferably:
 * ```bash
 * $(pkg-config --cflags --libs fireset)
 * ```
 * - Include Fireset in your source files:
 * ```c
 * #include <fireset/fireset.h>
 * ```
 *
 * ---
 *
 * \subsection Manual
 * - Go to the Fireset repository on GitHub.
 * - Open the **Releases** tab and download the latest stable version.
 * - Extract the `.zip` archive.
 * - You should see the **lib** and **include** directories.
 * - Move them to any location of your choice.
 * - Compile your project using:
 * ```bash
 * -Lpath/to/lib -lfireset -lglfw -lGL -lm -Ipath/to/include
 * ```
 * - If you encounter OpenGL or GLFW linker errors, ensure the libraries are installed
 *   and that the appropriate `-L` flags are provided.
 * - Include Fireset in your source files:
 * ```c
 * #include <fireset/fireset.h>
 * ```
 *
 * ---
 *
 * \section Compiling
 * This section is intended for users who want to build the engine manually.
 * This is **not recommended** for regular engine usage.
 *
 * Steps:
 * - Install the dependencies:
 *  - OpenGL (Immediate Mode, version 3.3 or lower)
 *  - GLFW
 * - Download the source code from the Fireset GitHub repository.
 * - Extract the archive.
 * - Open a terminal in the project root directory.
 * - To build a debug version:
 * ```bash
 * make
 * ```
 * - To build a release version:
 * ```bash
 * make release
 * ```
 * - To generate the documentation:
 * ```bash
 * make doc
 * ```
 * - To manually install:
 * ```bash
 * make install
 * ```
 * Note: if pkg-config cannot find this, ensure `/usr/local/pkgconfig` is present in `PKG_CONFIG_PATH` environment variable.
 * - To uninstall what was installed with `make install`:
 * ```bash
 * make uninstall
 * ```
 * - To generate the `.deb` package:
 * ```bash
 * make deb
 * ```
 * - To clean build artifacts:
 * ```bash
 * make clean
 * ```
 *
 * After compilation, the following directories will be created:
 * - **bin**: test executables
 * - **build**: object (`.o`) and dependency (`.d`) files
 * - **lib**: compiled static library (`.a`)
 *
 * ---
 *
 * \section Quickstart
 * This example demonstrates the minimum setup required to create a window
 * and run a basic application loop using Fireset.
 *
 * ```c
 * #include <fireset/fireset.h>
 *
 * int main(void){
 *     if (!fsInit()) return 1;
 *
 *     FsWindow window;
 *     window.width = 800;
 *     window.height = 600;
 *     window.name = "Example Game";
 *     fsCreateWindow(&window);
 *
 *     while (!fsWindowShouldClose(window)){
 *         fsClear((FsColor){0, 0, 0});
 *
 *         // rendering code
 *
 *         fsHandleWindow(&window);
 *     }
 *
 *     fsDestroyWindow(&window);
 *     fsExit();
 *     return 0;
 * }
 * ```
 *
 * This program:
 * - Initializes the engine
 * - Creates a window
 * - Runs a main loop until the window is closed
 * - Shuts down the engine
 *
 * Relevant modules:
 * - \ref Core
 * - \ref Window
 *
 * ---
 */
