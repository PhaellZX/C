#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

Fila * fila_cria(void);
int full(Fila * f);
void queue(Fila * f,int v);
int empty(Fila * f);
int dequeue(Fila * f);

int main(){
	
	Fila * filaPadrao, * filaPref;
	filaPadrao = fila_cria();
	filaPref =  fila_cria();
	int opcao = 1, codPad = 100, codPre = 200;
	
	while(opcao != 0){
		printf("BANCO TIO PATINHAS:\nonde seu dinheiro esta em maos seguras!\n");
		printf("Escolha uma das opcoes(1 - Fila Padrao | 2 - Fila Preferencial | 0 - Aguardar):");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				queue(filaPadrao,codPad);
				codPad++;
				system("cls");
				printf("\nPessoa Adicionada na fila padrao!\n\n");
			break;
			case 2:
				queue(filaPref,codPre);
				codPre++;
				system("cls");
				printf("\nPessoa Adicionada na fila preferencial!\n\n");
			break;	
			case 0:
				system("cls");
				printf("Aguarde o Guincho chamar...\n");
			break;
			default:
				system("cls");
				printf("Valor inválido!");
		}
	}
	
	while(!empty(filaPadrao) || !empty(filaPref)){
	
	printf("\n");
	
	printf("FILA PADRAO: ");
	print_queue(filaPadrao);
	printf("FILA PREFENRENCIAL: ");
	print_queue(filaPref);
	
	if(!empty(filaPref)){
		printf("Guinche 01: %d\n",dequeue(filaPref));
		if(!empty(filaPref)){
			printf("Guinche 02: %d\n",dequeue(filaPref));
		} else{
			printf("Guinche 02: %d\n",dequeue(filaPadrao));
		}
	} else {
		printf("Guinche 01: %d\n",dequeue(filaPadrao));
		if(!empty(filaPadrao)){
			printf("Guinche 02: %d\n",dequeue(filaPadrao));
		}
		if(!empty(filaPadrao)){
			printf("Guinche 03: %d\n",dequeue(filaPadrao));
		}
	}
}
return 0;
}
