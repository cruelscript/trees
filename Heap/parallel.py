from heapq import heapreplace

P = [(0, i) for i in range(int(input().split()[0]))]
for t in map(int, input().split()):
    print(*reversed(heapreplace(P, (P[0][0] + t, P[0][1]))))
