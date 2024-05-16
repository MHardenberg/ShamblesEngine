#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


SHAM_ui* SHAM_create_window() {
    // create heaped window
    if (!glfwInit()) {
        LOG_FMT_M("%s\n", "glfw initalisation failed.");
        return NULL;
    }
    

    // init GLFW window
    GLFWwindow* glWindow = glfwCreateWindow(BASE_WIDTH, BASE_HEIGHT,
            "Absolute shambles..", glfwGetPrimaryMonitor(), NULL);
    if (glWindow == NULL) {goto exitFailure;}

    // manage context ~ whatever that means.....
    glfwMakeContextCurrent(glWindow);
    gladLoadGL();
    // set viewport for scaling
    glViewport(0, 0, BASE_WIDTH, BASE_HEIGHT);


    // init SHAM window
    SHAM_ui ui = {
        .WIDTH = BASE_WIDTH, .HEIGHT = BASE_HEIGHT, .sysWindow = glWindow
    };
    SHAM_ui* ui_ptr = malloc(sizeof(SHAM_ui));

    // On fail free GL window
    if (ui_ptr == NULL){goto cleanUp;}
    memcpy(ui_ptr, &ui, sizeof(*ui_ptr));


exitSuccess:
    return ui_ptr;

// only clean on failure
cleanUp:
    glfwDestroyWindow(glWindow);

exitFailure:
    return NULL;
}


void SHAM_freeUI(SHAM_ui *ptr) {
    glfwDestroyWindow((GLFWwindow*)ptr->sysWindow);
    glfwTerminate();
     free(ptr);
}


bool SHAM_isRunning(SHAM_ui* ptr) {
    return glfwWindowShouldClose((GLFWwindow*) ptr->sysWindow);
}
