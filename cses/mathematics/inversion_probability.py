# im not dealing with rounding problems in c++
from math import gcd
n=int(input())
r=[*map(int, input().split())]

a,b=0,1
for i in range(n):
    for j in range(i+1, n):
        p,q=r[i]*(r[i]-1)//2,r[i]*r[j]
        if (r[j]<r[i]): p-=(r[i]-r[j])*(r[i]-r[j]-1)//2
        a,b=a*q+b*p,b*q
        g=gcd(a,b)
        a,b=a//g,b//g

print(f"{a/b:.6f}")