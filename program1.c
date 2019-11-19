#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 100
void readfile(double*, double*, double*, int *);

int main(){
    double firstColumn[MAXDATA];
    double secondColumn[MAXDATA];
    double sigmaStuff[MAXDATA];
    int * entries;
    readfile(firstColumn,secondColumn,sigmaStuff,entries);
    
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