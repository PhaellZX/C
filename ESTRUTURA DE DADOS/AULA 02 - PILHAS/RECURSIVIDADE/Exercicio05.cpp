#include <stdio.h>
#include <stdlib.h>

// 5-) Crie uma função recursiva que retorne a soma dos elementos de um vetor de inteiros

int recursive(int n[], int sum, int cont);

int main() {
    int n[] = {10, 20, 30, 40, 50};
    int cont = 0, sum = 0, x;
    
    x = recursive(n, sum, cont);
    
    return 0;
}

int recursive(int n[], int sum, int cont) {
    if (cont == 5) {
        printf("SOMA TOTAL DO VETOR: %d", sum);
        return 0;
    }
    else {
        return recursive(n, sum + n[cont], cont + 1);
    }
}

