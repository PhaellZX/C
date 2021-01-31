#include <stdio.h>
#include <stdlib.h>

// DESAFIO - Faça um programa que leia o arquivo da Contituição de 88
// e contar quantas palavras que tem o arquivo

// Obs: Essa tive que dá uma pesquisada na web, pelo que eu entendi deve criar uma variável c(letra)
// que vai por letra e letra no arquivo e passa por uma condição de se letra for igual ao 'espaço vazio'
// OU letra é igual a 'quebra de linha' ele pula, senão conta +1, e uma outra observação coloquei o 
// count = 1 porque parece que no C entendi o inicio como 0 nas contagens :/

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
