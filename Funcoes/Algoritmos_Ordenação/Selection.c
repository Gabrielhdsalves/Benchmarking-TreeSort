#include "Algoritmos.h"

int sequencial(int vetor[], long double *comparacoes,int inicio, int tam) {
    int menor = inicio;
    for(int i=inicio+1;i<tam;i++) {
        if (vetor[menor] > vetor[i]) {
            menor = i;
        }
        (*comparacoes)++;
    }
    return menor;
}

void selection(int vetor[], int tam, long double comparacoes[], long double trocas[], int cod) {
    int sequencials = 0, aux = 0;
    for(int i=1;i<tam;i++) {
        sequencials = sequencial(vetor,&comparacoes[cod],i,tam);
        if(vetor[i-1] > vetor[sequencials]) {
            aux = vetor[i-1];
            vetor[i-1] = vetor[sequencials];
            vetor[sequencials] = aux;
            trocas[cod]++;
        }
        comparacoes[cod]++;
    }
}
