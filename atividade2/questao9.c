#include <stdio.h>

// Função para calcular o máximo divisor comum (MDC)
long long mdc(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para calcular o inverso modular usando o Algoritmo Estendido de Euclides
long long inverso(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    return (x1 < 0) ? x1 + m0 : x1;
}

// Função principal para o Teorema Chinês do Resto
long long teoremaChines(int n, long long a[], long long m[]) {
    long long M = 1, x = 0;

    // Calcula o produto dos módulos
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }

    // Calcula a solução do sistema de congruências
    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long inv = inverso(Mi, m[i]);
        x += a[i] * Mi * inv;
    }

    return (x % M + M) % M; // Ajusta para o menor resto positivo
}

int main() {
    int n;
    printf("Digite o número de equações (até 4): ");
    scanf("%d", &n);

    if (n < 1 || n > 4) {
        printf("Número de equações inválido. Deve ser entre 1 e 4.\n");
        return 1;
    }

    long long a[4], m[4];
    printf("\nDigite os valores para cada equação no formato x ≡ a[i] (mod m[i]):\n");

    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i + 1);
        scanf("%lld", &a[i]);
        printf("m[%d]: ", i + 1);
        scanf("%lld", &m[i]);

        // Verifica se os módulos são válidos (positivos e coprimos)
        if (m[i] <= 0) {
            printf("Os módulos devem ser positivos.\n");
            return 1;
        }
        for (int j = 0; j < i; j++) {
            if (mdc(m[i], m[j]) != 1) {
                printf("Os módulos m[%d] e m[%d] não são coprimos. O sistema não pode ser resolvido.\n", i + 1, j + 1);
                return 1;
            }
        }
    }

    long long resultado = teoremaChines(n, a, m);
    long long M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }

    printf("\nSolução do sistema de congruências: x ≡ %lld (mod %lld)\n", resultado, M);

    return 0;
}
