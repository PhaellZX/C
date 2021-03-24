#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

struct Motor {	
	
	int pos;
	char peca[20];
	struct Motor * prox;
	
};

struct Pilha {
	
	Motor * primeiro;
};

void menu(){
	
	printf("\n-----OFICINA-----\n");
	printf("Montagem do Motor\n");
	printf("1 - Inserir peca\n");
	printf("2 - Retirar peca\n");
	printf("0 - Sair\n");
	
}

int pilhaVazia (Pilha * p){
   return (p->primeiro == NULL); 
 }

Pilha * criarPilha () {
 Pilha* p = (Pilha*)malloc(sizeof(Pilha));
 p->primeiro = NULL; 
 return p;
 }

void pecaPush(Pilha * p, int v, char pec[6][20],FILE * arquivo){
	
	arquivo = fopen("pecas.txt","w");
	
	if(arquivo==NULL){
		
		printf("Nao foi possivel abrir o arquivo!");
		
	}else{
	
	Motor * m = (Motor*) malloc(sizeof(Motor));
	m->pos = v;
	m->prox = p->primeiro;
	p->primeiro = m;
	
	system("cls");
	
	Motor * elem;
			
			fprintf(arquivo,"MOTOR(Pecas):\n");
			
	if(m->pos>=N){
		
		printf("O Motor ja esta montado!\n");
		for(elem = m; elem != NULL; elem = elem->prox){
		
		fprintf(arquivo,"%d - %s\n",elem->pos,elem->peca);
			}
		exit(0);
		
	}else{
		strcpy(m->peca,pec[m->pos]);
		m->pos++;
		
		printf("Peca %s adicionada!\n\n",m->peca);
		
		for(elem = m; elem != NULL; elem = elem->prox){
		
		printf("%d - %s\n",elem->pos,elem->peca);
		fprintf(arquivo,"%d - %s\n",elem->pos,elem->peca);
			}
		}
	}
	fclose(arquivo);
}

void pecaPop(Pilha* p, char pec[6][20]){
	
	system("cls");
	
	Motor * m; 
	
	int v;
	
	if (pilhaVazia(p)) {
		
         printf ("Pilha esta vazia!\n");
     
	 }else{
	 	
       m = p->primeiro; 
       v = m->pos;
       p->primeiro = m->prox;
       free(m);
      
      printf("Peca removida!\n"); 
      
      Motor * elem;
      
      for(elem = m; elem != NULL; elem = elem->prox){
		
		printf("%d - %s\n",elem->pos,elem->peca);
			}
      }
 }

int main(){
	
	Pilha * pilha = criarPilha();
	Motor * motor;
	FILE * txt;
	
	int opcao, valor = 0;
	
	// ""
	
	char pecas[6][20] = {"bloco"  ,"Pistao","Biela","Virabrequim","Carter","Cabecote"};
	
	do{
		
		menu();
		
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				pecaPush(pilha,valor,pecas,txt);
				valor++;
			break;
			case 2:
				pecaPop(pilha,pecas);
			break;
			case 0:
				printf("Saindo...");
			break;
			default:
				system("cls");
				printf("Valor invalido!\n");
			break;
		}
		
	}while(opcao!=0);
	
	return 0;
}
