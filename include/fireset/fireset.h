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
 *     <img src="logo.png" width="130"/>
 * </div>
 * 
 * \section Introduction
 * **Fireset** is a game engine written in **C**, its main propouse is to make game \n
 * development more **enjoyable** and **easy**, and also give your games that old feel \n
 * we all love, in this documentation you have all functions, types and structs \n
 * documented **in detail** and as well some **step by step** guides!
 * 
 * ---
 * 
 * \section Installing
 * ### Debian:
 * - go to https://github.com/saintsHr/Fireset
 * - go to Releases tab and install the latest stable release
 * - install your .deb:
 * ```bash
 * sudo apt install ./fireset-dev.deb
 * ```
 * - now use those flags in your compilation:
 * ```bash
 * -Ifireset -lfireset -lglfw -lGL -lm
 * ```
 * or:
 * ```bash
 * $(pkg-config --cflags --libs fireset)
 * ```
 * - and this line in your source files:
 * ```c
 * #include <fireset/fireset.h>
 * ```
 * - done, now you're ready to go!
 * 
 * ### Manual:
 * - go to https://github.com/saintsHr/Fireset
 * - go to Releases tab and install the latest stable release
 * - extract your .zip
 * - now you should see the folder **lib** and also **include**
 * - move those to any place you like
 * - now use those flags in your compilation:
 * ```bash
 * -Lpath/to/lib/folder -lfireset -lglfw -lGL -lm -Ipath/to/include/folder
 * ```
 * - if you get any linking errors related to OpenGL or GLFW, make sure you
 * have it installed and also add a "-L" flag for those
 * - and this line in your source files:
 * ```c
 * #include <fireset/fireset.h>
 * ```
 * - done, now you're ready to go!
 * 
 * ---
 * 
 * \section Compiling
 * This guide is for those who want to compile the engine by hand,
 * we do not recommend \n doing this for normal usage, anyways, heres the
 * step-by-step guide:
 * - Install the dependencies:
 *  - OpenGL Immediate Mode (3.3 or less)
 *  - GLFW
 * - Go to https://github.com/saintsHr/Fireset
 * - Press de "Code" button
 * - Click "Download ZIP"
 * - Extract it
 * - Now you should see some folders, like:
 *  - **src**, source files (.c)
 *  - **include**, header files (.h)
 *  - etc.
 * - Open your terminal in that folder
 * - for a debug version, run:
 * ```bash
 * make
 * ```
 * - for a release version, run:
 * ```bash
 * make release
 * ```
 * - to compile the docs, run:
 * ```bash
 * make doc
 * ```
 * - to compile the .deb, run:
 * ```bash
 * make deb
 * ```
 * - to remove build files, run:
 * ```bash
 * make clean
 * ```
 * - now you should see 3 extra folders: \n
 *  - **bin**: contains the test executable \n
 *  - **build**: contains the object (.o) and dependencies files (.d) \n
 *  - **lib**: contains the compiled engine (.a)
 * - done, you have compiled the engine!
 * 
 * ---
 * 
 * \section Quickstart
 * This guide is for those who want to have a window as fast as possible, \n
 * or for those who want to take a quick look on the API ,so heres a simple example:
 * 
 * ```c
 *  #include <fireset/fireset.h>
 *
 *  int main(void){
 *      // inits engine
 *      if (!fsInit()) return 1;
 * 
 *      // creates window
 *      FsWindow window;
 *      window.width = 800;
 *      window.height = 600;
 *      window.name = "Example Game";
 *      fsCreateWindow(&window);
 * 
 *      // main loop
 *      while (!fsWindowShouldClose(window)){
 *          fsClear((FsColor){0, 0, 0});
 * 
 *          // render here
 * 
 *          fsHandleWindow(&window);
 *      }
 * 
 *      // destroy window and closes engine
 *      fsDestroyWindow(&window);
 *      fsExit();
 *      return 0;
 *  }
 * ```
 * This code:
 * - opens a window
 * - loops until you close it
 * - then shutdowns the engine
 * 
 * The engine can do much more than it, so take a time to explore it!
 * 
 * Used modules:
 * - \ref Core
 * - \ref Window 
 * 
 * ---
 */