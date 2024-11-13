from bisect import bisect
n,q=map(int,input().split())
i,f=2,[1,n]
while i*i<=n:
    if n%i==0: f.extend([i, n//i])
    i+=1
f.sort()
for i in range(q):
    a,b=map(int,input().split())
    c=bisect(f,b)-1
    if b==n: print(1)
    elif a<=f[c]<=b: print(n//f[c])
    else: print(-1)