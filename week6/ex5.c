#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	pid_t truba = fork();
	if(truba == 0){
		while(1){
			fprintf(stdout, "%s\n", "I'm alive!");
			sleep(1);
		}
	} else{
		sleep(10);
		kill(truba, SIGTERM);
	}
}