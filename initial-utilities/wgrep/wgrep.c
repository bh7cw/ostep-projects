//
// Created by martin on 6/2/21.
//
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define BUFFER_SIZE (512)

// if line contains word, return true, otherwise return false
bool contains(char *line, char *word) {
    if(strlen(line) < strlen(word)) return false;
    for(int i=0;i<strlen(line)-strlen(word)+1;i++) {
        char *tmp = malloc(strlen(word));
        memcpy(tmp , line+i, strlen(word) );
        if(strcmp(tmp, word) == 0) return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *word = argv[1];
    if(argc == 2) {
        char buffer[BUFFER_SIZE];
        // get input from stdin
        while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
            if(contains(buffer, word)) printf("%s", buffer);
        }
        exit(0);
    }

    for(int i=2;i<argc;i++) {
        // get input from file
        FILE *fp = fopen(argv[i], "r");

        if(fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }

        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
            if(contains(buffer, word)) printf("%s", buffer);
        }

        fclose(fp);
    }

    return 0;
}
