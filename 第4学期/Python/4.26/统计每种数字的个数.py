import string
s = input('请输入任意一串字符：')

cnt = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for each in s:
    if each in string.digits:
        cnt[int(each)] += 1
for i in range(10):
    if cnt[i]:
        print('数字%d的个数为%d' % (i, cnt[i]))
