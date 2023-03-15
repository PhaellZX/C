#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// 2 - Com a sua biblioteca criada, crie uma pilha de tamanho 10. Execute as seguintes opera��es:
// Empilhar 23
// Empilhar 81
// Desempilhar
// Empilhar 100
// Desempilhar
// Desempilhar

// Definindo a estrutura de uma pilha
typedef struct Pilha {
    int topo;
    int itens[MAX];
} Pilha;

// Fun��o para inicializar a pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

// Fun��o para verificar se a pilha est� vazia
int empty(Pilha *p) {
    if (p->topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Fun��o para verificar se a pilha est� cheia
int full(Pilha *p) {
    if (p->topo == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Fun��o para adicionar um elemento no topo da pilha
void push(Pilha *p, int item) {
    if (full(p)) {
        printf("Erro: a pilha esta cheia.\n");
    } else {
        p->itens[++p->topo] = item;
        printf("Empilhar: %d\n",item);
    }
}

// Fun��o para remover um elemento do topo da pilha
int pop(Pilha *p) {
    if (empty(p)) {
        printf("Erro: a pilha esta vazia.\n");
        return -1;
    } else {
        return p->itens[p->topo--];
    }
}

// Fun��o principal
int main() {
    Pilha p;
    inicializaPilha(&p);

    push(&p, 23);
    push(&p, 81);
    printf("Desenpilhar: %d\n", pop(&p));
    push(&p, 100);
	printf("Desenpilhar: %d\n", pop(&p));
    printf("Desenpilhar: %d\n", pop(&p));

    return 0;
}

