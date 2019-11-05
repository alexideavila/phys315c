#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//have to modify to find smallest odd psuedoprimes
//for all bases 2 through 10
//use nested for loops

long powermod(long,long,long);
long fermat(long,long);
long rnd(long n);
long primeq(long n);

int main(void)
{
  long a=0, p=0;
  int test=0;
  srand((unsigned)time(NULL)); /* seed random number generator */
  printf("This program implements Fermat's Little Theorem to ");
  printf("test if a number p is prime and to find the smallest ");
  printf("odd psuedoprimes for all bases 2 through 10.\n");
//  printf("Enter the number p and base a separated by spaces: ");
//  scanf("%ld %ld",&p,&a);
	for(int i=2; i<=10; i++){
		a = i;
		if(test){
			continue;}
		for(int j=1; j<=1000; j++){
			p=(2*j)+1;
			  if (fermat(a,p)==1) {
 			 		 if (primeq(p)==0){
						printf("%ld is a base-%ld probable prime ",p,a);
 						printf("but it's not prime!\n");
						test=0;
						break;}
 			 		 else continue;
 			 }
 			 else continue;
		}
	}
  printf("\n"); 
 return 0;
}

long fermat(long a, long p)
{
return powermod(a,p-1,p);
}

long powermod(long b, long p, long m)
{
  long res=1;
  while (p>0) {
    if (p%2) {
    res=(res*b)%m;
    p--;
    }
  p/=2;
  b=(b*b)%m;
  }
  return res;
}

long rnd(long n) // Random number 0..n-1 using high bits of rand()
{
  return (long)((float)n*rand()/(RAND_MAX+1.0));
}

long primeq(long n)
// returns 0 if n composite, 1 if strong probable prime
// Modified version of that in the Number Theory Library
{
  long m, x, y, z;
  long i, j, k;
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  if (n == 3) return 1;
  if (n % 3 == 0) return 0;
  if (n == 5) return 1;
  if (n % 5 == 0) return 0;
  if (n == 7) return 1;
  if (n % 7 == 0) return 0;
  m = n - 1;
  k = 0;
  while((m & 1) == 0) {
    m = m >> 1;
    k++;
  }
// n - 1 == 2^k * m, m odd

for (i = 0; i < 10; i++) {
  do {
  x = rnd(n);
  } while (x == 0);
// x == 0 is not a useful candidate for a witness!
  z = powermod(x, m, n);
   if (z == 1) continue;
  j = 0;
  do {
  y = z;
  z = (y*y)%n;
  j++;
  } while (j != k && z != 1);
  if (z != 1 || y != n-1) return 0;
  }
  return 1;
}
