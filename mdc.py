def mdc(a, b):
    if b == 0:
        return a
    return mdc(b, a % b)

try:
    a = int(input("Digite o primeiro número inteiro positivo (a): "))
    b = int(input("Digite o segundo número inteiro positivo (b): "))
    if a < 0 or b < 0:
        print("Por favor, digite números inteiros positivos.")
    else:
        print(f"O MDC de {a} e {b} é: {mdc(a, b)}")
except ValueError:
    print("Erro: Você deve digitar números inteiros válidos.")
