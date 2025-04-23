#include <stdio.h>
#include "produto.h"

#define MAX_PRODUTOS 100

int main() {
    Produto produtos[MAX_PRODUTOS];
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    int total, opcaoOrdenacao;

    printf("Nome do arquivo CSV de entrada: ");
    scanf(" %99[^\n]", nomeArquivoEntrada);

    total = lerProdutos(nomeArquivoEntrada, produtos, MAX_PRODUTOS);
    if (total == 0) {
        printf("Nenhum produto lido. Encerrando.\n");
        return 1;
    }

    printf("\nEscolha o campo para ordenar:\n");
    printf("1 - Descrição\n");
    printf("2 - Preço\n");
    printf("3 - Quantidade\n");
    printf("Opção: ");
    scanf("%d", &opcaoOrdenacao);

    ordenarProdutos(produtos, total, opcaoOrdenacao);

    printf("Nome do arquivo CSV de saída: ");
    scanf(" %99s", nomeArquivoSaida);

    salvarProdutos(nomeArquivoSaida, produtos, total);

    printf("Arquivo salvo com sucesso!\n");
    return 0;
}
