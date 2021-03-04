#include <stdio.h>
#include <stdlib.h>

// 1-) Crie um Programa que leia um arquivos numeros,
// com um número indeterminado de valores numéricos. 
// Após a Leitura, o programa deverá ordenar usando o
// método Bolha (Bubble Sort) e gerar um novo Arquivo_ordenado. 

int main(){
	
	FILE * txtNumeros;
	FILE * txt;
	int valor, cont = 0, tam = 5555, i = 0, j = 0, aux;
	int vetor[5555];
	
	txtNumeros = fopen("numeros.txt","r");
	
	if(txtNumeros==NULL){
		
		printf("Nao foi possivel abrir o arquivo...");
	
	}else{
		
		while(!feof(txtNumeros)){
			
			fscanf(txtNumeros,"%d",&valor);
			
			vetor[cont] = valor;
			
		}	
		
	}
	fclose(txtNumeros);
	
	txt = fopen("Arquivo_ordenado.txt","w");
	
	if(txtNumeros==NULL){
		
		printf("Nao foi possivel abrir o arquivo...");
	
	}else{
		while (j < tam){
					for(i = 0; i < tam-1; i++)
						  if(vetor[i] > vetor[i + 1]){

                                aux=vetor[i];

                                vetor[i] = vetor[i+1];

                            	vetor[i+1] = aux;

                                   }                        
								j++;
								}
					for (int q=0; q<5555; q++){

        fprintf(txt,"%d \n",vetor[q]);

	}
		fclose(txt);
	}
	return 0;
}
