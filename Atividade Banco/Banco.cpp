#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//obs: Não consigo atualizar os saldos,
// não sei o porque :/

typedef struct Correntista{
	
	int cod;
	char nome[30];
	float saldo;
};

void menu(){
	printf("\n\n---------MENU---------\n");
	printf("1 - imprimir na tela\n");
	printf("2 - fazer operacao\n");
	printf("0 - Sair\n");
}

void imprimir(){
	system("cls");
	Correntista pessoa[10];
	int i = 0;
	FILE * txt = fopen("arquivo.txt","r+");
	if(txt==NULL){
		printf("Erro ao abrir o arquivo");
	}else{
		while(!feof(txt)){
			
			fscanf(txt,"%d %s %f",&pessoa[i].cod,pessoa[i].nome,&pessoa[i].saldo);
			printf("%d %s %.2f\n",pessoa[i].cod,pessoa[i].nome,pessoa[i].saldo);
			i++;
		}
	}
	fclose(txt);
}

void operacao(){
	system("cls");
	Correntista pessoa[10];
	FILE * txt = fopen("arquivo.txt","a+");
	int codigo, i = 0;
	char op;
	float dinheiro;
	
	if(txt==NULL){
		printf("Erro ao abrir o arquivo");
	}else{
	
	printf("Digite o codigo: ");
	scanf("%d",&codigo);
	
	while(!feof(txt)){
		fscanf(txt,"%d %s %f",&pessoa[i].cod,pessoa[i].nome,&pessoa[i].saldo);
		if(codigo==pessoa[i].cod){
			printf("Escolha uma das opcoes: (D) - debito | (C) - Credito\n");
			scanf(" %c",&op);
			if(op=='D'){
				printf("Digite o valor a retirar: ");
				scanf("%f",&dinheiro);
				
				pessoa[i].saldo = pessoa[i].saldo - dinheiro;
				
				printf("%d %s retirou %.2f | Saldo %.2f",pessoa[i].cod,pessoa[i].nome,dinheiro,pessoa[i].saldo);
			} else if(op=='C'){
				printf("Digite o valor a adicionar: ");
				scanf("%f",&dinheiro);
				
				pessoa[i].saldo = pessoa[i].saldo + dinheiro;
				
				printf("%d %s adicionou credito de %.2f | Saldo %.2f",pessoa[i].cod,pessoa[i].nome,dinheiro,pessoa[i].saldo);
			}
		i++;
	}
	}
	fclose(txt);
}
}

void error(){
	system("cls");
	printf("valor invalido!\n");
}

void sair(){
	printf("saindo...");
}

int main(){
	
	int opcao;
	
	menu();
	
	do{
		
		scanf("%d",&opcao);
		
	switch(opcao){
		case 1:
			imprimir();
			menu();
		break;
		case 2:
			operacao();
			menu();
		break;
		case 0:
			sair();
		break;
		default:
			error();
			menu();
	}
}while(opcao!=0);
	return 0;
}

