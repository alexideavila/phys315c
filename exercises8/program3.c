#include <stdio.h>
#include <math.h>

int gcd(int,int);

int main(void)
{
  int n;
  int max, a, b, c;
  int sum, cn;
  printf("Enter the desired exponent: ");
  scanf("%d",&n);
  printf("Enter the maximum value to search: ");
  scanf("%d",&max);
  for (a=1;a<=max;a++) {
    for (b=a+1;b<=max;b++) {
      if (gcd(a,b)>1) continue;
        sum=pow((double)a,n)+pow((double)b,n);
          for (c=b+1;c<=max;c++) {
            cn=pow((double)c,n);
              if (cn==sum) printf("%d^%d + %d^%d = %d^%d\n",
            a,n,b,n,c,n);
            if (cn>=sum) break;
    }
  }
}

return 0;
}
int gcd(int m, int n)
{
  int r;
  while ((r=m%n)!=0) { /* while (r=m%n) would work, but it could
    be easily mistaken as (r==m%n) */
    m=n;
    n=r;
    }
  return n;
}
