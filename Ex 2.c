#include <stdio.h>
#include <string.h>

#define MAX_VOOS 2
#define MAX_AVIOES 3

typedef struct {
    char destino[50];
    int distancia;
    int numeroVoo;
} Voo;

typedef struct {
    char id[10];
    Voo voos[MAX_VOOS];
    int distanciaTotal;
} Aviao;

void registrarVoos(Aviao* aviao) {
    for (int i = 0; i < MAX_VOOS; i++) {
        printf("Para o avião %s:\n", aviao->id);
        printf("Digite o destino do voo %d: ", i + 1);
        getchar();
        fgets(aviao->voos[i].destino, 50, stdin);
        aviao->voos[i].destino[strcspn(aviao->voos[i].destino, "\n")] = 0;

        printf("Digite a distancia do voo %d (em km): ", i + 1);
        scanf("%d", &aviao->voos[i].distancia);

        printf("Digite o numero do voo %d: ", i + 1);
        scanf("%d", &aviao->voos[i].numeroVoo);
    }
}

void calcularDistanciaTotal(Aviao* aviao) {
    aviao->distanciaTotal = 0;
    for (int i = 0; i < MAX_VOOS; i++) {
        aviao->distanciaTotal += aviao->voos[i].distancia;
    }
}

void ordenarAviacoes(Aviao aviacoes[], int n) {
    Aviao temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (aviacoes[i].distanciaTotal < aviacoes[j].distanciaTotal) {
                temp = aviacoes[i];
                aviacoes[i] = aviacoes[j];
                aviacoes[j] = temp;
            }
        }
    }
}

void exibirResultados(Aviao aviacoes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nAvião: %s\n", aviacoes[i].id);
        for (int j = 0; j < MAX_VOOS; j++) {
            printf("Voo para %s, Distância: %d km, Número do voo: %d\n", aviacoes[i].voos[j].destino,
                   aviacoes[i].voos[j].distancia, aviacoes[i].voos[j].numeroVoo);
        }
        printf("Distância total percorrida: %d km\n", aviacoes[i].distanciaTotal);
    }
}

int main() {
    Aviao aviacoes[MAX_AVIOES];

    for (int i = 0; i < MAX_AVIOES; i++) {
        printf("Digite o identificador do avião %d: ", i + 1);
        getchar();
        fgets(aviacoes[i].id, 10, stdin);
        aviacoes[i].id[strcspn(aviacoes[i].id, "\n")] = 0;

        registrarVoos(&aviacoes[i]);
        calcularDistanciaTotal(&aviacoes[i]);
    }

    ordenarAviacoes(aviacoes, MAX_AVIOES);

    exibirResultados(aviacoes, MAX_AVIOES);

    return 0;
}

