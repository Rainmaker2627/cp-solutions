from math import inf
from collections import deque
n,m,a,b=map(int,input().split())
e=[[] for _ in range(n)]
for _ in range(m):
    p,q=map(int,input().split())
    e[p-1].append(q-1)
    e[q-1].append(p-1)
def bfs(a):
    s=[inf]*n
    q=deque()
    q.append([a,0])
    s[a]=0
    while q:
        v,d=q.popleft()
        for i in e[v]:
            if s[i]==inf:
                s[i]=d+1
                q.append([i, d+1])
    return s
x,y=bfs(a-1),bfs(b-1)
p,q=inf,0
for i in range(n):
    if (max(x[i],y[i])<p):
        p,q=max(x[i],y[i]),i
print(q+1)