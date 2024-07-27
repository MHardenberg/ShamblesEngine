#include <core.h>
#include <coreSettings.h>
#include <coreGraphics/ui.h>
#include <coreGraphics/shaders.h>
#include <coreGraphics/verticeBuffers.h>


int exitStatus = EXIT_SUCCESS;

int main() {
    struct SHAM_UI *ui_ptr = SHAM_UI_createUI();
    if (ui_ptr == NULL) {
        LOG_M("FAILED to initialize SHAM_UI.\n");
        exitStatus = EXIT_FAILURE;
        goto exit;
    }

    if (SHAM_SHADERS_compile(ui_ptr)) {
        LOG_M("FAILED to compile shaders.\n");
        exitStatus = EXIT_FAILURE;
        goto freeUI;
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
        LOG_M("FAILED to setup vertices.\n");
        goto freeUI;
    }

    while (!SHAM_UI_shouldClose(ui_ptr)) {
        SHAM_UI_processInput(ui_ptr);
        SHAM_UI_render(ui_ptr);
        SHAM_UI_update(ui_ptr);
    }

freeUI:
    SHAM_UI_destroy(ui_ptr);

exit:
    return exitStatus;
}
