#include<stdio.h>
#include<stdlib.h>

int aging(int fps) {
	FILE *file = fopen("input.txt", "r");

	int hit = 0;
	int miss = 0;
	int amount = 0;
	int x;

	while (fgetc(file) != EOF){
		fscanf(file, "%d", &x);
		amount++;
	}

	fclose(file);

	file = fopen("input.txt", "r");
	int page_num;
	int *time = calloc(fps, sizeof(int));
	int *frame = calloc(fps, sizeof(int));

	for (int i = 0; i < amount; i++){
		fscanf(file, "%d", &page_num);
		int free = 0;
		int hits = 0;

		for(int j = 0; j < fps; j++){
	  		time[j] = time[j] >> 1;

		 	if (hits != 1 && frame[j] == page_num){
		    	time[j] += (1 << 31);
		    	hit++;
		    	hits = 1;
		    }
		}

		if (!hits){
			for(int j = 0; j < fps; j++){
				if (frame[j] == 0){
					frame[j] = page_num;
					time[j] = 1 << 31;
					miss++;
					free = 1;
					break;
				}
			}
		} 

		if (!hits && !free){
		  int index = 0;
		  int min_age = time[0];
		  for (int j = 1; j < fps; j++){
		    if (time[j] < min_age){
		    	min_age = time[j];
		    	index = j;
		    }
		  }

		  frame[index] = fps;
		  time[index] = 1 << 31;
		  miss++; 
		}
	}
	fclose(file);
  	printf("Hit/Miss ratio: %f\n", (double) hit/miss);
  	return 0;
}

int main(){
  aging(10);
  aging(50);
  aging(100);
}