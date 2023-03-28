#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

//1 - Crie uma lista de números inteiros, implementada por meio de lista encadeada. O seu
//programa deve inserir 100000 números inteiros (sorteados aleatoriamente). A lista
//deve manter os números na ordem crescente de valor. Então realize as seguintes
//operações:

int main(){
	
	Lista * lista, * lista2;
	int i, valor;
	float timeA, timeB, timeC, timeD, timeE;
	clock_t start, end;
	
	lista = lst_cria();
	lista2 = lst_cria();
	
	// A) Insira 100.000 números (comece 0 insira até 99.999). Calcule o tempo.
	start = clock();
	for(i = 0; i <= 99999; i++){
		valor = rand() % 100000 + 1;
		inserir_ordenar(&lista,valor);
	}
	end = clock();
	timeA = (float) (end - start) / CLOCKS_PER_SEC;
	
	// B) Remova os números 10000 a 10999. Calcule o tempo da remoção.
	start = clock();
	lista = Remover(lista,10000);
	lista = Remover(lista,10999);
	end = clock();
	
	timeB = (float) (end - start) / CLOCKS_PER_SEC;
	
	// C) Consulte os valores armazenados entre as posições 15000 e 20000. Calcule o
    // tempo da consulta. Obs: a questao F e a mesma coisa...
	start = clock();
	for(i = 15000; i <= 20000; i++){
		lista = Localiza(lista,i);
	}
	end = clock();
	
	timeC = (float) (end - start) / CLOCKS_PER_SEC;
	
	// D)Insira 100.000 números (comece 99.999 insira até 0). Calcule o tempo
	/* Obs: nao sei se funcionou...
	start = clock();
	for(i = 999999; i >= 0; i--){
		valor = rand() % 100000 + 1;
		inserir_ordenar(&lista2,valor);
	}
	end = clock();
	
	timeD = (float) (end - start) / CLOCKS_PER_SEC;
	*/
	
	//E)Remova os números 10000 a 10999. Calcule o tempo da remoção
	start = clock();
	for(i = 10000; i <= 10999; i++){
		lista = Remover(lista,i);
	}
	end = clock();
	
	timeE = (float) (end - start) / CLOCKS_PER_SEC;
	
	lst_imprime(lista);
	
	printf("A) tempo decorrido: %f\n", timeA);
	printf("B) tempo decorrido: %f\n", timeB);
	printf("C e F) tempo decorrido: %f\n", timeC);
	printf("D) tempo decorrido: %f\n", timeD);
	printf("E) tempo decorrido: %f\n", timeE);
		
	return 0;
}
