#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
	int status;
	int truba[2];
	pipe(truba);

	pid_t first, second;

	first = fork();
	second = fork();

	if(first != 0 & second != 0){
		write(truba[1], &second, sizeof(second));
		waitpid(second, &status, WUNTRACED);
		printf("Status:%d\n", status);
	}
	else if(first == 0){
		sleep(5);
		read(truba[0], &second, sizeof(second));
		kill(second, SIGSTOP);
	}
	else{
		while(1){
			printf("Second child is alive\n");
			sleep(1);
		}	
	}

  return 0;
}