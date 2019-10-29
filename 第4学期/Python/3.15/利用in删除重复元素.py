#删除列表中重复出现的元素,重复元素保留最后一个
init = [7, 5, 4, 7, 3, 3, 5, 3, 7]
res = []
init.reverse()
for item in init:
    if item not in res:
        res.append(item)
res.reverse()
print(res)
