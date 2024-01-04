b,k=[[0]*9 for _ in range(9)],0
for i in range(13):
    for j in input():
        if j not in ['+', '-', '|']:
            b[k//9][k%9]=(0 if j=='.' else int(j))
            k+=1

def row(i):
    t,d=True,{i: 0 for i in range(1, 10)}
    for j in b[i]:
        if j==0: continue
        d[j]+=1
        t=t and d[j]<2
    return t

def col(i):
    t,d=True,{i: 0 for i in range(1, 10)}
    for j in range(9):
        if b[j][i]==0: continue
        d[b[j][i]]+=1
        t=t and d[b[j][i]]<2
    return t

def square(i):
    t,d=True,{i: 0 for i in range(1, 10)}
    x,y=3*(i%3),3*(i//3)
    for j in range(3):
        for k in range(3):
            if b[j+y][k+x]==0: continue
            d[b[j+y][k+x]]+=1
            t=t and d[b[j+y][k+x]]<2
    return t

a,d=True,{i: 0 for i in range(1, 10)}
for i in range(9):
    a = a and row(i) and col(i) and square(i)

print(["GRESKA", "OK"][a])