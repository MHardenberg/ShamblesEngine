#include <shamCore.h>
#include <shamEngine/ui/ui.h>


int main() {
    LOG_M("We're in shambles!!!!!\n");
    SHAM_ui* ui_ptr = SHAM_UI_create();


    while (!SHAM_UI_isRunning(ui_ptr)) {
        if (SHAM_UI_update(ui_ptr)) {break;}
    }

    SHAM_UI_destroy(ui_ptr);
    LOG_M("Rattled!\n");
    return 0;
}
