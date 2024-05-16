#include "ui.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


SHAM_ui* SHAM_create_window() {
    // create heaped window
    if (!glfwInit()) {
        LOG_FMT_M("%s\n", "glfw initalisation failed.");
        goto exitFailure;
    }
    

    // init GLFW window
    GLFWwindow* glWindow = glfwCreateWindow(BASE_WIDTH, BASE_HEIGHT,
            "Absolute shambles..", NULL, NULL);
    if (glWindow == NULL) {goto cleanUpGL;}


    // manage context ~ whatever that means.....
    glfwMakeContextCurrent(glWindow);
    gladLoadGL();
    // set viewport for scaling
    glViewport(0, 0, BASE_WIDTH, BASE_HEIGHT);


    // init SHAM window
    SHAM_ui ui = {
        .WIDTH = BASE_WIDTH, .HEIGHT = BASE_HEIGHT, .sysWindow = glWindow};
    SHAM_ui* ui_ptr = malloc(sizeof(SHAM_ui));
    if (ui_ptr == NULL){goto cleanUpUi;}
    memcpy(ui_ptr, &ui, sizeof(*ui_ptr));


exitSuccess:
    return ui_ptr;

// only clean on failure
cleanUpUi:
    free(ui_ptr);

cleanUpGL:
    glfwDestroyWindow(glWindow);
    glfwTerminate();

exitFailure:
    return NULL;
}


void SHAM_freeUI(SHAM_ui *ptr) {
    glfwDestroyWindow((GLFWwindow*)ptr->sysWindow);
    glfwTerminate();
     free(ptr);
}


bool SHAM_isRunning(SHAM_ui* ptr) {
    if (ptr == NULL) {
        LOG_FMT_M("%s", "UI pointer is NULL!");
        return false;
    }
    return glfwWindowShouldClose((GLFWwindow*) ptr->sysWindow);
}
