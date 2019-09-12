// #include <stdio.h>
// #include <sys/types.h>

// int main(){
// 	int n = 0;

// 	fork();

// 	printf("hello %d\n", n);

//   return 0;
// }

// #include  <stdio.h>
// #include  <string.h>
// #include  <sys/types.h>

// #define   MAX_COUNT  200
// #define   BUF_SIZE   100

// void main(void){
// 	int pid;
// 	int i = 100;
// 	char *a = "data";
// 	char buf[BUF_SIZE];

// 	fork();
// 	pid = getpid();
// 	for (i = 1; i <= MAX_COUNT; i++){
// 		sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
// 		write(1, buf, strlen(buf));
// 	} 
// }

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void ex1(){
	int n;

	if(fork() == 0){
		n = getpid();
		printf("Hello from Child! [PID - %d]\n\n", n);
	}

	else{
		n = getpid();
		printf("Hello from Parent! [PID - %d]\n", n);
	}
}

int main(){

	ex1();
  return 0;
}