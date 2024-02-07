#include "gcd\gcd.c"

int main() {
  int d,s,t;
  gcd(348, 846, &d, &s, &t);
  printf("gcd = %d, s = %d, t = %d\n",d, s, t);
  return 0;
}