#include <stdio.h>
#include <math.h>

int main(){
	float z, y, x;
	float precision=0.0;
	printf("Give a number: ");
	scanf("%g", &x);
	printf("How precise? ");
	scanf("%g", &precision);
	
	y=1.0;
	z=1/5.0*(4.0*y+(x/pow(y,4)));
	while(fabs(y-z)>precision){
		y=z;
		z=1/5.0*(4.0*y+(x/pow(y,4)));
	}
	printf("The fifth root of %g is: %g\n", x, y); 
	return 0;
}
