#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

typedef struct Node {
    char uf[3];
    int cod_uf;
    int cod_munic;
    char nome_municipio[50];
    int populacao_estimada;
} Node;

int compareNodes(const void* a, const void* b) {
    const Node* nodeA = (const Node*)a;
    const Node* nodeB = (const Node*)b;

    return strcmp(nodeA->nome_municipio, nodeB->nome_municipio);
}

void loadCSVToArray(Node* array, int arraySize, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return;
    }

    char line[MAX_LINE_SIZE];
    int index = 0;
    while (fgets(line, sizeof(line), file) && index < arraySize) {
        char uf[3];
        int cod_uf;
        int cod_munic;
        char nome_municipio[50];
        int populacao_estimada;

        sscanf(line, "%[^,],%d,%d,%[^,],%d", uf, &cod_uf, &cod_munic, nome_municipio, &populacao_estimada);

        strcpy(array[index].uf, uf);
        array[index].cod_uf = cod_uf;
        array[index].cod_munic = cod_munic;
        strcpy(array[index].nome_municipio, nome_municipio);
        array[index].populacao_estimada = populacao_estimada;

        index++;
    }

    fclose(file);
}

void printArray(Node* array, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("UF: %s, COD. UF: %d, COD. MUNIC: %d, NOME DO MUNICÍPIO: %s, POPULAÇÃO ESTIMADA: %d\n",
               array[i].uf, array[i].cod_uf, array[i].cod_munic, array[i].nome_municipio, array[i].populacao_estimada);
    }
}

int main() {
    const char* filename = "cidades.csv";
    const int arraySize = 100; // Tamanho do array

    Node* array = (Node*)malloc(arraySize * sizeof(Node));

    loadCSVToArray(array, arraySize, filename);

    printf("Dados carregados:\n");
    printArray(array, arraySize);

    qsort(array, arraySize, sizeof(Node), compareNodes);

    printf("\nDados ordenados:\n");
    printArray(array, arraySize);

    free(array);

    return 0;
}

