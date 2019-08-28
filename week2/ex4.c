#include <stdio.h>

void mySwap(int *p, int *q){
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int main(){
	int a,b;

	printf("Enter two integers: ");

	scanf("%d %d", &a, &b);

	printf("Now a=%d, b=%d\n", a, b);

	mySwap(&a, &b);

	printf("Now a=%d, b=%d\n", a, b);

  return 0;
}