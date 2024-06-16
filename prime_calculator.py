x = 38523

x_int = int(x)
factors = []
if x_int <= 1:
    print(f"{x} is not a prime number")
else:
    for factor in range(2, x_int):
        if x_int % factor == 0:
            factors.append(factor)
    if len(factors) == 0:
        print(f"{x} is a prime number.")
    else:
        print(f"{x} is not a prime number. If has following factors: {', '.join(map(str, factors))}.")