l=[input() for _ in range(5)]
j,k,n=0,0,int(input())
c=[input() for _ in range(n)]
m=[]
x=[]
for i in c:
    if i not in x:
        x.append(i)
    else:
        x.remove(i)
for i in x:
    if i==l[j]:
        j+=1
    else:
        m.append(i)
m.extend(l[j:])
print(len(m))
print(*m, sep='\n')