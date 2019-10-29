#用户任意输入10个数，
#程序统计如下三个量：
#正数之和，负数之和，零的个数。

posList = []
negList = []
zeroCnt = 0

print('请每行输入一个数:')
for i in range(10):
    x = eval(input())
    if x < 0: negList.append(x)
    elif x == 0: zeroCnt = zeroCnt + 1
    else: posList.append(x)

print('正数之和为：', sum(posList)) #按无格式数输出，此时输出的数的类型由参与运算的操作数决定
print('负数之和为：', sum(negList))
print('共有%d个零' % zeroCnt)
