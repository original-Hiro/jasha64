#输入7位评委给出的成绩，
#去掉一个最高分，
#去掉一个最低分，
#计算出平均分，作为得分

scrList = []

for i in range(7):
    x = eval(input('评委%c给出的成绩: ' % (ord('A')+i))) #ord()返回字符的ASCII码
    scrList.append(x)

mx = max(scrList)
print('去掉一个最高分:', mx)
scrList.remove(mx)
mn = min(scrList)
print('去掉一个最低分:', mn)
scrList.remove(mn)
print('最终得分:', sum(scrList) / len(scrList))
