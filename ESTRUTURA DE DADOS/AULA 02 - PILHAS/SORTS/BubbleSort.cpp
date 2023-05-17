#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int* original, int length);

int main(){
	
	int num;
	
	printf("Digite o tamanho da Array: ");
	scanf("%d",&num);
	
	printf("\n");
	
	int vetor[num];
	srand(time(NULL));
	
	// Armazena os valores gerados aleatoriamente
    for (int i = 0; i < num; i++) vetor[i] = (rand() % 100) + 1;
	InsertionSort(vetor,num);
	
	for (int i = 0; i < num; i++) printf("%d\n", vetor[i]);
    
	return 0;
}

void InsertionSort(int* original, int length){
	int aux, i, j;
		for(int i=length-1; i >= 1; i--){
			for( int j=0; j < i ; j++){
				if(original[j]>original[j+1]){
					aux = original[j];
					original[j] = original[j+1];
					original[j+1] = aux;
				}
			}
		}
	}
