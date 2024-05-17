#ifndef window_H
#define window_H

#include <glad/glad.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <shamCore.h>

#include <stdbool.h>


typedef struct SHAM_ui {
    const u16 WIDTH, HEIGHT;

    // external stuff
    const GLFWwindow* sysWindow;
} SHAM_ui;


SHAM_ui* SHAM_UI_create(); 

void SHAM_UI_destroy(SHAM_ui* ptr);

bool SHAM_UI_isRunning(SHAM_ui *ptr);
#endif // !window_H
