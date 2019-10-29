#带两个星号参数的函数传入的参数存储为一个字典（dict），并且在
#调用时采取 key1 = value1, key2 = value2, ... 的形式。
#由于传入的参数个数不定，所以当与普通参数一同使用时，必须把带星号的参
#数放在最后。

#def demo(p):
def demo(**p):
    for item in p.items():
        print(item)

#demo({'x':1, 'y':2, 'z':3})
demo(x=1, y=2, z=3)

