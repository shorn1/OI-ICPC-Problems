n = int(input())
t = input().split()
a = int(t[0])
v = []
for i in range(0,n):
    s = input().split()
    v.append((int(s[0]),int(s[1])))
v.sort(key=lambda x: x[0] * x[1])
res = 0
for i in range(0,n):
    k = a // (v[i])[1]
    if(k > res):
        res = k
    a *= (v[i])[0]
print(res)