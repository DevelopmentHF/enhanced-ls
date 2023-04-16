#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#include "file_checking.h"

#define MAX_DIRNAME_SIZE (100)

int
main(int argc, char** argv) {

    // Open directory of ../enhanced-ls
    DIR *dir = opendir(".");
    struct dirent *ent;

    // Go through all entries within this directory
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            // Abide by ignore philosophy
            if (ent->d_name[0] != '.') {
                // Check if entry is a directory
                char str[MAX_DIRNAME_SIZE] = "./";
                strcat(str, ent->d_name);
                if (isDir(str)) {
                    printf("FILE %s\n", ent->d_name);
                } else {
                    printf("DIRECTORY %s\n", ent->d_name);
                }
            }
        }
        closedir(dir);
    } else {
        printf("Error: could not open directory.\n");
    }
    return 0;
}
