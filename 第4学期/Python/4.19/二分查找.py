#在一个已排序的列表中查找某值出现的位置
a = [11, 23, 45, 78, 93, 99, 101, 118, 209, 919]
n = len(a)
key = eval(input('请输入待查询整数:'))

Low = 0
High = n
res = -1
while Low <= High:
    Mid = (Low + High) // 2
    if key == a[Mid]:
        res = Mid
        break
    elif key < a[Mid]:
        if High == Mid:
            break
        High = Mid
    else:
        Low = Mid + 1
    
if res == -1:
    print('数值%d在列表中不存在。' % key)
else:
    print('数值%d在列表中的下标为%d。' % (key, res))

