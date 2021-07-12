#include <stdlib.h>
#include <stdio.h>
#include "ListaDE.h"

void menu(){
	
	printf("\n--------MENU-------\n");
	printf("1 - Inserir\n");
	printf("2 - Pesquisar\n");
	printf("3 - Remover\n");
	printf("4 - Mostrar Lista\n");
	printf("0 - Sair\n");
	
}

void sair(){
	printf("saindo...\n");
}
void error(){
	printf("Valor Invalido!\n");
}

int main(){
	
	Lista * lis = cria_lista();
	int opcao, id = 1001, matr;
	char name[20];
	
	menu();
	
    do{
    	scanf("%d",&opcao);
    	
	switch(opcao){
		case 1:
			system("cls");
			printf("Digite o nome do aluno: ");
			scanf("%s",&name);
			lis = set_lista(lis,id,name);
			printf("Cadastro realizado com sucesso!");
			id++;
			menu();
		break;
		case 2:
			system("cls");
			printf("Digite a matricula: ");
			scanf("%d",&matr);
			lis = find_lista(lis, matr);
			menu();
			break;
		case 3:
			system("cls");
			printf("Digite a matricula: ");
			scanf("%d",&matr);
			lis = delete_elemento(lis, matr);
			menu();                   
			break;
			case 4:
				system("cls");
				view_lista(lis);
				menu();
				break;
		case 0:
			sair();
			break;
		default:
			system("cls");
			error();
			menu();
			}
		}while(opcao != 0);
		
	return 0;
}

