#某人位于一个N×N区域的中央，
#他每次随机地选择上、下、左、右四个方向之一并走一步，
#问要多少步他才能走出这个区域？
#
#为了得到更加精确的结果，
#把他从中央开始到他走出区域称为一次模拟，
#程序做K次模拟，计算这K次模拟的平均步数。
#
#N和K在程序运行之初由用户输入，
#为了便于在区域中央，要求N为奇数。

def read():
    import sys
    N, K = eval(input('请输入区域边长N(要求为奇数)和模拟次数K,逗号分隔:'))
    if N <= 0 or K <= 0 or N % 2 == 0:
        print('输入错误，请重新输入。')
        sys.exit()
    return N, K

def print_graph(G, n):
    for i in range(n):
        for j in range(n):
            print(G[i][j], end = '')
        print()

def main():
    N, K = read()

    import random
    dg = ('<', '^', 'V', '>')
    dx = (-1,   0,   0,   1 )
    dy = ( 0,  -1,   1,   0 )
    res_str = 'Steps %d; Y=%d, X=%d, N=%d; Status: '
    res_status = ('IN', 'OUT')
    tot_cnt = 0
    for k in range(1, K+1):
        print('N=%d时开始第%d次模拟...' % (N, k))
        G0 = ['.'] * N
        G = []
        for i in range(N):
            G.append(G0.copy()) #注意建图方式，如方式不当将成浅拷贝
        x = N // 2
        y = N // 2
        G[y][x] = 'O'
        cnt = 0
        print_graph(G, N)
        done = 0
        print(res_str % (cnt, y, x, N) + 'IN')
        while not done:
            d = random.randint(0, 3)
            G[y][x] = 'O'
            x += dx[d]
            y += dy[d]
            done = x < 0 or x >= N or y < 0 or y >= N
            if not done:
                G[y][x] = dg[d]
            cnt += 1
            print_graph(G, N)
            print(res_str % (cnt, y, x, N) + res_status[done])
        print('N=%d时第%d次模拟结束，共%d步走出。' % (N, k, cnt))
        tot_cnt += cnt
    print('N=%d时平均%d步走出!!!' % (N, tot_cnt // k))

if __name__ == '__main__':
    main()
        
