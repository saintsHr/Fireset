// Copyright (c) 2025 Henrique Rodrigues Santos
// Licensed under the MIT License
// Repo: https://github.com/saintsHr/Fireset

#include "fireset/physics.h"
#include "settings.h"

static void clampBodyVelocity(cpBody* body, void* data){
    cpFloat* limits = (cpFloat*)data;
    cpFloat maxVel = limits[0];
    cpFloat maxAngular = limits[1];

    cpVect v = cpBodyGetVelocity(body);
    cpFloat speed = cpvlength(v);
    if(speed > maxVel){
        cpVect clamped = cpvmult(v, maxVel / speed);
        cpBodySetVelocity(body, clamped);
    }

    cpFloat angVel = cpBodyGetAngularVelocity(body);
    if(fabs(angVel) > maxAngular){
        cpBodySetAngularVelocity(body, (angVel > 0 ? maxAngular : -maxAngular));
    }
}

static void clampVelocities(cpSpace* space){
    cpFloat limits[2] = { PHYS_MAX_VELOCITY, PHYS_MAX_ANGULAR };
    cpSpaceEachBody(space, clampBodyVelocity, limits);
}

FsSpace fsSpaceCreate(FsVec2 gravity){
    FsSpace space;
    space.raw = cpSpaceNew();
    cpSpaceSetGravity(space.raw, cpv(gravity.x, gravity.y));
    return space;
}

FsBody fsBodyCreate(FsBodyType type, FsSpace* space){
    FsBody body = {0};
    body.type = type;

    switch (type){
        case FS_BODY_STATIC:
            body.raw = cpSpaceGetStaticBody(space->raw);
            break;
        case FS_BODY_KINEMATIC:
            body.raw = cpBodyNewKinematic();
            break;
        case FS_BODY_DYNAMIC:
            body.raw = cpBodyNew(1.0f, 1.0f);
            break;
        default:
            break;
    }

    return body;
}

FsShape fsShapeCreate(FsBody* body, const FsShapeDesc* desc){
    FsShape shape = {0};

    switch (desc->type){
    case FS_SHAPE_BOX:
        shape.type = FS_SHAPE_BOX;
        shape.raw = cpBoxShapeNew(
            body->raw,
            desc->box.width,
            desc->box.height,
            desc->box.radius
        );
        break;
    case FS_SHAPE_CIRCLE:
        shape.type = FS_SHAPE_CIRCLE;
        shape.raw = cpCircleShapeNew(
            body->raw,
            desc->circle.radius,
            desc->circle.offset
        );
        break;
    case FS_SHAPE_LINE:
        shape.type = FS_SHAPE_LINE;
        shape.raw = cpSegmentShapeNew(
            body->raw,
            desc->segment.a,
            desc->segment.b,
            desc->segment.radius
        );
        break;
    default:
        break;
    }

    return shape;
}

void fsSpaceAddShape(FsSpace* space, FsShape* shape){
    cpSpaceAddShape(space->raw, shape->raw);
}

void fsSpaceAddBody(FsSpace* space, FsBody* body){
    cpSpaceAddBody(space->raw, body->raw);
}

void fsShapeSetFriction(FsShape* shape, float friction){
    cpShapeSetFriction(shape->raw, friction);
}

void fsBodySetMass(FsBody* body, float mass){
    cpBodySetMass(body->raw, mass);
}

void fsBodySetMoment(FsBody* body, float moment){
    cpBodySetMoment(body->raw, moment);
}

void fsBodySetPosition(FsBody* body, FsVec2 position){
    cpBodySetPosition(body->raw, cpv(position.x, position.y));
}

void fsSpaceStep(FsSpace* space){
    cpFloat subdt = PHYS_DT / PHYS_SUBSTEPS;
    for(int i = 0; i < PHYS_SUBSTEPS; i++){
        cpSpaceStep(space->raw, subdt);
        clampVelocities(space->raw);
    }
}

FsVec2 fsBodyGetPosition(FsBody* body){
    cpVect cpvec = cpBodyGetPosition(body->raw);
    FsVec2 vec = FsVec2_new(cpvec.x, cpvec.y);
    return vec;
}

float fsBodyGetAngle(FsBody* body){
    return cpBodyGetAngle(body->raw) * (180.0f / PI);
}

FsShape fsShapeBoxCreate(FsBody* body, float width, float height, float radius){
    FsShapeDesc desc = {
        .type = FS_SHAPE_BOX,
        .box = {
            .width = width,
            .height = height,
            .radius = radius
        }
    };
    FsShape shape = fsShapeCreate(
        body,
        &desc
    );
    return shape;
}

float fsMomentForBox(mass, width, height){
    return cpMomentForBox(mass, width, height);
}