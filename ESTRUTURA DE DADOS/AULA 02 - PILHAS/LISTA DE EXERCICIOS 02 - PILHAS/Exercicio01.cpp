#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// 1 - Fa�a um programa capaz de implementar a estrutura de dados de uma pilha de n�meros inteiros.
// Utilize-se de struct para definir a estrutura de dados. A biblioteca deve possuir as fun��es push,
//pop, empty e full. N�o precisa fazer a biblioteca (DLL). Utilize o projeto em anexo.

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

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Elemento retirado: %d\n", pop(&p));
    printf("Elemento retirado: %d\n", pop(&p));
    printf("Elemento retirado: %d\n", pop(&p));
    printf("Elemento retirado: %d\n", pop(&p));

    return 0;
}

