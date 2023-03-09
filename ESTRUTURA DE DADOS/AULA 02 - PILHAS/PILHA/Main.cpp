#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int array[10];

int main(){
	
	// printf("%d",IsEmpty(array)); // Checar se a pilha está vazia saída: 1

	for(int i = 0; i <= 9; i++){
		if(i % 2 == 0){
			push(array,i); // colocando o valor no topo da lista 
			printf("Inserido -> %d\n",i);
		}
	}
	
	// printf("%d",IsEmpty(array)); // Vericando se a pilha está vazia saída: 0
	
	
	printf("\n\n");
	
	printf("removido -> %d\n", pop(array));
	printf("removido -> %d\n", pop(array));
    
	return 0;
}
