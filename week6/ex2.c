#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int     truba[2], nbytes;
	pid_t   childpid;
	char    first[] = "Hello, world!\n";
	char    second[80];

	pipe(truba);

	if((childpid = fork()) == -1){
		perror("fork");
	  exit(1);
	}

	if(childpid == 0){
		close(truba[0]);

		write(truba[1], first, (strlen(first)+1));
	  exit(0);
	}
	else{
		close(truba[1]);

		nbytes = read(truba[0], second, sizeof(second));
		printf("Received first: %s", second);
	}

  return(0);
}