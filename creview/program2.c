#include <stdio.h>
#define MAXDATA 100
	
int main(){
	char option=0;
	int count=0;
	float average=0;
	int scores[MAXDATA];	
	
	printf("Enter some lab grades: ");//entering data
	while(scanf("%d", &scores[count])){
		
		count++;
	}
	int min=0;
	int minValue=scores[0];
	//checking data for lowest value of scores
	for(int j=0; j<count; j++){
		if (minValue>scores[j]){
			min=j;
			minValue=scores[j];
		}
		else {
			continue;
		}
	}
	//checking for min value of data
	printf("%d scores were entered\n",count);
	printf("%d score was discarded\n",scores[min]);
	printf("The average of %d scores is: ", (count-1));
	
	for(int d=0; d<count; d++){
		if(d!=min){
			average+=scores[d];
		}		
		else continue;
	}
	printf("%g\n", average/(count-1));
	return 0;
}
