//
// Created by martin on 6/2/21.
//
#include "stdio.h"
#include "stdlib.h"
#define BUFFER_SIZE (512)

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for(int i=1;i<argc;i++) {
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        char buffer[BUFFER_SIZE];

        while (fread(buffer, sizeof(char), 5, fp) != 0) {
            // little endian
            int count = buffer[0] | buffer[1] << 8 | buffer[2] << 16 | buffer[3] << 24;
            char character = buffer[4];
            for(int i=0; i<count; i++) {
                printf("%c", character);
            }
        }

        fclose(fp);
    }

    return 0;
}