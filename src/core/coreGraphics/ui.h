#ifndef SHAM_UI_H
#define SHAM_UI_H

#include <core.h>
#include <coreSettings.h>
#include <string.h>

struct SHAM_UI {
    u16 width;
    u16 height;
    u32 VBO, VAO, EBO;
 struct {
    window_t* window;
    u32 shader;
 } external;
};

static void framebufferSize_callback_(GLFWwindow* window, 
        int width, int height) {
    glViewport(0, 0, width, height);
}

static inline exitStatus_t procAddrsInit_() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_M("FAILED to initialize GLAD.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static inline exitStatus_t windowInit_(struct SHAM_UI *ui_ptr) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    ui_ptr->external.window = glfwCreateWindow(
            ui_ptr->width, ui_ptr->height, "We're in ShAmBleS!", NULL, NULL);
    if (ui_ptr->external.window == NULL) {
        glfwTerminate();
        LOG_M("FAILED to initialize GLFW.\n");
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(ui_ptr->external.window);
    glfwSetFramebufferSizeCallback(ui_ptr->external.window,
            framebufferSize_callback_);

    return EXIT_SUCCESS;
}

struct SHAM_UI *SHAM_UI_createUI();

void SHAM_UI_destroy(struct SHAM_UI *ptr);

#endif // !SHAM_UI_H
