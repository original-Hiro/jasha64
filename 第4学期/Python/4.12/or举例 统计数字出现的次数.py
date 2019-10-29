#随机产生一列15个[1, 10)范围内的数
import random
base = range(10)
numList = [random.choice(base) for i in range(15)] #列表推导式

#统计
countTable = dict() #空字典
for num in numList:
    countTable[num] = 1 + (countTable.get(num) or 0)
    #如果字典里没有这个数，countTable.get(num)的结果为null，
    #此时按照or的运算规则，表达式countTable.get(num) or 0会取0
    #注意优先级
    #或：countTable[num] = 1 + countTable.get(num, 0)

#输出
for i in base:
    if (countTable.get(i)):
        print("数值%d次数：%d" % (i, countTable[i]))
