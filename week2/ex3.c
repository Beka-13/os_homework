#include <stdio.h>
#include <stdlib.h>

void figure1(int h){
	for(int i=0;i<h;i++){
		for(int j=0;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}

void figure2(int h){
	for(int i=0;i<h;i++){
		if(h/2 > i){
			for(int j=0;j<=i;j++)
				printf("*");
		}else{
			for(int j=h-i-1;j>=0;j--)
				printf("*");
		}
		printf("\n");
	}
}

void figure3(int h){
	for(int i=0;i<h;i++){
		for(int j=0;j<h;j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);

	int a=n-1;
	for(int g=0; g<n; g++){

		for(int i=a-1; i>=0; i--){
			if(g>i){
				printf("*");
			}else{
				printf(" ");
			}
		}

		printf("*");

		for(int i=0; i<n-1; i++){
			if(g<=i){
				printf(" ");
			}else{
				printf("*");
			}
		}

		printf("\n");
	}

	printf("\nNow choose one of the figures: 1 2 3\n");
	printf("Figure: ");

	int num;
	scanf("%d", &num);

	if(num>3 || num<1){
		printf("Incorect number\n");
	}else{
		if(num == 1)figure1(n);
		if(num == 2)figure2(n);
		if(num == 3)figure3(n);
	}
	
  return 0;
}