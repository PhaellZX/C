#include <stdio.h>
#include <stdlib.h>

struct lista {
	int info;
	struct lista * prox;
}; typedef struct lista Lista;

// Cria a Lista (vazia)

Lista * criaLista(){
	return NULL;
}

// Inserir no inicio da lista - usando Lista * com retorno

Lista * lista_insere_inicio(Lista * lista, int valor){
	Lista * novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = lista;
	return novo;	
}

// Inserir no inicio da lista - usando void sem retorno 

void lst_insere_inicio(Lista ** lista, int valor){
	Lista * novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = *lista;
}


// Inserir no fim da lista

Lista * lista_insere_fim(Lista * lista, int valor){
      if (lista->prox == NULL) {
        lista->info = valor;

      } else {
        Lista * elem = NULL;
        for(elem = lista; elem->prox != NULL; elem = elem->prox);
        Lista * novo = (Lista*)malloc(sizeof(Lista));
        novo->info = valor;
        novo->prox = NULL;
        elem->prox = novo;
      }
      return lista;
}

// Tamanho da Lista

int comprimento(Lista * l){
	Lista * elem;
	int tamanho = 0;
	for(elem = l; elem != NULL; elem = elem->prox){
	tamanho++;   }
	return tamanho;
		}

// Selecionar a posição e inseri-lá

Lista * insere_posicao(Lista * lista, int valor, int pos){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		if(elem->info==pos){
		lista = (Lista*) malloc(sizeof(Lista));
		elem->info = valor;
		
		return elem;
	}
	}
	return NULL;
}

// Selecionar e remover da lista

Lista * remover_lista(Lista * lista, int valor){
	Lista * ant = NULL;  // ponteira para elemento anterior
	Lista * elem = lista; //ponteiro para percorrer a lista
	
	//procura elemento, guardando anterior
	while(elem != NULL && elem->info != valor){
		ant = elem;
		elem = elem->prox;
	}
	
	// verificar se elemento foi encontrado
	if(elem == NULL)
	    return lista; //não encontrou, retorna lista original
	
	//remove elemento    
	if(ant == NULL){
	    lista = elem->prox; //remove elemento do inicio
	} else {
		ant->prox = elem->prox; // remove elemento do meio
	}
	
	free(elem);
	return lista;
}

// Imprimir lista

void imprimirLista(Lista * lista){
	Lista * elem;
	int pos = 0;
	for(elem = lista; elem != NULL; elem = elem->prox)
	printf("info = %d\n",elem->info);
	
}

void lista_libera(Lista* lista){
     Lista* elem = lista;
     while (elem != NULL){
     Lista* temp = elem->prox; //ref para prox elemento
     free(elem);
     elem = temp;
     }
}

int main(){
	Lista * lista;
	lista = criaLista();
	lista = lista_insere_inicio(lista,1);
	lista = lista_insere_inicio(lista,2);
	lista = lista_insere_inicio(lista,3);
	lista = lista_insere_inicio(lista,4);
	lista = lista_insere_inicio(lista,5);
	
	/* Exercicio 1 - inserir num final da lista
	
	lista = lista_insere_fim(lista,1);
	lista = lista_insere_fim(lista,2);
	lista = lista_insere_fim(lista,3);
	lista = lista_insere_fim(lista,4);
	lista = lista_insere_fim(lista,5);
	
	*/
	
	/* Exercicio 2 - Tamanho da lista
	imprimirLista(lista);
	printf("\nO tamanho da lista: %d",comprimento(lista));
	return 0;
	*/
	
	int valor, pos;
	
	/* Exercicio 3 - Selecionar e alterar o valor
	printf("Digite um valor da lista:");
	scanf("%d",&pos);
	printf("Digite um valor para substituir:");
	scanf("%d",&valor);
	
	insere_posicao(lista,valor,pos);
	
	imprimirLista(lista);*/
	
	/* Exercicio 4 - Selecionar remover da Lista 
	printf("Digite um valor para excluir:");
	scanf("%d",&valor);
	
	lista = remover_lista(lista,valor);
	
	imprimirLista(lista);
	*/
	// Exercicio 5
	
	lst_insere_inicio(&lista,1);
	lst_insere_inicio(&lista,2);
	lst_insere_inicio(&lista,3);
	lst_insere_inicio(&lista,4);
	lst_insere_inicio(&lista,5);
	
	//lista_libera(lista);
	
	imprimirLista(lista);
	
	return 0;
	
}
