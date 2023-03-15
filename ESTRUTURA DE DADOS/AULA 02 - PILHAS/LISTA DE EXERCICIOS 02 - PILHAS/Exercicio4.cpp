#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000

// 4 - Fa�a um programa em C, capaz de transformar um n�mero na base 10 para base 2.
// Para tal, leia um valor do usu�rio e converta-o em bin�rio. Para facilitar, utilize uma pilha

// Definindo uma estrutura para a pilha
typedef struct {
    int items[MAX_SIZE];
    int top;
} Pilha;

// Fun��o para inicializar a pilha
void iniciar(Pilha * pilha) {
    pilha->top = -1;
}

// Fun��o para verificar se a pilha est� vazia
bool isEmpty(Pilha * pilha) {
    return (pilha->top == -1);
}

// Fun��o para verificar se a pilha est� cheia
bool isFull(Pilha * pilha) {
    return (pilha->top == MAX_SIZE - 1);
}

// Fun��o para empilhar um elemento na pilha
void push(Pilha * pilha, int value) {
    if (isFull(pilha)) {
        printf("Erro: a pilha est� cheia.\n");
        exit(EXIT_FAILURE);
    }
    
    int resto = 0;
    
    while(value != 0){ // Convertendo em Bin�rio
    	resto = value % 2;
    	value /= 2;
    	pilha->top++;
    	pilha->items[pilha->top] = resto;
	}
}

// Fun��o para desempilhar um elemento da pilha
int pop(Pilha * pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: a pilha est� vazia.\n");
        exit(EXIT_FAILURE);
    }
    int value = pilha->items[pilha->top];
    pilha->top--;
    return value;
}

// Fun��o para mostrar na tela os elementos da pilha
void display(Pilha * pilha) {
    if (isEmpty(pilha)) {
        printf("A pilha est� vazia.\n");
        return;
    }
    printf("\nValor em Binario: \n");
    for (int i = pilha->top; i >= 0; i--) {
        printf("%d\n", pilha->items[i]);
    }
}

// Fun��o principal
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

