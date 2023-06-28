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
    struct Node* next;
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

int compareByCodMunic(const void* a, const void* b) {
    int keyA = *(const int*)a;
    Node* nodeB = (Node*)b;
    int keyB = nodeB->cod_munic;

    return keyA - keyB;
}

Node* searchHashTable(Node** hashtable, int size, int cod_munic) {
    unsigned int index = cod_munic % size;
    Node* current = hashtable[index];
    while (current != NULL) {
        if (current->cod_munic == cod_munic) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* searchArray(Node* array, int arraySize, int cod_munic) {
    Node keyNode;
    keyNode.cod_munic = cod_munic;
    Node* foundNode = (Node*)bsearch(&keyNode, array, arraySize, sizeof(Node), compareByCodMunic);
    return foundNode;
}

int main() {
    const char* filename = "cidades.csv";
    const int arraySize = 100; // Tamanho do array

    Node* array = (Node*)malloc(arraySize * sizeof(Node));

    loadCSVToArray(array, arraySize, filename);

    printf("Dados carregados:\n");
    printArray(array, arraySize);

        // Ordenar o array pelo nome do município
    qsort(array, arraySize, sizeof(Node), compareNodes);

    printf("\nDados ordenados:\n");
    printArray(array, arraySize);

    // Criar a tabela hash
    const int hashtableSize = arraySize; // Tamanho da tabela hash

    Node** hashtable = (Node**)calloc(hashtableSize, sizeof(Node*));
    for (int i = 0; i < arraySize; i++) {
        Node* node = &array[i];
        unsigned int index = node->cod_munic % hashtableSize;
        node->next = hashtable[index];
        hashtable[index] = node;
    }

    // Testar a pesquisa usando tabela hash
    int cod_munic = 296; // Código do município a ser pesquisado
    Node* foundNodeHashTable = searchHashTable(hashtable, hashtableSize, cod_munic);
    if (foundNodeHashTable != NULL) {
        printf("\nResultado da pesquisa (Tabela Dispersa):\n");
        printf("UF: %s, COD. UF: %d, COD. MUNIC: %d, NOME DO MUNICÍPIO: %s, POPULAÇÃO ESTIMADA: %d\n",
               foundNodeHashTable->uf, foundNodeHashTable->cod_uf, foundNodeHashTable->cod_munic,
               foundNodeHashTable->nome_municipio, foundNodeHashTable->populacao_estimada);
    } else {
        printf("\nMunicípio não encontrado (Tabela Dispersa).\n");
    }

    // Testar a pesquisa usando busca binária
    qsort(array, arraySize, sizeof(Node), compareByCodMunic); // Ordenar o array pelo código do município
	
    Node* foundNodeArray = searchArray(array, arraySize, cod_munic);
    if (foundNodeArray != NULL) {
        printf("\nResultado da pesquisa (Busca Binária):\n");
        printf("UF: %s, COD. UF: %d, COD. MUNIC: %d, NOME DO MUNICÍPIO: %s, POPULAÇÃO ESTIMADA: %d\n",
               foundNodeArray->uf, foundNodeArray->cod_uf, foundNodeArray->cod_munic,
               foundNodeArray->nome_municipio, foundNodeArray->populacao_estimada);
    } else {
        printf("\nMunicípio não encontrado (Busca Binária).\n");
    }

    free(array);
    free(hashtable);

    return 0;
}


