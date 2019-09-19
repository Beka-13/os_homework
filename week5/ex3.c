#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

const long long max = 1e9 + 1;
long long buff; 

void *produce(){
	while (1){
		if(buff < max){
			buff++;
		}
		else{
			while(1){
				if(buff<max)break;
			}
		}
	}
}
void *consume(){
	while(1){
		if(buff > 0){
			buff--;
		}
		else{
			while(1){
				if(buff > 0)break;
			}
		}
	}
}
void *print(){
	while(1){
		printf("Buffer size is %lld\n", buff);
		sleep(60);
	}
}

int main(){
	pthread_t first, second, third;
	pthread_create (&first, NULL, produce, NULL);
	pthread_create (&first, NULL, consume, NULL);
	pthread_create (&third, NULL, print, NULL);
	pthread_join(first, NULL);
	pthread_join(second, NULL);
	pthread_join(third, NULL);
  return 0;
}