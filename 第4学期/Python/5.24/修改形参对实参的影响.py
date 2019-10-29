def addOneForList(aList):
    L = len(aList)
    for i in range(L):
        aList[i] = aList[i] + 1

x = [1, 2, 3, 4, 5]
addOneForList(x)
print(x)
