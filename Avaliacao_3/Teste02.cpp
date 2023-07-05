#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define TABLE_SIZE 100

typedef struct Node {
    char uf[3];
    int cod_uf;
    int cod_munic;
    char nome_municipio[MAX_LINE_LENGTH];
    int populacao_estimada;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} HashTable;

typedef struct {
    int cod_munic;
    Node* node;
} MunicipioEntry;

typedef struct {
    MunicipioEntry* entries;
    int count;
} MunicipioArray;

typedef struct {
    Node** nodes;
    int count;
} NodeArray;

HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].head = NULL;
    }
    return table;
}

int hashFunction(int cod_munic) {
    return cod_munic % TABLE_SIZE;
}

void insertData(HashTable* table, char uf[3], int cod_uf, int cod_munic, char nome_municipio[MAX_LINE_LENGTH], int populacao_estimada) {
    int index = hashFunction(cod_munic);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->uf, uf);
    newNode->cod_uf = cod_uf;
    newNode->cod_munic = cod_munic;
    strcpy(newNode->nome_municipio, nome_municipio);
    newNode->populacao_estimada = populacao_estimada;
    newNode->next = NULL;

    if (table[index].head == NULL) {
        table[index].head = newNode;
    } else {
        Node* current = table[index].head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void imprimirMunicipio(Node municipio) {
    printf("| %-2s | %-8d | %-10d | %-25s | %-16d |\n",
           municipio.uf, municipio.cod_uf, municipio.cod_munic,
           municipio.nome_municipio, municipio.populacao_estimada);
}

void printHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            Node municipio;
            strcpy(municipio.uf, current->uf);
            municipio.cod_uf = current->cod_uf;
            municipio.cod_munic = current->cod_munic;
            strcpy(municipio.nome_municipio, current->nome_municipio);
            municipio.populacao_estimada = current->populacao_estimada;
            imprimirMunicipio(municipio);

            current = current->next;
        }
    }
}

int compareNodes(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;

    return strcmp(nodeA->nome_municipio, nodeB->nome_municipio);
}

int compareMunicipioEntry(const void* a, const void* b) {
    MunicipioEntry* entryA = (MunicipioEntry*)a;
    MunicipioEntry* entryB = (MunicipioEntry*)b;

    return entryA->cod_munic - entryB->cod_munic;
}

void createNodeArray(HashTable* table, NodeArray* nodeArray) {
    int totalCount = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            totalCount++;
            current = current->next;
        }
    }

    nodeArray->nodes = (Node**)malloc(sizeof(Node*) * totalCount);
    nodeArray->count = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            nodeArray->nodes[nodeArray->count] = current;
            nodeArray->count++;
            current = current->next;
        }
    }

    qsort(nodeArray->nodes, nodeArray->count, sizeof(Node*), compareNodes);
}

void printNodeArray(NodeArray* nodeArray) {
    for (int i = 0; i < nodeArray->count; i++) {
        imprimirMunicipio(*nodeArray->nodes[i]);
    }
}

MunicipioArray* createMunicipioArray(HashTable* table) {
    MunicipioArray* munArray = (MunicipioArray*)malloc(sizeof(MunicipioArray));
    int totalCount = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            totalCount++;
            current = current->next;
        }
    }

    munArray->entries = (MunicipioEntry*)malloc(sizeof(MunicipioEntry) * totalCount);
    munArray->count = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            munArray->entries[munArray->count].cod_munic = current->cod_munic;
            munArray->entries[munArray->count].node = current;
            munArray->count++;
            current = current->next;
        }
    }

    qsort(munArray->entries, munArray->count, sizeof(MunicipioEntry), compareMunicipioEntry);

    return munArray;
}

Node* findMunicipioHashTable(HashTable* table, int cod_munic) {
    int index = hashFunction(cod_munic);
    Node* current = table[index].head;

    while (current != NULL) {
        if (current->cod_munic == cod_munic) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

Node* findMunicipioBinarySearch(MunicipioArray* munArray, int cod_munic) {
    MunicipioEntry target;
    target.cod_munic = cod_munic;

    MunicipioEntry* foundEntry = (MunicipioEntry*)bsearch(&target, munArray->entries, munArray->count, sizeof(MunicipioEntry), compareMunicipioEntry);

    if (foundEntry != NULL) {
        return foundEntry->node;
    }

    return NULL;
}

void testAccess(HashTable* table, NodeArray* nodeArray, MunicipioArray* munArray, int cod_munic) {
    // Access using Hash Table
    Node* hashNode = findMunicipioHashTable(table, cod_munic);
    if (hashNode != NULL) {
        printf("Buscando usando Hash Table:\n");
        imprimirMunicipio(*hashNode);
    } else {
        printf("Município nao encontrado com Hash Table.\n");
    }

    // Access using Binary Search
    Node* binarySearchNode = findMunicipioBinarySearch(munArray, cod_munic);
    if (binarySearchNode != NULL) {
        printf("Buscando usando bsearch():\n");
        imprimirMunicipio(*binarySearchNode);
    } else {
        printf("Município nao encontrado usando bsearch().\n");
    }
}

int main() {
    FILE* arquivo;
    int cont = 0;
    char nome_arquivo[MAX_LINE_LENGTH] = "cidades.csv";
    char linha[MAX_LINE_LENGTH];
    Node municipio;

    // Criar a tabela hash
    HashTable* table = createHashTable();

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler e inserir os dados do arquivo CSV na tabela hash
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%[^,],%d,%d,%[^,],%d",
               municipio.uf, &municipio.cod_uf, &municipio.cod_munic,
               municipio.nome_municipio, &municipio.populacao_estimada);
        insertData(table, municipio.uf, municipio.cod_uf, municipio.cod_munic,
                   municipio.nome_municipio, municipio.populacao_estimada);
        cont++;
    }
    // Fechar o arquivo
    fclose(arquivo);

    // Imprimir os dados da tabela hash
    printHashTable(table);

    // Criar a matriz de nós e ordenar os dados
    NodeArray nodeArray;
    createNodeArray(table, &nodeArray);

    // Criar o array de municípios ordenados
    MunicipioArray* munArray = createMunicipioArray(table);

    // Imprimir os dados ordenados
    printf("\nDados Ordenados(Hash Table):\n");
    printNodeArray(&nodeArray);

    // Test access to the data
    int cod_munic = 9457;  // Municipality code to search for
    
    printf("\n");
    
    testAccess(table, &nodeArray, munArray, cod_munic);

    printf("\nNumeros de Cidades no CSV: %d", cont);
    return 0;
}



