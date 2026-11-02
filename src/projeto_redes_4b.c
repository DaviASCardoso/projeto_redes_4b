#include <stdio.h>

int main() {
    int estado[10];
    int n, i;
    int ativos = 0, inativos = 0;
    float percentual;

    do {
        printf("Quantos dispositivos (1 a 10)? ");
        scanf("%i", &n);
        if (n < 1 || n > 10) {
            printf("Valor invalido!\n");
        }
    } while (n < 1 || n > 10);

    for (i = 0; i < n; i++) {
        do {
            printf("Estado do dispositivo %i (1=ativo, 0=inativo): ", i + 1);
            scanf("%i", &estado[i]);
            if (estado[i] != 0 && estado[i] != 1) {
                printf("Digite apenas 0 ou 1\n");
            }
        } while (estado[i] != 0 && estado[i] != 1);
    }

    printf("\n--- ESTADOS ---\n");
    for (i = 0; i < n; i++) {
        if (estado[i] == 1) {
            printf("Dispositivo %i: ATIVO\n", i + 1);
        } else {
            printf("Dispositivo %i: INATIVO\n", i + 1);
        }
    }

    for (i = 0; i < n; i++) {
        if (estado[i] == 1) {
            ativos = ativos + 1;
        } else {
            inativos = inativos + 1;
        }
    }

    percentual = ativos * 100.0 / n;

    printf("\n--- PAINEL ---\n");
    printf("Ativos: %i\n", ativos);
    printf("Inativos: %i\n", inativos);
    printf("Disponibilidade: %.1f%%\n", percentual);

    if (inativos >= 2) {
        printf("ALERTA: 2 ou mais dispositivos indisponiveis\n");
    } else {
        printf("Situacao normal\n");
    }

    return 0;
}
