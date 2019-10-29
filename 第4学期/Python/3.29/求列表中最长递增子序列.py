#求列表中最长递增子序列，若有多解，随意输出一个即可。

#generate random sequence
import random
N = 10
x = [random.randint(1, 10) for i in range(N)]
print(x)

#determine increasing subsequences
Lx = len(x)
mono = [1 if x[i]<=x[i+1] else 0 for i in range(Lx-1)] #单调信息序列
Lm = Lx - 1 #len of mono
sumsOfMono = [[sum(mono[i:j]), i, j-i] for i in range(Lm) for j in range(i+1, Lm+1)] #枚举区间[i, j)
y = [[tot, beg] for tot, beg, l in sumsOfMono if l == tot] #mono序列中对应位置的和等于区间长度，说明区间单调递增

#print answer
ans = max(y)
print('LIS起点：', ans[1])
print('LIS长度：', ans[0] + 1)
print('LIS：', x[ans[1]: ans[1]+ans[0]+1])
