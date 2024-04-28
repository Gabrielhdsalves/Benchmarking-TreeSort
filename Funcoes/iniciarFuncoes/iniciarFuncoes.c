#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TreeSort.h"
#include "GeraVetor.h"
#include "Algoritmos.h"
#include "iniciarFuncoes.h"
#include "Tabela.h"
#define COD_SELECAO 0
#define COD_INSERCAO 1
#define COD_MERGE 2
#define COD_QUICK 3
#define COD_TREE 4
#define QTDMETRICA 4

struct metricas {
    long double *trocas;
    long double *comparacoes;
    long double *tempo;
};


// Inicia os testes do selection
void iniciarFuncoes_selection(int *tam, int n, int porcentagem) {
    metricas *selection_metricas = (metricas *) malloc(sizeof(metricas) * 4);
    int *vetor;
    long double tempo_soma;
    clock_t inicio, final;

    if (!selection_metricas) {
        printf("Erro\n");
        return;
    }

    // Aloca espaço para as 4 informações
    for (int i = 0; i < QTDMETRICA; i++) {
        selection_metricas[i].trocas = (long double *) malloc(sizeof(long double) * n);
        selection_metricas[i].comparacoes = (long double *) malloc(sizeof(long double) * n);
        selection_metricas[i].tempo = (long double *) malloc(sizeof(long double) * n);

        if (!selection_metricas[i].trocas || !selection_metricas[i].comparacoes ||
            !selection_metricas[i].tempo) {
            printf("Erro\n");
            return;
        }
    }

    // Inicializa todos os valores como 0
    for (int j = 0; j < QTDMETRICA; j++) {
        for (int i = 0; i < n; i++) {
            selection_metricas[j].comparacoes[i] = 0;
            selection_metricas[j].trocas[i] = 0;
            selection_metricas[j].tempo[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        // Aleatórios
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraAleatorios(tam[i], j + 1595);
            tempo_soma += calculaTempo(vetor, i, 0, selection_metricas, tam, COD_SELECAO);
            free(vetor);
        }
        selection_metricas[0].tempo[i] = tempo_soma / 5;
        selection_metricas[0].trocas[i] = (selection_metricas[0].trocas[i] / 5);
        selection_metricas[0].comparacoes[i] = (selection_metricas[0].comparacoes[i] / 5);

        // Crescente
        vetor = geraOrdenados(tam[i], 0);
        tempo_soma = calculaTempo(vetor, i, 1, selection_metricas, tam, COD_SELECAO);
        free(vetor);
        selection_metricas[1].tempo[i] = tempo_soma;

        // Decrescente
        vetor = geraOrdenados(tam[i], 1);
        tempo_soma = calculaTempo(vetor, i, 2, selection_metricas, tam,COD_SELECAO);
        free(vetor);
        selection_metricas[2].tempo[i] = tempo_soma;

        // Quase ordenados
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraQuaseOrdenados(tam[i], porcentagem);
            tempo_soma += calculaTempo(vetor, i, 3, selection_metricas, tam, COD_SELECAO);
            free(vetor);
        }

        selection_metricas[3].tempo[i] = tempo_soma / 5;
        selection_metricas[3].trocas[i] = (selection_metricas[3].trocas[i] / 5);
        selection_metricas[3].comparacoes[i] = (selection_metricas[3].comparacoes[i] / 5);
    }

    selectionTabela(tam, selection_metricas, n);

    for (int i = 0; i < QTDMETRICA; i++)
    {
            free(selection_metricas[i].trocas);
            free(selection_metricas[i].comparacoes);
            free(selection_metricas[i].tempo);
    }

    free (selection_metricas);
    return;
}

