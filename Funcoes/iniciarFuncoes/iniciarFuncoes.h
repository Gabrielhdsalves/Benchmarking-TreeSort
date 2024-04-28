typedef struct metricas metricas;

// Essas funcoes executam os testes dos algoritmos, utilizando a struct metricas para armazenar o tempo, as comparacoes e as trocas
// para cada teste, vetor aleatorio, vetor crescente, vetor decrescente e vetor quase ordenado.
// Ao final dos testes e impresso uma tabela referente as 3 metricas estabelecidas para cada caso

void iniciarFuncoes_selection (int *tam, int n, int porcentagem);

void iniciarFuncoes_inserction (int *tam, int n, int porcentagem);

void iniciarFuncoes_merge (int *tam, int n, int porcentagem);

void iniciarFuncoes_quick (int *tam, int n, int porcentagem);

void iniciarFuncoes_tree (int *tam, int n, int porcentagem);

long double calculaTempo(int *vetor, int i, int ordem, metricas *selection_metricas, int *tam,int codigo);
// Funcao que, dado um codigo, chama a funcao de ordenacao relativo ao codigo para ordenar o vetor passado como parametro