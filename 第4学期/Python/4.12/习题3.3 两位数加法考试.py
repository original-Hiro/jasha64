import random
n = eval(input('你想做几道题？'))
res = 0
i = 0
while i < n:
    a = random.randint(10, 100)
    b = random.randint(10, 100)
    c = eval(input('第%d道：%d + %d = ? ' % (i, a, b)))
    if c == a+b:
        print('答对了！加1分。')
        res += 1
    else:
        print('答错了！不得分。正确答案是%d。' % (a + b))
    i += 1
print('你做了%d道题，共答对了%d道。' % (n, res))

