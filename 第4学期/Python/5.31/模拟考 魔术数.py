# -*- coding:cp936 -*-
'''------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：

我们这样定义一个魔术数，假设其最大的数字位n，则该魔术数的各位数字中
有0个0、1个1、2个2...n个n，除此之外不包含其他数字，可以是负数。
比如312233和-312233是一个魔术数，而1224就不是一个魔术数。
(1) 请实现函数is_magic_number(n)，判断n是否是一个魔术数。
    如果n是一个整数并且是一个魔术数，则返回True

，否则返回False

(2) 定义第一个魔术数为第一个大于0的魔术数，请实现函数nth_magic_number(n)，
如果n不是一个正整数，则抛出异常，否则返回第n个正魔术数。本函数的实现中可以
使用第一步实现的函数is_magic_number。

---------------------------------------------------------
注意：部分源程序给出如下。请勿改动其它函数中的任何内容，
      仅在函数的注释标志之间填入所编写的若干语句。
------------------------------------------------------'''
def is_magic_number(n):
    #**********Program**********
    n = abs(n)
    numstr = str(n)
    cnt = [0] * 10
    mx = 0
    for each in numstr:
        cnt[int(each)] += 1
        mx = max(mx, int(each))
    for i in range(mx+1):
        if cnt[i] != i:
            return False
    return True
    #**********  End  **********

def nth_magic_number(n):
    #**********Program**********
    if n <= 0:
        raise ValueError('您输入的不是正整数！')
    r = 0
    while n > 0:
        r += 1
        if is_magic_number(r):
            n -= 1
    return r
    #**********  End  **********

if __name__ == '__main__':
    print(is_magic_number(312233))  # True
    print(is_magic_number(-312233)) # True
    print(is_magic_number(3122332)) # False
    print(is_magic_number(0))        # False
        # 下述循环输出魔术数 1, 122, 212, 221, 122333
    for i in range(1, 6):
        print(nth_magic_number(i))

    print(nth_magic_number(0))  # 抛出异常

