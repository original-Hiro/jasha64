#程序产生100个1到20之间的随机整数并分行显示，每行显示的个数由用户指定。
#每个数占4位，右对齐。
import random
ansTable = [random.randint(1, 20) for i in range(100)]

ll = int(input('请输入每行显示的个数:'))
for i in range(0, 100, ll):
    for x in ansTable[i: i+ll]: #部分序列→切片
        print('%4d' % x, end = '')
    print()
