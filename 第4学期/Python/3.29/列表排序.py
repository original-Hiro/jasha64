#给定考生姓名列表和分数列表，要求按分数从高到低的顺序给考生姓名排序
aList = ['张三', '李四', '王五', '赵六']
bList = [86, 93, 84, 88]

pairs = list(zip(bList, aList))
#因为要求以分数为第一排序依据，所以把分数放在前面
pairs.sort(reverse = True) #降序
#from operator import itemgetter
#result = sorted(zip(aList, bList), key = itemgetter(1), reverse = True)
#itemgetter()下标从0开始
#等价，除了aList和bList的列编号交换了

result = [x[1] for x in pairs] #只输出姓名
print(result)
