#用户随意输入一串字符，程序依次在相邻位置插入一个空格，逐行输出。
iStr = input('请输入：')

Res = []
for pos in range(1, len(iStr)):
    Res.append(' '.join([iStr[:pos:], iStr[pos::]])) #感谢切片

for each in Res[::-1]: #再次感谢切片
    print(each)
print('-----')
for each in Res:
    print(each)
