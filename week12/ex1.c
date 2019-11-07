#include <stdio.h>

int main(){

    FILE *in = fopen("/dev/random", "r");
    if(in == NULL) perror("/dev/random: ");
    
    FILE *out = fopen("./ex1.txt", "w");
    if(out == NULL) perror("./ex1.txt: ");

    for(size_t i = 0; i <  20; i++) {
      int32_t byte = fgetc(in);
      fputc(byte, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}
