#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main(){
	
	//SEMANA 02
	
	//ATIVIDADE 01
	
	/*char matriz[7][7];
	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			
			if(i == j){
				
				matriz[i][j] = 'X';	
			
			} else {
				
				matriz[i][j] = '-';
				
			}
			
			printf(" %c ",matriz[i][j]);
					
		  }
		  	printf("\n");
	   }
	  */ 
	   // ATIVIDADE 02
	   /*
	   char matriz[7][7];
	
		for(int i = 0; i < 7; i++){
			for(int j = 0; j < 7; j++){
			
			if(i==j || i + j == 6){
				
				matriz[i][j] = 'X';	
			
			} else {
				
				matriz[i][j] = '-';
				
			}
			
			printf(" %c ",matriz[i][j]);
					
		  }
		  	printf("\n");
	   }
	   */
	   //ATIVIDADE 03
	   /*
	   char matriz[7][7];
	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			
			if(i==j || i < j){
				
				matriz[i][j] = 'X';	
			
			} else {
				
				matriz[i][j] = '-';
				
			}
			
			printf(" %c ",matriz[i][j]);
					
		  }
		  	printf("\n");
	   }
	   */
	   
	   //ATIVIDADE 04
	   /*
	   char matriz[7][7];
	
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			
			if(i>=3 && j>=3 || i<=3 && j<=3){
				
				matriz[i][j] = 'X';	
			
			} else {
				
				matriz[i][j] = '-';
				
			}
			
			printf(" %c ",matriz[i][j]);
					
		  }
		  	printf("\n");
	   }
	   */
		//ATIVIDADE 05
		
		// a) b[0] ser� o valor da v�riavel e &b[0] � o endere�o da m�moria da vari�vel
		// b) O b[0] est� armazenando o valor fixo da v�riavel, j� o &b[0] est� armazenando 
		// no endere�o da v�riavel e que estar alocada entre 4 slots de endere�os   
	
		//ATIVIDADE 06
		
	struct Cpessoa {
		
		char nome[10];
		int idade;
		
	};
	
	int main(){
		
		Cpessoa aluno;

		Cpessoa *paluno;
		
		paluno = &aluno;
		
		int opcao, cont = 0;
		
			paluno = (struct Cpessoa *) malloc(4*sizeof(struct Cpessoa));

		do{

			printf("Digite o nome:");
			scanf("%s",(paluno+cont)->nome);
			printf("Digite a idade:");
			scanf("%d",&(paluno+cont)->idade);

			cont++;

			printf("Deseja continuar?? Sim(1)|Naum(0)");
			scanf("%d",&opcao);

		}while(opcao != 0);
		
		for (int i = 0; i<cont ; i++){
			
				printf("%s - %d \n", (paluno+i)->nome, (paluno+i)->idade);
				printf("\n");
				
				}
			return 0;
	}
	

