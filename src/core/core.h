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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#ifndef __FUNCTION_NAME__
    #ifdef WIN32   //WINDOWS
        #define __FUNCTION_NAME__   __FUNCTION__  
    #else          //*NIX
        #define __FUNCTION_NAME__   __func__ 
    #endif
#endif


// constants
#define BASE_WIDTH 1920
#define BASE_HEIGHT 1080


// logging
#ifdef DEVEL
    #include <stdio.h>
    #include <unistd.h>
    #define LOG_FUNCTION \
    char cwd[1024];\
    if (getcwd(cwd, sizeof(cwd))){fprintf(stderr, "Current working dir: %s\n", cwd);}\
    fprintf(stderr, "%s %s %s", ANSI_COLOR_RED, __FUNCTION_NAME__, ANSI_COLOR_RESET);

    #define LOG_FMT_M(fmt, x) LOG_FUNCTION; fprintf(stderr, fmt, x)
    #define LOG_M(x) LOG_FUNCTION; fprintf(stderr, "%s\n", x)
#endif


#endif // !core_H
#define core_H
