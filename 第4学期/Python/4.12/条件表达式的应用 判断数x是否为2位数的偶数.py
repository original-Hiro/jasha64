#判断数x是否为2位数的偶数
x = eval(input('请输入一个数:'))
if not x % 2 and 10 <= x <= 99: #等价于C语言的if (!(x % 2))
#if x in range(10, 100, 2):
    print('Yes')
else:
    print('No')
