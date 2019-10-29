from tkinter.filedialog import asksaveasfilename
fileNameSaved = asksaveasfilename()
print(fileNameSaved)

if not fileNameSaved:
    exit() #因为用户没有指定文件名，所以该变量为None，所以我们不再执行后面的程序语句
f = open(fileNameSaved, 'w')
s = 'HoHoHo\n'
for i in range(10):
    f.write(s)
f.close()

