#输入两个数，排序后输出

a, b = eval(input('Input two numbers: '))
#调用eval得到固定个数的输入数据，此方法仅对逗号分隔的数据有效
if a > b:
    a, b = b, a #序列解包
print(a, b)
