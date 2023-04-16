#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "file_checking.h"

/* Checks whether a file is a directory */
int isDir(const char* fileName) {
    struct stat path;

    stat(fileName, &path);

    return S_ISREG(path.st_mode);
}