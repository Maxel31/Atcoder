H,W,N = map(int, input().split())
s = [["." for j in range(W)] for i in range(H)]
dy = [-1,0,1,0]
dx = [0,1,0,-1]

y,x,d = 0,0,0

for _ in range(N):
    if s[y][x] == ".":
        s[y][x] = "#"
        d = (d+1)%4
    else:
        s[y][x] = "."
        d = (d-1)%4
    y = (y+dy[d])%H
    x = (x+dx[d])%W

for r in s:
    print("".join(r))