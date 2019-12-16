#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void writeFile(float, float, float, int*);
float ran1(long *);
long rnum;// random number generator

int main(){
	//simulate Radioactive Decay
	float initialCount;
	float finalCount, r;
	int test[10];
	int numtests=500000;
	int i, entries, timeTotal, timeFinal; 
	float alpha, dtime;

	rnum=-time(NULL);
	ran1(&rnum); // seed generator

	printf("This is a program that simulates Radioactive Decay\n");
	printf("Please enter an initial Count of your Radioactive substance: ");
	scanf("%g", &initialCount);
	printf("Please enter the decay rate: ");
	scanf("%g", &alpha);
	printf("The time steps: ");
	scanf("%g", &dtime);
	printf("And enter the total time for it to decay: ");
	scanf("%d", &timeFinal);
	
	float n[timeFinal];
	
	printf("     n0    alpha(s^-1) dtime(s) T(s)\n");
	printf("-------------------------------------\n");
	finalCount = initialCount;
	n[0]=initialCount;
	for(timeTotal=dtime; timeTotal<=timeFinal; timeTotal+=dtime){
		initialCount = finalCount;
		for (i=0;i<10;i++) test[i]=0;
		for (i=1;i<=numtests;i++) {
			r=ran1(&rnum);
			test[(int)(10*r)]++;
		}
		for(int j =1; j<=initialCount; j++){
			if(ran1(&rnum)<alpha*dtime){ 			
				finalCount--;
			}
		}
		n[timeTotal]=finalCount;
		printf(" %6g %12g %5g %7d \n", finalCount, alpha, dtime, timeTotal);
	}
	int t[timeTotal];
	for (int k=1; k<=timeTotal; k++){
		t[k-1]=k;
	}
	char name[40];
	FILE *data;
	int num=0;
	printf("Enter the name of the data file: ");
	scanf("%40s", name);
	if((data=fopen(name, "w"))==NULL){
		printf("Can't open file %s. \n", name);
		exit(1);
	}
	while(num<(timeTotal-1) && fprintf(data, "%d %g\n", t[num], n[num])){
		num++;
	}
	if(fclose(data)) printf("Error in closing data file.\n");
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
