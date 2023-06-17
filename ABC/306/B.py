def binary_to_decimal(binary):
    decimal = 0
    power = 0

    for bit in binary:
        if bit == '1':
            decimal += 2**power
        power += 1

    return decimal

# 入力の受け取り
input_binary = input().strip().replace(' ', '')

# 64桁の2進数を10進数に変換 # 末尾から処理するために逆順にする
decimal = binary_to_decimal(input_binary)

print(decimal)
