#include <stdio.h>
#include <stdlib.h>
#include "GeraVetor.h"
#include "iniciarFuncoes/iniciarFuncoes.h"


// Implementação das funções do arquivo GerarVetor.h
int* geraAleatorios(int tam, int semente)
{
    int *vetor = (int*)malloc(sizeof(int)*tam);

    if (vetor == NULL)
    {
        printf ("Erro ao alocar memória.\n");
        return NULL;
    }

    srand(semente); // Definindo a semente

    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand();
    }

    return vetor;
}

// Gera um vetor ordenado em ordem crescente descrescente
int* geraOrdenados(int tam, int ordem)
{
    int *vetor = (int*)malloc(sizeof(int)*tam);

    if (vetor == NULL)
    {
        printf ("Erro ao alocar memória.\n");
        return NULL;
    }

    if (ordem == 0)
    {
        // Ordem Crescente
        for (int i = 0; i < tam; i++) {
            vetor[i] = i;
        }
    } else {
        // Ordem Decrescente

        for (int i = 0; i < tam; i++) {
            vetor[i] = tam - i - 1; // Gerando valores de tam até 0
        }

    }
    return vetor;
}

// Gera um vetor quase ordenado com uma porcentagem escolhida pelo usuário
int* geraQuaseOrdenados(int tam, int porcentagem)
{
    int *vetor,indice_a, indice_b, auxiliar;
    float quantidade_Desordenada;
    vetor = geraOrdenados(tam, 0);
    // Gerando um vetor ordenado

    if (vetor == NULL)
    {
        printf ("Erro ao alocar memória.\n");
        return NULL;
    }


    quantidade_Desordenada = ((float)porcentagem/100)*(float)tam;
    // Quantidade de elementos que estarão desordenados

    if (quantidade_Desordenada >= 1) {
        for (int i = 0; i < quantidade_Desordenada / 2; i++) {
            indice_a = rand() % (tam - 1);
            indice_b = rand() % (tam - 1);
            // Obtendo o índice dos elementos a serem substituídos

            // Trocando os elementos
            auxiliar = vetor[indice_a];
            vetor[indice_a] = vetor[indice_b];
            vetor[indice_b] = auxiliar;
        }
    }
    return vetor;
}