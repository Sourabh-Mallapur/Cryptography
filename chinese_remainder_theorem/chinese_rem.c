// implement chinese remainder theorem
// for 3 congruence equations
#include <stdio.h>

void inverse(int a, int b, int *inv) {
    int t1 = 0, t2 = 1;
    int q,r,t;
    while(b > 0) {
    q = a/b;
    r = a - (q*b);
    t = t1 - (q*t2);
    t1 = t2; t2 = t;
    a = b; b = r;
    }
    *inv = t1;
    if(*inv < 0) *inv += t2;
}

void chinese_rem(int a1, int a2, int a3, int m1, int m2, int m3) {
    int M,M1,M2,M3,M1i,M2i,M3i;
    M = m1*m2*m3;
    M1 = M/m1; M2 = M/m2; M3 = M/m3;
    inverse(m1,M1,&M1i);
    inverse(m2,M2,&M2i);
    inverse(m3,M3,&M3i);
    int sum = (a1*M1*M1i) + (a2*M2*M2i) + (a3*M3*M3i);
    printf("Common Remainder is: %d",sum%M); 
}

void main() {
    int a1,a2,a3;
    int m1,m2,m3;
    printf("Enter value of a1: ");
    scanf("%d",&a1);
    printf("Enter value of a2: ");
    scanf("%d",&a2);
    printf("Enter value of a3: ");
    scanf("%d",&a3);
    printf("Enter value of m1: ");
    scanf("%d",&m1);
    printf("Enter value of m2: ");
    scanf("%d",&m2);
    printf("Enter value of m3: ");
    scanf("%d",&m3);
    chinese_rem(a1,a2,a3,m1,m2,m3);
}