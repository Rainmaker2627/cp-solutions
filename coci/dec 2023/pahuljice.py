n,m=map(int, input().split())
s,c=[input() for _ in range(n)],[]
for i in range(n):
    for j in range(m):
        if s[i][j]=='+':
            c.append([i, j])

def size(x, y):
    # too lazy to write better code
    t,p=[],0
    for i in range(x-1, -1, -1):
        if s[i][y]=='|':
            p+=1
        else: break
    t.append(p)
    p=0
    for i in range(x+1, n):
        if s[i][y]=='|':
            p+=1
        else: break
    t.append(p)
    p=0
    for i in range(y-1, -1, -1):
        if s[x][i]=='-':
            p+=1
        else: break
    t.append(p)
    p=0
    for i in range(y+1, m):
        if s[x][i]=='-':
            p+=1
        else: break
    t.append(p)
    p=0
    for i in range(1, min(n-x-1, y)+1):
        if s[x+i][y-i]=='/':
            p+=1
        else: break
    t.append(p)
    p=0
    for i in range(1, min(x, m-y-1)+1):
        if s[x-i][y+i]=='/':
            p+=1
        else: break
    t.append(p)
    p=0
    for i in range(1, min(n-x-1, m-y-1)+1):
        if s[x+i][y+i]=='\\':
            p+=1
        else: break
    t.append(p)
    p=0
    for i in range(1, min(x, y)+1):
        if s[x-i][y-i]=='\\':
            p+=1
        else: break
    t.append(p)
    return min(t)

a=0
for i in c:
    a=max(a, size(i[0], i[1]))
print(a)