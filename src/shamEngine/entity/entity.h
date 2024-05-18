#include "shamEngine/shader/shader.h"
#include <shamCore.h>
#include <shamEngine/ui/ui.h>


typedef enum {point, triangle} SHAM_ENTITY_type ;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} SHAM_ENTITY_point;


typedef struct {
   SHAM_ENTITY_point a;
   SHAM_ENTITY_point b;
   SHAM_ENTITY_point c;
} SHAM_ENTITY_triangle;


SHAM_ENTITY_triangle SHAM_ENTITY_triangleCreate() {
    SHAM_ENTITY_triangle ent;
    ent.a = (SHAM_ENTITY_point) {-0.5f, -0.5f, 0.0f,};
    ent.b = (SHAM_ENTITY_point) { 0.5f, -0.5f, 0.0f,};
    ent.c = (SHAM_ENTITY_point) { 0.0f,  0.5f, 0.0f,};

    return ent;
}


int SHAM_ENTITY_draw(SHAM_ui* ui_ptr, void* ent_ptr,
        SHAM_ENTITY_type ent_type) {
    if (ui_ptr == NULL || ent_ptr == NULL) {
        return EXIT_FAILURE;
    }

    switch (ent_type) {
        case point: {
                        LOG_M("Not impl....\n");
                        break;
                    }
        case triangle: {
                        glBufferData(ui_ptr->external.vertexBufferObject,
                                sizeof(triangle), (f32*)ent_ptr,
                                GL_STATIC_DRAW);
                        glDrawArrays(GL_TRIANGLES, 0, 3);
                        break;
                       }
    }

    return EXIT_SUCCESS;
}
