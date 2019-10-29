#检查两个单词是否为相似词。
#两个单词如果包含相同的字母，则它们是相似词。
#例如：silent和listen是相似词。

iStr = input('请输入两个单词，以空格分隔：')
x, y = iStr.split()

cnt = [0] * 26
for each in x:
    cnt[ord(each) - ord('a')] += 1
for each in y:
    cnt[ord(each) - ord('a')] -= 1

print('单词%s与单词%s' % (x, y), end = '')
for each in cnt:
    if each != 0:
        print('不是相似词!')
        break
else:
    print('是相似词!')
