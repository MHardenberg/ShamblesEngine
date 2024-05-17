#ifndef shader_H
#define shader_H

#include <glad/glad.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <shamCore.h>
#include <stdlib.h>

typedef struct {
    char* vertexShader; 
    char* fragmentShader;
} SHAM_shader;



u32 SHAM_SHADER_create() {
    /*
    SHAM_shader* shader_ptr = malloc(sizeof(SHAM_shader));
    if (NULL == shader_ptr) {return NULL;}
    */
        const char* vertexShaderSource= 
            "#version 460 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main() {\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

        const char* fragmentShaderSource = 
            "#version 460 core\n"
            "out vec4 FragColor\n;"
            "void main() {\n"
            "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\0";


        int  success;
        char infoLog[512];


        u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);       
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success){
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            LOG_FMT_M("%s", infoLog);
            goto cleanVertex;
        }

        u32 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);       
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success){
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            LOG_FMT_M("%s", infoLog);
            goto cleanFragment;
        }

        // link
        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success){
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            LOG_FMT_M("%s", infoLog);
            shaderProgram = 0;
            goto cleanUp;
        }
cleanUp:

cleanFragment:
        glDeleteShader(fragmentShader);
cleanVertex:
        glDeleteShader(vertexShader);

        return NULL;
}



void SHAM_SHADER_destroy(SHAM_shader* ptr) {
    if (NULL == ptr) {return;}
    glDeleteShader(*ptr->vertexShader);
    glDeleteShader(*ptr->fragmentShader);
}

#endif // !shader_H
