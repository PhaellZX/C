int binarySearch(NodeArray* nodeArray, int cod_munic, int* accessCount) {
    int left = 0;
    int right = nodeArray->count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*accessCount)++; // Incrementar o contador de acessos

        if (nodeArray->nodes[mid]->cod_munic == cod_munic) {
            return mid;
        }

        if (nodeArray->nodes[mid]->cod_munic < cod_munic) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void testBinarySearch(NodeArray* nodeArray, int cod_munic) {
    int accessCount = 0;
    int index = binarySearch(nodeArray, cod_munic, &accessCount);

    if (index != -1) {
        Node* node = nodeArray->nodes[index];
        printf("Código do município: %d\n", node->cod_munic);
        printf("Nome do município: %s\n", node->nome_municipio);
        printf("Quantidade de acessos: %d\n", accessCount);
    } else {
        printf("Município não encontrado.\n");
    }
}

int main() {
    // Restante do código ...

    // Criar a matriz de nós e ordenar os dados
    NodeArray nodeArray;
    createNodeArray(table, &nodeArray);

    // Realizar a busca binária por todos os códigos de municípios
    for (int i = 0; i < nodeArray.count; i++) {
        int cod_munic = nodeArray.nodes[i]->cod_munic;
        printf("Realizando busca binária para o código do município: %d\n", cod_munic);
        testBinarySearch(&nodeArray, cod_munic);
        printf("------------------------------------------------\n");
    }

    // Restante do código ...

    return 0;
}

