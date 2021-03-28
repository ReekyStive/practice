from typing import List


raw = input().strip().split(' ')

a = []
for i in range(3):
    raw = input().strip().split(' ')
    a.append([int(x) for x in raw])
    a[i].sort()

m = 1
for i in range(3):
    for item in a[i]:
        if item > m:
            m = item


def next(last: List, cur: List) -> List:
    point = last[0]
    count = len(last)
    for i in range(point + 1, m + 1):
        if (cur.count(i) >= count):
            return [i for j in range(count)][:]
    for i in range(1, point + 1):
        if (cur.count(i) >= count + 1):
            return [i for j in range(count + 1)][:]
    return None


last = [0]
last_index = 0

running = True
while running:
    for i in range(3):
        cur_list = a[i]
        cur = next(last, cur_list)

        if (last_index == i):
            cur = next([0], cur_list)
            # print("[debug] #{}: new round".format(i + 1))
        elif (cur == None):
            # print("[debug] #{}: pass".format(i + 1))
            continue

        point = cur[0]
        count = len(cur)
        for j in range(count):
            cur_list.remove(point)

        last = cur[:]
        last_index = i
        # print("[debug] #{}: {}".format(i + 1, cur))

        if (len(cur_list) == 0):
            # print("[debug] #{}: won".format(i + 1))
            print(i + 1)
            running = False
            break
