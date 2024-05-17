#ifndef window_H
#define window_H

#include <glad/glad.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <shamCore.h>

#include <stdbool.h>


typedef struct {
    const u16 WIDTH, HEIGHT;
    u32 vertexBuffer, vertexArray;
    u32 shader;
    struct {
        const GLFWwindow* sysWindow;
    } external;

} SHAM_ui;


SHAM_ui* SHAM_UI_create(); 

void SHAM_UI_destroy(SHAM_ui* ptr);

bool SHAM_UI_isRunning(SHAM_ui *ptr);

int SHAM_UI_update(SHAM_ui* ui_ptr);
#endif // !window_H
