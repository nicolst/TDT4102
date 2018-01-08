def is_fibonacci_number(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b += a
        a = temp
    return b == n
