#include <stdio.h>
#include <stdlib.h>

struct listaDupla {
	int info;
	struct listaDupla * prox;
	struct listaDupla * ant;
}; typedef struct listaDupla ListaDupla;

listaDupla * criaLista(){
	return NULL;
}

listaDupla * listaInsereInicio(listaDupla * lista, int valor){
	listaDupla * novo = (listaDupla*) malloc(sizeof(listaDupla));
	novo->info = valor;
	novo->prox = lista;
	novo->ant = NULL; // Aponta para o valorda lista anterior
	
	if(lista != NULL){ // Confere se a lista não está vazia
		lista->ant = novo;
	}
	return novo;	
}

int main(){
	
	listaDupla * lista;
	
	lista = criaLista();
	
	lista = listaInsereInicio(lista,10);
	lista = listaInsereInicio(lista,20);
	lista = listaInsereInicio(lista,30);
	lista = listaInsereInicio(lista,40);
	lista = listaInsereInicio(lista,50);
	
	return 0;
}
