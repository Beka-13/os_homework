#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10

void *thread_func(void *vargp){
	int *num = (int *)vargp;
    printf("I am a thread%d!\n", ++(*num));
    (*num)--;
  return NULL;
}

int main(){

	for(int i=0;i<N;i++){
		pthread_t id;
		pthread_create(&id, NULL, thread_func, (void *)&i);

		printf("Hello World \n");

		pthread_join(id, NULL);
	}
	
  return 0;
}