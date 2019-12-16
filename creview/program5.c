#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float ran1(long *);
long rnum; /* global variable for randum number generator */

int main(){
	int darts;
	float x,y;//this is my random number
	int ahashed=0;
	double e,f;

	rnum=-time(NULL);
	ran1(&rnum); /* seed generator */
	
	printf("How many darts: ");
	scanf("%d", &darts);	
	
	for(int i=0; i<darts; i++){
		y=2*ran1(&rnum);
		x=ran1(&rnum);
		if(pow(2,x)<=y){
			continue;
		}
		else ahashed++;
	}
	f=(double)ahashed/(double)darts;
	e=pow(2, 2*f);
	printf("The approx e is: %g\n", e);
	return 0;
}

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
float ran1(long *idum)
{
	int j;
	long k;
	static long iy=0;
	static long iv[NTAB];
	float temp;
	if (*idum<=0 || !iy) {
		if (-(*idum)<1) *idum=1;
		else *idum= -(*idum);
			for (j=NTAB+7;j>=0;j--) {
			k=(*idum)/IQ;
			*idum=IA*(*idum-k*IQ)-IR*k;
			if (*idum<0) *idum+=IM;
			if (j<NTAB) iv[j]= *idum;
		}
		iy=iv[0];
	}
	k=(*idum)/IQ;
	*idum=IA*(*idum-k*IQ)-IR*k;
	
	if (*idum<0) *idum+=IM;
		j=iy/NDIV;
		iy=iv[j];
		iv[j]= *idum;
	if ((temp=AM*iy)>RNMX) return RNMX;
	else return temp;
}
