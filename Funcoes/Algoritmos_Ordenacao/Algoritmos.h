// Arquivo da interface das funções dos seguintes algoritmos de ordenação:
// Seleção, Inserção, MergeSort, QuickSort

// Algoritmo que retorna a posição do menor elemento do vetor no intervalo especificado
int sequencial(int vetor[], long double *comparacoes,int inicio, int tam);

// Função que ordena um vetor usando o método seleção
void selection(int vetor[], int tam,long double comparacoes[], long double trocas[],int cod);

// Função que ordena um vetor usando o método inserção
void insertion(int vetor[], int tam,long double comparacao[], long double trocas[],int cod);

// Função que ordena um vetor usando o método MergeSort
void mergesort(int *v, int inicio, int fim,long double comparacoes[], long double trocas[],int cod);

// Função que junta dois vetores previamente ordenados em um novo de forma ordenada
void merge(int *v, int inicio, int meio, int fim,long double comparacoes[], long double trocas[],int cod);

// Função que particiona e coloca o pivo na posição correta.
int particiona(int V[], int inicio, int fim,long double comparacoes[],long double trocas[],int cod);

// Função que ordena um vetor usando o método quickSort
void quickSort(int V[], int inicio, int fim,long double comparacoes[],long double trocas[],int cod);
