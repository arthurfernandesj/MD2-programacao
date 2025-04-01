def tabela_adicao_modular(n):
    print(f"Tabela de Adição Modular (Z_{n}):")
    print("   ", end="")
    for i in range(n):
        print(f"{i:3}", end="")
    print("\n" + "-" * (4 * (n + 1)))
    
    for i in range(n):
        print(f"{i:2}|", end="")
        for j in range(n):
            print(f"{(i + j) % n:3}", end="")
        print()

try:
    n = int(input("Digite o valor de n para gerar a tabela Z_n de adição modular: "))
    if n <= 0:
        print("Por favor, digite um número inteiro positivo maior que zero.")
    else:
        tabela_adicao_modular(n)
except ValueError:
    print("Erro: Você deve digitar um número inteiro válido.")
