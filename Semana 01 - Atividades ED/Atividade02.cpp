#include <stdio.h>
#include <stdlib.h>

// SEMANA 01
// ATIVIDADE 02 - Faça um programa que leia uma nome qualquer, uma
//idade qualquer e armazena em um arquivo
//demonnado dados2.txt.

int main(){
	
	char nome[10];
	int idade;
	FILE * txt;
	
	txt = fopen("dados2.txt","w");
	
	if(txt == NULL){
		
		printf("ERRO ao abrir o arquivo!");
		
	} else {
	
 	    printf("Digite seu nome: ");
 	    scanf("%s",&nome);
 	    printf("Digite sua idade: ");
 	    scanf("%d",&idade);
 	    
 	    fprintf(txt,"nome: %s\nidade: %d",nome,idade);
	
	}
	fclose(txt);
	
	return 0;
}
