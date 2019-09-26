#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static void handle(int sig){
	fprintf("Signal %d\n", sig);
	fprintf(stderr, "Interrupted\n");
  exit(2);
}

int main(int argc, char *argv[]){
	struct sigaction sact;
	memset(&sact, 0, sizeof(sact));

	sact.sa_handler = handle;

	sigaction(SIGUSR1, &sact, NULL);
	sigaction(SIGKILL, &sact, NULL);
	sigaction(SIGSTOP, &sact, NULL);

	while(1){}
}