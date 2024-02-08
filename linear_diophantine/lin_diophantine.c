// solutions of linear diophantine eqaution
#include <stdio.h>
#include "../gcd/gcd.h"

void main() {
  int a,b,c,d,temp,s,t;
  printf("Enter value of a: ");
  scanf("%d",&a);
  printf("Enter value of b: ");
  scanf("%d",&b);
  printf("Enter value of c: ");
  scanf("%d",&c);
  
    // find gcd of a,b
  gcd(a,b,&d,&s,&t);
  printf("%d %d %d\n",d,s,t);
  
  if (!(c % d)) {
    // divide whole eqaution by d
    int a2 = a/d;
    int b2 = b/d;
    gcd(a2,b2,&temp,&s,&t);
    printf("%d %d %d\n",temp,s,t);
  
    // particular solution
    int x0 = (c/d)*s;
    int y0 = (c/d)*t;

    // general solutions
    printf("the general solutions are - \n");
    printf("x = %d + %dk\n",x0,(b/d));
    printf("y = %d - %dk\n",y0,(a/d));
  }
  else printf("NO Solutions");
}