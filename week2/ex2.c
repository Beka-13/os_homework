#include <stdio.h>
#include <string.h>

void strrev(char *ptr){
	printf("Reverse is: ");

	int i = strlen(ptr) -1;
	while(i>=0){
		printf("%c", *(ptr+i));
		i--;
	}
	printf("\n");
}

int main(){

	printf("Good day dear user. Today I am going to tell you about 'String'. It is array of chars.\n");
	printf("Now, type any word without space and I will reverse it. Max amount of letters is 20\n");
	printf("Enter a word: ");
	
	char c[20];

	scanf("%s", c);

	strrev(&c[0]);

  return 0;
}