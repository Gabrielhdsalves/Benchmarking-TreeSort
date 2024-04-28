#include <stdio.h>
#include <stdlib.h>
#include "TreeSort.h"

// Implementação das funções do arquivo TreeSort.h

struct no{
    struct no *direita, *esquerda;
    int elemento;
};

tno* inserir_arvore (tno *raiz, int elemento, long double comparacao[], int cod)
{
    if (!raiz)
    {
        // Elemento a inserir é a raiz

        tno *no = (tno *)malloc(sizeof(tno));

        if (!no)
        {
            return NULL;
        }

        no->elemento = elemento;
        no->direita  = NULL;
        no->esquerda = NULL;
        raiz = no;

    } else if (raiz->elemento >= elemento){
        // Nó a inserir é menor que a raiz, procurar a posição na sub-árvore esquerda
        comparacao[cod]++;
        raiz->esquerda = inserir_arvore(raiz->esquerda, elemento, comparacao, cod);
    }
    else {
        // Nó a inserir é maior que a raiz, procurar a posição na sub-árvore direita
        comparacao[cod]++;
        raiz->direita = inserir_arvore(raiz->direita, elemento, comparacao, cod);
    }

    return raiz;

}

int Percurso_Em_Ordem (tno *raiz, int *vetor, int indice, long double trocas[],int cod)
{

    if (raiz) {
        // Árvore não é nula

        // Percorre Sub-Árvore Esquerda e obtém o índice do próximo elemento desordenado do vetor
        indice = Percurso_Em_Ordem(raiz->esquerda, vetor, indice, trocas, cod);

        // Pega o elemento da raiz
        vetor[indice] = raiz->elemento;

        // Percorre Sub-Árvore Direita com o próximo índice do vetor
        indice = Percurso_Em_Ordem(raiz->direita, vetor, indice + 1, trocas, cod);

        // Libera o espaço da raiz
        free(raiz);

        trocas[cod]++;
    }

    return indice;
}

void TreeSort (int *vetor, int tamanho, long double comparacao[], long double trocas[],int cod)
{
    tno *raiz = NULL; // inicializando a árvore
    for (int i = 0; i < tamanho; i++)
    {
        raiz = inserir_arvore (raiz, vetor[i], comparacao, cod);
        trocas[cod]++;

        if (raiz == NULL)
        {
            printf ("Erro ao alocar memória.\n");
            return;
        }

    }
    // Saíndo do laço com todos os elementos dentro da árvore

    // Percurso em ordem para retirar todos os elementos da árvore já ordenado
    if (Percurso_Em_Ordem(raiz, vetor, 0, trocas, cod) < 0)
    {
        printf ("Houve uma falha no algoritmo do percurso em ordem.\n");
    }

    return;
}