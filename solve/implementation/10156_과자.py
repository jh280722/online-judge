a, b, c = map(int, input().split())
if a * b > c:
    print(eval(str(a) + '*' + str(b) + '-' + str(c)))
else:
    print("0")
