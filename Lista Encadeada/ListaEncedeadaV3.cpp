#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
	int codigo;
	char nome[50];
	int idade;
	char exame[50];
	char data[20];
	struct lista * prox;

}; typedef struct lista Lista;

// Criar a lista
Lista * criarLista(){
	return NULL;
}

//Inserir no inicio da lista
Lista * lista_insere_inicio(Lista * lista, int id, char * name, int ano, char * exa,char * dat){
	Lista * novo = (Lista*) malloc(sizeof(Lista));
	novo->codigo = id;  // codigo
	strcpy(novo->nome,name); // nome
	novo->idade = ano; // idade
	strcpy(novo->exame,exa); // Exame
	strcpy(novo->data,dat); // data do atendimento
	novo->prox = lista; // proximo da lista
	return novo;
}

//Inserir no fim da lista
Lista * lista_insere_fim(Lista * lista, int id, char * name, int ano, char * exa,char * dat){
	if(lista->prox==NULL){
		lista->codigo = id;
		strcpy(lista->nome,name);
		lista->idade = ano;
		strcpy(lista->exame,exa);
		strcpy(lista->data,dat);
	
	}else{
		Lista * elem = NULL;
		for(elem = lista; elem->prox != NULL; elem = elem->prox);
		Lista * novo = (Lista*) malloc(sizeof(Lista));
		novo->codigo = id;
		strcpy(novo->nome,name);
		novo->idade = ano;
		strcpy(novo->exame,exa);
		strcpy(novo->data,dat);
	
		novo->prox = NULL;
		elem->prox = novo;
	}
	return lista;
}

//Buscar pelo nome na lista
Lista * buscar_nome(Lista * lista, char * texto){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		if(strcmp(elem->nome,texto)==0){
			printf("\nEncontrado!");
			return elem;
		}
	}
	printf("\nNao encontrado!");
	return NULL;
}

Lista * buscar_codigo(Lista * lista, int id){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		if(elem->codigo==id){
			printf("\nEncontrado");
			return elem;
		}
	}
	printf("\nNao encontrado!");
	return NULL;
}
// Remover da lista
Lista * remover_lista(Lista * lista, int id){
    Lista * ant = NULL;
	Lista * elem = lista;
	
	while(elem != NULL && elem->codigo != id){
		ant = elem;
		elem = elem->prox;
	}	
	if(elem==NULL)
	return lista;
	
	if(ant==NULL){
		lista = elem->prox;
	
	} else {
		ant->prox = elem->prox;
	}
	free(elem);
	return lista;
}

//Alterar na lista o nome do paciente

Lista * alterar_lista(Lista * lista, char * name, int cod){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox){
		if(elem->codigo==cod){
			lista = (Lista*) malloc(sizeof(Lista));
			strcpy(elem->nome,name);
			printf("Nome alterar!\n");
			return elem;
		}
	}
	printf("Nao encontrado!");
	return NULL;	
}	

//Tarefa: Alterar o exame e a idade

// Imprimir lista 
void imprimirLista(Lista * lista){
	Lista * elem;
	for(elem = lista; elem != NULL; elem = elem->prox)
	printf("\n cod: %d\n nome: %s\n idade: %d\n Exame: %s\n Data: %s\n",elem->codigo,elem->nome,elem->idade,elem->exame,elem->data);
}

int main(){
	
	Lista * lista;
	lista = criarLista();
	
	lista = lista_insere_inicio(lista,1,"Raphael",25,"Hemograma","28/02/2020");
	lista = lista_insere_inicio(lista,2,"Mateus",33,"Urina","29/02/2020");
	lista = lista_insere_inicio(lista,3,"Pedro",19,"Fezes","01/03/2020");
	lista = lista_insere_inicio(lista,4,"Rebeca",20,"Hemograma","02/03/2020");

	lista = lista_insere_fim(lista,4,"Isaac",36,"Urina","03/03/2020");
	lista = lista_insere_fim(lista,5,"Elena",24,"Hemograma","05/03/2020");		
	
	//lista = buscar_nome(lista,"Andreia");
	//lista = buscar_codigo(lista,3);
	
	//lista = remover_lista(lista,2);
	
	lista = alterar_lista(lista,"Telmo",2);
	imprimirLista(lista);
	return 0;
}
