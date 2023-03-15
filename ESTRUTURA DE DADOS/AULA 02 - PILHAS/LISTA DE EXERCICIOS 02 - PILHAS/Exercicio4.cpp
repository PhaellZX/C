#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000

// 4 - Faça um programa em C, capaz de transformar um número na base 10 para base 2.
// Para tal, leia um valor do usuário e converta-o em binário. Para facilitar, utilize uma pilha

// Definindo uma estrutura para a pilha
typedef struct {
    int items[MAX_SIZE];
    int top;
} Pilha;

// Função para inicializar a pilha
void iniciar(Pilha * pilha) {
    pilha->top = -1;
}

// Função para verificar se a pilha está vazia
bool isEmpty(Pilha * pilha) {
    return (pilha->top == -1);
}

// Função para verificar se a pilha está cheia
bool isFull(Pilha * pilha) {
    return (pilha->top == MAX_SIZE - 1);
}

// Função para empilhar um elemento na pilha
void push(Pilha * pilha, int value) {
    if (isFull(pilha)) {
        printf("Erro: a pilha está cheia.\n");
        exit(EXIT_FAILURE);
    }
    
    int resto = 0;
    
    while(value != 0){ // Convertendo em Binário
    	resto = value % 2;
    	value /= 2;
    	pilha->top++;
    	pilha->items[pilha->top] = resto;
	}
}

// Função para desempilhar um elemento da pilha
int pop(Pilha * pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: a pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    int value = pilha->items[pilha->top];
    pilha->top--;
    return value;
}

// Função para mostrar na tela os elementos da pilha
void display(Pilha * pilha) {
    if (isEmpty(pilha)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("\nValor em Binario: \n");
    for (int i = pilha->top; i >= 0; i--) {
        printf("%d\n", pilha->items[i]);
    }
}

// Função principal
int main() {
    
    int num;
	
	Pilha pilha;
	iniciar(&pilha);

	printf("Digite um numero para converter em binario: ");
	scanf("%d",&num);

    push(&pilha, num);
	display(&pilha);

    return 0;
}

