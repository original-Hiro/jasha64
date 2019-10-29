def trans(iNum, isFirst):
    a = iNum // 10 #十位
    b = iNum % 10 #个位
    x = ('', '一十', '二十', '三十', '四十', '五十', '六十', '七十', '八十', '九十')
    y = ('', '一', '二', '三', '四', '五', '六', '七', '八', '九')
    z = (',', '')
    print(z[isFirst], x[a] + y[b], end = '')

def main():
    iStr = input("请输入0~100之间的一列整数(以','分隔)：")
    iNum = [eval(x) for x in iStr.split(',')] #输入多个整数的标准方法
    print('该列数的中文表示：', end = '')
    for i in range(len(iNum)):
        trans(iNum[i], i == 0)

if __name__ == '__main__':
    main()
