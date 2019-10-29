#ISBN-13是区别书籍的新标准。它使用13个数字：d1d2d3d4d5d6d7d8d9d10d11d12d13。
#最后一位d13是一个校验码，它是使用下面的公式从其他几位计算得到的：
#10 - (d1+3d2+d3+3d4+d5+3d6+d7+3d8+d9+3d10+d11+3d12) % 10
#如果校验码是10，就用0替换它。
#
#用户输入前12位，程序输出完整的ISBN号码。右图是程序的两次运行，黑色为用户输入，蓝色为程序输出。
#当用户输入不是12个数字时，程序再次出现输入提示，直至用户输入正确，之后程序显示完整的ISBN号码。

import re
patStr = re.compile(r'^\d{12}$')
print('输入ISBN-13的前12位：')
iStr = input()
while not patStr.match(iStr):
    print('输入ISBN-13的前12位：')
    iStr = input()

d = [0] * 12
for i in range(12):
    d[i] = int(iStr[i])
pat = 10 - (d[0] + 3*d[1] + d[2] + 3*d[3] + d[4] + 3*d[5] + d[6]
            + 3*d[7] + d[8] + 3*d[9] + d[10] + 3*d[11]) % 10
if pat == 10:
    pat = 0

s1 = "%d%d%d" % (d[0], d[1], d[2])
s2 = "%d" % d[3]
s3 = "%d%d%d" % (d[4], d[5], d[6])
s4 = "%d%d%d%d%d" % (d[7], d[8], d[9], d[10], d[11])
s5 = "%d" % pat
print('ISBN号码：%s-%s-%s-%s-%s' % (s1, s2, s3, s4, s5))
