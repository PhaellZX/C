#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define P 1000

//Obs: quando salva no arquivo.txt os alunos e suas notas, est�
//escrevendo uns tr�s 0.0 no final da linha, n�o sei o porque :/
//mas o programa est� funcionando normalmente.

int opcao, cont = 0;
FILE * txt;
float n1[P], n2[P], n3[P], media[P];
char nome[10][P], n[10], pos[P];

void menu(){
	
	printf("\n--------MENU-------\n");
	printf("1 - Novo Registro\n");
	printf("2 - Salvar todos no arquivo\n");
	printf("3 - Pesquisar nome do(a) aluno(a)\n");
	printf("0 - Sair\n");
	
}

void novoRegistro(){
	
	system("cls");
	
	printf("Digite o nome do(a) Aluno(a): ");
	scanf("%s",&nome[cont]);
	printf("Digite a primeira nota: ");
	scanf("%f",&n1[cont]);
	printf("Digite a segunda nota: ");
	scanf("%f",&n2[cont]);
	printf("Digite a terceira nota: ");
	scanf("%f",&n3[cont]);
	
	media[cont] = (n1[cont] + n2[cont] + n3[cont]) / 3; 
	
	printf("Dados salvos com sucesso!\n");
	
	cont++;
	
	for(int i = 0; i < cont; i++){
		
		printf("nome: %s nota1: %.1f nota2: %.1f nota3: %.1f media: %.1f\n",nome[i],n1[i],n2[i],n3[i],media[i]);
	}
	
}

void salvarArquivo(){
	txt = fopen("arquivo.txt","w");
	
	if(txt==NULL){
		printf("Nao foi possivel abrir o arquivo...");
	}else{
		for(int i = 0; i <= cont; i++){
		
		fprintf(txt,"%s %.1f %.1f %.1f %.1f\n",nome[i],n1[i],n2[i],n3[i],media[i]);
		}	
		system("cls");
		printf("Dados salvos no arquivo!");
	}
	fclose(txt);
}

void procurarNome(){
		
		system("cls");
		
		printf("Digite o nome do(a) aluno(a): ");
		scanf("%s",&n);
		
		for(int i = 0; i < cont; i++){
			if(strcmp(n,nome[i])==0){
				system("cls");
				printf("Aluno(a) Encontrado!\n");
				printf("nome: %s nota1: %.1f nota2: %.1f nota3: %.1f media: %.1f\n",nome[i],n1[i],n2[i],n3[i],media[i]);
				break;
			}else{
				system("cls");
				printf("\nNao foi possivel achar o aluno...\n");
			}
		}
	}

void error(){
	printf("Valor Invalido!\n");
}

void sair(){
	printf("saindo...\n");
}

void lerArquivo(){
	txt = fopen("arquivo.txt","r");
	
	if(txt==NULL){
		printf("Nao ha alunos cadastrados no arquivo...");
	}else{
		printf("---LISTA DE ALUNOS---|nome|nota1|nota2|nota3|media\n");
		while(!feof(txt)){
			fgets(pos, 1000, txt);
			printf("%s",pos);
		}
	}
	fclose(txt);
}

int main(){
	
	lerArquivo();
	
	menu();
	
    do{
    	scanf("%d",&opcao);
    	
	switch(opcao){
		case 1:
			novoRegistro();
			menu();
		break;
		case 2:
			salvarArquivo();
			menu();
			break;
		case 3:
			procurarNome();
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
