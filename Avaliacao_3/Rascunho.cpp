#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_COLUMNS 5
#define HASH_SIZE 10000

typedef struct Node {
    char uf[MAX_FIELD_LENGTH];
    char codUf[MAX_FIELD_LENGTH];
    char codMunic[MAX_FIELD_LENGTH];
    char nomeMunicipio[MAX_FIELD_LENGTH];
    char populacaoEstimada[MAX_FIELD_LENGTH];
    struct Node* next;
} Node;

int hashFunction(const char* key);

void insert(Node* hashTable[], Node* newNode) {
    int hashIndex = hashFunction(newNode->nomeMunicipio);

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    } else {
        Node* current = hashTable[hashIndex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int hashFunction(const char* key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // djb2 hash algorithm
    }

    return hash % HASH_SIZE;
}

int compareNodes(const void* a, const void* b) {
    const Node* nodeA = *(const Node**)a;
    const Node* nodeB = *(const Node**)b;

    return strcmp(nodeA->nomeMunicipio, nodeB->nomeMunicipio);
}

int main() {
    int cont = 0;

    FILE* file = fopen("cidades.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Node* hashTable[HASH_SIZE] = { NULL };
    Node* nodeArray[MAX_LINE_LENGTH / 2];
    int nodeArraySize = 0;

    char line[MAX_LINE_LENGTH];
    char field[MAX_FIELD_LENGTH];

    int row = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* token;
        char* rest = line;
        char* columns[MAX_COLUMNS];

        int column = 0;
        while ((token = strtok_r(rest, ",", &rest)) != NULL && column < MAX_COLUMNS) {
            strncpy(field, token, MAX_FIELD_LENGTH - 1);
            field[MAX_FIELD_LENGTH - 1] = '\0';

            columns[column] = strdup(field);
            column++;
        }

        if (column == MAX_COLUMNS) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            strcpy(newNode->uf, columns[0]);
            strcpy(newNode->codUf, columns[1]);
            strcpy(newNode->codMunic, columns[2]);
            strcpy(newNode->nomeMunicipio, columns[3]);
            strcpy(newNode->populacaoEstimada, columns[4]);
            newNode->next = NULL;

            insert(hashTable, newNode);

            nodeArray[nodeArraySize] = newNode;
            nodeArraySize++;
        }

        for (int i = 0; i < column; i++) {
            free(columns[i]);
        }

        row++;
    }

    fclose(file);

    // Ordenar os nós usando qsort
    qsort(nodeArray, nodeArraySize, sizeof(Node*), compareNodes);

    // Imprimir os nós ordenados
    for (int i = 0; i < nodeArraySize; i++) {
        Node* node = nodeArray[i];
        printf("UF: %s, Cod. UF: %s, Cod. Munic: %s, Nome do Município: %s, População Estimada: %s\n",
            node->uf, node->codUf, node->codMunic, node->nomeMunicipio, node->populacaoEstimada);
            cont++;
    }
    
    printf("\n%d",cont);

    // Liberar a memória alocada para os nós da tabela de hash
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
	
    return 0;
}


