#include <stdio.h>
#include <stdlib.h>
#include "Algoritmos.h"

void mergesort(int *v, int inicio, int fim,long double comparacoes[], long double trocas[],int cod)
{
    int meio = (inicio + fim) / 2;

    if (fim > inicio)
    {
        mergesort(v, inicio, meio,comparacoes,trocas,cod);
        mergesort(v, meio + 1, fim,comparacoes,trocas,cod);
        merge(v, inicio, meio, fim,comparacoes,trocas,cod);
    }
}

void merge(int *v, int inicio, int meio, int fim,long double comparacoes[], long double trocas[],int cod)
{
    int *vetor_auxiliar = (int*) malloc (sizeof(int) * (fim - inicio + 1));

    if (!vetor_auxiliar)
    {
        printf ("Houve um erro ao alocar memória.\n");
        return;
    }

    int ponteiro_v1 = inicio;
    int ponteiro_v2 = meio + 1;
    int ponteiro_auxiliar = 0;

    while (ponteiro_v1 <= meio && ponteiro_v2 <= fim)
    {
        if (v[ponteiro_v1] <= v[ponteiro_v2])
        {

            vetor_auxiliar[ponteiro_auxiliar] = v[ponteiro_v1];
            ponteiro_v1++;

        } else {

            vetor_auxiliar[ponteiro_auxiliar] = v[ponteiro_v2];
            ponteiro_v2++;

        }
        trocas[cod]++;
        ponteiro_auxiliar++;
        comparacoes[cod]++;

    }

    if (ponteiro_v1 > meio)
    {
        for (int i = ponteiro_v2; i <= fim; i++)
        {
            vetor_auxiliar[ponteiro_auxiliar++] = v[i];
            trocas[cod]++;
        }

    } else {

        for (int i = ponteiro_v1; i <= meio; i++)
        {
            vetor_auxiliar[ponteiro_auxiliar++] = v[i];
            trocas[cod]++;
        }

    }

    ponteiro_auxiliar = 0;

    for (int i = inicio; i <= fim; i++)
    {
        v[i] = vetor_auxiliar[ponteiro_auxiliar++];
        trocas[cod]++;
    }

    free(vetor_auxiliar);
}