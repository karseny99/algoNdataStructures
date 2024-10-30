# def d(n, m):
#     return n % m == 0
# def func(x, A):
#     return not(d(x, 6)) or not(d(x, 10)) or (x + A > 121)
#
# for A in range(1, 150):
#     if all(func(x, A) == 1 for x in range(1, 400)):
#         print(A)
#


def fib1(n):
    if n == 1 or n == 0:
        return 1
    return fib2(n - 1) + fib2(n - 2)


def fib2(n):
    if n == 1 or n == 0:
        return 1
    return fib1(n - 1) + fib1(n - 2)

print(fib1(5))