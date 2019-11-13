#include <stdio.h>

#include <stdlib.h>
#include <time.h>
/* insert roll() function prototype here */
int roll(int, int*);
int rnd(int);

int main(void)
{
 int histogram[6] = {};
 int i, times;
 srand((unsigned)time(NULL)); /* seed random number generator */
/* initialize all elements of histogram to 0 here */ 
 printf("This program will roll a die and return the measured\n");
 printf("probability of each number appearing.\n");
 printf("How many times should I roll the die? ");
 scanf("%d",&times);
/* insert the commands to roll the die using the function roll()
the appropriate number of times here. Perform the loop over
i in main. roll() should only update the histogram */
 roll(times, histogram);
 printf("The probablility of each number appearing is: \n");
 printf("Number  Probability\n");
 for(i=1; i<=6; i++){
  printf("%d      %d/%d",i,histogram[i-1],times);
  printf("\n");
 }

 return 0;
}
/* insert the appropriate function for roll() here.
Use the function rnd() to generate the random numbers */
int roll(int times1, int z[]){
	int roll1;	
	for(int i=0; i<=times1; i++){
		roll1=rnd(6);
		z[roll1]++;
	}
}

int rnd(int n) // Random number 0..n-1 using high bits of rand()
{
 return (int)((float)n*rand()/(RAND_MAX+1.0));
}
