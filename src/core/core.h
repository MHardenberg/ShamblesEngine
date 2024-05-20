#ifndef core_H
#define DEVEL
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// data  
#include <stdint.h>
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef short f16;
typedef float f32;
typedef double f64;

// graphics
#include <glad/glad.h>
#include <GLFW/glfw3.h>
typedef GLFWwindow window_t;


// defines
typedef i8 exitStatus_t;
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


// constants
#define BASE_WIDTH 1920
#define BASE_HEIGHT 1080


// logging
#ifdef DEVEL
    #include <stdio.h>
    #define LOG_FMT_M(fmt, x) fprintf(stderr, fmt, x)
    #define LOG_M(x) fprintf(stderr, x)
#endif


#endif // !core_H
#define core_H
