#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

int lerProdutos(const char* nomeArquivo, Produto vetor[], int tamanhoMaximo);
void ordenarProdutos(Produto vetor[], int n, int campo);
void salvarProdutos(const char* nomeArquivo, Produto vetor[], int n);

#endif