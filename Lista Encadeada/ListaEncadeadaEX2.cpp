#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
  int info;
  struct lista * prox;
}; typedef struct lista Lista;

struct listaReais {
	float info;
	struct listaReais * prox;
}; typedef struct listaReais ListaReais;

Lista * inserirLista(Lista * lista, int valor, int &n){
  Lista * elem = (Lista*) malloc(sizeof(Lista));
  elem->info = valor;
  elem->prox = lista;
  n++;
  return elem;
}

// Exercicio 1 percorrer a lista e encontrar o valor maior que a lista
int maiores(Lista * lista, int n){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		if(elem->info > n){
			return n;
		}
	}
  return 1;
}
// Exercicio 2 retornar o ultimo valor
Lista * ultimo(Lista * l){
	Lista * elem;
	for(elem = l; elem != NULL; elem = elem->prox){
		if(elem->prox!=NULL){
			printf("\nO ultimo elemento da lista eh: %d",elem->info);
			return elem;
		}
	}
}

// Exercicio 3 criar duas listas encadeadas com valores reais e concatenalas

ListaReais * inserirNaLista(ListaReais * lista, float valor){
	ListaReais * elem = (ListaReais*) malloc(sizeof(ListaReais));
	elem->info = valor;
	elem->prox = lista;
	return elem;
}

ListaReais * concatena(ListaReais * l1,ListaReais * l2){
	ListaReais * elem;
	float ultimo, primeiro;
	
	ultimo = l1->info;
	
	if(elem->prox!=NULL){
	primeiro = l2->info;
	}
	
	printf("%.1f%.1f",ultimo,primeiro);
	return elem;
}


ListaReais * criarListaReais(){
  return NULL;
}
Lista * criarLista(){
  return NULL;
}
void imprimirReais(ListaReais * lista){
	ListaReais * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		printf("\nelemento: %.1f",elem->info);
	}
}

void imprimir(Lista * lista){
  Lista * elem;
  for(elem = lista; elem != NULL; elem = elem->prox){
    printf("info: %d\n",elem->info);
  	}
}

int main(){
  ListaReais * l1, *l2;
  Lista * lista;
  int cont = 0;
  lista = criarLista(); 
	
  // Exercicio 1:  
	
 /*lista = inserirLista(lista, 8, cont);
  lista = inserirLista(lista, 1, cont);
  lista = inserirLista(lista, 2, cont);
  lista = inserirLista(lista, 3, cont);
  lista = inserirLista(lista, 4, cont);
  lista = inserirLista(lista, 5, cont);
  
  imprimir(lista);

  printf("\nO numero maior de nos eh: %d",maiores(lista,cont));
  */
  // Exercicio 2:
  /*lista = inserirLista(lista, 8, cont);
  lista = inserirLista(lista, 1, cont);
  lista = inserirLista(lista, 2, cont);
  lista = inserirLista(lista, 3, cont);
  lista = inserirLista(lista, 4, cont);
  lista = inserirLista(lista, 5, cont);
  
  imprimir(lista);
  
  lista = ultimo(lista);*/
  // Exercicio 3
  l1 = criarListaReais();
  l2 = criarListaReais();
  
  l1 = inserirNaLista(l1, 1.5);
  l1 = inserirNaLista(l1, 2.2);
  l1 = inserirNaLista(l1, 3.5);
  l1 = inserirNaLista(l1, 4.2);
  l1 = inserirNaLista(l1, 5.5);
  
  l2 = inserirNaLista(l2, 6.5);
  l2 = inserirNaLista(l2, 7.2);
  l2 = inserirNaLista(l2, 8.5);
  l2 = inserirNaLista(l2, 9.2);
  l2 = inserirNaLista(l2, 10.5);
  
  printf("Lista 1\n");
  imprimirReais(l1);
  printf("\n\nLista 2\n");
  imprimirReais(l2);
  
  printf("\n\nConcatenacao:\n");
  
  concatena(l1,l2); // RESOLVER
	
  return 0;
}
