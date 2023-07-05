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
        printf("C�digo do munic�pio: %d\n", node->cod_munic);
        printf("Nome do munic�pio: %s\n", node->nome_municipio);
        printf("Quantidade de acessos: %d\n", accessCount);
    } else {
        printf("Munic�pio n�o encontrado.\n");
    }
}

int main() {
    // Restante do c�digo ...

    // Criar a matriz de n�s e ordenar os dados
    NodeArray nodeArray;
    createNodeArray(table, &nodeArray);

    // Realizar a busca bin�ria por todos os c�digos de munic�pios
    for (int i = 0; i < nodeArray.count; i++) {
        int cod_munic = nodeArray.nodes[i]->cod_munic;
        printf("Realizando busca bin�ria para o c�digo do munic�pio: %d\n", cod_munic);
        testBinarySearch(&nodeArray, cod_munic);
        printf("------------------------------------------------\n");
    }

    // Restante do c�digo ...

    return 0;
}

