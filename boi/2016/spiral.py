q=[[[0, -1, 2, 4, 2], [0, 0, 4, 0, 2]], [[0, -4, 10, 0, 2], [0, 1, 2, -4, 2]]]
r=[[[0, 13, 15, 8], [0, 19, -21, 8]], [[0, 19, 21, 8], [0, 13, -15, 8]]]
def p(p, x):
    return sum(p[i]*x**i for i in range(len(p)))

def t(x, y):
    a,b=x,y
    if abs(x)<abs(y): a,b=b,a
    c=p(q[x>=0][y>=0], abs(b))
    d=abs(b)*(p(r[abs(x)<abs(y)][a>=0],abs(a))-p(r[abs(x)<abs(y)][a>=0],abs(b)))//6
    d+=(abs(a)-abs(b))*(abs(b)-(b>=0))*(abs(b)-(b>=0)+1)//2 *(-1 if (abs(x)<abs(y))^(x>=0)^(y>=0) else 1)
    if y<0<x and -y<x: d-=8*y
    return c+d

mod=10**9+7
n,m=map(int, input().split())
for _ in range(m):
    s=0
    a,b,c,d=map(int, input().split())
    x,y=[a,c+1],[b,d+1]
    for i in range(2):
        for j in range(2):
            s+=t(x[i], y[j])*(-1 if x[0]*x[1]>0 and abs(x[i])<abs(x[1-i]) else 1)*(-1 if y[0]*y[1]>0 and abs(y[j])<abs(y[1-j]) else 1)
    print(s%mod)