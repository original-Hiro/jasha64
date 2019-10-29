s = input("请输入一个非负整数：")
while not s.isdigit():
    print("输入错误！请重新输入。")
    s = input()

x = int(s)
x = x ** 3
print(x)
