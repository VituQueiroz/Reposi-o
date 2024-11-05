#include <stdio.h>
#include <string.h>

#define MAX_FILMES 100

typedef struct {
    char titulo[100];
    char diretor[100];
    int ano;
    int duracao;
} Filme;

Filme filmes[MAX_FILMES];
int total_filmes = 0;

void listarFilmes() {
    if (total_filmes == 0) {
        printf("Nenhum filme cadastrado.\n");
        return;
    }
    printf("\nLista dos Filmes:\n");
    for (int i = 0; i < total_filmes; i++) {
        printf("Título: %s\n", filmes[i].titulo);
        printf("Diretor: %s\n", filmes[i].diretor);
        printf("Ano: %d\n", filmes[i].ano);
        printf("Duração: %d minutos\n\n", filmes[i].duracao);
    }
}

void buscarFilmesPorNome() {
    char nome[100];
    int encontrados = 0;

    printf("Digite o título do filme: ");
    getchar();
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < total_filmes; i++) {
        if (strstr(filmes[i].titulo, nome) != NULL) {
            printf("Título: %s\n", filmes[i].titulo);
            printf("Diretor: %s\n", filmes[i].diretor);
            printf("Ano: %d\n", filmes[i].ano);
            printf("Duração: %d minutos\n\n", filmes[i].duracao);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum filme encontrado. \n");
    }
}

void inserirFilme() {
    if (total_filmes >= MAX_FILMES) {
        printf("Limite de filmes atingido.\n");
        return;
    }

    Filme novoFilme;

    printf("Digite o título do filme: ");
    getchar();
    fgets(novoFilme.titulo, 100, stdin);
    novoFilme.titulo[strcspn(novoFilme.titulo, "\n")] = '\0';

    printf("Digite o nome do diretor: ");
    fgets(novoFilme.diretor, 100, stdin);
    novoFilme.diretor[strcspn(novoFilme.diretor, "\n")] = '\0';

    printf("Digite o ano de lançamento: ");
    scanf("%d", &novoFilme.ano);

    printf("Digite a duração do filme (em minutos): ");
    scanf("%d", &novoFilme.duracao);

    filmes[total_filmes] = novoFilme;
    total_filmes++;
    printf("Filme '%s' \n", novoFilme.titulo);
}

void exibirMenu() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Listar Filmes\n");
        printf("2. Buscar Filmes por Nome\n");
        printf("3. Inserir Novo Filme\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarFilmes();
                break;
            case 2:
                buscarFilmesPorNome();
                break;
            case 3:
                inserirFilme();
                break;
            case 4:
                printf("Saindo\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);
}

int main() {
    exibirMenu();
    return 0;
}

