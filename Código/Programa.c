#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define MAX_LINHAS 100
#define MAX_TAMANHO 100

typedef struct {
    char nome[MAX_TAMANHO];
    float preco;
    int quantidade;
} Produto;

void trocar(Produto *a, Produto *b) {
    Produto temp = *a;
    *a = *b;
    *b = temp;
}

int carregarCSV(const char *nomeArquivo, Produto produtos[], int *totalProdutos) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    char linha[MAX_TAMANHO];
    fgets(linha, MAX_TAMANHO, arquivo); // Pular cabeçalho

    while (fgets(linha, MAX_TAMANHO, arquivo) && *totalProdutos < MAX_LINHAS) {
        sscanf(linha, "%[^,],%f,%d", 
               produtos[*totalProdutos].nome, 
               &produtos[*totalProdutos].preco, 
               &produtos[*totalProdutos].quantidade);
        (*totalProdutos)++;
    }

    fclose(arquivo);
    return 1;
}

void salvarCSV(const char *nomeArquivo, Produto produtos[], int totalProdutos) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome,Preço,Quantidade\n");

    for (int i = 0; i < totalProdutos; i++) {
        fprintf(arquivo, "%s,%.2f,%d\n", 
                produtos[i].nome, 
                produtos[i].preco, 
                produtos[i].quantidade);
    }

    fclose(arquivo);
    printf("Arquivo ordenado salvo com sucesso!\n");
}

void ordenar(Produto produtos[], int totalProdutos, int opcao) {
    for (int i = 0; i < totalProdutos - 1; i++) {
        for (int j = 0; j < totalProdutos - i - 1; j++) {
            int troca = 0;

            if (opcao == 1 && strcmp(produtos[j].nome, produtos[j + 1].nome) > 0)
                troca = 1;
            else if (opcao == 2 && produtos[j].preco > produtos[j + 1].preco)
                troca = 1;
            else if (opcao == 3 && produtos[j].quantidade > produtos[j + 1].quantidade)
                troca = 1;

            if (troca)
                trocar(&produtos[j], &produtos[j + 1]);
        }
    }
}

int main() {
    Produto produtos[MAX_LINHAS];
    int totalProdutos = 0;
    char nomeEntrada[MAX_TAMANHO], nomeSaida[MAX_TAMANHO];
    int opcao;

    printf("Digite o nome do arquivo CSV de entrada: ");
    scanf("%s", nomeEntrada);

    if (!carregarCSV(nomeEntrada, produtos, &totalProdutos)) {
        return 1;
    }

    printf("\nOrdenar por:\n");
    printf("1 - Nome\n");
    printf("2 - Preco\n");
    printf("3 - Quantidade\n");
    printf("Escolha a opcao: ");
    scanf("%d", &opcao);

    ordenar(produtos, totalProdutos, opcao);

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nomeSaida);

    salvarCSV(nomeSaida, produtos, totalProdutos);

    return 0;
}
