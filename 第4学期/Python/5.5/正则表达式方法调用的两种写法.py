import re
pattern = r'\b\d{6}\b'
s = "I know 200433, 100084 and 443000 are postcodes."

print('正则表达式对象')
regex = re.compile(pattern, re.I)
matchObj = regex.search(s)
while matchObj:
    print(matchObj.group())
    matchObj = regex.search(s, matchObj.end())

print('re模块的方法')
matchObj = re.search(pattern, s, re.I) #只能匹配一个
if matchObj:
    print(matchObj.group())

