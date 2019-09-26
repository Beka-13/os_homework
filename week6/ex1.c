#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 21

int main(){
  char* first = "Bekzhan Talgat B18-05";
  char second[SIZE];
  int truba[2];

  if(pipe(truba) < 0) exit(1);

  write(truba[1], first, SIZE);
  read(truba[0], second, SIZE);
  close(truba[1]);

  printf("%s\n", second);

  return 0;
}
