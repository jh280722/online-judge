h, m = input().split()
h = int(h)
m = int(m)
p = int(input())
if m + p >= 60:
    h = int(h + (m + p) / 60)
    m = int((m + p) % 60)
else:
    m = m + p
if h >= 24:
    h = int(h % 24)
print(h, m)
