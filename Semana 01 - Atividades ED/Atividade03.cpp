#include <stdio.h>
#include <stdlib.h>

// SEMANA 01
// ATIVIDADE 03 - Faça um programa que leia um arquivo 
//(arquivo.txt - disponível no moodle) e mostre seu conteúdo na tela.

int main(){
	
	int codigo;
	char empresa[10];
	char sobre[12];
	char nome[10];
	char funcao[10];
	
	FILE * txt;
	
	txt = fopen("arquivo.txt","r");
	
	if(txt == NULL){
		
		printf("ERRO ao abrir o arquivo!");
		
	} else {
	
	while(!feof(txt)){
		fscanf(txt, "%d %s %s %s %s ", &codigo, empresa, sobre, nome, funcao);
		printf("%d %s %s %s %s\n", codigo, empresa, sobre, nome, funcao);
	}
}
	fclose(txt);
	
	return 0;
}
