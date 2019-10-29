#某国人口普查局基于如下假设来预测人口：
#每7秒1人出生
#每13秒1人死亡
#每45秒1个新增移民
#编写程序显示接下来5年每一年的人口。假设当前的人口数是3120324986，每年有365天。

def inc_year(x): #计算x年过后人口增量
    sec = x * 365 * 24 * 60 * 60
    dp = 0
    dp = dp + sec // 7
    dp = dp - sec // 13
    dp = dp + sec // 45
    return dp
def calc_year(x): #计算x年过后的人口并输出
    people = 3120324986
    people = people + inc_year(x)
    print('%d年过后，人口数为: %d' % (x, people))
def main():
    calc_year(1)
    calc_year(2)
    calc_year(3)
    calc_year(4)
    calc_year(5)
if  __name__ == "__main__":
    main()
