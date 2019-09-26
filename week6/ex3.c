#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static void handle(int sig){
	fprintf(stderr, "\nCommand-C has pressed. It is a macbook\n\n");
	exit(2);
}

int main(int argc, char *argv[]){
	struct sigaction sact;
	memset(&sact, 0, sizeof(sact));

	sact.sa_handler = handle;

	sigaction(SIGINT, &sact, NULL);

	while (1){sleep(1)}
}