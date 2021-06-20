//
// Created by martin on 6/2/21.
//

// key: binary vs ascii, like 3 ascii is 33
// `cat` and `hexdump` shows little endian
// fwrite output binary
// wzip: binary number + ascii letter

#include "stdio.h"
#include "stdlib.h"
#define BUFFER_SIZE (512)

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    for(int i=1;i<argc;i++) {
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        char buffer[BUFFER_SIZE];

        while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
            // printf("buffer: %s\n", buffer);
            int count = 1;
            int start = 0;
            while (start < BUFFER_SIZE && buffer[start] != '\n') {
                if(buffer[start] == buffer[start+1]) {
                    count++;
                } else {
                    //printf("%d%c", count, buffer[start]);
                    fwrite(&count, sizeof(int), 1, stdout); // binary
                    // printf("%c", buffer[start]); // ascii
                    fwrite(&buffer[start], sizeof(char), 1, stdout);
                    count = 1;
                }
                start++;
            }

        }

        fclose(fp);
    }

    return 0;
}