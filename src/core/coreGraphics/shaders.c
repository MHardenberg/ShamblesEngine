#include "shaders.h"

exitStatus_t SHAM_SHADERS_compile(struct SHAM_UI *ui_ptr) {
    u32 vertexShader, fragmentShader;
    const u32 bufferLen = 512;
    char infoLog[bufferLen];

    if (vertexShader_compile_(&vertexShader, infoLog, bufferLen)) {
        return EXIT_FAILURE;
    }
    if (fragmentShader_compile_(&fragmentShader, infoLog, bufferLen)) {
        return EXIT_FAILURE;
    }

    if (linkShaders_(&ui_ptr->external.shader, &vertexShader, &fragmentShader,
                infoLog, bufferLen)) {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return EXIT_FAILURE;
        
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return EXIT_SUCCESS;
}
