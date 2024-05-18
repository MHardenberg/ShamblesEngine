#ifndef shader_H
#define shader_H

#include <shamEngine/ui/ui.h>
#include <shamCore.h>

typedef struct {
    char* vertexShader; 
    char* fragmentShader;
} SHAM_shader;



u32 SHAM_SHADER_create(SHAM_ui* ui_ptr) ;


void SHAM_SHADER_destroy(SHAM_shader* ptr);

#endif // !shader_H
