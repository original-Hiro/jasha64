ans = [(cock, hen, ch3 * 3)
       for cock in range(21) for hen in range(34) for ch3 in range(101)
       if cock + hen + ch3*3 == 100 and cock*5 + hen*3 + ch3 == 100]
print(ans)
