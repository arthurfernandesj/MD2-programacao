def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)

n = int(input("Digite a quantidade de números da sequência de Fibonacci: "))
print("Sequência de Fibonacci:")
for i in range(n):
    print(f"Fibonacci({i}) = {fibonacci(i)}")
