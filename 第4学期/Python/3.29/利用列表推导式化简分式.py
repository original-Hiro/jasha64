s = input('请输入形如a/b的分式：')
a, b = [eval(x) for x in s.split('/')]
ans = ["%d/%d" % (i, j)
       for i in range(0, a+1)
       for j in range(1, b+1)
       if a * j == b * i]
print("%s的最简分式为%s" % (s, ans[0]))
