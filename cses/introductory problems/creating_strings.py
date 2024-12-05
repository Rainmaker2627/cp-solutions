from itertools import permutations
s,c=input(),set()
for i in permutations(s):
    if i in c: continue
    c.add(''.join(i))
print(len(c))
for j in sorted(c):
    print(j)