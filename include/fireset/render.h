#pragma once

#include <GL/gl.h>
#include "fireset/vertex.h"

void fsDrawTriangle(const FsVec2f* vertices);
void fsDrawQuad(const FsVec2f* vertices);
void fsClear(int red, int green, int blue);