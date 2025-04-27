# README - Sistema de Ordenação de Produtos a partir de Arquivo CSV

## Visão Geral

Este projeto é um programa em C que:

- Lê produtos de um arquivo CSV.
- Permite ao usuário escolher o critério de ordenação (Descrição, Preço ou Quantidade).
- Salva os produtos ordenados em uma nova pasta chamada `Produtos_Ordenados`.

## Estrutura dos Arquivos

- **main.c**: Responsável pela interação com o usuário e pelo fluxo principal do programa.
- **produto.h**: Define a estrutura `Produto` e declara as funções auxiliares.
- **produto.c**: Implementação das funções:
  - `lerProdutos()`: Lê os produtos do arquivo CSV.
  - `ordenarProdutos()`: Ordena o vetor de produtos baseado no campo escolhido.
  - `salvarProdutos()`: Salva os produtos ordenados em arquivo CSV.
- **produtos.csv**: Exemplo de arquivo de entrada contendo os produtos.

## Como Executar

1. Compile os arquivos:

```bash
gcc main.c produto.c -o programa
```

2. Execute o programa:

```bash
./programa
```

3. Informe:
   - O nome do arquivo CSV de entrada.
   - O critério de ordenação (1- Descrição, 2- Preço, 3- Quantidade).
   - O nome do arquivo CSV de saída.

O programa irá criar a pasta `Produtos_Ordenados` (caso não exista) e salvará o arquivo ordenado dentro dela.

## Exemplo de Entrada CSV

```
Descricao,Preco,Quantidade
Apontador Duplo #6,2.93,99
Bloco Adesivo #14,2.98,58
Caderno Brochura #52,5.88,86
...
```

## Funcionalidades

- Suporte a caracteres especiais (português BR).
- Leitura segura de strings.
- Ordenação por diferentes campos.
- Criação automática da pasta de saída.
- Mensagens de erro claras.

## Requisitos

- Compilador C (GCC recomendado).
- Ambiente Windows para uso de `chcp 65001` (ou ajustar para outros SOs).

## Observações

- Certifique-se de que o arquivo CSV esteja formatado corretamente.
- A pasta `Produtos_Ordenados` será criada no mesmo diretório onde o programa for executado.
- O programa suporta no máximo 100 produtos por padrão (pode ser alterado em `#define MAX_PRODUTOS 100`).

## Autores
Leonardo Ataides dos Santos
Gabriel Bocacio Linder 
Joel Junior Carvalho de Oliveira
Matheus Martins Rios
Nathalia Cassimiro dos Santos
Pedro Henrique Fernandes 
Nicolas Mauricio e Silva
Vinicius Lobo Quirino
Rodrigo Junio Oliveira da Silva
