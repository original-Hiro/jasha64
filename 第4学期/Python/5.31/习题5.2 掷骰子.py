#掷两个骰子。每个骰子有六个面，分别表示值1、2、…、6。
#检查两个骰子的和。如果和为2、3和12，你就输了；如果和为7或11，你就赢了；
#如果和是其他数字(4、5、6、8、9或10)，就确定了一个点数，
#继续掷骰子，直到掷出一个7或者掷出与第一次相同的点数，
#如果掷出的是7，你就输了，如果掷出的点数与第一次掷出的点数相同，你就赢了。
#输一次或赢一次算一局。最后统计胜率以及平均每局投骰子的次数。

import random
rnd = eval(input('请输入要玩的局数：'))
totcnt = 0
win = 0
for i in range(1, rnd+1):
    print('第%d局：' % i, end = '')
    cnt = 0
    
    d1 = random.randint(1, 6)
    d2 = random.randint(1, 6)
    cnt += 1
    print('（%d,%d）' % (d1, d2), end = '')
    
    initsum = d1 + d2
    if initsum in (2, 3, 12):
        print('You Lose.', end = ' ')
        win += 1
    elif initsum in (7, 11):
        print('You Win.', end = ' ')
    else:
        while True:
            d1 = random.randint(1, 6)
            d2 = random.randint(1, 6)
            cnt += 1
            print('（%d,%d）' % (d1, d2), end = '')

            cursum = d1 + d2
            if cursum == initsum:
                print('You Win.', end = ' ')
                win += 1
                break
            elif cursum == 7:
                print('You Lose.', end = ' ')
                break
    
    print('投骰子%d次！' % cnt)
    totcnt += cnt

print('胜率：%.2f，平均每局投骰子%d次。' % (win/rnd, round(totcnt/rnd)))
