#消除一列数中的重复值，
#要求采用两种方法实现，
#一种要求显示的顺序必须与原顺序一致，
#另一种采取不同的方法，但不要求保留顺序。

ins = input('请输入一列数，以空格分隔：')
s = [eval(x) for x in ins.split()] #获得输入的各项（缺省情况下是空格分隔）

s1 = set(s)
print('不保持顺序的结果：', end = '')
for x in s1:
    print(x, end = ' ')
print('')

s2 = []
for x in s:
    if x not in s2:
        s2.append(x)
print('保持顺序的结果：', end = '')
for x in s2:
    print(x, end = ' ')
