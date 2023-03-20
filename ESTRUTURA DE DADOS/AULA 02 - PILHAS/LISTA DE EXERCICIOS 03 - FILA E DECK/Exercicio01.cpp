#include <stdio.h>
#include <stdlib.h>
#include "library01.h"

Fila * fila_cria(void);
int full(Fila * f);
void queue(Fila * f,int v);
int empty(Fila * f);
int dequeue(Fila * f);

int main(){
	
	Fila * fila;
	fila = fila_cria();
	
	queue(fila,23);
	queue(fila,81);
	printf("Remover %d\n",dequeue(fila));
	queue(fila,100);
	printf("Remover %d\n",dequeue(fila));
	queue(fila,50);
	queue(fila,30);
	queue(fila,40);
	queue(fila,10);
	
	return 0;
}
