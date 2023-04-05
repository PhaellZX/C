#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"

// Pilha Biblioteca
int main() {
    Pilha livro;
    criarPilha(&livro);
    char titulo[50];
    int pags, i, opcao;
    
    do{
    
    interface();
    scanf("%d",&opcao);
    
    switch(opcao){
    	case 1:
    		leituraLivro(titulo,pags,i);
		break;		
    	case 0:
    		printf("Volte sempre...\n");	
		break;
		default:
			printf("Valor invalido!\n");
	}
}while(opcao != 0);
    return 0;
}
