#define MAX_TXT 30

struct lde {
	struct lde* ant;
	char texto[MAX_TXT];
	struct lde* prox;
};

typedef struct lde LDE;
LDE * historicoAtual = NULL;


LDE* cria_lde()
{
	return NULL;
}

void destroi_lde()
{
	LDE* lde = historicoAtual;
    while (lde != NULL) {
        LDE* proximo = lde->prox;
        free(lde);
        lde = proximo;
    }
    historicoAtual = NULL;
}

bool inserir(char* url)
{
 if (historicoAtual == NULL) {
        return false;
    }
    
    LDE* novo = (LDE*) malloc(sizeof(LDE));
    if (novo == NULL) {
        return false;
    }
    
    strcpy(novo->texto, url);
    novo->ant = historicoAtual;
    novo->prox = NULL;
    
    if (historicoAtual->prox != NULL) {
        historicoAtual->prox->ant = novo;
    }
    historicoAtual->prox = novo;
    historicoAtual = novo;
    
    return true;

}

void definePaginaInicial(char* url)
{
	if (historicoAtual != NULL) {
        destroi_lde();
    }
    
    historicoAtual = (LDE*) malloc(sizeof(LDE));
    if (historicoAtual == NULL) {
        return;
    }
    
    strcpy(historicoAtual->texto, url);
    historicoAtual->ant = NULL;
    historicoAtual->prox = NULL;

}

void visitar(char* url)
{	
	 inserir(url);
	 printf("visitando %s \n", url);
}

char* voltar(int qtd)
{	
	int i;
    for (i = 0; i < qtd && historicoAtual->ant != NULL; i++) {
        historicoAtual = historicoAtual->ant;
    }
    printf("voltar %d\n", qtd);
    return historicoAtual->texto;
}

char* avancar(int qtd)
{	
	int i;
    for (i = 0; i < qtd && historicoAtual->prox != NULL; i++) {
        historicoAtual = historicoAtual->prox;
    }
    
    printf("avancar %d\n", qtd);
    return historicoAtual->texto;
}

bool comparar(char* url)
{
	if (historicoAtual== NULL)
		return false;
	printf("comparando %s == %s \n",historicoAtual->texto, url);
	return strcmp(historicoAtual->texto, url)==0;
}
