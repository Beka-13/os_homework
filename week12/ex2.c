//
//  ex2.c
//  
//
//  Created by Bekzhan Talgat on 07.11.2019.
//

#include "ex2.h"

int main(int argc, char **argv) {
    char f[] = "w";

    if(argc >= 2 && strcmp(argv[1], "-a") == 0) {
    strcpy(f, "a");
    }

    FILE **out = calloc(argc, sizeof(FILE*));
    out[0] = stdout;

    for(size_t i = 1; i < argc; i++) {
        out[i] = fopen(argv[i], f);
        if(out[i] == NULL) perror(argv[i]);
    }

    while(1) {
        int in = fgetc(stdin);
        if(in == EOF) break;

        for(size_t i = 0; i < argc; i++)
            fputc(in, out[i]);
    }


    for(size_t i = 1; i < argc; i++)
        fclose(out[i]);
    
}
