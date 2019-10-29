#K数定义为：若正整数n可以分割为二个数(不一定是在中间位分割)，
#而这二个数相加之和的平方恰好等于n，那么n就是K数。
#请找出100000以内的全部K数。

print('1=(0+1)**2') #x**2==1的解有且仅有1，下面不再判断这种平凡的情况
for i in range(100001):
    si = str(i)
    for j in range(1, len(si)):
        #print(i, j, end = ' ')
        i1 = int(si[:j:])
        i2 = int(si[j::])
        #print(i1, i2)
        if (i1 + i2) ** 2 == i:
            sol = 1
            break
    else:
        sol = 0
    if sol:
        print('%d=(%d+%d)**2' % (i, i1, i2))
