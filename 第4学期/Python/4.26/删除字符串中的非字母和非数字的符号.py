import string
s = input()
charSet = string.ascii_letters + string.digits
t = ""
for x in s:
    if x in charSet:
        t += x
print(t)
