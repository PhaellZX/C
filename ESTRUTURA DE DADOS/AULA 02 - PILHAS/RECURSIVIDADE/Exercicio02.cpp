#include <stdio.h>
#include <stdlib.h>

// 2-)Crie uma fun��o recursiva que receba um n�mero
// inteiro N e imprima todos os n�meros de
// 0 at� N em ordem decrescente.

int recursive(int n);

int main(){
	
	int n, x;
	
	printf("Digite um numero: ");
	scanf("%d",&n);
	
	x = recursive(n);
	
	return 0;
}

int recursive(int n){
	if(n == -1)
		return 0;
	else
		printf("%d\n",n);
		return recursive(n - 1);
}
