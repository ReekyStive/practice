t = int(input())

for k in range(t):
    data = input().strip().split(' ')
    data = [int(x) for x in data]
    l1, r1, l2, r2 = data[0], data[1], data[2], data[3]

    a = 1
    for i in range(l1, r1 + 1):
        a *= i
    b = 1
    for i in range(l2, r2 + 1):
        b *= i

    if (b // a) * a == b:
        print('Yes')
    else:
        print('No')
