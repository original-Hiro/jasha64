#一个文本文件包含未指定个数的分数及随机空行，
#编写程序统计分数附加于原文件末尾，并清除原文件中的全部空行。
#程序弹出一个打开文件对话框便于用户选择文件。

from tkinter.filedialog import askopenfilename
print('请选择一个分数文件...')
fn = askopenfilename()
if not fn:
    exit()
print('您选择的文件是', fn)
infs = open(fn, 'r')
ss = infs.readlines()
outfs = open(fn, 'w')

print('该文件中包括下列分数：', end = '')
tot = 0
cnt = 0
first = 1
for each in ss:
    if each != '\n':
        outfs.write(each)
    curln = [eval(x) for x in each.split()] #获得当前行的各个数字
    for x in curln:
        if first:
            first = 0
        else:
            print(',', end = '')
        print(x, end = '')
        tot += x
        cnt += 1
print()

outfs.write('共有%d个分数' % cnt + '\n')
outfs.write('总分数是%d' % tot + '\n')
outfs.write('平均分是%.2f' % (tot / cnt) + '\n')
print('统计完毕，请查看原文件', fn)
infs.close()
outfs.close() #若不close，信息是不会从流中写到文件中的
