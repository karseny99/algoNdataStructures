s = "100011"
res = 0
for i in s:
    print(i)
    if i == "1":
        res = res * 2 + 1
    if i == "0":
        res *= 2
print(res)
