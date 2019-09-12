#include <stdio.h>
#include <sys/types.h>

int main(){
  // it works in exponentially
  // 3 = 8 processes
  // 5 = 32 processes

  for(int i = 0; i < 5; i++){
     fork();
     sleep(5);
  }

  return 0;
}