dist = eval(input('请输入行驶里程数(公里)：'))
wt = eval(input('请输入等候时间(分钟)：'))

res = wt // 5 * 2.1
if dist <= 3:
    res += 11
elif 3 < dist <= 10:
    res += 11 + (dist - 3) * 2.1
elif dist > 10:
    res += 25.7 + (dist - 10) * 3.2

print('请您付款%d元，谢谢！' % round(res)) #老师说最后价格四舍五入到整数就行了
