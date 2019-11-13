#include <stdio.h>
#define MAXDIM 10
/* function to take the dot product of two vectors */
float dot(float *, float *, int);

int main(void)
{
 float num, v1[MAXDIM], v2[MAXDIM];
 int size1=0, size2=0, done=1;
 printf("This program will take the dot product of two vectors ");
 printf("of dimension %d or less.\n", MAXDIM);
 printf("Input the elements of the first vector. ");
 printf("Enter \'q\' when done:\n");
 while(1) {
  done=scanf("%f",&num);
 if (!done) break;
 if (++size1>MAXDIM) {
 printf("Vector too large, ignoring last element.\n");
 size1--;
 break;
 }
 v1[size1-1]=num;
 }

/* clear remaining text input still in keyboard buffer */
 while (getchar()!='\n') continue;
 printf("Input the elements of the second vector. ");
 printf("Enter \'q\' when done:\n");
/* another way of getting input. Automatically exits after the
10th input. DON’T put the scanf first! */
 while(size2<MAXDIM && scanf("%f",&v2[size2])==1) size2++;
 if (size1!=size2) printf("Vectors must be of the same size.\n");
 else if (size1==0) printf("No vectors were entered.\n");
 else printf("The dot product of the two vectors is %g.\n",
 dot(v1,v2,size1));
return 0;
}
float dot(float v1[], float v2[], int size)
{
	float dotproduct=0;
	for(int i=0; i<=size; i++){
		dotproduct += (v1[i]*v2[i]);
	}
	return dotproduct;
}
