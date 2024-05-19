#include "ui.h"

struct SHAM_UI *SHAM_UI_createUI() {
    struct SHAM_UI ui = {.width = SCR_WIDTH, .height = SCR_HEIGHT};
    struct SHAM_UI *ui_ptr = malloc(sizeof(struct SHAM_UI));
    if (ui_ptr == NULL) {
        goto exitFailure;
    }

    if (memcpy(ui_ptr, &ui, sizeof(struct SHAM_UI)) == NULL) {
        goto freeUI;       
    };

    if (windowInit_(ui_ptr)) {goto freeUI;}
    if (procAddrsInit_()) {goto freeUI;}

    return ui_ptr;

freeUI:
    free(ui_ptr);

exitFailure:
    return NULL;
}

void SHAM_UI_destroy(struct SHAM_UI *ptr) {
    if (ptr == NULL) {
        LOG_M("FAILED to free SHAM_UI.\n");
        return;
    }

    glfwDestroyWindow(ptr->external.window);
    glDeleteVertexArrays(1, &ptr->VAO);
    glDeleteBuffers(1, &ptr->VBO);
    glDeleteBuffers(1, &ptr->EBO);
    glDeleteProgram(ptr->external.shader);

}
