#    大  白
#+   大  白
#——————————
#白  胖  胖
#
#求 大、白、胖 分别是哪三个数字？

x = [(d, b, p) for d in range(1, 10) for b in range(1, 10) for p in range(10)
     if (d*10 + b) * 2 == b*100 + p*10 + p*1]
print(x)
