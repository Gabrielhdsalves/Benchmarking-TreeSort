//
// Created by Gabriel Alves on 07/04/2024.
//
#include "Algoritmos.h"
#include <stdio.h>
#include <stdlib.h>

void insertion(int vetor[], int tam,long double comparacao[],long double trocas[],int cod)  {
    int aux = 0, pos = 0;
    for(int marcador = 1; marcador < tam; marcador++) {
        pos = marcador -1;
        aux = vetor[marcador];
        comparacao[cod]++;
        while(pos>=0 && aux<vetor[pos]) {
            vetor[pos+1] = vetor[pos];
            comparacao[cod]++;
            trocas[cod]++;
            pos--;
        }
        vetor[pos+1] = aux;
        trocas[cod]++;
    }
}