// Inicia os testes do inserction
void iniciarFuncoes_inserction(int *tam, int n, int porcentagem) {
    metricas *inserction_metricas = (metricas *) malloc(sizeof(metricas) * 4);
    int *vetor;
    long double tempo_soma;
    clock_t inicio, final;

    if (!inserction_metricas) {
        printf("Erro\n");
        return;
    }

    // Aloca espaço para as 4 informações
    for (int i = 0; i < QTDMETRICA; i++) {
        inserction_metricas[i].trocas = (long double *) malloc(sizeof(long double) * n);
        inserction_metricas[i].comparacoes = (long double *) malloc(sizeof(long double) * n);
        inserction_metricas[i].tempo = (long double *) malloc(sizeof(long double) * n);

        if (!inserction_metricas[i].trocas || !inserction_metricas[i].comparacoes ||
            !inserction_metricas[i].tempo) {
            printf("Erro\n");
            return;
        }
    }

    // Inicializa todos os valores como 0
    for (int j = 0; j < QTDMETRICA; j++) {
        for (int i = 0; i < n; i++) {
            inserction_metricas[j].comparacoes[i] = 0;
            inserction_metricas[j].trocas[i] = 0;
            inserction_metricas[j].tempo[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        // Aleatórios
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraAleatorios(tam[i], j + 1595);
            tempo_soma += calculaTempo(vetor, i, 0, inserction_metricas, tam,COD_INSERCAO);
            free(vetor);
        }
        inserction_metricas[0].tempo[i] = tempo_soma / 5;
        inserction_metricas[0].trocas[i] = (inserction_metricas[0].trocas[i] / 5);
        inserction_metricas[0].comparacoes[i] = (inserction_metricas[0].comparacoes[i] / 5);

        // Crescente
        vetor = geraOrdenados(tam[i], 0);
        tempo_soma = calculaTempo(vetor, i, 1, inserction_metricas, tam,COD_INSERCAO);
        free(vetor);
        inserction_metricas[1].tempo[i] = tempo_soma;

        // Decrescente
        vetor = geraOrdenados(tam[i], 1);
        tempo_soma = calculaTempo(vetor, i, 2, inserction_metricas, tam,COD_INSERCAO);
        free(vetor);
        inserction_metricas[2].tempo[i] = tempo_soma;

        // Quase ordenados
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraQuaseOrdenados(tam[i], porcentagem);
            tempo_soma += calculaTempo(vetor, i, 3, inserction_metricas, tam,COD_INSERCAO);
            free(vetor);
        }

        inserction_metricas[3].tempo[i] = tempo_soma / 5;
        inserction_metricas[3].trocas[i] = (inserction_metricas[3].trocas[i] / 5);
        inserction_metricas[3].comparacoes[i] = (inserction_metricas[3].comparacoes[i] / 5);
    }

    inserctionTabela(tam, inserction_metricas, n);

    for (int i = 0; i < QTDMETRICA; i++) {
        free(inserction_metricas[i].trocas);
        free(inserction_metricas[i].comparacoes);
        free(inserction_metricas[i].tempo);
    }

    free (inserction_metricas);

    return;
}

// Inicia os testes do merge
void iniciarFuncoes_merge(int *tam, int n, int porcentagem) {
    metricas *merge_metricas = (metricas *) malloc(sizeof(metricas) * 4);
    int *vetor;
    long double tempo_soma;
    clock_t inicio, final;

    if (!merge_metricas) {
        printf("Erro\n");
        return;
    }

    // Aloca espaço para as 4 informações
    for (int i = 0; i < QTDMETRICA; i++) {
        merge_metricas[i].trocas = (long double *) malloc(sizeof(long double) * n);
        merge_metricas[i].comparacoes = (long double *) malloc(sizeof(long double) * n);
        merge_metricas[i].tempo = (long double *) malloc(sizeof(long double) * n);

        if (!merge_metricas[i].trocas || !merge_metricas[i].comparacoes ||
            !merge_metricas[i].tempo) {
            printf("Erro\n");
            return;
        }
    }

    // Inicializa todos os valores como 0
    for (int j = 0; j < QTDMETRICA; j++) {
        for (int i = 0; i < n; i++) {
            merge_metricas[j].comparacoes[i] = 0;
            merge_metricas[j].trocas[i] = 0;
            merge_metricas[j].tempo[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        // Aleatórios
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraAleatorios(tam[i], j);
            tempo_soma += calculaTempo(vetor, i, 0, merge_metricas, tam,COD_MERGE);
            free(vetor);
        }
        merge_metricas[0].tempo[i] = tempo_soma / 5;
        merge_metricas[0].trocas[i] = (merge_metricas[0].trocas[i] / 5);
        merge_metricas[0].comparacoes[i] = (merge_metricas[0].comparacoes[i] / 5);

        // Crescente
        vetor = geraOrdenados(tam[i], 0);
        tempo_soma = calculaTempo(vetor, i, 1, merge_metricas, tam,COD_MERGE);
        free(vetor);
        merge_metricas[1].tempo[i] = tempo_soma;

        // Decrescente
        vetor = geraOrdenados(tam[i], 1);
        tempo_soma = calculaTempo(vetor, i, 2, merge_metricas, tam,COD_MERGE);
        free(vetor);
        merge_metricas[2].tempo[i] = tempo_soma;

        // Quase ordenados
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraQuaseOrdenados(tam[i], porcentagem);
            tempo_soma += calculaTempo(vetor, i, 3, merge_metricas, tam,COD_MERGE);
            free(vetor);
        }

        merge_metricas[3].tempo[i] = tempo_soma / 5;
        merge_metricas[3].trocas[i] = (merge_metricas[3].trocas[i] / 5);
        merge_metricas[3].comparacoes[i] = (merge_metricas[3].comparacoes[i] / 5);
    }

    mergeTabela(tam, merge_metricas, n);

    for (int i = 0; i < QTDMETRICA; i++) {
        free(merge_metricas[i].trocas);
        free(merge_metricas[i].comparacoes);
        free(merge_metricas[i].tempo);
    }

    free (merge_metricas);

    return;
}

