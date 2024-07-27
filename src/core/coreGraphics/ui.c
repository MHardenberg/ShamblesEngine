#include "ui.h"

struct SHAM_UI *SHAM_UI_createUI() {
    struct SHAM_UI *ui_ptr = malloc(sizeof(struct SHAM_UI));
    if (ui_ptr == NULL) {
        goto exitFailure;
    }
    ui_ptr->width = SCR_WIDTH;
    ui_ptr->height = SCR_HEIGHT;


    if (windowInit_(ui_ptr)) {goto freeUI;}
    if (procAddrsInit_()) {goto freeUI;}

    return ui_ptr;

freeUI:
    free(ui_ptr);

exitFailure:
    return NULL;
}

void SHAM_UI_destroy(struct SHAM_UI *ui_ptr) {
    assert(ui_ptr != NULL);

    glfwDestroyWindow(ui_ptr->external.window);
    glDeleteVertexArrays(1, &ui_ptr->VAO);
    glDeleteBuffers(1, &ui_ptr->VBO);
    glDeleteBuffers(1, &ui_ptr->EBO);
    glDeleteProgram(ui_ptr->external.shader);
}

bool SHAM_UI_shouldClose(struct SHAM_UI *ui_ptr) {
    assert(ui_ptr != NULL);
 return glfwWindowShouldClose(ui_ptr->external.window);
}

void SHAM_UI_processInput(struct SHAM_UI *ui_ptr) {
    assert(ui_ptr != NULL);
    if (glfwGetKey(ui_ptr->external.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(ui_ptr->external.window, 1);
}

void SHAM_UI_render(struct SHAM_UI *ui_ptr) {
    assert(ui_ptr != NULL);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(ui_ptr->external.shader);
        glBindVertexArray(ui_ptr->VAO); 
        // seeing as we only have a single VAO there's no need to bind 
        // it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 
}

void SHAM_UI_update(struct SHAM_UI *ui_ptr) {
        assert(ui_ptr != NULL);
        glfwSwapBuffers(ui_ptr->external.window);
        glfwPollEvents();
}

