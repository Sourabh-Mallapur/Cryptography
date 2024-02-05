# Extended Euclidean Algorithm in python
def gcd(a,b):
    s1 = 1; s2 = 0; t1 = 0; t2 = 1;
    while(b > 0):
        q = a//b;
        r = a - (q*b);
        s = s1 - (q*s2);
        t = t1 - (q*t2);
        s1 = s2; s2 = s;
        t1 = t2; t2 = t;
        a = b; b = r;
    if (a == 1):
        print("It is a relative prime")
    else:
        print("not a relative Prime")
    return (a, s1, t1)

