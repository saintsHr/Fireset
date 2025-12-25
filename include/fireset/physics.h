// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#pragma once

#include <chipmunk/chipmunk.h>

#include "fireset/vertex.h"
#include "fireset/window.h"

typedef enum{
    FS_BODY_STATIC,
    FS_BODY_KINEMATIC,
    FS_BODY_DYNAMIC
}FsBodyType;

typedef enum{
    FS_SHAPE_CIRCLE,
    FS_SHAPE_BOX,
    FS_SHAPE_LINE
}FsShapeType;

typedef struct{
    cpSpace* raw;
    FsVec2 gravity;
}FsSpace;

typedef struct{
    cpBody* raw;
    FsBodyType type;
}FsBody;

typedef struct{
    FsShapeType type;
    union{
        struct{
            float radius;
            cpVect offset;
        }circle;

        struct{
            cpVect a, b;
            float radius;
        }segment;

        struct{
            float width, height;
            float radius;
        }box;
    };
}FsShapeDesc;

typedef struct{
    cpShape* raw;
    FsShapeType type;
}FsShape;

FsSpace fsSpaceCreate(FsVec2 gravity);
void fsSpaceStep(FsSpace* space);
void fsSpaceAddShape(FsSpace* space, FsShape* shape);
void fsSpaceAddBody(FsSpace* space, FsBody* body);

void fsShapeSetFriction(FsShape* shape, float friction);
FsShape fsShapeCreate(FsBody* body, const FsShapeDesc* desc);
FsShape fsShapeBoxCreate(FsBody* body, float width, float height, float radius);

FsBody fsBodyCreate(FsBodyType type, FsSpace* space);
void fsBodySetMoment(FsBody* body, float moment);
void fsBodySetMass(FsBody* body, float mass);
void fsBodySetPosition(FsBody* body, FsVec2 position);
FsVec2 fsBodyGetPosition(FsBody* body);
float fsBodyGetAngle(FsBody* body);

float fsMomentForBox(mass, width, height);