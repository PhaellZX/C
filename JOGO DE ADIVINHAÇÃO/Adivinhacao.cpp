#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib.h"

int main(){
	
	srand(time(NULL));
	int escolha ,opcao = rand() % 29 + 1, t, palpite = 0;
	
	do{
		do{
	
	printf("Escolha um numero: ");
	scanf("%d",&escolha);
	
	numero(escolha,opcao);
	
	if(escolha!=opcao){
		palpite++;
	}
	
	}while(escolha!=opcao);
	
	printf("Quer jogar de novo? sim(1) / nao(qualquer valor)\n");
	scanf("%d",&t);
	
	if(t == 1){
		
		opcao = rand() % 29 + 1;
		
	}
	
	}while(t == 1);
	
	if(palpite < 10){
		
		printf("Ou voce sabe o segredo ou tem muita sorte!");
		
	} else if(palpite == 10){
		
		printf("Ahah! Voce sabe o segredo!");
	
	}  else if(palpite > 10){
		
		printf("Voce deve ser capaz de fazer melhor!");
	}
	
	return 0;
}
