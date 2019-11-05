#include <stdio.h>
#include <math.h>

int prime1(int);
int prime2(int);
int prime3(int);
int prime4(int);

int main(void)
{
	int n=100;
	printf("This program finds the prime numbers less than %d ",n);
	printf("four different ways.\n\n");
	printf("\nMethod 1 took %d mods.\n\n",prime1(n));
	printf("\nMethod 2 took %d mods.\n\n",prime2(n));
	printf("\nMethod 3 took %d mods.\n\n",prime3(n));
	printf("\nMethod 4 took %d mods.\n\n",prime4(n));
	return 0;
}

int prime1(int n)
{
	int i,j;
	int count=0;
	for (i=1;i<=n;i++) {
		for (j=2;j<i;j++) {
			count++;
				if (i%j==0) break;
			}
		if (j==i) printf("%d, ",i);
		}
	return count;
}

int prime2(int n)
{
	int i,j;
	int count=0;
	printf("%d, ",2); /* only even prime */
	for (i=3;i<=n;i+=2) {
		for (j=3;j<i;j+=2) {
			count++;
		if (i%j==0) break;
		}
		if (j==i) printf("%d, ",i);	
	}
	return count;
}

int prime3(int n)
{
	int i,j;
	int root;
	int count=0;
	for (i=2;i<=n;i++) {
		root=sqrt((double)i);
			for (j=2;j<=root;j++) {
				count++;
				if (i%j==0) break;
				}
		if (j>root) printf("%d, ",i);
		}
	return count;
}

int prime4(int n)
{
	int i,j;
	int root;
	int count=0;
	printf("%d, ",2);
	for (i=3;i<=n;i+=2) {
		root=sqrt((double)i);
		for (j=3;j<=root;j+=2) {
			count++;
			if (i%j==0) break;
			}
		if (j>root) printf("%d, ",i);
		}
	return count;
}
