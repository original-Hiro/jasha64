def f(x):
    s = "%-4d%-4d%-4d"
    print(s % (x, x*x, x**3))
def main():
    print("a   a^2 a^3 ")
    f(1)
    f(2)
    f(3)
    f(4)
main()
