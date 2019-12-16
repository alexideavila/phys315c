#include<stdio.h>

void sumdiff(int*, int*);

int main(){
	int x[1];
	int y[1];
	printf("Input two numbers to take the sum and difference of: ");
	scanf("%d %d", x, y);
	
	sumdiff(x,y);	
	printf("Your new numbers are %d %d \n",x[0],y[0]);	
	return 0;
}

void sumdiff(int* a, int* b){
	int temp[1];
	temp[0]=a[0];
	a[0]=temp[0]-b[0]; // a is know the difference of a-b
	b[0]=temp[0]+b[0];//b is the sum
}
