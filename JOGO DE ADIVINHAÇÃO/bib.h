#include <stdio.h>
#include <stdlib.h>

void numero(int esc,int op){
	
	if(esc == op){
	
	printf("acertou\n");
	
	} else if (esc < op) {
		
		printf("muito baixo, tente de novo\n");
		
	} else if (esc > op) {
		
		printf("muito alto, tente de novo\n");
		
	}
}
