#include <stdio.h>
#include <string.h>
#define TAM 10

// 4 - Fa�a um programa em C, contendo uma lista de funcion�rios de uma empresa de tamanho 10. Cada
// cadastro de funcion�rio dever� ter as seguintes informa��es: nome, sobrenome, sal�rio. 
// O seu programa deve conter um vetor de structs. O programa deve ser capaz de armazenar 
// os cadastros e de exibi-los na tela, bem como possuir uma fun��o que calcula a m�dia salarial
// dos funcion�rios.

struct funcionario {
    char nome[30];
    char sobrenome[30];
    float salario;
};

typedef struct funcionario Funcionario;

void cadastrar(Funcionario[], int);
void exibir(Funcionario[], int);
float calcularMediaSalario(Funcionario[], int);

int main() {
    Funcionario empresa[TAM];
    int opcao;

    do {
        printf("\n\n1 - Cadastrar funcionario");
        printf("\n2 - Exibir funcionarios");
        printf("\n3 - Calcular media salarial");
        printf("\n0 - Sair");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar(empresa, TAM);
                break;
            case 2:
                exibir(empresa, TAM);
                break;
            case 3:
                printf("\nA media salarial eh %.2f\n", calcularMediaSalario(empresa, TAM));
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void cadastrar(Funcionario empresa[], int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        printf("\n\nFuncionario %d:\n", i+1);
        printf("Digite o nome: ");
        scanf("%s", empresa[i].nome);
        printf("Digite o sobrenome: ");
        scanf("%s", empresa[i].sobrenome);
        printf("Digite o salario: ");
        scanf("%f", &empresa[i].salario);
    }
}

void exibir(Funcionario empresa[], int tam) {
    int i;

    printf("\n\nFuncionarios cadastrados:\n");
    for (i = 0; i < tam; i++) {
        printf("\nFuncionario %d:\n", i+1);
        printf("Nome: %s %s\n", empresa[i].nome, empresa[i].sobrenome);
        printf("Salario: %.2f\n", empresa[i].salario);
    }
}

float calcularMediaSalario(Funcionario empresa[], int tam) {
    int i;
    float soma = 0;

    for (i = 0; i < tam; i++) {
        soma += empresa[i].salario;
    }

    return soma / tam;
}

