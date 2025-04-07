#ifndef GPRINT_H
#define GPRINT_H

#include <stdio.h>

// clang-format off
#define GPRINT_FUNC(T, f) T: f,
#define GPRINT_LAST(T, f) T: f
// clang-format on

#ifndef GPRINT_TABLE_CUSTOM
#    define GPRINT_TABLE_CUSTOM
#endif // GPRINT_TABLE_CUSTOM

#define GPRINT_TABLE                                                                               \
    GPRINT_TABLE_CUSTOM                                                                            \
    GPRINT_FUNC(char, gprint_char)                                                                 \
    GPRINT_FUNC(short, gprint_short)                                                               \
    GPRINT_FUNC(unsigned short, gprint_unsigned_short)                                             \
    GPRINT_FUNC(int, gprint_int)                                                                   \
    GPRINT_FUNC(unsigned int, gprint_unsigned_int)                                                 \
    GPRINT_FUNC(long, gprint_long)                                                                 \
    GPRINT_FUNC(unsigned long, gprint_unsigned_long)                                               \
    GPRINT_FUNC(float, gprint_float)                                                               \
    GPRINT_FUNC(double, gprint_float)                                                              \
    GPRINT_FUNC(char *, gprint_cstr)                                                               \
    GPRINT_FUNC(const char *, gprint_cstr)                                                         \
    GPRINT_FUNC(void *, gprint_pointer)                                                            \
    GPRINT_LAST(const void *, gprint_pointer)

// Modified from https://github.com/swansontec/map-macro
#define GPRINT_EVAL0(...) __VA_ARGS__
#define GPRINT_EVAL1(...) GPRINT_EVAL0(GPRINT_EVAL0(GPRINT_EVAL0(__VA_ARGS__)))
#define GPRINT_EVAL2(...) GPRINT_EVAL1(GPRINT_EVAL1(GPRINT_EVAL1(__VA_ARGS__)))
#define GPRINT_EVAL3(...) GPRINT_EVAL2(GPRINT_EVAL2(GPRINT_EVAL2(__VA_ARGS__)))
#define GPRINT_EVAL4(...) GPRINT_EVAL3(GPRINT_EVAL3(GPRINT_EVAL3(__VA_ARGS__)))
#define GPRINT_EVAL(...)  GPRINT_EVAL4(GPRINT_EVAL4(GPRINT_EVAL4(__VA_ARGS__)))

#define GPRINT_END(...)
#define GPRINT_OUT
#define GPRINT_COMMA ,

#define GPRINT_GET_END2()             0, GPRINT_END
#define GPRINT_GET_END1(...)          GPRINT_GET_END2
#define GPRINT_GET_END(...)           GPRINT_GET_END1
#define GPRINT_NEXT0(test, next, ...) next GPRINT_OUT

#define GPRINT_LIST_NEXT1(test, next) GPRINT_NEXT0(test, GPRINT_COMMA next, 0)
#define GPRINT_LIST_NEXT(test, next)  GPRINT_LIST_NEXT1(GPRINT_GET_END test, next)

#define GPRINT_LIST0(a, x, peek, ...)                                                              \
    _Generic((x), GPRINT_TABLE)(a, x) GPRINT_LIST_NEXT(peek, GPRINT_LIST1)(a, peek, __VA_ARGS__)

#define GPRINT_LIST1(a, x, peek, ...)                                                              \
    _Generic((x), GPRINT_TABLE)(a, x) GPRINT_LIST_NEXT(peek, GPRINT_LIST0)(a, peek, __VA_ARGS__)

#define fprint(f, ...)   GPRINT_EVAL(GPRINT_LIST1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))
#define fprintln(f, ...) fprint(f, __VA_ARGS__, (char) '\n')

#define eprint(...)   fprint(stderr, __VA_ARGS__)
#define eprintln(...) eprint(__VA_ARGS__, (char) '\n')

#define print(...)   fprint(stdout, __VA_ARGS__)
#define println(...) print(__VA_ARGS__, (char) '\n')

void gprint_char(FILE *f, char x);
void gprint_short(FILE *f, short x);
void gprint_unsigned_short(FILE *f, unsigned short x);
void gprint_int(FILE *f, int x);
void gprint_unsigned_int(FILE *f, unsigned int x);
void gprint_long(FILE *f, long x);
void gprint_unsigned_long(FILE *f, unsigned long x);
void gprint_float(FILE *f, double x);
void gprint_cstr(FILE *f, const char *s);
void gprint_pointer(FILE *f, const void *p);

#endif // GPRINT_H

#ifdef GPRINT_IMPLEMENTATION

void gprint_char(FILE *f, char x) {
    fprintf(f, "%c", x);
}

void gprint_short(FILE *f, short x) {
    fprintf(f, "%d", x);
}

void gprint_unsigned_short(FILE *f, unsigned short x) {
    fprintf(f, "%u", x);
}

void gprint_int(FILE *f, int x) {
    fprintf(f, "%d", x);
}

void gprint_unsigned_int(FILE *f, unsigned int x) {
    fprintf(f, "%u", x);
}

void gprint_long(FILE *f, long x) {
    fprintf(f, "%ld", x);
}

void gprint_unsigned_long(FILE *f, unsigned long x) {
    fprintf(f, "%lu", x);
}

void gprint_float(FILE *f, double x) {
    fprintf(f, "%g", x);
}

void gprint_cstr(FILE *f, const char *s) {
    fprintf(f, "%s", s);
}

void gprint_pointer(FILE *f, const void *p) {
    fprintf(f, "%p", p);
}

#endif // GPRINT_IMPLEMENTATION
