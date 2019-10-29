#判断一列数是否排好序
#用户随意输入一列数，数的个数不限，以逗号分隔。
#如果这列数是从小到大排列，则显示“这列数是升序排列的！”
#如果这列数是从大到小排列，则显示“这列数是降序排列的！”
#如果这列数是乱序排列，则不作显示。
#注意，每次输入的数值及个数都可能不同。

def main():
    inList = list(eval(input("请输入一列数，以','分隔：")))
    #对输入内容s调用eval(s)得到数值元组，此方法仅对逗号分隔的数据有效
    ascList = sorted(inList)
    if ascList == inList:
        print('这列数是升序排列的！')
    descList = sorted(inList, reverse = True)
    if descList == inList:
        print('这列数是降序排列的！')
if __name__ == "__main__":
    main()
