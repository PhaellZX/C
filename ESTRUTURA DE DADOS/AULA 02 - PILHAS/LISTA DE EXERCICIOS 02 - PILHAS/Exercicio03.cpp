#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

// 3 - Faça um programa em C, capaz de verificar se uma sequência de parêntese e colchetes está bem formada.
// Para que a sequência esteja bem formada, percorra a string de parênteses e colchetes, fazendo o seguinte:
// a. Sempre que encontrar um ( ou [ na string, você deve empilhar o símbolo na pilha.
// b. Sempre que encontrar ) na string, você deve desempilhar o símbolo ( da pilha.
// c. Sempre que encontrar ] na string, você deve desempilhar o símbolo [ da pilha.

// Definindo uma estrutura para a pilha
typedef struct {
    char items[MAX_SIZE];
    int top;
} Pilha;

// Função para inicializar a pilha
void iniciar(Pilha *pilha) {
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
void push(Pilha * pilha, char value) {
    if (isFull(pilha)) {
        printf("Erro: a pilha está cheia.\n");
        exit(EXIT_FAILURE);
    }
    pilha->top++;
    pilha->items[pilha->top] = value;
}

// Função para desempilhar um elemento da pilha
char pop(Pilha * pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: a pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    char value = pilha->items[pilha->top];
    pilha->top--;
    return value;
}

// Função principal
int main() {
    Pilha pilha;
    char sequence[MAX_SIZE];
    bool wellFormed = true;

    printf("Digite uma sequência de parênteses e colchetes: ");
    scanf("%s", sequence);

    iniciar(&pilha);

    for (int i = 0; i < strlen(sequence); i++) {
        if (sequence[i] == '(' || sequence[i] == '[') {
            push(&pilha, sequence[i]);
        } else if (sequence[i] == ')') {
            if (isEmpty(&pilha) || pop(&pilha) != '(') {
                wellFormed = false;
                break;
            }
        } else if (sequence[i] == ']') {
            if (isEmpty(&pilha) || pop(&pilha) != '[') {
                wellFormed = false;
                break;
            }
        }
    }

    if (!isEmpty(&pilha)) {
        wellFormed = false;
    }

    if (wellFormed) {
        printf("A sequência está bem formada.\n");
    } else {
        printf("A sequência não está bem formada.\n");
    }

    return 0;
}

