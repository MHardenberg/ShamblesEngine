#include <stdio.h>
#include <time.h>
#include "io.h"
#ifdef __linux
    #include <sys/stat.h>

    size_t fileSize(const char *file) {
        struct stat st;
        stat(file, &st);
        return st.st_size;
    }

#endif

#ifdef _WIN32
    #include <fileapi.h>

    size_t fileSize(const char *file)  {
        size_t size;
        GetFileSize(file, &size);
        return size;
    }

#endif

const char *CORE_readFile(const char * path) {
    if (path == NULL) {
        LOG_M("path pointer is NULL.");
        return NULL;
    }

    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) {
        LOG_M("file path invalid.");
        return NULL;
    }
    
    size_t length;
    char *content = malloc(length);
    if (content == NULL) {
        LOG_M("Allocation error.");
        return NULL;
    }

    fread(content, sizeof(char), length, file);
    return content;
}




