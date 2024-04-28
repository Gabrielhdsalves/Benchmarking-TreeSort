// Arquivo que especifica o funcionamento das funções do algoritmo TreeSort


typedef struct no tno; // Struct definida TreeSort.c


tno* inserir_arvore (tno *raiz, int elemento, long double comparacao[], int cod);
// Função que recebe a raiz da árvore e um elemento para inserir na árvore binária
// Função retorna a raiz da árvore

int Percurso_Em_Ordem (tno *raiz, int *vetor, int indice, long double trocas[],int cod);
// Função que percorre a árvore fazendo o percurso em ordem e guarda o elemento em um vetor
// Percorre sub-árvore esquerda
// Visita Raiz
// Percorre sub-árvore direita

void TreeSort (int *vetor, int tamanho, long double comparacao[], long double trocas[],int cod);
// Função que utilizará a função inserir_arvore e Percurso_Em_Ordem para realizar o TreeSort
