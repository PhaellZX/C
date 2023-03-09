#include <stdio.h>
#include <stdlib.h>

int topo = -1;

int IsEmpty(int * array){  // Verificar se está vazio
	if (topo == -1) {
        return 1;
    } else {
        return 0;
    } 
}

void push(int * array, int valor) { // Inserir no topo da pilha
    if (topo == 10 - 1) {
        printf("Erro: pilha cheia!\n");
    } else {
        topo++;
        array[topo] = valor;
    }
}

int pop(int * array) { // Retirar do topo da pilha
    if (topo == -1) { // verificar se topo é menor que 0
        printf("Erro: pilha vazia!\n");
        return -1;
    } else {
        int valor = array[topo];
        topo--;
        return valor;
    }
}

