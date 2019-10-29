#下面的代码首先生成包含1000个随机字符的字符串，然后统计每个字符的出现次数
import string
import random
x = string.ascii_letters + string.digits + string.punctuation #字符库
y = [random.choice(x) for i in range(1000)] #列表推导式
z = ''.join(y) #列表转字符串
print(z)
d = dict()
for ch in z:
    d[ch] = d.get(ch, 0) + 1
print(d)
