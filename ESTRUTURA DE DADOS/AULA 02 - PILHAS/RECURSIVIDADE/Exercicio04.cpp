#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 4-)Escreva uma função recursiva que calcule a soma dos primeiros n cubos:

// S = 1^3 + 2^3 + ... + n^3

int recursive(int n, int n3, int cont);

int main(){
	
	int  n, n3 = 0, cont = 1, x;
	
	printf("Digite o numero: ");
	scanf("%d",&n);
	
	x = recursive(n,n3,cont);
	
	return 0;
}

int recursive(int n, int n3, int cont){
	if(cont > n){
		printf("SOMA TOTAL: %d\n",n3);
		return 0;
	}else{
		int y = pow(cont, 3);
		printf("%d^3 = %d\n",cont,y);
		return recursive(n, n3 += y,cont + 1);
	}
}
