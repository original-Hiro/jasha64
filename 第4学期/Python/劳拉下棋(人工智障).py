def printWelcome():
    print('''Hi,我是劳拉，我们来玩一局四连环。我用O型棋子，你用X型棋子。
游戏规则：双方轮流选择棋盘的列号放进自己的棋子，
        若棋盘上有四颗相同型号的棋子在一行、一列或一条斜线上连接起来，
        则使用该型号棋子的玩家就赢了!
    ''')

def printBoard(G):
    charList = (' ', 'O', 'X')
    print(' 1 2 3 4 5 6 7 8')
    for i in range(6):
        print('|', end = '')
        for j in range(8):
            print('%c|' % charList[G[i][j]], end = '')
        print('')
    print('-----------------')
    print('')

#仅当读入的数据满足要求时，该函数会返回，否则输出错误信息并让用户重新输入
def legalRead0(nonEmptyCols):
    inputPat = re.compile(r'^\d+$')
    iStr = input('>>>轮到你了,你放X棋子,请选择列号(1-8): ')
    if not inputPat.match(iStr):
        print('您输入的不是数，请重新输入...')
        return -1

    curCol = int(iStr)
    if not 1 <= curCol <= 8:
        print('列号应该在1～8之间，请重新选择...')
        return -1

    curCol -= 1
    if curCol not in nonEmptyCols:
        print('这列满了，请另选一列...')
        return -1

    return curCol

def legalRead(nonEmptyCols):
    ret = -1
    while ret == -1:
        ret = legalRead0(nonEmptyCols)
    return ret

def Judge0(X, Y, G): #四个坐标
    cur = -1 #当前正在判定的棋子种类，-1表示未设定
    for i in range(4):
        x = X[i]
        y = Y[i]
        if x < 0 or x >= 6 or y < 0 or y >= 8: #越界
            return False
        if cur == -1:
            cur = G[x][y]
        if G[x][y] != cur: #不能形成四连环
            return False
    return True

def Judge(x, y, G): #以(x, y)为中心判断是否有四连环形成
    dx = ((-3, -2, -1, 0), (-2, -1, 0, 1), (-1, 0, 1, 2), (0, 1, 2, 3), ( 0,  0,  0, 0), ( 0,  0, 0, 0), ( 0, 0, 0, 0), (0, 0, 0, 0), (-3, -2, -1, 0), (-2, -1, 0, 1), (-1, 0, 1, 2), (0, 1, 2, 3), (-3, -2, -1, 0), (-2, -1, 0,  1), (-1, 0,  1,  2), (0,  1,  2,  3))
    dy = (( 0,  0,  0, 0), ( 0,  0, 0, 0), ( 0, 0, 0, 0), (0, 0, 0, 0), (-3, -2, -1, 0), (-2, -1, 0, 1), (-1, 0, 1, 2), (0, 1, 2, 3), (-3, -2, -1, 0), (-2, -1, 0, 1), (-1, 0, 1, 2), (0, 1, 2, 3), ( 3,  2,  1, 0), ( 2,  1, 0, -1), ( 1, 0, -1, -2), (0, -1, -2, -3))
    for i in range(16): #16种可能的情况
        X = []
        Y = []
        for j in range(4):
            X.append(x + dx[i][j])
            Y.append(y + dy[i][j])
        if Judge0(X, Y, G):
            return True
    return False

def main():
    printWelcome()

    G0 = [0] * 8
    G = []
    for i in range(6):
        G.append(G0.copy())
    print('开始了！这是棋盘的初始状态：')
    printBoard(G)

    Top = [5] * 8 #5是最底层
    nonEmptyCols = [0, 1, 2, 3, 4, 5, 6, 7]
    chessCnt = 0
    while chessCnt < 6*8:
        curCol = random.choice(nonEmptyCols)
        print('>>>轮到我了,我把O棋子放在第%d列...' % (curCol + 1))
        G[Top[curCol]][curCol] = 1
        printBoard(G)
        chessCnt += 1
        if Judge(Top[curCol], curCol, G):
            print('******* 耶，我赢了！^_^')
            break
        Top[curCol] -= 1
        if Top[curCol] == -1:
            nonEmptyCols.remove(curCol)

        curCol = legalRead(nonEmptyCols)
        G[Top[curCol]][curCol] = 2
        printBoard(G)
        chessCnt += 1
        if Judge(Top[curCol], curCol, G):
            print('******* 好吧，你赢了！^_*')
            break
        Top[curCol] -= 1
        if Top[curCol] == -1:
            nonEmptyCols.remove(curCol)
    else:
        print('******* 难分胜负！@_@')

import random
import re
if __name__ == '__main__':
    main()
