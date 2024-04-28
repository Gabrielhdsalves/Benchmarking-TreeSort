//
// Created by tiago on 10/04/2024.
//
#include <stdio.h>
#include "Tabela.h"
#include "iniciarFuncoes/iniciarFuncoes.h"

struct metricas {
    long double *trocas;
    long double *comparacoes;
    long double *tempo;
};

void selectionTabela(int *tam, metricas *m,int n) {
    printf ("\n");
    printf("SELECTION SORT\n");
    printf("TEMPO\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.3Lf%9s%12.3Lf%10s%12.3Lf%11s%12.3Lf%11s\n", i+1, "|", tam[i], "|", m[0].tempo[i], "|", m[1].tempo[i], "|", m[2].tempo[i], "|", m[3].tempo[i], "|");
    printf ("\n");
    printf("TROCAS\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].trocas[i], "|", m[1].trocas[i], "|", m[2].trocas[i], "|", m[3].trocas[i], "|");
    printf ("\n");
    printf("COMPARACOES\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].comparacoes[i], "|", m[1].comparacoes[i], "|", m[2].comparacoes[i], "|", m[3].comparacoes[i], "|");
    printf ("\n");
}
void inserctionTabela(int *tam, metricas *m,int n) {
    printf("INSERCTION SORT\n");
    printf("TEMPO\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.3Lf%9s%12.3Lf%10s%12.3Lf%11s%12.3Lf%11s\n", i+1, "|", tam[i], "|", m[0].tempo[i], "|", m[1].tempo[i], "|", m[2].tempo[i], "|", m[3].tempo[i], "|");
    printf ("\n");
    printf("TROCAS\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].trocas[i], "|", m[1].trocas[i], "|", m[2].trocas[i], "|", m[3].trocas[i], "|");
    printf ("\n");
    printf("COMPARACOES\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].comparacoes[i], "|", m[1].comparacoes[i], "|", m[2].comparacoes[i], "|", m[3].comparacoes[i], "|");
    printf ("\n");
}
void mergeTabela(int *tam, metricas *m,int n) {
    printf("MERGE SORT\n");
    printf("TEMPO\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.3Lf%9s%12.3Lf%10s%12.3Lf%11s%12.3Lf%11s\n", i+1, "|", tam[i], "|", m[0].tempo[i], "|", m[1].tempo[i], "|", m[2].tempo[i], "|", m[3].tempo[i], "|");
    printf ("\n");
    printf("TROCAS\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].trocas[i], "|", m[1].trocas[i], "|", m[2].trocas[i], "|", m[3].trocas[i], "|");
    printf ("\n");
    printf("COMPARACOES\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].comparacoes[i], "|", m[1].comparacoes[i], "|", m[2].comparacoes[i], "|", m[3].comparacoes[i], "|");
    printf ("\n");
}
void quickTabela(int *tam, metricas *m,int n){
    printf("QUICK SORT\n");
    printf("TEMPO\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.3Lf%9s%12.3Lf%10s%12.3Lf%11s%12.3Lf%11s\n", i+1, "|", tam[i], "|", m[0].tempo[i], "|", m[1].tempo[i], "|", m[2].tempo[i], "|", m[3].tempo[i], "|");
    printf ("\n");
    printf("TROCAS\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].trocas[i], "|", m[1].trocas[i], "|", m[2].trocas[i], "|", m[3].trocas[i], "|");
    printf ("\n");
    printf("COMPARACOES\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].comparacoes[i], "|", m[1].comparacoes[i], "|", m[2].comparacoes[i], "|", m[3].comparacoes[i], "|");
    printf ("\n");
}
void treeTabela(int *tam, metricas *m,int n) {
    printf("TREE SORT\n");
    printf("TEMPO\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.3Lf%9s%12.3Lf%10s%12.3Lf%11s%12.3Lf%11s\n", i+1, "|", tam[i], "|", m[0].tempo[i], "|", m[1].tempo[i], "|", m[2].tempo[i], "|", m[3].tempo[i], "|");
    printf ("\n");
    printf("TROCAS\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].trocas[i], "|", m[1].trocas[i], "|", m[2].trocas[i], "|", m[3].trocas[i], "|");
    printf ("\n");
    printf("COMPARACOES\n");
    printf("%s%2s%18s%4s%15s%6s%18s%4s%19s%4s%18s%5s \n","TESTE","|","TAMANHO ENTRADA","|","ALEATORIO","|","ORDEM CRESCENTE","|","ORDEM DECRESCENTE","|","QUASE ORDENADO","|");
    for (int i = 0; i < n; i++)
        printf("%3d%4s%9d%13s%12.0Lf%9s%12.0Lf%10s%12.0Lf%11s%12.0Lf%11s\n", i+1, "|", tam[i], "|", m[0].comparacoes[i], "|", m[1].comparacoes[i], "|", m[2].comparacoes[i], "|", m[3].comparacoes[i], "|");
    printf ("\n");
}