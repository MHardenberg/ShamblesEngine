#include "ui.h"
#include <shamEngine/shader/shader.h>


#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


SHAM_ui* SHAM_UI_create() {
    // create heaped window
    if (!glfwInit()) {
        LOG_FMT_M("%s\n", "glfw initalisation failed.");
        return NULL;
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
        .WIDTH = BASE_WIDTH, .HEIGHT = BASE_HEIGHT, .external.sysWindow = glWindow};
    SHAM_ui* ui_ptr = malloc(sizeof(SHAM_ui));
    if (ui_ptr == NULL){goto cleanUpUi;}
    memcpy(ui_ptr, &ui, sizeof(*ui_ptr));


    // init buffers
    glGenBuffers(1, &ui_ptr->external.vertexBufferObject);


    // compile shader 
    if (SHAM_SHADER_create(ui_ptr)){goto exitFailure;}

    return ui_ptr;


exitFailure:
// only clean on failure
cleanUpUi:
    free(ui_ptr);

cleanUpGL:
    glfwDestroyWindow(glWindow);
    glfwTerminate();

    return NULL;
}


void SHAM_UI_destroy(SHAM_ui *ptr) {
    glfwDestroyWindow((GLFWwindow*)ptr->external.sysWindow);
    glfwTerminate();
     free(ptr);
}


bool SHAM_UI_isRunning(SHAM_ui* ptr) {
    if (ptr == NULL) {
        LOG_FMT_M("%s", "UI pointer is NULL!");
        return false;
    }
    return glfwWindowShouldClose((GLFWwindow*) ptr->external.sysWindow);
}


int SHAM_UI_update(SHAM_ui *ui_ptr) {
        // process input and act
        glClear(GL_COLOR_BUFFER_BIT);

        // Render here
        // ...
        
        // Poll for and process events
        glfwPollEvents();

        // Swap front and back buffers
        glfwSwapBuffers((GLFWwindow*)ui_ptr->external.sysWindow);

        return EXIT_SUCCESS;

exitFailure:
        return EXIT_FAILURE;
}
