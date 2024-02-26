from math import gcd
from itertools import combinations
n,k=map(int,input().split())
t=[*map(int,input().split())]
def lcm(n):
    if len(n)==1: return n[0]
    elif len(n)==2: return n[0]*n[1]//gcd(n[0],n[1])
    else: return lcm([n[0],lcm(n[1:])])
l=[[lcm(j) for j in combinations(t,i+1)] for i in range(n)]
def f(k,s=0):
    for i in range(n):
        for j in l[i]:
            s+=k//j * (-1)**i
    return s
s,e=0,max(l[0])*k
while s<e:
    h=(s+e)//2
    if f(h)<k: s=h+1
    else: e=h
print(s+2020)