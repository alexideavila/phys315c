#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* insert roll() function prototype here */
int roll(int, int*, int, int);
int rnd(int);
#define MAX 100

int main(void)
{
	int histogram[MAX]={};
	int i, times;
	int amountDice;
	int sizeDice;

	srand((unsigned)time(NULL)); /* seed random number generator */
/* initialize all elements of histogram to 0 here */
	printf("This program will roll a die and return the measured\n");
	printf("probability of each number appearing.\n");
	printf("How many dice do you have? ");
	scanf("%d",&amountDice);// this is my m
	printf("How many sides? ");
	scanf("%d",&sizeDice);// this is my n
	printf("How many times? ");
	scanf("%d",&times);
/* insert the commands to roll the die using the function roll()
the appropriate number of times here. Perform the loop over
i in main. roll() should only update the histogram */
	roll(times,histogram,sizeDice,amountDice);	
	printf("The probablility of each number appearing is: \n");
	printf("Number  Probability\n");
	for(int i=1; i<=100; i++)
	{
		printf("%3d%9d/%d",i,histogram[i-1],times);
		printf("\n");
	}
/* insert the commands for printing the fraction of times each
number appeared here */
	return 0;
}
/* insert the appropriate function for roll() here.
Use the function rnd() to generate the random numbers */

int roll(int times1, int z[], int x, int y){
	int roll1;
	int check;
	for(int i=0; i<times1; i++){
		check=0;
		for(int j=0; j<y; j++){
			roll1=rnd(x)+1;	
			check += roll1;
		}
		z[check-1]++;
	}

}

int rnd(int n) // Random number 0..n-1 using high bits of rand()
{
	return (int)((float)n*rand()/(RAND_MAX+1.0));
}
