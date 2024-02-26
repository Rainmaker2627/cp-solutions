def solve():
    s,w=[],[]
    for i in range(int(input())):
        s.append([*map(int, input().split())])
    s.sort()
    a=n=0;b=100000000000000
    for i in s:
        a=i[0]
        if b<a:
            w.append(b)
            b=i[1]
            n+=1
        else:
            b=min(b,i[1])
    print(n+1)
    print(*w,a)
solve()