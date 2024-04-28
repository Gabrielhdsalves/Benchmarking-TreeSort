#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "iniciarFuncoes.h"

void menu(){
    int cod,n,*tam, porcentagem;
    printf("\nDigite a quantidade de testes que serao feitos:");
    scanf("%d",&n);
    tam = (int*)malloc(n*sizeof(int));
    printf("\nDigite o tamanho dos vetores dos testes:");
    for(int i=0;i<n;i++){
        scanf("%d",&tam[i]);
    }
    printf("\nDigite a porcentagem de elementos nao ordenados dos vetores quase ordenados:");
    scanf("%d",&porcentagem);
    do{
      printf("\nSelecione uma opcao:\n");
      printf("1-Selection\n");
      printf("2-Insertion\n");
      printf("3-Merge\n");
      printf("4-Quick\n");
      printf("5-Tree\n");
      printf("6-Todos\n");
      printf("0-Sair\n");
      scanf("%d",&cod);
      switch(cod){
          case 1:
              iniciarFuncoes_selection(tam,n,porcentagem);
              break;
          case 2:
              iniciarFuncoes_inserction(tam,n,porcentagem);
              break;
          case 3:
              iniciarFuncoes_merge(tam,n,porcentagem);
              break;
          case 4:
              iniciarFuncoes_quick(tam,n,porcentagem);
              break;
          case 5:
              iniciarFuncoes_tree(tam,n,porcentagem);
              break;
          case 0:
              break;
          default:
              iniciarFuncoes_selection(tam,n,porcentagem);
              iniciarFuncoes_inserction(tam,n,porcentagem);
              iniciarFuncoes_merge(tam,n,porcentagem);
              iniciarFuncoes_quick(tam,n,porcentagem);
              iniciarFuncoes_tree(tam,n,porcentagem);
      }
    }while(cod !=0);
    free(tam);
}