def output(x):
    str = x * '*'
    for i in range(1, x+1):
        print((x-i) * ' ' + str[-i:])
def main():
    num = int(input('请输入一个正整数：'))
    output(num)
if __name__ == '__main__':
    main()
