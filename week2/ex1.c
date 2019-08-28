#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a;
	float b;
	double c;

	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;

	printf("size of a(int) = %lu\n", sizeof(a));
	printf("size of b(float) = %lu\n", sizeof(b));
	printf("size of c(double) = %lu\n\n", sizeof(c));
	
	printf("max value for a(int) = %d\n\n", a);
	printf("max value for b(float) = %f\n\n", b);
	printf("max value for c(double) = %lf\n\n", c);

  return 0;
}