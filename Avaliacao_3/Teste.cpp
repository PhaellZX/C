#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10000
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

typedef struct Node_Binary {
    char uf[MAX_FIELD_LENGTH];
    char codUf[MAX_FIELD_LENGTH];
    char codMunic[MAX_FIELD_LENGTH];
    char nomeMunicipio[MAX_FIELD_LENGTH];
    char populacaoEstimada[MAX_FIELD_LENGTH];
    struct Node_Binary* next;
} Node_Binary;

int hashFunction(const char* key);

void insert(Node* hashTable[], Node* newNode) {
    int hashIndex = hashFunction(newNode->codMunic);

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
    const Node_Binary* nodeA = *(const Node_Binary**)a;
    const Node_Binary* nodeB = *(const Node_Binary**)b;

    return strcmp(nodeA->codMunic, nodeB->codMunic);
}

void testAccess(Node* hashTable[], Node_Binary* sortedNodeArray[], int nodeArraySize, const char* codMunic) {
    // Acesso usando tabela dispersa
    int hashIndex = hashFunction(codMunic);
    Node* currentNode = hashTable[hashIndex];
    while (currentNode != NULL) {
        if (strcmp(currentNode->codMunic, codMunic) == 0) {
            printf("Acesso por Tabela Dispersa: Nome do Município: %s, População Estimada: %s\n",
                currentNode->nomeMunicipio, currentNode->populacaoEstimada);
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Acesso por Tabela Dispersa: Município não encontrado.\n");

    // Acesso usando busca binária
	Node_Binary searchNode;
		strcpy(searchNode.codMunic, codMunic);
	Node_Binary** foundNode = (Node_Binary**)bsearch(&searchNode, sortedNodeArray, nodeArraySize, sizeof(Node_Binary*), compareNodes);
	if (foundNode != NULL) {
    printf("Acesso por Busca Binária: Nome do Município: %s, População Estimada: %s\n",
        (*foundNode)->nomeMunicipio, (*foundNode)->populacaoEstimada);
	} else {
	    printf("Acesso por Busca Binária: Município não encontrado.\n");
	}

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
    Node_Binary* sortedNodeArray[MAX_LINE_LENGTH / 2];
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

            Node_Binary* newSortedNode = (Node_Binary*)malloc(sizeof(Node_Binary));
            strcpy(newSortedNode->uf, newNode->uf);
            strcpy(newSortedNode->codUf, newNode->codUf);
            strcpy(newSortedNode->codMunic, newNode->codMunic);
            strcpy(newSortedNode->nomeMunicipio, newNode->nomeMunicipio);
            strcpy(newSortedNode->populacaoEstimada, newNode->populacaoEstimada);
            newSortedNode->next = NULL;

            sortedNodeArray[nodeArraySize - 1] = newSortedNode;
        }

        for (int i = 0; i < column; i++) {
            free(columns[i]);
        }

        row++;
    }

    fclose(file);

    // Ordenar os nós usando qsort
    qsort(sortedNodeArray, nodeArraySize, sizeof(Node_Binary*), compareNodes);

    // Imprimir os nós ordenados
    /*for (int i = 0; i < nodeArraySize; i++) {
        Node_Binary* sortedNode = sortedNodeArray[i];
        printf("UF: %s, Cod. UF: %s, Cod. Munic: %s, Nome do Município: %s, População Estimada: %s\n",
            sortedNode->uf, sortedNode->codUf, sortedNode->codMunic, sortedNode->nomeMunicipio, sortedNode->populacaoEstimada);
        cont++;
    }*/

    printf("\n%d\n", cont);

    // Liberar a memória alocada para os nós ordenados
    for (int i = 0; i < nodeArraySize; i++) {
        free(sortedNodeArray[i]);
    }

    // Testar o acesso aos dados usando tabela dispersa e busca binária
    printf("\nTeste de acesso aos dados:\n");
    printf("Digite o código do município: ");
    char codMunic[MAX_FIELD_LENGTH];
    fgets(codMunic, MAX_FIELD_LENGTH, stdin);
    codMunic[strcspn(codMunic, "\n")] = '\0'; // Remover a quebra de linha do final

    testAccess(hashTable, sortedNodeArray, nodeArraySize, codMunic);

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



