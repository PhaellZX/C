#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int array[10];

int main(){
	
	// printf("%d",IsEmpty(array)); // Checar se a pilha est? vazia sa?da: 1
	   int nums[5] = {0, 2, 4, 6, 8};
		
	   push(array,nums[0]); // colocando o valor no topo da lista
	   printf("Inserindo -> %d\n", nums[0]);
	   push(array,nums[1]);
	   printf("Inserindo -> %d\n", nums[1]);
	   push(array,nums[2]);
	   printf("Inserindo -> %d\n", nums[2]);
	   push(array,nums[3]);
	   printf("Inserindo -> %d\n", nums[3]);
	   push(array,nums[4]); 
	   printf("Inserindo -> %d\n", nums[4]);
	
	
	// printf("%d",IsEmpty(array)); // Vericando se a pilha est? vazia sa?da: 0
	
	
	printf("\n\n");
	
	printf("removido -> %d\n", pop(array));
	printf("removido -> %d\n", pop(array));
	printf("removido -> %d\n", pop(array));
	    
	return 0;
}
