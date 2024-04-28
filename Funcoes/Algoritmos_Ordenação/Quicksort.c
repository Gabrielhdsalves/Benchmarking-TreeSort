//
// Created by Gabriel Alves on 20/04/2024.
//
#include <stdio.h>
#include "Algoritmos.h"

int particiona(int V[], int inicio, int fim,long double comparacoes[],long double trocas[],int cod) {
    int pivo = V[inicio];
    int pos = inicio;
    int aux;
    for (int i = inicio + 1; i <= fim; i++) {
        if (V[i] < pivo) {
            pos = pos + 1;
            if (i != pos) {
                aux = V[i];
                V[i] = V[pos];
                V[pos] = aux;
                trocas[cod]++;
            }
        }
        comparacoes[cod]++;
    }
    aux = V[inicio];
    V[inicio] = V[pos];
    V[pos] = aux;
    trocas[cod]++;
    return pos;
}

void quickSort(int V[], int inicio, int fim,long double comparacoes[],long double trocas[],int cod) {
    if (inicio < fim) {
        int pivo = particiona(V, inicio, fim,comparacoes,trocas,cod);
        quickSort(V, inicio, pivo - 1,comparacoes,trocas,cod);
        quickSort(V, pivo + 1, fim,comparacoes,trocas,cod);
    }
}