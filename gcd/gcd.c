#include "gcd.h"

int main() {
  int d,s,t,a,b;
  printf("Enter value of a: ");
  scanf("%d",&a);
  printf("Enter value of b: ");
  scanf("%d",&b);
  gcd(a,b, &d, &s, &t);
  printf("gcd = %d, s = %d, t = %d\n",d, s, t);
  return 0;
}