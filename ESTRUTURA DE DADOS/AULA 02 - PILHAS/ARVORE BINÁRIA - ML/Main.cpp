#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"

// Fun��o principal
int main() {
    Node* root = NULL;
    char nome[50];
    int opcao;

    // Inserindo alguns valores na �rvore bin�ria
    insert_node(&root, "cachorro");
    insert_node(&root, "gato");
    insert_node(&root, "pato");
    
    do{
        window();
        scanf("%d",&opcao);
        
        switch(opcao){
            case 1:
                printf("Digite o nome de algum animal: ");
                scanf("%s",nome);
                char* string_to_find = nome;
                Node* node_found = search_string_node(root, string_to_find);
                if (node_found == NULL) {
                    printf("Esse animal '%s' n�o conheco, colocarei no meu banco de dados.\n", string_to_find);
                    insert_node(&root,nome);
                } else {
                    printf("Esse animal conheco\n");
                }
            break;
            case 0:
                printf("Saindo...\n");
            break;
            default:
                printf("Valor invalido!\n");
        }
    }while(opcao!=0);
    
    
    // Imprimindo a �rvore bin�ria em ordem
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    
    // Procurando uma string na �rvore bin�ria
    


    return 0;
}
