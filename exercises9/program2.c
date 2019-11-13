#include <stdio.h>

int cross(int *, int *, int *);

int main()
{
	int vector1[3];
	int vector2[3];
	int crossproduct[3];
	printf("Enter a three dimensional vector by the return key: ");
	
	for(int i=0; i<=2; i++){
		scanf("%d",&vector1[i]);
	}	

	printf("Enter one more: ");
	for(int j=0; j<=2; j++){
		scanf("%d",&vector2[j]);
	}
	cross(vector1,vector2,crossproduct);
	printf("The cross product of those vectors are: <");

	for(int k=0; k<=2; k++){		
		printf("%d,",crossproduct[k]);
	}
	printf("\b");
	printf(">");
	printf("\n");
	return 0;
}

int cross(int x[],int y[], int z[]){

	z[0] = (x[1]*y[2])-(x[2]*y[1]);
	z[1] = -((x[0]*y[2])-(x[2]*y[0]));
	z[2] = (x[0]*y[1])-(x[1]*y[0]);

}
