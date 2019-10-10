#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

int main(){
	
    for (int i; i < 10; i++) {
        void *v = malloc(1024 * 1024 * 10);
        memset(v, 0, 10240);
        sleep(1);
    }

  return 0;
}