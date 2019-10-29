s = "A takes 30 min, B takes 19 sec, and C takes 26 ms."
pat = r"(\d+) (min|sec|ms)"

import re
reg = re.compile(pat)
matched = reg.search(s)
times = 1

while matched:
    print('第%d次匹配' % times)
    for i in range(3): #三种子模式
        print('模式%d匹配到的内容：' % i, end = ' ') #0表示整个模式，大于0表示子模式
        print(matched.group(i), end = ', ') #matched.group(0)等价于matched.group()，表示整个模式匹配到的内容
        print('在原串中的切片范围：', matched.span(i)) #.span(i)等价于元组(.start(i), .end(i))
    times += 1
    matched = reg.search(s, matched.end(0))
