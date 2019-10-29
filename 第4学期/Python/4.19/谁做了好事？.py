#四个人中有一人做了好事，
#已知有三个人说了真话，
#根据下面对话判断是谁做的好事。
#A说：不是我；
#B说：是C；
#C说：是D；
#D说：C胡说。
for iNum in ['A', 'B', 'C', 'D']:
    if (iNum != 'A') + (iNum == 'C')\
       + (iNum == 'D') + (iNum != 'D') == 3:
        print(iNum, '做了好事!')
#ans = [iNum for iNum in ['A', 'B', 'C', 'D'] \
       #if (iNum (iNum != 'A') + (iNum == 'C')\
           #+ (iNum == 'D') + (iNum != 'D') == 3]
#print(ans)
