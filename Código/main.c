#include <stdio.h>
#include <locale.h>
#include <stdlib.h> 
#include "produto.h"
#include "produto.c"

#define MAX_PRODUTOS 100

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    system("chcp 65001 > nul");

    Produto produtos[MAX_PRODUTOS];
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    int total, opcaoOrdenacao;
    int primeiraTentativa = 1;

    printf("Nome do arquivo CSV de entrada: ");
    scanf(" %99[^\n]", nomeArquivoEntrada);

    total = lerProdutos(nomeArquivoEntrada, produtos, MAX_PRODUTOS);
    if (total == 0) {
        printf("Nenhum produto lido. Encerrando.\n");
        return 1;   
    }

    do {
        if (!primeiraTentativa) {
            printf("Opção inválida! Por favor, escolha: [ 1 | 2 | 3 ]\n");
        }
        printf("\nEscolha o campo para ordenar:\n");
        printf("1 - Descrição\n");
        printf("2 - Preço\n");
        printf("3 - Quantidade\n");
        printf("Opção: ");
        scanf("%d", &opcaoOrdenacao);
        primeiraTentativa = 0;
    } while (opcaoOrdenacao < 1 || opcaoOrdenacao > 3);

    ordenarProdutos(produtos, total, opcaoOrdenacao);

    printf("Nome do arquivo CSV de saída: ");
    scanf(" %99s", nomeArquivoSaida);

    salvarProdutos(nomeArquivoSaida, produtos, total);

    printf("Arquivo salvo com sucesso!\n");
    return 0;
}
