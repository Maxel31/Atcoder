# 入力
N = int(input())
# Sは文字列
S = input()
T = input()

# 判定
for i in range(N):
    if (S[i] == T[i] or (S[i] == '1' and T[i] == 'l') or (S[i] == 'l' and T[i] == '1') or (S[i] == 'o' and T[i] == '0') or (S[i] == '0' and T[i] == 'o')):
        continue
    else:
        print("No")
        exit()

print ("Yes")