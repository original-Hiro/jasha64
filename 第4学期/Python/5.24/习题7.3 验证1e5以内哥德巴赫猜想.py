#验证100000以内的哥德巴赫猜想。
#程序执行时依次显示每个偶数的分解结果，
#要求且只需显示两质数距离最短的分解结果，
#要求等号右边两个质数从小到大排列。
#并且程序执行结果自动分10个文件保存于当前文件夹内：
#第1个文件 Goldbach01.txt，保存4~9999内偶数的分解结果；
#第2个文件 Goldbach02.txt，保存10000~19999内偶数的分解结果；
#…… 
#第10个文件 Goldbach10.txt，保存90000~99999内偶数的分解结果。



#筛法求素数
isp = [True] * 100001 #isprime
isp[0] = isp[1] = False
for i in range(2, 100001):
    if isp[i]:
        j = 2
        while i*j <= 100000:
            isp[i*j] = False
            j += 1

for i in range(10):
    print('现在写入第%d个文件' % (i+1))
    ofs = open('Goldbach%d.txt' % (i+1), 'w') #output file stream
    for j in range(max(4, i * 10000), (i+1) * 10000, 2):
        k = j // 2
        while not (isp[k] and isp[j-k]):
            k -= 1
        outstr = '%d = %d + %d' % (j, k, j-k)
        print(outstr)
        ofs.write(outstr + '\n')
    ofs.close()
