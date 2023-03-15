#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

// 3 - Fa�a um programa em C, capaz de verificar se uma sequ�ncia de par�ntese e colchetes est� bem formada.
// Para que a sequ�ncia esteja bem formada, percorra a string de par�nteses e colchetes, fazendo o seguinte:
// a. Sempre que encontrar um ( ou [ na string, voc� deve empilhar o s�mbolo na pilha.
// b. Sempre que encontrar ) na string, voc� deve desempilhar o s�mbolo ( da pilha.
// c. Sempre que encontrar ] na string, voc� deve desempilhar o s�mbolo [ da pilha.

// Definindo uma estrutura para a pilha
typedef struct {
    char items[MAX_SIZE];
    int top;
} Pilha;

// Fun��o para inicializar a pilha
void iniciar(Pilha *pilha) {
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
void push(Pilha * pilha, char value) {
    if (isFull(pilha)) {
        printf("Erro: a pilha est� cheia.\n");
        exit(EXIT_FAILURE);
    }
    pilha->top++;
    pilha->items[pilha->top] = value;
}

// Fun��o para desempilhar um elemento da pilha
char pop(Pilha * pilha) {
    if (isEmpty(pilha)) {
        printf("Erro: a pilha est� vazia.\n");
        exit(EXIT_FAILURE);
    }
    char value = pilha->items[pilha->top];
    pilha->top--;
    return value;
}

// Fun��o principal
int main() {
    Pilha pilha;
    char sequence[MAX_SIZE];
    bool wellFormed = true;

    printf("Digite uma sequ�ncia de par�nteses e colchetes: ");
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
        printf("A sequ�ncia est� bem formada.\n");
    } else {
        printf("A sequ�ncia n�o est� bem formada.\n");
    }

    return 0;
}

