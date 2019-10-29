ans = [x*100 + y*10 + z
       for x in range(1, 10) for y in range(10) for z in range(10)
       if x**3 + y**3 + z**3 == x*100 + y*10 + z]
#ans = [x for x in range(100, 1000)
#       if (x%10)**3 + (x//10%10)**3 + (x//100)**3 == x]
print(ans)
