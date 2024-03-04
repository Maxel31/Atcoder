N = int(input())
A = list(map(int, input().split()))

s, m= 0, 0
for x in A:
    s += x
    m = min(m, s) # 最小値の更新
    
print(s - m) # mが0になるように調整