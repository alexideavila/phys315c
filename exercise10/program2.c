#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define i 10

void linearfit(double*,double*,double*,double*,int*);

int main(){
    srand(time(NULL));
    double first[i];
    double second[i];
    double sigma[i];
    double parameter[5];
    int entries=10;
    for(int j=0; j<entries; j++){
        first[j]=rand() % 11;
        second[j]=rand() % 11;
    }
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

void linearfit(double x[], double y[], double sigma[],
double parameter[], int * entries)
{
/* given x[], y[], sigma[], and entries
fill parameter[] as follows:
parameter[0] = linear coefficient a
parameter[1] = uncertainty in linear coefficient sigma a
parameter[2] = constant coefficient b
parameter[3] = uncertainty in constant coefficient sigma b
parameter[4] = chi-square 
chi-square=The sum from i=1 to N of ((yi-fxi)/sigmai)^2
also
sxy-asxx-bsx=0
sy-asx-bs=0
a=ssxy-sxsy/delta
b=sxxsy-sxsxy/delta
delta=ssxx-sx^2
sigmaa^2=sum of i=1 to N (partialsa/partialsx)^2(sigmai^2) similarly for b
partials of a/partials yi = sxi-sx/sigmai^2 delta
partials of b/partials xi = sxx-sxXi/sigmai^2delta
sigmaa^2=S/delta uncertanity
simgaa = sqrt(s/delta) variants
sigmab = sqrt(sxx/delta)
reduced kai^2 = kai^2/N-2
*/
double s=0, sx=0, sy=0, sxx=0, sxy=0, delta, f;
for(int k=0; k<i; k++){
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
for(int t=0; t<i; t++){
	parameter[4]+=pow(((y[t]-parameter[0]*x[t]-parameter[2])/1),2);
}
/* use a loop to calculate the value of parameter[4] here.
to simplify the logic, use f to hold the current value of
the fitted function: f=parameter[0]*x[i]+parameter[2]
you may use pow() to do the squaring if you wish */
return;
}
