#include <string.h>

// Estrutura que representa um n� da �rvore bin�ria
typedef struct node {
    char animal[50];
    struct node* left;
    struct node* right;
} Node;

// Fun��o para criar um novo n� da �rvore bin�ria
Node* create_node(char * value) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->animal,value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fun��o para inserir um novo n� na �rvore bin�ria
void insert_node(Node** root, char * value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else {
        if (strcmp(value,(*root)->animal)) {
            insert_node(&(*root)->left, value);
        } else {
            insert_node(&(*root)->right, value);
        }
    }
}

// Fun��o para percorrer a �rvore bin�ria em ordem (esquerda, n�, direita)
void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%s ", root->animal);
        inorder_traversal(root->right);
    }
}

// Fun��o para procurar uma string na �rvore bin�ria
Node* search_string_node(Node* root, char* string) {
    if (root == NULL || strcmp(root->animal, string) == 0) {
        return root;
    }
    if (strcmp(string, root->animal) < 0) {
        return search_string_node(root->left, string);
    } else {
        return search_string_node(root->right, string);
    }
}

void window(){
    printf("----MENU----\n1 - COMPUTER\n0 - SAIR\n");
}
