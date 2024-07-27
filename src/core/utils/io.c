#include <stdio.h>
#include "io.h"


exitStatus_t CORE_readFile(char *dest, const char * path, size_t bytes) {
    if (dest == NULL) {
        LOG_M("dest pointer is NULL.");
        return EXIT_FAILURE;
    }
    if (path == NULL) {
        LOG_M("path pointer is NULL.");
        return EXIT_FAILURE;
    }

    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) {
        LOG_M("file path invalid.");
        return EXIT_FAILURE;
    }
        char c;
        size_t i = 0;


        do {
            if(i == bytes) {
                LOG_M("Buffer exceeded.");
                return EXIT_FAILURE;
            }

         c = getc(file);
         dest[i] = c;
         ++i;

        } while (c != EOF);
    return EXIT_SUCCESS;
}




