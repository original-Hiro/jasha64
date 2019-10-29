a = eval(input('请输入数A: '))
b = eval(input('请输入数B: '))
print('这两个数的算术平均为: %.3f' % ((a + b) / 2))
import math
print('这两个数的几何平均为: %.3f' % math.sqrt(a*b))
print('这两个数的调和平均为: %.3f' % (2 / (1/a + 1/b)))
