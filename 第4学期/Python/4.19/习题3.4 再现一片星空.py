#输入任意一个正整数，显示相应大小的菱形
n = int(input('请输入n:'))

#先用矩阵存储打印图案的对称的上半部分
Res = []
for i in range(n):
    cStr = '  ' * (n-i) + '* ' * (i*2+1)
    Res.append(cStr)
else:
    cStr = '* ' * (n*2+1)
    Res.append(cStr)

for i in range(n+1):
    print(Res[i])
for i in range(1, n+1):
    print(Res[n-i])
