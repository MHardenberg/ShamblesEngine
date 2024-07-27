#ifndef SHAM_SHADERS_H
#define SHAM_SHADERS_H

#include "utils/io.h"
#include <core.h>
#include <utils.h>
#include <coreGraphics/ui.h>

#define vertexShaderPath "../shaders/vertexShader"
#define fragmentShaderPath "../shaders/fragmentShader"


static inline exitStatus_t vertexShader_compile_ (u32 *vertexShader,
        char *infoLog, size_t bufferLen) {

    if (vertexShader == NULL) {return EXIT_FAILURE;}
    const char *vertexShaderSource = CORE_readFile(vertexShaderPath);

    *vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(*vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(*vertexShader);
    free((char *)vertexShaderSource);

    // check for shader compile errors
    int success;
    glGetShaderiv(*vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(*vertexShader, bufferLen, NULL, infoLog);
        LOG_FMT_M("FAILED to compile vertex shader.\n%s\n", infoLog);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}



static inline exitStatus_t fragmentShader_compile_ (u32 *fragmentShader,
        char *infoLog, size_t bufferLen) {

    if (fragmentShader == NULL) {return EXIT_FAILURE;}
    const char *fragmentShaderSource = CORE_readFile(fragmentShaderPath);

    *fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(*fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(*fragmentShader);
    free((char *)fragmentShaderSource);

    // check for shader compile errors
    int success;
    glGetShaderiv(*fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(*fragmentShader, 512, NULL, infoLog);
        LOG_FMT_M("FAILED to compile fragment shader.\n%s\n", infoLog);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


static inline exitStatus_t linkShaders_ (u32 * shaderProgram, 
        u32 *vertexShader, u32 *fragmentShader,
        char *infoLog, size_t bufferLen) {
    if (shaderProgram == NULL) {return EXIT_FAILURE;}

    *shaderProgram = glCreateProgram();

    glAttachShader(*shaderProgram, *vertexShader);
    glAttachShader(*shaderProgram, *fragmentShader);
    glLinkProgram(*shaderProgram);

    // linking check
    int success;
    glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(*shaderProgram, bufferLen, NULL, infoLog);
        LOG_FMT_M("FAILED to link shaders.\n%s\n", infoLog);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}


exitStatus_t SHAM_SHADERS_compile(struct SHAM_UI *ui_ptr);

#endif // !SHAM_SHADERS_H
