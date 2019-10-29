x = [7, 5, 4, 7, 3, 3, 5, 3, 7]
print('删除前:', x)

i = 1
while i < len(x):
    if x[i] in x[:i]:
        x.pop(i)
    else:
        i = i+1

print('删除后:', x)
