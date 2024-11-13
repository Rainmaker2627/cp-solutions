n,a,b=[*map(int, input().split())]
dp=[1]+[0]*(6*n)
for i in range(n):
    for j in range(6*i, i-1, -1):
        for k in range(1, 7):
            dp[j+k]+=dp[j]
        dp[j]=0

s=t=0
for i in range(6*n+1):
    if a<=i<=b: s+=dp[i]
    t+=dp[i]

print(f"{s/t:.6f}")