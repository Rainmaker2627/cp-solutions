import sys
sys.setrecursionlimit(1000001)
mod=1000000007

n,k=map(int, input().split())
n+=1
a=[*map(int, input().split())]
imp=[False]*n
for i in a:
    imp[i]=True

g=[[] for _ in range(n)]
for i in range(n-2):
    t,b,c=map(int, input().split())
    g[t].append([b, c])
    g[b].append([t, c])

m,s,s2,l,q=[0]*n,[0]*n,[0]*n,[0]*n,[0]*n

def dfs1(u, p):
    if (imp[u]):
        m[u]+=1
    for v, w in g[u]:
        if v==p:
            continue
        dfs1(v, u)
        s[u]=(s[u]+(m[v]*w)%mod+s[v]%mod)%mod
        s2[u]=(s2[u]+(m[v]*w)%mod*w%mod+s2[v]+(2*s[v]%mod*w)%mod)%mod
        m[u]=(m[u]+m[v])%mod;
    
def dfs2(u, p):
    for v, w in g[u]:
        if (v==p):
            continue
        l[v]=(l[u]+w*(k-2*m[v])%mod)%mod
        q[v]=(q[u]+2*w%mod*(l[u]-2*s[v])%mod+(k-4*m[v])*(w*w%mod)%mod)%mod
        dfs2(v, u)
    
dfs1(1,1)
l[1]=s[1]
q[1]=s2[1]
dfs2(1,1)

x=y=0
for i in a:
    x+=l[i]
    y+=q[i]
x=(x*500000004)%mod
y=(y*500000004)%mod
print(x)
print(y)