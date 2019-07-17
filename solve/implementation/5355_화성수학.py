t = int(input())
while t:
    t = t - 1
    a = input().split()
    n = float(a[0])
    for i in a:
        if i == '@':
            n *= 3
        elif i == '#':
            n -= 7
        elif i == '%':
            n += 5
    print("%0.2f" % n)
