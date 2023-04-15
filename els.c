#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

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
                printf("%s\n", ent->d_name);
            }
        }
        closedir(dir);
    } else {
        printf("Error: could not open directory.\n");
    }
    return 0;
}
