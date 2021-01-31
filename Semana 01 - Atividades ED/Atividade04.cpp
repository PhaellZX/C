#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// SEMANA 01
// ATIVIDADE 04 
// - Faça um programa que crie um array de inteiros com
//1000 posições.
// - O programa deverá ler os valores enquanto for
//informado valores positivos. Caso um valor negativo
//seja informado, deverá armazenar os valores em um
//arquivo.
// - Ao executar novamente o programa, este deverá ler os
//valores e mostrar na tela os valores informados anteriormente.

int main(){
	
	int array[1000];
	char linha[1024];
	srand(time(NULL));
	
	FILE * txt;
	
	txt = fopen("NumerosNegativos.txt","r+");
	
	if(txt == NULL){
		
		printf("ERRO ao abrir o arquivo!");
		
	} else {
	
	while(!feof(txt)){   
		fgets(linha, 1024, txt);
        printf("%s",linha);
	}
	
	for(int i = 0; i <= 999; i++){
		array[i] = rand() % 100 - 20;
		
		if(array[i] < 0){
			
			fprintf(txt,"%d\n",array[i]);
		
		}
	}
}
	fclose(txt);
	
	return 0;
}
