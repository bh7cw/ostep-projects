//
// Created by martin on 5/25/21.
//
#include "stdio.h"
#include "stdlib.h"

#define BUFFER_SIZE (512)

// hexdump vs cat
// gcc -o wcat wcat.c -Wall -Werror
int main(int argc, char *argv[]) {
    // no file specified
    if(argc < 2) {
        exit(0);
    }

    // cat each file
    for(int i=1;i<argc;i++) {
        // open the file
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        // read the file
        char buffer[BUFFER_SIZE];
        // fgets -- get a line from a stream
        while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
            printf("%s", buffer);
        }

        // close the file
        fclose(fp);
    }

    return 0;
}