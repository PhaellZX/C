#include <stdio.h>
#include <stdlib.h>

// 3-) Crie uma fun��o recursiva que receba dois n�meros inteiros
// I e F e retorne o somat�rio dos n�meros de I at� F.

// Soma = I + (I+1) + (I+2) + ...... + (F)

int recursive(int i,int f,int cont,int sum);

int main(){
	
	int i, f, cont = 1, sum = 0, x;
	
	printf("Digite o numero inicial: ");
	scanf("%d",&i);
	printf("Digite o numero final: ");
	scanf("%d",&f);
	
	x = recursive(i,f,cont,sum);
	
	return 0;
}

int recursive(int i, int f, int cont, int sum){
	if(cont == f){
		printf("SOMA TOTAL: %d\n",sum);
		return 0;
	}else{
		printf("%d + %d = %d\n",i,cont,(i+cont));
		return recursive(i, f, cont + 1,sum += (i+cont));
	}
}
