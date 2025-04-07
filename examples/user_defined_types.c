#include <stdio.h>

typedef struct {
    float x;
    float y;
} Vec2;

void gprint_vec2(FILE *f, Vec2 v) {
    fprintf(f, "(%g, %g)", v.x, v.y);
}

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

void gprint_vec3(FILE *f, Vec3 v) {
    fprintf(f, "(%g, %g, %g)", v.x, v.y, v.z);
}

// Define custom print functions before loading gprint.h
//
// NOTE: DO NOT use comma/semicolon(s) to separate the items of this list.
//       Just write the entries one after the other.
//
#define GPRINT_TABLE_CUSTOM                                                                        \
    GPRINT_FUNC(Vec2, gprint_vec2)                                                                 \
    GPRINT_FUNC(Vec3, gprint_vec3)

#define GPRINT_IMPLEMENTATION
#include "gprint.h"

int main(void) {
    const Vec2 a = {
        .x = 69,
        .y = 420,
    };
    print("a = ", a, "\n");

    const Vec3 b = {
        .x = 69,
        .y = 420,
        .z = 1337,
    };
    print("b = ", b, "\n");
}
