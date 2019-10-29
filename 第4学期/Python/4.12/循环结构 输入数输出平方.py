#用户输入一个数，程序输出其平方数；
#重复上述过程，当用户输入0时程序才退出。
x = eval(input('请输入一个数：'))
while x:
    print(x, '的平方值是', x*x)
    x = eval(input('请输入一个数：'))
print('Goodbye!')
