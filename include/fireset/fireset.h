#pragma once

#include "fireset/window.h"
#include "fireset/core.h"
#include "fireset/render.h"
#include "fireset/vertex.h"

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
 * To install Fireset Engine, you can follow this step-by-step guide:
 * - go to https://github.com/saintsHr/Fireset
 * - go to Releases tab and install the latest stable release
 * - extract your .zip
 * - now you should see the folder **lib** and also **include**
 * - move those to any place you like
 * - now use those flags in your compilation:
 * ```bash
 * -Lpath/to/lib/folder -lfireset -ipath/to/include/folder
 * ```
 * - and this line in your source files:
 * ```c
 * #include <fireset/fireset.h>
 * ```
 * - done, now you're ready to go!
 * 
 * ---
 * 
 * 
 */