#条件：用户会输入正整数；第一个数会较小；输入两数的奇偶性随意
#要求：最终各个随机偶数出现的百分比必须相近似

iStr = input('请输入两个数，以空格分隔：')
iList = iStr.split()
a, b = eval(iList[0]), eval(iList[1])
print('产生2000000个%d~%d之间的随机偶数...统计如下:' % (a, b))

import random
a = (a+1) // 2 #下界, inclusive
b = b // 2 #上界, inclusive
cnt = dict()
for i in range(2000000):
    x = random.randint(a, b) * 2
    cnt[x] = cnt.get(x, 0) + 1

print('数值   次数     百分比')
for i in range(a, b+1):
    j = i*2
    print('%-6d%-8d%.2f%%' % (j, cnt.get(j, 0), cnt.get(j, 0) / 2000000 * 100))
