#include <stdio.h>
#include <stdlib.h>

//3 - Faça um programa em C, contendo um struct de produto conforme os membros abaixo.
// Crie duas variáveis do tipo produto. Leia valores do usuário e depois aumente o
// preço dos produtos em 10%. Mostre os valores de cada produto na tela.

char nome[30];
char *marca;
float preco;

struct Produto {
	char nome[30];
	char * marca;
	float preco;
};

int main(){
	
	struct Produto prod1;
	struct Produto prod2;
	int tam = 5;
	
	prod1.marca = (char *) malloc(tam * sizeof(char));
	prod2.marca = (char *) malloc(tam * sizeof(char));
	
	printf("\nCadastre um produto 01.\n");
	printf("Digite o nome: ");
	scanf("%s", prod1.nome);
	printf("Digite a marca: ");
	scanf("%s", prod1.marca);
	printf("Digite o preco: ");
	scanf("%f", &prod1.preco);
	
	printf("\nCadastre um produto 02.\n");
	printf("Digite o nome: ");
	scanf("%s", prod2.nome);
	printf("Digite a marca: ");
	scanf("%s", prod2.marca);
	printf("Digite o preco: ");
	scanf("%f", &prod2.preco);
	
	printf("\n\nPRODUTO 1: %s\nMARCA: %s\nPRECO(Acrescimo de 10 porc): R$%.2f\n", prod1.nome, prod1.marca, prod1.preco*1.1);
	printf("\nPRODUTO 2: %s\nMARCA: %s\nPRECO(Acrescimo de 10 porc): R$%.2f\n", prod2.nome, prod2.marca, prod2.preco*1.1);
	
	return 0;
}
