a = input()
op = input()
b = input()
if op == '+':
    if len(a) > len(b):
        n = a[0:len(a) - len(b)] + '1'
        n += a[len(a) - len(b) + 1:]
        print(n)
    elif len(a) == len(b):
        n = '2'
        n += a[1:]
        print(n)
    else:
        n = b[0:len(b) - len(a)] + '1'
        n += b[len(b) - len(a) + 1:]
        print(n)
else:
    if len(a) > len(b):
        for i in range(1, len(b)):
            a += '0'
        print(a)
    else:
        for i in range(1, len(a)):
            b += '0'
        print(b)
# 파이썬 eval은 문자열로 계산하나보다 아래 한줄로 끝
# print(eval(input()+input()+input()))
