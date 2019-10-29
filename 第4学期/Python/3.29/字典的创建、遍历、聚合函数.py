aKey = ('张三', '李四', '王五', '赵六', '田七', '夏八')
aValue = (93, 94, 95, 96, 97, 97)
aDict = dict(zip(aKey, aValue))
#dict()利用已有数据创建字典
for k, v in aDict.items(): #序列解包
    print(k, v)
average = sum(aDict.values()) / len(aDict)
print(average)
highest = max(aDict.values())
highestPeople = [k for k, v in aDict.items() if v == highest] #列表推导式
#aDict.items()返回的是字典全体键、值对元组
print(highestPeople)
