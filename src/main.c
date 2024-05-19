#include <core.h>
#include <coreSettings.h>
#include <coreGraphics/ui.h>
#include <coreGraphics/shaders.h>
#include <coreGraphics/verticeBuffers.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main() {

    struct SHAM_UI *ui_ptr = SHAM_UI_createUI();
    if (ui_ptr == NULL) {
        LOG_M("FAILED to initialize SHAM_UI.\n");
        return EXIT_FAILURE;
    }

    if (SHAM_SHADERS_compile(ui_ptr)) {
        LOG_M("FAILED to compile shaders.\n");
    }



    
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    if (SHAM_setVertexBuffers(ui_ptr, vertices, sizeof(vertices),
                indices, sizeof(indices))) {
        LOG_M("FAILED to setup vertices\n");
        goto freeUI;
    }

    // render loop
    // -----------
    while (!glfwWindowShouldClose(ui_ptr->external.window)) {
        // input
        // -----
        processInput(ui_ptr->external.window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(ui_ptr->external.shader);
        glBindVertexArray(ui_ptr->VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(ui_ptr->external.window);
        glfwPollEvents();
    }

freeUI:
    SHAM_UI_destroy(ui_ptr);
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}
