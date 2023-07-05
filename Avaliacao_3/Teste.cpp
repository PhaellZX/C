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

int main() {
    FILE* arquivo;
    int cont = 0;
    char nome_arquivo[MAX_LINE_LENGTH] = "cidades.csv";
    char linha[MAX_LINE_LENGTH];
    Node municipio;

    // Criar a tabela hash
    HashTable* table = createHashTable();

    // Abrir o arquivo para leitura
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
    //printHashTable(table);

    // Criar a matriz de nós e ordenar os dados
    NodeArray nodeArray;
    createNodeArray(table, &nodeArray);

    // Imprimir os dados ordenados
    printf("\nDados Ordenados(Table Hash):\n");
    printNodeArray(&nodeArray);

    // Liberar a memória alocada para a tabela hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table);

    // Liberar a memória alocada para a matriz de nós
    free(nodeArray.nodes);

    printf("\nNumeros de Cidades no CSV: %d", cont);
    return 0;
}


