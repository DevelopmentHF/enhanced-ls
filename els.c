#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <assert.h>

#include "file_checking.h"
#include "els.h"

int
main(int argc, char** argv) {

    // Open directory in which els command is run 
    DIR *dir = opendir(".");
    struct dirent *ent;

    // Arrays of directory strings and file strings
    char **dirstrs;
    char **filestrs;
    int num_dirstrs = 0;
    int num_filestrs = 0;
    int cur_size_dirstrs = INIT_SIZE;
    int cur_size_filestrs = INIT_SIZE;
    dirstrs = (char**) malloc (INIT_SIZE * sizeof(*dirstrs));
    filestrs = (char**) malloc (INIT_SIZE * sizeof(*filestrs));
    assert(dirstrs);
    assert(filestrs);


    // Go through all entries within this directory
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {

            // Abide by ignore philosophy
            if (ent->d_name[0] != '.') {

                // Check if entry is a directory
                if (isDir(ent->d_name)) {
                    // might need to resize array of file name
                    if (num_filestrs == (int)cur_size_filestrs) {
                        cur_size_filestrs *= 2;
                        filestrs = (char**)realloc(filestrs, cur_size_filestrs * sizeof(*filestrs));
                        assert(filestrs);
                    }
                    // add cur file name to array of file names
                    filestrs[num_filestrs] = (char*)malloc(1 + strlen(ent->d_name));
                    assert(filestrs[num_filestrs]);
                    strcpy(filestrs[num_filestrs++], ent->d_name);
                } else {
                    // might need to resize array of dir names
                    if (num_dirstrs == (int)cur_size_dirstrs) {
                        cur_size_dirstrs *= 2;
                        dirstrs = (char**)realloc(dirstrs, cur_size_dirstrs * sizeof(*dirstrs));
                        assert(dirstrs);
                    }
                    // add cur dir name to array of dir names
                    dirstrs[num_dirstrs] = (char*)malloc(1 + strlen(ent->d_name));
                    assert(dirstrs[num_dirstrs]);
                    strcpy(dirstrs[num_dirstrs++], ent->d_name);
                }
            }
        }
        closedir(dir);
    } else {
        printf("Error: could not open directory.\n");
    }

    // Go thru all sub-directories and print them
    printf(YEL "===DIRECTORIES===\n");
    for (int i=0; i<num_dirstrs; i++) {
        printf(BLU "%s\n" RESET, dirstrs[i]);
    }

    // Go thru all files and print them
    printf(GRN "\n===FILES===\n");
    for (int i=0; i<num_filestrs; i++) {
        printf(WHT "%s\n" RESET, filestrs[i]);
    }

    // Free
    for (int i=0; i<num_dirstrs; i++) {
        free(dirstrs[i]);
    }
    free(dirstrs);
    for (int i=0; i<num_filestrs; i++) {
        free(filestrs[i]);
    }
    free(filestrs);
    return 0;
}

