#include <stdio.h>
#include <stdlib.h>

struct lista {
	int valor;
	struct lista * prox;
}; typedef struct lista Lista;

// Cria a Lista (vazia)

Lista * criaLista(){
	return NULL;
}

// Método que insere e ordena automaticamente os valores 

void lista_insere(Lista ** lista, int num){ //Obs: Utilizei o ponteiro do ponteiro
	Lista * novo = (Lista*) malloc(sizeof(Lista)); 
	Lista * atual; // Cria a lista atual
	Lista * anterior; // Cria a lista anterior
	
	atual = *lista; // ao iniciar o atual vai receber o ponteiro da lista
	anterior = NULL; // e o anterior vai receber null
	novo->valor = num; // adiciona um valor na lista
	
	if(atual==NULL){ //Se o atual for igual a NULL
		novo->prox = NULL; // O ponteiro do proximo vai receber NULL
		*lista = novo;	// Lista será NULL
	} else {
		while(atual != NULL && atual->valor < num){ // Quando o valor atual da lista for diferente de NULL e quando o valor atual for menor que o valor adicionado
			anterior = atual; // O valor anterior vai ser o atual
			atual = atual->prox; // e o atual aponta para o próximo valor
		}
		
		novo->prox = atual; // ponteiro aponta para o atual
		
		if(anterior == NULL){ // se o valor for igual NULL
			*lista = novo; // Lista recebe os valores atuais
		} else {
			anterior->prox = novo; // ponteiro aponta para a lista atual 
		}
	}
}

// Imprimir lista

void imprimirLista(Lista * lista){ 
	Lista * elem;
	int pos = 0;
	for(elem = lista; elem != NULL; elem = elem->prox)
	printf("info = %d\n",elem->valor);
	
}

int main(){
	Lista * lista = NULL;
	lista = criaLista();
	lista_insere(&lista,20);
	lista_insere(&lista,6);
	lista_insere(&lista,8);
	lista_insere(&lista,12);
	lista_insere(&lista,1);
	lista_insere(&lista,55);
	lista_insere(&lista,30);
	lista_insere(&lista,24);
	
	imprimirLista(lista);
	
	return 0;
	
}
