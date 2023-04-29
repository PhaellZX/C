#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void quick_sort(int array[], int left, int right);
int partition(int array[], int left, int right);
int linear_search(int array[], int n, int num);
int binary_search(int i, int *vet, int elem);


int main() {
    int i, num, vet[N], number;
    
    srand(time(NULL));
    
    for (i = 1; i <= 20; i++) {
        num = rand() % 100 + 1;
        vet[i] = num;
    }
    
    quick_sort(vet, 0, N - 1);
    
    printf("VALORES ORDENADOS:\n");
    for (i = 0; i < 19; i++) {
        printf("%d\n",vet[i]);
    }
    printf("\n\nDigite o numero que voce quer buscar: ");
    scanf("%d",&number);
    
    //printf("O numero esta na posicao [%d]!",linear_search(vet, N, number));
	 printf("O numero esta na posicao [%d]!",binary_search(N, vet, number));
	    
    return 0;
}

int partition(int array[], int left, int right) {
    int pivot, i, j, temp;
    
    pivot = array[right];
    i = left - 1;
    
    for (j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;
    
    return i + 1;
}

void quick_sort(int array[], int left, int right) {
    int index;
    
    if (left < right) {
        index = partition(array, left, right);
        quick_sort(array, left, index - 1);
        quick_sort(array, index + 1, right);
    }
}

int linear_search(int array[], int n, int num) {
    int i;
    
    for (i = 0; i < n; i++) {
        if (array[i] == num) {
            return i;
        }
    }
    
    return -1;
}

int binary_search(int i, int *vet, int elem) {
    int left = 0;
    int right = i - 1;
    int mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (vet[mid] == elem) {
            return mid;
        } else if (vet[mid] < elem) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}


