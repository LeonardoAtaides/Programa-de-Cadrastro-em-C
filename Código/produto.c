#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <sys/stat.h>
#include "produto.h"


int lerProdutos(const char* nomeArquivo, Produto vetor[], int tamanhoMaximo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    int count = 0;
    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo) && count < tamanhoMaximo) {
        linha[strcspn(linha, "\n")] = 0;  // remove o \n

        char* token = strtok(linha, ",");
        if (token != NULL) strncpy(vetor[count].descricao, token, sizeof(vetor[count].descricao));

        token = strtok(NULL, ",");
        if (token != NULL) vetor[count].preco = (float) atof(token);  // cast explícito

        token = strtok(NULL, ",");
        if (token != NULL) vetor[count].quantidade = atoi(token);

        count++;
    }

    fclose(arquivo);
    return count;
}

void ordenarProdutos(Produto vetor[], int n, int campo) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            int comparar = 0;

            if (campo == 1) {
                comparar = strcmp(vetor[j].descricao, vetor[menor].descricao) < 0;
            } else if (campo == 2) {
                comparar = vetor[j].preco < vetor[menor].preco;
            } else if (campo == 3) {
                comparar = vetor[j].quantidade < vetor[menor].quantidade;
            }

            if (comparar) menor = j;
        }

        if (menor != i) {
            Produto temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

void salvarProdutos(const char* nomeArquivo, Produto vetor[], int n) {
    const char* pasta = "Produtos_Ordenados";
    if (mkdir(pasta) == -1) {
        printf("Pasta Identificada.\n");
    } else {
        printf("Pasta %s criada com sucesso.\n", pasta);
    }

    char caminhoArquivo[256];
    snprintf(caminhoArquivo, sizeof(caminhoArquivo), "%s/%s", pasta, nomeArquivo);

    FILE* arquivo = fopen(caminhoArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s.\n", caminhoArquivo);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%s,%.2f,%d\n", vetor[i].descricao, vetor[i].preco, vetor[i].quantidade);
    }

    fclose(arquivo);
    printf("Arquivo salvo em: %s\n", caminhoArquivo);
}
