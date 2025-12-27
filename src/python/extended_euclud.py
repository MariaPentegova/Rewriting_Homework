def extended_euclid(a, b):
    if b == 0:
        return a, 1, 0
    else:
        gcd, x1, y1 = extended_euclid(b, a % b)

        x = y1
        y = x1 - (a // b) * y1
        return gcd, x, y

a = int(input("Enter a: "))
b = int(input("Enter b: "))

gcd, x, y = extended_euclid(a, b)

print(f"gcd({a}, {b}) = {gcd}")
print(f"{a}*({x}) + {b}*({y}) = {a*x + b*y}")
