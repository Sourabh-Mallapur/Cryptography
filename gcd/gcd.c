// Extended Euclidean Algorithm in C
#include <stdio.h>

void gcd(int, int);

void gcd(int a,int b) {
  int s1 = 1, s2 = 0, t1 = 0, t2 = 1;
  int q,r,s,t;
  while(b > 0) {
    q = a/b;
    r = a - (q*b);
    s = s1 - (q*s2);
    t = t1 - (q*t2);
    s1 = s2; s2 = s;
    t1 = t2; t2 = t;
    a = b; b = r;
    }
  if (a == 1)
    printf("It is a relative prime\n");
  else
    printf("not a relative Prime\n");
  printf("gcd = %d, s = %d, t = %d\n",a, s1, t1);
}