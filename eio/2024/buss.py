from math import inf
H,M=map(int, input().split())
t=60*H+M
x,y=-inf,-1
n=int(input())
for i in range(n):
    h,m,j=map(int, input().split())
    if x<60*h+m-t-j:
        x=60*h+m-t-j
        y=i+1
print("JAH" if x>=0 else "EI")
print(y)