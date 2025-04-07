# gprint.h
Generic Variadic Print in C.

## Quick Start
Just copy [gprint.h](gprint.h) into your project and include it like this:

```c
#define GPRINT_IMPLEMENTATION
#include "gprint.h"
```

## Usage
### `print(...)`
Print the arguments into standard output.

```c
// print.c

#define GPRINT_IMPLEMENTATION
#include "gprint.h"

int main(void) {
    print(69, " and ", 420, ". Nice!\n");
}
```

```console
$ cc -o print print.c
$ ./print
69 and 420. Nice!
```

### `eprint(...)`
Print the arguments into standard error.

### `fprint(FILE *stream, ...)`
Print the arguments into `stream`.

**NOTE:** The argument `stream` will be evaluated multiple times.

### `GPRINT_TABLE_CUSTOM`
Implement print functions for custom types.

```c
// custom.c

#include <stdio.h>

typedef struct {
    float x;
    float y;
} Vec2;

void file_print_vec2(FILE *f, Vec2 v) {
    fprintf(f, "(%g, %g)", v.x, v.y);
}

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

void file_print_vec3(FILE *f, Vec3 v) {
    fprintf(f, "(%g, %g, %g)", v.x, v.y, v.z);
}

// Define custom print functions before loading gprint.h
//
// NOTE: DO NOT use comma/semicolon(s) to separate the items of this list.
//       Just write the entries one after the other.
//
#define GPRINT_TABLE_CUSTOM                                                    \
    GPRINT_FUNC(Vec2, file_print_vec2)                                         \
    GPRINT_FUNC(Vec3, file_print_vec3)

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
```

```console
$ cc -o custom custom.c
$ ./custom
a = (69, 420)
b = (69, 420, 1337)
```

## Examples
See the examples in the [examples/](examples/) folder.

```console
$ cd examples
$ make
$ ./simple
69 and 420. Nice!
Floats work as well: 13.37
$ ./user_defined_types
a = (69, 420)
b = (69, 420, 1337)
```

## Notes
- [STB](https://github.com/nothings/stb)
- [Header only Libraries](https://github.com/nothings/stb/blob/master/docs/stb_howto.txt)
