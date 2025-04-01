#include <stdio.h>

int calcularCPF(int cpf[]) {
    int soma1 = 0, soma2 = 0;
    for (int i = 0; i < 9; i++) {
        soma1 += cpf[i] * (10 - i);
        soma2 += cpf[i] * (11 - i); 
    }
    
    int d1 = (soma1 % 11) < 2 ? 0 : 11 - (soma1 % 11);
    soma2 += d1 * 2;
    int d2 = (soma2 % 11) < 2 ? 0 : 11 - (soma2 % 11);
    
    return (d1 == cpf[9] && d2 == cpf[10]); 
}

int calcularISBN(int isbn[]) {
    int soma = 0;
    for (int i = 0; i < 12; i++) {
        soma += isbn[i] * (i % 2 == 0 ? 1 : 3); 
    }
    
    int d13 = (10 - (soma % 10)) % 10;
    return (d13 == isbn[12]); 
}

void calcularEValidarCPF() {
    int cpf[11];
    printf("Digite os 9 primeiros digitos do CPF (sem pontos ou traços): ");
    for (int i = 0; i < 9; i++) {
        scanf("%d", &cpf[i]);
    }
    printf("Digite os 2 digitos verificadores do CPF: ");
    scanf("%d %d", &cpf[9], &cpf[10]);

    if (calcularCPF(cpf)) {
        printf("CPF valido!\n");
    } else {
        printf("CPF invalido!\n");
    }
}

void calcularEValidarISBN() {
    int isbn[13];
    printf("Digite os 12 primeiros digitos do ISBN-13: ");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &isbn[i]);
    }
    printf("Digite o digito verificador do ISBN-13: ");
    scanf("%d", &isbn[12]);

    if (calcularISBN(isbn)) {
        printf("ISBN valido!\n");
    } else {
        printf("ISBN invalido!\n");
    }
}

int main() {
    int escolha;
    printf("Escolha a opcao:\n1. Validar CPF\n2. Validar ISBN\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        calcularEValidarCPF();
    } else if (escolha == 2) {
        calcularEValidarISBN();
    } else {
        printf("Opcao invalida!\n");
    }

    return 0;
}
