#ifndef verticeBuffers_H
#define verticeBuffers_H

#include <core.h>
#include <coreGraphics/ui.h>

exitStatus_t SHAM_setVertexBuffers(struct SHAM_UI *ui_ptr,
        f32 *vertices, size_t verticesSize,
        u32 *indices, size_t indicesSize);

#endif // !verticeBuffers_H
