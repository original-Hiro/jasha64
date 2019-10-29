#random.shuffle(aList)的作用是打乱一个列表。
#要求不使用random.shuffle(aList)来打乱一列数，并显示这列数，要求每次运行的乱序结果都不一样。
def main():
    import random
    iStr = input('请输入一列数，以空格分隔：')
    iList = [eval(x) for x in iStr.split()]
    oList = []
    for i in range(len(iList)):
        curPos = random.randint(0, len(iList)-1)
        oList.append(iList[curPos])
        iList.pop(curPos)
    print('乱序结果：', end = ' ')
    for i in oList:
        print(i, end = ' ') #注意格式
if __name__ == '__main__':
   main()
