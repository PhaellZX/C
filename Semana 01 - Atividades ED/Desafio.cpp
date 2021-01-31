#include <stdio.h>
#include <stdlib.h>

// DESAFIO - Faça um programa que leia o arquivo da Contituição de 88
// e contar quantas palavras que tem o arquivo

int main(){
	
	char c;
	FILE * txt;
	int count = 1;
	int flag = 0;
	
	txt = fopen("Constituicao88.txt","r");
	
	if(txt == NULL){
		
		printf("ERRO ao abrir o arquivo!");
		
	}else{
		
	 while(!feof(txt)){
		c = getc(txt);
		if ( c == ' ' || c == '\n' ){
		
			if (flag == 0){
				
				count++;
				flag = 1;
			}
		
		}else{
			
			if ( flag == 1 )
				 flag = 0;
		}
	}
}
	fclose(txt);

	printf("Na Constituicao de 88 tem %d palavras.\n", count);

	return (0);
}
