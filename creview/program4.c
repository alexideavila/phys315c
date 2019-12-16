#include <stdio.h>

double fact(int);

int main(){
	int terms=0;
	double e[4]={};
	printf("This a program that calculates the value of e 4 different ways\n");
	printf("How many terms would you like: ");
	scanf("%d", &terms);	
	for(int i=0; i<terms; i++){
		e[0]+=1/fact(i);
		e[1]+=(2*i+1)/fact(2*i);
		e[2]+=(1/2.0)*(i+1)/fact(i);
		e[3]+=2*(i+1)/fact(2*i+1);
	}
	printf("Here are the values of e\n");
	for(int j=0; j<4; j++){
		printf("%g\n", e[j]);
	}
	return 0;
}

double fact(int n){
	if (n<1) return 1;
	else return (double)n * fact(n-1);
}
