answer = [(cock, 30-cock)
          for cock in range(0, 30)
          if 2 * cock + 4 * (30-cock) == 90]
print(answer)
