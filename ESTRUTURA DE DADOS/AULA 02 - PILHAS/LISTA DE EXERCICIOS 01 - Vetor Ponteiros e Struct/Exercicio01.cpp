#include <stdio.h>
#include <stdlib.h>

//1 - Faça um programa em C capaz de alocar dois vetores de números inteiros de tamanho 10.
// Leia valores do usuário e armazene-os no primeiro vetor. Depois copie todos os valores 
// positivos para o segundo vetor. Mostre os valores armazenados no segundo vetor na tela 
// do computador.


int main(){
	
	int vetor1[10], vetor2[10] = {0}, i, d = 0;
	
	for(i = 0; i <= 9; i++){
		printf("Digite um valor: ");
		scanf("%d", &vetor1[i]);
	}	
	printf("\nTodos os valores: ");
	for(i = 0; i <= 9; i++){
		printf("\n%d", vetor1[i]);
		if(vetor1[i] > 0){
			vetor2[d] = vetor1[i];
			d++;
		}	
	}	
	printf("\nValores Positivos: ");
	for(i = 0; i < d; i++){
		printf("\n%d", vetor2[i]);
	}
	return 0;
} 

