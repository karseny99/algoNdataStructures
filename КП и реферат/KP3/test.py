


def f(x):
    res = x
    k = 1
    cst = 2 ** (-53) * 8
    i = 1
    sq = 90
    while (abs(sq) >= cst):
        k *= (2 * i + 1) * (2 * i)
        sq = ((-1) ** i) * ((x ** (2 * i + 1)) / k)
        res += sq
        i += 1
    return res, i

for i in range(50):
    print(i / 49, f(i / 49))























































