def func(score):
    gradeList = ['F']*6
    gradeList.extend(['D', 'C', 'B', 'A', 'A'])
    #用下标表示等级
    tDigit = score // 10
    grade = 'Wrong Score' if not 0 <= score <= 100 else gradeList[tDigit]
    #双分支语句
    return grade

x = eval(input('请输入分数：'))
print(x, '分的等级是', func(x))
