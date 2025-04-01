#include <stdio.h>
#include <string.h>
#include <math.h>

// Define o mapeamento do alfabeto
int mapChar(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A' + 11; // A = 11, B = 12, ..., Z = 36
    return -1; // Caso inválido
}

char mapNumber(int num) {
    return (num >= 11 && num <= 36) ? (num - 11 + 'A') : '?';
}

// Função para calcular o MDC (Máximo Divisor Comum)
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para calcular o inverso modular
int inversoModular(int e, int phi) {
    int t = 0, new_t = 1;
    int r = phi, new_r = e;
    while (new_r != 0) {
        int quociente = r / new_r;
        int temp = t;
        t = new_t;
        new_t = temp - quociente * new_t;
        temp = r;
        r = new_r;
        new_r = temp - quociente * new_r;
    }
    if (r > 1) return -1; // Não há inverso
    if (t < 0) t += phi;
    return t;
}

// Função para calcular (base^exp) % mod de forma eficiente
long long potenciaModular(long long base, long long exp, long long mod) {
    long long resultado = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) resultado = (resultado * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return resultado;
}

int main() {
    int p, q, e, bloco;
    char texto[100];

    // Entradas
    printf("Digite os números primos p e q: ");
    scanf("%d %d", &p, &q);
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    printf("Digite o valor de E (coprimo a %d): ", phi);
    scanf("%d", &e);
    if (mdc(e, phi) != 1) {
        printf("E precisa ser coprimo com %d.\n", phi);
        return 1;
    }

    printf("Digite o tamanho do bloco (máximo %d): ", n);
    scanf("%d", &bloco);

    printf("Digite o texto para criptografar (somente letras): ");
    scanf("%s", texto);

    // Calcula o inverso modular de E
    int d = inversoModular(e, phi);
    if (d == -1) {
        printf("Não foi possível calcular o inverso modular.\n");
        return 1;
    }

    // Criptografia
    printf("\nTexto criptografado:\n");
    int len = strlen(texto);
    long long criptografado[len];
    for (int i = 0; i < len; i++) {
        int valor = mapChar(texto[i]);
        if (valor == -1) {
            printf("Caractere inválido detectado.\n");
            return 1;
        }
        criptografado[i] = potenciaModular(valor, e, n);
        printf("%lld ", criptografado[i]);
    }

    // Descriptografia
    printf("\n\nTexto descriptografado:\n");
    for (int i = 0; i < len; i++) {
        long long valorDescripto = potenciaModular(criptografado[i], d, n);
        char caractere = mapNumber(valorDescripto);
        printf("%c", caractere);
    }
    printf("\n");

    return 0;
}