// Inicia os testes do quick
void iniciarFuncoes_quick(int *tam, int n, int porcentagem) {
    metricas *quick_metricas = (metricas *) malloc(sizeof(metricas) * 4);
    int *vetor;
    long double tempo_soma;
    clock_t inicio, final;

    if (!quick_metricas) {
        printf("Erro\n");
        return;
    }

    // Aloca espaço para as 4 informações
    for (int i = 0; i < QTDMETRICA; i++) {
        quick_metricas[i].trocas = (long double *) malloc(sizeof(long double) * n);
        quick_metricas[i].comparacoes = (long double *) malloc(sizeof(long double) * n);
        quick_metricas[i].tempo = (long double *) malloc(sizeof(long double) * n);

        if (!quick_metricas[i].trocas || !quick_metricas[i].comparacoes ||
            !quick_metricas[i].tempo) {
            printf("Erro\n");
            return;
        }
    }

    // Inicializa todos os valores como 0
    for (int j = 0; j < QTDMETRICA; j++) {
        for (int i = 0; i < n; i++) {
            quick_metricas[j].comparacoes[i] = 0;
            quick_metricas[j].trocas[i] = 0;
            quick_metricas[j].tempo[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        // Aleatórios
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraAleatorios(tam[i], j + 1595);
            tempo_soma += calculaTempo(vetor, i, 0, quick_metricas, tam,COD_QUICK);
            free(vetor);
        }
        quick_metricas[0].tempo[i] = tempo_soma / 5;
        quick_metricas[0].trocas[i] = (quick_metricas[0].trocas[i] / 5);
        quick_metricas[0].comparacoes[i] = (quick_metricas[0].comparacoes[i] / 5);

        printf ("Terminei Aleatorio %d\n", tam[i]);

        // Crescente
        vetor = geraOrdenados(tam[i], 0);
        tempo_soma = calculaTempo(vetor, i, 1, quick_metricas, tam,COD_QUICK);
        free(vetor);
        quick_metricas[1].tempo[i] = tempo_soma;

        printf ("Terminei Crescente %d\n", tam[i]);

        // Decrescente
        vetor = geraOrdenados(tam[i], 1);
        tempo_soma = calculaTempo(vetor, i, 2, quick_metricas, tam,COD_QUICK);
        free(vetor);
        quick_metricas[2].tempo[i] = tempo_soma;

        printf ("Terminei Decrescente %d\n", tam[i]);

        // Quase ordenados
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraQuaseOrdenados(tam[i], porcentagem);
            tempo_soma += calculaTempo(vetor, i, 3, quick_metricas, tam,COD_QUICK);
            free(vetor);
            printf ("Terminei quase ordenado %d %d\n", tam[i], j);
        }

        quick_metricas[3].tempo[i] = tempo_soma / 5;
        quick_metricas[3].trocas[i] = (quick_metricas[3].trocas[i] / 5);
        quick_metricas[3].comparacoes[i] = (quick_metricas[3].comparacoes[i] / 5);
        printf ("Terminei quase ordenado %d\n", tam[i]);
    }

    quickTabela(tam, quick_metricas, n);

    for (int i = 0; i < QTDMETRICA; i++) {
        free(quick_metricas[i].trocas);
        free(quick_metricas[i].comparacoes);
        free(quick_metricas[i].tempo);
    }
    free (quick_metricas);
    return;
}

