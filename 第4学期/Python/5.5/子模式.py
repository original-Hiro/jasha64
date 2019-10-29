def myFind(txt, patStr):
    pat = re.compile(patStr)
    res = pat.findall(txt)
    print(res)
def main():
    s = "A takes 30 min, B takes 19 sec, and C takes 26 ms."
    myFind(s, r"\d+ (?:min|sec|ms)")
import re
if __name__ == '__main__':
    main()
