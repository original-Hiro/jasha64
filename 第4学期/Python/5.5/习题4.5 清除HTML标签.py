import re
iStr = input()
patStr = re.compile('<.+?>') #懒惰匹配
matchObj = patStr.search(iStr)
delList = [] #存放需要被删除的所有区间的下标
while matchObj:
    delList.append(matchObj.span())
    matchObj = patStr.search(iStr, matchObj.end())

oStr = ''
pos = 0
for each in delList:
    while pos < each[0]:
        oStr += iStr[pos]
        pos += 1
    pos = each[1]
while pos < len(iStr):
    oStr += iStr[pos]
    pos += 1
print(oStr)
