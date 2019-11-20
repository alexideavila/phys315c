#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAXDATA 100

void readfile(double*, double*, double*, int*);
void linearfit(double*,double*,double*,double*,int*);

int main(){
    srand(time(NULL));
    double first[MAXDATA];
    double second[MAXDATA];
    double sigma[MAXDATA];
    double parameter[5];
    int entries;
    readfile(first,second,sigma,&entries);
    linearfit(first,second,sigma,parameter,&entries);
	printf("x  y\n");
	for(int m=0; m<entries; m++){
		printf("%g  %g\n",first[m],second[m]);
	}
	printf("The A-value is: %g\n", parameter[0]);
	printf("The B-values is: %g\n", parameter[2]);
	printf("The Sigma A and B value is: %g %g\n", parameter[1],parameter[3]);
	printf("The Chi Square values is: %g\n",parameter[4]);
	return 0;
}


void readfile(double x[], double y[], double sigma[], int * entries)
{
/* read data into x[] and y[]
fill sigma[] with 1's
determine the value of entries */
    char name[40];
    FILE *data;
    *entries=0;
    printf("Enter the name of the data file: ");
    scanf("%40s",name);
    if ((data=fopen(name,"r"))==NULL) {
        printf("Can't open file %s.\n",name);
        exit(1); // Exits program
    }
// Assume data file contains 2 columns of data with no header
    while (*entries<MAXDATA &&
    fscanf(data,"%lf %lf",&x[*entries],&y[*entries])==2) {
    sigma[*entries]=1;
    (*entries)++;
    }
    if (fclose(data)) printf("Error in closing data file.\n");
    return;
}

void linearfit(double x[], double y[], double sigma[],
double parameter[], int * entries)
{
double s=0, sx=0, sy=0, sxx=0, sxy=0, delta, f;
for(int k=0; k<*entries; k++){
	sigma[k]=1;
	s+=1/pow(sigma[k],2);	
	sx+=x[k]/pow(sigma[k],2);
	sy+=y[k]/pow(sigma[k],2);
	sxx+=pow(x[k],2)/pow(sigma[k],2);
	sxy+=(x[k]*y[k])/pow(sigma[k],2);
}
delta=s*sxx-sx*sx;
parameter[0]=(s*sxy-sx*sy)/delta;//a
parameter[1]=sqrt(s/delta);//sigma a
parameter[2]=(sxx*sy-sx*sxy)/delta;//b
parameter[3]=sqrt(sxx/delta);//sigma b
/* calculate the values of parameter[0] through parameter[3]
here */
parameter[4]=0;
for(int t=0; t<*entries; t++){
	parameter[4]+=pow(((y[t]-parameter[0]*x[t]-parameter[2])/sigma[t]),2);
}
return;
}

