#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define i 10
void linearfit(double*,double*,double*,double*,int);

int main(){
    srand(time(NULL));
    double first[i];
    double second[i];
    double sigma[i];
    double parameter[i];
    int entries=10;
    for(int j=0; j<10; j++){
        first[j]=rand() % 11;
        second[j]=rand() % 11;
    }
    linearfit(first,second,sigma,parameter,entries);
    return 0;
}

void linearfit(double x[], double y[], double sigma[],
double parameter[], int entries)
{
/* given x[], y[], sigma[], and entries
fill parameter[] as follows:
parameter[0] = linear coefficient
parameter[1] = uncertainty in linear coefficient
parameter[2] = constant coefficient
parameter[3] = uncertainty in constant coefficient
parameter[4] = chi-square */
double s=0, sx=0, sy=0, sxx=0, sxy=0, delta, f;
int k;
/* use a loop to calculate the values of s, sx, sy,
sxx, and sxy here */
delta=s*sxx-sx*sx;
/* calculate the values of parameter[0] through parameter[3]
here */
parameter[4]=0;
/* use a loop to calculate the value of parameter[4] here.
to simplify the logic, use f to hold the current value of
the fitted function: f=parameter[0]*x[i]+parameter[2]
you may use pow() to do the squaring if you wish */
return;
}