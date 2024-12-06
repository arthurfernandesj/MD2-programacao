def soma_numeros(n):
    if n == 0:
        return 0
    return n + soma_numeros(n - 1)

n = int(input("Digite um número para calcular a soma de 1 a n: "))
print(f"Soma de 1 a {n}: {soma_numeros(n)}")
