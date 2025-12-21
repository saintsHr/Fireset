#pragma once

#include <chipmunk/chipmunk.h>

#include "fireset/vertex.h"

typedef struct{
    cpSpace* raw;
    FsVec2 gravity;
}FsSpace;

FsSpace fsCreateSpace(FsVec2 gravity);