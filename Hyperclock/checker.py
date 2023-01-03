UP = 1
DOWN = -1

n = int(input())
a = [int(input()) for _ in range(n)]

visited = set()

cur = [0 for _ in range(n)]

prod = 1
for k in a:
    prod *= k

for _ in range(prod):
    id_, d = map(int, input().split())
    id_ -= 1
    if d == UP:
        cur[id_] += 1
        cur[id_] %= a[id_]
    else:
        if cur[id_] > 0:
            cur[id_] -= 1
        else:
            cur[id_] = a[id_]-1
    t_cur = tuple(cur)
    print(t_cur)
    assert t_cur not in visited
    visited.add(t_cur)

assert len(visited) == prod
