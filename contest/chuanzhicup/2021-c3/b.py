raw = input().strip().split(' ')
n = int(raw[0])
k = int(raw[1])

raw = input().strip().split(' ')
a = [int(x) for x in raw]

res = 0
for i in range(n):
    for j in range(i + 1, n):
        if a[i] * a[j] <= k:
            res += 1

print(res)
