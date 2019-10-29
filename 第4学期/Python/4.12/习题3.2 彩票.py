import random

def cnt(x, cnt):
    cnt[x // 100] += 1 #百位
    cnt[x % 10] += 1 #个位
    cnt[x // 10 % 10] += 1 #十位
    
def pp(x, y): #匹配
    cntx = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    cnt(x, cntx)
    cnty = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    cnt(y, cnty)
    
    tpp = 0 #总匹配位数
    for i in range(0, 10):
        tpp += min(cntx[i], cnty[i])
    if tpp == 3:
        print('匹配所有数字：你赢得3,000元。')
    elif tpp == 1:
        print('匹配一个数字：你赢得1,000元。')
    else:
        print('很抱歉，没有中奖。')

def main():
    priz = random.randint(100, 999)

    cp = eval(input('请输入你的彩票号码(三位数)：'))
    print('中奖号是', priz)
    if cp < 100 or cp >= 1000:
        print('无效输入')
    elif cp == priz:
        print('完全匹配：你赢得10,000元。')
    else:
        pp(priz, cp)

if __name__ == '__main__':
    main()
