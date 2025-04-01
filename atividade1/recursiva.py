def imprimir_naturais(n):
    if n == 0:
        return
    imprimir_naturais(n - 1)
    print(n, end=" ")

n = int(input("Digite o valor de n para imprimir os números naturais de 1 a n: "))
print(f"Números naturais de 1 a {n}:")
imprimir_naturais(n)
print()
