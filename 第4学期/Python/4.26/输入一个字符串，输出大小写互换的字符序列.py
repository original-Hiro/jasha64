import string
s = input()

dis = ""
for each in s:
    if each in string.ascii_lowercase:
        dis += each.upper()
    elif each in string.ascii_uppercase:
        dis += each.lower()
    else:
        dis += each

print(dis)
