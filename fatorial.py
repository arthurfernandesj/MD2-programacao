def fatorial(n):
    if n == 0 or n == 1:
        return 1
    return n * fatorial(n - 1)

n = int(input("Digite um numero para calcular o fatorial: "))
print(f"{n}! = {fatorial(n)}")
