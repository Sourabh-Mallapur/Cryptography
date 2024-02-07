#include <stdio.h>
#include "../gcd/gcd.h"

// solutions of linear diophantine eqaution

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
  
  // divide whole eqaution by d
  int a2 = a/d;
  int b2 = b/d;
  gcd(a2,b2,&temp,&s,&t);
  
   // particular solution
  int x0 = (c/d)*s;
  int y0 = (c/d)*t;

  // genral solutions
  printf("the solutions are - \n");
  printf("x = %d + %dk\n",x0,(b/d));
  printf("x = %d - %dk",y0,(a/d));
}