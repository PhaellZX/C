#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

FILE * txt;
int opcao;
int cont = 0, ID = 1000, tam = 4;
char n[10];

struct Aluno {
	
	int id;
	char nome[10];
	float n1, n2, n3, n4, media;
	
};

void menu(){
	
	printf("\n--------MENU-------\n");
	printf("1 - Novo Registro\n");
	printf("2 - Salvar todos num arquivo\n");
	printf("3 - Pesquisar nome\n");
	printf("0 - Sair\n");
	
}

void novoRegistro(Aluno *paluno, Aluno a){
	
	system("cls");
	
		printf("Digite o nome do Aluno: ");
		scanf("%s",(paluno+cont)->nome);
		printf("Digite a primeira nota: ");
		scanf("%f",&(paluno+cont)->n1);
		printf("Digite a segunda nota: ");
		scanf("%f",&(paluno+cont)->n2);
		printf("Digite a terceira nota: ");
		scanf("%f",&(paluno+cont)->n3);
		printf("Digite a quarta nota: ");
		scanf("%f",&(paluno+cont)->n4);
		
		ID++;
		(paluno+cont)->id = ID;
		
		(paluno+cont)->media = ((paluno+cont)->n1 + (paluno+cont)->n2 + (paluno+cont)->n3 + (paluno+cont)->n4) / 4;
		
		printf("id:%d nome:%s nota1:%.1f nota2:%.1f nota3:%.1f nota4:%.1f media:%.1f\n",(paluno+cont)->id,(paluno+cont)->nome,(paluno+cont)->n1,(paluno+cont)->n2,(paluno+cont)->n3,(paluno+cont)->n4,(paluno+cont)->media);
		
		printf("Dados Salvos!\n");
		
		cont++;
		tam++;
		
		paluno = (Aluno*) realloc(paluno,tam * sizeof(Aluno));
}

void salvarNoArquivo(Aluno * paluno, Aluno a){
	
	system("cls");
	
	txt = fopen("arquivo.txt","w"); 
	
	if(txt==NULL){
		
		printf("Nao foi possivel abrir o arquivo");
		
	}else{
		
		for(int c = 0; c < cont; c++){
		
			fprintf(txt,"id:%d nome:%s nota1:%.1f nota2:%.1f nota3:%.1f nota4:%.1f media:%.1f\n",(paluno+c)->id,(paluno+c)->nome,(paluno+c)->n1,(paluno+c)->n2,(paluno+c)->n3,(paluno+c)->n4,(paluno+c)->media);
			
		}
		printf("Dados salvos no arquivo!");
		
		free(paluno);
		
		paluno = (struct Aluno*) malloc(4 * sizeof(struct Aluno));
		
		tam = 4;
		ID = 1000;
		cont = 0;
		
		fclose(txt);
	}
}

void pesquisarNome(Aluno * paluno, Aluno a){
	
	system("cls");
	
	printf("Digite o nome do Aluno: ");
	scanf("%s",&n);
		
		for(int c = 0; c < cont; c++){
			
			if(strcmp(n,(paluno+c)->nome)==0){
				system("cls");
				printf("\nAluno Encontrado!\n");
				printf("id:%d nome:%s nota1:%.1f nota2:%.1f nota3:%.1f nota4:%.1f media:%.1f\n",(paluno+c)->id,(paluno+c)->nome,(paluno+c)->n1,(paluno+c)->n2,(paluno+c)->n3,(paluno+c)->n4,(paluno+c)->media);
				break;
			}else{
				system("cls");
				printf("\nNao foi possivel achar o Aluno...\n");
			}
		}	
		fclose(txt);
	}

void error(){
	printf("Valor Invalido!\n");
}

void sair(){
	printf("saindo...\n");
}

int main(){
	
	menu();
	
	Aluno a;
	Aluno *paluno;
	paluno = &a;

	paluno = (struct Aluno*) malloc(4 * sizeof(struct Aluno));
	
    do{
    	scanf("%d",&opcao);
    	
	switch(opcao){
		case 1:
			novoRegistro(paluno,a);
			menu();
		break;
		case 2:
			salvarNoArquivo(paluno,a);
			menu();
			break;
		case 3:
			pesquisarNome(paluno,a);  
			menu();                   
			break;
		case 0:
			sair();
			break;
		default:
			system("cls");
			error();
			menu();
			}
		}while(opcao != 0);
		
	return 0;
}
