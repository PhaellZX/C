#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
	int pos;
	char nome[50];
	struct lista * prox;
}; typedef struct lista Lista;

// Criar Lista
Lista * criarLista(){
	return NULL;
}

// Inserir no inicio da lista
Lista * lista_insere_inicio(Lista * lista, int valor, char * texto){
	Lista * novo = (Lista*) malloc(sizeof(Lista));
	novo->pos = valor;
	strcpy(novo->nome,texto);
	novo->prox = lista;
	return novo;
}

// Inserir no fim da lista
Lista * lista_insere_fim(Lista * lista, int valor, char * texto){
	if(lista->prox==NULL){
		lista->pos = valor;
		strcpy(lista->nome,texto);
	
	}else{
		Lista * elem = NULL;
		for(elem = lista; elem->prox != NULL; elem = elem->prox);
		Lista * novo = (Lista*) malloc(sizeof(Lista));
		novo->pos = valor;
		strcpy(novo->nome,texto);
		novo->prox = NULL;
		elem->prox = novo;
	}
	return lista;
}

// Buscar na lista
Lista * buscar(Lista * lista, char * texto){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		if(strcmp(elem->nome,texto)==0){
			printf("Encontrado!");
			return elem;
	       }
	}
	printf("Nao encontrado!");
	return NULL;
}

// Remover da Lista  
Lista * remover_lista(Lista * lista, int codigo){
	Lista * ant = NULL;
	Lista * elem = lista;
	
	while(elem != NULL && elem->pos != codigo){
	ant = elem;
	elem = elem->prox;	
	}
	
	if(elem == NULL)
	return lista;
	
	if(ant == NULL){
	lista = elem->prox;
	
	} else {
		ant->prox = elem->prox;
	}
	free(elem);
	return lista;
}

//Alterar na Lista
Lista * alterar_lista(Lista * lista, char * texto, int valor){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		if(elem->pos==valor){
			lista = (Lista*) malloc(sizeof(Lista));
			strcpy(elem->nome,texto);
			printf("Nome alterado!\n");
			return elem;
	       }
	}
	printf("Nao encontrado!");
	return NULL;
}

// Mostrar lista
void imprimirLista(Lista * lista){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox)
	printf("posicao: %d - %s\n",elem->pos,elem->nome);
}

int main(){
	
	Lista * lista;
	lista = criarLista(); 
	
	int id = 0, opcao, cod;
	char nome[50];
	
	do{
		printf("\nMENU\n1 - Inserir no inicio da lista\n2 - Inserir no fim da lista\n3 - Selecionar na lista\n4 - Visualizar lista\n5 - Remover da lista\n6 - Alterar na lista\n0 - Sair(Visualizar lista)\n");
		scanf("%d",&opcao);
	switch(opcao){
		case 1:
		printf("Digite o nome:");
		scanf("%s",&nome);
		id++;
		lista = lista_insere_inicio(lista,id,nome);
		printf("Dados inserindos!!\n");
    	break;
    	case 2:                    
    	printf("Digite o nome:");
		scanf("%s",&nome);
		id++;
		lista = lista_insere_fim(lista,id,nome);
		printf("Dados inserindos!!\n");
		break;
		case 3:
		printf("Digite o nome: ");
		scanf("%s",&nome);
		buscar(lista,nome);
		break;
		case 4:
		printf("\n");
    	imprimirLista(lista);
    	printf("\n");
	    break;
	    case 5:
	    printf("Digite o ID: ");
	    scanf("%d",&cod);
	    lista = remover_lista(lista,cod);
	    break;
	    case 6:
	    printf("Digite o codigo: ");
	    scanf("%d",&cod);
		printf("Altere o nome: ");
		scanf("%s",&nome);
		alterar_lista(lista,nome,cod);
		break;
		case 0:
		printf("\nSaindo...\nSUA LISTA:\n");
		break;
    	default:
		printf("Valor Invalido!");
		break;	
    }
	}while(opcao!=0);
    printf("\n");
    imprimirLista(lista);
	return 0;
}
