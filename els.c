#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#include "file_checking.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define MAX_DIRNAME_SIZE (250)

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
                    printf(WHT "FILE %s\n" RESET, ent->d_name);
                } else {
                    printf(BLU "DIRECTORY %s\n" RESET, ent->d_name);
                }
            }
        }
        closedir(dir);
    } else {
        printf("Error: could not open directory.\n");
    }
    return 0;
}
