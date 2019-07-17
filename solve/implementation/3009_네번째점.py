a = input().split()
b = input().split()
c = input().split()
x = a[0]
y = a[1]
if x == b[0]:
    x = c[0]
elif x == c[0]:
    x = b[0]

if y == b[1]:
    y = c[1]
elif y == c[1]:
    y = b[1]
print(x, y)
