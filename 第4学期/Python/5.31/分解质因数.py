def factors(x): #函数内修改参数x不影响主程序的变量x
    import math
    primes = [p for p in range(2, x//2+1) if 0 not in \
              [p%d for d in range(2, int(math.sqrt(p))+1)]]
    #利用列表推导式求素数
    
    factorList = []
    for i in primes:
        while x % i == 0:
          factorList.append(i)
          x //= i
    
    return factorList

def main():
    x = eval(input('请输入一个正整数：'))
    flist = factors(x)
    if flist:
        print('%d=%s' % (x, '*'.join([str(each) for each in flist])))
        #用join()把它们写成连乘形式
    else:
        print('%d已经是质数，无需分解' % x)

if __name__ == '__main__':
    main()
