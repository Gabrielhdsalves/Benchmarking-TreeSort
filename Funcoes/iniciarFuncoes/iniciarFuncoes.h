typedef struct metricas metricas;

void iniciarFuncoes_selection (int *tam, int n, int porcentagem);

void iniciarFuncoes_inserction (int *tam, int n, int porcentagem);

void iniciarFuncoes_merge (int *tam, int n, int porcentagem);

void iniciarFuncoes_quick (int *tam, int n, int porcentagem);

void iniciarFuncoes_tree (int *tam, int n, int porcentagem);

long double calculaTempo(int *vetor, int i, int ordem, metricas *selection_metricas, int *tam,int codigo);