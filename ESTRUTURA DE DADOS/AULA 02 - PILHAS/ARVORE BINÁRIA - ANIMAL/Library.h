#include <string.h>

// Estrutura que representa um nó da árvore binária
typedef struct node {
    char animal[50];
    struct node* left;
    struct node* right;
} Node;

// Função para criar um novo nó da árvore binária
Node* create_node(char * value) {
    Node* node = (Node*) malloc(sizeof(Node));
    strcpy(node->animal,value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para inserir um novo nó na árvore binária
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

// Função para percorrer a árvore binária em ordem (esquerda, nó, direita)
void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%s ", root->animal);
        inorder_traversal(root->right);
    }
}

// Função para procurar uma string na árvore binária
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
