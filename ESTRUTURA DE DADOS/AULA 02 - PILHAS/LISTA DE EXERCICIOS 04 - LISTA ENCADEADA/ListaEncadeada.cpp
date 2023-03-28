#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

int main(){
	
	Lista * lista;
	lista = lst_cria();
	//lista = lst_insere(lista,10);
	
	lst_insere_Atualizar(&lista,40);
	lst_insere_Atualizar(&lista,20);
	lst_insere_Atualizar(&lista,30);
	lst_insere_Atualizar(&lista,10);
	
	lista = Remover(lista,10);
	
	//lista = Inserir_ordenar(lista,50);
	//lista = Inserir_ordenar(lista,10);
	//lista = Inserir_ordenar(lista,40);
	//lista = Inserir_ordenar(lista,20);
	//lista = Inserir_ordenar(lista,30);	
	
	lst_imprime(lista);
	
	//lista = ApagarLista(lista);
	//printf("%d",lst_vazia(lista));
	
	return 0;
}
