n, m = 20, 7
x = [None] * n
y = [6, 13, 0, 8, 16, 4, 14, 3, 15, 7,\
     19, 12, 10, 9, 11, 18, 5, 17, 1, 2]
z = list(range(20))

cur = 0
for each in y:
    cur = (cur + m - 1) % len(z)
    x[z.pop(cur)] = each

print(x)
