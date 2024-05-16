#include <stdio.h>
#include <shamCore.h>
#include <engine/ui/ui.h>

int main() {
    printf("We're in shambles!!!!!\n");

    SHAM_ui* ui_ptr = SHAM_create_window();


    while (!SHAM_isRunning(ui_ptr)) {
        // process input and act
        glClear(GL_COLOR_BUFFER_BIT);

        // Render here
        
        // Poll for and process events
        glfwPollEvents();

        // Swap front and back buffers
        glfwSwapBuffers((GLFWwindow*)ui_ptr->sysWindow);
    }

    SHAM_freeUI(ui_ptr);
    return 0;
}