// Inicia os testes do tree
void iniciarFuncoes_tree(int *tam, int n, int porcentagem) {
    metricas *treesort_metricas = (metricas *) malloc(sizeof(metricas) * 4);
    int *vetor;
    long double tempo_soma;
    clock_t inicio, final;

    if (!treesort_metricas) {
        printf("Erro\n");
        return;
    }

    // Aloca espaço para as 4 informações
    for (int i = 0; i < QTDMETRICA; i++) {
        treesort_metricas[i].trocas = (long double *) malloc(sizeof(long double) * n);
        treesort_metricas[i].comparacoes = (long double *) malloc(sizeof(long double) * n);
        treesort_metricas[i].tempo = (long double *) malloc(sizeof(long double) * n);

        if (!treesort_metricas[i].trocas || !treesort_metricas[i].comparacoes ||
            !treesort_metricas[i].tempo) {
            printf("Erro\n");
            return;
        }
    }
    // Inicializa todos os valores como 0
    for (int j = 0; j < QTDMETRICA; j++) {
        for (int i = 0; i < n; i++) {
            treesort_metricas[j].comparacoes[i] = 0;
            treesort_metricas[j].trocas[i] = 0;
            treesort_metricas[j].tempo[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        // Aleatórios
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraAleatorios(tam[i], j + 1595);
            tempo_soma += calculaTempo(vetor, i, 0, treesort_metricas, tam, COD_TREE);
            free(vetor);
        }
        treesort_metricas[0].tempo[i] = tempo_soma / 5;
        treesort_metricas[0].trocas[i] = (treesort_metricas[0].trocas[i] / 5);
        treesort_metricas[0].comparacoes[i] = (treesort_metricas[0].comparacoes[i] / 5);

        printf ("Tree Terminei aleatório %d\n", tam[i]);

        // Crescente
        vetor = geraOrdenados(tam[i], 0);
        tempo_soma = calculaTempo(vetor, i, 1, treesort_metricas, tam, COD_TREE);
        free(vetor);
        treesort_metricas[1].tempo[i] = tempo_soma;

        printf ("Tree Terminei Crescente %d\n", tam[i]);

        // Decrescente
        vetor = geraOrdenados(tam[i], 1);
        tempo_soma = calculaTempo(vetor, i, 2, treesort_metricas, tam, COD_TREE);
        free(vetor);
        treesort_metricas[2].tempo[i] = tempo_soma;

        printf ("Tree Terminei Decrescente %d\n", tam[i]);

        // Quase ordenados
        tempo_soma = 0;
        for (int j = 0; j < 5; j++) {
            vetor = geraQuaseOrdenados(tam[i], porcentagem);
            tempo_soma += calculaTempo(vetor, i, 3, treesort_metricas, tam, COD_TREE);
            free(vetor);
            printf ("Tree Terminei quase ordenado %d %d\n", tam[i], j);
        }
        treesort_metricas[3].tempo[i] = tempo_soma / 5;
        treesort_metricas[3].trocas[i] = (treesort_metricas[3].trocas[i] / 5);
        treesort_metricas[3].comparacoes[i] = (treesort_metricas[3].comparacoes[i] / 5);
    }

    treeTabela(tam, treesort_metricas, n);

    for (int i = 0; i < QTDMETRICA; i++)
    {
        free(treesort_metricas[i].trocas);
        free(treesort_metricas[i].comparacoes);
        free(treesort_metricas[i].tempo);
    }
    free (treesort_metricas);
    return;
}

// Retorna o tempo obtido
long double calculaTempo(int *vetor, int i, int ordem, metricas *metricas, int *tam, int codigo) {
    long double tempo_soma = 0;
    clock_t inicio, final;
    inicio = clock();
    switch (codigo) {
        case 0:
            selection(vetor, tam[i], metricas[ordem].comparacoes, metricas[ordem].trocas, i);
            break;
        case 1:
            insertion(vetor, tam[i], metricas[ordem].comparacoes, metricas[ordem].trocas, i);
            break;
        case 2:
            mergesort(vetor, 0, tam[i] - 1, metricas[ordem].comparacoes, metricas[ordem].trocas, i);
            break;
        case 3:
            quickSort(vetor, 0, tam[i] - 1, metricas[ordem].comparacoes, metricas[ordem].trocas, i);
            break;
        case 4:
             TreeSort(vetor, tam[i], metricas[ordem].comparacoes, metricas[ordem].trocas, i);
             break;
    }
    final = clock();
    tempo_soma += ((float) (final - inicio) / (CLOCKS_PER_SEC));
    return tempo_soma;
}