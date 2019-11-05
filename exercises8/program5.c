#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long powermod(long,long,long);
long fermat(long,long);
long rnd(long n);
long primeq(long n);

int main(void)
{
  long a, p;
  srand((unsigned)time(NULL)); /* seed random number generator */
  printf("This program implements Fermat's Little Theorem to ");
  printf("test if a number p is prime.\n");
  printf("Enter the number p and base a separated by spaces: ");
  scanf("%ld %ld",&p,&a);
  
  if (fermat(a,p)==1) {
    printf("\n%ld is a base-%ld probable prime ",p,a);
  
  if (primeq(p)==0) printf("but it's not prime!\n");
  else printf("and it's probably prime.\n");
  
  }

  else printf("%ld is composite.\n",p);
  
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
