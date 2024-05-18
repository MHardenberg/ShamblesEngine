#include <shamCore.h>
#include <shamEngine/ui/ui.h>
#include <shamEngine/entity/entity.h>


int main() {
    LOG_M("We're in shambles!!!!!\n");
    SHAM_ui* ui_ptr = SHAM_UI_create();



    SHAM_ENTITY_triangle x = SHAM_ENTITY_triangleCreate();
    while (!SHAM_UI_isRunning(ui_ptr)) {
        if (SHAM_UI_update(ui_ptr)) {break;}
        if (SHAM_ENTITY_draw(ui_ptr, &x, triangle)) {LOG_M("Error drawing..");};
        
    }


    SHAM_UI_destroy(ui_ptr);
    LOG_M("Rattled!\n");
    return 0;
}
