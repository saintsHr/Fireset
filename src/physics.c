#include "fireset/physics.h"

FsSpace fsCreateSpace(FsVec2 gravity){
    FsSpace space;
    space.raw = cpSpaceNew();
    cpSpaceSetGravity(space.raw, cpv(gravity.x, gravity.y));
    return space;
}