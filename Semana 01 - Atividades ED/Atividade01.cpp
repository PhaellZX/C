#include <stdio.h>
#include <stdlib.h>

// SEMANA 01
// ATIVIDADE 01 - Faça um programa que leia um nome
//qualquer e armazene em um arquivo
//demoninado “dados.txt”.

int main(){
	
	char nome[10];
	FILE * txt;
	
	txt = fopen("dados.txt","w");
	
	if(txt == NULL){
		
		printf("ERRO ao abrir o arquivo!");
		
	} else {
	
	printf("Digite seu nome:");
	scanf("%s",&nome);
	
	fprintf(txt,"%s",nome);
	
	}
	fclose(txt);
	
	return 0;
}
