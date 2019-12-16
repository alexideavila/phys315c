#include <stdio.h>

void sumdiff(int*, int*);

int main(){
	int x,y;
	printf("Input two numbers: ");
	scanf("%d %d", &x, &y);
	sumdiff(&x,&y);//pass by reference
	printf("Your new numbers are: %d %d\n", x,y);
	return 0;
}

void sumdiff(int* a, int* b){
	int temp;//this our swapping ability
	temp=*a;
	*a=temp-*b;
	*b+=temp;
	return;
}
