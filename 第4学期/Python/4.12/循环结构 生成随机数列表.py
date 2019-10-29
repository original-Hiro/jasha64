#生成一个含有20个随机数的列表，
#要求所有元素不相同，
#并且每个元素的值介于1到100之间。
import random
oList = []
while len(oList) < 20:
    x = random.randint(1, 100)
    if x not in oList: #in算符
        oList.append(x) #append()方法
print(oList)
