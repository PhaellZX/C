#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 100000
#define MAX_FIELD_LENGTH 256
#define MAX_COLUMNS 5
#define HASH_SIZE 10000

typedef struct Node {
    char uf[MAX_FIELD_LENGTH];
    char codUf[MAX_FIELD_LENGTH];
    int codMunic;
    char nomeMunicipio[MAX_FIELD_LENGTH];
    char populacaoEstimada[MAX_FIELD_LENGTH];
    struct Node* next;
} Node;

int hashFunction(int key) {
    unsigned int hash = (unsigned int)key;
    return hash % HASH_SIZE;
}

void insert(Node* hashTable[], Node* newNode) {
    int hashIndex = hashFunction(newNode->codMunic);
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

int compareNodes(const void* a, const void* b) {
    const Node* nodeA = *(const Node**)a;
    const Node* nodeB = *(const Node**)b;

    return (nodeA->codMunic - nodeB->codMunic);
}

char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end > str && (*end == '\n' || *end == '\r' || *end == ' ')) {
        *end = '\0';
        end--;
    }
    return str;
}

void testHashAccess(Node* hashTable[], int codMunic) {
    int hashIndex = hashFunction(codMunic);
    Node* current = hashTable[hashIndex];

    while (current != NULL) {
        if (current->codMunic == codMunic) {
            printf("Acesso por Tabela Dispersa:\n");
            printf("UF: %s, Cod. UF: %s, Cod. Munic: %d, Nome do Município: %s, População Estimada: %s\n",
                   current->uf, current->codUf, current->codMunic, current->nomeMunicipio, current->populacaoEstimada);
            return;
        }
        current = current->next;
    }

    printf("Município não encontrado usando Tabela Dispersa.\n");
}

int compareCodMunic(const void* key, const void* node) {
    const int* codMunic = (const int*)key;
    const Node* n = *(const Node**)node;

    if (*codMunic < n->codMunic) {
        return -1;
    } else if (*codMunic > n->codMunic) {
        return 1;
    } else {
        return 0;
    }
}

void testBinarySearch(Node* nodeArray[], int nodeArraySize, int codMunic) {
    Node keyNode;
    keyNode.codMunic = codMunic;

    Node* foundNode = *(Node**)bsearch(&keyNode, nodeArray, nodeArraySize, sizeof(Node*), compareCodMunic);

    if (foundNode != NULL) {
        printf("Acesso por Busca Binária:\n");
        printf("UF: %s, Cod. UF: %s, Cod. Munic: %d, Nome do Município: %s, População Estimada: %s\n",
               foundNode->uf, foundNode->codUf, foundNode->codMunic,
               foundNode->nomeMunicipio, foundNode->populacaoEstimada);
    } else {
        printf("Município não encontrado usando Busca Binária.\n");
    }
}


int main() {
    FILE* file = fopen("cidades.csv", "r");
    if (file == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return 1;
    }

    Node* hashTable[HASH_SIZE];
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }

    Node* nodeArray[MAX_LINE_LENGTH];
    int nodeArraySize = 0;

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Ignorar o cabeçalho

    while (fgets(line, sizeof(line), file)) {
        Node* newNode = (Node*)malloc(sizeof(Node));

        char* token = strtok(line, ",");
        int column = 0;
        while (token != NULL && column < MAX_COLUMNS) {
            switch (column) {
                case 0:
                    strncpy(newNode->uf, trim(token), sizeof(newNode->uf));
                    break;
                case 1:
                    strncpy(newNode->codUf, trim(token), sizeof(newNode->codUf));
                    break;
                case 2:
                    newNode->codMunic = atoi(trim(token));
                    break;
                case 3:
                    strncpy(newNode->nomeMunicipio, trim(token), sizeof(newNode->nomeMunicipio));
                    break;
                case 4:
                    strncpy(newNode->populacaoEstimada, trim(token), sizeof(newNode->populacaoEstimada));
                    break;
            }
            token = strtok(NULL, ",");
            column++;
        }

        newNode->next = NULL;
        insert(hashTable, newNode);
        nodeArray[nodeArraySize++] = newNode;
    }

    fclose(file);

    int codMunic;
    printf("Digite o código do município: ");
    scanf("%d", &codMunic);

    testHashAccess(hashTable, codMunic);
    testBinarySearch(nodeArray, nodeArraySize, codMunic);

    return 0;
}


