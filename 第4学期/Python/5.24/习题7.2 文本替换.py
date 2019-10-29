from tkinter.filedialog import askopenfilename
print('请选择一个文本文件...')
fn = askopenfilename()
if not fn:
    exit()
print('您选择的文件是', fn)
ifs = open(fn, 'r')
ss = ifs.readlines()
ofs = open(fn, 'w')

oldpat = input('输入要被替换的旧文本：')
newpat = input('输入用于替换的新文本：')
cnt = 0
for each in ss:
    cnt += each.count(oldpat)
    each = each.replace(oldpat, newpat)
    ofs.write(each)
print('完成！共有%d处替换。' % cnt)

ifs.close()
ofs.close() #记得关文件！
