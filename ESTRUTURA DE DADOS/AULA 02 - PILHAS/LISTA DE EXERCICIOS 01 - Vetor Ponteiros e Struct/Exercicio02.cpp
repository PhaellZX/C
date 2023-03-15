#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//2 - Faça um programa em C em que o usuário digitará o tamanho de um vetor de números inteiros.
// Após instancie o vetor com o tamanho especificado pelo usuário. Então sorteie números aleatórios
// utilizando a função rand(). Faça uma função que calcule a média dos valores sorteados. Ao final,
// mostre os valores sorteados na tela e a média desses números.

float media(float s, int t){
	return (s / t);
}

int main(){
	
	int tam = 0, min = 1, max = 100, i;
	float soma = 0;
	srand(time(NULL));
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d",&tam);
	
	float vetor[tam] = {0};
	
	printf("\nVetor: \n");
	
	for(i = 0; i < tam; i++){
		vetor[i] = rand() % (max - min + 1) + min;	
		soma += vetor[i];
		printf("%.1f\n",vetor[i]);
	}
	
	printf("\n\nA media dos valores do vetor eh: %.1f",media(soma,tam));
	
	return 0;
}
