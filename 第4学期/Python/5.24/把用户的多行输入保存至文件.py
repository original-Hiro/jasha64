f = open('MyInputs.txt', 'w')

s = input()
while s:
    f.write(s + '\n')
    s = input()

f.close()
