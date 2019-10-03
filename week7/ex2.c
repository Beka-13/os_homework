#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(){

	int *array = malloc(N*sizeof(int));

	for (int i=0; i<N; i++){
		array[i] = i;
		printf("%d\n", array[i]);
	}
	free(array);
	// printf("%d\n", array[0]);
  return 0;
}