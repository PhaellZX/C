#include <stdio.h>
#include <stdlib.h>

// 1-) Crie uma fun��o recursiva que receba um n�mero
// inteiro N e imprima todos os n�meros de
// 0 at� N em ordem crescente

int recursive(int n,int i);

int main(){
	
	int n,i = 0, x;
	
	printf("Digite um numero: ");
	scanf("%d",&n);
	
	x = recursive(n,i);
	
	return 0;
}

int recursive(int n, int i){
	if(i > n)
		return 0;
	else
		printf("%d\n",i);
		return recursive(n,i + 1);
}
