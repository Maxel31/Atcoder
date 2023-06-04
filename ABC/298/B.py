import numpy as np

n = int(input())
a_ = [list(map(int, input().split())) for _ in range(n)]
b_ = [list(map(int, input().split())) for _ in range(n)]

a = np.array(a_)
b = np.array(b_)

for i in range(4):
    if np.min(b - a) >= 0:
        print('Yes')
        exit()
        
    a = np.rot90(a)       

print('No')